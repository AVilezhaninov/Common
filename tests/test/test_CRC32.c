/* Includes ------------------------------------------------------------------*/
#include "unity.h"

#include "CRC32.h"


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private constants ---------------------------------------------------------*/
const uint8_t one_byte = 0xAA;
const uint32_t one_byte_crc32 = 0xE401A57B;

const uint8_t string1[] = "01234567891472583697849516230";
const uint32_t string1_crc32 = 0xFF1D9011;

const uint8_t string2[] = "abcdefghijklmnopqrstuvwxyzqwertyuiopasdfghjklzxcvbn";
const uint32_t string2_crc32 = 0xEB2F920E;

const uint32_t strin1_plus_string2_crc32 = 0xD346CEC5;
const uint32_t strin2_plus_string1_crc32 = 0x10603937;


/* Private types -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/




/* Setup ---------------------------------------------------------------------*/
void setUp(void) {

}


/* Teardown  -----------------------------------------------------------------*/
void tearDown(void) {

}


/* Tests ---------------------------------------------------------------------*/
void test_GetCRC32_with_one_byte(void) {
    TEST_ASSERT_EQUAL_HEX32_MESSAGE(one_byte_crc32,
                                    GetCRC32(0u, &one_byte, sizeof(one_byte)),
                                    "failed one byte crc32");
}


void test_GetCRC32_with_one_string(void) {
    TEST_ASSERT_EQUAL_HEX32_MESSAGE(string1_crc32,
                                    GetCRC32(0u, string1, sizeof(string1) - 1u),
                                    "failed one string crc32");

    TEST_ASSERT_EQUAL_HEX32_MESSAGE(string2_crc32,
                                    GetCRC32(0u, string2, sizeof(string2) - 1u),
                                    "failed one string crc32");
}


void test_GetCRC32_with_two_strings(void) {
    uint32_t crc32;

    crc32 = GetCRC32(0u, string1, sizeof(string1) - 1u);
    crc32 = GetCRC32(crc32, string2, sizeof(string2) - 1u);
    TEST_ASSERT_EQUAL_HEX32_MESSAGE(strin1_plus_string2_crc32,
                                    crc32,
                                    "failed two strings crc32");

    crc32 = GetCRC32(0u, string2, sizeof(string2) - 1u);
    crc32 = GetCRC32(crc32, string1, sizeof(string1) - 1u);
    TEST_ASSERT_EQUAL_HEX32_MESSAGE(strin2_plus_string1_crc32,
                                    crc32,
                                    "failed two strings crc32");
}


/* Private functions ---------------------------------------------------------*/
