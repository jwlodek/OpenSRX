#pragma once

#include "OpenSRX/BankParam.hpp"
#include "OpenSRX/CommParam.hpp"
#include "OpenSRX/OperationParam.hpp"
#include "OpenSRX/TuningParam.hpp"

namespace OpenSRX {

/**
 * @brief Combined wire format and value-enum type for a parameter.
 *
 * When reading a parameter with RB/RC/RP/RN, the response payload is always a
 * string. This enum describes both how that string should be interpreted
 * (HEX, ASCII, INT, INT_VECTOR) and, for integer parameters that map to a
 * known enumeration, which ParamValues.hpp enum applies.
 *
 * Parameters that are plain integers with no corresponding enum use INT.
 */
enum class ParamType {
    // ── Non-integer wire formats ────────────────────────────────────────────

    /// Hex-encoded value (bit-field, byte sequence, or Unicode string).
    HEX,

    /// Plain ASCII string (names, descriptions, IP addresses, coordinates).
    ASCII,

    /// Colon-separated list of integer values (e.g. "a:b:c:d:e").
    INT_VECTOR,

    // ── Integer types (raw or enumerated) ───────────────────────────────────

    INT,
    TOGGLE,
    INTERNAL_LIGHTING_TYPE,
    CONTRAST_ADJUSTMENT,
    FILTER_TYPE,
    OUTPUT_DIRECTION,
    LENGTH_LIMITATION_METHOD,
    GRID_CORRECTION,
    PDF417_READ_CODE_TYPE,
    NW7_START_STOP_LETTER_TYPE,
    NW7_CHECK_DIGIT_TYPE,
    UPC_A_OUTPUT,
    INVERSE_MODE,
    REVERSE_MODE,
    PHARMACODE_READ_DIRECTION,
    IN_TERMINAL_FUNCTION,
    TEST_MODE_ASSIGNMENT,
    INPUT_POLARITY,
    INPUT_PULSE_WIDTH,
    STARTUP_TEST_MODE,
    TIMING_MODE,
    READING_MODE,
    DATA_TRANSMISSION,
    DUPLICATE_READING_PREVENTION,
    ALTERNATE_ORDER,
    AUTO_POINTER_LIGHTING,
    MULTIPLE_READING_SAME_CODE,
    MULTI_CODE_OUTPUT_FORMAT,
    IMAGE_SAVING_DESTINATION,
    IMAGE_SAVING_MODE,
    IMAGE_FORMAT,
    BINNING,
    TRIGGER_COMMAND_RESPONSE,
    PRESENTATION_MODE,
    LIVE_VIEW_DISPLAY_IMAGE,
    VERIFICATION_THRESHOLD,
    CALIBRATION_LIGHTING,
    VERIFICATION_METHOD,
    GRADE_EXPRESSION,
    SORT_ORDER,
    BAUD_RATE_LOW,
    BAUD_RATE_HIGH,
    DATA_LENGTH,
    PARITY_CHECK,
    STOP_BIT_LENGTH,
    COMM_PROTOCOL,
    ETHERNET_COMMAND_MODE,
    ETHERNET_DATA_CLIENT_MODE,
    TCP_CLIENT_CONNECTION_TIMING,
    PLC_PROTOCOL,
    FTP_CONNECTION_TIMING,
    SUBFOLDER_NAME_METHOD,
    MASTER_SLAVE_OPERATION,
};

// ─── BankParam ──────────────────────────────────────────────────────────────

constexpr ParamType paramType(BankParam p) {
    switch (p) {
        // ASCII
        case BankParam::BANK_NAME:
            return ParamType::ASCII;

        // HEX bit-fields
        case BankParam::CODE_TYPE:
        case BankParam::QR_VERSION_MODEL1:
        case BankParam::QR_VERSION_MODEL2_1_20:
        case BankParam::QR_VERSION_MODEL2_21_40:
        case BankParam::QR_VERSION_MICRO:
        case BankParam::DATAMATRIX_TARGET_SIZE:
        case BankParam::DMRE_TARGET_SIZE:
        case BankParam::CODE_ORIENTATION_1D:
            return ParamType::HEX;

        // Colon-separated length limitation values
        case BankParam::QR_LENGTH_LIMITATION_VALUE:
        case BankParam::DATAMATRIX_LENGTH_LIMITATION_VALUE:
        case BankParam::PDF417_LENGTH_LIMITATION_VALUE:
        case BankParam::MAXICODE_LENGTH_LIMITATION_VALUE:
        case BankParam::GS1_DATABAR_LENGTH_LIMITATION_VALUE:
        case BankParam::CODE39_LENGTH_LIMITATION_VALUE:
        case BankParam::ITF_LENGTH_LIMITATION_VALUE:
        case BankParam::TWO_OF_5_LENGTH_LIMITATION_VALUE:
        case BankParam::NW7_LENGTH_LIMITATION_VALUE:
        case BankParam::CODE128_LENGTH_LIMITATION_VALUE:
        case BankParam::COOP_2OF5_LENGTH_LIMITATION_VALUE:
        case BankParam::CODE93_LENGTH_LIMITATION_VALUE:
        case BankParam::GS1_COMPOSITE_DATABAR_LENGTH_LIMITATION_VALUE:
        case BankParam::GS1_COMPOSITE_EAN_UPC_LENGTH_LIMITATION_VALUE:
        case BankParam::GS1_COMPOSITE_GS1_128_LENGTH_LIMITATION_VALUE:
        case BankParam::POSTAL_LENGTH_LIMITATION_VALUE:
        case BankParam::DOTCODE_LENGTH_LIMITATION_VALUE:
        case BankParam::AZTEC_LENGTH_LIMITATION_VALUE:
            return ParamType::INT_VECTOR;

        // Toggle (enable/disable)
        case BankParam::INTERNAL_LIGHTING_USE:
        case BankParam::EXTERNAL_LIGHTING_USE:
        case BankParam::AI_FILTER:
        case BankParam::CONTRAST_THRESHOLD_CORRECTION:
        case BankParam::OUTPUT_LENGTH_LIMITATION:
        case BankParam::ECI_OUTPUT:
        case BankParam::CODE39_SEND_START_STOP:
        case BankParam::CODE39_INSPECT_CHECK_DIGIT:
        case BankParam::CODE39_SEND_CHECK_DIGIT:
        case BankParam::CODE39_TRIOPTIC_READING:
        case BankParam::CODE39_FULL_ASCII:
        case BankParam::ITF_INSPECT_CHECK_DIGIT:
        case BankParam::ITF_SEND_CHECK_DIGIT:
        case BankParam::NW7_SEND_START_STOP:
        case BankParam::NW7_INSPECT_CHECK_DIGIT:
        case BankParam::NW7_SEND_CHECK_DIGIT:
        case BankParam::UPC_E_READING:
        case BankParam::EAN_JAN_8_READING:
        case BankParam::EAN_JAN_13_READING:
        case BankParam::UPC_E_NUMBER_SYSTEM:
        case BankParam::SUPPLEMENTAL_2_DIGIT:
        case BankParam::SUPPLEMENTAL_5_DIGIT:
        case BankParam::IGNORE_UPC_WITHOUT_SUPPLEMENTAL:
        case BankParam::GTIN_14_DIGIT_OUTPUT:
        case BankParam::CODE128_GS1_128:
        case BankParam::POSTAL_JAPAN_READING:
        case BankParam::POSTAL_INTELLIGENT_MAIL:
        case BankParam::PHARMACODE_BINARY_OUTPUT:
        case BankParam::ALTERNATE:
        case BankParam::GS1_DATABAR_OMNIDIRECTIONAL:
        case BankParam::GS1_DATABAR_STACKED:
        case BankParam::GS1_DATABAR_LIMITED:
        case BankParam::GS1_DATABAR_EXPANDED:
        case BankParam::GS1_DATABAR_EXPANDED_STACKED:
        case BankParam::GS1_COMPOSITE_GS1_128_CC_C_READING:
            return ParamType::TOGGLE;

        case BankParam::INTERNAL_LIGHTING_TYPE:
            return ParamType::INTERNAL_LIGHTING_TYPE;

        case BankParam::CONTRAST_ADJUSTMENT_METHOD:
            return ParamType::CONTRAST_ADJUSTMENT;

        case BankParam::FILTER_1ST_TYPE:
        case BankParam::FILTER_2ND_TYPE:
        case BankParam::FILTER_3RD_TYPE:
        case BankParam::FILTER_4TH_TYPE:
            return ParamType::FILTER_TYPE;

        case BankParam::OUTPUT_DIRECTION:
            return ParamType::OUTPUT_DIRECTION;

        case BankParam::QR_LENGTH_LIMITATION_METHOD:
        case BankParam::DATAMATRIX_LENGTH_LIMITATION_METHOD:
        case BankParam::PDF417_LENGTH_LIMITATION_METHOD:
        case BankParam::MAXICODE_LENGTH_LIMITATION_METHOD:
        case BankParam::GS1_DATABAR_LENGTH_LIMITATION_METHOD:
        case BankParam::CODE39_LENGTH_LIMITATION_METHOD:
        case BankParam::ITF_LENGTH_LIMITATION_METHOD:
        case BankParam::TWO_OF_5_LENGTH_LIMITATION_METHOD:
        case BankParam::NW7_LENGTH_LIMITATION_METHOD:
        case BankParam::CODE128_LENGTH_LIMITATION_METHOD:
        case BankParam::COOP_2OF5_LENGTH_LIMITATION_METHOD:
        case BankParam::CODE93_LENGTH_LIMITATION_METHOD:
        case BankParam::GS1_COMPOSITE_DATABAR_LENGTH_LIMITATION_METHOD:
        case BankParam::GS1_COMPOSITE_EAN_UPC_LENGTH_LIMITATION_METHOD:
        case BankParam::GS1_COMPOSITE_GS1_128_LENGTH_LIMITATION_METHOD:
        case BankParam::POSTAL_LENGTH_LIMITATION_METHOD:
        case BankParam::DOTCODE_LENGTH_LIMITATION_METHOD:
        case BankParam::AZTEC_LENGTH_LIMITATION_METHOD:
            return ParamType::LENGTH_LIMITATION_METHOD;

        case BankParam::QR_GRID_CORRECTION:
            return ParamType::GRID_CORRECTION;

        case BankParam::PDF417_READ_CODE_TYPE:
            return ParamType::PDF417_READ_CODE_TYPE;

        case BankParam::NW7_START_STOP_LETTER_TYPE:
            return ParamType::NW7_START_STOP_LETTER_TYPE;

        case BankParam::NW7_CHECK_DIGIT_TYPE:
            return ParamType::NW7_CHECK_DIGIT_TYPE;

        case BankParam::UPC_A_OUTPUT:
            return ParamType::UPC_A_OUTPUT;

        case BankParam::INVERSE:
            return ParamType::INVERSE_MODE;

        case BankParam::REVERSE:
            return ParamType::REVERSE_MODE;

        case BankParam::PHARMACODE_READ_DIRECTION:
            return ParamType::PHARMACODE_READ_DIRECTION;

        // Raw integer (numeric range, no enum)
        default:
            return ParamType::INT;
    }
}

// ─── TuningParam ────────────────────────────────────────────────────────────

constexpr ParamType paramType(TuningParam p) {
    switch (p) {
        // Toggle
        case TuningParam::CODE39_SEND_START_STOP:
        case TuningParam::CODE39_INSPECT_CHECK_DIGIT:
        case TuningParam::CODE39_SEND_CHECK_DIGIT:
        case TuningParam::CODE39_TRIOPTIC_READING:
        case TuningParam::CODE39_FULL_ASCII:
        case TuningParam::ITF_INSPECT_CHECK_DIGIT:
        case TuningParam::ITF_SEND_CHECK_DIGIT:
        case TuningParam::NW7_SEND_START_STOP:
        case TuningParam::NW7_INSPECT_CHECK_DIGIT:
        case TuningParam::NW7_SEND_CHECK_DIGIT:
        case TuningParam::UPC_E_READING:
        case TuningParam::EAN_JAN_8_READING:
        case TuningParam::EAN_JAN_13_READING:
        case TuningParam::UPC_E_NUMBER_SYSTEM:
        case TuningParam::SUPPLEMENTAL_2_DIGIT:
        case TuningParam::SUPPLEMENTAL_5_DIGIT:
        case TuningParam::IGNORE_UPC_WITHOUT_SUPPLEMENTAL:
        case TuningParam::GTIN_14_DIGIT_OUTPUT:
        case TuningParam::CODE128_GS1_128:
        case TuningParam::PHARMACODE_BINARY_OUTPUT:
        case TuningParam::POSTAL_INTELLIGENT_MAIL:
        case TuningParam::POSTAL_JAPAN_READING:
        case TuningParam::GS1_DATABAR_OMNIDIRECTIONAL:
        case TuningParam::GS1_DATABAR_STACKED:
        case TuningParam::GS1_DATABAR_LIMITED:
        case TuningParam::GS1_DATABAR_EXPANDED:
        case TuningParam::GS1_DATABAR_EXPANDED_STACKED:
        case TuningParam::DATAMATRIX_DMRE_READ:
            return ParamType::TOGGLE;

        case TuningParam::NW7_START_STOP_LETTER_TYPE:
            return ParamType::NW7_START_STOP_LETTER_TYPE;

        case TuningParam::NW7_CHECK_DIGIT_TYPE:
            return ParamType::NW7_CHECK_DIGIT_TYPE;

        case TuningParam::UPC_A_OUTPUT:
            return ParamType::UPC_A_OUTPUT;

        case TuningParam::PHARMACODE_READ_DIRECTION:
            return ParamType::PHARMACODE_READ_DIRECTION;

        case TuningParam::PDF417_TARGET_CODE:
            return ParamType::PDF417_READ_CODE_TYPE;

        // Raw integer
        default:
            return ParamType::INT;
    }
}

// ─── OperationParam ─────────────────────────────────────────────────────────

constexpr ParamType paramType(OperationParam p) {
    switch (p) {
        // HEX-encoded strings / byte sequences
        case OperationParam::TRIGGER_ON_COMMAND_STRING:
        case OperationParam::TRIGGER_OFF_COMMAND_STRING:
        case OperationParam::READ_ERROR_STRING:
        case OperationParam::TRIGGER_OVERRUN_STRING:
        case OperationParam::PRESET_DATA_REGISTRATION:
        case OperationParam::DELIMITER_CHARACTER:
        case OperationParam::INTER_DELIMITER:
        case OperationParam::DATA_FILLING_CHARACTER:
        case OperationParam::COMPOSITE_DELIMITER:
        case OperationParam::READER_NAME:
        case OperationParam::TRIGGER_COMMAND_SUCCESS_RESPONSE:
        case OperationParam::TRIGGER_COMMAND_FAILURE_RESPONSE:
        case OperationParam::CODE_TYPE_SEQUENCE_SETTING:
        case OperationParam::TUNING_TARGET_CODE:
        case OperationParam::VERIFICATION_STANDARD_SELECTION:
        case OperationParam::ISO_15416_EXECUTION:
            return ParamType::HEX;

        // Plain ASCII strings (including coordinate format)
        case OperationParam::READER_DESCRIPTION_1:
        case OperationParam::READER_DESCRIPTION_2:
        case OperationParam::READER_DESCRIPTION_3:
        case OperationParam::READER_DESCRIPTION_4:
        case OperationParam::IMAGE_CAPTURE_RANGE:
            return ParamType::ASCII;

        // Toggle
        case OperationParam::IN1_CAPTURE_BANK:
        case OperationParam::IN2_CAPTURE_BANK:
        case OperationParam::IN1_INPUT_AT_POWER_ON:
        case OperationParam::IN2_INPUT_AT_POWER_ON:
        case OperationParam::BUSY_OUTPUT_ON_STARTUP:
        case OperationParam::TRIGGER_ON_OFF_ONE_CHAR:
        case OperationParam::MATCHING_LEVEL_JUDGMENT:
        case OperationParam::SHORTEN_BANK_TRANSITION:
        case OperationParam::ALLOW_REDUCED_DETECTION_COUNT:
        case OperationParam::TRIGGER_OVERRUN_OUTPUT:
        case OperationParam::TIME_APPENDING:
        case OperationParam::CODE_TYPE_APPENDING:
        case OperationParam::SYMBOL_ID_APPENDING:
        case OperationParam::BANK_NUMBER_APPENDING:
        case OperationParam::DECODING_TIME_APPENDING:
        case OperationParam::SCAN_COUNT_APPENDING:
        case OperationParam::READ_TIME_APPENDING:
        case OperationParam::CODE_VERTEX_APPENDING:
        case OperationParam::CODE_CENTER_APPENDING:
        case OperationParam::UNUSED_ECC_RATIO_APPENDING:
        case OperationParam::FILE_NAME_APPENDING:
        case OperationParam::REGION_NUMBER_APPENDING:
        case OperationParam::MASTER_SLAVE_GROUP_NAME_APPENDING:
        case OperationParam::MASTER_SLAVE_ID_APPENDING:
        case OperationParam::DATA_EDIT_FUNCTION:
        case OperationParam::NUMBER_OF_SUCCESSFUL_DECODES_APPENDING:
        case OperationParam::ANGLE_APPENDING:
        case OperationParam::OUTPUT_DATA_WITH_ENTER_BUTTON:
        case OperationParam::SILENT_MODE:
        case OperationParam::ENTER_BUTTON_LOCK:
        case OperationParam::WRITE_BLOAD_TO_ROM:
        case OperationParam::STATUS_LED_LIGHTING:
        case OperationParam::ISO_15415_RESULT_APPENDING:
        case OperationParam::ISO_29158_RESULT_APPENDING:
        case OperationParam::SAE_AS9132_RESULT_APPENDING:
        case OperationParam::SEMI_T10_RESULT_APPENDING:
        case OperationParam::JP_PHARMA_RESULT_APPENDING:
        case OperationParam::ISO_16022_RESULT_APPENDING:
        case OperationParam::DETAILED_ITEM_ADDITION:
        case OperationParam::EVALUATION_VALUE_ADDITION:
        case OperationParam::TUNING_EXPOSURE_TIME:
        case OperationParam::TUNING_IMAGE_FILTER:
        case OperationParam::TUNING_ALLOW_REDUCED_DETECTION:
        case OperationParam::TUNING_AUTO_INTERNAL_LIGHTING:
        case OperationParam::TUNING_CODE_SEARCH:
        case OperationParam::TUNING_INTERNAL_LIGHTING:
        case OperationParam::TUNING_EXTERNAL_LIGHTING:
        case OperationParam::TUNING_BLACK_WHITE_INVERSION:
        case OperationParam::TUNING_CONTRAST_ADJUSTMENT:
        case OperationParam::TUNING_AUTO_CONTRAST_ADJUSTMENT:
        case OperationParam::IMAGE_SAVING_CONTINUATION:
            return ParamType::TOGGLE;

        case OperationParam::IN1_TERMINAL_FUNCTION:
        case OperationParam::IN2_TERMINAL_FUNCTION:
            return ParamType::IN_TERMINAL_FUNCTION;

        case OperationParam::IN1_TEST_MODE_ASSIGNMENT:
        case OperationParam::IN2_TEST_MODE_ASSIGNMENT:
            return ParamType::TEST_MODE_ASSIGNMENT;

        case OperationParam::IN1_INPUT_POLARITY:
        case OperationParam::IN2_INPUT_POLARITY:
        case OperationParam::OUT1_OUTPUT_POLARITY:
        case OperationParam::OUT2_OUTPUT_POLARITY:
        case OperationParam::OUT3_OUTPUT_POLARITY:
            return ParamType::INPUT_POLARITY;

        case OperationParam::IN1_INPUT_PULSE_WIDTH:
        case OperationParam::IN2_INPUT_PULSE_WIDTH:
            return ParamType::INPUT_PULSE_WIDTH;

        case OperationParam::STARTUP_TEST_MODE:
            return ParamType::STARTUP_TEST_MODE;

        case OperationParam::TIMING_MODE:
            return ParamType::TIMING_MODE;

        case OperationParam::READING_MODE:
            return ParamType::READING_MODE;

        case OperationParam::DATA_TRANSMISSION:
            return ParamType::DATA_TRANSMISSION;

        case OperationParam::DUPLICATE_READING_PREVENTION_MODE:
            return ParamType::DUPLICATE_READING_PREVENTION;

        case OperationParam::ALTERNATE_ORDER:
            return ParamType::ALTERNATE_ORDER;

        case OperationParam::AUTO_POINTER_LIGHTING:
            return ParamType::AUTO_POINTER_LIGHTING;

        case OperationParam::MULTIPLE_READING_SAME_CODE:
            return ParamType::MULTIPLE_READING_SAME_CODE;

        case OperationParam::MULTI_CODE_OUTPUT_FORMAT:
            return ParamType::MULTI_CODE_OUTPUT_FORMAT;

        case OperationParam::SAVE_DEST_READ_OK:
        case OperationParam::SAVE_DEST_VERIFICATION_NG:
        case OperationParam::SAVE_DEST_READ_ERROR:
        case OperationParam::SAVE_DEST_UNSTABLE:
        case OperationParam::SAVE_DEST_CAPTURE:
            return ParamType::IMAGE_SAVING_DESTINATION;

        case OperationParam::IMAGE_SAVING_MODE:
            return ParamType::IMAGE_SAVING_MODE;

        case OperationParam::IMAGE_FORMAT:
            return ParamType::IMAGE_FORMAT;

        case OperationParam::BINNING:
            return ParamType::BINNING;

        case OperationParam::TRIGGER_COMMAND_RESPONSE:
            return ParamType::TRIGGER_COMMAND_RESPONSE;

        case OperationParam::PRESENTATION_MODE:
            return ParamType::PRESENTATION_MODE;

        case OperationParam::LIVEVIEW_DISPLAY_IMAGE:
            return ParamType::LIVE_VIEW_DISPLAY_IMAGE;

        case OperationParam::ISO_15415_THRESHOLD:
        case OperationParam::ISO_29158_THRESHOLD:
        case OperationParam::ISO_15416_THRESHOLD:
        case OperationParam::ISO_16022_THRESHOLD:
            return ParamType::VERIFICATION_THRESHOLD;

        case OperationParam::CALIBRATION_LIGHTING:
            return ParamType::CALIBRATION_LIGHTING;

        case OperationParam::VERIFICATION_METHOD:
            return ParamType::VERIFICATION_METHOD;

        case OperationParam::GRADE_EXPRESSION_SETTING:
            return ParamType::GRADE_EXPRESSION;

        case OperationParam::SCANNING_ORDER_SETTING:
        case OperationParam::CODE_CENTER_X_ORDER_SETTING:
        case OperationParam::CODE_CENTER_Y_ORDER_SETTING:
        case OperationParam::REGION_SEQUENCE_SETTING:
        case OperationParam::CODE_DIGITS_SEQUENCE_SETTING:
            return ParamType::SORT_ORDER;

        // Raw integer
        default:
            return ParamType::INT;
    }
}

// ─── CommParam ──────────────────────────────────────────────────────────────

constexpr ParamType paramType(CommParam p) {
    switch (p) {
        // HEX-encoded byte sequences
        case CommParam::HEADER_SETTINGS:
        case CommParam::TERMINATOR_SETTINGS:
        case CommParam::HEARTBEAT_STRING:
        case CommParam::HEARTBEAT_HEADER:
        case CommParam::HEARTBEAT_TERMINATOR:
            return ParamType::HEX;

        // Plain ASCII strings (including IP addresses)
        case CommParam::IP_ADDRESS:
        case CommParam::DEFAULT_GATEWAY:
        case CommParam::ETHERNET_DATA_CLIENT_REMOTE_IP_1:
        case CommParam::ETHERNET_DATA_CLIENT_REMOTE_IP_2:
        case CommParam::PLC_REMOTE_IP:
        case CommParam::FTP_REMOTE_IP:
        case CommParam::FTP_DATA_REMOTE_IP:
        case CommParam::SNTP_SERVER_ADDRESS:
        case CommParam::LOGIN_USER_NAME:
        case CommParam::LOGIN_PASSWORD:
        case CommParam::PROFINET_DEVICE_NAME:
        case CommParam::FTP_USER_NAME:
        case CommParam::FTP_PASSWORD:
        case CommParam::FTP_SUBFOLDER_NAME:
        case CommParam::FTP_DATA_USER_NAME:
        case CommParam::FTP_DATA_PASSWORD:
        case CommParam::FTP_DATA_SUBFOLDER_NAME:
        case CommParam::FTP_DATA_FILE_NAME:
        case CommParam::MASTER_SLAVE_GROUP_NAME:
        case CommParam::ADMIN_USERNAME:
        case CommParam::ADMIN_PASSWORD:
        case CommParam::USER1_USERNAME:
        case CommParam::USER1_PASSWORD:
        case CommParam::USER2_USERNAME:
        case CommParam::USER2_PASSWORD:
        case CommParam::USER3_USERNAME:
        case CommParam::USER3_PASSWORD:
        case CommParam::USER4_USERNAME:
        case CommParam::USER4_PASSWORD:
            return ParamType::ASCII;

        // Toggle
        case CommParam::APPEND_CHECKSUM:
        case CommParam::APPEND_DATA_SIZE:
        case CommParam::AI_NET_CONNECTION:
        case CommParam::RS232C_COMMUNICATION:
        case CommParam::RS232C_HEARTBEAT_SEND:
        case CommParam::RNDIS:
        case CommParam::ETHERNET_DATA_SERVER:
        case CommParam::KEEP_ALIVE:
        case CommParam::HOST_CONNECTION_ERROR_CLIENT:
        case CommParam::LOGIN_AUTHENTICATION:
        case CommParam::HEARTBEAT_SEND_ETHERNET_SERVER:
        case CommParam::HEARTBEAT_SEND_ETHERNET_CLIENT:
        case CommParam::HEARTBEAT_RESET_ON_DATA_TX:
        case CommParam::PLC_LINK_TIMING_INPUT:
        case CommParam::PLC_LINK_ERROR_ON_FAILURE:
        case CommParam::ETHERNET_IP_HANDSHAKE:
        case CommParam::ETHERNET_IP_BYTE_SWAPPING:
        case CommParam::PROFINET_HANDSHAKE:
        case CommParam::FTP_PASSIVE_MODE:
        case CommParam::FTP_HOST_CONNECTION_ERROR:
        case CommParam::FTP_SUBFOLDER:
        case CommParam::FTP_HISTORY_DATA_TX:
        case CommParam::FTP_DATA_TX:
        case CommParam::FTP_DATA_PASSIVE_MODE:
        case CommParam::FTP_DATA_APPEND_PRECEDING:
        case CommParam::FTP_DATA_SUBFOLDER:
        case CommParam::FTP_DATA_HOST_CONNECTION_ERROR:
        case CommParam::SFTP:
        case CommParam::SR_WEB_TOOL:
        case CommParam::SR_WEB_PASSWORD_AUTH:
        case CommParam::HTTPS:
        case CommParam::VNC_SERVER:
            return ParamType::TOGGLE;

        case CommParam::BAUD_RATE_HIGH:
            return ParamType::BAUD_RATE_HIGH;

        case CommParam::BAUD_RATE_LOW:
            return ParamType::BAUD_RATE_LOW;

        case CommParam::DATA_LENGTH:
            return ParamType::DATA_LENGTH;

        case CommParam::PARITY_CHECK:
            return ParamType::PARITY_CHECK;

        case CommParam::STOP_BIT_LENGTH:
            return ParamType::STOP_BIT_LENGTH;

        case CommParam::COMM_PROTOCOL:
            return ParamType::COMM_PROTOCOL;

        case CommParam::ETHERNET_COMMAND:
            return ParamType::ETHERNET_COMMAND_MODE;

        case CommParam::ETHERNET_DATA_CLIENT:
            return ParamType::ETHERNET_DATA_CLIENT_MODE;

        case CommParam::TCP_CLIENT_CONNECTION_TIMING:
            return ParamType::TCP_CLIENT_CONNECTION_TIMING;

        case CommParam::PLC_PROTOCOL:
            return ParamType::PLC_PROTOCOL;

        case CommParam::FTP_CONNECTION_TIMING:
        case CommParam::FTP_DATA_CONNECTION_TIMING:
            return ParamType::FTP_CONNECTION_TIMING;

        case CommParam::FTP_SUBFOLDER_NAME_METHOD:
            return ParamType::SUBFOLDER_NAME_METHOD;

        case CommParam::MASTER_SLAVE_OPERATION:
            return ParamType::MASTER_SLAVE_OPERATION;

        // Raw integer
        default:
            return ParamType::INT;
    }
}

}  // namespace OpenSRX
