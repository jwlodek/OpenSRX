#include "OpenSRX/ICommInterface.hpp"

namespace OpenSRX {

/**
 * @brief Adds an appropriate header and terminator to a command
 *
 * @param command Base command to which the header and terminator should be appended
 * @return std::string The command with the header and terminator added according to the current
 * communication format
 */
std::string ICommInterface::addHeaderAndTerminator(const std::string& command) {
    std::string fullCommand = "";
    if (commFormat == CommFormat::STX_HEADER_ETX_IN_ETX_OUT) {
        fullCommand += "\x02";  // ASCII Start of Text
    }
    fullCommand += command;
    if (commFormat == CommFormat::STX_HEADER_ETX_IN_ETX_OUT) {
        fullCommand += "\x03";  // ASCII End of Text
    } else {
        fullCommand += "\r";
    }
    return fullCommand;
}

/**
 * @brief Strips the echoed command from the start of the response, if it exists
 *
 * @param response The response received from the scanner, which may include an echoed command at
 * the start
 * @param command The command that was sent, which may be echoed at the start of the response
 * @return std::string The response with the echoed command stripped from the start, if it was
 * present.
 */
std::string ICommInterface::stripEcho(const std::string& response, const std::string& command) {
    if (response.rfind(command, 0) == 0) {
        auto pos = command.size();
        // Skip a comma separator between the echo and the payload.
        if (pos < response.size() && response[pos] == ',') {
            ++pos;
        }
        return response.substr(pos);
    }
    return response;
}

/**
 * @brief Sets the communication format for this interface, which determines the header and
 * terminators
 *
 * @param commFormat The communication format to use
 */
void ICommInterface::setCommFormat(const CommFormat commFormat) {
    this->commFormat = commFormat;
    switch (commFormat) {
        case CommFormat::NO_HEADER_CR_IN_CR_OUT:
            this->inTermStr = "\r";
            break;
        case CommFormat::NO_HEADER_CRLF_IN_CR_OUT:
            this->inTermStr = "\r\n";
            break;
        case CommFormat::STX_HEADER_ETX_IN_ETX_OUT:
            this->inTermStr = "\x03";
            break;
    }
}

};  // namespace OpenSRX
