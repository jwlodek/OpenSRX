#include "OpenSRX/SocketInterface.hpp"

namespace OpenSRX {

SocketInterface::SocketInterface(const std::string& ip, int port)
    : socket(ioContext), ip(ip), port(port) {
    spdlog::debug("Initializing socket connection to {}...", describe());
    asio::ip::tcp::resolver resolver(ioContext);
    asio::ip::tcp::resolver::results_type endpoints =
        resolver.resolve(this->ip, std::to_string(this->port));
    asio::connect(socket, endpoints);
    spdlog::debug("Socket connection established.");
}

SocketInterface::~SocketInterface() {
    spdlog::debug("Closing socket connection to {}...", describe());
    socket.close();
    if (pFtpServer != nullptr && pFtpServer->getOpenConnectionCount() > 0) {
        spdlog::debug("Stopping FTP server with {} open connections...",
                      pFtpServer->getOpenConnectionCount());
        pFtpServer->stop();
        spdlog::debug("FTP server stopped.");
    }
    spdlog::debug("Socket connection to {} closed.", describe());
}

std::string SocketInterface::sendCommand(const std::string& command) {
    // Attach the correct header and terminator depending on the comm format
    std::string fullCommand = addHeaderAndTerminator(command);
    asio::write(socket, asio::buffer(fullCommand));

    // Read from socket until we see our terminator
    asio::streambuf response;
    asio::read_until(socket, response, inTermStr);

    // Convert response to a string
    std::string result{asio::buffers_begin(response.data()), asio::buffers_end(response.data())};

    // Strip the terminator from the end of the response, and the header from the start if
    // applicable
    auto pos = result.find(inTermStr);
    if (pos != std::string::npos) result.erase(pos);

    if (commFormat == CommFormat::STX_HEADER_ETX_IN_ETX_OUT && !result.empty() &&
        result[0] == '\x02')
        result.erase(0, 1);

    return result;
}

void SocketInterface::startFtpServer(const std::string& address, int port,
                                     const std::string& mountPoint, int threadPoolSize) {
    spdlog::debug("Starting FTP server on {}:{} with mount point '{}'...", address, port,
                  mountPoint);
    pFtpServer = std::make_unique<fineftp::FtpServer>(address, port);
    pFtpServer->addUserAnonymous(mountPoint, fineftp::Permission::All);
    pFtpServer->start(threadPoolSize);
    spdlog::debug("FTP server started on {}:{}.", address, port);
}

};  // namespace OpenSRX
