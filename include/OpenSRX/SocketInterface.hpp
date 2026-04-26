#pragma once

#include <fineftp/fineftp_version.h>
#include <fineftp/server.h>

#include <thread>

#include "OpenSRX/AsioInterface.hpp"

namespace OpenSRX {

class SocketInterface : public AsioInterface<asio::ip::tcp::socket> {
   public:
    SocketInterface(const std::string& ip = "192.168.100.100", int port = 9004);
    ~SocketInterface() override;

    std::string describe() const override { return ip + ":" + std::to_string(port); };

    void startFtpServer(const std::string& address, int port, const std::string& mountPoint,
                        int threadPoolSize = 4);

   private:
    std::string ip;
    int port;

    // Assignment operator is deleted for FtpServer class,
    // so we need to use a pointer to manage its lifetime.
    std::unique_ptr<fineftp::FtpServer> pFtpServer = nullptr;
};

}  // namespace OpenSRX
