/*
 * uFCoder.h
 *
 * library version: 5.0.10
 *
 * Created on:  2009-01-14
 * Last edited: 2019-06-20
 *
 * Author: D-Logic
 */

#ifndef uFCoder_H_
#define uFCoder_H_

#include <stdint.h>
#include <stddef.h>

#define IN
#define OUT
#define VAR


////////////////////////////////////////////////////////////////////
/**
 * Type for representing null terminated char array ( aka C-String )
 * Array is always one byte longer ( for null character ) then string
 * Memory space for array must be allocated before use.
 */
typedef const char * c_string;
////////////////////////////////////////////////////////////////////

#ifdef _WIN32
// WINDOWS
#	if defined(DL_CREATE_STATIC_LIB) || defined(DL_USE_STATIC_LIB)
#		define DL_API
#	else
#		ifndef DL_uFC_EXPORTS
#			ifdef _WIN_IOT
#				define DL_API __declspec(dllimport)						// Win IoT
#			else
#				define DL_API /*__declspec(dllimport) */ __stdcall		// STDCALL - GCC - .NET
#			endif //  _WIN_IOT
#		else
#			define DL_API __declspec(dllexport) __stdcall
#		endif // DL_uFC_EXPORTS
#	endif // DL_CREATE_STATIC_LIB
#else
// Linux & MAC OS
#	define DL_API
#endif // _WIN32

#if defined(DL_uFC_EXPORTS) || defined(DL_CREATE_STATIC_LIB)
	typedef struct S_UFR_HANDLE * UFR_HANDLE;
#else
	typedef void * UFR_HANDLE;
#endif

// MIFARE CLASSIC type id's:
#define MIFARE_CLASSIC_1k               0x08
#define MF1ICS50                        0x08
#define SLE66R35                        0x88 // Infineon = Mifare Classic 1k
#define MIFARE_CLASSIC_4k               0x18
#define MF1ICS70                        0x18
#define MIFARE_CLASSIC_MINI             0x09
#define MF1ICS20                        0x09

//DLOGIC CARD TYPE
#define TAG_UNKNOWN						0
#define DL_MIFARE_ULTRALIGHT			0x01
#define DL_MIFARE_ULTRALIGHT_EV1_11		0x02
#define DL_MIFARE_ULTRALIGHT_EV1_21		0x03
#define DL_MIFARE_ULTRALIGHT_C			0x04
#define DL_NTAG_203						0x05
#define DL_NTAG_210						0x06
#define DL_NTAG_212						0x07
#define DL_NTAG_213						0x08
#define DL_NTAG_215						0x09
#define DL_NTAG_216						0x0A
#define DL_MIKRON_MIK640D				0x0B
#define NFC_T2T_GENERIC					0x0C
#define DL_NT3H_1101                    0x0D
#define DL_NT3H_1201                    0x0E
#define DL_NT3H_2111                    0x0F
#define DL_NT3H_2211                    0x10

#define DL_MIFARE_MINI					0x20
#define	DL_MIFARE_CLASSIC_1K			0x21
#define DL_MIFARE_CLASSIC_4K			0x22
#define DL_MIFARE_PLUS_S_2K_SL0			0x23
#define DL_MIFARE_PLUS_S_4K_SL0			0x24
#define DL_MIFARE_PLUS_X_2K_SL0			0x25
#define DL_MIFARE_PLUS_X_4K_SL0			0x26
#define DL_MIFARE_DESFIRE				0x27
#define DL_MIFARE_DESFIRE_EV1_2K		0x28
#define DL_MIFARE_DESFIRE_EV1_4K		0x29
#define DL_MIFARE_DESFIRE_EV1_8K		0x2A
#define DL_MIFARE_DESFIRE_EV2_2K		0x2B
#define DL_MIFARE_DESFIRE_EV2_4K		0x2C
#define DL_MIFARE_DESFIRE_EV2_8K		0x2D
#define DL_MIFARE_PLUS_S_2K_SL1			0x2E
#define DL_MIFARE_PLUS_X_2K_SL1			0x2F
#define DL_MIFARE_PLUS_EV1_2K_SL1       0x30
#define DL_MIFARE_PLUS_X_2K_SL2			0x31
#define DL_MIFARE_PLUS_S_2K_SL3			0x32
#define DL_MIFARE_PLUS_X_2K_SL3			0x33
#define DL_MIFARE_PLUS_EV1_2K_SL3       0x34
#define DL_MIFARE_PLUS_S_4K_SL1			0x35
#define DL_MIFARE_PLUS_X_4K_SL1			0x36
#define DL_MIFARE_PLUS_EV1_4K_SL1       0x37
#define DL_MIFARE_PLUS_X_4K_SL2			0x38
#define DL_MIFARE_PLUS_S_4K_SL3			0x39
#define DL_MIFARE_PLUS_X_4K_SL3			0x3A
#define DL_MIFARE_PLUS_EV1_4K_SL3       0x3B

#define DL_UNKNOWN_ISO_14443_4			0x40
#define DL_GENERIC_ISO14443_4			0x40
#define DL_GENERIC_ISO14443_4_TYPE_B	0x41
#define	DL_GENERIC_ISO14443_3_TYPE_B	0x42
#define DL_IMEI_UID						0x80

// ST Product ID-s:
#define M24SR02							0x82
#define M24SR02_AUTOMOTIVE				0x8A
#define M24SR04							0x86
#define M24SR04_AUTOMOTIVE				0x8E
#define M24SR16							0x85
#define M24SR16_AUTOMOTIVE				0x8D
#define M24SR64							0x84
#define M24SR64_AUTOMOTIVE				0x8C

// DLJavaCardTypes:
#define DLSigner81	0xA0
#define DLSigner22	0xA1
#define DLSigner30	0xA2
#define DLSigner10	0xA3
#define DLSigner145	0xAA

// DLJavaCardSignerAlgorithmTypes:
enum E_SIGNER_CIPHERS {
	SIG_CIPHER_RSA = 0,
	SIG_CIPHER_ECDSA,

	SIG_CIPHER_MAX_SUPPORTED
};

enum E_SIGNER_PADDINGS {
	PAD_NULL = 0,
	PAD_PKCS1,

	SIG_PAD_MAX_SUPPORTED
};

enum E_SIGNER_DIGESTS {
	ALG_NULL = 0,
	ALG_SHA,
	ALG_SHA_256,
	ALG_SHA_384,
	ALG_SHA_512,
	ALG_SHA_224,

	SIG_DIGEST_MAX_SUPPORTED
};

enum E_KEY_TYPES {
	TYPE_RSA_PRIVATE = 0,
	TYPE_RSA_CRT_PRIVATE,
	TYPE_EC_F2M_PRIVATE,
	TYPE_EC_FP_PRIVATE
};

enum E_OBJ_TYPES {
	OBJ_TYPE_RSA_CERT = 0,
	OBJ_TYPE_EC_CERT,
	OBJ_TYPE_CA_CERT,

	OBJ_TYPES_COUNT
};

// JCDL_AIDs
#define DL_RAW_SIZEOF_SZ(x)	(sizeof(x) - 1)
#define DL_AID_RID_PLUS 	"\xF0" "DLogic"
#define DL_SIGNER_PIX		"\x00\x01"
#define DL_STORAGE_PIX		"\x01\x01"
#define DL_SIGNER_AID		DL_AID_RID_PLUS  DL_SIGNER_PIX
#define DL_SIGNER_AID_SIZE	9
#define DL_STORAGE_AID		DL_AID_RID_PLUS  DL_STORAGE_PIX
#define DL_STORAGE_AID_SIZE	9

// Universal JCDL instructions:
#define INS_LOGIN					0x20
#define INS_GET_PIN_TRIES_REMAINING 0x21
#define INS_PIN_CHANGE				0x22
#define INS_PIN_UNBLOCK				0x23

// JCDLStorage instructions:
#define INS_PIN_ENABLE				0x24
#define INS_PIN_DISABLE				0x25
#define INS_LIST_FILES				0x31
#define INS_GET_FILE_SIZE			0x32
#define INS_READ_FILE				0x33
#define INS_WRITE_FILE				0x34
#define INS_DELETE_FILE				0x3F

// JCDLSigner instructions:
#define INS_SET_RSA_PRIKEY			0x51
#define INS_GEN_RSA_KEY_PAIR		0x52
#define INS_GET_RSA_PUBKEY_MODULUS	0x53
#define INS_GET_RSA_PUBKEY_EXPONENT	0x54
#define INS_DEL_RSA_KEY_PAIR		0x5F
#define INS_SET_EC_PRIKEY			0x61
#define INS_GEN_EC_KEY_PAIR			0x62
#define INS_GET_EC_PUBKEY			0x63
#define INS_GET_EC_FIELD			0x64
#define INS_GET_EC_AB				0x65
#define INS_GET_EC_G				0x66
#define INS_GET_EC_RK_SIZE			0x67
#define INS_DEL_EC_KEY_PAIR			0x6F
#define INS_GET_SIGNATURE			0x71
#define INS_PUT_OBJ					0x31
#define INS_PUT_OBJ_SUBJECT			0x32
#define INS_INVALIDATE_CERT			0x33
#define INS_GET_OBJ					0x41
#define INS_GET_OBJ_ID				0x42
#define INS_GET_OBJ_SUBJECT			0x43

// Universal JCDL constants:
#define PIN_MAX_TRIES				5
#define PIN_MIN_LENGTH				4
#define PIN_MAX_LENGTH				8
#define PUK_MAX_TRIES				10
#define PUK_LENGTH					8

// JCDLSigner constants:
#define JC_APP_MAX_KEY_INDEX		((3) - 1)
#define JC_APP_MAX_CA_CERT_INDEX	((12) - 1)
#define JC_APP_MAX_ID_SIZE			253
#define JC_APP_MAX_SUBJECT_SIZE		255
#define JC_APP_MAX_SIGNATURE_LEN	256
#define JC_APP_MAX_PIN_LENGTH		8

// JCDLStorage constants:
#define JC_DL_STORAGE_MAX_FILES		16
#define JC_DL_STORAGE_MAX_FILE_SIZE	(32 * 1024 - 2) // 32KB - 2 byte system reserved

// MIFARE CLASSIC Authentication Modes:
enum MIFARE_AUTHENTICATION
{
	MIFARE_AUTHENT1A = 0x60,
	MIFARE_AUTHENT1B = 0x61,
};

//MIFARE PLUS AES Authentication Modes:
enum MIFARE_PLUS_AES_AUTHENTICATION
{
	MIFARE_PLUS_AES_AUTHENT1A = 0x80,
	MIFARE_PLUS_AES_AUTHENT1B = 0x81,
};

// T2T authentication constants:
enum T2T_AUTHENTICATION
{
	T2T_NO_PWD_AUTH	= 0,
	T2T_RKA_PWD_AUTH = 1,
	T2T_PK_PWD_AUTH = 3,
	T2T_WITHOUT_PWD_AUTH = 0x60,
	T2T_WITH_PWD_AUTH = 0x61,
};

enum ADDRESS_MODE
{
	ADDRESS_MODE_BLOCK = 0,
	ADDRESS_MODE_SECTOR,
};

#define MAX_UID_LEN		10
#define ECC_SIG_LEN		32

// API Status Codes Type:
typedef enum UFCODER_ERROR_CODES
{
	UFR_OK = 0x00,
	UFR_COMMUNICATION_ERROR = 0x01,
	UFR_CHKSUM_ERROR = 0x02,
	UFR_READING_ERROR = 0x03,
	UFR_WRITING_ERROR = 0x04,
	UFR_BUFFER_OVERFLOW = 0x05,
	UFR_MAX_ADDRESS_EXCEEDED = 0x06,
	UFR_MAX_KEY_INDEX_EXCEEDED = 0x07,
	UFR_NO_CARD = 0x08,
	UFR_COMMAND_NOT_SUPPORTED = 0x09,
	UFR_FORBIDEN_DIRECT_WRITE_IN_SECTOR_TRAILER = 0x0A,
	UFR_ADDRESSED_BLOCK_IS_NOT_SECTOR_TRAILER = 0x0B,
	UFR_WRONG_ADDRESS_MODE = 0x0C,
	UFR_WRONG_ACCESS_BITS_VALUES = 0x0D,
	UFR_AUTH_ERROR = 0x0E,
	UFR_PARAMETERS_ERROR = 0x0F, // ToDo, point 5.
	UFR_MAX_SIZE_EXCEEDED = 0x10,
	UFR_UNSUPPORTED_CARD_TYPE = 0x11,

	UFR_COMMUNICATION_BREAK = 0x50,
	UFR_NO_MEMORY_ERROR = 0x51,
	UFR_CAN_NOT_OPEN_READER = 0x52,
	UFR_READER_NOT_SUPPORTED = 0x53,
	UFR_READER_OPENING_ERROR = 0x54,
	UFR_READER_PORT_NOT_OPENED = 0x55,
	UFR_CANT_CLOSE_READER_PORT = 0x56,

	UFR_WRITE_VERIFICATION_ERROR = 0x70,
	UFR_BUFFER_SIZE_EXCEEDED = 0x71,
	UFR_VALUE_BLOCK_INVALID = 0x72,
	UFR_VALUE_BLOCK_ADDR_INVALID = 0x73,
	UFR_VALUE_BLOCK_MANIPULATION_ERROR = 0x74,
	UFR_WRONG_UI_MODE = 0x75,
	UFR_KEYS_LOCKED = 0x76,
	UFR_KEYS_UNLOCKED = 0x77,
	UFR_WRONG_PASSWORD = 0x78,
	UFR_CAN_NOT_LOCK_DEVICE = 0x79,
	UFR_CAN_NOT_UNLOCK_DEVICE = 0x7A,
	UFR_DEVICE_EEPROM_BUSY = 0x7B,
	UFR_RTC_SET_ERROR = 0x7C,

	ANTI_COLLISION_DISABLED = 0x7D,
	NO_TAGS_ENUMERRATED = 0x7E,
	CARD_ALREADY_SELECTED = 0x7F,

	// NDEF error codes
	UFR_WRONG_NDEF_CARD_FORMAT = 0x80,
	UFR_NDEF_MESSAGE_NOT_FOUND = 0x81,
	UFR_NDEF_UNSUPPORTED_CARD_TYPE = 0x82,
	UFR_NDEF_CARD_FORMAT_ERROR = 0x83,
	UFR_MAD_NOT_ENABLED = 0x84,
	UFR_MAD_VERSION_NOT_SUPPORTED = 0x85,

	// Tag emulation mode errors:
	FORBIDDEN_IN_TAG_EMULATION_MODE = 0x90,

	// FTDI errors:
	UFR_FT_STATUS_ERROR_1 = 0xA0,
	UFR_FT_STATUS_ERROR_2 = 0xA1,
	UFR_FT_STATUS_ERROR_3 = 0xA2,
	UFR_FT_STATUS_ERROR_4 = 0xA3,
	UFR_FT_STATUS_ERROR_5 = 0xA4,
	UFR_FT_STATUS_ERROR_6 = 0xA5,
	UFR_FT_STATUS_ERROR_7 = 0xA6,
	UFR_FT_STATUS_ERROR_8 = 0xA7,
	UFR_FT_STATUS_ERROR_9 = 0xA8,

	//MIFARE PLUS error codes
	UFR_MFP_COMMAND_OVERFLOW = 0xB0,
	UFR_MFP_INVALID_MAC = 0xB1,
	UFR_MFP_INVALID_BLOCK_NR = 0xB2,
	UFR_MFP_NOT_EXIST_BLOCK_NR = 0xB3,
	UFR_MFP_COND_OF_USE_ERROR =	0xB4,
	UFR_MFP_LENGTH_ERROR = 	0xB5,
	UFR_MFP_GENERAL_MANIP_ERROR = 0xB6,
	UFR_MFP_SWITCH_TO_ISO14443_4_ERROR = 0xB7,
	UFR_MFP_ILLEGAL_STATUS_CODE = 0xB8,
	UFR_MFP_MULTI_BLOCKS_READ = 0xB9,

	// multiple units - return from the functions with ReaderList_ prefix in name
	UFR_DEVICE_WRONG_HANDLE = 0x100,
	UFR_DEVICE_INDEX_OUT_OF_BOUND,
	UFR_DEVICE_ALREADY_OPENED,
	UFR_DEVICE_ALREADY_CLOSED,
	UFR_DEVICE_IS_NOT_CONNECTED,

	// Originality Check Error Codes:
	UFR_NOT_NXP_GENUINE = 0x200,
	UFR_OPEN_SSL_DYNAMIC_LIB_FAILED,
	UFR_OPEN_SSL_DYNAMIC_LIB_NOT_FOUND,

	// DESFIRE Card Status Error Codes:
	READER_ERROR = 0xBB7,					// 2999 [dec]
	NO_CARD_DETECTED = 0xBB8,				// 3000 [dec]
	CARD_OPERATION_OK = 0xBB9,				// 3001 [dec]
	WRONG_KEY_TYPE = 0xBBA,					// 3002 [dec]
	KEY_AUTH_ERROR = 0xBBB,					// 3003 [dec]
	CARD_CRYPTO_ERROR = 0xBBC,				// 3004 [dec]
	READER_CARD_COMM_ERROR = 0xBBD,			// 3005 [dec]
	PC_READER_COMM_ERROR = 0xBBE,			// 3006 [dec]
	COMMIT_TRANSACTION_NO_REPLY = 0xBBF,	// 3007 [dec]
	COMMIT_TRANSACTION_ERROR = 0xBC0,		// 3008 [dec]

	DESFIRE_CARD_NO_CHANGES = 0x0C0C,
	DESFIRE_CARD_OUT_OF_EEPROM_ERROR = 0x0C0E,
	DESFIRE_CARD_ILLEGAL_COMMAND_CODE = 0x0C1C,
	DESFIRE_CARD_INTEGRITY_ERROR = 0x0C1E,
	DESFIRE_CARD_NO_SUCH_KEY = 0x0C40,
	DESFIRE_CARD_LENGTH_ERROR = 0x0C7E,
	DESFIRE_CARD_PERMISSION_DENIED = 0x0C9D,
	DESFIRE_CARD_PARAMETER_ERROR = 0x0C9E,
	DESFIRE_CARD_APPLICATION_NOT_FOUND = 0x0CA0,
	DESFIRE_CARD_APPL_INTEGRITY_ERROR = 0x0CA1,
	DESFIRE_CARD_AUTHENTICATION_ERROR = 0x0CAE,
	DESFIRE_CARD_ADDITIONAL_FRAME = 0x0CAF,
	DESFIRE_CARD_BOUNDARY_ERROR = 0x0CBE,
	DESFIRE_CARD_PICC_INTEGRITY_ERROR = 0x0CC1,
	DESFIRE_CARD_COMMAND_ABORTED = 0x0CCA,
	DESFIRE_CARD_PICC_DISABLED_ERROR = 0x0CCD,
	DESFIRE_CARD_COUNT_ERROR = 0x0CCE,
	DESFIRE_CARD_DUPLICATE_ERROR = 0x0CDE,
	DESFIRE_CARD_EEPROM_ERROR_DES = 0x0CEE,
	DESFIRE_CARD_FILE_NOT_FOUND = 0x0CF0,
	DESFIRE_CARD_FILE_INTEGRITY_ERROR = 0x0CF1,

	// uFCoder library errors:
	UFR_NOT_IMPLEMENTED = 0x1000,
	UFR_COMMAND_FAILED = 0x1001,
	UFR_TIMEOUT_ERR = 0x1002,
	UFR_FILE_SYSTEM_ERROR = 0x1003,
	UFR_FILE_SYSTEM_PATH_NOT_EXISTS = 0x1004,
	UFR_FILE_NOT_EXISTS = 0x1005,

	// JC cards APDU Error Codes:
	UFR_APDU_TRANSCEIVE_ERROR = 0xAE,
	UFR_APDU_JC_APP_NOT_SELECTED  = 0x6000,
	UFR_APDU_JC_APP_BUFF_EMPTY,
	UFR_APDU_WRONG_SELECT_RESPONSE,
	UFR_APDU_WRONG_KEY_TYPE,
	UFR_APDU_WRONG_KEY_SIZE,
	UFR_APDU_WRONG_KEY_PARAMS,
	UFR_APDU_WRONG_SIGNING_ALGORITHM,
	UFR_APDU_PLAIN_TEXT_MAX_SIZE_EXCEEDED,
	UFR_APDU_UNSUPPORTED_KEY_SIZE,
	UFR_APDU_UNSUPPORTED_ALGORITHMS,
	UFR_APDU_PKI_OBJECT_NOT_FOUND,
	UFR_APDU_MAX_PIN_LENGTH_EXCEEDED,
	UFR_DIGEST_LENGTH_DOES_NOT_MATCH,

	// ISO7816-4 Errors (R-APDU) - 2 SW bytes returned by the card, prefixed with 0x000A:
	UFR_APDU_SW_TAG = 0x000A0000,
	UFR_APDU_SW_WRONG_LENGTH = 0x000A6700,
	UFR_APDU_SW_SECURITY_STATUS_NOT_SATISFIED = 0x000A6982,
	UFR_APDU_SW_AUTHENTICATION_METHOD_BLOCKED = 0x000A6983,
	UFR_APDU_SW_DATA_INVALID = 0x000A6984,
	UFR_APDU_SW_CONDITIONS_NOT_SATISFIED = 0x000A6985,
	UFR_APDU_SW_WRONG_DATA = 0x000A6A80,
	UFR_APDU_SW_FILE_NOT_FOUND = 0x000A6A82,
	UFR_APDU_SW_RECORD_NOT_FOUND = 0x000A6A83,
	UFR_APDU_SW_DATA_NOT_FOUND = 0x000A6A88,
	UFR_APDU_SW_ENTITY_ALREADY_EXISTS = 0x000A6A89,
	UFR_APDU_SW_INS_NOT_SUPPORTED = 0x000A6D00,
	UFR_APDU_SW_NO_PRECISE_DIAGNOSTIC = 0x000A6F00,

	MAX_UFR_STATUS = 0x7FFFFFFF

} UFR_STATUS;

//DESFIRE key settings values
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_CHANGE				0x09
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_CHANGE			0x0F
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_CHANGE			0x01
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_CHANGE		0x07
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_NOT_CHANGE			0x08
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_NOT_CHANGE		0x0E
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE		0x00
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE	0x06

#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_CHANGE_APP_IDS_WITH_AUTH				0x09
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_CHANGE_APP_IDS_WIDTHOUT_AUTH			0x0F
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_CHANGE_APP_IDS_WITH_AUTH			0x01
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_CHANGE_APP_IDS_WIDTHOUT_AUTH		0x07
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_NOT_CHANGE_APP_IDS_WITH_AUTH			0x08
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_NOT_CHANGE_APP_IDS_WIDTHOUT_AUTH		0x0E
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE_APP_IDS_WITH_AUTH		0x00
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE_APP_IDS_WIDTHOUT_AUTH	0x06
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_CHANGE_APP_IDS_WIDTHOUT_AUTH			0x0B
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_CHANGE_APP_IDS_WIDTHOUT_AUTH		0x02
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_NOT_CHANGE_APP_IDS_WIDTHOUT_AUTH		0x0A
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE_APP_IDS_WIDTHOUT_AUTH	0x02


enum E_ASYMMETRIC_KEY_TYPES {
	RSA_PRIVATE_KEY = 0,
	ECDSA_PRIVATE_KEY,

	ASYMMETRIC_KEY_TYPES_NUM
};

typedef enum {
	USER_PIN = 0,
	SO_PIN,
	USER_PUK,
	SO_PUK
} dl_sec_code_t;

//SAM definition
typedef enum E_SAM_HW_VER {
	SAM_UNKNOWN_TYPE,
	SAM_T1AD2060_AV1_MODE ,
	SAM_T1AD2060_AV2_MODE,
	SAM_T1AR1070_AV1_MODE,
	SAM_T1AR1070_AV2_MODE
}SAM_HW_TYPE;

#ifdef __cplusplus
extern "C"
{
#endif

//--------------------------------------------------------------------------------------------------

UFR_STATUS DL_API ReaderOpen(void);

/**
 * Useful for speed up opening for non uFR basic reader type
 *
 * @param reader_type : 0 : auto > same as call ReaderOpen()
 *                      1 : uFR type (1 Mbps)
 *                      2 : uFR RS232 type (115200 bps)
 *                      3 : BASE HD uFR (XRC) type (250 Kbps)
 * @return
 */
UFR_STATUS DL_API ReaderOpenByType(uint32_t reader_type);

/**
 * ReaderOpenEx() is a function for opening port with
 *
 * @param reader_type : 0 : auto > same as call ReaderOpen()
 *                      1 : uFR type (1 Mbps)
 *                      2 : uFR RS232 type (115200 bps)
 *                      3 : BASE HD uFR (XRC) type (250 Kbps)
 * @param port_name : serial port name, identifier, like
 *                      "COM3" on Window or
 *                      "/dev/ttyS0" on Linux or
 *                      "/dev/tty.serial1" on OS X
 *                      or if you select FTDI
 *                      "UN123456" if Reader have integrated FTDI interface
 *                      "192.168.1.162:8881" IP adress:port for TCP/IP or UDP I/F
 * @param port_interface : type of communication interfaces
 *                      0 : auto - first try FTDI than serial if no port_name defined
 *                      1 : try serial / virtual COM port / interfaces
 *                      2 : try only FTDI communication interfaces
 *                      // Digital Logic Shields
 *                      10 : open Digital Logic Shields with RS232 uFReader on Raspberry Pi (serial interfaces with GPIO reset)
 *                      84 ('T') : TCP/IP interface
 *                      85 ('U') : UDP interface
 * @param arg : additional settings in c-string format:
 *                      "UNIT_OPEN_RESET_DISABLE" : do not reset the reader when opening
 *                      "UNIT_OPEN_RESET_FORCE"   : force reset the reader when opening
 *                      "READER_ACTIVE_ON_RTS_LOW"  : (default) Reset the reader when RTS is high - the reader works when RTS is low
 *                      "READER_ACTIVE_ON_RTS_HIGH" : Reset the reader when RTS is low - the reader works when RTS is high
 *                      "RTS_ALWAYS_HIGH"           : not implemented yet
 *                      "RTS_ALWAYS_LOW"            : not implemented yet
 *                      "RTS_DISCONNECTED"          : disconnect RTS (RTS is not initiate nor use)
 *
 * @return
 */
UFR_STATUS DL_API ReaderOpenEx(uint32_t reader_type,
							   IN c_string port_name,
		                       uint32_t port_interface,
							   IN void *arg);

UFR_STATUS DL_API ReaderReset(void);
UFR_STATUS DL_API ReaderClose(void);
UFR_STATUS DL_API ReaderSoftRestart(void);
UFR_STATUS DL_API ReaderHwReset(void);
UFR_STATUS DL_API GetReaderType(IN uint32_t *lpulReaderType);
UFR_STATUS DL_API GetReaderSerialNumber(IN uint32_t *lpulSerialNumber);

UFR_STATUS DL_API ReaderStillConnected(VAR uint32_t *connected);

UFR_STATUS DL_API ReaderKeyWrite(IN const uint8_t *aucKey, uint8_t ucKeyIndex);
UFR_STATUS DL_API ReaderKeysLock(IN const uint8_t *password);
UFR_STATUS DL_API ReaderKeysUnlock(IN const uint8_t *password);
UFR_STATUS DL_API ReaderUISignal(uint8_t light_signal_mode,
                                     uint8_t beep_signal_mode);
UFR_STATUS DL_API ReadUserData(OUT uint8_t *aucData);
UFR_STATUS DL_API WriteUserData(IN const uint8_t *aucData);
UFR_STATUS DL_API GetCardId(VAR uint8_t *lpucCardType, OUT uint32_t *lpulCardSerial);
UFR_STATUS DL_API BlockRead(OUT uint8_t *data,
                                uint8_t block_address,
                                uint8_t auth_mode,
                                uint8_t key_index);
UFR_STATUS DL_API BlockWrite(IN const uint8_t *data,
                                 uint8_t block_address,
                                 uint8_t auth_mode,
                                 uint8_t key_index);
UFR_STATUS DL_API BlockInSectorRead(OUT uint8_t *data,
                                        uint8_t sector_address,
                                        uint8_t block_in_sector_address,
                                        uint8_t auth_mode,
                                        uint8_t key_index);
UFR_STATUS DL_API BlockInSectorWrite(IN const uint8_t *data,
                                         uint8_t sector_address,
                                         uint8_t block_in_sector_address,
                                         uint8_t auth_mode,
                                         uint8_t key_index);
UFR_STATUS DL_API LinearRead(OUT uint8_t *aucData,
                                 uint16_t usLinearAddress,
                                 uint16_t usDataLength,
                             VAR uint16_t *lpusBytesReturned,
                                 uint8_t ucKeyMode,
                                 uint8_t ucReaderKeyIndex);
UFR_STATUS DL_API LinRowRead(OUT uint8_t *aucData,
                                 uint16_t usLinearAddress,
                                 uint16_t usDataLength,
                             VAR uint16_t *lpusBytesReturned,
                                 uint8_t ucKeyMode,
                                 uint8_t ucReaderKeyIndex);
UFR_STATUS DL_API LinearWrite(IN const uint8_t *aucData,
                                  uint16_t usLinearAddress,
                                  uint16_t usDataLength,
                              VAR uint16_t *lpusBytesWritten,
                                  uint8_t ucKeyMode,
                                  uint8_t ucReaderKeyIndex);
UFR_STATUS DL_API LinearFormatCard(IN const uint8_t *new_key_A,
                                       uint8_t blocks_access_bits,
                                       uint8_t sector_trailers_access_bits,
                                       uint8_t sector_trailers_byte9,
                                   IN  const uint8_t *new_key_B,
                                   VAR uint8_t *lpucSectorsFormatted,
                                       uint8_t auth_mode,
                                       uint8_t key_index);
UFR_STATUS DL_API SectorTrailerWrite(uint8_t addressing_mode,
                                         uint8_t address,
                                     IN const uint8_t *new_key_A,
                                         uint8_t block0_access_bits,
                                         uint8_t block1_access_bits,
                                         uint8_t block2_access_bits,
                                         uint8_t sector_trailer_access_bits,
                                         uint8_t sector_trailer_byte9,
                                      IN const uint8_t *new_key_B,
                                         uint8_t auth_mode,
                                         uint8_t key_index);
UFR_STATUS DL_API SectorTrailerWriteUnsafe(uint8_t addressing_mode,
                                               uint8_t address,
                                              IN const uint8_t *sector_trailer,
                                               uint8_t auth_mode,
                                               uint8_t key_index);
UFR_STATUS DL_API ValueBlockRead(VAR int32_t *value,
                                     VAR uint8_t *value_addr,
                                     uint8_t block_address,
                                     uint8_t auth_mode,
                                     uint8_t key_index);
UFR_STATUS DL_API ValueBlockInSectorRead(VAR int32_t *value,
                                             VAR uint8_t *value_addr,
                                             uint8_t sector_address,
                                             uint8_t block_in_sector_address,
                                             uint8_t auth_mode,
                                             uint8_t key_index);
UFR_STATUS DL_API ValueBlockWrite(int32_t value,
                                      uint8_t value_addr,
                                      uint8_t block_address,
                                      uint8_t auth_mode,
                                      uint8_t key_index);
UFR_STATUS DL_API ValueBlockInSectorWrite(int32_t value,
                                              uint8_t value_addr,
                                              uint8_t sector_address,
                                              uint8_t block_in_sector_address,
                                              uint8_t auth_mode,
                                              uint8_t key_index);
UFR_STATUS DL_API ValueBlockIncrement(int32_t increment_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode,
                                          uint8_t key_index);
UFR_STATUS DL_API ValueBlockInSectorIncrement(int32_t increment_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode,
                                                  uint8_t key_index);
UFR_STATUS DL_API ValueBlockDecrement(int32_t decrement_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode,
                                          uint8_t key_index);
UFR_STATUS DL_API ValueBlockInSectorDecrement(int32_t decrement_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode,
                                                  uint8_t key_index);

UFR_STATUS DL_API BlockRead_AKM1(OUT uint8_t *data,
                                    uint8_t block_address,
                                    uint8_t auth_mode);
UFR_STATUS DL_API BlockWrite_AKM1(IN const uint8_t *data,
                                 uint8_t block_address,
                                 uint8_t auth_mode);
UFR_STATUS DL_API BlockInSectorRead_AKM1(OUT uint8_t *data,
                                        uint8_t sector_address,
                                        uint8_t block_in_sector_address,
                                        uint8_t auth_mode);
UFR_STATUS DL_API BlockInSectorWrite_AKM1(IN const uint8_t *data,
                                         uint8_t sector_address,
                                         uint8_t block_in_sector_address,
                                         uint8_t auth_mode);
UFR_STATUS DL_API LinearRead_AKM1(OUT uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 VAR uint16_t *bytes_returned,
                                 uint8_t auth_mode);
UFR_STATUS DL_API LinRowRead_AKM1(OUT uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 VAR uint16_t *bytes_returned,
                                 uint8_t auth_mode);
UFR_STATUS DL_API LinearWrite_AKM1(IN const uint8_t *data,
                                  uint16_t linear_address,
                                  uint16_t length,
                                  VAR uint16_t *bytes_written,
                                  uint8_t auth_mode);
UFR_STATUS DL_API LinearFormatCard_AKM1(IN const uint8_t *new_key_A,
                                       uint8_t blocks_access_bits,
                                       uint8_t sector_trailers_access_bits,
                                       uint8_t sector_trailers_byte9,
                                       IN const uint8_t *new_key_B,
                                       VAR uint8_t *lpucSectorsFormatted,
                                       uint8_t auth_mode);
UFR_STATUS DL_API SectorTrailerWrite_AKM1(uint8_t addressing_mode,
                                         uint8_t address,
                                         IN const uint8_t *new_key_A,
                                         uint8_t block0_access_bits,
                                         uint8_t block1_access_bits,
                                         uint8_t block2_access_bits,
                                         uint8_t sector_trailer_access_bits,
                                         uint8_t sector_trailer_byte9,
                                         IN const uint8_t *new_key_B,
                                         uint8_t auth_mode);
UFR_STATUS DL_API SectorTrailerWriteUnsafe_AKM1(uint8_t addressing_mode,
                                               uint8_t address,
                                               IN const uint8_t *sector_trailer,
                                               uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockRead_AKM1(VAR int32_t *value,
                                     VAR uint8_t *value_addr,
                                     uint8_t block_address,
                                     uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockInSectorRead_AKM1(VAR int32_t *value,
                                             VAR uint8_t *value_addr,
                                             uint8_t sector_address,
                                             uint8_t block_in_sector_address,
                                             uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockWrite_AKM1(int32_t value,
                                      uint8_t value_addr,
                                      uint8_t block_address,
                                      uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockInSectorWrite_AKM1(int32_t value,
                                              uint8_t value_addr,
                                              uint8_t sector_address,
                                              uint8_t block_in_sector_address,
                                              uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockIncrement_AKM1(int32_t increment_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockInSectorIncrement_AKM1(int32_t increment_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockDecrement_AKM1(int32_t decrement_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockInSectorDecrement_AKM1(int32_t decrement_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);

UFR_STATUS DL_API BlockRead_AKM2(OUT uint8_t *data,
                                    uint8_t block_address,
                                    uint8_t auth_mode);
UFR_STATUS DL_API BlockWrite_AKM2(IN const uint8_t *data,
                                 uint8_t block_address,
                                 uint8_t auth_mode);
UFR_STATUS DL_API BlockInSectorRead_AKM2(OUT uint8_t *data,
                                        uint8_t sector_address,
                                        uint8_t block_in_sector_address,
                                        uint8_t auth_mode);
UFR_STATUS DL_API BlockInSectorWrite_AKM2(IN const uint8_t *data,
                                         uint8_t sector_address,
                                         uint8_t block_in_sector_address,
                                         uint8_t auth_mode);
UFR_STATUS DL_API LinearRead_AKM2(OUT uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 VAR uint16_t *bytes_returned,
                                 uint8_t auth_mode);
UFR_STATUS DL_API LinRowRead_AKM2(OUT uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 VAR uint16_t *bytes_returned,
                                 uint8_t auth_mode);
UFR_STATUS DL_API LinearWrite_AKM2(IN const uint8_t *data,
                                  uint16_t linear_address,
                                  uint16_t length,
                                  VAR uint16_t *bytes_written,
                                  uint8_t auth_mode);
UFR_STATUS DL_API LinearFormatCard_AKM2(IN const uint8_t *new_key_A,
                                       uint8_t blocks_access_bits,
                                       uint8_t sector_trailers_access_bits,
                                       uint8_t sector_trailers_byte9,
                                       IN const uint8_t *new_key_B,
                                       VAR uint8_t *lpucSectorsFormatted,
                                       uint8_t auth_mode);
UFR_STATUS DL_API SectorTrailerWrite_AKM2(uint8_t addressing_mode,
                                         uint8_t address,
                                         IN const uint8_t *new_key_A,
                                         uint8_t block0_access_bits,
                                         uint8_t block1_access_bits,
                                         uint8_t block2_access_bits,
                                         uint8_t sector_trailer_access_bits,
                                         uint8_t sector_trailer_byte9,
                                         IN const uint8_t *new_key_B,
                                         uint8_t auth_mode);
UFR_STATUS DL_API SectorTrailerWriteUnsafe_AKM2(uint8_t addressing_mode,
                                               uint8_t address,
                                               IN const uint8_t *sector_trailer,
                                               uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockRead_AKM2(VAR int32_t *value,
                                     VAR uint8_t *value_addr,
                                     uint8_t block_address,
                                     uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockInSectorRead_AKM2(VAR int32_t *value,
                                             VAR uint8_t *value_addr,
                                             uint8_t sector_address,
                                             uint8_t block_in_sector_address,
                                             uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockWrite_AKM2(int32_t value,
                                      uint8_t value_addr,
                                      uint8_t block_address,
                                      uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockInSectorWrite_AKM2(int32_t value,
                                              uint8_t value_addr,
                                              uint8_t sector_address,
                                              uint8_t block_in_sector_address,
                                              uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockIncrement_AKM2(int32_t increment_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockInSectorIncrement_AKM2(int32_t increment_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockDecrement_AKM2(int32_t decrement_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
UFR_STATUS DL_API ValueBlockInSectorDecrement_AKM2(int32_t decrement_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);

UFR_STATUS DL_API BlockRead_PK(OUT uint8_t *data,
                                   uint8_t block_address,
                                   uint8_t auth_mode,
                                   IN const uint8_t *key);
UFR_STATUS DL_API BlockWrite_PK(IN const uint8_t *data,
                                    uint8_t block_address,
                                    uint8_t auth_mode,
                                    IN const uint8_t *key);
UFR_STATUS DL_API BlockInSectorRead_PK(OUT uint8_t *data,
                                           uint8_t sector_address,
                                           uint8_t block_in_sector_address,
                                           uint8_t auth_mode,
                                           IN const uint8_t *key);
UFR_STATUS DL_API BlockInSectorWrite_PK(IN const uint8_t *data,
                                            uint8_t sector_address,
                                            uint8_t block_in_sector_address,
                                            uint8_t auth_mode,
                                            IN const uint8_t *key);
UFR_STATUS DL_API LinearRead_PK(OUT uint8_t *data,
                                    uint16_t linear_address,
                                    uint16_t length,
                                    VAR uint16_t *bytes_returned,
                                    uint8_t auth_mode,
                                    IN const uint8_t *key);
UFR_STATUS DL_API LinRowRead_PK(OUT uint8_t *data,
                                    uint16_t linear_address,
                                    uint16_t length,
                                    VAR uint16_t *bytes_returned,
                                    uint8_t auth_mode,
                                    IN const uint8_t *key);
UFR_STATUS DL_API LinearWrite_PK(IN const uint8_t *data,
                                     uint16_t linear_address,
                                     uint16_t length,
                                     VAR uint16_t *bytes_written,
                                     uint8_t auth_mode,
                                     IN const uint8_t *key);
UFR_STATUS DL_API LinearFormatCard_PK(IN const uint8_t *new_key_A,
                                          uint8_t blocks_access_bits,
                                          uint8_t sector_trailers_access_bits,
                                          uint8_t sector_trailers_byte9,
                                          IN const uint8_t *new_key_B,
                                          VAR uint8_t *lpucSectorsFormatted,
                                          uint8_t auth_mode,
                                          IN const uint8_t *key);
UFR_STATUS DL_API SectorTrailerWrite_PK(uint8_t addressing_mode,
                                            uint8_t address,
                                            IN const uint8_t *new_key_A,
                                            uint8_t block0_access_bits,
                                            uint8_t block1_access_bits,
                                            uint8_t block2_access_bits,
                                            uint8_t sector_trailer_access_bits,
                                            uint8_t sector_trailer_byte9,
                                            IN const uint8_t *new_key_B,
                                            uint8_t auth_mode,
                                            IN const uint8_t *key);
UFR_STATUS DL_API SectorTrailerWriteUnsafe_PK(uint8_t addressing_mode,
                                                  uint8_t address,
                                                  IN const uint8_t *sector_trailer,
                                                  uint8_t auth_mode,
                                                  IN const uint8_t *key);
UFR_STATUS DL_API ValueBlockRead_PK(VAR int32_t *value,
                                        VAR uint8_t *value_addr,
                                        uint8_t block_address,
                                        uint8_t auth_mode,
                                        IN const uint8_t *key);
UFR_STATUS DL_API ValueBlockInSectorRead_PK(VAR int32_t *value,
                                                VAR uint8_t *value_addr,
                                                uint8_t sector_address,
                                                uint8_t block_in_sector_address,
                                                uint8_t auth_mode,
                                                IN const uint8_t *key);
UFR_STATUS DL_API ValueBlockWrite_PK(int32_t value,
                                         uint8_t value_addr,
                                         uint8_t block_address,
                                         uint8_t auth_mode,
                                         IN const uint8_t *key);
UFR_STATUS DL_API ValueBlockInSectorWrite_PK(int32_t value,
                                                 uint8_t value_addr,
                                                 uint8_t sector_address,
                                                 uint8_t block_in_sector_address,
                                                 uint8_t auth_mode,
                                                 IN const uint8_t *key);
UFR_STATUS DL_API ValueBlockIncrement_PK(int32_t increment_value,
                                             uint8_t block_address,
                                             uint8_t auth_mode,
                                             IN const uint8_t *key);
UFR_STATUS DL_API ValueBlockInSectorIncrement_PK(int32_t increment_value,
                                                     uint8_t sector_address,
                                                     uint8_t block_in_sector_address,
                                                     uint8_t auth_mode,
                                                     IN const uint8_t *key);
UFR_STATUS DL_API ValueBlockDecrement_PK(int32_t decrement_value,
                                             uint8_t block_address,
                                             uint8_t auth_mode,
                                             IN const uint8_t *key);
UFR_STATUS DL_API ValueBlockInSectorDecrement_PK(int32_t decrement_value,
                                                     uint8_t sector_address,
                                                     uint8_t block_in_sector_address,
                                                     uint8_t auth_mode,
                                                     IN const uint8_t *key);
UFR_STATUS DL_API GetReaderHardwareVersion(VAR uint8_t *version_major,
                                               VAR uint8_t *version_minor);
UFR_STATUS DL_API GetReaderFirmwareVersion(VAR uint8_t *version_major,
                                               VAR uint8_t *version_minor);

// New commands (for RTC & I2C EEPROM):
UFR_STATUS DL_API GetReaderTime(VAR uint8_t *time);
UFR_STATUS DL_API SetReaderTime(IN uint8_t *password, VAR uint8_t *time);
UFR_STATUS DL_API ChangeReaderPassword(IN uint8_t *old_password, IN uint8_t *new_password);
UFR_STATUS DL_API ReaderEepromWrite(IN uint8_t *data, uint32_t address, uint32_t size, IN uint8_t *password);
UFR_STATUS DL_API ReaderEepromRead(OUT uint8_t *data, uint32_t address, uint32_t size);

UFR_STATUS DL_API SubscribeSector(uint8_t block_nr, uint32_t admin_serial);
UFR_STATUS DL_API SubscribeBlock(uint8_t block_nr, uint32_t admin_serial);
UFR_STATUS DL_API BusAdminCardMake(uint32_t serial,	IN uint8_t *password);

UFR_STATUS DL_API GetReaderSerialDescription(OUT uint8_t pSerialDescription[8]);

// New since version 2.0:
UFR_STATUS DL_API GetBuildNumber(VAR uint8_t *build);
UFR_STATUS DL_API GetCardIdEx(VAR uint8_t *lpucSak, OUT uint8_t *aucUid,
		VAR uint8_t *lpucUidSize);
UFR_STATUS DL_API GetLastCardIdEx(VAR uint8_t *lpucSak, OUT uint8_t *aucUid,
		VAR uint8_t *lpucUidSize);
//------------------------------------------------------------------------------
//Multi-card (anti collision) mode:
//------------------------------------------------------------------------------
UFR_STATUS DL_API EnableAntiCollision(void);
UFR_STATUS DL_API DisableAntiCollision(void);
UFR_STATUS DL_API EnumCards(VAR uint8_t *lpucCardsNumber, OUT uint8_t *lpucUidListSize); // Card pointer is on the first card in list
UFR_STATUS DL_API ListCards(OUT uint8_t *aucUidList, uint8_t ucUidListSize); // Before calling this function you must call EnumCards() first.
UFR_STATUS DL_API SelectCard(IN const uint8_t *aucUid, uint8_t ucUidSize, OUT uint8_t *lpucSelctedCardType);
UFR_STATUS DL_API DeslectCard(void);
UFR_STATUS DL_API GetAntiCollisionStatus(VAR int8_t *lpcIsAntiCollEnabled, VAR int8_t *lpcIsAnyCardSelected);
//------------------------------------------------------------------------------
UFR_STATUS DL_API GetDlogicCardType(VAR uint8_t *lpucCardType);
UFR_STATUS DL_API GetNfcT2TVersion(OUT uint8_t lpucVersionResponse[8]);
UFR_STATUS DL_API GetCardSize(VAR uint32_t *lpulLinearSize, VAR uint32_t *lpulRawSize);

// uFCoder PRO MODE
UFR_STATUS DL_API GetReaderProMode(VAR uint32_t *pReaderProMode, OUT uint32_t *pReaderProConfig);
UFR_STATUS DL_API SetReaderProMode(const uint32_t ReaderProMode);

// QR barcode crypt algorithm
// initialization. with TB serial like 'TB123456'
UFR_STATUS DL_API CardEncryption_Initialize(IN const uint8_t *TBSerialString, uint16_t job_number);

// You must define 25 bytes array in memory for out_card_data[]
UFR_STATUS DL_API CardEncryption_GetNextEncryptedCard(const uint32_t from_timestamp, const uint32_t to_timestamp,
		OUT uint8_t out_card_data[]);

enum CARD_ENCRYPTION_CODE_TYPE
{
	CODE_TYPE_STANDARD,
	CODE_TYPE_GROUP,
	CODE_TYPE_DAILY_RANGE, // valid from, but only to_timestamp / every day
};

/**
 * Same function like CardEncryption_GetNextEncryptedCard() with an additional byte
 * to set master byte on the encrypted card ID
 *
 * @param code_type card type, look in CARD_ENCRYPTION_CODE_TYPE enumeration
 * @param from_timestamp start date-time validity of the generated card
 * @param to_timestamp end date-time validity of the generated card
 * @param additional_data_size additional data size in bytes
 * @param additional_data array with additional data - only master byte on the encrypted card ID for now
 * @param out_card_data_size returns how many bytes are stored in the out_card_data array
 * @param out_card_data pointer to the allocated byte array in memory (minimal size of 20 bytes) for the output data
 * @return
 */
UFR_STATUS DL_API CardEncryption_GetNext(const uint32_t code_type,
		const uint32_t from_timestamp, const uint32_t to_timestamp,
		const uint32_t additional_data_size, IN const uint8_t additional_data[],
		VAR uint32_t *out_card_data_size, OUT uint8_t out_card_data[]);

UFR_STATUS DL_API CardEncryption_GetActualCardSN(OUT uint32_t *ActualCard_SN, VAR uint32_t *ActualCard_SN_LOG);
UFR_STATUS DL_API CardEncryption_GetJobSN(VAR uint32_t *JobSN);
UFR_STATUS DL_API CardEncryption_GetSalterSN(OUT uint8_t SalterSN[8], VAR uint8_t * magicByte);

UFR_STATUS DL_API read_ndef_record(uint8_t message_nr, uint8_t record_nr, VAR uint8_t *tnf, OUT uint8_t *type_record, VAR uint8_t *type_length, OUT uint8_t *id, VAR uint8_t *id_length,
									   OUT uint8_t *payload, VAR uint32_t *payload_length);
UFR_STATUS DL_API write_ndef_record(uint8_t message_nr, uint8_t *tnf, IN uint8_t *type_record, uint8_t *type_length, IN uint8_t *id, uint8_t *id_length,
		   IN uint8_t *payload, uint32_t *payload_length, VAR uint8_t *card_formated);
UFR_STATUS DL_API write_ndef_record_mirroring(uint8_t message_nr,
                  uint8_t *tnf, IN uint8_t *type_record, uint8_t *type_length, IN uint8_t *id,
		          uint8_t *id_length, IN uint8_t *payload, uint32_t *payload_length,
		          VAR uint8_t *card_formated,
		          int use_uid_ascii_mirror, int use_counter_ascii_mirror, uint32_t payload_mirroring_pos);
UFR_STATUS DL_API get_ndef_record_count(VAR uint8_t *ndef_message_cnt, VAR uint8_t *ndef_record_cnt, OUT uint8_t *ndef_record_array, VAR uint8_t *empty_ndef_message_cnt);
UFR_STATUS DL_API erase_last_ndef_record(uint8_t message_nr);
UFR_STATUS DL_API erase_all_ndef_records(uint8_t message_nr);
UFR_STATUS DL_API ndef_card_initialization(void);
//---------------------------------------------------------------------
// Card emulation:
//---------------------------------------------------------------------
UFR_STATUS DL_API WriteEmulationNdef(uint8_t tnf,
		IN uint8_t* type_record,
		uint8_t type_length,
		IN uint8_t* id,
		uint8_t id_length,
		IN uint8_t* payload,
		uint8_t payload_length);
UFR_STATUS DL_API WriteEmulationNdefWithAAR(
		uint8_t tnf,
		IN uint8_t *type_record,
		uint8_t type_length,
		IN uint8_t *id,
		uint8_t id_length,
		IN uint8_t *payload,
		uint8_t payload_length,
		IN uint8_t *aar,
		uint8_t aar_length);
UFR_STATUS DL_API TagEmulationStart(void);
UFR_STATUS DL_API TagEmulationStop(void);
UFR_STATUS DL_API CombinedModeEmulationStart(void);
UFR_STATUS DL_API AdHocEmulationStart(void);
UFR_STATUS DL_API AdHocEmulationStop(void);
UFR_STATUS DL_API GetAdHocEmulationParams(VAR uint8_t *ThresholdMinLevel, VAR uint8_t *ThresholdCollLevel,
											VAR uint8_t *RFLevelAmp, VAR uint8_t *RxGain, VAR uint8_t *RFLevel);
UFR_STATUS DL_API SetAdHocEmulationParams(uint8_t ThresholdMinLevel, uint8_t ThresholdCollLevel,
											uint8_t RFLevelAmp, uint8_t RxGain, uint8_t RFLevel);
UFR_STATUS DL_API GetExternalFieldState(VAR uint8_t *is_field_present);
UFR_STATUS DL_API EnterShareRamCommMode(void);
UFR_STATUS DL_API ExitShareRamCommMode(void);
UFR_STATUS DL_API WriteShareRam(IN uint8_t *ram_data, uint8_t addr, uint8_t data_len);
UFR_STATUS DL_API ReadShareRam(OUT uint8_t *ram_data, uint8_t addr, uint8_t data_len);

//------------------------------------------------------------------------------

// GetNfcT2TVersion() returns 8 bytes (see T2T documentation):
typedef struct t2t_version_struct {
	uint8_t header;
	uint8_t vendor_id;
	uint8_t product_type;
	uint8_t product_subtype;
	uint8_t major_product_version;
	uint8_t minor_product_version;
	uint8_t storage_size;
	uint8_t protocol_type;
} t2t_version_t;

// NfcT2TSafeConvertVersion() returns converts version_record that returned from GetNfcT2TVersion()
// or GetNfcT2TVersionM(). Conversion is "alignment safe"
// (you don't need to pay attention on structure byte alignment):
void DL_API NfcT2TSafeConvertVersion(t2t_version_t *version, const uint8_t *version_record);
UFR_STATUS DL_API ReadECCSignature(IN uint8_t lpucECCSignature[ECC_SIG_LEN],
		OUT uint8_t lpucUid[MAX_UID_LEN], VAR uint8_t *lpucUidLen, VAR uint8_t *lpucDlogicCardType);

//------------------------------------------------------------------------------
UFR_STATUS DL_API ReadCounter(uint8_t counter_address, VAR uint32_t *value);
UFR_STATUS DL_API IncrementCounter(uint8_t counter_address, uint32_t inc_value);
UFR_STATUS DL_API ReadNFCCounter(VAR uint32_t *value); // Same as ReadCounter(2, &value);
UFR_STATUS DL_API ReadNFCCounterPwdAuth_RK(VAR uint32_t *value, uint8_t reader_key_index);
UFR_STATUS DL_API ReadNFCCounterPwdAuth_PK(VAR uint32_t *value, IN const uint8_t *key);

//------------------------------------------------------------------------------

UFR_STATUS DL_API SetAsyncCardIdSendConfig(uint8_t send_enable,
		uint8_t prefix_enable, uint8_t prefix, uint8_t suffix,
		uint8_t send_removed_enable, uint32_t async_baud_rate);

UFR_STATUS DL_API SetAsyncCardIdSendConfigEx(uint8_t send_enable,
		uint8_t prefix_enable, uint8_t prefix, uint8_t suffix,
		uint8_t send_removed_enable, uint8_t reverse_byte_order,
		uint8_t decimal_representation, uint32_t async_baud_rate);

UFR_STATUS DL_API GetAsyncCardIdSendConfig(VAR uint8_t *send_enable,
		VAR uint8_t *prefix_enable, VAR uint8_t *prefix, VAR uint8_t *suffix,
		VAR uint8_t *send_removed_enable, VAR uint32_t *async_baud_rate);

UFR_STATUS DL_API GetAsyncCardIdSendConfigEx(VAR uint8_t *send_enable,
		VAR uint8_t *prefix_enable, VAR uint8_t *prefix, VAR uint8_t *suffix,
		VAR uint8_t *send_removed_enable, VAR uint8_t *reverse_byte_order,
		VAR uint8_t *decimal_representation, VAR uint32_t *async_baud_rate);

/*****************************************************************************
 * AIS FUNCTIONS
 *****************************************************************************
 */

/**
 * ais_get_card_number() read assigned serial number from AIS cards
 *
 * @param card_number ( pointer to reserved 32 bit integer )  AIS card serial number
 * @return UFR_STATUS execution status
 */
UFR_STATUS DL_API ais_get_card_number(VAR uint32_t *card_number);

UFR_STATUS DL_API ais_set_right_record(uint8_t record_number, uint16_t first_reader_nr, uint16_t last_reader_nr,
		uint8_t start_hour, uint8_t start_minute, uint8_t end_hour, uint8_t end_minute, IN uint8_t *days);
UFR_STATUS DL_API ais_get_right_record(uint8_t record_number, VAR uint16_t *first_reader_nr, VAR uint16_t *last_reader_nr,
		VAR uint8_t *start_hour, VAR uint8_t *start_minute, VAR uint8_t *end_hour, VAR uint8_t *end_minute, OUT uint8_t *days);
UFR_STATUS DL_API ais_erase_right_record(uint8_t record_number);
UFR_STATUS DL_API ais_set_validate_record(uint8_t begin_year, uint8_t begin_month, uint8_t begin_day, uint8_t begin_hour, uint8_t begin_minute,
		uint8_t end_year, uint8_t end_month, uint8_t end_day, uint8_t end_hour, uint8_t end_minute);
UFR_STATUS DL_API ais_get_validate_record(VAR uint8_t *begin_year, VAR uint8_t *begin_month, VAR uint8_t *begin_day, VAR uint8_t *begin_hour, VAR uint8_t *begin_minute,
		VAR uint8_t *end_year, VAR uint8_t *end_month, VAR uint8_t *end_day, VAR uint8_t *end_hour, VAR uint8_t *end_minute);
UFR_STATUS DL_API ais_set_card_type(uint8_t card_type);
UFR_STATUS DL_API ais_get_card_type(VAR uint8_t *card_type);
UFR_STATUS DL_API ais_set_card_daily_duration(uint16_t duration);
UFR_STATUS DL_API ais_get_card_daily_duration(VAR uint16_t *duration);
UFR_STATUS DL_API ais_set_card_total_duration(uint32_t duration);
UFR_STATUS DL_API ais_get_card_total_duration(VAR uint32_t *duration);

// swimming pool **************************************************************
/**
 * ais_get_credit_and_period_validity() > get information about credit and period of validity
 *
 * @param credit ( pointer to integer ) :
 * @param begin_year ( pointer to integer ) :
 * @param begin_month ( pointer to integer ) :
 * @param begin_day ( pointer to integer ) :
 * @param begin_hour ( pointer to integer ) :
 * @param begin_minute ( pointer to integer ) :
 * @param end_year ( pointer to integer ) :
 * @param end_month ( pointer to integer ) :
 * @param end_day ( pointer to integer ) :
 * @param end_hour ( pointer to integer ) :
 * @param end_minute ( pointer to integer ) :
 * @return
 */
UFR_STATUS DL_API ais_get_credit_and_period_validity(VAR int32_t *credit,
		VAR uint32_t *begin_year, VAR uint32_t *begin_month, VAR uint32_t *begin_day,
		VAR uint32_t *begin_hour,
		VAR uint32_t *begin_minute, //
		VAR uint32_t *end_year, VAR uint32_t *end_month, VAR uint32_t *end_day,
		VAR uint32_t *end_hour, VAR uint32_t *end_minute);

/**
 * ais_set_credit_and_period_validity() > set credit and period of validity
 *
 * @param credit ( integer ) :
 * @param begin_year ( integer ) :
 * @param begin_month ( integer ) :
 * @param begin_day ( integer ) :
 * @param begin_hour ( integer ) :
 * @param begin_minute ( integer ) :
 * @param end_year ( integer ) :
 * @param end_month ( integer ) :
 * @param end_day ( integer ) :
 * @param end_hour ( integer ) :
 * @param end_minute ( integer ) :
 * @return
 */
UFR_STATUS DL_API ais_set_credit_and_period_validity(int32_t credit,
		uint32_t begin_year, uint32_t begin_month, uint32_t begin_day,
		uint32_t begin_hour,
		uint32_t begin_minute, //
		uint32_t end_year, uint32_t end_month, uint32_t end_day,
		uint32_t end_hour, uint32_t end_minute);

UFR_STATUS DL_API ais_set_right_type_record(uint8_t record_number,
		uint8_t right_record_type, IN uint8_t *right_data);

UFR_STATUS DL_API ais_get_right_type_record(uint8_t record_number,
		VAR uint8_t *right_record_type, OUT uint8_t *right_data);

UFR_STATUS DL_API ais_set_right_record_type_max_daily_counter(uint8_t record_number,
		uint16_t first_reader_nr, uint16_t last_reader_nr, uint8_t start_hour,
		uint8_t start_minute, uint8_t end_hour, uint8_t end_minute,
		IN uint8_t *days, uint8_t max_daily_counter);

UFR_STATUS DL_API ais_get_right_record_type_max_daily_counter(uint8_t record_number,
		VAR uint16_t *first_reader_nr, VAR uint16_t *last_reader_nr,
		VAR uint8_t *start_hour, VAR uint8_t *start_minute, VAR uint8_t *end_hour,
		VAR uint8_t *end_minute, OUT uint8_t *days, VAR uint8_t *max_daily_counter);

//=============================================================================

UFR_STATUS DL_API UfrXrcLockOn(uint16_t pulse_duration);
UFR_STATUS DL_API UfrXrcRelayState(uint8_t state);
UFR_STATUS DL_API UfrXrcGetIoState(VAR uint8_t *intercom, VAR uint8_t *door, VAR uint8_t *relay_state);
UFR_STATUS DL_API UfrRedLightControl(uint8_t light_status);
UFR_STATUS DL_API UfrRgbLightControl(uint8_t red, uint8_t green, uint8_t blue, uint8_t intensity, uint8_t enable);

UFR_STATUS DL_API UfrSetBadSelectCardNrMax(uint8_t bad_select_nr_max);
UFR_STATUS DL_API UfrGetBadSelectCardNrMax(VAR uint8_t *bad_select_nr_max);

UFR_STATUS DL_API UfrEnterSleepMode(void);
UFR_STATUS DL_API UfrLeaveSleepMode(void);
UFR_STATUS DL_API AutoSleepSet(uint8_t seconds_wait);
UFR_STATUS DL_API AutoSleepGet(VAR uint8_t *seconds_wait);

UFR_STATUS DL_API SetSpeedPermanently(unsigned char tx_speed, unsigned char rx_speed);
UFR_STATUS DL_API GetSpeedParameters(VAR unsigned char *tx_speed, VAR unsigned char *rx_speed);
UFR_STATUS DL_API SetDisplayData(IN uint8_t *display_data, uint8_t data_length);
UFR_STATUS DL_API SetSpeakerFrequency(uint16_t frequency);
UFR_STATUS DL_API SetDisplayIntensity(uint8_t intensity);
UFR_STATUS DL_API GetDisplayIntensity(VAR uint8_t *intensity);
// DESFIRE functions **************************************************************

/**
 *
 * @param chaining
 * @param timeout
 * @param block_length
 * @param snd_data_array
 * @param rcv_length
 * @param rcv_data_array
 * @param ufr_status
 * @return
 */
UFR_STATUS DL_API SetISO14443_4_Mode(void);
UFR_STATUS DL_API SetISO14443_4_DLStorage(void);
UFR_STATUS DL_API uFR_i_block_transceive(uint8_t chaining, uint8_t timeout,
		uint8_t block_length, IN uint8_t *snd_data_array, VAR size_t *rcv_length,
		OUT uint8_t *rcv_data_array, VAR uint32_t *ufr_status);

UFR_STATUS DL_API uFR_APDU_Transceive(uint8_t cls, uint8_t ins, uint8_t p1, uint8_t p2,
		IN uint8_t *data_out, uint8_t data_out_len, OUT uint8_t *data_in, uint32_t max_data_in_len, VAR uint32_t *response_len,
		uint8_t send_le, OUT uint8_t *apdu_status);

UFR_STATUS DL_API APDUHexStrTransceive(IN const char *c_apdu, OUT char **r_apdu);
UFR_STATUS DL_API APDUPlainTransceive(IN const uint8_t *c_apdu, uint32_t c_apdu_len, OUT uint8_t *r_apdu, VAR uint32_t *r_apdu_len);
UFR_STATUS DL_API APDUTransceive(uint8_t cls, uint8_t ins, uint8_t p1, uint8_t p2,
		IN const uint8_t *data_out, uint32_t Nc, OUT uint8_t *data_in, VAR uint32_t *Ne,
		uint8_t send_le, OUT uint8_t *apdu_status);
UFR_STATUS DL_API i_block_trans_rcv_chain(uint8_t chaining,	uint8_t timeout,
		uint8_t block_length, IN uint8_t *snd_data_array,
		VAR uint8_t *rcv_length, OUT uint8_t *rcv_data_array, VAR uint8_t *rcv_chained, VAR uint32_t *ufr_status);
UFR_STATUS DL_API r_block_transceive(uint8_t ack, uint8_t timeout,
		VAR uint8_t *rcv_length, OUT uint8_t *rcv_data_array, VAR uint8_t *rcv_chained, VAR uint32_t *ufr_status);
UFR_STATUS DL_API s_block_deselect(uint8_t timeout);

UFR_STATUS DL_API card_transceive(uint8_t card_activate, uint8_t card_halted, uint8_t tx_crc, uint8_t rx_crc, uint8_t crypto1,
		uint32_t timeout, IN uint8_t *tx_data, uint8_t tx_data_len, OUT uint8_t *rx_data, VAR uint8_t *rx_data_len);
UFR_STATUS DL_API card_transceive_mode_start(uint8_t tx_crc, uint8_t rx_crc, uint32_t rf_timeout, uint32_t uart_timeout);
UFR_STATUS DL_API card_transceive_mode_stop(void);
UFR_STATUS DL_API card_halt_enable(void);

UFR_STATUS DL_API uart_transceive(IN uint8_t *send_data, uint8_t send_len, OUT uint8_t *rcv_data, uint32_t bytes_to_receive, VAR uint32_t *rcv_len);

UFR_STATUS DL_API open_ISO7816_interface(OUT uint8_t *atr_data, VAR uint8_t *atr_len);
UFR_STATUS DL_API APDU_switch_to_ISO7816_interface(void);
UFR_STATUS DL_API close_ISO7816_interface_no_APDU(void);
UFR_STATUS DL_API close_ISO7816_interface_APDU_ISO14443_4(void);
UFR_STATUS DL_API APDU_switch_to_ISO14443_4_interface(void);
UFR_STATUS DL_API APDU_switch_off_from_ISO7816_interface(void);

//==============================================================================
UFR_STATUS DL_API JCAppSelectByAid(IN const uint8_t *aid, uint8_t aid_len, OUT uint8_t selection_response[16]);
UFR_STATUS DL_API JCAppPutPrivateKey(uint8_t key_type, uint8_t key_index,
		IN const uint8_t *key, uint16_t key_bit_len, const IN uint8_t *key_param, uint16_t key_parm_len);
UFR_STATUS DL_API JCAppGenerateKeyPair(uint8_t key_type, uint8_t key_index, uint8_t key_designator,
		uint16_t key_bit_len, IN const uint8_t *params, uint16_t params_size);
UFR_STATUS DL_API JCAppDeleteRsaKeyPair(uint8_t key_index);
UFR_STATUS DL_API JCAppDeleteEcKeyPair(uint8_t key_index);
UFR_STATUS DL_API JCAppSignatureBegin(uint8_t cipher, uint8_t digest, uint8_t padding,
		uint8_t key_index,
		IN const uint8_t *chunk, uint16_t chunk_len, IN const uint8_t *alg_param, uint16_t alg_parm_len);
UFR_STATUS DL_API JCAppSignatureUpdate(IN const uint8_t *chunk, uint16_t chunk_len);
UFR_STATUS DL_API JCAppSignatureEnd(VAR uint16_t *sig_len);
UFR_STATUS DL_API JCAppGenerateSignature(uint8_t cipher, uint8_t digest, uint8_t padding,
		uint8_t key_index,
		IN const uint8_t *plain_data, uint16_t plain_data_len, VAR uint16_t *sig_len,
		IN const uint8_t *alg_param, uint16_t alg_parm_len);
UFR_STATUS DL_API JCAppGetSignature(OUT uint8_t *sig, uint16_t sig_len);
UFR_STATUS DL_API JCAppPutObj(uint8_t obj_type, uint8_t obj_index, IN uint8_t *obj, int16_t obj_size, IN uint8_t *id, uint8_t id_size);
UFR_STATUS DL_API JCAppPutObjSubject(uint8_t obj_type, uint8_t obj_index, IN uint8_t *subject, uint8_t size);
UFR_STATUS DL_API JCAppInvalidateCert(uint8_t obj_type, uint8_t obj_index);
UFR_STATUS DL_API JCAppGetObjId(uint8_t obj_type, uint8_t obj_index, OUT uint8_t *id, VAR uint16_t *id_size); // when id == NULL returns size
UFR_STATUS DL_API JCAppGetObjSubject(uint8_t obj_type, uint8_t obj_index, OUT uint8_t *subject, VAR uint16_t *size); // when subject == NULL returns size
UFR_STATUS DL_API JCAppGetObj(uint8_t obj_type, uint8_t obj_index, OUT uint8_t *obj, int16_t size); // when obj == NULL returns size
c_string DL_API JCAppGetErrorDescription(UFR_STATUS apdu_error_status);
UFR_STATUS DL_API JCAppLogin(uint8_t SO, IN uint8_t *pin, uint8_t pinSize);
UFR_STATUS DL_API JCAppGetPinTriesRemaining(dl_sec_code_t secureCodeType, VAR uint16_t *triesRemaining);
UFR_STATUS DL_API JCAppPinChange(dl_sec_code_t secureCodeType, IN uint8_t *newPin, uint8_t newPinSize);
UFR_STATUS DL_API JCAppPinUnblock(uint8_t SO, IN uint8_t *puk, uint8_t pukSize);
UFR_STATUS DL_API JCAppPinEnable(uint8_t SO);
UFR_STATUS DL_API JCAppPinDisable(uint8_t SO);
UFR_STATUS DL_API JCAppGetRsaPublicKey(uint8_t key_index, OUT uint8_t *modulus, VAR uint16_t *modulus_size,
		OUT uint8_t *exponent, VAR uint16_t *exponent_size); // when modulus == NULL, returns sizes and exponent ignored
UFR_STATUS DL_API JCAppGetEcPublicKey(uint8_t key_index, OUT uint8_t *keyW, VAR uint16_t *kexWSize, // when keyW == NULL, returns size
		OUT uint8_t *field, VAR uint16_t *field_size, OUT uint8_t *ab , VAR uint16_t *ab_size, OUT uint8_t *g, VAR uint16_t *g_size,
		OUT uint8_t *r, VAR uint16_t *r_size, VAR uint16_t *k, VAR uint16_t *key_size_bits, VAR uint16_t *key_designator);
UFR_STATUS DL_API JCAppGetEcKeySizeBits(uint8_t key_index, VAR uint16_t *key_size_bits, VAR uint16_t *key_designator);
//------------------------------------------------------------------------------
UFR_STATUS DL_API JCStorageGetFilesListSize(VAR uint32_t *list_size);
UFR_STATUS DL_API JCStorageListFiles(OUT uint8_t *list, uint32_t list_bytes_allocated);
UFR_STATUS DL_API JCStorageGetFileSize(uint8_t card_file_index, VAR uint32_t *file_size);
UFR_STATUS DL_API JCStorageReadFile(uint8_t card_file_index, OUT uint8_t *data, uint32_t data_bytes_allocated);
UFR_STATUS DL_API JCStorageReadFileToFileSystem(uint8_t card_file_index, IN const char *file_system_path_name);
UFR_STATUS DL_API JCStorageWriteFile(uint8_t card_file_index, IN const uint8_t *data, uint32_t data_size);
UFR_STATUS DL_API JCStorageWriteFileFromFileSystem(uint8_t card_file_index, IN const char *file_system_path_name);
UFR_STATUS DL_API JCStorageDeleteFile(uint8_t file_index);
//==============================================================================
UFR_STATUS DL_API DES_to_AES_key_type(void);
UFR_STATUS DL_API AES_to_DES_key_type(void);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

UFR_STATUS DL_API uFR_int_GetDesfireUid(uint8_t aes_key_nr, uint32_t aid,
		uint8_t aid_key_nr, OUT uint8_t *card_uid, VAR uint8_t *card_uid_len,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);
UFR_STATUS DL_API uFR_int_GetDesfireUid_PK(IN uint8_t *aes_key_ext, uint32_t aid,
		uint8_t aid_key_nr, OUT uint8_t *card_uid, VAR uint8_t *card_uid_len,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireFreeMem(VAR uint32_t *free_mem_byte, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireFormatCard(uint8_t aes_key_nr, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireFormatCard_PK(IN uint8_t *aes_key_ext, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateStdDataFile(uint8_t aes_key_nr, uint32_t aid, uint8_t file_id, uint32_t file_size,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateStdDataFile_PK(IN uint8_t *aes_key_ext, uint32_t aid, uint8_t file_id, uint32_t file_size,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateStdDataFile_no_auth(uint32_t aid, uint8_t file_id, uint32_t file_size,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDeleteFile(uint8_t aes_key_nr, uint32_t aid, uint8_t file_id,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDeleteFile_PK(IN uint8_t *aes_key_ext, uint32_t aid, uint8_t file_id,
		uint16_t VAR *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDeleteFile_no_auth(uint32_t aid, uint8_t file_id,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateAesApplication(uint8_t aes_key_nr, uint32_t aid,
		uint8_t setting, uint8_t max_key_no, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateAesApplication_PK(IN uint8_t *aes_key_ext, uint32_t aid,
		uint8_t setting, uint8_t max_key_no, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateAesApplication_no_auth(uint32_t aid,
		uint8_t setting, uint8_t max_key_no, VAR uint16_t *card_status,	VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDeleteApplication(uint8_t aes_key_nr,	uint32_t aid,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDeleteApplication_PK(IN uint8_t *aes_key_ext, uint32_t aid,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireSetConfiguration(uint8_t aes_key_nr, uint8_t random_uid, uint8_t format_disable,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireSetConfiguration_PK(IN uint8_t *aes_key_ext, uint8_t random_uid, uint8_t format_disable,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireGetKeySettings(uint8_t aes_key_nr, uint32_t aid,
		VAR uint8_t *setting, VAR uint8_t *max_key_no,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireGetKeySettings_PK(IN uint8_t *aes_key_ext, uint32_t aid,
		VAR uint8_t *setting, VAR uint8_t *max_key_no,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireChangeKeySettings(uint8_t aes_key_nr,	uint32_t aid,
		uint8_t setting, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireChangeKeySettings_PK(IN uint8_t *aes_key_ext, uint32_t aid,
		uint8_t setting, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireChangeAesKey(uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_no_auth,
		IN uint8_t new_aes_key[16], uint8_t aid_key_no, IN uint8_t old_aes_key[16],
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

// all keys are in reader
UFR_STATUS DL_API uFR_int_DesfireChangeAesKey_A(uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_no_auth,
		uint8_t new_aes_key_nr, uint8_t aid_key_no, uint8_t old_aes_key_nr,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireChangeAesKey_PK(IN uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_no_auth,
		IN uint8_t new_aes_key[16], uint8_t aid_key_no, IN uint8_t old_aes_key[16],
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireWriteAesKey(uint8_t aes_key_no, IN uint8_t *aes_key);

//---------------------------------------------------------------------------

UFR_STATUS DL_API uFR_int_DesfireReadStdDataFile(uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, OUT uint8_t *data,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireReadStdDataFile_PK(IN uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, OUT uint8_t *data,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireReadStdDataFile_no_auth(uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, OUT uint8_t *data,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireWriteStdDataFile(uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, IN uint8_t *data,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireWriteStdDataFile_PK(IN uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, IN uint8_t *data,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireWriteStdDataFile_no_auth(uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, IN uint8_t *data,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateValueFile(uint8_t aes_key_nr, uint32_t aid, uint8_t file_id,
		int32_t lower_limit, int32_t upper_limit, int32_t value, uint8_t limited_credit_enabled,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateValueFile_PK(IN uint8_t *aes_key_ext, uint32_t aid, uint8_t file_id,
		int32_t lower_limit, int32_t upper_limit, int32_t value, uint8_t limited_credit_enabled,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateValueFile_no_auth(uint32_t aid, uint8_t file_id,
		int32_t lower_limit, int32_t upper_limit, int32_t value, uint8_t limited_credit_enabled,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireReadValueFile(uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint8_t communication_settings, VAR int32_t *value,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireReadValueFile_PK(IN uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint8_t communication_settings, VAR int32_t *value,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireReadValueFile_no_auth(uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint8_t communication_settings, VAR int32_t *value,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireIncreaseValueFile(uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint8_t communication_settings, uint32_t value,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireIncreaseValueFile_PK(IN uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint8_t communication_settings, uint32_t value,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireIncreaseValueFile_no_auth(uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint8_t communication_settings, uint32_t value,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDecreaseValueFile(uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint8_t communication_settings, uint32_t value,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDecreaseValueFile_PK(IN uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint8_t communication_settings, uint32_t value,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDecreaseValueFile_no_auth(uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint8_t communication_settings, uint32_t value,
		VAR uint16_t *card_status, VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireGetApplicationIds(uint8_t aes_key_nr,
		uint32_t *application_ids, uint8_t *number_of_aplication_ids,
		uint16_t *card_status, uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireGetApplicationIds_PK(uint8_t *aes_key_ext,
		uint32_t *application_ids, uint8_t *number_of_aplication_ids,
		uint16_t *card_status, uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireGetApplicationIds_no_auth(uint32_t *application_ids, uint8_t *number_of_aplication_ids,
		uint16_t *card_status, uint16_t *exec_time);

/////////////////////////////////////////////////////////////////////

UFR_STATUS DL_API GreenLedBlinkingTurnOn(void);
UFR_STATUS DL_API GreenLedBlinkingTurnOff(void);

/////////////////////////////////////////////////////////////////////

UFR_STATUS DL_API SetRfAnalogRegistersTypeA(uint8_t ThresholdMinLevel, uint8_t ThresholdCollLevel,
										uint8_t RFLevelAmp, uint8_t RxGain, uint8_t RFLevel);
UFR_STATUS DL_API SetRfAnalogRegistersTypeB(uint8_t ThresholdMinLevel, uint8_t ThresholdCollLevel,
										uint8_t RFLevelAmp, uint8_t RxGain, uint8_t RFLevel);
UFR_STATUS DL_API SetRfAnalogRegistersISO14443_212(uint8_t ThresholdMinLevel, uint8_t ThresholdCollLevel,
										uint8_t RFLevelAmp, uint8_t RxGain, uint8_t RFLevel);
UFR_STATUS DL_API SetRfAnalogRegistersISO14443_424(uint8_t ThresholdMinLevel, uint8_t ThresholdCollLevel,
										uint8_t RFLevelAmp, uint8_t RxGain, uint8_t RFLevel);

UFR_STATUS DL_API SetRfAnalogRegistersTypeADefault(void);
UFR_STATUS DL_API SetRfAnalogRegistersTypeBDefault(void);
UFR_STATUS DL_API SetRfAnalogRegistersISO14443_212Default(void);
UFR_STATUS DL_API SetRfAnalogRegistersISO14443_424Default(void);

UFR_STATUS DL_API GetRfAnalogRegistersTypeA(VAR uint8_t *ThresholdMinLevel, VAR uint8_t *ThresholdCollLevel,
					VAR uint8_t *RFLevelAmp, VAR uint8_t *RxGain, VAR uint8_t *RFLevel);
UFR_STATUS DL_API GetRfAnalogRegistersTypeB(VAR uint8_t *ThresholdMinLevel, VAR uint8_t *ThresholdCollLevel,
					VAR uint8_t *RFLevelAmp, VAR uint8_t *RxGain, VAR uint8_t *RFLevel);
UFR_STATUS DL_API GetRfAnalogRegistersISO14443_212(VAR uint8_t *ThresholdMinLevel, VAR uint8_t *ThresholdCollLevel,
					VAR uint8_t *RFLevelAmp, VAR uint8_t *RxGain, VAR uint8_t *RFLevel);
UFR_STATUS DL_API GetRfAnalogRegistersISO14443_424(VAR uint8_t *ThresholdMinLevel, VAR uint8_t *ThresholdCollLevel,
					VAR uint8_t *RFLevelAmp, VAR uint8_t *RxGain, VAR uint8_t *RFLevel);

UFR_STATUS DL_API SetRfAnalogRegistersTypeATrans(uint8_t ThresholdMinLevel, uint8_t ThresholdCollLevel,
										uint8_t RFLevelAmp, uint8_t RxGain, uint8_t RFLevel,
										uint8_t CWGsNOn, uint8_t ModGsNOn, uint8_t CWGsP,
										uint8_t CWGsNOff, uint8_t ModGsNOff);
UFR_STATUS DL_API SetRfAnalogRegistersTypeBTrans(uint8_t ThresholdMinLevel, uint8_t ThresholdCollLevel,
										uint8_t RFLevelAmp, uint8_t RxGain, uint8_t RFLevel,
										uint8_t CWGsNOn, uint8_t ModGsNOn, uint8_t CWGsP, uint8_t ModGsP);

UFR_STATUS DL_API GetRfAnalogRegistersTypeATrans(VAR uint8_t *ThresholdMinLevel, VAR uint8_t *ThresholdCollLevel,
					VAR uint8_t *RFLevelAmp, VAR uint8_t *RxGain, VAR uint8_t *RFLevel,
					VAR uint8_t *CWGsNOn, VAR uint8_t *ModGsNOn, VAR uint8_t *CWGsP,
					VAR uint8_t *CWGsNOff, VAR uint8_t *ModGsNOff);
UFR_STATUS DL_API GetRfAnalogRegistersTypeBTrans(VAR uint8_t *ThresholdMinLevel, VAR uint8_t *ThresholdCollLevel,
					VAR uint8_t *RFLevelAmp, VAR uint8_t *RxGain, VAR uint8_t *RFLevel,
					VAR uint8_t *CWGsNOn, VAR uint8_t *ModGsNOn, VAR uint8_t *CWGsP, VAR uint8_t *ModGsP);

UFR_STATUS DL_API CheckBootFirmware(VAR uint8_t *exec_location);
UFR_STATUS DL_API FastFlashCheck(void);
UFR_STATUS DL_API DefaultBaudrateFlashCheck(void);

//SAM
UFR_STATUS DL_API SAM_get_version_raw(OUT uint8_t *data, VAR uint8_t *length);
UFR_STATUS DL_API SAM_get_version(VAR SAM_HW_TYPE *sam_type, OUT uint8_t *sam_uid);

//MIFARE PLUS
UFR_STATUS DL_API MFP_WritePerso(uint16_t address, IN uint8_t *data);
UFR_STATUS DL_API MFP_CommitPerso(void);
UFR_STATUS DL_API MFP_PersonalizationMinimal(IN uint8_t *card_master_key, IN uint8_t *card_config_key,
						IN uint8_t *level_2_switch_key, IN uint8_t *level_3_switch_key, IN uint8_t *level_1_auth_key,
						IN uint8_t *select_vc_key, IN uint8_t *prox_chk_key, IN uint8_t *vc_poll_enc_key, IN uint8_t *vc_poll_mac_key);
UFR_STATUS DL_API MFP_SwitchToSecurityLevel3(uint8_t key_index);
UFR_STATUS DL_API MFP_SwitchToSecurityLevel3_PK(IN uint8_t *aes_key);
UFR_STATUS DL_API MFP_AesAuthSecurityLevel1(uint8_t key_index);
UFR_STATUS DL_API MFP_AesAuthSecurityLevel1_PK(IN uint8_t *aes_key);
UFR_STATUS DL_API MFP_ChangeMasterKey(uint8_t key_index, IN uint8_t *new_key);
UFR_STATUS DL_API MFP_ChangeMasterKey_PK(IN uint8_t *old_key, IN uint8_t *new_key);
UFR_STATUS DL_API MFP_ChangeConfigurationKey(uint8_t key_index, IN uint8_t *new_key);
UFR_STATUS DL_API MFP_ChangeConfigurationKey_PK(IN uint8_t *old_key, IN uint8_t *new_key);
UFR_STATUS DL_API MFP_FieldConfigurationSet(uint8_t configuration_key_index, uint8_t rid_use, uint8_t prox_check_use);
UFR_STATUS DL_API MFP_FieldConfigurationSet_PK(IN uint8_t *configuration_key, uint8_t rid_use, uint8_t prox_check_use);
UFR_STATUS DL_API MFP_ChangeSectorKey(uint8_t sector_nr, uint8_t auth_mode, uint8_t key_index, IN uint8_t *new_key);
UFR_STATUS DL_API MFP_ChangeSectorKey_PK(uint8_t sector_nr, uint8_t auth_mode, IN uint8_t *old_key, IN uint8_t *new_key);
UFR_STATUS DL_API MFP_GetUid(uint8_t key_index_vc_poll_enc_key, uint8_t key_index_vc_poll_mac_key, OUT uint8_t *uid, VAR uint8_t *uid_len);
UFR_STATUS DL_API MFP_GetUid_PK(IN uint8_t *vc_poll_enc_key, IN uint8_t *vc_poll_mac_key, OUT uint8_t *uid, VAR uint8_t *uid_len);
UFR_STATUS DL_API MFP_ChangeVcPollingEncKey(uint8_t configuration_key_index, IN uint8_t *new_key);
UFR_STATUS DL_API MFP_ChangeVcPollingEncKey_PK(IN uint8_t *configuration_key, IN uint8_t *new_key);
UFR_STATUS DL_API MFP_ChangeVcPollingMacKey(uint8_t configuration_key_index, IN uint8_t *new_key);
UFR_STATUS DL_API MFP_ChangeVcPollingMacKey_PK(IN uint8_t *configuration_key, IN uint8_t *new_key);

//ULTRALIGHT C
UFR_STATUS DL_API ULC_ExternalAuth_PK(IN uint8_t *key);
UFR_STATUS DL_API ULC_write_3des_key_no_auth(IN uint8_t *new_3des_key);
UFR_STATUS DL_API ULC_write_3des_key_factory_key(IN uint8_t *new_3des_key);
UFR_STATUS DL_API ULC_write_3des_key(IN uint8_t *new_3des_key, IN uint8_t *old_3des_key);

/**
 * BalanceGet() gets balance of the AIS SDK formated cards
 *
 * @param auth_mode only MIFARE_AUTHENT1A supported for now
 * @param auth_value pointer to the Crypto1 6-bytes key array, for now
 * @param credit how many credits is on the card
 *
 * @return execution status
 */
UFR_STATUS DL_API BalanceGet(uint32_t auth_mode, IN void *auth_value, VAR int32_t *credit);

/**
 * BalanceSet() sets balance of the AIS SDK formated cards
 *
 * @param auth_mode only MIFARE_AUTHENT1A supported for now
 * @param auth_value pointer to the Crypto1 6-bytes key array, for now
 * @param credit new credit balance
 *
 * @return execution status
 */
UFR_STATUS DL_API BalanceSet(uint32_t auth_mode, IN void *auth_value, int32_t credit);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// XXX: Support for multiple readers with same DLL
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#################  M U L T I   R E A D E R   S U P P O R T  #################
//#################  M U L T I   R E A D E R   S U P P O R T  #################
//#################  M U L T I   R E A D E R   S U P P O R T  #################
//#################  M U L T I   R E A D E R   S U P P O R T  #################
//#################  M U L T I   R E A D E R   S U P P O R T  #################
//#################  M U L T I   R E A D E R   S U P P O R T  #################
//#################  M U L T I   R E A D E R   S U P P O R T  #################
//#################  M U L T I   R E A D E R   S U P P O R T  #################
//#################  M U L T I   R E A D E R   S U P P O R T  #################
//#################  M U L T I   R E A D E R   S U P P O R T  #################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################
//#############################################################################

//--------------------------------------------------------------------------------------------------
/**
 * This is the main function of the multi-reader support.
 * ReaderList_UpdateAndGetCount() scan all communication ports for compatible devices.
 * Function probes opened readers if still connected, if not close and mark them handles for deletion.
 * If some device is disconnected from system this function should remove its handle.
 *
 * @param NumberOfDevices
 * @return status of execution
 */
UFR_STATUS DL_API ReaderList_UpdateAndGetCount(VAR int32_t * NumberOfDevices);

/**
 * Function for getting all relevant information about connected readers.
 *
 * Eg. If you have tree connected readers, detected by ReaderList_UpdateAndGetCount(),
 * you should call this function tree times.
 *
 * @param DeviceHandle
 * @param DeviceSerialNumber
 * @param DeviceType
 * @param DeviceFWver
 * @param DeviceCommID
 * @param DeviceCommSpeed
 * @param DeviceCommFTDISerial
 * @param DeviceCommFTDIDescription
 * @param DeviceIsOpened
 * @param DeviceStatus
 * @return
 */
UFR_STATUS DL_API ReaderList_GetInformation( //
		VAR UFR_HANDLE *DeviceHandle, //// assigned Handle
		OUT c_string *DeviceSerialNumber, //// device serial number
		VAR int *DeviceType, //// device type - device identification in AIS database
		VAR int *DeviceFWver, //// version of firmware
		VAR int *DeviceCommID, //// device identification number (master)
		VAR int *DeviceCommSpeed, //// communication speed
		OUT c_string *DeviceCommFTDISerial, //// FTDI COM port identification
		OUT c_string *DeviceCommFTDIDescription, //// FTDI COM port description
		VAR int *DeviceIsOpened, //// is Device opened
		VAR int *DeviceStatus //// actual device status
);

/**
 * If the handle exists in the list of opened devices,
 * function would try to close communication port and destroy the handle.
 * ( ReaderList_UpdateAndGetCount() will do that automatically in next execution)
 *
 * Good when you identify that the reader is no longer connected, and want to release the handle.
 *
 * @param DeviceHandle the handle that will be destroyed
 * @return
 */
UFR_STATUS DL_API ReaderList_Destroy(UFR_HANDLE DeviceHandle);

// XXX: Obsolete functions - remain for backward compatibility
UFR_STATUS DL_API ReaderList_GetSerialByIndex(int32_t DeviceIndex, VAR uint32_t *lpulSerialNumber);
UFR_STATUS DL_API ReaderList_GetSerialDescriptionByIndex(int32_t DeviceIndex, OUT uint8_t pSerialDescription[8]);
UFR_STATUS DL_API ReaderList_GetTypeByIndex(int32_t DeviceIndex, VAR uint32_t *lpulReaderType);
UFR_STATUS DL_API ReaderList_GetFTDISerialByIndex(int32_t DeviceIndex, OUT char ** Device_Serial);
UFR_STATUS DL_API ReaderList_GetFTDIDescriptionByIndex(int32_t DeviceIndex, OUT char ** Device_Description);
UFR_STATUS DL_API ReaderList_OpenByIndex(const int32_t DeviceIndex, VAR UFR_HANDLE *hndUFR);
UFR_STATUS DL_API ReaderList_OpenBySerial(const char Device_SN[16], VAR UFR_HANDLE *hndUFR); // ! not implemented

//--------------------------------------------------------------------------------------------------

// open first/next Reader and return handle - better to use ReaderList_OpenByIndex()
UFR_STATUS DL_API ReaderOpenM(VAR UFR_HANDLE *hndUFR);

UFR_STATUS DL_API ReaderResetM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API ReaderCloseM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API ReaderSoftRestartM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API GetReaderTypeM(UFR_HANDLE hndUFR,
                                 IN uint32_t *lpulReaderType);

UFR_STATUS DL_API GetReaderSerialNumberM(UFR_HANDLE hndUFR,
                                         IN uint32_t *lpulSerialNumber);

UFR_STATUS DL_API ReaderStillConnectedM(UFR_HANDLE hndUFR,
                                        VAR uint32_t *connected);

UFR_STATUS DL_API ReaderKeyWriteM(UFR_HANDLE hndUFR,
                                  IN const uint8_t *aucKey,
                                  uint8_t ucKeyIndex);

UFR_STATUS DL_API ReaderKeysLockM(UFR_HANDLE hndUFR,
                                  IN const uint8_t *password);

UFR_STATUS DL_API ReaderKeysUnlockM(UFR_HANDLE hndUFR,
                                    IN const uint8_t *password);

UFR_STATUS DL_API ReaderUISignalM(UFR_HANDLE hndUFR,
                                  uint8_t light_signal_mode,
                                  uint8_t beep_signal_mode);

UFR_STATUS DL_API ReadUserDataM(UFR_HANDLE hndUFR,
                                OUT uint8_t *aucData);

UFR_STATUS DL_API WriteUserDataM(UFR_HANDLE hndUFR,
                                 IN const uint8_t *aucData);

UFR_STATUS DL_API GetCardIdM(UFR_HANDLE hndUFR,
                             VAR uint8_t *lpucCardType,
                             OUT uint32_t *lpulCardSerial);

UFR_STATUS DL_API BlockReadM(UFR_HANDLE hndUFR,
                             OUT uint8_t *data,
                             uint8_t block_address,
                             uint8_t auth_mode,
                             uint8_t key_index);

UFR_STATUS DL_API BlockWriteM(UFR_HANDLE hndUFR,
                              IN const uint8_t *data,
                              uint8_t block_address,
                              uint8_t auth_mode,
                              uint8_t key_index);

UFR_STATUS DL_API BlockInSectorReadM(UFR_HANDLE hndUFR,
                                     OUT uint8_t *data,
                                     uint8_t sector_address,
                                     uint8_t block_in_sector_address,
                                     uint8_t auth_mode,
                                     uint8_t key_index);

UFR_STATUS DL_API BlockInSectorWriteM(UFR_HANDLE hndUFR,
                                      IN const uint8_t *data,
                                      uint8_t sector_address,
                                      uint8_t block_in_sector_address,
                                      uint8_t auth_mode,
                                      uint8_t key_index);

UFR_STATUS DL_API LinearReadM(UFR_HANDLE hndUFR,
                              OUT uint8_t *aucData,
                              uint16_t usLinearAddress,
                              uint16_t usDataLength,
                              VAR uint16_t *lpusBytesReturned,
                              uint8_t ucKeyMode,
                              uint8_t ucReaderKeyIndex);

UFR_STATUS DL_API LinRowReadM(UFR_HANDLE hndUFR,
                              OUT uint8_t *aucData,
                              uint16_t usLinearAddress,
                              uint16_t usDataLength,
                              VAR uint16_t *lpusBytesReturned,
                              uint8_t ucKeyMode,
                              uint8_t ucReaderKeyIndex);

UFR_STATUS DL_API LinearWriteM(UFR_HANDLE hndUFR,
                               IN const uint8_t *aucData,
                               uint16_t usLinearAddress,
                               uint16_t usDataLength,
                               VAR uint16_t *lpusBytesWritten,
                               uint8_t ucKeyMode,
                               uint8_t ucReaderKeyIndex);

UFR_STATUS DL_API LinearFormatCardM(UFR_HANDLE hndUFR,
                                    IN const uint8_t *new_key_A,
                                    uint8_t blocks_access_bits,
                                    uint8_t sector_trailers_access_bits,
                                    uint8_t sector_trailers_byte9,
                                    IN  const uint8_t *new_key_B,
                                    VAR uint8_t *lpucSectorsFormatted,
                                    uint8_t auth_mode,
                                    uint8_t key_index);

UFR_STATUS DL_API SectorTrailerWriteM(UFR_HANDLE hndUFR,
                                      uint8_t addressing_mode,
                                      uint8_t address,
                                      IN const uint8_t *new_key_A,
                                      uint8_t block0_access_bits,
                                      uint8_t block1_access_bits,
                                      uint8_t block2_access_bits,
                                      uint8_t sector_trailer_access_bits,
                                      uint8_t sector_trailer_byte9,
                                      IN const uint8_t *new_key_B,
                                      uint8_t auth_mode,
                                      uint8_t key_index);

UFR_STATUS DL_API SectorTrailerWriteUnsafeM(UFR_HANDLE hndUFR,
                                            uint8_t addressing_mode,
                                            uint8_t address,
                                            IN const uint8_t *sector_trailer,
                                            uint8_t auth_mode,
                                            uint8_t key_index);

UFR_STATUS DL_API ValueBlockReadM(UFR_HANDLE hndUFR,
                                  VAR int32_t *value,
                                  VAR uint8_t *value_addr,
                                  uint8_t block_address,
                                  uint8_t auth_mode,
                                  uint8_t key_index);

UFR_STATUS DL_API ValueBlockInSectorReadM(UFR_HANDLE hndUFR,
                                          VAR int32_t *value,
                                          VAR uint8_t *value_addr,
                                          uint8_t sector_address,
                                          uint8_t block_in_sector_address,
                                          uint8_t auth_mode,
                                          uint8_t key_index);

UFR_STATUS DL_API ValueBlockWriteM(UFR_HANDLE hndUFR,
                                   int32_t value,
                                   uint8_t value_addr,
                                   uint8_t block_address,
                                   uint8_t auth_mode,
                                   uint8_t key_index);

UFR_STATUS DL_API ValueBlockInSectorWriteM(UFR_HANDLE hndUFR,
                                           int32_t value,
                                           uint8_t value_addr,
                                           uint8_t sector_address,
                                           uint8_t block_in_sector_address,
                                           uint8_t auth_mode,
                                           uint8_t key_index);

UFR_STATUS DL_API ValueBlockIncrementM(UFR_HANDLE hndUFR,
                                       int32_t increment_value,
                                       uint8_t block_address,
                                       uint8_t auth_mode,
                                       uint8_t key_index);

UFR_STATUS DL_API ValueBlockInSectorIncrementM(UFR_HANDLE hndUFR,
                                               int32_t increment_value,
                                               uint8_t sector_address,
                                               uint8_t block_in_sector_address,
                                               uint8_t auth_mode,
                                               uint8_t key_index);

UFR_STATUS DL_API ValueBlockDecrementM(UFR_HANDLE hndUFR,
                                       int32_t decrement_value,
                                       uint8_t block_address,
                                       uint8_t auth_mode,
                                       uint8_t key_index);

UFR_STATUS DL_API ValueBlockInSectorDecrementM(UFR_HANDLE hndUFR,
                                               int32_t decrement_value,
                                               uint8_t sector_address,
                                               uint8_t block_in_sector_address,
                                               uint8_t auth_mode,
                                               uint8_t key_index);

UFR_STATUS DL_API BlockRead_AKM1M(UFR_HANDLE hndUFR,
                                  OUT uint8_t *data,
                                  uint8_t block_address,
                                  uint8_t auth_mode);

UFR_STATUS DL_API BlockWrite_AKM1M(UFR_HANDLE hndUFR,
                                   IN const uint8_t *data,
                                   uint8_t block_address,
                                   uint8_t auth_mode);

UFR_STATUS DL_API BlockInSectorRead_AKM1M(UFR_HANDLE hndUFR,
                                          OUT uint8_t *data,
                                          uint8_t sector_address,
                                          uint8_t block_in_sector_address,
                                          uint8_t auth_mode);

UFR_STATUS DL_API BlockInSectorWrite_AKM1M(UFR_HANDLE hndUFR,
                                           IN const uint8_t *data,
                                           uint8_t sector_address,
                                           uint8_t block_in_sector_address,
                                           uint8_t auth_mode);

UFR_STATUS DL_API LinearRead_AKM1M(UFR_HANDLE hndUFR,
                                   OUT uint8_t *data,
                                   uint16_t linear_address,
                                   uint16_t length,
                                   VAR uint16_t *bytes_returned,
                                   uint8_t auth_mode);

UFR_STATUS DL_API LinRowRead_AKM1M(UFR_HANDLE hndUFR,
                                   OUT uint8_t *data,
                                   uint16_t linear_address,
                                   uint16_t length,
                                   VAR uint16_t *bytes_returned,
                                   uint8_t auth_mode);

UFR_STATUS DL_API LinearWrite_AKM1M(UFR_HANDLE hndUFR,
                                    IN const uint8_t *data,
                                    uint16_t linear_address,
                                    uint16_t length,
                                    VAR uint16_t *bytes_written,
                                    uint8_t auth_mode);

UFR_STATUS DL_API LinearFormatCard_AKM1M(UFR_HANDLE hndUFR,
                                         IN const uint8_t *new_key_A,
                                         uint8_t blocks_access_bits,
                                         uint8_t sector_trailers_access_bits,
                                         uint8_t sector_trailers_byte9,
                                         IN const uint8_t *new_key_B,
                                         VAR uint8_t *lpucSectorsFormatted,
                                         uint8_t auth_mode);

UFR_STATUS DL_API SectorTrailerWrite_AKM1M(UFR_HANDLE hndUFR,
                                           uint8_t addressing_mode,
                                           uint8_t address,
                                           IN const uint8_t *new_key_A,
                                           uint8_t block0_access_bits,
                                           uint8_t block1_access_bits,
                                           uint8_t block2_access_bits,
                                           uint8_t sector_trailer_access_bits,
                                           uint8_t sector_trailer_byte9,
                                           IN const uint8_t *new_key_B,
                                           uint8_t auth_mode);

UFR_STATUS DL_API SectorTrailerWriteUnsafe_AKM1M(UFR_HANDLE hndUFR,
                                                 uint8_t addressing_mode,
                                                 uint8_t address,
                                                 IN const uint8_t *sector_trailer,
                                                 uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockRead_AKM1M(UFR_HANDLE hndUFR,
                                       VAR int32_t *value,
                                       VAR uint8_t *value_addr,
                                       uint8_t block_address,
                                       uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockInSectorRead_AKM1M(UFR_HANDLE hndUFR,
                                               VAR int32_t *value,
                                               VAR uint8_t *value_addr,
                                               uint8_t sector_address,
                                               uint8_t block_in_sector_address,
                                               uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockWrite_AKM1M(UFR_HANDLE hndUFR,
                                        int32_t value,
                                        uint8_t value_addr,
                                        uint8_t block_address,
                                        uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockInSectorWrite_AKM1M(UFR_HANDLE hndUFR,
                                                int32_t value,
                                                uint8_t value_addr,
                                                uint8_t sector_address,
                                                uint8_t block_in_sector_address,
                                                uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockIncrement_AKM1M(UFR_HANDLE hndUFR,
                                            int32_t increment_value,
                                            uint8_t block_address,
                                            uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockInSectorIncrement_AKM1M(UFR_HANDLE hndUFR,
                                                    int32_t increment_value,
                                                    uint8_t sector_address,
                                                    uint8_t block_in_sector_address,
                                                    uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockDecrement_AKM1M(UFR_HANDLE hndUFR,
                                            int32_t decrement_value,
                                            uint8_t block_address,
                                            uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockInSectorDecrement_AKM1M(UFR_HANDLE hndUFR,
                                                    int32_t decrement_value,
                                                    uint8_t sector_address,
                                                    uint8_t block_in_sector_address,
                                                    uint8_t auth_mode);

UFR_STATUS DL_API BlockRead_AKM2M(UFR_HANDLE hndUFR,
                                  OUT uint8_t *data,
                                  uint8_t block_address,
                                  uint8_t auth_mode);

UFR_STATUS DL_API BlockWrite_AKM2M(UFR_HANDLE hndUFR,
                                   IN const uint8_t *data,
                                   uint8_t block_address,
                                   uint8_t auth_mode);

UFR_STATUS DL_API BlockInSectorRead_AKM2M(UFR_HANDLE hndUFR,
                                          OUT uint8_t *data,
                                          uint8_t sector_address,
                                          uint8_t block_in_sector_address,
                                          uint8_t auth_mode);

UFR_STATUS DL_API BlockInSectorWrite_AKM2M(UFR_HANDLE hndUFR,
                                           IN const uint8_t *data,
                                           uint8_t sector_address,
                                           uint8_t block_in_sector_address,
                                           uint8_t auth_mode);

UFR_STATUS DL_API LinearRead_AKM2M(UFR_HANDLE hndUFR,
                                   OUT uint8_t *data,
                                   uint16_t linear_address,
                                   uint16_t length,
                                   VAR uint16_t *bytes_returned,
                                   uint8_t auth_mode);

UFR_STATUS DL_API LinRowRead_AKM2M(UFR_HANDLE hndUFR,
                                   OUT uint8_t *data,
                                   uint16_t linear_address,
                                   uint16_t length,
                                   VAR uint16_t *bytes_returned,
                                   uint8_t auth_mode);

UFR_STATUS DL_API LinearWrite_AKM2M(UFR_HANDLE hndUFR,
                                    IN const uint8_t *data,
                                    uint16_t linear_address,
                                    uint16_t length,
                                    VAR uint16_t *bytes_written,
                                    uint8_t auth_mode);

UFR_STATUS DL_API LinearFormatCard_AKM2M(UFR_HANDLE hndUFR,
                                         IN const uint8_t *new_key_A,
                                         uint8_t blocks_access_bits,
                                         uint8_t sector_trailers_access_bits,
                                         uint8_t sector_trailers_byte9,
                                         IN const uint8_t *new_key_B,
                                         VAR uint8_t *lpucSectorsFormatted,
                                         uint8_t auth_mode);

UFR_STATUS DL_API SectorTrailerWrite_AKM2M(UFR_HANDLE hndUFR,
                                           uint8_t addressing_mode,
                                           uint8_t address,
                                           IN const uint8_t *new_key_A,
                                           uint8_t block0_access_bits,
                                           uint8_t block1_access_bits,
                                           uint8_t block2_access_bits,
                                           uint8_t sector_trailer_access_bits,
                                           uint8_t sector_trailer_byte9,
                                           IN const uint8_t *new_key_B,
                                           uint8_t auth_mode);

UFR_STATUS DL_API SectorTrailerWriteUnsafe_AKM2M(UFR_HANDLE hndUFR,
                                                 uint8_t addressing_mode,
                                                 uint8_t address,
                                                 IN const uint8_t *sector_trailer,
                                                 uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockRead_AKM2M(UFR_HANDLE hndUFR,
                                       VAR int32_t *value,
                                       VAR uint8_t *value_addr,
                                       uint8_t block_address,
                                       uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockInSectorRead_AKM2M(UFR_HANDLE hndUFR,
                                               VAR int32_t *value,
                                               VAR uint8_t *value_addr,
                                               uint8_t sector_address,
                                               uint8_t block_in_sector_address,
                                               uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockWrite_AKM2M(UFR_HANDLE hndUFR,
                                        int32_t value,
                                        uint8_t value_addr,
                                        uint8_t block_address,
                                        uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockInSectorWrite_AKM2M(UFR_HANDLE hndUFR,
                                                int32_t value,
                                                uint8_t value_addr,
                                                uint8_t sector_address,
                                                uint8_t block_in_sector_address,
                                                uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockIncrement_AKM2M(UFR_HANDLE hndUFR,
                                            int32_t increment_value,
                                            uint8_t block_address,
                                            uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockInSectorIncrement_AKM2M(UFR_HANDLE hndUFR,
                                                    int32_t increment_value,
                                                    uint8_t sector_address,
                                                    uint8_t block_in_sector_address,
                                                    uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockDecrement_AKM2M(UFR_HANDLE hndUFR,
                                            int32_t decrement_value,
                                            uint8_t block_address,
                                            uint8_t auth_mode);

UFR_STATUS DL_API ValueBlockInSectorDecrement_AKM2M(UFR_HANDLE hndUFR,
                                                    int32_t decrement_value,
                                                    uint8_t sector_address,
                                                    uint8_t block_in_sector_address,
                                                    uint8_t auth_mode);

UFR_STATUS DL_API BlockRead_PKM(UFR_HANDLE hndUFR,
                                OUT uint8_t *data,
                                uint8_t block_address,
                                uint8_t auth_mode,
                                IN const uint8_t *key);

UFR_STATUS DL_API BlockWrite_PKM(UFR_HANDLE hndUFR,
                                 IN const uint8_t *data,
                                 uint8_t block_address,
                                 uint8_t auth_mode,
                                 IN const uint8_t *key);

UFR_STATUS DL_API BlockInSectorRead_PKM(UFR_HANDLE hndUFR,
                                        OUT uint8_t *data,
                                        uint8_t sector_address,
                                        uint8_t block_in_sector_address,
                                        uint8_t auth_mode,
                                        IN const uint8_t *key);

UFR_STATUS DL_API BlockInSectorWrite_PKM(UFR_HANDLE hndUFR,
                                         IN const uint8_t *data,
                                         uint8_t sector_address,
                                         uint8_t block_in_sector_address,
                                         uint8_t auth_mode,
                                         IN const uint8_t *key);

UFR_STATUS DL_API LinearRead_PKM(UFR_HANDLE hndUFR,
                                 OUT uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 VAR uint16_t *bytes_returned,
                                 uint8_t auth_mode,
                                 IN const uint8_t *key);

UFR_STATUS DL_API LinRowRead_PKM(UFR_HANDLE hndUFR,
                                 OUT uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 VAR uint16_t *bytes_returned,
                                 uint8_t auth_mode,
                                 IN const uint8_t *key);

UFR_STATUS DL_API LinearWrite_PKM(UFR_HANDLE hndUFR,
                                  IN const uint8_t *data,
                                  uint16_t linear_address,
                                  uint16_t length,
                                  VAR uint16_t *bytes_written,
                                  uint8_t auth_mode,
                                  IN const uint8_t *key);

UFR_STATUS DL_API LinearFormatCard_PKM(UFR_HANDLE hndUFR,
                                       IN const uint8_t *new_key_A,
                                       uint8_t blocks_access_bits,
                                       uint8_t sector_trailers_access_bits,
                                       uint8_t sector_trailers_byte9,
                                       IN const uint8_t *new_key_B,
                                       VAR uint8_t *lpucSectorsFormatted,
                                       uint8_t auth_mode,
                                       IN const uint8_t *key);

UFR_STATUS DL_API SectorTrailerWrite_PKM(UFR_HANDLE hndUFR,
                                         uint8_t addressing_mode,
                                         uint8_t address,
                                         IN const uint8_t *new_key_A,
                                         uint8_t block0_access_bits,
                                         uint8_t block1_access_bits,
                                         uint8_t block2_access_bits,
                                         uint8_t sector_trailer_access_bits,
                                         uint8_t sector_trailer_byte9,
                                         IN const uint8_t *new_key_B,
                                         uint8_t auth_mode,
                                         IN const uint8_t *key);

UFR_STATUS DL_API SectorTrailerWriteUnsafe_PKM(UFR_HANDLE hndUFR,
                                               uint8_t addressing_mode,
                                               uint8_t address,
                                               IN const uint8_t *sector_trailer,
                                               uint8_t auth_mode,
                                               IN const uint8_t *key);

UFR_STATUS DL_API ValueBlockRead_PKM(UFR_HANDLE hndUFR,
                                     VAR int32_t *value,
                                     VAR uint8_t *value_addr,
                                     uint8_t block_address,
                                     uint8_t auth_mode,
                                     IN const uint8_t *key);

UFR_STATUS DL_API ValueBlockInSectorRead_PKM(UFR_HANDLE hndUFR,
                                             VAR int32_t *value,
                                             VAR uint8_t *value_addr,
                                             uint8_t sector_address,
                                             uint8_t block_in_sector_address,
                                             uint8_t auth_mode,
                                             IN const uint8_t *key);

UFR_STATUS DL_API ValueBlockWrite_PKM(UFR_HANDLE hndUFR,
                                      int32_t value,
                                      uint8_t value_addr,
                                      uint8_t block_address,
                                      uint8_t auth_mode,
                                      IN const uint8_t *key);

UFR_STATUS DL_API ValueBlockInSectorWrite_PKM(UFR_HANDLE hndUFR,
                                              int32_t value,
                                              uint8_t value_addr,
                                              uint8_t sector_address,
                                              uint8_t block_in_sector_address,
                                              uint8_t auth_mode,
                                              IN const uint8_t *key);

UFR_STATUS DL_API ValueBlockIncrement_PKM(UFR_HANDLE hndUFR,
                                          int32_t increment_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode,
                                          IN const uint8_t *key);

UFR_STATUS DL_API ValueBlockInSectorIncrement_PKM(UFR_HANDLE hndUFR,
                                                  int32_t increment_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode,
                                                  IN const uint8_t *key);

UFR_STATUS DL_API ValueBlockDecrement_PKM(UFR_HANDLE hndUFR,
                                          int32_t decrement_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode,
                                          IN const uint8_t *key);

UFR_STATUS DL_API ValueBlockInSectorDecrement_PKM(UFR_HANDLE hndUFR,
                                                  int32_t decrement_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode,
                                                  IN const uint8_t *key);

UFR_STATUS DL_API GetReaderHardwareVersionM(UFR_HANDLE hndUFR,
                                            VAR uint8_t *version_major,
                                            VAR uint8_t *version_minor);

UFR_STATUS DL_API GetReaderFirmwareVersionM(UFR_HANDLE hndUFR,
                                            VAR uint8_t *version_major,
                                            VAR uint8_t *version_minor);

// New commands (for RTC & I2C EEPROM):
UFR_STATUS DL_API GetReaderTimeM(UFR_HANDLE hndUFR,
                                 VAR uint8_t *time);

UFR_STATUS DL_API SetReaderTimeM(UFR_HANDLE hndUFR,
                                 IN uint8_t *password,
                                 VAR uint8_t *time);

UFR_STATUS DL_API ChangeReaderPasswordM(UFR_HANDLE hndUFR,
                                        IN uint8_t *old_password,
                                        IN uint8_t *new_password);

UFR_STATUS DL_API ReaderEepromWriteM(UFR_HANDLE hndUFR,
                                     IN uint8_t *data,
                                     uint32_t address,
                                     uint32_t size,
                                     IN uint8_t *password);

UFR_STATUS DL_API ReaderEepromReadM(UFR_HANDLE hndUFR,
                                    OUT uint8_t *data,
                                    uint32_t address,
                                    uint32_t size);

UFR_STATUS DL_API GetReaderSerialDescriptionM(UFR_HANDLE hndUFR,
                                              OUT uint8_t pSerialDescription[8]);

// New since version 2.0:
UFR_STATUS DL_API GetBuildNumberM(UFR_HANDLE hndUFR,
                                  VAR uint8_t *build);

UFR_STATUS DL_API GetCardIdExM(UFR_HANDLE hndUFR,
                               VAR uint8_t *lpucSak,
                               OUT uint8_t *aucUid,
                               VAR uint8_t *lpucUidSize);

UFR_STATUS DL_API GetLastCardIdExM(UFR_HANDLE hndUFR,
                                   VAR uint8_t *lpucSak,
                                   OUT uint8_t *aucUid,
                                   VAR uint8_t *lpucUidSize);

//------------------------------------------------------------------------------
//Multi card mode:
//------------------------------------------------------------------------------
UFR_STATUS DL_API EnableAntiCollisionM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API DisableAntiCollisionM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API EnumCardsM(UFR_HANDLE hndUFR,
                             VAR uint8_t *lpucCardsNumber,
                             OUT uint8_t *lpucUidListSize); // Card pointer is on the first card in list

UFR_STATUS DL_API ListCardsM(UFR_HANDLE hndUFR,
                             OUT uint8_t *aucUidList,
                             uint8_t ucUidListSize); // Before calling this function you must call EnumCards() first.

UFR_STATUS DL_API SelectCardM(UFR_HANDLE hndUFR,
                              IN const uint8_t *aucUid,
                              uint8_t ucUidSize,
                              OUT uint8_t *lpucSelctedCardType);

UFR_STATUS DL_API DeslectCardM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API GetAntiCollisionStatusM(UFR_HANDLE hndUFR,
                                          VAR int8_t *lpcIsAntiCollEnabled,
                                          VAR int8_t *lpcIsAnyCardSelected);
//------------------------------------------------------------------------------

UFR_STATUS DL_API GetDlogicCardTypeM(UFR_HANDLE hndUFR,
                                     VAR uint8_t *lpucCardType);

UFR_STATUS DL_API GetNfcT2TVersionM(UFR_HANDLE hndUFR,
                                    OUT uint8_t lpucVersionResponse[8]);

UFR_STATUS DL_API GetCardSizeM(UFR_HANDLE hndUFR,
                               VAR uint32_t *lpulLinearSize,
                               VAR uint32_t *lpulRawSize);

// uFCoder PRO MODE
UFR_STATUS DL_API GetReaderProModeM(UFR_HANDLE hndUFR,
                                    VAR uint32_t *pReaderProMode,
                                    OUT uint32_t *pReaderProConfig);

UFR_STATUS DL_API SetReaderProModeM(UFR_HANDLE hndUFR,
                                    const uint32_t ReaderProMode);

// QR barcode crypt algorithm
// initialization. with TB serial like 'TB123456'
UFR_STATUS DL_API CardEncryption_InitializeM(UFR_HANDLE hndUFR,
                                             IN const uint8_t *TBSerialString,
                                             uint16_t job_number);

// You must define 25 bytes array in memory for out_card_data[]
UFR_STATUS DL_API CardEncryption_GetNextEncryptedCardM(UFR_HANDLE hndUFR,
                                                       const uint32_t from_timestamp,
                                                       const uint32_t to_timestamp,
                                                       OUT uint8_t out_card_data[]);

UFR_STATUS DL_API CardEncryption_GetNextM(UFR_HANDLE hndUFR,
                                          const uint32_t code_type,
                                          const uint32_t from_timestamp,
                                          const uint32_t to_timestamp,
                                          const uint32_t additional_data_size,
                                          IN const uint8_t additional_data[],
                                          VAR uint32_t *out_card_data_size,
                                          OUT uint8_t out_card_data[]);

UFR_STATUS DL_API CardEncryption_GetActualCardSNM(UFR_HANDLE hndUFR,
                                                  OUT uint32_t *ActualCard_SN,
                                                  VAR uint32_t *ActualCard_SN_LOG);

UFR_STATUS DL_API CardEncryption_GetJobSNM(UFR_HANDLE hndUFR,
                                           VAR uint32_t *JobSN);

UFR_STATUS DL_API CardEncryption_GetSalterSNM(UFR_HANDLE hndUFR,
                                              OUT uint8_t SalterSN[8],
                                              VAR uint8_t * magicByte);

UFR_STATUS DL_API read_ndef_recordM(UFR_HANDLE hndUFR,
                                    uint8_t message_nr,
                                    uint8_t record_nr,
                                    VAR uint8_t *tnf,
                                    OUT uint8_t *type_record,
                                    VAR uint8_t *type_length,
                                    OUT uint8_t *id,
                                    VAR uint8_t *id_length,
                                    OUT uint8_t *payload,
                                    VAR uint32_t *payload_length);

UFR_STATUS DL_API write_ndef_recordM(UFR_HANDLE hndUFR,
                                     uint8_t message_nr,
                                     uint8_t *tnf,
                                     IN uint8_t *type_record,
                                     uint8_t *type_length,
                                     IN uint8_t *id,
                                     uint8_t *id_length,
                                     IN uint8_t *payload,
                                     uint32_t *payload_length,
                                     VAR uint8_t *card_formated);

UFR_STATUS DL_API write_ndef_record_mirroringM(UFR_HANDLE hndUFR,
                                               uint8_t message_nr,
                                               uint8_t *tnf,
                                               IN uint8_t *type_record,
                                               uint8_t *type_length,
                                               IN uint8_t *id,
                                               uint8_t *id_length,
                                               IN uint8_t *payload,
                                               uint32_t *payload_length,
                                               VAR uint8_t *card_formated,
                                               int use_uid_ascii_mirror,
                                               int use_counter_ascii_mirror,
                                               uint32_t payload_mirroring_pos);

UFR_STATUS DL_API get_ndef_record_countM(UFR_HANDLE hndUFR,
                                         VAR uint8_t *ndef_message_cnt,
                                         VAR uint8_t *ndef_record_cnt,
                                         OUT uint8_t *ndef_record_array,
                                         VAR uint8_t *empty_ndef_message_cnt);

UFR_STATUS DL_API erase_last_ndef_recordM(UFR_HANDLE hndUFR,
                                          uint8_t message_nr);

UFR_STATUS DL_API erase_all_ndef_recordsM(UFR_HANDLE hndUFR,
                                          uint8_t message_nr);

UFR_STATUS DL_API ndef_card_initializationM(UFR_HANDLE hndUFR);

//---------------------------------------------------------------------
// Card emulation:
//---------------------------------------------------------------------
UFR_STATUS DL_API WriteEmulationNdefM(UFR_HANDLE hndUFR,
                                      uint8_t tnf,
                                      IN uint8_t* type_record,
                                      uint8_t type_length,
                                      IN uint8_t* id,
                                      uint8_t id_length,
                                      IN uint8_t* payload,
                                      uint8_t payload_length);

UFR_STATUS DL_API TagEmulationStartM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API TagEmulationStopM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API CombinedModeEmulationStartM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API AdHocEmulationStartM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API AdHocEmulationStopM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API GetAdHocEmulationParamsM(UFR_HANDLE hndUFR,
                                           VAR uint8_t *ThresholdMinLevel,
                                           VAR uint8_t *ThresholdCollLevel,
                                           VAR uint8_t *RFLevelAmp,
                                           VAR uint8_t *RxGain,
                                           VAR uint8_t *RFLevel);

UFR_STATUS DL_API SetAdHocEmulationParamsM(UFR_HANDLE hndUFR,
                                           uint8_t ThresholdMinLevel,
                                           uint8_t ThresholdCollLevel,
                                           uint8_t RFLevelAmp,
                                           uint8_t RxGain,
                                           uint8_t RFLevel);

UFR_STATUS DL_API GetExternalFieldStateM(UFR_HANDLE hndUFR,
                                         VAR uint8_t *is_field_present);
//------------------------------------------------------------------------------
UFR_STATUS DL_API ReadECCSignatureM(UFR_HANDLE hndUFR,
                                    IN uint8_t lpucECCSignature[ECC_SIG_LEN],
                                    OUT uint8_t lpucUid[MAX_UID_LEN],
                                    VAR uint8_t *lpucUidLen,
                                    VAR uint8_t *lpucDlogicCardType);

//------------------------------------------------------------------------------
UFR_STATUS DL_API ReadCounterM(UFR_HANDLE hndUFR,
                               uint8_t counter_address,
                               VAR uint32_t *value);

UFR_STATUS DL_API IncrementCounterM(UFR_HANDLE hndUFR,
                                    uint8_t counter_address,
                                    uint32_t inc_value);

UFR_STATUS DL_API ReadNFCCounterM(UFR_HANDLE hndUFR,
                                  VAR uint32_t *value); // Same as ReadCounter(2, &value);

UFR_STATUS DL_API ReadNFCCounterPwdAuth_RKM(UFR_HANDLE hndUFR,
                                            VAR uint32_t *value,
                                            uint8_t reader_key_index);

UFR_STATUS DL_API ReadNFCCounterPwdAuth_PKM(UFR_HANDLE hndUFR,
                                            VAR uint32_t *value,
                                            IN const uint8_t *key);
//------------------------------------------------------------------------------

UFR_STATUS DL_API SetAsyncCardIdSendConfigM(UFR_HANDLE hndUFR,
                                            uint8_t send_enable,
                                            uint8_t prefix_enable,
                                            uint8_t prefix,
                                            uint8_t suffix,
                                            uint8_t send_removed_enable,
                                            uint32_t async_baud_rate);

UFR_STATUS DL_API SetAsyncCardIdSendConfigExM(UFR_HANDLE hndUFR,
                                              uint8_t send_enable,
                                              uint8_t prefix_enable,
                                              uint8_t prefix,
                                              uint8_t suffix,
                                              uint8_t send_removed_enable,
                                              uint8_t reverse_byte_order,
                                              uint8_t decimal_representation,
                                              uint32_t async_baud_rate);

UFR_STATUS DL_API GetAsyncCardIdSendConfigM(UFR_HANDLE hndUFR,
                                            VAR uint8_t *send_enable,
                                            VAR uint8_t *prefix_enable,
                                            VAR uint8_t *prefix,
                                            VAR uint8_t *suffix,
                                            VAR uint8_t *send_removed_enable,
                                            VAR uint32_t *async_baud_rate);

UFR_STATUS DL_API GetAsyncCardIdSendConfigExM(UFR_HANDLE hndUFR,
                                              VAR uint8_t *send_enable,
                                              VAR uint8_t *prefix_enable,
                                              VAR uint8_t *prefix,
                                              VAR uint8_t *suffix,
                                              VAR uint8_t *send_removed_enable,
                                              VAR uint8_t *reverse_byte_order,
                                              VAR uint8_t *decimal_representation,
                                              VAR uint32_t *async_baud_rate);

/*****************************************************************************
 * AIS FUNCTIONS
 *****************************************************************************
 */

UFR_STATUS DL_API ais_get_card_numberM(UFR_HANDLE hndUFR,
                                       VAR uint32_t *card_number);

UFR_STATUS DL_API ais_set_right_recordM(UFR_HANDLE hndUFR,
                                        uint8_t record_number,
                                        uint16_t first_reader_nr,
                                        uint16_t last_reader_nr,
                                        uint8_t start_hour,
                                        uint8_t start_minute,
                                        uint8_t end_hour,
                                        uint8_t end_minute,
                                        IN uint8_t *days);

UFR_STATUS DL_API ais_get_right_recordM(UFR_HANDLE hndUFR,
                                        uint8_t record_number,
                                        VAR uint16_t *first_reader_nr,
                                        VAR uint16_t *last_reader_nr,
                                        VAR uint8_t *start_hour,
                                        VAR uint8_t *start_minute,
                                        VAR uint8_t *end_hour,
                                        VAR uint8_t *end_minute,
                                        OUT uint8_t *days);

UFR_STATUS DL_API ais_erase_right_recordM(UFR_HANDLE hndUFR,
                                          uint8_t record_number);

UFR_STATUS DL_API ais_set_validate_recordM(UFR_HANDLE hndUFR,
                                           uint8_t begin_year,
                                           uint8_t begin_month,
                                           uint8_t begin_day,
                                           uint8_t begin_hour,
                                           uint8_t begin_minute,
                                           uint8_t end_year,
                                           uint8_t end_month,
                                           uint8_t end_day,
                                           uint8_t end_hour,
                                           uint8_t end_minute);

UFR_STATUS DL_API ais_get_validate_recordM(UFR_HANDLE hndUFR,
                                           VAR uint8_t *begin_year,
                                           VAR uint8_t *begin_month,
                                           VAR uint8_t *begin_day,
                                           VAR uint8_t *begin_hour,
                                           VAR uint8_t *begin_minute,
                                           VAR uint8_t *end_year,
                                           VAR uint8_t *end_month,
                                           VAR uint8_t *end_day,
                                           VAR uint8_t *end_hour,
                                           VAR uint8_t *end_minute);

UFR_STATUS DL_API ais_set_card_typeM(UFR_HANDLE hndUFR,
                                     uint8_t card_type);

UFR_STATUS DL_API ais_get_card_typeM(UFR_HANDLE hndUFR,
                                     VAR uint8_t *card_type);

UFR_STATUS DL_API ais_set_card_daily_durationM(UFR_HANDLE hndUFR,
                                               uint16_t duration);

UFR_STATUS DL_API ais_get_card_daily_durationM(UFR_HANDLE hndUFR,
                                               VAR uint16_t *duration);

UFR_STATUS DL_API ais_set_card_total_durationM(UFR_HANDLE hndUFR,
                                               uint32_t duration);

UFR_STATUS DL_API ais_get_card_total_durationM(UFR_HANDLE hndUFR,
                                               VAR uint32_t *duration);

// swimming pool **************************************************************

UFR_STATUS DL_API ais_get_credit_and_period_validityM(UFR_HANDLE hndUFR,
                                                      VAR int32_t *credit,
                                                      VAR uint32_t *begin_year,
                                                      VAR uint32_t *begin_month,
                                                      VAR uint32_t *begin_day,
                                                      VAR uint32_t *begin_hour,
                                                      VAR uint32_t *begin_minute,
                                                      VAR uint32_t *end_year,
                                                      VAR uint32_t *end_month,
                                                      VAR uint32_t *end_day,
                                                      VAR uint32_t *end_hour,
                                                      VAR uint32_t *end_minute);

UFR_STATUS DL_API ais_set_credit_and_period_validityM(UFR_HANDLE hndUFR,
                                                      int32_t credit,
                                                      uint32_t begin_year,
                                                      uint32_t begin_month,
                                                      uint32_t begin_day,
                                                      uint32_t begin_hour,
                                                      uint32_t begin_minute,
                                                      uint32_t end_year,
                                                      uint32_t end_month,
                                                      uint32_t end_day,
                                                      uint32_t end_hour,
                                                      uint32_t end_minute);

UFR_STATUS DL_API ais_set_right_type_recordM(UFR_HANDLE hndUFR,
                                             uint8_t record_number,
                                             uint8_t right_record_type,
                                             IN uint8_t *right_data);

UFR_STATUS DL_API ais_get_right_type_recordM(UFR_HANDLE hndUFR,
                                             uint8_t record_number,
                                             VAR uint8_t *right_record_type,
                                             OUT uint8_t *right_data);

UFR_STATUS DL_API ais_set_right_record_type_max_daily_counterM(UFR_HANDLE hndUFR,
                                                               uint8_t record_number,
                                                               uint16_t first_reader_nr,
                                                               uint16_t last_reader_nr,
                                                               uint8_t start_hour,
                                                               uint8_t start_minute,
                                                               uint8_t end_hour,
                                                               uint8_t end_minute,
                                                               IN uint8_t *days,
                                                               uint8_t max_daily_counter);

//=============================================================================

UFR_STATUS DL_API UfrXrcLockOnM(UFR_HANDLE hndUFR,
                                uint16_t pulse_duration);

UFR_STATUS DL_API UfrXrcRelayStateM(UFR_HANDLE hndUFR,
                                    uint8_t state);

UFR_STATUS DL_API UfrXrcGetIoStateM(UFR_HANDLE hndUFR,
                                    VAR uint8_t *intercom,
                                    VAR uint8_t *door,
                                    VAR uint8_t *relay_state);

UFR_STATUS DL_API UfrRedLightControlM(UFR_HANDLE hndUFR,
                                      uint8_t light_status);

UFR_STATUS DL_API UfrRgbLightControlM(UFR_HANDLE hndUFR,
                                      uint8_t red,
                                      uint8_t green,
                                      uint8_t blue,
                                      uint8_t intensity,
                                      uint8_t enable);

UFR_STATUS DL_API UfrSetBadSelectCardNrMaxM(UFR_HANDLE hndUFR,
                                            uint8_t bad_select_nr_max);

UFR_STATUS DL_API UfrGetBadSelectCardNrMaxM(UFR_HANDLE hndUFR,
                                            VAR uint8_t *bad_select_nr_max);

UFR_STATUS DL_API UfrEnterSleepModeM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API UfrLeaveSleepModeM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API AutoSleepSetM(UFR_HANDLE hndUFR,
                                uint8_t seconds_wait);

UFR_STATUS DL_API AutoSleepGetM(UFR_HANDLE hndUFR,
                                VAR uint8_t *seconds_wait);

UFR_STATUS DL_API SetSpeedPermanentlyM(UFR_HANDLE hndUFR,
                                       unsigned char tx_speed,
                                       unsigned char rx_speed);

UFR_STATUS DL_API GetSpeedParametersM(UFR_HANDLE hndUFR,
                                      VAR unsigned char *tx_speed,
                                      VAR unsigned char *rx_speed);

UFR_STATUS DL_API SetDisplayDataM(UFR_HANDLE hndUFR,
                                  IN uint8_t *display_data,
                                  uint8_t data_length);

UFR_STATUS DL_API SetSpeakerFrequencyM(UFR_HANDLE hndUFR,
                                       uint16_t frequency);

UFR_STATUS DL_API SetDisplayIntensityM(UFR_HANDLE hndUFR,
                                       uint8_t intensity);

UFR_STATUS DL_API GetDisplayIntensityM(UFR_HANDLE hndUFR,
                                       VAR uint8_t *intensity);

//#############################################################################
//#############################################################################

UFR_STATUS DL_API SetISO14443_4_ModeM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API SetISO14443_4_DLStorageM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API uFR_i_block_transceiveM(UFR_HANDLE hndUFR,
                                          uint8_t chaining,
                                          uint8_t timeout,
                                          uint8_t block_length,
                                          IN uint8_t *snd_data_array,
                                          VAR size_t *rcv_length,
                                          OUT uint8_t *rcv_data_array,
                                          VAR uint32_t *ufr_status);

UFR_STATUS DL_API uFR_APDU_TransceiveM(UFR_HANDLE hndUFR,
                                       uint8_t cls,
                                       uint8_t ins,
                                       uint8_t p1,
                                       uint8_t p2,
                                       IN uint8_t *data_out,
                                       uint8_t data_out_len,
                                       OUT uint8_t *data_in,
                                       uint32_t max_data_in_len,
                                       VAR uint32_t *response_len,
                                       uint8_t send_le,
                                       OUT uint8_t *apdu_status);

UFR_STATUS DL_API APDUHexStrTransceiveM(UFR_HANDLE hndUFR,
                                        IN const char *c_apdu,
                                        OUT char **r_apdu);

UFR_STATUS DL_API APDUPlainTransceiveM(UFR_HANDLE hndUFR,
                                       IN const uint8_t *c_apdu,
                                       uint32_t c_apdu_len,
                                       OUT uint8_t *r_apdu,
                                       VAR uint32_t *r_apdu_len);

UFR_STATUS DL_API APDUTransceiveM(UFR_HANDLE hndUFR,
                                  uint8_t cls,
                                  uint8_t ins,
                                  uint8_t p1,
                                  uint8_t p2,
                                  IN const uint8_t *data_out,
                                  uint32_t Nc,
                                  OUT uint8_t *data_in,
                                  VAR uint32_t *Ne,
                                  uint8_t send_le,
                                  OUT uint8_t *apdu_status);

UFR_STATUS DL_API i_block_trans_rcv_chainM(UFR_HANDLE hndUFR,
                                           uint8_t chaining,
                                           uint8_t timeout,
                                           uint8_t block_length,
                                           IN uint8_t *snd_data_array,
                                           VAR uint8_t *rcv_length,
                                           OUT uint8_t *rcv_data_array,
                                           VAR uint8_t *rcv_chained,
                                           VAR uint32_t *ufr_status);

UFR_STATUS DL_API r_block_transceiveM(UFR_HANDLE hndUFR,
                                      uint8_t ack,
                                      uint8_t timeout,
                                      VAR uint8_t *rcv_length,
                                      OUT uint8_t *rcv_data_array,
                                      VAR uint8_t *rcv_chained,
                                      VAR uint32_t *ufr_status);

UFR_STATUS DL_API s_block_deselectM(UFR_HANDLE hndUFR,
                                    uint8_t timeout);

UFR_STATUS DL_API card_transceiveM(UFR_HANDLE hndUFR,
                                   uint8_t card_activate,
                                   uint8_t card_halted,
                                   uint8_t tx_crc,
                                   uint8_t rx_crc,
                                   uint8_t crypto1,
                                   uint32_t timeout,
                                   IN uint8_t *tx_data,
                                   uint8_t tx_data_len,
                                   OUT uint8_t *rx_data,
                                   VAR uint8_t *rx_data_len);

UFR_STATUS DL_API card_transceive_mode_startM(UFR_HANDLE hndUFR,
                                              uint8_t tx_crc,
                                              uint8_t rx_crc,
                                              uint32_t rf_timeout,
                                              uint32_t uart_timeout);

UFR_STATUS DL_API card_transceive_mode_stopM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API card_halt_enableM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API uart_transceiveM(UFR_HANDLE hndUFR,
                                   IN uint8_t *send_data,
                                   uint8_t send_len,
                                   OUT uint8_t *rcv_data,
                                   uint32_t bytes_to_receive,
                                   VAR uint32_t *rcv_len);

UFR_STATUS DL_API open_ISO7816_interfaceM(UFR_HANDLE hndUFR,
                                          OUT uint8_t *atr_data,
                                          VAR uint8_t *atr_len);

UFR_STATUS DL_API APDU_switch_to_ISO7816_interfaceM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API close_ISO7816_interface_no_APDUM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API close_ISO7816_interface_APDU_ISO14443_4M(UFR_HANDLE hndUFR);

UFR_STATUS DL_API APDU_switch_to_ISO14443_4_interfaceM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API APDU_switch_off_from_ISO7816_interfaceM(UFR_HANDLE hndUFR);

//------------------------------------------------------------------------------
UFR_STATUS DL_API JCAppSelectByAidM(UFR_HANDLE hndUFR,
                                    IN const uint8_t *aid,
                                    uint8_t aid_len,
                                    OUT uint8_t selection_response[16]);

UFR_STATUS DL_API JCAppPutPrivateKeyM(UFR_HANDLE hndUFR,
                                      uint8_t key_type,
                                      uint8_t key_index,
                                      IN const uint8_t *key,
                                      uint16_t key_bit_len,
                                      const IN uint8_t *key_param,
                                      uint16_t key_parm_len);

UFR_STATUS DL_API JCAppGenerateKeyPairM(UFR_HANDLE hndUFR,
                                        uint8_t key_type,
                                        uint8_t key_index,
                                        uint8_t key_designator,
                                        uint16_t key_bit_len,
                                        IN const uint8_t *params,
                                        uint16_t params_size);

UFR_STATUS DL_API JCAppDeleteRsaKeyPairM(UFR_HANDLE hndUFR,
                                         uint8_t key_index);

UFR_STATUS DL_API JCAppDeleteEcKeyPairM(UFR_HANDLE hndUFR,
                                        uint8_t key_index);

UFR_STATUS DL_API JCAppSignatureBeginM(UFR_HANDLE hndUFR,
                                       uint8_t cipher,
                                       uint8_t digest,
                                       uint8_t padding,
                                       uint8_t key_index,
                                       IN const uint8_t *chunk,
                                       uint16_t chunk_len,
                                       IN const uint8_t *alg_param,
                                       uint16_t alg_parm_len);

UFR_STATUS DL_API JCAppSignatureUpdateM(UFR_HANDLE hndUFR,
                                        IN const uint8_t *chunk,
                                        uint16_t chunk_len);

UFR_STATUS DL_API JCAppSignatureEndM(UFR_HANDLE hndUFR,
                                     VAR uint16_t *sig_len);

UFR_STATUS DL_API JCAppGenerateSignatureM(UFR_HANDLE hndUFR,
                                          uint8_t cipher,
                                          uint8_t digest,
                                          uint8_t padding,
                                          uint8_t key_index,
                                          IN const uint8_t *plain_data,
                                          uint16_t plain_data_len,
                                          VAR uint16_t *sig_len,
                                          IN const uint8_t *alg_param,
                                          uint16_t alg_parm_len);

UFR_STATUS DL_API JCAppPutObjM(UFR_HANDLE hndUFR,
                               uint8_t obj_type,
                               uint8_t obj_index,
                               IN uint8_t *obj,
                               int16_t obj_size,
                               IN uint8_t *id,
                               uint8_t id_size);

UFR_STATUS DL_API JCAppPutObjSubjectM(UFR_HANDLE hndUFR,
                                      uint8_t obj_type,
                                      uint8_t obj_index,
                                      IN uint8_t *subject,
                                      uint8_t size);

UFR_STATUS DL_API JCAppInvalidateCertM(UFR_HANDLE hndUFR,
                                       uint8_t obj_type,
                                       uint8_t obj_index);

UFR_STATUS DL_API JCAppGetObjIdM(UFR_HANDLE hndUFR,
                                 uint8_t obj_type,
                                 uint8_t obj_index,
                                 OUT uint8_t *id,
                                 VAR uint16_t *id_size); // when id == NULL returns size

UFR_STATUS DL_API JCAppGetObjSubjectM(UFR_HANDLE hndUFR,
                                      uint8_t obj_type,
                                      uint8_t obj_index,
                                      OUT uint8_t *subject,
                                      VAR uint16_t *size); // when subject == NULL returns size

UFR_STATUS DL_API JCAppGetObjM(UFR_HANDLE hndUFR,
                               uint8_t obj_type,
                               uint8_t obj_index,
                               OUT uint8_t *obj,
                               int16_t size); // when obj == NULL returns size

UFR_STATUS DL_API JCAppLoginM(UFR_HANDLE hndUFR,
                              uint8_t SO,
                              IN uint8_t *pin,
                              uint8_t pinSize);

UFR_STATUS DL_API JCAppGetPinTriesRemainingM(UFR_HANDLE hndUFR,
                                             dl_sec_code_t secureCodeType,
                                             VAR uint16_t *triesRemaining);

UFR_STATUS DL_API JCAppPinChangeM(UFR_HANDLE hndUFR,
                                  dl_sec_code_t secureCodeType,
                                  IN uint8_t *newPin,
                                  uint8_t newPinSize);

UFR_STATUS DL_API JCAppPinUnblockM(UFR_HANDLE hndUFR,
                                   uint8_t SO,
                                   IN uint8_t *puk,
                                   uint8_t pukSize);

UFR_STATUS DL_API JCAppPinEnableM(UFR_HANDLE hndUFR, uint8_t SO);

UFR_STATUS DL_API JCAppPinDisableM(UFR_HANDLE hndUFR, uint8_t SO);

UFR_STATUS DL_API JCAppGetRsaPublicKeyM(UFR_HANDLE hndUFR,
                                        uint8_t key_index,
                                        OUT uint8_t *modulus,
                                        VAR uint16_t *modulus_size,
                                        OUT uint8_t *exponent,
                                        VAR uint16_t *exponent_size); // when modulus == NULL, returns sizes and exponent ignored

UFR_STATUS DL_API JCAppGetEcPublicKeyM(UFR_HANDLE hndUFR,
                                       uint8_t key_index,
                                       OUT uint8_t *keyW,
                                       VAR uint16_t *kexWSize,
                                       OUT uint8_t *field,
                                       VAR uint16_t *field_size,
                                       OUT uint8_t *ab,
                                       VAR uint16_t *ab_size,
                                       OUT uint8_t *g,
                                       VAR uint16_t *g_size,
                                       OUT uint8_t *r,
                                       VAR uint16_t *r_size,
                                       VAR uint16_t *k,
                                       VAR uint16_t *key_size_bits,
                                       VAR uint16_t *key_designator); // when keyW == NULL, returns size

UFR_STATUS DL_API JCAppGetEcKeySizeBitsM(UFR_HANDLE hndUFR,
                                         uint8_t key_index,
                                         VAR uint16_t *key_size_bits,
                                         VAR uint16_t *key_designator);
//------------------------------------------------------------------------------
UFR_STATUS DL_API JCStorageGetFilesListSizeM(UFR_HANDLE hndUFR, VAR uint32_t *list_size);
UFR_STATUS DL_API JCStorageListFilesM(UFR_HANDLE hndUFR, OUT uint8_t *list, uint32_t list_bytes_allocated);
UFR_STATUS DL_API JCStorageGetFileSizeM(UFR_HANDLE hndUFR, uint8_t card_file_index, VAR uint32_t *file_size);
UFR_STATUS DL_API JCStorageReadFileM(UFR_HANDLE hndUFR, uint8_t card_file_index, OUT uint8_t *data, uint32_t data_bytes_allocated);
UFR_STATUS DL_API JCStorageReadFileToFileSystemM(UFR_HANDLE hndUFR, uint8_t card_file_index, IN const char *file_system_path_name);
UFR_STATUS DL_API JCStorageWriteFileM(UFR_HANDLE hndUFR, uint8_t card_file_index, IN const uint8_t *data, uint32_t data_size);
UFR_STATUS DL_API JCStorageWriteFileFromFileSystemM(UFR_HANDLE hndUFR, uint8_t card_file_index, IN const char *file_system_path_name);
UFR_STATUS DL_API JCStorageDeleteFileM(UFR_HANDLE hndUFR, uint8_t file_index);
//#############################################################################

UFR_STATUS DL_API uFR_DESFIRE_Start(void);
UFR_STATUS DL_API uFR_DESFIRE_StartM(UFR_HANDLE hndUFR);
UFR_STATUS DL_API uFR_DESFIRE_Stop(void);
UFR_STATUS DL_API uFR_DESFIRE_StopM(UFR_HANDLE hndUFR);
UFR_STATUS DL_API uFR_APDU_Start(void);                 // Alias for uFR_DESFIRE_Start()
UFR_STATUS DL_API uFR_APDU_StartM(UFR_HANDLE hndUFR);   // Alias for uFR_DESFIRE_StartM()
UFR_STATUS DL_API uFR_APDU_Stop(void);                  // Alias for uFR_DESFIRE_Stop()
UFR_STATUS DL_API uFR_APDU_StopM(UFR_HANDLE hndUFR);    // Alias for uFR_DESFIRE_StopM()

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

UFR_STATUS DL_API uFR_int_GetDesfireUidM(UFR_HANDLE hndUFR,
                                         uint8_t aes_key_nr,
                                         uint32_t aid,
                                         uint8_t aid_key_nr,
                                         OUT uint8_t *card_uid,
                                         VAR uint8_t *card_uid_len,
                                         VAR uint16_t *card_status,
                                         VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_GetDesfireUid_PK_M(UFR_HANDLE hndUFR,
                                             IN uint8_t *aes_key_ext,
											 uint32_t aid,
		                                     uint8_t aid_key_nr,
											 OUT uint8_t *card_uid,
											 VAR uint8_t *card_uid_len,
		                                     VAR uint16_t *card_status,
											 VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireFreeMemM(UFR_HANDLE hndUFR,
                                          VAR uint32_t *free_mem_byte,
                                          VAR uint16_t *card_status,
                                          VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireFormatCardM(UFR_HANDLE hndUFR,
                                             uint8_t aes_key_nr,
                                             VAR uint16_t *card_status,
                                             VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireFormatCard_PK_M(UFR_HANDLE hndUFR,
                                                 IN uint8_t *aes_key_ext,
												 VAR uint16_t *card_status,
												 VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateStdDataFileM(UFR_HANDLE hndUFR,
                                                    uint8_t aes_key_nr,
                                                    uint32_t aid,
                                                    uint8_t file_id,
                                                    uint32_t file_size,
                                                    uint8_t read_key_no,
                                                    uint8_t write_key_no,
                                                    uint8_t read_write_key_no,
                                                    uint8_t change_key_no,
                                                    uint8_t communication_settings,
                                                    VAR uint16_t *card_status,
                                                    VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateStdDataFile_PK_M(UFR_HANDLE hndUFR,
                                                        IN uint8_t *aes_key_ext,
														uint32_t aid,
														uint8_t file_id,
														uint32_t file_size,
		                                                uint8_t read_key_no,
														uint8_t write_key_no,
														uint8_t read_write_key_no,
														uint8_t change_key_no,
		                                                uint8_t communication_settings,
														VAR uint16_t *card_status,
														VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateStdDataFile_no_auth_M(UFR_HANDLE hndUFR,
                                                             uint32_t aid,
															 uint8_t file_id,
															 uint32_t file_size,
		                                                     uint8_t read_key_no,
															 uint8_t write_key_no,
															 uint8_t read_write_key_no,
															 uint8_t change_key_no,
		                                                     uint8_t communication_settings,
															 VAR uint16_t *card_status,
															 VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDeleteFileM(UFR_HANDLE hndUFR,
                                             uint8_t aes_key_nr,
                                             uint32_t aid,
                                             uint8_t file_id,
                                             VAR uint16_t *card_status,
                                             VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDeleteFile_PK_M(UFR_HANDLE hndUFR,
                                                 IN uint8_t *aes_key_ext,
												 uint32_t aid,
												 uint8_t file_id,
		                                         VAR uint16_t *card_status,
												 VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDeleteFile_no_auth_M(UFR_HANDLE hndUFR,
                                                      uint32_t aid,
													  uint8_t file_id,
                                                	  VAR uint16_t *card_status,
													  VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateAesApplicationM(UFR_HANDLE hndUFR,
                                                       uint8_t aes_key_nr,
                                                       uint32_t aid,
                                                       uint8_t setting,
                                                       uint8_t max_key_no,
                                                       VAR uint16_t *card_status,
                                                       VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateAesApplication_PK_M(UFR_HANDLE hndUFR,
                                                           IN uint8_t *aes_key_ext,
 														   uint32_t aid,
		                                                   uint8_t setting,
														   uint8_t max_key_no,
														   VAR uint16_t *card_status,
														   VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateAesApplication_no_auth_M(UFR_HANDLE hndUFR,
                                                                uint32_t aid,
		                                                        uint8_t setting,
																uint8_t max_key_no,
																VAR uint16_t *card_status,
																VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDeleteApplicationM(UFR_HANDLE hndUFR,
                                                    uint8_t aes_key_nr,
                                                    uint32_t aid,
                                                    VAR uint16_t *card_status,
                                                    VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDeleteApplication_PK_M(UFR_HANDLE hndUFR,
                                                        IN uint8_t *aes_key_ext,
														uint32_t aid,
		                                                OUT uint16_t *card_status,
														OUT uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireSetConfigurationM(UFR_HANDLE hndUFR,
                                                   uint8_t aes_key_nr,
                                                   uint8_t random_uid,
                                                   uint8_t format_disable,
                                                   VAR uint16_t *card_status,
                                                   VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireSetConfiguration_PK_M(UFR_HANDLE hndUFR,
                                                       IN uint8_t *aes_key_ext,
													   uint8_t random_uid,
													   uint8_t format_disable,
		                                               VAR uint16_t *card_status,
													   VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireGetKeySettingsM(UFR_HANDLE hndUFR,
                                                 uint8_t aes_key_nr,
                                                 uint32_t aid,
                                                 VAR uint8_t *setting,
                                                 VAR uint8_t *max_key_no,
                                                 VAR uint16_t *card_status,
                                                 VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireGetKeySettings_PK_M(UFR_HANDLE hndUFR,
                                                     IN uint8_t *aes_key_ext,
													 uint32_t aid,
		                                             VAR uint8_t *setting,
													 VAR uint8_t *max_key_no,
		                                             VAR uint16_t *card_status,
													 VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireChangeKeySettingsM(UFR_HANDLE hndUFR,
                                                    uint8_t aes_key_nr,
                                                    uint32_t aid,
                                                    uint8_t setting,
                                                    VAR uint16_t *card_status,
                                                    VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireChangeKeySettings_PK_M(UFR_HANDLE hndUFR,
                                                        IN uint8_t *aes_key_ext,
														uint32_t aid,
		                                                uint8_t setting,
														VAR uint16_t *card_status,
														VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireChangeAesKeyM(UFR_HANDLE hndUFR,
                                               uint8_t aes_key_nr,
                                               uint32_t aid,
                                               uint8_t aid_key_no_auth,
                                               IN uint8_t new_aes_key[16],
                                               uint8_t aid_key_no,
                                               IN uint8_t old_aes_key[16],
                                               VAR uint16_t *card_status,
                                               VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireChangeAesKey_PK_M(UFR_HANDLE hndUFR,
                                                   IN uint8_t *aes_key_ext,
												   uint32_t aid,
												   uint8_t aid_key_no_auth,
		                                           IN uint8_t new_aes_key[16],
												   uint8_t aid_key_no,
												   IN uint8_t old_aes_key[16],
		                                           OUT uint16_t *card_status,
												   OUT uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireWriteAesKeyM(UFR_HANDLE hndUFR,
											uint8_t aes_key_no,
											uint8_t *aes_key);

//---------------------------------------------------------------------------

UFR_STATUS DL_API uFR_int_DesfireReadStddDataFileM(UFR_HANDLE hndUFR,
                                                  uint8_t aes_key_nr,
												  uint32_t aid,
												  uint8_t aid_key_nr,
												  uint8_t file_id,
		                                          uint16_t offset,
												  uint16_t data_length,
		                                          uint8_t communication_settings,
												  OUT uint8_t *data,
		                                          VAR uint16_t *card_status,
												  VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireReadStdDataFile_PK_M(UFR_HANDLE hndUFR,
                                                  IN uint8_t *aes_key_ext,
												  uint32_t aid,
												  uint8_t aid_key_nr,
												  uint8_t file_id,
		                                          uint16_t offset,
												  uint16_t data_length,
		                                          uint8_t communication_settings,
												  OUT uint8_t *data,
		                                          VAR uint16_t *card_status,
												  VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireReadStdDataFile_no_auth_M(UFR_HANDLE hndUFR,
												  uint32_t aid,
												  uint8_t aid_key_nr,
												  uint8_t file_id,
		                                          uint16_t offset,
												  uint16_t data_length,
		                                          uint8_t communication_settings,
												  OUT uint8_t *data,
		                                          VAR uint16_t *card_status,
												  VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireWriteStdDataFileM(UFR_HANDLE hndUFR,
                                                   uint8_t aes_key_nr,
                                                   uint32_t aid,
                                                   uint8_t aid_key_nr,
                                                   uint8_t file_id,
                                                   uint16_t offset,
                                                   uint16_t data_length,
                                                   uint8_t communication_settings,
                                                   IN uint8_t *data,
                                                   VAR uint16_t *card_status,
                                                   VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireWriteStdDataFile_PK_M(UFR_HANDLE hndUFR,
                                                   IN uint8_t *aes_key_ext,
                                                   uint32_t aid,
                                                   uint8_t aid_key_nr,
                                                   uint8_t file_id,
                                                   uint16_t offset,
                                                   uint16_t data_length,
                                                   uint8_t communication_settings,
                                                   IN uint8_t *data,
                                                   VAR uint16_t *card_status,
                                                   VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireWriteStdDataFile_no_auth_M(UFR_HANDLE hndUFR,
                                                   uint32_t aid,
                                                   uint8_t aid_key_nr,
                                                   uint8_t file_id,
                                                   uint16_t offset,
                                                   uint16_t data_length,
                                                   uint8_t communication_settings,
                                                   IN uint8_t *data,
                                                   VAR uint16_t *card_status,
                                                   VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateValueFileM(UFR_HANDLE hndUFR,
                                                  uint8_t aes_key_nr,
                                                  uint32_t aid,
                                                  uint8_t file_id,
                                                  int32_t lower_limit,
                                                  int32_t upper_limit,
                                                  int32_t value,
                                                  uint8_t limited_credit_enabled,
                                                  uint8_t read_key_no,
                                                  uint8_t write_key_no,
                                                  uint8_t read_write_key_no,
                                                  uint8_t change_key_no,
                                                  uint8_t communication_settings,
                                                  VAR uint16_t *card_status,
                                                  VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateValueFile_PK_M(UFR_HANDLE hndUFR,
                                                  IN uint8_t *aes_key_ext,
                                                  uint32_t aid,
                                                  uint8_t file_id,
                                                  int32_t lower_limit,
                                                  int32_t upper_limit,
                                                  int32_t value,
                                                  uint8_t limited_credit_enabled,
                                                  uint8_t read_key_no,
                                                  uint8_t write_key_no,
                                                  uint8_t read_write_key_no,
                                                  uint8_t change_key_no,
                                                  uint8_t communication_settings,
                                                  VAR uint16_t *card_status,
                                                  VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireCreateValueFile_no_auth_M(UFR_HANDLE hndUFR,
                                                  uint32_t aid,
                                                  uint8_t file_id,
                                                  int32_t lower_limit,
                                                  int32_t upper_limit,
                                                  int32_t value,
                                                  uint8_t limited_credit_enabled,
                                                  uint8_t read_key_no,
                                                  uint8_t write_key_no,
                                                  uint8_t read_write_key_no,
                                                  uint8_t change_key_no,
                                                  uint8_t communication_settings,
                                                  VAR uint16_t *card_status,
                                                  VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireReadValueFileM(UFR_HANDLE hndUFR,
                                                uint8_t aes_key_nr,
                                                uint32_t aid,
                                                uint8_t aid_key_nr,
                                                uint8_t file_id,
                                                uint8_t communication_settings,
                                                VAR int32_t *value,
                                                VAR uint16_t *card_status,
                                                VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireReadValueFile_PK_M(UFR_HANDLE hndUFR,
                                                IN uint8_t *aes_key_ext,
                                                uint32_t aid,
                                                uint8_t aid_key_nr,
                                                uint8_t file_id,
                                                uint8_t communication_settings,
                                                VAR int32_t *value,
                                                VAR uint16_t *card_status,
                                                VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireReadValueFile_no_auth_M(UFR_HANDLE hndUFR,
                                                uint32_t aid,
                                                uint8_t aid_key_nr,
                                                uint8_t file_id,
                                                uint8_t communication_settings,
                                                VAR int32_t *value,
                                                VAR uint16_t *card_status,
                                                VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireIncreaseValueFileM(UFR_HANDLE hndUFR,
                                                    uint8_t aes_key_nr,
                                                    uint32_t aid,
                                                    uint8_t aid_key_nr,
                                                    uint8_t file_id,
                                                    uint8_t communication_settings,
                                                    uint32_t value,
                                                    VAR uint16_t *card_status,
                                                    VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireIncreaseValueFile_PK_M(UFR_HANDLE hndUFR,
                                                    IN uint8_t *aes_key_ext,
                                                    uint32_t aid,
                                                    uint8_t aid_key_nr,
                                                    uint8_t file_id,
                                                    uint8_t communication_settings,
                                                    uint32_t value,
                                                    VAR uint16_t *card_status,
                                                    VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireIncreaseValueFile_no_auth_M(UFR_HANDLE hndUFR,
                                                    uint32_t aid,
                                                    uint8_t aid_key_nr,
                                                    uint8_t file_id,
                                                    uint8_t communication_settings,
                                                    uint32_t value,
                                                    VAR uint16_t *card_status,
                                                    VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDecreaseValueFileM(UFR_HANDLE hndUFR,
                                                    uint8_t aes_key_nr,
                                                    uint32_t aid,
                                                    uint8_t aid_key_nr,
                                                    uint8_t file_id,
                                                    uint8_t communication_settings,
                                                    uint32_t value,
                                                    VAR uint16_t *card_status,
                                                    VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDecreaseValueFile_PK_M(UFR_HANDLE hndUFR,
                                                    IN uint8_t *aes_key_ext,
                                                    uint32_t aid,
                                                    uint8_t aid_key_nr,
                                                    uint8_t file_id,
                                                    uint8_t communication_settings,
                                                    uint32_t value,
                                                    VAR uint16_t *card_status,
                                                    VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireDecreaseValueFile_no_auth_M(UFR_HANDLE hndUFR,
                                                    uint32_t aid,
                                                    uint8_t aid_key_nr,
                                                    uint8_t file_id,
                                                    uint8_t communication_settings,
                                                    uint32_t value,
                                                    VAR uint16_t *card_status,
                                                    VAR uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireGetApplicationIdsM(UFR_HANDLE hndUFR,
													uint8_t aes_key_nr,
													uint32_t *application_ids,
													uint8_t *number_of_aplication_ids,
													uint16_t *card_status,
													uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireGetApplicationIds_PK_M(UFR_HANDLE hndUFR,
													uint8_t *aes_key_ext,
													uint32_t *application_ids,
													uint8_t *number_of_aplication_ids,
													uint16_t *card_status,
													uint16_t *exec_time);

UFR_STATUS DL_API uFR_int_DesfireGetApplicationIds_no_auth_M(UFR_HANDLE hndUFR,
													uint32_t *application_ids,
													uint8_t *number_of_aplication_ids,
													uint16_t *card_status,
													uint16_t *exec_time);

UFR_STATUS DL_API GreenLedBlinkingTurnOnM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API GreenLedBlinkingTurnOffM(UFR_HANDLE hndUFR);

/////////////////////////////////////////////////////////////////////

UFR_STATUS DL_API SetRfAnalogRegistersTypeAM(UFR_HANDLE hndUFR,
                                             uint8_t ThresholdMinLevel,
                                             uint8_t ThresholdCollLevel,
                                             uint8_t RFLevelAmp,
                                             uint8_t RxGain,
                                             uint8_t RFLevel);

UFR_STATUS DL_API SetRfAnalogRegistersTypeBM(UFR_HANDLE hndUFR,
                                             uint8_t ThresholdMinLevel,
                                             uint8_t ThresholdCollLevel,
                                             uint8_t RFLevelAmp,
                                             uint8_t RxGain,
                                             uint8_t RFLevel);

UFR_STATUS DL_API SetRfAnalogRegistersISO14443_212M(UFR_HANDLE hndUFR,
                                                    uint8_t ThresholdMinLevel,
                                                    uint8_t ThresholdCollLevel,
                                                    uint8_t RFLevelAmp,
                                                    uint8_t RxGain,
                                                    uint8_t RFLevel);

UFR_STATUS DL_API SetRfAnalogRegistersISO14443_424M(UFR_HANDLE hndUFR,
                                                    uint8_t ThresholdMinLevel,
                                                    uint8_t ThresholdCollLevel,
                                                    uint8_t RFLevelAmp,
                                                    uint8_t RxGain,
                                                    uint8_t RFLevel);

UFR_STATUS DL_API SetRfAnalogRegistersTypeADefaultM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API SetRfAnalogRegistersTypeBDefaultM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API SetRfAnalogRegistersISO14443_212DefaultM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API SetRfAnalogRegistersISO14443_424DefaultM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API GetRfAnalogRegistersTypeAM(UFR_HANDLE hndUFR,
                                             VAR uint8_t *ThresholdMinLevel,
                                             VAR uint8_t *ThresholdCollLevel,
                                             VAR uint8_t *RFLevelAmp,
                                             VAR uint8_t *RxGain,
                                             VAR uint8_t *RFLevel);

UFR_STATUS DL_API GetRfAnalogRegistersTypeBM(UFR_HANDLE hndUFR,
                                             VAR uint8_t *ThresholdMinLevel,
                                             VAR uint8_t *ThresholdCollLevel,
                                             VAR uint8_t *RFLevelAmp,
                                             VAR uint8_t *RxGain,
                                             VAR uint8_t *RFLevel);

UFR_STATUS DL_API GetRfAnalogRegistersISO14443_212M(UFR_HANDLE hndUFR,
                                                    VAR uint8_t *ThresholdMinLevel,
                                                    VAR uint8_t *ThresholdCollLevel,
                                                    VAR uint8_t *RFLevelAmp,
                                                    VAR uint8_t *RxGain,
                                                    VAR uint8_t *RFLevel);

UFR_STATUS DL_API GetRfAnalogRegistersISO14443_424M(UFR_HANDLE hndUFR,
                                                    VAR uint8_t *ThresholdMinLevel,
                                                    VAR uint8_t *ThresholdCollLevel,
                                                    VAR uint8_t *RFLevelAmp,
                                                    VAR uint8_t *RxGain,
                                                    VAR uint8_t *RFLevel);

UFR_STATUS DL_API SetRfAnalogRegistersTypeATransM(UFR_HANDLE hndUFR,
                                                  uint8_t ThresholdMinLevel,
                                                  uint8_t ThresholdCollLevel,
                                                  uint8_t RFLevelAmp,
                                                  uint8_t RxGain,
                                                  uint8_t RFLevel,
                                                  uint8_t CWGsNOn,
                                                  uint8_t ModGsNOn,
                                                  uint8_t CWGsP,
                                                  uint8_t CWGsNOff,
                                                  uint8_t ModGsNOff);

UFR_STATUS DL_API SetRfAnalogRegistersTypeBTransM(UFR_HANDLE hndUFR,
                                                  uint8_t ThresholdMinLevel,
                                                  uint8_t ThresholdCollLevel,
                                                  uint8_t RFLevelAmp,
                                                  uint8_t RxGain,
                                                  uint8_t RFLevel,
                                                  uint8_t CWGsNOn,
                                                  uint8_t ModGsNOn,
                                                  uint8_t CWGsP,
                                                  uint8_t ModGsP);

UFR_STATUS DL_API GetRfAnalogRegistersTypeATransM(UFR_HANDLE hndUFR,
                                                  VAR uint8_t *ThresholdMinLevel,
                                                  VAR uint8_t *ThresholdCollLevel,
                                                  VAR uint8_t *RFLevelAmp,
                                                  VAR uint8_t *RxGain,
                                                  VAR uint8_t *RFLevel,
                                                  VAR uint8_t *CWGsNOn,
                                                  VAR uint8_t *ModGsNOn,
                                                  VAR uint8_t *CWGsP,
                                                  VAR uint8_t *CWGsNOff,
                                                  VAR uint8_t *ModGsNOff);

UFR_STATUS DL_API GetRfAnalogRegistersTypeBTransM(UFR_HANDLE hndUFR,
                                                  VAR uint8_t *ThresholdMinLevel,
                                                  VAR uint8_t *ThresholdCollLevel,
                                                  VAR uint8_t *RFLevelAmp,
                                                  VAR uint8_t *RxGain,
                                                  VAR uint8_t *RFLevel,
                                                  VAR uint8_t *CWGsNOn,
                                                  VAR uint8_t *ModGsNOn,
                                                  VAR uint8_t *CWGsP,
                                                  VAR uint8_t *ModGsP);

//MIFARE PLUS
UFR_STATUS DL_API MFP_WritePersoM(UFR_HANDLE hndUFR,
                                  uint16_t address,
                                  IN uint8_t *data);

UFR_STATUS DL_API MFP_CommitPersoM(UFR_HANDLE hndUFR);

UFR_STATUS DL_API MFP_PersonalizationMinimalM(UFR_HANDLE hndUFR,
                                              IN uint8_t *card_master_key,
                                              IN uint8_t *card_config_key,
                                              IN uint8_t *level_2_switch_key,
                                              IN uint8_t *level_3_switch_key,
                                              IN uint8_t *level_1_auth_key,
                                              IN uint8_t *select_vc_key,
                                              IN uint8_t *prox_chk_key,
                                              IN uint8_t *vc_poll_enc_key,
                                              IN uint8_t *vc_poll_mac_key);

UFR_STATUS DL_API MFP_SwitchToSecurityLevel3M(UFR_HANDLE hndUFR,
                                              uint8_t key_index);

UFR_STATUS DL_API MFP_SwitchToSecurityLevel3_PKM(UFR_HANDLE hndUFR,
                                                 IN uint8_t *aes_key);

UFR_STATUS DL_API MFP_AesAuthSecurityLevel1M(UFR_HANDLE hndUFR,
                                             uint8_t key_index);

UFR_STATUS DL_API MFP_AesAuthSecurityLevel1_PKM(UFR_HANDLE hndUFR,
                                                IN uint8_t *aes_key);

UFR_STATUS DL_API MFP_ChangeMasterKeyM(UFR_HANDLE hndUFR,
                                       uint8_t key_index,
                                       IN uint8_t *new_key);

UFR_STATUS DL_API MFP_ChangeMasterKey_PKM(UFR_HANDLE hndUFR,
                                          IN uint8_t *old_key,
                                          IN uint8_t *new_key);

UFR_STATUS DL_API MFP_ChangeConfigurationKeyM(UFR_HANDLE hndUFR,
                                              uint8_t key_index,
                                              IN uint8_t *new_key);

UFR_STATUS DL_API MFP_ChangeConfigurationKey_PKM(UFR_HANDLE hndUFR,
                                                 IN uint8_t *old_key,
                                                 IN uint8_t *new_key);

UFR_STATUS DL_API MFP_FieldConfigurationSetM(UFR_HANDLE hndUFR,
                                             uint8_t configuration_key_index,
                                             uint8_t rid_use,
                                             uint8_t prox_check_use);

UFR_STATUS DL_API MFP_FieldConfigurationSet_PKM(UFR_HANDLE hndUFR,
                                                IN uint8_t *configuration_key,
                                                uint8_t rid_use,
                                                uint8_t prox_check_use);

UFR_STATUS DL_API MFP_ChangeSectorKeyM(UFR_HANDLE hndUFR,
                                       uint8_t sector_nr,
                                       uint8_t auth_mode,
                                       uint8_t key_index,
                                       IN uint8_t *new_key);

UFR_STATUS DL_API MFP_ChangeSectorKey_PKM(UFR_HANDLE hndUFR,
                                          uint8_t sector_nr,
                                          uint8_t auth_mode,
                                          IN uint8_t *old_key,
                                          IN uint8_t *new_key);

UFR_STATUS DL_API MFP_GetUidM(UFR_HANDLE hndUFR,
                              uint8_t key_index_vc_poll_enc_key,
                              uint8_t key_index_vc_poll_mac_key,
                              OUT uint8_t *uid,
                              VAR uint8_t *uid_len);

UFR_STATUS DL_API MFP_GetUid_PKM(UFR_HANDLE hndUFR,
                                 IN uint8_t *vc_poll_enc_key,
                                 IN uint8_t *vc_poll_mac_key,
                                 OUT uint8_t *uid,
                                 VAR uint8_t *uid_len);

UFR_STATUS DL_API MFP_ChangeVcPollingEncKeyM(UFR_HANDLE hndUFR,
                                             uint8_t configuration_key_index,
                                             IN uint8_t *new_key);

UFR_STATUS DL_API MFP_ChangeVcPollingEncKey_PKM(UFR_HANDLE hndUFR,
                                                IN uint8_t *configuration_key,
                                                IN uint8_t *new_key);

UFR_STATUS DL_API MFP_ChangeVcPollingMacKeyM(UFR_HANDLE hndUFR,
                                             uint8_t configuration_key_index,
                                             IN uint8_t *new_key);

UFR_STATUS DL_API MFP_ChangeVcPollingMacKey_PKM(UFR_HANDLE hndUFR,
                                                IN uint8_t *configuration_key,
                                                IN uint8_t *new_key);

//ULTRALIGHT C
UFR_STATUS DL_API ULC_ExternalAuth_PKM(UFR_HANDLE hndUFR,
                                       IN uint8_t *key);

UFR_STATUS DL_API ULC_write_3des_key_no_authM(UFR_HANDLE hndUFR,
                                              IN uint8_t *new_3des_key);

UFR_STATUS DL_API ULC_write_3des_key_factory_keyM(UFR_HANDLE hndUFR,
                                                  IN uint8_t *new_3des_key);

UFR_STATUS DL_API ULC_write_3des_keyM(UFR_HANDLE hndUFR,
                                      IN uint8_t *new_3des_key,
                                      IN uint8_t *old_3des_key);


//ESP32
UFR_STATUS DL_API EspSetDisplayData(IN uint8_t *display_data, IN uint8_t data_length, uint16_t duration);
UFR_STATUS DL_API EspReaderReset(void);
UFR_STATUS DL_API EspChangeReaderPassword(uint8_t *old_password, uint8_t *new_password);
UFR_STATUS DL_API EspReaderEepromWrite(uint8_t *data, uint32_t address, uint32_t size, uint8_t *password);
UFR_STATUS DL_API EspReaderEepromRead(uint8_t *data, uint32_t address, uint32_t size);
UFR_STATUS DL_API EspGetReaderTime(uint8_t *time);
UFR_STATUS DL_API EspSetReaderTime(uint8_t *password, uint8_t *time);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// DLL version ----------------------------------------------------------------
uint32_t DL_API GetDllVersion(void);

/*
 * Get "exploded" dll version example:
 *
 *  #include <windows.h>
 *  #include <uFCoder.h>
 *
 *  void main(int argc, char *argv[])
 *  {
 *       uint32_t dwDllVersion = 0;
 *       uint32_t dwDllMajorVersion = 0;
 *       uint32_t dwDllMinorVersion = 0;
 *       uint32_t dwDllBuild = 0;
 *
 *       dwDllVersion = GetDllVersion();
 *
 *       // "explode" the dll version:
 *       dwDllMajorVersion = (DWORD)(LOBYTE(LOWORD(dwDllVersion)));
 *       dwDllMinorVersion = (DWORD)(HIBYTE(LOWORD(dwDllVersion)));
 *
 *       // Get the dll build number.
 *       dwDllBuild = (DWORD)(HIWORD(dwDllVersion));
 *
 *       printf("Dll version is %ld.%ld (%ld)\n", dwDllMajorVersion,
 *                                             dwDllMinorVersion,
 *                                             dwDllBuild);
 *  }
 *
 */

// Originality Check (performs the check is the chip on the card/tag NXP genuine):
UFR_STATUS DL_API OriginalityCheck(IN const uint8_t *signature, IN const uint8_t *uid, uint8_t uid_len, uint8_t DlogicCardType);
// Returns:
// UFR_OPEN_SSL_DYNAMIC_LIB_NOT_FOUND in case there is no OpenSSL library (libeay32.dll) in current folder or path
// UFR_OPEN_SSL_DYNAMIC_LIB_FAILED    in case of OpenSSL library error (e.g. wrong OpenSSL version)
// UFR_NOT_NXP_GENUINE                if chip on the card/tag is NOT NXP genuine
// UFR_OK                             is chip on the card/tag is NXP GENUINE

//// debug functions:
c_string DL_API GetDllVersionStr(void);
c_string DL_API UFR_Status2String(const UFR_STATUS status);
c_string DL_API UFR_DLCardType2String(uint8_t dl_type_code);

//// Helper functions:
#ifndef _WIN32

unsigned long GetTickCount(void);

#endif // #ifndef _WIN32

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

c_string DL_API GetReaderDescription(void);
c_string DL_API GetReaderDescriptionM(UFR_HANDLE hndUFR);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#ifdef __cplusplus
}
#endif

#endif /* uFCoder_H_ */
