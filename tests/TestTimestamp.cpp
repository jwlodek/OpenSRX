#include <OpenSRX/Timestamp.hpp>

#include "TestOpenSRX.hpp"

TEST(TestTimestamp, TestConstructFromBuffer) {
    std::vector<std::byte> buff = {
        std::byte{0xEA}, std::byte{0x07}, std::byte{0x00}, std::byte{0x00},  // year = 2026
        std::byte{0x03}, std::byte{0x00},                                    // month = 3
        std::byte{0x1E}, std::byte{0x00},                                    // day = 30
        std::byte{0x0A}, std::byte{0x00},                                    // hour = 10
        std::byte{0x0F}, std::byte{0x00},                                    // minute = 15
        std::byte{0x1E}, std::byte{0x00}                                     // second = 30
    };
    OpenSRX::Timestamp timestamp(buff);
    EXPECT_EQ(timestamp.year, 2026);
    EXPECT_EQ(timestamp.month, 3);
    EXPECT_EQ(timestamp.day, 30);
    EXPECT_EQ(timestamp.hour, 10);
    EXPECT_EQ(timestamp.minute, 15);
    EXPECT_EQ(timestamp.second, 30);
}
