// Copyright GHI Electronics, LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _DEVICE_EMX_H_
#define _DEVICE_EMX_H_


#define DEVICE_TARGET LPC24
#define DEVICE_NAME "EMX"
#define DEVICE_MANUFACTURER "GHI Electronics, LLC"
#define DEVICE_VERSION ((0x0000ULL << 32) | (0x0006ULL << 16) | (0x0000ULL << 0))

#define USB_DEBUGGER_VENDOR_ID 0x1B9F
#define USB_DEBUGGER_PRODUCT_ID 0x0110

#define UART_DEBUGGER_INDEX 0
#define USB_DEBUGGER_INDEX 0

#define DEBUGGER_SELECTOR_PIN PIN(3, 23)
#define DEBUGGER_SELECTOR_PULL TinyCLR_Gpio_PinDriveMode::InputPullDown
#define DEBUGGER_SELECTOR_USB_STATE TinyCLR_Gpio_PinValue::Low

#define RUN_APP_PIN PIN(0, 4)
#define RUN_APP_PULL TinyCLR_Gpio_PinDriveMode::InputPullUp
#define RUN_APP_STATE TinyCLR_Gpio_PinValue::High

#define RAM_BOOTLOADER_HOLD_ADDRESS 0xA0FFFFF8
#define RAM_BOOTLOADER_HOLD_VALUE 0xB53D0238

#define SYSTEM_CLOCK_HZ 18000000
#define LPC24_AHB_CLOCK_HZ 72000000

#define INCLUDE_ADC
#define LPC24_ADC_PINS { { PIN(0,23), PF(1) }, { PIN(0,24), PF(1) }, { PIN(0,25), PF(1) }, { PIN(0,26), PF(1) }, { PIN_NONE, PF(0) }, { PIN(1,31), PF(3) }, { PIN(0,12), PF(3) }, { PIN(0,13), PF(3) } }

#define INCLUDE_DAC
#define LPC24_DAC_PINS { { PIN(0,26), PF(2)} }

#define INCLUDE_I2C
#define LPC24_I2C_SCL_PINS { { PIN(0, 28), PF(1) } }
#define LPC24_I2C_SDA_PINS { { PIN(0, 27), PF(1) } }

#define INCLUDE_PWM
#define LPC24_PWM_PINS  { { { PIN(3, 16), PF(2) }, { PIN(3, 17), PF(2) }, { PIN_NONE, PF(0) }, { PIN_NONE, PF(0) }, { PIN_NONE, PF(0) }, { PIN_NONE  , PF(0) } }, { { PIN(3, 24), PF(3) }, { PIN_NONE  , PF(0) }, { PIN(3, 26), PF(3) }, { PIN(3, 27), PF(3) }, { PIN_NONE, PF(0) }, { PIN(3, 29), PF(3) } } }

#if 0
#define PLATFORM_ARM_DEFINED

// Macro
#define GLOBAL_LOCK(x)             LPC24_SmartPtr_IRQ x
#define DISABLE_INTERRUPTS()       LPC24_SmartPtr_IRQ::ForceDisabled()
#define ENABLE_INTERRUPTS()        LPC24_SmartPtr_IRQ::ForceEnabled()

#if defined(_DEBUG)
#define ASSERT(x)                  while (!(x))
#define ASSERT_IRQ_MUST_BE_OFF()   ASSERT(!LPC24_SmartPtr_IRQ::GetState())
#define ASSERT_IRQ_MUST_BE_ON()    ASSERT( LPC24_SmartPtr_IRQ::GetState())
#else
#define ASSERT_IRQ_MUST_BE_OFF()
#define ASSERT_IRQ_MUST_BE_ON()
#endif

#define INTERRUPT_START         LPC24_Interrupt_Started();
#define INTERRUPT_END           LPC24_Interrupt_Ended();

// Device
#define HAL_SYSTEM_NAME "EMX"





// external Memory - Flash
#define EXT_FLASH_MEMORY_Base                0x80000000
#define EXT_FLASH_MEMORY_Size                0x00400000 // 4MB ext flash
#define EXT_SDRAM_MEMORY_Base                0xA0000000
#define EXT_SDRAM_MEMORY_Size                0x01000000 // 16MB ext ram
#endif

// Macro
#define PORT_PIN(port,pin)                   (((int)port)*32 + (pin))
#define _P(port, pin)                        PORT_PIN(GPIO_PORT##port, pin)
#define _P_NONE_                             PIN_NONE
#define GPIO_PORT0                           0
#define GPIO_PORT1                           1
#define GPIO_PORT2                           2
#define GPIO_PORT3                           3
#define GPIO_PORT4                           4


// GPIO
#define TOTAL_GPIO_PORT                      (GPIO_PORT4 + 1)
#define TOTAL_GPIO_PINS                      (TOTAL_GPIO_PORT*32)

// USBC
#define TOTAL_USB_CONTROLLER            1
#define USB_MAX_QUEUES                  16
#define USB_VENDOR_ID                   0x1B9F
#define USB_PRODUCT_ID                  0x0110
#define USB_MANUFACTURER_NAME           {'G', 'H', 'I', ' ', 'E', 'l', 'e', 'c', 't', 'r', 'o', 'n', 'i', 'c', 's', ',', ' ', 'L', 'L', 'C'}
#define USB_PRODUCT_NAME                {'E', 'M', 'X'}
#define USB_DISPLAY_NAME                USB_PRODUCT_NAME
#define USB_FRIENDLY_NAME               USB_PRODUCT_NAME

// UART
#define TOTAL_UART_CONTROLLERS               4
#define LPC24_UART_TX_BUFFER_SIZE           (16*1024)
#define LPC24_UART_RX_BUFFER_SIZE           (16*1024)

// ADC
//#define TOTAL_ADC_CONTROLLERS               8
//#define LPC24_ADC_PINS                     {_P(0,23),_P(0,24),_P(0,25),_P(0,26),_P_NONE_,_P(1,31),_P(0,12),_P(0,13)}
//#define LPC24_ADC_ALT_MODE                 {LPC24_Gpio_PinFunction::PinFunction1, LPC24_Gpio_PinFunction::PinFunction1, LPC24_Gpio_PinFunction::PinFunction1, LPC24_Gpio_PinFunction::PinFunction1, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction3}

// DAC
// #define TOTAL_DAC_CONTROLLERS                1
// #define LPC24_DAC_PINS                     {_P(0,26)}
// #define LPC24_DAC_ALT_MODE                 {LPC24_Gpio_PinFunction::PinFunction2}

// I2C
// #define LPC24_I2C_PCLK_KHZ                 SYSTEM_CLOCK_HZ/1000
// #define LPC24_I2C_SCL_PIN                  _P(0,28)
// #define LPC24_I2C_SDA_PIN                  _P(0,27)
// #define LPC24_I2C_SCL_ALT_MODE             LPC24_Gpio_PinFunction::PinFunction1
// #define LPC24_I2C_SDA_ALT_MODE             LPC24_Gpio_PinFunction::PinFunction1

// PWM
// #define LPC24_PWM_PCLK                     (SYSTEM_CLOCK_HZ)
// #define LPC24_PWM                           {   { 0 ,  {0x0, 0x0, 0x0, 0x0, 0x0, 0x0} , {0x0, 0x1, 0x2, 0x3, 0x4, 0x5 } , { _P(3, 16), _P(3, 17), _P_NONE_ , _P_NONE_ , _P_NONE_ , _P_NONE_},   {LPC24_Gpio_PinFunction::PinFunction2, LPC24_Gpio_PinFunction::PinFunction2, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction3},  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {PWM0MR1, PWM0MR2, PWM0MR3, PWM0MR4, PWM0MR5, PWM0MR6 }, { false, false, false, false, false, false }, 0.0, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}  } ,\
                                                // { 1 ,  {0x1, 0x1, 0x1, 0x1, 0x1, 0x1} , {0x0, 0x1, 0x2, 0x3, 0x4, 0x5 } , { _P(3, 24), _P_NONE_ , _P(3, 26), _P(3, 27), _P_NONE_ , _P(3, 29)},  {LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction3},  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, {PWM1MR1, PWM1MR2, PWM1MR3, PWM1MR4, PWM1MR5, PWM1MR6 }, { false, false, false, false, false, false }, 0.0, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}  } }
// SPI
#define TOTAL_SPI_CONTROLLERS               2
#define LPC24_SPI_PCLK_KHZ                 (LPC24_AHB_CLOCK_HZ/1000)
#define LPC24_SPI_MISO_PINS                {_P(0,17),_P(0,8)}
#define LPC24_SPI_MOSI_PINS                {_P(0,18),_P(0,9)}
#define LPC24_SPI_CLK_PINS                 {_P(0,15),_P(0,7)}
#define LPC24_SPI_MISO_ALT_MODE            {LPC24_Gpio_PinFunction::PinFunction2, LPC24_Gpio_PinFunction::PinFunction2}
#define LPC24_SPI_MOSI_ALT_MODE            {LPC24_Gpio_PinFunction::PinFunction2, LPC24_Gpio_PinFunction::PinFunction2}
#define LPC24_SPI_CLK_ALT_MODE             {LPC24_Gpio_PinFunction::PinFunction2, LPC24_Gpio_PinFunction::PinFunction2}

// UARTs
#define LPC24_UART_PCLK                   LPC24_AHB_CLOCK_HZ
//UART EMX
#define LPC24_UART_TX_PINS              {_P(0,2) , _P(2,0) , _P(4,22), _P(0,25) }
#define LPC24_UART_RX_PINS              {_P(0,3) , _P(2,1) , _P(4,23), _P(0,26)  }
#define LPC24_UART_RTS_PINS             {_P_NONE_, _P(3,30), _P_NONE_, _P_NONE_ }
#define LPC24_UART_CTS_PINS             {_P_NONE_, _P(3,18), _P_NONE_, _P_NONE_ }
#define LPC24_UART_TX_ALT_MODE          {LPC24_Gpio_PinFunction::PinFunction1, LPC24_Gpio_PinFunction::PinFunction2, LPC24_Gpio_PinFunction::PinFunction2,LPC24_Gpio_PinFunction::PinFunction3}
#define LPC24_UART_RX_ALT_MODE          {LPC24_Gpio_PinFunction::PinFunction1, LPC24_Gpio_PinFunction::PinFunction2, LPC24_Gpio_PinFunction::PinFunction2,LPC24_Gpio_PinFunction::PinFunction3}
#define LPC24_UART_RTS_ALT_MODE         {LPC24_Gpio_PinFunction::PinFunction0, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction0,LPC24_Gpio_PinFunction::PinFunction0}
#define LPC24_UART_CTS_ALT_MODE         {LPC24_Gpio_PinFunction::PinFunction0, LPC24_Gpio_PinFunction::PinFunction3, LPC24_Gpio_PinFunction::PinFunction0,LPC24_Gpio_PinFunction::PinFunction0}

// Debug
#define DEBUG_TEXT_PORT                      USB1
#define STDIO                                USB1
#define DEBUGGER_PORT                        USB1
#define MESSAGING_PORT                       USB1

#define LMODE_PIN                       	_P(3,23)
#define LMODE_USB_STATE                 	TinyCLR_Gpio_PinValue::Low

// Loader
#define RUNAPP_PIN                          _P(0,4)
#define RUNAPP_STATE                        TinyCLR_Gpio_PinValue::High

#define UART_DEBUGGER_INDEX                 0
#define USB_DEBUGGER_INDEX                  0

// #define RAM_BOOTLOADER_HOLD_ADDRESS         (EXT_SDRAM_MEMORY_Base + EXT_SDRAM_MEMORY_Size - 8)
// #define RAM_BOOTLOADER_HOLD_VALUE           0xB53D0238

// OEM information
#define OEM_STRING                          "GHI Electronics, LLC\0"
#define OEM_VERSION_MAJOR                   0
#define OEM_VERSION_MINOR                   6
#define OEM_VERSION_PATCH                   0

#define INCLUDE_ADC
#define INCLUDE_DAC
#define INCLUDE_GPIO
#define INCLUDE_I2C
#define INCLUDE_PWM
#define INCLUDE_SPI
#define INCLUDE_UART
#define INCLUDE_USBCLIENT
#define INCLUDE_DISPLAY

//#define TARGET LPC24

#include <LPC24.h>

#endif