/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CRC32_H
#define CRC32_H


/* Exported functions --------------------------------------------------------*/
unsigned int GetCRC32(const unsigned int init_crc32,
                      const unsigned char *const data,
                      const unsigned int len);


#endif /* CRC32_H */
