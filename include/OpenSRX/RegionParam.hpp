#pragma once

namespace OpenSRX {

/**
 * @brief Command numbers for region configuration (WD/RD commands).
 *
 * Used with the WD (write region) and RD (read region) commands in the format:
 *   WD,m,n  (write)   RD,m  (read)
 * where m = region number (001–128), n = region coordinates as "abcd"
 * (a,b = top-left x,y; c,d = bottom-right x,y; each 4-digit zero-padded).
 *
 * Minimum region size: 96×96 dots.
 *
 * Coordinate ranges depend on model:
 *   SR-X300/X300W/X300P/X300WP: a,c = 0000–1919; b,d = 0000–1199
 *   SR-X100/X100W/X100P/X100WP: a,c = 0000–1359; b,d = 0000–1023
 *
 * The region number itself (1–128) is used as the command number, so this
 * enum is intentionally empty — use integer region IDs directly.
 */

constexpr int REGION_MIN = 1;
constexpr int REGION_MAX = 128;

}  // namespace OpenSRX
