/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef RMS_H
#define RMS_H


/* Includes ----------------------------------------------------------------- */
#include <stdint.h>
#include <math.h>


/* Exported types definition ------------------------------------------------ */
typedef enum {UINT8_T, UINT16_T, UINT32_T, FLOAT_T} rms_buff_data_type_t;


/* Exported functions prototypes -------------------------------------------- */
float GetBuffRMS(const void *const buff,
                 const uint32_t buff_size,
                 const rms_buff_data_type_t data_type);


#endif /* RMS_H */
