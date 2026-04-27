#pragma once

namespace OpenSRX {

// ── Shared value enums for bank and tuning parameter settings ───────────────

/// Generic enable/disable toggle used by many parameters.
enum class Toggle {
    DISABLE = 0,
    ENABLE = 1,
};

/// Internal lighting type (command 010).
enum class InternalLightingType {
    DIRECT = 0,
    POLARIZED = 1,
    DIFFUSED = 2,
};

/// Contrast adjustment method (command 108).
enum class ContrastAdjustment {
    STANDARD = 0,
    HDR = 1,
    HDR2 = 2,
    CONTRAST_ZOOM = 3,
};

/// Filter type for filter slots 1–4 (commands 200–203).
enum class FilterType {
    DISABLE = 0,
    EQUALIZE = 1,
    EXPAND = 2,
    SHRINK = 3,
    OPEN = 4,
    CLOSE = 5,
    MEDIAN = 6,
    UNSHARP_MASK = 7,
};

/// Output direction (command 307).
enum class OutputDirection {
    FORWARD = 0,
    BACKWARD = 1,
};

/// Length limitation method used by many code types.
enum class LengthLimitationMethod {
    SPECIFY_RANGE = 0,
    SPECIFY_VALUE = 1,
};

/// Grid correction mode (command 500).
enum class GridCorrection {
    DISABLE = 0,
    ENABLE = 1,
    AUTOMATIC = 2,
};

/// PDF417 read code type.
enum class PDF417ReadCodeType {
    PDF417_ONLY = 1,
    MICRO_PDF_ONLY = 2,
    PDF417_AND_MICRO_PDF = 3,
};

/// NW-7 (CodaBar) start/stop letter type.
enum class NW7StartStopLetterType {
    LOWERCASE = 0,
    UPPERCASE = 1,
};

/// NW-7 (CodaBar) check-digit type.
enum class NW7CheckDigitType {
    MODULUS_16 = 0,
    MODULUS_11 = 1,
    MODULUS_10_WEIGHT_2 = 2,
    MODULUS_10_WEIGHT_3 = 3,
    CHECK_DR = 4,
    MODULUS_11_ALT = 5,
    LUHN = 6,
};

/// UPC-A output format.
enum class UpcAOutput {
    OUTPUT_13_DIGITS = 0,
    OUTPUT_12_DIGITS = 1,
};

/// Inverse reading mode.
enum class InverseMode {
    DISABLE = 0,
    ENABLE = 1,
    AUTOMATIC = 2,
};

/// Reverse reading mode.
enum class ReverseMode {
    DISABLE = 0,
    ENABLE = 1,
    AUTOMATIC = 2,
};

/// Pharmacode read direction.
enum class PharmacodeReadDirection {
    LEFT_TO_RIGHT = 0,
    RIGHT_TO_LEFT = 1,
    DOWNWARD = 2,
    UPWARD = 3,
};

// ── Value enums for operation configuration (WP/RP) ─────────────────────────

/// IN terminal function (commands 000, 001).
enum class InTerminalFunction {
    DISABLE = 0,
    TRIGGER_INPUT = 1,
    PRESET_INPUT = 2,
    START_TEST_MODE = 3,
    CAPTURE = 4,
    CLEAR_PLC_LINK_ERROR = 5,
    TRIGGER_LOCK = 6,
    READ_QUICK_SETUP_CODE = 7,
    TUNING_OPERATION = 8,
    TIMING_INPUT_START = 9,
    TIMING_INPUT_STOP = 10,
    COMMAND_REPLACEMENT = 14,
    DATA_OUTPUT = 15,
};

/// Test mode assignment (commands 002, 003).
enum class TestModeAssignment {
    READING_RATE_TEST = 1,
    TACT_TEST = 2,
};

/// Input polarity (commands 040, 041, 050, 051, 052).
enum class InputPolarity {
    NORMAL_OPEN = 0,
    NORMAL_CLOSE = 1,
};

/// Input pulse width (commands 043, 044).
enum class InputPulseWidth {
    MS_1 = 0,
    MS_2 = 1,
    MS_10 = 2,
};

/// Test mode on startup (command 100).
enum class StartupTestMode {
    NONE = 0,
    READING_RATE_TEST = 1,
    READ_TIME_TEST = 2,
};

/// Timing mode (command 101).
enum class TimingMode {
    LEVEL_TRIGGER = 0,
    ONE_SHOT_TRIGGER = 1,
};

/// Reading mode (command 200).
enum class ReadingMode {
    STANDARD = 0,
    CONTINUOUS = 1,
    BURST_READ = 3,
    SCRIPT = 4,
};

/// Data transmission timing (command 201).
enum class DataTransmission {
    SEND_AFTER_READ = 0,
    SEND_AFTER_TIMING_OFF = 1,
};

/// Standard duplicate reading prevention (command 239).
enum class DuplicateReadingPrevention {
    RESET_BY_TIME = 0,
    RESET_BY_TIME_OR_ANOTHER_CODE = 1,
    DO_NOT_PREVENT = 2,
};

/// Specifying alternate order (command 204).
enum class AlternateOrder {
    ORDER_OF_BANK_NUMBER = 0,
    BEGIN_WITH_SUCCESSFUL_BANK = 1,
};

/// Automatic pointer lighting (command 209).
enum class AutoPointerLighting {
    DO_NOT_LIGHT = 0,
    LIGHT_AUTOMATICALLY = 1,
    ONLY_WHEN_CAPTURING = 2,
};

/// Multiple reading of same code type/data (command 243).
enum class MultipleReadingSameCode {
    DISABLE = 0,
    ALLOW_SAME_WITHIN_CAPTURE = 1,
    ALLOW_SAME_SEPARATED_BY_INTERVAL = 2,
};

/// Multiple-code output format (command 290).
enum class MultiCodeOutputFormat {
    STANDARD = 0,
    PER_BANK = 1,
    PER_AREA = 2,
};

/// Image saving destination (commands 500–504).
enum class ImageSavingDestination {
    DISABLE = 0,
    SAVE_TO_RAM = 1,
    SAVE_TO_ROM = 2,
    SEND_BY_FTP = 3,
    SAVE_USB = 4,
    SAVE_ROM_AND_FTP = 5,
    SAVE_USB_AND_FTP = 6,
};

/// Image saving mode (command 505).
enum class ImageSavingMode {
    LATEST_BANK_IMAGE = 0,
    AFTER_TRIGGER_ON = 1,
    AFTER_TRIGGER_OFF = 2,
    AFTER_TRIGGER_ON_INTERMITTENT = 3,
    AFTER_TRIGGER_OFF_INTERMITTENT = 4,
};

/// Image format (command 511).
enum class ImageFormat {
    BMP = 0,
    JPG = 1,
};

/// Binning (command 513).
enum class Binning {
    FULL = 0,
    QUARTER = 1,
    SIXTEENTH = 3,
    SIXTY_FOURTH = 4,
};

/// Trigger command response string mode (command 610).
enum class TriggerCommandResponse {
    NOT_SPECIFIED = 0,
    DETAILED_RESPONSE = 1,
    USER_SETTING = 2,
    ECHO_BACK = 3,
    COMMAND_REPLACEMENT = 4,
};

/// Presentation mode (command 616).
enum class PresentationMode {
    DISABLE = 0,
    POLARIZED_LIGHT = 1,
    DIRECT_LIGHT = 2,
    DIFFUSED_LIGHT = 3,
};

/// LiveView display image (command 900).
enum class LiveViewDisplayImage {
    BEFORE_IMAGE_FILTER = 0,
    AFTER_IMAGE_FILTER = 1,
};

/// Verification threshold grade (commands 231, 232, 235, 237).
enum class VerificationThreshold {
    DISABLE = 0,
    GRADE_D = 1,
    GRADE_C = 2,
    GRADE_B = 3,
    GRADE_A = 4,
};

/// Code verification calibration lighting (command 890).
enum class CalibrationLighting {
    DISABLE = 0,
    POLARIZED_LIGHT = 1,
    DIRECT_LIGHT = 2,
    DIFFUSED_LIGHT = 3,
};

/// Verification method (command 403).
enum class VerificationMethod {
    NORMAL = 0,
    SEQUENTIAL_VALUE = 1,
};

/// Grade expression setting (command 350).
enum class GradeExpression {
    ALPHABET = 0,
    NUMERICAL_VALUE = 1,
};

/// Sorting order (commands 280–285).
enum class SortOrder {
    ASCENDING = 0,
    DESCENDING = 1,
};

// ── Value enums for communication configuration (WN/RN) ─────────────────────

/// RS-232C baud rate low range (command 105).
enum class BaudRateLow {
    DISABLE = 0,
    BPS_600 = 1,
    BPS_1200 = 2,
    BPS_2400 = 3,
    BPS_4800 = 4,
};

/// RS-232C baud rate high range (command 100).
enum class BaudRateHigh {
    BPS_9600 = 0,
    BPS_19200 = 1,
    BPS_38400 = 2,
    BPS_57600 = 3,
    BPS_115200 = 4,
};

/// RS-232C data length (command 101).
enum class DataLength {
    SEVEN_BIT = 0,
    EIGHT_BIT = 1,
};

/// RS-232C parity check (command 102).
enum class ParityCheck {
    DISABLE = 0,
    EVEN = 1,
    ODD = 2,
};

/// RS-232C stop bit length (command 103).
enum class StopBitLength {
    ONE_BIT = 0,
    TWO_BIT = 1,
};

/// RS-232C communication protocol (command 104).
enum class CommProtocol {
    NO_HANDSHAKING = 0,
    PASS_RTRY = 1,
    ACK_NAK = 2,
};

/// Ethernet command mode (command 203).
enum class EthernetCommandMode {
    NOT_USED = 0,
    TCP = 1,
    UDP = 2,
};

/// Ethernet data client setting (command 207).
enum class EthernetDataClientMode {
    NOT_USED = 0,
    TCP = 1,
    UDP = 2,
};

/// TCP client connection timing (command 213).
enum class TCPClientConnectionTiming {
    AFTER_READING = 0,
    IMMEDIATELY_AFTER_POWER_UP = 1,
};

/// PLC protocol setting (command 303).
enum class PLCProtocol {
    NOT_USED = 0,
    MC_PROTOCOL_RS232C = 1,
    SYSWAY = 2,
    KV_STUDIO_RS232C = 3,
    MC_PROTOCOL_ETHERNET = 4,
    OMRON_PLC_LINK = 5,
    KV_STUDIO = 6,
    ETHERNET_IP = 7,
    PROFINET = 8,
};

/// FTP connection timing (commands 405, 426).
enum class FTPConnectionTiming {
    AFTER_READING = 0,
    IMMEDIATELY_AFTER_POWER_UP = 1,
    ALWAYS_DISCONNECT = 2,
};

/// Subfolder name setting method (command 411).
enum class SubfolderNameMethod {
    MANUAL = 0,
    AUTO = 1,
};

/// Master/Slave operation configuration (command 500).
enum class MasterSlaveOperation {
    DISABLE = 0,
    MULTI_DROP_LINK = 1,
    ADVANCED_MULTI_HEAD = 3,
};

}  // namespace OpenSRX
