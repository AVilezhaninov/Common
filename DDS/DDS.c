/* Includes ------------------------------------------------------------------*/
#include "DDS.h"


/* Private defines -----------------------------------------------------------*/
#define DDS_OUT_FREQUENCY_HZ    1000u
#define DDS_FCLK_HZ             10000u
#define POW_2_32                4294967296u


/* Private variables ---------------------------------------------------------*/
static unsigned int DDS_acc_phase;


/* Private constantce --------------------------------------------------------*/
static const unsigned int DDS_increment = (DDS_OUT_FREQUENCY_HZ * POW_2_32) / DDS_FCLK_HZ;

/* Sin table */
static const int DDS_sin_table[] = {
    0, 3, 6, 9, 12, 16, 19, 22, 25, 28, 31, 34, 37, 40, 43, 46, 49, 51,
    54, 57, 60, 63, 65, 68, 71, 73, 76, 78, 81, 83, 85, 88, 90, 92, 94,
    96, 98, 100, 102, 104, 106, 107, 109, 111, 112, 113, 115, 116, 117,
    118, 120, 121, 122, 122, 123, 124, 125, 125, 126, 126, 126, 127, 127,
    127, 127, 127, 127, 127, 126, 126, 126, 125, 125, 124, 123, 122, 122,
    121, 120, 118, 117, 116, 115, 113, 112, 111, 109, 107, 106, 104, 102,
    100, 98, 96, 94, 92, 90, 88, 85, 83, 81, 78, 76, 73, 71, 68, 65, 63,
    60, 57, 54, 51, 49, 46, 43, 40, 37, 34, 31, 28, 25, 22, 19, 16, 12,
    9, 6, 3, 0, -3, -6, -9, -12, -16, -19, -22, -25, -28, -31, -34, -37,
    -40, -43, -46, -49, -51, -54, -57, -60, -63, -65, -68, -71, -73, -76,
    -78, -81, -83, -85, -88, -90, -92, -94, -96, -98, -100, -102, -104,
    -106, -107, -109, -111, -112, -113, -115, -116, -117, -118, -120,
    -121, -122, -122, -123, -124, -125, -125, -126, -126, -126, -127,
    -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125,
    -124, -123, -122, -122, -121, -120, -118, -117, -116, -115, -113,
    -112, -111, -109, -107, -106, -104, -102, -100, -98, -96, -94, -92,
    -90, -88, -85, -83, -81, -78, -76, -73, -71, -68, -65, -63, -60, -57,
    -54, -51, -49, -46, -43, -40, -37, -34, -31, -28, -25, -22, -19, -16,
    -12, -9, -6, -3
};



/* Exported functions --------------------------------------------------------*/
int DDS_GetSinVal(void) {
    int DDS_val;

    DDS_val = DDS_sin_table[(DDS_acc_phase & 0xFF000000u) >> 24u];
    DDS_acc_phase += DDS_increment;

    return DDS_val;
}
