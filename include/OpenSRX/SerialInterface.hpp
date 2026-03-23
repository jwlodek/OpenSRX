#pragma once

#include <asio.hpp>
#include "OpenSRX/ICommInterface.hpp"

namespace OpenSRX {

enum class Parity {
    NONE = 0,
    EVEN = 1,
    ODD = 2,
};

enum class DataBits {
    SEVEN = 7,
    EIGHT = 8,
};

enum class StopBits {
    ONE = 0,
    TWO = 1,
};

enum class FlowControl {
    NONE = 0,
    RTS_CTS = 1,
    XON_XOFF = 2,
};

class SerialInterface : public ICommInterface {
public:
    SerialInterface(std::string port = "/dev/ttyUSB0", int baudRate = 115200, DataBits dataBits = DataBits::EIGHT, Parity parity = Parity::EVEN, StopBits stopBits = StopBits::ONE, FlowControl flowControl = FlowControl::NONE);
    ~SerialInterface() override;

    bool sendCommand(const std::string& command) override;

private:

    asio::serial_port serialPort;
};

};  // namespace OpenSRX