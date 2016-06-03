/*
 * uFCoder.h
 *
 * library version: 3.9.14
 *
 * Created on:  2009-01-14
 * Last edited: 2016-05-24
 *
 * Author: D-Logic
 */

#ifndef uFCoder_H_
#define uFCoder_H_

#include <stdint.h>
#include <stddef.h>

////////////////////////////////////////////////////////////////////
/**
 * Type for representing null terminated char array ( aka C-String )
 * Array is always one byte longer ( for null character ) then string
 * Memory space for array must be allocated before use.
 */
typedef const char * c_string;
typedef const char * chr_ptr; // deprecated
////////////////////////////////////////////////////////////////////

#ifdef _WIN32
// WINDOWS
#	ifdef DL_uFC_STATIC_LIB
#		define DL_API __stdcall
#	else
#		ifndef DL_uFC_EXPORTS
#			define DL_API /* __declspec(dllimport) */ __stdcall
#		else
#			define DL_API __declspec(dllexport) __stdcall
#		endif
#	endif
#else
// Linux & OS X
#	define DL_API
#endif // _WIN32

#if defined(DL_uFC_EXPORTS) || defined(DL_uFC_STATIC_LIB)
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

#define DL_MIFARE_MINI					0x20
#define	DL_MIFARE_CLASSIC_1K			0x21
#define DL_MIFARE_CLASSIC_4K			0x22
#define DL_MIFARE_PLUS_S_2K				0x23
#define DL_MIFARE_PLUS_S_4K				0x24
#define DL_MIFARE_PLUS_X_2K				0x25
#define DL_MIFARE_PLUS_X_4K				0x26
#define DL_MIFARE_DESFIRE				0x27
#define DL_MIFARE_DESFIRE_EV1_2K		0x28
#define DL_MIFARE_DESFIRE_EV1_4K		0x29
#define DL_MIFARE_DESFIRE_EV1_8K		0x2A
#define DL_MIFARE_DESFIRE_EV2_2K		0x2B
#define DL_MIFARE_DESFIRE_EV2_4K		0x2C
#define DL_MIFARE_DESFIRE_EV2_8K		0x2D

#define DL_IMEI_UID						0x80

// MIFARE CLASSIC Authentication Modes:
enum MIFARE_AUTHENTICATION
{
	MIFARE_AUTHENT1A = 0x60,
	MIFARE_AUTHENT1B = 0x61,
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
	UFR_UNSUPPORTED_CARD_TYPE,

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
	UFR_TAG_UNKNOWN = 0x7D,

	UFR_COMMUNICATION_BREAK = 0x50,
	UFR_NO_MEMORY_ERROR = 0x51,
	UFR_CAN_NOT_OPEN_READER = 0x52,
	UFR_READER_NOT_SUPPORTED = 0x53,
	UFR_READER_OPENING_ERROR = 0x54,
	UFR_READER_PORT_NOT_OPENED = 0x55,
	UFR_CANT_CLOSE_READER_PORT = 0x56,

	UFR_TIMEOUT_ERR = 0x90,

	UFR_FT_STATUS_ERROR_1 = 0xA0,
	UFR_FT_STATUS_ERROR_2 = 0xA1,
	UFR_FT_STATUS_ERROR_3 = 0xA2,
	UFR_FT_STATUS_ERROR_4 = 0xA3,
	UFR_FT_STATUS_ERROR_5 = 0xA4,
	UFR_FT_STATUS_ERROR_6 = 0xA5,
	UFR_FT_STATUS_ERROR_7 = 0xA6,
	UFR_FT_STATUS_ERROR_8 = 0xA7,
	UFR_FT_STATUS_ERROR_9 = 0xA8,

	//NDEF error codes
	UFR_WRONG_NDEF_CARD_FORMAT = 0x80,
	UFR_NDEF_MESSAGE_NOT_FOUND = 0x81,
	UFR_NDEF_UNSUPPORTED_CARD_TYPE 	= 0x82,
	UFR_NDEF_CARD_FORMAT_ERROR	= 0x83,
	UFR_MAD_NOT_ENABLED	= 0x84,
	UFR_MAD_VERSION_NOT_SUPPORTED = 0x85,

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

	MAX_UFR_STATUS = 0xFFFFFFFF
} UFR_STATUS;

//DESFIRE Card Status Error Codes
#define READER_ERROR			2999
#define NO_CARD_DETECTED		3000
#define CARD_OPERATION_OK		3001
#define WRONG_KEY_TYPE			3002
#define KEY_AUTH_ERROR			3003
#define CARD_CRYPTO_ERROR		3004
#define READER_CARD_COMM_ERROR	3005
#define PC_READER_COMM_ERROR	3006

#define	DESFIRE_CARD_NO_CHANGES					0x0C0C
#define	DESFIRE_CARD_OUT_OF_EEPROM_ERROR		0x0C0E
#define	DESFIRE_CARD_ILLEGAL_COMMAND_CODE		0x0C1C
#define	DESFIRE_CARD_INTEGRITY_ERROR			0x0C1E
#define	DESFIRE_CARD_NO_SUCH_KEY				0x0C40
#define	DESFIRE_CARD_LENGTH_ERROR				0x0C7E
#define	DESFIRE_CARD_PERMISSION_DENIED			0x0C9D
#define	DESFIRE_CARD_PARAMETER_ERROR			0x0C9E
#define	DESFIRE_CARD_APPLICATION_NOT_FOUND		0x0CA0
#define	DESFIRE_CARD_APPL_INTEGRITY_ERROR		0x0CA1
#define	DESFIRE_CARD_AUTHENTICATION_ERROR		0x0CAE
#define	DESFIRE_CARD_ADDITIONAL_FRAME			0x0CAF
#define	DESFIRE_CARD_BOUNDARY_ERROR				0x0CBE
#define	DESFIRE_CARD_PICC_INTEGRITY_ERROR		0x0CC1
#define	DESFIRE_CARD_COMMAND_ABORTED			0x0CCA
#define	DESFIRE_CARD_PICC_DISABLED_ERROR		0x0CCD
#define	DESFIRE_CARD_COUNT_ERROR				0x0CCE
#define	DESFIRE_CARD_DUPLICATE_ERROR			0x0CDE
#define	DESFIRE_CARD_EEPROM_ERROR_DES			0x0CEE
#define	DESFIRE_CARD_FILE_NOT_FOUND				0x0CF0
#define	DESFIRE_CARD_FILE_INTEGRITY_ERROR		0x0CF1

//DESFIRE key settings values
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_CHANGE				0x09
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_CHANGE			0x0F
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_CHANGE			0x01
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_CHANGE		0x07
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_CHANGE_KEY_NOT_CHANGE			0x08
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_CHANGE_KEY_NOT_CHANGE		0x0E
#define DESFIRE_KEY_SET_CREATE_WITH_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE		0x00
#define DESFIRE_KEY_SET_CREATE_WITHOUT_AUTH_SET_NOT_CHANGE_KEY_NOT_CHANGE	0x06


#ifdef __cplusplus
extern "C"
{
#endif

//--------------------------------------------------------------------------------------------------

DL_API UFR_STATUS ReaderOpen(void);

/**
 * Useful for speed up opening for non uFR basic reader type
 *
 * @param reader_type : 0 : auto > same as call ReaderOpen()
 *                      1 : uFR type (1 Mbps)
 *                      2 : uFR RS232 type (115200 bps)
 *                      3 : XRC type (250 Kbps)
 * @return
 */
DL_API UFR_STATUS ReaderOpenByType(uint32_t reader_type);

DL_API UFR_STATUS ReaderReset(void);
DL_API UFR_STATUS ReaderClose(void);
DL_API UFR_STATUS ReaderSoftRestart(void);
DL_API UFR_STATUS GetReaderType(uint32_t *lpulReaderType);
DL_API UFR_STATUS GetReaderSerialNumber(uint32_t *lpulSerialNumber);

DL_API UFR_STATUS ReaderStillConnected(uint32_t *connected);

DL_API UFR_STATUS ReaderKeyWrite(const uint8_t *aucKey, uint8_t ucKeyIndex);
DL_API UFR_STATUS ReaderKeysLock(const uint8_t *password);
DL_API UFR_STATUS ReaderKeysUnlock(const uint8_t *password);
DL_API UFR_STATUS ReaderUISignal(uint8_t light_signal_mode,
                                     uint8_t beep_signal_mode);
DL_API UFR_STATUS ReadUserData(uint8_t *aucData);
DL_API UFR_STATUS WriteUserData(const uint8_t *aucData);
DL_API UFR_STATUS GetCardId(uint8_t *lpucCardType, uint32_t *lpulCardSerial);
DL_API UFR_STATUS BlockRead(uint8_t *data,
                                uint8_t block_address,
                                uint8_t auth_mode,
                                uint8_t key_index);
DL_API UFR_STATUS BlockWrite(const uint8_t *data,
                                 uint8_t block_address,
                                 uint8_t auth_mode,
                                 uint8_t key_index);
DL_API UFR_STATUS BlockInSectorRead(uint8_t *data,
                                        uint8_t sector_address,
                                        uint8_t block_in_sector_address,
                                        uint8_t auth_mode,
                                        uint8_t key_index);
DL_API UFR_STATUS BlockInSectorWrite(const uint8_t *data,
                                         uint8_t sector_address,
                                         uint8_t block_in_sector_address,
                                         uint8_t auth_mode,
                                         uint8_t key_index);
DL_API UFR_STATUS LinearRead(uint8_t *aucData,
                                 uint16_t usLinearAddress,
                                 uint16_t usDataLength,
                                 uint16_t *lpusBytesReturned,
                                 uint8_t ucKeyMode,
                                 uint8_t ucReaderKeyIndex);
DL_API UFR_STATUS LinRowRead(uint8_t *aucData,
                                 uint16_t usLinearAddress,
                                 uint16_t usDataLength,
                                 uint16_t *lpusBytesReturned,
                                 uint8_t ucKeyMode,
                                 uint8_t ucReaderKeyIndex);
DL_API UFR_STATUS LinearWrite(const uint8_t *aucData,
                                  uint16_t usLinearAddress,
                                  uint16_t usDataLength,
                                  uint16_t *lpusBytesWritten,
                                  uint8_t ucKeyMode,
                                  uint8_t ucReaderKeyIndex);
DL_API UFR_STATUS LinearFormatCard(const uint8_t *new_key_A,
                                       uint8_t blocks_access_bits,
                                       uint8_t sector_trailers_access_bits,
                                       uint8_t sector_trailers_byte9,
                                       const uint8_t *new_key_B,
                                       uint8_t *lpucSectorsFormatted,
                                       uint8_t auth_mode,
                                       uint8_t key_index);
DL_API UFR_STATUS SectorTrailerWrite(uint8_t addressing_mode,
                                         uint8_t address,
                                         const uint8_t *new_key_A,
                                         uint8_t block0_access_bits,
                                         uint8_t block1_access_bits,
                                         uint8_t block2_access_bits,
                                         uint8_t sector_trailer_access_bits,
                                         uint8_t sector_trailer_byte9,
                                         const uint8_t *new_key_B,
                                         uint8_t auth_mode,
                                         uint8_t key_index);
DL_API UFR_STATUS SectorTrailerWriteUnsafe(uint8_t addressing_mode,
                                               uint8_t address,
                                               const uint8_t *sector_trailer,
                                               uint8_t auth_mode,
                                               uint8_t key_index);
DL_API UFR_STATUS ValueBlockRead(int32_t *value,
                                     uint8_t *value_addr,
                                     uint8_t block_address,
                                     uint8_t auth_mode,
                                     uint8_t key_index);
DL_API UFR_STATUS ValueBlockInSectorRead(int32_t *value,
                                             uint8_t *value_addr,
                                             uint8_t sector_address,
                                             uint8_t block_in_sector_address,
                                             uint8_t auth_mode,
                                             uint8_t key_index);
DL_API UFR_STATUS ValueBlockWrite(int32_t value,
                                      uint8_t value_addr,
                                      uint8_t block_address,
                                      uint8_t auth_mode,
                                      uint8_t key_index);
DL_API UFR_STATUS ValueBlockInSectorWrite(int32_t value,
                                              uint8_t value_addr,
                                              uint8_t sector_address,
                                              uint8_t block_in_sector_address,
                                              uint8_t auth_mode,
                                              uint8_t key_index);
DL_API UFR_STATUS ValueBlockIncrement(int32_t increment_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode,
                                          uint8_t key_index);
DL_API UFR_STATUS ValueBlockInSectorIncrement(int32_t increment_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode,
                                                  uint8_t key_index);
DL_API UFR_STATUS ValueBlockDecrement(int32_t decrement_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode,
                                          uint8_t key_index);
DL_API UFR_STATUS ValueBlockInSectorDecrement(int32_t decrement_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode,
                                                  uint8_t key_index);

DL_API UFR_STATUS BlockRead_AKM1(uint8_t *data,
                                    uint8_t block_address,
                                    uint8_t auth_mode);
DL_API UFR_STATUS BlockWrite_AKM1(const uint8_t *data,
                                 uint8_t block_address,
                                 uint8_t auth_mode);
DL_API UFR_STATUS BlockInSectorRead_AKM1(uint8_t *data,
                                        uint8_t sector_address,
                                        uint8_t block_in_sector_address,
                                        uint8_t auth_mode);
DL_API UFR_STATUS BlockInSectorWrite_AKM1(const uint8_t *data,
                                         uint8_t sector_address,
                                         uint8_t block_in_sector_address,
                                         uint8_t auth_mode);
DL_API UFR_STATUS LinearRead_AKM1(uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 uint16_t *bytes_returned,
                                 uint8_t auth_mode);
DL_API UFR_STATUS LinRowRead_AKM1(uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 uint16_t *bytes_returned,
                                 uint8_t auth_mode);
DL_API UFR_STATUS LinearWrite_AKM1(const uint8_t *data,
                                  uint16_t linear_address,
                                  uint16_t length,
                                  uint16_t *bytes_written,
                                  uint8_t auth_mode);
DL_API UFR_STATUS LinearFormatCard_AKM1(const uint8_t *new_key_A,
                                       uint8_t blocks_access_bits,
                                       uint8_t sector_trailers_access_bits,
                                       uint8_t sector_trailers_byte9,
                                       const uint8_t *new_key_B,
                                       uint8_t *lpucSectorsFormatted,
                                       uint8_t auth_mode);
DL_API UFR_STATUS SectorTrailerWrite_AKM1(uint8_t addressing_mode,
                                         uint8_t address,
                                         const uint8_t *new_key_A,
                                         uint8_t block0_access_bits,
                                         uint8_t block1_access_bits,
                                         uint8_t block2_access_bits,
                                         uint8_t sector_trailer_access_bits,
                                         uint8_t sector_trailer_byte9,
                                         const uint8_t *new_key_B,
                                         uint8_t auth_mode);
DL_API UFR_STATUS SectorTrailerWriteUnsafe_AKM1(uint8_t addressing_mode,
                                               uint8_t address,
                                               const uint8_t *sector_trailer,
                                               uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockRead_AKM1(int32_t *value,
                                     uint8_t *value_addr,
                                     uint8_t block_address,
                                     uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorRead_AKM1(int32_t *value,
                                             uint8_t *value_addr,
                                             uint8_t sector_address,
                                             uint8_t block_in_sector_address,
                                             uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockWrite_AKM1(int32_t value,
                                      uint8_t value_addr,
                                      uint8_t block_address,
                                      uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorWrite_AKM1(int32_t value,
                                              uint8_t value_addr,
                                              uint8_t sector_address,
                                              uint8_t block_in_sector_address,
                                              uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockIncrement_AKM1(int32_t increment_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorIncrement_AKM1(int32_t increment_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockDecrement_AKM1(int32_t decrement_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorDecrement_AKM1(int32_t decrement_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);

DL_API UFR_STATUS BlockRead_AKM2(uint8_t *data,
                                    uint8_t block_address,
                                    uint8_t auth_mode);
DL_API UFR_STATUS BlockWrite_AKM2(const uint8_t *data,
                                 uint8_t block_address,
                                 uint8_t auth_mode);
DL_API UFR_STATUS BlockInSectorRead_AKM2(uint8_t *data,
                                        uint8_t sector_address,
                                        uint8_t block_in_sector_address,
                                        uint8_t auth_mode);
DL_API UFR_STATUS BlockInSectorWrite_AKM2(const uint8_t *data,
                                         uint8_t sector_address,
                                         uint8_t block_in_sector_address,
                                         uint8_t auth_mode);
DL_API UFR_STATUS LinearRead_AKM2(uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 uint16_t *bytes_returned,
                                 uint8_t auth_mode);
DL_API UFR_STATUS LinRowRead_AKM2(uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 uint16_t *bytes_returned,
                                 uint8_t auth_mode);
DL_API UFR_STATUS LinearWrite_AKM2(const uint8_t *data,
                                  uint16_t linear_address,
                                  uint16_t length,
                                  uint16_t *bytes_written,
                                  uint8_t auth_mode);
DL_API UFR_STATUS LinearFormatCard_AKM2(const uint8_t *new_key_A,
                                       uint8_t blocks_access_bits,
                                       uint8_t sector_trailers_access_bits,
                                       uint8_t sector_trailers_byte9,
                                       const uint8_t *new_key_B,
                                       uint8_t *lpucSectorsFormatted,
                                       uint8_t auth_mode);
DL_API UFR_STATUS SectorTrailerWrite_AKM2(uint8_t addressing_mode,
                                         uint8_t address,
                                         const uint8_t *new_key_A,
                                         uint8_t block0_access_bits,
                                         uint8_t block1_access_bits,
                                         uint8_t block2_access_bits,
                                         uint8_t sector_trailer_access_bits,
                                         uint8_t sector_trailer_byte9,
                                         const uint8_t *new_key_B,
                                         uint8_t auth_mode);
DL_API UFR_STATUS SectorTrailerWriteUnsafe_AKM2(uint8_t addressing_mode,
                                               uint8_t address,
                                               const uint8_t *sector_trailer,
                                               uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockRead_AKM2(int32_t *value,
                                     uint8_t *value_addr,
                                     uint8_t block_address,
                                     uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorRead_AKM2(int32_t *value,
                                             uint8_t *value_addr,
                                             uint8_t sector_address,
                                             uint8_t block_in_sector_address,
                                             uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockWrite_AKM2(int32_t value,
                                      uint8_t value_addr,
                                      uint8_t block_address,
                                      uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorWrite_AKM2(int32_t value,
                                              uint8_t value_addr,
                                              uint8_t sector_address,
                                              uint8_t block_in_sector_address,
                                              uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockIncrement_AKM2(int32_t increment_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorIncrement_AKM2(int32_t increment_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockDecrement_AKM2(int32_t decrement_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorDecrement_AKM2(int32_t decrement_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);

DL_API UFR_STATUS BlockRead_PK(uint8_t *data,
                                   uint8_t block_address,
                                   uint8_t auth_mode,
                                   const uint8_t *key);
DL_API UFR_STATUS BlockWrite_PK(const uint8_t *data,
                                    uint8_t block_address,
                                    uint8_t auth_mode,
                                    const uint8_t *key);
DL_API UFR_STATUS BlockInSectorRead_PK(uint8_t *data,
                                           uint8_t sector_address,
                                           uint8_t block_in_sector_address,
                                           uint8_t auth_mode,
                                           const uint8_t *key);
DL_API UFR_STATUS BlockInSectorWrite_PK(const uint8_t *data,
                                            uint8_t sector_address,
                                            uint8_t block_in_sector_address,
                                            uint8_t auth_mode,
                                            const uint8_t *key);
DL_API UFR_STATUS LinearRead_PK(uint8_t *data,
                                    uint16_t linear_address,
                                    uint16_t length,
                                    uint16_t *bytes_returned,
                                    uint8_t auth_mode,
                                    const uint8_t *key);
DL_API UFR_STATUS LinRowRead_PK(uint8_t *data,
                                    uint16_t linear_address,
                                    uint16_t length,
                                    uint16_t *bytes_returned,
                                    uint8_t auth_mode,
                                    const uint8_t *key);
DL_API UFR_STATUS LinearWrite_PK(const uint8_t *data,
                                     uint16_t linear_address,
                                     uint16_t length,
                                     uint16_t *bytes_written,
                                     uint8_t auth_mode,
                                     const uint8_t *key);
DL_API UFR_STATUS LinearFormatCard_PK(const uint8_t *new_key_A,
                                          uint8_t blocks_access_bits,
                                          uint8_t sector_trailers_access_bits,
                                          uint8_t sector_trailers_byte9,
                                          const uint8_t *new_key_B,
                                          uint8_t *lpucSectorsFormatted,
                                          uint8_t auth_mode,
                                          const uint8_t *key);
DL_API UFR_STATUS SectorTrailerWrite_PK(uint8_t addressing_mode,
                                            uint8_t address,
                                            const uint8_t *new_key_A,
                                            uint8_t block0_access_bits,
                                            uint8_t block1_access_bits,
                                            uint8_t block2_access_bits,
                                            uint8_t sector_trailer_access_bits,
                                            uint8_t sector_trailer_byte9,
                                            const uint8_t *new_key_B,
                                            uint8_t auth_mode,
                                            const uint8_t *key);
DL_API UFR_STATUS SectorTrailerWriteUnsafe_PK(uint8_t addressing_mode,
                                                  uint8_t address,
                                                  const uint8_t *sector_trailer,
                                                  uint8_t auth_mode,
                                                  const uint8_t *key);
DL_API UFR_STATUS ValueBlockRead_PK(int32_t *value,
                                        uint8_t *value_addr,
                                        uint8_t block_address,
                                        uint8_t auth_mode,
                                        const uint8_t *key);
DL_API UFR_STATUS ValueBlockInSectorRead_PK(int32_t *value,
                                                uint8_t *value_addr,
                                                uint8_t sector_address,
                                                uint8_t block_in_sector_address,
                                                uint8_t auth_mode,
                                                const uint8_t *key);
DL_API UFR_STATUS ValueBlockWrite_PK(int32_t value,
                                         uint8_t value_addr,
                                         uint8_t block_address,
                                         uint8_t auth_mode,
                                         const uint8_t *key);
DL_API UFR_STATUS ValueBlockInSectorWrite_PK(int32_t value,
                                                 uint8_t value_addr,
                                                 uint8_t sector_address,
                                                 uint8_t block_in_sector_address,
                                                 uint8_t auth_mode,
                                                 const uint8_t *key);
DL_API UFR_STATUS ValueBlockIncrement_PK(int32_t increment_value,
                                             uint8_t block_address,
                                             uint8_t auth_mode,
                                             const uint8_t *key);
DL_API UFR_STATUS ValueBlockInSectorIncrement_PK(int32_t increment_value,
                                                     uint8_t sector_address,
                                                     uint8_t block_in_sector_address,
                                                     uint8_t auth_mode,
                                                     const uint8_t *key);
DL_API UFR_STATUS ValueBlockDecrement_PK(int32_t decrement_value,
                                             uint8_t block_address,
                                             uint8_t auth_mode,
                                             const uint8_t *key);
DL_API UFR_STATUS ValueBlockInSectorDecrement_PK(int32_t decrement_value,
                                                     uint8_t sector_address,
                                                     uint8_t block_in_sector_address,
                                                     uint8_t auth_mode,
                                                     const uint8_t *key);
DL_API UFR_STATUS GetReaderHardwareVersion(uint8_t *version_major,
                                               uint8_t *version_minor);
DL_API UFR_STATUS GetReaderFirmwareVersion(uint8_t *version_major,
                                               uint8_t *version_minor);

// New commands (for RTC & I2C EEPROM):
DL_API UFR_STATUS GetReaderTime(uint8_t *time);
DL_API UFR_STATUS SetReaderTime(uint8_t *password, uint8_t *time);
DL_API UFR_STATUS ChangeReaderPassword(uint8_t *old_password, uint8_t *new_password);
DL_API UFR_STATUS ReaderEepromWrite(uint8_t *data, uint32_t address, uint32_t size, uint8_t *password);
DL_API UFR_STATUS ReaderEepromRead(uint8_t *data, uint32_t address, uint32_t size);
DL_API UFR_STATUS ChangeReaderJobId(uint8_t *job_id, uint8_t *new_password);

DL_API UFR_STATUS GetReaderSerialDescription(uint8_t pSerialDescription[8]);
DL_API UFR_STATUS SetReaderSerialDescription(const uint8_t pSerialDescription[8]);

// New since version 2.0:
DL_API UFR_STATUS GetBuildNumber(uint8_t *build);
DL_API UFR_STATUS GetCardIdEx(uint8_t *lpucSak, uint8_t *aucUid,
		uint8_t *lpucUidSize);
DL_API UFR_STATUS GetLastCardIdEx(uint8_t *lpucSak, uint8_t *aucUid,
		uint8_t *lpucUidSize);
DL_API UFR_STATUS EnableAntiColl(void);
DL_API UFR_STATUS DisableAntiColl(void);
DL_API UFR_STATUS EnumCards(uint8_t *lpucCardsNumber,
		uint8_t *lpucUidListSize);
DL_API UFR_STATUS ListCards(uint8_t *aucUidList, uint8_t ucUidListSize); // Before calling this function you must call EnumCards() first.
DL_API UFR_STATUS SelectCard(const uint8_t *aucUid, uint8_t ucUidSize,
		uint8_t *lpucSak);
DL_API UFR_STATUS DeslectCard(void);
DL_API UFR_STATUS GetAntiCollStatus(int8_t *lpcIsAntiCollEnabled,
		int8_t *lpcIsAnyCardSelected);


DL_API UFR_STATUS GetDlogicCardType(uint8_t *lpucCardType);
DL_API UFR_STATUS GetNfcT2TVersion(uint8_t lpucVersionResponse[8]);
DL_API UFR_STATUS GetCardSize(uint32_t *lpulLinearSize, uint32_t *lpulRawSize);

// uFCoder PRO MODE
DL_API UFR_STATUS GetReaderProMode(uint32_t *pReaderProMode, uint32_t *pReaderProConfig);
DL_API UFR_STATUS SetReaderProMode(const uint32_t ReaderProMode);


// QR barcode crypt algorithm
// initialization. with TB serial like 'TB123456'
DL_API UFR_STATUS CardEncryption_Initialize(const uint8_t *TBSerialString, uint16_t job_number);

// You must define 25 bytes array in memory for CardSerialString[]
DL_API
UFR_STATUS CardEncryption_GetNextEncryptedCard(const uint32_t from_timestamp, const uint32_t to_timestamp,
		uint8_t CardSerialString[25]);

DL_API
UFR_STATUS CardEncryption_GetActualCardSN(uint32_t *ActualCard_SN, uint32_t *ActualCard_SN_LOG);
DL_API
UFR_STATUS CardEncryption_GetJobSN(uint32_t *JobSN);
DL_API
UFR_STATUS CardEncryption_GetSalterSN(uint8_t SalterSN[8], uint8_t * magicByte);

DL_API UFR_STATUS read_ndef_record(uint8_t message_nr, uint8_t record_nr, uint8_t *tnf, uint8_t *type_record, uint8_t *type_length, uint8_t *id, uint8_t *id_length,
									   uint8_t *payload, uint32_t *payload_length);
DL_API UFR_STATUS write_ndef_record(uint8_t message_nr, uint8_t *tnf, uint8_t *type_record, uint8_t *type_length, uint8_t *id, uint8_t *id_length,
		   uint8_t *payload, uint32_t *payload_length, uint8_t *card_formated);
DL_API UFR_STATUS get_ndef_record_count(uint8_t *ndef_message_cnt, uint8_t *ndef_record_cnt, uint8_t *ndef_record_array, uint8_t *empty_ndef_message_cnt);
DL_API UFR_STATUS erase_last_ndef_record(uint8_t message_nr);
DL_API UFR_STATUS erase_all_ndef_records(uint8_t message_nr);
DL_API UFR_STATUS ndef_card_initialization(void);
//---------------------------------------------------------------------
// Card emulation:
//---------------------------------------------------------------------
DL_API UFR_STATUS WriteEmulationNdef(uint8_t tnf,
		uint8_t* type_record,
		uint8_t type_length,
		uint8_t* id,
		uint8_t id_length,
		uint8_t* payload,
		uint8_t payload_length);
DL_API UFR_STATUS TagEmulationStart(void);
DL_API UFR_STATUS TagEmulationStop(void);
DL_API UFR_STATUS CombinedModeEmulationStart(void);

DL_API UFR_STATUS EnterShareRamCommMode(void);
DL_API UFR_STATUS ExitShareRamCommMode(void);
DL_API UFR_STATUS WriteShareRam(uint8_t *ram_data, uint8_t addr, uint8_t data_len);
DL_API UFR_STATUS ReadShareRam(uint8_t *ram_data, uint8_t addr, uint8_t data_len);

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
DL_API void NfcT2TSafeConvertVersion(t2t_version_t *version, const uint8_t *version_record);
DL_API UFR_STATUS ReadECCSignature(uint8_t lpucECCSignature[ECC_SIG_LEN],
		uint8_t lpucUid[MAX_UID_LEN], uint8_t *lpucUidLen, uint8_t *lpucDlogicCardType);

//------------------------------------------------------------------------------
// NTAG 21x specific:
//------------------------------------------------------------------------------
// NTAG_FastRead() - data must point to a (end_block_addr - start_block_addr) * 4 allocated bytes.
// If you want to read only n bytes allocated use NTAG_FastReadBytes(ptr_n_bytes_allocated, n);
DL_API UFR_STATUS NTAG_FastRead(uint8_t *data, uint8_t start_block_addr, uint8_t end_block_addr);
DL_API UFR_STATUS NTAG_FastReadBytes(uint8_t *data, uint8_t start_block_addr, uint8_t data_size);
DL_API UFR_STATUS NTAG_ReadNFCCounter(uint32_t *nfc_counter_value);
// For NTAG_GetStaticLockBytes() you have to allocate some bytes before function call.
// Most secure way is to allocate 4 bytes in advance even so all known cards have 2 static lock bytes.
// in pointer uint8_t *lock_bytes_num will be placed actual lock bytes number (2 for now, in all cases).
DL_API UFR_STATUS NTAG_GetStaticLockBytes(uint8_t *lock_bytes, uint8_t *lock_bytes_num,
		uint8_t *lock_page, uint8_t *start_byte_in_page);
DL_API UFR_STATUS NTAG_SetStaticLockBytes(uint8_t *lock_bytes, uint8_t lock_bytes_num);
// For NTAG_GetDynamicLockBytes() you have to allocate some bytes before function call.
// Most secure way is to allocate 4 bytes in advance even so all known cards have max. 3 dynamic lock bytes.
// in pointer uint8_t *lock_bytes_num will be placed actual lock bytes number.
DL_API UFR_STATUS NTAG_GetDynamicLockBytes(uint8_t *lock_bytes, uint8_t *lock_bytes_num,
		uint8_t *lock_page, uint8_t *start_byte_in_page);
DL_API UFR_STATUS NTAG_SetDynamicLockBytes(uint8_t *lock_bytes, uint8_t lock_bytes_num);
//------------------------------------------------------------------------------

DL_API UFR_STATUS SetAsyncCardIdSendConfig(uint8_t send_enable,
		uint8_t prefix_enable, uint8_t prefix, uint8_t suffix,
		uint8_t send_removed_enable, uint32_t async_baud_rate);

DL_API UFR_STATUS GetAsyncCardIdSendConfig(uint8_t *send_enable,
		uint8_t *prefix_enable, uint8_t *prefix, uint8_t *suffix,
		uint8_t *send_removed_enable, uint32_t *async_baud_rate);

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
DL_API UFR_STATUS ais_get_card_number(uint32_t *card_number);

DL_API UFR_STATUS ais_set_right_record(uint8_t record_number, uint16_t first_reader_nr, uint16_t last_reader_nr,
		uint8_t start_hour, uint8_t start_minute, uint8_t end_hour, uint8_t end_minute, uint8_t *days);
DL_API UFR_STATUS ais_get_right_record(uint8_t record_number, uint16_t *first_reader_nr, uint16_t *last_reader_nr,
		uint8_t *start_hour, uint8_t *start_minute, uint8_t *end_hour, uint8_t *end_minute, uint8_t *days);
DL_API UFR_STATUS ais_erase_right_record(uint8_t record_number);
DL_API UFR_STATUS ais_set_validate_record(uint8_t begin_year, uint8_t begin_month, uint8_t begin_day, uint8_t begin_hour, uint8_t begin_minute,
		uint8_t end_year, uint8_t end_month, uint8_t end_day, uint8_t end_hour, uint8_t end_minute);
DL_API UFR_STATUS ais_get_validate_record(uint8_t *begin_year, uint8_t *begin_month, uint8_t *begin_day, uint8_t *begin_hour, uint8_t *begin_minute,
		uint8_t *end_year, uint8_t *end_month, uint8_t *end_day, uint8_t *end_hour, uint8_t *end_minute);
DL_API UFR_STATUS ais_set_card_type(uint8_t card_type);
DL_API UFR_STATUS ais_get_card_type(uint8_t *card_type);
DL_API UFR_STATUS ais_set_card_daily_duration(uint16_t duration);
DL_API UFR_STATUS ais_get_card_daily_duration(uint16_t *duration);
DL_API UFR_STATUS ais_set_card_total_duration(uint32_t duration);
DL_API UFR_STATUS ais_get_card_total_duration(uint32_t *duration);

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
DL_API UFR_STATUS ais_get_credit_and_period_validity(int32_t *credit,
		uint32_t *begin_year, uint32_t *begin_month, uint32_t *begin_day,
		uint32_t *begin_hour,
		uint32_t *begin_minute, //
		uint32_t *end_year, uint32_t *end_month, uint32_t *end_day,
		uint32_t *end_hour, uint32_t *end_minute);

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
DL_API UFR_STATUS ais_set_credit_and_period_validity(int32_t credit,
		uint32_t begin_year, uint32_t begin_month, uint32_t begin_day,
		uint32_t begin_hour,
		uint32_t begin_minute, //
		uint32_t end_year, uint32_t end_month, uint32_t end_day,
		uint32_t end_hour, uint32_t end_minute);
//=============================================================================

DL_API UFR_STATUS UfrXrcLockOn(uint16_t pulse_duration);
DL_API UFR_STATUS UfrXrcRelayState(uint8_t state);
DL_API UFR_STATUS UfrXrcGetIoState(uint8_t *intercom, uint8_t *door, uint8_t *relay_state);
DL_API UFR_STATUS UfrRedLightControl(uint8_t light_status);

DL_API UFR_STATUS UfrSetBadSelectCardNrMax(uint8_t bad_select_nr_max);
DL_API UFR_STATUS UfrGetBadSelectCardNrMax(uint8_t *bad_select_nr_max);

DL_API UFR_STATUS UfrEnterSleepMode(void);
DL_API UFR_STATUS UfrLeaveSleepMode(void);
DL_API UFR_STATUS AutoSleepSet(uint8_t seconds_wait);
DL_API UFR_STATUS AutoSleepGet(uint8_t *seconds_wait);

DL_API UFR_STATUS SetSpeedPermanently(unsigned char tx_speed, unsigned char rx_speed);
DL_API UFR_STATUS GetSpeedParameters(unsigned char *tx_speed, unsigned char *rx_speed);
DL_API UFR_STATUS SetDisplayData(uint8_t *display_data, uint8_t data_length);
DL_API UFR_STATUS SetSpeakerFrequency(uint16_t frequency);
DL_API UFR_STATUS SetDisplayIntensity(uint8_t intensity);
DL_API UFR_STATUS GetDisplayIntensity(uint8_t *intensity);
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
DL_API
UFR_STATUS uFR_i_block_transceive(uint8_t chaining, uint8_t timeout,
		uint8_t block_length, uint8_t *snd_data_array, size_t *rcv_length,
		uint8_t *rcv_data_array, uint32_t *ufr_status);

DL_API
UFR_STATUS DES_to_AES_key_type(void);

DL_API
UFR_STATUS AES_to_DES_key_type(void);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

DL_API
UFR_STATUS uFR_int_GetDesfireUid(uint8_t aes_key_nr, uint32_t aid,
		uint8_t aid_key_nr, uint8_t *card_uid, uint8_t *card_uid_len,
		uint16_t *card_status, uint16_t *exec_time);
DL_API
UFR_STATUS uFR_int_GetDesfireUid_PK(uint8_t *aes_key_ext, uint32_t aid,
		uint8_t aid_key_nr, uint8_t *card_uid, uint8_t *card_uid_len,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireFreeMem(uint32_t *free_mem_byte, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireFormatCard(uint8_t aes_key_nr, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireFormatCard_PK(uint8_t *aes_key_ext, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateStdDataFile(uint8_t aes_key_nr, uint32_t aid, uint8_t file_id, uint32_t file_size,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateStdDataFile_PK(uint8_t *aes_key_ext, uint32_t aid, uint8_t file_id, uint32_t file_size,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateStdDataFile_no_auth(uint32_t aid, uint8_t file_id, uint32_t file_size,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireDeleteFile(uint8_t aes_key_nr, uint32_t aid, uint8_t file_id,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireDeleteFile_PK(uint8_t *aes_key_ext, uint32_t aid, uint8_t file_id,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireDeleteFile_no_auth(uint32_t aid, uint8_t file_id,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateAesApplication(uint8_t aes_key_nr, uint32_t aid,
		uint8_t setting, uint8_t max_key_no, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateAesApplication_PK(uint8_t *aes_key_ext, uint32_t aid,
		uint8_t setting, uint8_t max_key_no, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateAesApplication_no_auth(uint32_t aid,
		uint8_t setting, uint8_t max_key_no, uint16_t *card_status,	uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireDeleteApplication(uint8_t aes_key_nr,	uint32_t aid,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireDeleteApplication_PK(uint8_t *aes_key_ext, uint32_t aid,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireSetConfiguration(uint8_t aes_key_nr, uint8_t random_uid, uint8_t format_disable,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireSetConfiguration_PK(uint8_t *aes_key_ext, uint8_t random_uid, uint8_t format_disable,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireGetKeySettings(uint8_t aes_key_nr, uint32_t aid,
		uint8_t *setting, uint8_t *max_key_no,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireGetKeySettings_PK(uint8_t *aes_key_ext, uint32_t aid,
		uint8_t *setting, uint8_t *max_key_no,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireChangeKeySettings(uint8_t aes_key_nr,	uint32_t aid,
		uint8_t setting, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireChangeKeySettings_PK(uint8_t *aes_key_ext, uint32_t aid,
		uint8_t setting, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireChangeAesKey(uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_no_auth,
		uint8_t new_aes_key[16], uint8_t aid_key_no, uint8_t old_aes_key[16],
		uint16_t *card_status, uint16_t *exec_time);

// all keys are in reader
DL_API
UFR_STATUS uFR_int_DesfireChangeAesKey_A(uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_no_auth,
		uint8_t new_aes_key_nr, uint8_t aid_key_no, uint8_t old_aes_key_nr,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireChangeAesKey_PK(uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_no_auth,
		uint8_t new_aes_key[16], uint8_t aid_key_no, uint8_t old_aes_key[16],
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_SetParam(uint8_t aes_key[16], uint8_t key_no,
		uint32_t aid_nr, uint8_t file_id);

DL_API
UFR_STATUS uFR_int_DesfireWriteAesKey(uint8_t aes_key_no, uint8_t *aes_key);

//---------------------------------------------------------------------------

DL_API
UFR_STATUS uFR_int_DesfireReadStdDataFile(uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireReadStdDataFile_PK(uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireReadStdDataFile_no_auth(uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireWriteStdDataFile(uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireWriteStdDataFile_PK(uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireWriteStdDataFile_no_auth(uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

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
DL_API UFR_STATUS ReaderList_UpdateAndGetCount(int32_t * NumberOfDevices);

DL_API UFR_STATUS ReaderList_GetSerialByIndex(int32_t DeviceIndex, uint32_t *lpulSerialNumber);
DL_API UFR_STATUS ReaderList_GetSerialDescriptionByIndex(int32_t DeviceIndex, uint8_t pSerialDescription[8]);

DL_API UFR_STATUS ReaderList_GetTypeByIndex(int32_t DeviceIndex, uint32_t *lpulReaderType);

DL_API UFR_STATUS ReaderList_GetFTDISerialByIndex(int32_t DeviceIndex, char ** Device_Serial);
DL_API UFR_STATUS ReaderList_GetFTDIDescriptionByIndex(int32_t DeviceIndex, char ** Device_Description);

DL_API UFR_STATUS ReaderList_OpenByIndex(const int32_t DeviceIndex, UFR_HANDLE *hndUFR);

// not implemented
//DL_API UFR_STATUS ReaderList_OpenBySerial(const char Device_SN[16], UFR_HANDLE *hndUFR);


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
DL_API UFR_STATUS ReaderList_GetInformation( //
		UFR_HANDLE *DeviceHandle, //// assigned Handle
		c_string *DeviceSerialNumber, //// device serial number
		int *DeviceType, //// device type - device identification in AIS database
		int *DeviceFWver, //// version of firmware
		int *DeviceCommID, //// device identification number (master)
		int *DeviceCommSpeed, //// communication speed
		c_string *DeviceCommFTDISerial, //// FTDI COM port identification
		c_string *DeviceCommFTDIDescription, //// FTDI COM port description
		int *DeviceIsOpened, //// is Device opened
		int *DeviceStatus //// actual device status
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
DL_API UFR_STATUS ReaderList_Destroy(UFR_HANDLE DeviceHandle);

//--------------------------------------------------------------------------------------------------

// open first/next Reader and return handle - better to use ReaderList_OpenByIndex()
DL_API UFR_STATUS ReaderOpenM(UFR_HANDLE *hndUFR);
DL_API UFR_STATUS ReaderResetM(UFR_HANDLE hndUFR);
DL_API UFR_STATUS ReaderCloseM(UFR_HANDLE hndUFR);
DL_API UFR_STATUS ReaderSoftRestartM(UFR_HANDLE hndUFR);
DL_API UFR_STATUS GetReaderTypeM(UFR_HANDLE hndUFR, uint32_t *lpulReaderType);
DL_API UFR_STATUS GetReaderSerialNumberM(UFR_HANDLE hndUFR, uint32_t *lpulSerialNumber);

DL_API UFR_STATUS ReaderStillConnectedM(UFR_HANDLE hndUFR, uint32_t *connected);

DL_API UFR_STATUS ReaderKeyWriteM(UFR_HANDLE hndUFR, const uint8_t *aucKey, uint8_t ucKeyIndex);
DL_API UFR_STATUS ReaderKeysLockM(UFR_HANDLE hndUFR, const uint8_t *password);
DL_API UFR_STATUS ReaderKeysUnlockM(UFR_HANDLE hndUFR, const uint8_t *password);
DL_API UFR_STATUS ReaderUISignalM(UFR_HANDLE hndUFR, uint8_t light_signal_mode,
                                     uint8_t beep_signal_mode);
DL_API UFR_STATUS ReadUserDataM(UFR_HANDLE hndUFR, uint8_t *aucData);
DL_API UFR_STATUS WriteUserDataM(UFR_HANDLE hndUFR, const uint8_t *aucData);
DL_API UFR_STATUS GetCardIdM(UFR_HANDLE hndUFR, uint8_t *lpucCardType, uint32_t *lpulCardSerial);
DL_API UFR_STATUS BlockReadM(UFR_HANDLE hndUFR, uint8_t *data,
                                uint8_t block_address,
                                uint8_t auth_mode,
                                uint8_t key_index);
DL_API UFR_STATUS BlockWriteM(UFR_HANDLE hndUFR, const uint8_t *data,
                                 uint8_t block_address,
                                 uint8_t auth_mode,
                                 uint8_t key_index);
DL_API UFR_STATUS BlockInSectorReadM(UFR_HANDLE hndUFR, uint8_t *data,
                                        uint8_t sector_address,
                                        uint8_t block_in_sector_address,
                                        uint8_t auth_mode,
                                        uint8_t key_index);
DL_API UFR_STATUS BlockInSectorWriteM(UFR_HANDLE hndUFR, const uint8_t *data,
                                         uint8_t sector_address,
                                         uint8_t block_in_sector_address,
                                         uint8_t auth_mode,
                                         uint8_t key_index);
DL_API UFR_STATUS LinearReadM(UFR_HANDLE hndUFR, uint8_t *aucData,
                                 uint16_t usLinearAddress,
                                 uint16_t usDataLength,
                                 uint16_t *lpusBytesReturned,
                                 uint8_t ucKeyMode,
                                 uint8_t ucReaderKeyIndex);
DL_API UFR_STATUS LinRowReadM(UFR_HANDLE hndUFR, uint8_t *aucData,
                                 uint16_t usLinearAddress,
                                 uint16_t usDataLength,
                                 uint16_t *lpusBytesReturned,
                                 uint8_t ucKeyMode,
                                 uint8_t ucReaderKeyIndex);
DL_API UFR_STATUS LinearWriteM(UFR_HANDLE hndUFR, const uint8_t *aucData,
                                  uint16_t usLinearAddress,
                                  uint16_t usDataLength,
                                  uint16_t *lpusBytesWritten,
                                  uint8_t ucKeyMode,
                                  uint8_t ucReaderKeyIndex);
DL_API UFR_STATUS LinearFormatCardM(UFR_HANDLE hndUFR, const uint8_t *new_key_A,
                                       uint8_t blocks_access_bits,
                                       uint8_t sector_trailers_access_bits,
                                       uint8_t sector_trailers_byte9,
                                       const uint8_t *new_key_B,
                                       uint8_t *lpucSectorsFormatted,
                                       uint8_t auth_mode,
                                       uint8_t key_index);
DL_API UFR_STATUS SectorTrailerWriteM(UFR_HANDLE hndUFR, uint8_t addressing_mode,
                                         uint8_t address,
                                         const uint8_t *new_key_A,
                                         uint8_t block0_access_bits,
                                         uint8_t block1_access_bits,
                                         uint8_t block2_access_bits,
                                         uint8_t sector_trailer_access_bits,
                                         uint8_t sector_trailer_byte9,
                                         const uint8_t *new_key_B,
                                         uint8_t auth_mode,
                                         uint8_t key_index);
DL_API UFR_STATUS SectorTrailerWriteUnsafeM(UFR_HANDLE hndUFR, uint8_t addressing_mode,
                                               uint8_t address,
                                               const uint8_t *sector_trailer,
                                               uint8_t auth_mode,
                                               uint8_t key_index);
DL_API UFR_STATUS ValueBlockReadM(UFR_HANDLE hndUFR, int32_t *value,
                                     uint8_t *value_addr,
                                     uint8_t block_address,
                                     uint8_t auth_mode,
                                     uint8_t key_index);
DL_API UFR_STATUS ValueBlockInSectorReadM(UFR_HANDLE hndUFR, int32_t *value,
                                             uint8_t *value_addr,
                                             uint8_t sector_address,
                                             uint8_t block_in_sector_address,
                                             uint8_t auth_mode,
                                             uint8_t key_index);
DL_API UFR_STATUS ValueBlockWriteM(UFR_HANDLE hndUFR, int32_t value,
                                      uint8_t value_addr,
                                      uint8_t block_address,
                                      uint8_t auth_mode,
                                      uint8_t key_index);
DL_API UFR_STATUS ValueBlockInSectorWriteM(UFR_HANDLE hndUFR, int32_t value,
                                              uint8_t value_addr,
                                              uint8_t sector_address,
                                              uint8_t block_in_sector_address,
                                              uint8_t auth_mode,
                                              uint8_t key_index);
DL_API UFR_STATUS ValueBlockIncrementM(UFR_HANDLE hndUFR, int32_t increment_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode,
                                          uint8_t key_index);
DL_API UFR_STATUS ValueBlockInSectorIncrementM(UFR_HANDLE hndUFR, int32_t increment_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode,
                                                  uint8_t key_index);
DL_API UFR_STATUS ValueBlockDecrementM(UFR_HANDLE hndUFR, int32_t decrement_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode,
                                          uint8_t key_index);
DL_API UFR_STATUS ValueBlockInSectorDecrementM(UFR_HANDLE hndUFR, int32_t decrement_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode,
                                                  uint8_t key_index);

DL_API UFR_STATUS BlockRead_AKM1M(UFR_HANDLE hndUFR, uint8_t *data,
                                    uint8_t block_address,
                                    uint8_t auth_mode);
DL_API UFR_STATUS BlockWrite_AKM1M(UFR_HANDLE hndUFR, const uint8_t *data,
                                 uint8_t block_address,
                                 uint8_t auth_mode);
DL_API UFR_STATUS BlockInSectorRead_AKM1M(UFR_HANDLE hndUFR, uint8_t *data,
                                        uint8_t sector_address,
                                        uint8_t block_in_sector_address,
                                        uint8_t auth_mode);
DL_API UFR_STATUS BlockInSectorWrite_AKM1M(UFR_HANDLE hndUFR, const uint8_t *data,
                                         uint8_t sector_address,
                                         uint8_t block_in_sector_address,
                                         uint8_t auth_mode);
DL_API UFR_STATUS LinearRead_AKM1M(UFR_HANDLE hndUFR, uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 uint16_t *bytes_returned,
                                 uint8_t auth_mode);
DL_API UFR_STATUS LinRowRead_AKM1M(UFR_HANDLE hndUFR, uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 uint16_t *bytes_returned,
                                 uint8_t auth_mode);
DL_API UFR_STATUS LinearWrite_AKM1M(UFR_HANDLE hndUFR, const uint8_t *data,
                                  uint16_t linear_address,
                                  uint16_t length,
                                  uint16_t *bytes_written,
                                  uint8_t auth_mode);
DL_API UFR_STATUS LinearFormatCard_AKM1M(UFR_HANDLE hndUFR, const uint8_t *new_key_A,
                                       uint8_t blocks_access_bits,
                                       uint8_t sector_trailers_access_bits,
                                       uint8_t sector_trailers_byte9,
                                       const uint8_t *new_key_B,
                                       uint8_t *lpucSectorsFormatted,
                                       uint8_t auth_mode);
DL_API UFR_STATUS SectorTrailerWrite_AKM1M(UFR_HANDLE hndUFR, uint8_t addressing_mode,
                                         uint8_t address,
                                         const uint8_t *new_key_A,
                                         uint8_t block0_access_bits,
                                         uint8_t block1_access_bits,
                                         uint8_t block2_access_bits,
                                         uint8_t sector_trailer_access_bits,
                                         uint8_t sector_trailer_byte9,
                                         const uint8_t *new_key_B,
                                         uint8_t auth_mode);
DL_API UFR_STATUS SectorTrailerWriteUnsafe_AKM1M(UFR_HANDLE hndUFR, uint8_t addressing_mode,
                                               uint8_t address,
                                               const uint8_t *sector_trailer,
                                               uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockRead_AKM1M(UFR_HANDLE hndUFR, int32_t *value,
                                     uint8_t *value_addr,
                                     uint8_t block_address,
                                     uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorRead_AKM1M(UFR_HANDLE hndUFR, int32_t *value,
                                             uint8_t *value_addr,
                                             uint8_t sector_address,
                                             uint8_t block_in_sector_address,
                                             uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockWrite_AKM1M(UFR_HANDLE hndUFR, int32_t value,
                                      uint8_t value_addr,
                                      uint8_t block_address,
                                      uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorWrite_AKM1M(UFR_HANDLE hndUFR, int32_t value,
                                              uint8_t value_addr,
                                              uint8_t sector_address,
                                              uint8_t block_in_sector_address,
                                              uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockIncrement_AKM1M(UFR_HANDLE hndUFR, int32_t increment_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorIncrement_AKM1M(UFR_HANDLE hndUFR, int32_t increment_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockDecrement_AKM1M(UFR_HANDLE hndUFR, int32_t decrement_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorDecrement_AKM1M(UFR_HANDLE hndUFR, int32_t decrement_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);

DL_API UFR_STATUS BlockRead_AKM2M(UFR_HANDLE hndUFR, uint8_t *data,
                                    uint8_t block_address,
                                    uint8_t auth_mode);
DL_API UFR_STATUS BlockWrite_AKM2M(UFR_HANDLE hndUFR, const uint8_t *data,
                                 uint8_t block_address,
                                 uint8_t auth_mode);
DL_API UFR_STATUS BlockInSectorRead_AKM2M(UFR_HANDLE hndUFR, uint8_t *data,
                                        uint8_t sector_address,
                                        uint8_t block_in_sector_address,
                                        uint8_t auth_mode);
DL_API UFR_STATUS BlockInSectorWrite_AKM2M(UFR_HANDLE hndUFR, const uint8_t *data,
                                         uint8_t sector_address,
                                         uint8_t block_in_sector_address,
                                         uint8_t auth_mode);
DL_API UFR_STATUS LinearRead_AKM2M(UFR_HANDLE hndUFR, uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 uint16_t *bytes_returned,
                                 uint8_t auth_mode);
DL_API UFR_STATUS LinRowRead_AKM2M(UFR_HANDLE hndUFR, uint8_t *data,
                                 uint16_t linear_address,
                                 uint16_t length,
                                 uint16_t *bytes_returned,
                                 uint8_t auth_mode);
DL_API UFR_STATUS LinearWrite_AKM2M(UFR_HANDLE hndUFR, const uint8_t *data,
                                  uint16_t linear_address,
                                  uint16_t length,
                                  uint16_t *bytes_written,
                                  uint8_t auth_mode);
DL_API UFR_STATUS LinearFormatCard_AKM2M(UFR_HANDLE hndUFR, const uint8_t *new_key_A,
                                       uint8_t blocks_access_bits,
                                       uint8_t sector_trailers_access_bits,
                                       uint8_t sector_trailers_byte9,
                                       const uint8_t *new_key_B,
                                       uint8_t *lpucSectorsFormatted,
                                       uint8_t auth_mode);
DL_API UFR_STATUS SectorTrailerWrite_AKM2M(UFR_HANDLE hndUFR, uint8_t addressing_mode,
                                         uint8_t address,
                                         const uint8_t *new_key_A,
                                         uint8_t block0_access_bits,
                                         uint8_t block1_access_bits,
                                         uint8_t block2_access_bits,
                                         uint8_t sector_trailer_access_bits,
                                         uint8_t sector_trailer_byte9,
                                         const uint8_t *new_key_B,
                                         uint8_t auth_mode);
DL_API UFR_STATUS SectorTrailerWriteUnsafe_AKM2M(UFR_HANDLE hndUFR, uint8_t addressing_mode,
                                               uint8_t address,
                                               const uint8_t *sector_trailer,
                                               uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockRead_AKM2M(UFR_HANDLE hndUFR, int32_t *value,
                                     uint8_t *value_addr,
                                     uint8_t block_address,
                                     uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorRead_AKM2M(UFR_HANDLE hndUFR, int32_t *value,
                                             uint8_t *value_addr,
                                             uint8_t sector_address,
                                             uint8_t block_in_sector_address,
                                             uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockWrite_AKM2M(UFR_HANDLE hndUFR, int32_t value,
                                      uint8_t value_addr,
                                      uint8_t block_address,
                                      uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorWrite_AKM2M(UFR_HANDLE hndUFR, int32_t value,
                                              uint8_t value_addr,
                                              uint8_t sector_address,
                                              uint8_t block_in_sector_address,
                                              uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockIncrement_AKM2M(UFR_HANDLE hndUFR, int32_t increment_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorIncrement_AKM2M(UFR_HANDLE hndUFR, int32_t increment_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockDecrement_AKM2M(UFR_HANDLE hndUFR, int32_t decrement_value,
                                          uint8_t block_address,
                                          uint8_t auth_mode);
DL_API UFR_STATUS ValueBlockInSectorDecrement_AKM2M(UFR_HANDLE hndUFR, int32_t decrement_value,
                                                  uint8_t sector_address,
                                                  uint8_t block_in_sector_address,
                                                  uint8_t auth_mode);

DL_API UFR_STATUS BlockRead_PKM(UFR_HANDLE hndUFR, uint8_t *data,
                                   uint8_t block_address,
                                   uint8_t auth_mode,
                                   const uint8_t *key);
DL_API UFR_STATUS BlockWrite_PKM(UFR_HANDLE hndUFR, const uint8_t *data,
                                    uint8_t block_address,
                                    uint8_t auth_mode,
                                    const uint8_t *key);
DL_API UFR_STATUS BlockInSectorRead_PKM(UFR_HANDLE hndUFR, uint8_t *data,
                                           uint8_t sector_address,
                                           uint8_t block_in_sector_address,
                                           uint8_t auth_mode,
                                           const uint8_t *key);
DL_API UFR_STATUS BlockInSectorWrite_PKM(UFR_HANDLE hndUFR, const uint8_t *data,
                                            uint8_t sector_address,
                                            uint8_t block_in_sector_address,
                                            uint8_t auth_mode,
                                            const uint8_t *key);
DL_API UFR_STATUS LinearRead_PKM(UFR_HANDLE hndUFR, uint8_t *data,
                                    uint16_t linear_address,
                                    uint16_t length,
                                    uint16_t *bytes_returned,
                                    uint8_t auth_mode,
                                    const uint8_t *key);
DL_API UFR_STATUS LinRowRead_PKM(UFR_HANDLE hndUFR, uint8_t *data,
                                    uint16_t linear_address,
                                    uint16_t length,
                                    uint16_t *bytes_returned,
                                    uint8_t auth_mode,
                                    const uint8_t *key);
DL_API UFR_STATUS LinearWrite_PKM(UFR_HANDLE hndUFR, const uint8_t *data,
                                     uint16_t linear_address,
                                     uint16_t length,
                                     uint16_t *bytes_written,
                                     uint8_t auth_mode,
                                     const uint8_t *key);
DL_API UFR_STATUS LinearFormatCard_PKM(UFR_HANDLE hndUFR, const uint8_t *new_key_A,
                                          uint8_t blocks_access_bits,
                                          uint8_t sector_trailers_access_bits,
                                          uint8_t sector_trailers_byte9,
                                          const uint8_t *new_key_B,
                                          uint8_t *lpucSectorsFormatted,
                                          uint8_t auth_mode,
                                          const uint8_t *key);
DL_API UFR_STATUS SectorTrailerWrite_PKM(UFR_HANDLE hndUFR, uint8_t addressing_mode,
                                            uint8_t address,
                                            const uint8_t *new_key_A,
                                            uint8_t block0_access_bits,
                                            uint8_t block1_access_bits,
                                            uint8_t block2_access_bits,
                                            uint8_t sector_trailer_access_bits,
                                            uint8_t sector_trailer_byte9,
                                            const uint8_t *new_key_B,
                                            uint8_t auth_mode,
                                            const uint8_t *key);
DL_API UFR_STATUS SectorTrailerWriteUnsafe_PKM(UFR_HANDLE hndUFR, uint8_t addressing_mode,
                                                  uint8_t address,
                                                  const uint8_t *sector_trailer,
                                                  uint8_t auth_mode,
                                                  const uint8_t *key);
DL_API UFR_STATUS ValueBlockRead_PKM(UFR_HANDLE hndUFR, int32_t *value,
                                        uint8_t *value_addr,
                                        uint8_t block_address,
                                        uint8_t auth_mode,
                                        const uint8_t *key);
DL_API UFR_STATUS ValueBlockInSectorRead_PKM(UFR_HANDLE hndUFR, int32_t *value,
                                                uint8_t *value_addr,
                                                uint8_t sector_address,
                                                uint8_t block_in_sector_address,
                                                uint8_t auth_mode,
                                                const uint8_t *key);
DL_API UFR_STATUS ValueBlockWrite_PKM(UFR_HANDLE hndUFR, int32_t value,
                                         uint8_t value_addr,
                                         uint8_t block_address,
                                         uint8_t auth_mode,
                                         const uint8_t *key);
DL_API UFR_STATUS ValueBlockInSectorWrite_PKM(UFR_HANDLE hndUFR, int32_t value,
                                                 uint8_t value_addr,
                                                 uint8_t sector_address,
                                                 uint8_t block_in_sector_address,
                                                 uint8_t auth_mode,
                                                 const uint8_t *key);
DL_API UFR_STATUS ValueBlockIncrement_PKM(UFR_HANDLE hndUFR, int32_t increment_value,
                                             uint8_t block_address,
                                             uint8_t auth_mode,
                                             const uint8_t *key);
DL_API UFR_STATUS ValueBlockInSectorIncrement_PKM(UFR_HANDLE hndUFR, int32_t increment_value,
                                                     uint8_t sector_address,
                                                     uint8_t block_in_sector_address,
                                                     uint8_t auth_mode,
                                                     const uint8_t *key);
DL_API UFR_STATUS ValueBlockDecrement_PKM(UFR_HANDLE hndUFR, int32_t decrement_value,
                                             uint8_t block_address,
                                             uint8_t auth_mode,
                                             const uint8_t *key);
DL_API UFR_STATUS ValueBlockInSectorDecrement_PKM(UFR_HANDLE hndUFR, int32_t decrement_value,
                                                     uint8_t sector_address,
                                                     uint8_t block_in_sector_address,
                                                     uint8_t auth_mode,
                                                     const uint8_t *key);
DL_API UFR_STATUS GetReaderHardwareVersionM(UFR_HANDLE hndUFR, uint8_t *version_major,
                                               uint8_t *version_minor);
DL_API UFR_STATUS GetReaderFirmwareVersionM(UFR_HANDLE hndUFR, uint8_t *version_major,
                                               uint8_t *version_minor);

// New commands (for RTC & I2C EEPROM):
DL_API UFR_STATUS GetReaderTimeM(UFR_HANDLE hndUFR, uint8_t *time);
DL_API UFR_STATUS SetReaderTimeM(UFR_HANDLE hndUFR, uint8_t *password, uint8_t *time);
DL_API UFR_STATUS ChangeReaderPasswordM(UFR_HANDLE hndUFR, uint8_t *old_password, uint8_t *new_password);
DL_API UFR_STATUS ReaderEepromWriteM(UFR_HANDLE hndUFR, uint8_t *data, uint32_t address, uint32_t size, uint8_t *password);
DL_API UFR_STATUS ReaderEepromReadM(UFR_HANDLE hndUFR, uint8_t *data, uint32_t address, uint32_t size);
DL_API UFR_STATUS ChangeReaderJobIdM(UFR_HANDLE hndUFR, uint8_t *job_id, uint8_t *new_password);

DL_API UFR_STATUS GetReaderSerialDescriptionM(UFR_HANDLE hndUFR, uint8_t pSerialDescription[8]);

// New since version 2.0:
DL_API UFR_STATUS GetBuildNumberM(UFR_HANDLE hndUFR, uint8_t *build);
DL_API UFR_STATUS GetCardIdExM(UFR_HANDLE hndUFR, uint8_t *lpucSak,
		uint8_t *aucUid, uint8_t *lpucUidSize);
DL_API UFR_STATUS GetLastCardIdExM(UFR_HANDLE hndUFR, uint8_t *lpucSak,
		uint8_t *aucUid, uint8_t *lpucUidSize);
DL_API UFR_STATUS EnableAntiCollM(UFR_HANDLE hndUFR);
DL_API UFR_STATUS DisableAntiCollM(UFR_HANDLE hndUFR);
DL_API UFR_STATUS EnumCardsM(UFR_HANDLE hndUFR, uint8_t *lpucCardsNumber,
		uint8_t *lpucUidListSize);
DL_API UFR_STATUS ListCardsM(UFR_HANDLE hndUFR, uint8_t *aucUidList,
		uint8_t ucUidListSize); // Before calling this function you must call EnumCardsM() first.
DL_API UFR_STATUS SelectCardM(UFR_HANDLE hndUFR, const uint8_t *aucUid,
		uint8_t ucUidSize, uint8_t *lpucSak);
DL_API UFR_STATUS DeslectCardM(UFR_HANDLE hndUFR);
DL_API UFR_STATUS GetAntiCollStatusM(UFR_HANDLE hndUFR, int8_t *lpcIsAntiCollEnabled,
		int8_t *lpcIsAnyCardSelected);


DL_API UFR_STATUS GetDlogicCardTypeM(UFR_HANDLE hndUFR, uint8_t *lpucCardType);
DL_API UFR_STATUS GetNfcT2TVersionM(UFR_HANDLE hndUFR, uint8_t lpucVersionResponse[8]);
DL_API UFR_STATUS GetCardSizeM(UFR_HANDLE hndUFR, uint32_t *lpulLinearSize, uint32_t *lpulRawSize);

// uFCoder PRO MODE
DL_API UFR_STATUS GetReaderProModeM(UFR_HANDLE hndUFR, uint32_t *pReaderProMode, uint32_t *pReaderProConfig);
DL_API UFR_STATUS SetReaderProModeM(UFR_HANDLE hndUFR, const uint32_t ReaderProMode);

// QR barcode crypt algorithm
// initialization. with TB serial like 'TB123456'
DL_API UFR_STATUS CardEncryption_InitializeM(UFR_HANDLE hndUFR, const uint8_t *TBSerialString, uint16_t job_number);

// You must define 25 bytes array in memory for CardSerialString[]
DL_API
UFR_STATUS CardEncryption_GetNextEncryptedCardM(UFR_HANDLE hndUFR, const uint32_t from_timestamp, const uint32_t to_timestamp,
		uint8_t CardSerialString[25]);

DL_API
UFR_STATUS CardEncryption_GetActualCardSNM(UFR_HANDLE hndUFR, uint32_t *ActualCard_SN, uint32_t *ActualCard_SN_LOG);
DL_API
UFR_STATUS CardEncryption_GetJobSNM(UFR_HANDLE hndUFR, uint32_t *JobSN);
DL_API
UFR_STATUS CardEncryption_GetSalterSNM(UFR_HANDLE hndUFR, uint8_t SalterSN[8], uint8_t * magicByte);

DL_API UFR_STATUS read_ndef_recordM(UFR_HANDLE hndUFR, uint8_t message_nr, uint8_t record_nr, uint8_t *tnf, uint8_t *type_record, uint8_t *type_length, uint8_t *id, uint8_t *id_length,
									   uint8_t *payload, uint32_t *payload_length);
DL_API UFR_STATUS write_ndef_recordM(UFR_HANDLE hndUFR, uint8_t message_nr, uint8_t *tnf, uint8_t *type_record, uint8_t *type_length, uint8_t *id, uint8_t *id_length,
		   uint8_t *payload, uint32_t *payload_length, uint8_t *card_formated);
DL_API UFR_STATUS get_ndef_record_countM(UFR_HANDLE hndUFR, uint8_t *ndef_message_cnt, uint8_t *ndef_record_cnt, uint8_t *ndef_record_array, uint8_t *empty_ndef_message_cnt);
DL_API UFR_STATUS erase_last_ndef_recordM(UFR_HANDLE hndUFR, uint8_t message_nr);
DL_API UFR_STATUS erase_all_ndef_recordsM(UFR_HANDLE hndUFR, uint8_t message_nr);
DL_API UFR_STATUS ndef_card_initializationM(UFR_HANDLE hndUFR);
//---------------------------------------------------------------------
// Card emulation:
//---------------------------------------------------------------------
DL_API UFR_STATUS WriteEmulationNdefM(UFR_HANDLE hndUFR,
		uint8_t tnf,
		uint8_t* type_record,
		uint8_t type_length,
		uint8_t* id,
		uint8_t id_length,
		uint8_t* payload,
		uint8_t payload_length);
DL_API UFR_STATUS TagEmulationStartM(UFR_HANDLE hndUFR);
DL_API UFR_STATUS TagEmulationStopM(UFR_HANDLE hndUFR);
DL_API UFR_STATUS CombinedModeEmulationStartM(UFR_HANDLE hndUFR);
//------------------------------------------------------------------------------
DL_API UFR_STATUS ReadECCSignatureM(UFR_HANDLE hndUFR, uint8_t lpucECCSignature[ECC_SIG_LEN],
		uint8_t lpucUid[MAX_UID_LEN], uint8_t *lpucUidLen, uint8_t *lpucDlogicCardType);

//------------------------------------------------------------------------------
// NTAG 21x specific:
//------------------------------------------------------------------------------
DL_API UFR_STATUS NTAG_FastReadM(UFR_HANDLE hndUFR, uint8_t *data, uint8_t start_block_addr, uint8_t end_block_addr);
DL_API UFR_STATUS NTAG_FastReadBytesM(UFR_HANDLE hndUFR, uint8_t *data, uint8_t start_block_addr, uint8_t data_size);
DL_API UFR_STATUS NTAG_ReadNFCCounterM(UFR_HANDLE hndUFR, uint32_t *nfc_counter_value);
DL_API UFR_STATUS NTAG_GetStaticLockBytesM(UFR_HANDLE hndUFR, uint8_t *lock_bytes, uint8_t *lock_bytes_num,
		uint8_t *lock_page, uint8_t *start_byte_in_page);
DL_API UFR_STATUS NTAG_SetStaticLockBytesM(UFR_HANDLE hndUFR, uint8_t *lock_bytes, uint8_t lock_bytes_num);
DL_API UFR_STATUS NTAG_GetDynamicLockBytesM(UFR_HANDLE hndUFR, uint8_t *lock_bytes, uint8_t *lock_bytes_num,
		uint8_t *lock_page, uint8_t *start_byte_in_page);
DL_API UFR_STATUS NTAG_SetDynamicLockBytesM(UFR_HANDLE hndUFR, uint8_t *lock_bytes, uint8_t lock_bytes_num);
//------------------------------------------------------------------------------

DL_API UFR_STATUS SetAsyncCardIdSendConfigM(UFR_HANDLE hndUFR,
		uint8_t send_enable, uint8_t prefix_enable, uint8_t prefix,
		uint8_t suffix, uint8_t send_removed_enable, uint32_t async_baud_rate);

DL_API UFR_STATUS GetAsyncCardIdSendConfigM(UFR_HANDLE hndUFR,
		uint8_t *send_enable, uint8_t *prefix_enable, uint8_t *prefix,
		uint8_t *suffix, uint8_t *send_removed_enable, uint32_t *async_baud_rate);

/*****************************************************************************
 * AIS FUNCTIONS
 *****************************************************************************
 */

DL_API UFR_STATUS ais_get_card_numberM(UFR_HANDLE hndUFR, uint32_t *card_number);

DL_API UFR_STATUS ais_set_right_recordM(UFR_HANDLE hndUFR,
		uint8_t record_number, uint16_t first_reader_nr,
		uint16_t last_reader_nr, uint8_t start_hour, uint8_t start_minute,
		uint8_t end_hour, uint8_t end_minute, uint8_t *days);
DL_API UFR_STATUS ais_get_right_recordM(UFR_HANDLE hndUFR,
		uint8_t record_number, uint16_t *first_reader_nr,
		uint16_t *last_reader_nr, uint8_t *start_hour,
		uint8_t *start_minute, uint8_t *end_hour, uint8_t *end_minute,
		uint8_t *days);
DL_API UFR_STATUS ais_erase_right_recordM(UFR_HANDLE hndUFR,
		uint8_t record_number);
DL_API UFR_STATUS ais_set_validate_recordM(UFR_HANDLE hndUFR,
		uint8_t begin_year, uint8_t begin_month, uint8_t begin_day,
		uint8_t begin_hour, uint8_t begin_minute, uint8_t end_year,
		uint8_t end_month, uint8_t end_day, uint8_t end_hour,
		uint8_t end_minute);
DL_API UFR_STATUS ais_get_validate_recordM(UFR_HANDLE hndUFR,
		uint8_t *begin_year, uint8_t *begin_month, uint8_t *begin_day,
		uint8_t *begin_hour, uint8_t *begin_minute, uint8_t *end_year,
		uint8_t *end_month, uint8_t *end_day, uint8_t *end_hour,
		uint8_t *end_minute);
DL_API UFR_STATUS ais_set_card_typeM(UFR_HANDLE hndUFR, uint8_t card_type);
DL_API UFR_STATUS ais_get_card_typeM(UFR_HANDLE hndUFR, uint8_t *card_type);
DL_API UFR_STATUS ais_set_card_daily_durationM(UFR_HANDLE hndUFR, uint16_t duration);
DL_API UFR_STATUS ais_get_card_daily_durationM(UFR_HANDLE hndUFR, uint16_t *duration);
DL_API UFR_STATUS ais_set_card_total_durationM(UFR_HANDLE hndUFR, uint32_t duration);
DL_API UFR_STATUS ais_get_card_total_durationM(UFR_HANDLE hndUFR, uint32_t *duration);

// swimming pool **************************************************************

DL_API UFR_STATUS ais_get_credit_and_period_validityM(UFR_HANDLE hndUFR,
		int32_t *credit, uint32_t *begin_year, uint32_t *begin_month,
		uint32_t *begin_day, uint32_t *begin_hour, uint32_t *begin_minute, //
		uint32_t *end_year, uint32_t *end_month, uint32_t *end_day,
		uint32_t *end_hour, uint32_t *end_minute);

DL_API UFR_STATUS ais_set_credit_and_period_validityM(UFR_HANDLE hndUFR,
		int32_t credit, uint32_t begin_year, uint32_t begin_month,
		uint32_t begin_day, uint32_t begin_hour, uint32_t begin_minute, //
		uint32_t end_year, uint32_t end_month, uint32_t end_day,
		uint32_t end_hour, uint32_t end_minute);
//=============================================================================

DL_API UFR_STATUS UfrXrcLockOnM(UFR_HANDLE hndUFR, uint16_t pulse_duration);
DL_API UFR_STATUS UfrXrcRelayStateM(UFR_HANDLE hndUFR, uint8_t state);
DL_API UFR_STATUS UfrXrcGetIoStateM(UFR_HANDLE hndUFR, uint8_t *intercom, uint8_t *door, uint8_t *relay_state);
DL_API UFR_STATUS UfrRedLightControlM(UFR_HANDLE hndUFR, uint8_t light_status);

DL_API UFR_STATUS UfrSetBadSelectCardNrMaxM(UFR_HANDLE hndUFR, uint8_t bad_select_nr_max);
DL_API UFR_STATUS UfrGetBadSelectCardNrMaxM(UFR_HANDLE hndUFR, uint8_t *bad_select_nr_max);

DL_API UFR_STATUS UfrEnterSleepModeM(UFR_HANDLE hndUFR);
DL_API UFR_STATUS UfrLeaveSleepModeM(UFR_HANDLE hndUFR);
DL_API UFR_STATUS AutoSleepSetM(UFR_HANDLE hndUFR, uint8_t seconds_wait);
DL_API UFR_STATUS AutoSleepGetM(UFR_HANDLE hndUFR, uint8_t *seconds_wait);

DL_API UFR_STATUS SetSpeedPermanentlyM(UFR_HANDLE hndUFR, unsigned char tx_speed, unsigned char rx_speed);
DL_API UFR_STATUS GetSpeedParametersM(UFR_HANDLE hndUFR, unsigned char *tx_speed, unsigned char *rx_speed);
DL_API UFR_STATUS SetDisplayDataM(UFR_HANDLE hndUFR, uint8_t *display_data, uint8_t data_length);
DL_API UFR_STATUS SetSpeakerFrequencyM(UFR_HANDLE hndUFR, uint16_t frequency);
DL_API UFR_STATUS SetDisplayIntensityM(UFR_HANDLE hndUFR, uint8_t intensity);
DL_API UFR_STATUS GetDisplayIntensityM(UFR_HANDLE hndUFR, uint8_t *intensity);

//#############################################################################
//#############################################################################


DL_API
UFR_STATUS uFR_i_block_transceiveM(UFR_HANDLE hndUFR, uint8_t chaining,
		uint8_t timeout, uint8_t block_length, uint8_t *snd_data_array,
		size_t *rcv_length, uint8_t *rcv_data_array, uint32_t *ufr_status);

//#############################################################################

//DL_API
//void print_desfire_version(struct mifare_desfire_version_info *desfire_version);

typedef void * HND;

DL_API
UFR_STATUS uFR_DESFIRE_Start(void);

DL_API
UFR_STATUS uFR_DESFIRE_Stop(void);

DL_API
HND
uFR_mifare_desfire_tag_new (void);

DL_API
void
uFR_mifare_desfire_tag_free (HND tag);

DL_API
HND
uFR_mifare_desfire_des_key_new (uint8_t value[8]);

DL_API
int uFR_mifare_desfire_get_key_settings (HND tag, uint8_t *settings, uint8_t *max_keys);

DL_API
void
uFR_mifare_desfire_key_free (HND key);

DL_API
HND
uFR_mifare_desfire_aes_key_new_with_version (uint8_t value[16], uint8_t version);

DL_API
int
uFR_mifare_desfire_change_key (HND tag, uint8_t key_no, HND new_key, HND old_key);

DL_API
int
uFR_mifare_desfire_authenticate (HND tag, uint8_t key_no, HND key);

DL_API
int
uFR_mifare_desfire_authenticate_aes (HND tag, uint8_t key_no, HND key);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

DL_API
UFR_STATUS uFR_int_GetDesfireUidM(UFR_HANDLE hndUFR, uint8_t aes_key_nr, uint32_t aid,
		uint8_t aid_key_nr, uint8_t *card_uid, uint8_t *card_uid_len,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_GetDesfireUid_PK_M(UFR_HANDLE hndUFR,uint8_t *aes_key_ext, uint32_t aid,
		uint8_t aid_key_nr, uint8_t *card_uid, uint8_t *card_uid_len,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireFreeMemM(UFR_HANDLE hndUFR, uint32_t *free_mem_byte, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireFormatCardM(UFR_HANDLE hndUFR, uint8_t aes_key_nr, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireFormatCard_PK_M(UFR_HANDLE hndUFR, uint8_t *aes_key_ext, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateStdDataFileM(UFR_HANDLE hndUFR,uint8_t aes_key_nr, uint32_t aid, uint8_t file_id, uint32_t file_size,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateStdDataFile_PK_M(UFR_HANDLE hndUFR, uint8_t *aes_key_ext, uint32_t aid, uint8_t file_id, uint32_t file_size,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateStdDataFile_no_auth_M(UFR_HANDLE hndUFR, uint32_t aid, uint8_t file_id, uint32_t file_size,
		uint8_t read_key_no, uint8_t write_key_no, uint8_t read_write_key_no, uint8_t change_key_no,
		uint8_t communication_settings, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireDeleteFileM(UFR_HANDLE hndUFR, uint8_t aes_key_nr, uint32_t aid, uint8_t file_id,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireDeleteFile_PK_M(UFR_HANDLE hndUFR, uint8_t *aes_key_ext, uint32_t aid, uint8_t file_id,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireDeleteFile_no_auth_M(UFR_HANDLE hndUFR, uint32_t aid, uint8_t file_id,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateAesApplicationM(UFR_HANDLE hndUFR,uint8_t aes_key_nr, uint32_t aid,
		uint8_t setting, uint8_t max_key_no, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateAesApplication_PK_M(UFR_HANDLE hndUFR, uint8_t *aes_key_ext, uint32_t aid,
		uint8_t setting, uint8_t max_key_no, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireCreateAesApplication_no_auth_M(UFR_HANDLE hndUFR, uint32_t aid,
		uint8_t setting, uint8_t max_key_no, uint16_t *card_status,	uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireDeleteApplicationM(UFR_HANDLE hndUFR, uint8_t aes_key_nr,	uint32_t aid,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireDeleteApplication_PK_M(UFR_HANDLE hndUFR, uint8_t *aes_key_ext, uint32_t aid,
		uint16_t *card_status, uint16_t *exec_time);


DL_API
UFR_STATUS uFR_int_DesfireSetConfigurationM(UFR_HANDLE hndUFR, uint8_t aes_key_nr, uint8_t random_uid, uint8_t format_disable,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireSetConfiguration_PK_M(UFR_HANDLE hndUFR, uint8_t *aes_key_ext, uint8_t random_uid, uint8_t format_disable,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireGetKeySettingsM(UFR_HANDLE hndUFR, uint8_t aes_key_nr, uint32_t aid,
		uint8_t *setting, uint8_t *max_key_no,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireGetKeySettings_PK_M(UFR_HANDLE hndUFR, uint8_t *aes_key_ext, uint32_t aid,
		uint8_t *setting, uint8_t *max_key_no,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireChangeKeySettingsM(UFR_HANDLE hndUFR,uint8_t aes_key_nr,	uint32_t aid,
		uint8_t setting, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireChangeKeySettings_PK_M(UFR_HANDLE hndUFR, uint8_t *aes_key_ext, uint32_t aid,
		uint8_t setting, uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireChangeAesKeyM(UFR_HANDLE hndUFR, uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_no_auth,
		uint8_t new_aes_key[16], uint8_t aid_key_no, uint8_t old_aes_key[16],
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireChangeAesKey_PK_M(UFR_HANDLE hndUFR, uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_no_auth,
		uint8_t new_aes_key[16], uint8_t aid_key_no, uint8_t old_aes_key[16],
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_SetParamM(UFR_HANDLE hndUFR, uint8_t aes_key[16], uint8_t key_no,
		uint32_t aid_nr, uint8_t file_id);


//---------------------------------------------------------------------------

DL_API
UFR_STATUS uFR_int_DesfireReaStddDataFileM(UFR_HANDLE hndUFR, uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireReadStdDataFile_PK_M(UFR_HANDLE hndUFR, uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireReadStdDataFile_no_auth_M(UFR_HANDLE hndUFR, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireWriteStdDataFileM(UFR_HANDLE hndUFR, uint8_t aes_key_nr, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireWriteStdDataFile_PK_M(UFR_HANDLE hndUFR, uint8_t *aes_key_ext, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

DL_API
UFR_STATUS uFR_int_DesfireWriteStdDataFile_no_auth_M(UFR_HANDLE hndUFR, uint32_t aid, uint8_t aid_key_nr, uint8_t file_id,
		uint16_t offset, uint16_t data_length,
		uint8_t communication_settings, uint8_t *data,
		uint16_t *card_status, uint16_t *exec_time);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// DLL version ----------------------------------------------------------------
DL_API uint32_t GetDllVersion(void);

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
DL_API
UFR_STATUS OriginalityCheck(const uint8_t *signature, const uint8_t *uid, uint8_t uid_len, uint8_t DlogicCardType);
// Returns:
// UFR_OPEN_SSL_DYNAMIC_LIB_NOT_FOUND in case there is no OpenSSL library (libeay32.dll) in current folder or path
// UFR_OPEN_SSL_DYNAMIC_LIB_FAILED    in case of OpenSSL library error (e.g. wrong OpenSSL version)
// UFR_NOT_NXP_GENUINE                if chip on the card/tag is NOT NXP genuine
// UFR_OK                             is chip on the card/tag is NXP GENUINE

//// debug functions:
DL_API c_string GetDllVersionStr(void);
DL_API c_string UFR_Status2String(const UFR_STATUS status);
DL_API void error_get(void *out, int32_t *size);

//// Helper functions:
#ifndef _WIN32

unsigned long GetTickCount(void);

#endif // #ifndef _WIN32

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

DL_API c_string GetReaderDescription(void);
DL_API c_string GetReaderDescriptionM(UFR_HANDLE hndUFR);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DL_API UFR_STATUS test_i_block(void);
DL_API UFR_STATUS test_desfire_ver(void);

#ifdef __cplusplus
}
#endif

#endif /* uFCoder_H_ */
