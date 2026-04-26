#include "OpenSRX/SocketInterface.hpp"

namespace OpenSRX {

SocketInterface::SocketInterface(const std::string& ip, int port)
    : AsioInterface(ioContext), ip(ip), port(port) {
    spdlog::debug("Initializing socket connection to {}...", describe());
    asio::ip::tcp::resolver resolver(ioContext);
    asio::ip::tcp::resolver::results_type endpoints =
        resolver.resolve(this->ip, std::to_string(this->port));
    asio::connect(stream, endpoints);
    spdlog::debug("Socket connection established.");
}

SocketInterface::~SocketInterface() {
    spdlog::debug("Closing socket connection to {}...", describe());
    stream.close();
    if (pFtpServer != nullptr && pFtpServer->getOpenConnectionCount() > 0) {
        spdlog::debug("Stopping FTP server with {} open connections...",
                      pFtpServer->getOpenConnectionCount());
        pFtpServer->stop();
        spdlog::debug("FTP server stopped.");
    }
    spdlog::debug("Socket connection to {} closed.", describe());
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
