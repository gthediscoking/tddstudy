#ifndef D_LedDriver_H
#define D_LedDriver_H
#include <stdint.h>

/**********************************************************
 *
 * LedDriver is responsible for ...
 *
 **********************************************************/

void LedDriver_Create(uint16_t * address);
void LedDriver_Destroy(void);

#endif  /* D_FakeLedDriver_H */
