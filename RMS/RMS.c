/* Includes ----------------------------------------------------------------- */
#include "RMS.h"


/* Private function prototypes ---------------------------------------------- */
static float CalcBuffSumSquare(const void *const buff,
                               const uint32_t buff_size,
                               const rms_buff_data_type_t data_type);

static float CalcRMS(const float sum_square, const uint32_t sum_square_size);

static float GetBuffVal(const void *const buff,
                        const uint32_t index,
                        const rms_buff_data_type_t data_type);




/* Exported functions ------------------------------------------------------- */
/**
 * Return RMS of buffer
 * @param  buff      pointer to buffer
 * @param  buff_size buffer size
 * @param  data_type buffer data type
 * @return           RMS
 */
float GetBuffRMS(const void *const buff,
                 const uint32_t buff_size,
                 const rms_buff_data_type_t data_type) {
    float sum_square;
    float rms;

    sum_square = CalcBuffSumSquare(buff, buff_size, data_type);
    rms = CalcRMS(sum_square, buff_size);

    return rms;
}




/* Private functions -------------------------------------------------------- */
/**
 * Calculate sum of squares from buffer
 * @param  buff      pointer to buffer
 * @param  buff_size buffer size
 * @param  data_type buffer data type
 * @return           sum of squres
 */
static float CalcBuffSumSquare(const void *const buff,
                               const uint32_t buff_size,
                               const rms_buff_data_type_t data_type) {
    float sum_square = 0.0f;
    float current_val;

    for (uint32_t i = 0u; i < buff_size; ++i) {
        current_val = GetBuffVal(buff, i, data_type);
        sum_square += current_val * current_val;
    }

    return sum_square;
}


/**
 * Calculate RMS from sum of squares and it's size
 * @param  sum_square      sum of squares
 * @param  sum_square_size num of elements in sum of squares
 * @return                 RMS
 */
static float CalcRMS(const float sum_square, const uint32_t sum_square_size) {
    float rms = 0.0f;

    if (sum_square_size > 0u) {
        if (sum_square_size >= 0.0f) {
            rms = sqrt(sum_square / sum_square_size);
        }
    }

    return rms;
}


/**
 * Get value from buffer and cast it to float data type
 * @param  buff      pointer to buffer
 * @param  index     index of element in buffer
 * @param  data_type buffer data type
 * @return           buffer's value
 */
static float GetBuffVal(const void *const buff,
                        const uint32_t index,
                        const rms_buff_data_type_t data_type) {
    float buff_val = 0.0f;

    switch (data_type) {
        case UINT8_T:
            buff_val = (float)(*((uint8_t *)buff + index));
            break;
        case UINT16_T:
            buff_val = (float)(*((uint16_t *)buff + index));
            break;
        case UINT32_T:
            buff_val = (float)(*((uint32_t *)buff + index));
            break;
        case FLOAT_T:
            buff_val = (float)(*((float *)buff + index));
            break;
        default:
            break;
    }

    return buff_val;
}
