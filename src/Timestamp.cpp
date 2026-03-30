#include "OpenSRX/Timestamp.hpp"

#include <cstdint>
#include <stdexcept>

namespace OpenSRX {

static int readU16(std::vector<std::byte>::const_iterator it) {
    return static_cast<int>(std::to_integer<uint8_t>(it[0])) |
           (static_cast<int>(std::to_integer<uint8_t>(it[1])) << 8);
}

static int readU32(std::vector<std::byte>::const_iterator it) {
    return readU16(it) | (readU16(it + 2) << 16);
}

Timestamp::Timestamp(std::vector<std::byte> buff) {
    if (buff.size() != 14)
        throw std::invalid_argument(
            "Buffer size must be exactly 14 bytes to construct a Timestamp");

    auto it = buff.cbegin();
    year = readU32(it);
    month = readU16(it + 4);
    day = readU16(it + 6);
    hour = readU16(it + 8);
    minute = readU16(it + 10);
    second = readU16(it + 12);
}

}  // namespace OpenSRX
