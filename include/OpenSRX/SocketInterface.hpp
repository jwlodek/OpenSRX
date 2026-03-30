#pragma once

#include <asio.hpp>

#include "OpenSRX/ICommInterface.hpp"

namespace OpenSRX {

class SocketInterface : public ICommInterface {
   public:
    SocketInterface(std::string ip = "192.168.100.100", int port = 9004);
    ~SocketInterface() override;

    std::string describe() const override { return ip + ":" + std::to_string(port); };
    std::string sendCommand(const std::string& command) override;

   private:
    asio::io_context ioContext;
    asio::ip::tcp::socket socket;
    std::string ip;
    int port;
};

}  // namespace OpenSRX
