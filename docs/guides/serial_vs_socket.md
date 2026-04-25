# Serial vs. Socket Communication {#serial_vs_socket}

OpenSRX provides two concrete communication backends, both implementing the
OpenSRX::ICommInterface abstract class.

## SocketInterface

Use OpenSRX::SocketInterface for Ethernet (TCP/IP) connections.
This is the most common setup for the SR-X series.

```cpp
#include "OpenSRX/SocketInterface.hpp"
#include "OpenSRX/Scanner.hpp"

OpenSRX::SocketInterface comm("192.168.100.100", 9004);
OpenSRX::Scanner scanner(comm);
```

The socket interface also supports starting an embedded FTP server for
image readback via OpenSRX::SocketInterface::startFtpServer.

## SerialInterface

Use OpenSRX::SerialInterface for RS-232 serial connections.

```cpp
#include "OpenSRX/SerialInterface.hpp"
#include "OpenSRX/Scanner.hpp"

OpenSRX::SerialInterface comm("/dev/ttyUSB0", 115200);
OpenSRX::Scanner scanner(comm);
```

You can configure parity, data bits, stop bits, and flow control through
the constructor parameters. See the OpenSRX::SerialInterface class reference
for details.

## Communication Format

Both backends support switching between different command framing modes via
OpenSRX::ICommInterface::setCommFormat. The available modes are defined in
OpenSRX::CommFormat.
