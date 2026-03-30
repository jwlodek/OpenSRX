#include "OpenSRX/ICommInterface.hpp"


namespace OpenSRX {

std::string ICommInterface::addHeaderAndTerminator(const std::string& command) {
    std::string fullCommand = "";
    if (commFormat == CommFormat::STX_HEADER_ETX_IN_ETX_OUT) {
        fullCommand += "\x02";  // ASCII Start of Text
    }
    fullCommand += command;
    if (commFormat == CommFormat::NO_HEADER_CRLF_IN_CR_OUT) {
        fullCommand += "\r\n";
    } else if (commFormat == CommFormat::STX_HEADER_ETX_IN_ETX_OUT) {
        fullCommand += "\x03";  // ASCII End of Text
    } else {
        fullCommand += "\r";
    }
    return fullCommand;
}



};  // namespace OpenSRX