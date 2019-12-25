
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/flash.h"
#include "driverlib/eeprom.h"


int main( ) {

  uint32_t pui32Data[2];
  uint32_t pui32Read[2];
  
  pui32Data[0] = 0x00000001 ; 
  pui32Data[2] = 0x00000002 ; 
  
  SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN) ;
  SysCtlDelay(20000000);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0);
  EEPROMInit();
  
  
  EEPROMMassErase();

  EEPROMRead(pui32Read , 0x0 , sizeof(pui32Read));
             
  EEPROMProgram(pui32Data , 0x0 , sizeof(pui32Data));
  
  EEPROMRead(pui32Read , 0x0 , sizeof(pui32Read));
  while(1)
  {}
}