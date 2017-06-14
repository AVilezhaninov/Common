#include "build/temp/_test_CRC32.c"
#include "CRC32.h"
#include "unity.h"




const uint8_t one_byte = 0xAA;

const uint32_t one_byte_crc32 = 0xE401A57B;



const uint8_t string1[] = "01234567891472583697849516230";

const uint32_t string1_crc32 = 0xFF1D9011;



const uint8_t string2[] = "abcdefghijklmnopqrstuvwxyzqwertyuiopasdfghjklzxcvbn";

const uint32_t string2_crc32 = 0xEB2F920E;



const uint32_t strin1_plus_string2_crc32 = 0xD346CEC5;

const uint32_t strin2_plus_string1_crc32 = 0x10603937;

void setUp(void) {



}







void tearDown(void) {



}







void test_GetCRC32_with_one_byte(void) {

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((one_byte_crc32)), (UNITY_INT)(UNITY_INT32)((GetCRC32(0u, &one_byte, sizeof(one_byte)))), (("failed one byte crc32")), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_HEX32)



                                                            ;

}





void test_GetCRC32_with_one_string(void) {

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((string1_crc32)), (UNITY_INT)(UNITY_INT32)((GetCRC32(0u, string1, sizeof(string1) - 1u))), (("failed one string crc32")), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_HEX32)



                                                              ;



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((string2_crc32)), (UNITY_INT)(UNITY_INT32)((GetCRC32(0u, string2, sizeof(string2) - 1u))), (("failed one string crc32")), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_HEX32)



                                                              ;

}





void test_GetCRC32_with_two_strings(void) {

    uint32_t crc32;



    crc32 = GetCRC32(0u, string1, sizeof(string1) - 1u);

    crc32 = GetCRC32(crc32, string2, sizeof(string2) - 1u);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((strin1_plus_string2_crc32)), (UNITY_INT)(UNITY_INT32)((crc32)), (("failed two strings crc32")), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_HEX32)



                                                               ;



    crc32 = GetCRC32(0u, string2, sizeof(string2) - 1u);

    crc32 = GetCRC32(crc32, string1, sizeof(string1) - 1u);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((strin2_plus_string1_crc32)), (UNITY_INT)(UNITY_INT32)((crc32)), (("failed two strings crc32")), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_HEX32)



                                                               ;

}
