#pragma once
#include <cstddef>
#include <vector>

namespace OpenSRX {

class Timestamp {
   public:
    Timestamp(int second = 0, int minute = 0, int hour = 0, int day = 1, int month = 1,
              int year = 1970)
        : second(second), minute(minute), hour(hour), day(day), month(month), year(year) {}
    Timestamp() : Timestamp(0, 0, 0, 1, 1, 1970) {}
    Timestamp(std::vector<std::byte> buff);
    ~Timestamp() = default;

    std::tuple<int, int, int, int, int, int> asTuple() const {
        return std::make_tuple(year, month, day, hour, minute, second);
    }

    std::tuple<int, int, int> asDate() const { return std::make_tuple(year, month, day); }

    int second, minute, hour, day, month, year;
};

}  // namespace OpenSRX
