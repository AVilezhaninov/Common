/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CRC32_H
#define CRC32_H


/* Includes ------------------------------------------------------------------*/
#include <stdint.h>


/* Exported types ------------------------------------------------------------*/
typedef uint32_t crc32_t;


/* Exported functions --------------------------------------------------------*/
crc32_t GetCRC32(const crc32_t initial_crc32,
                 const unsigned char *const data,
                 const unsigned int len);


#endif /* CRC32_H */
