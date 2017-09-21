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

#pragma once



#define DEVICE_TARGET AT91
#define DEVICE_NAME "G400"
#define DEVICE_MANUFACTURER "GHI Electronics, LLC"
#define DEVICE_VERSION ((0x0000ULL << 32) | (0x0006ULL << 16) | (0x0000ULL << 0))

#define USB_DEBUGGER_VENDOR_ID 0x1B9F
#define USB_DEBUGGER_PRODUCT_ID 0x0110

#define UART_DEBUGGER_INDEX 0
#define USB_DEBUGGER_INDEX 0

#define DEBUGGER_SELECTOR_PIN PIN(A, 25)
#define DEBUGGER_SELECTOR_PULL TinyCLR_Gpio_PinDriveMode::InputPullUp
#define DEBUGGER_SELECTOR_USB_STATE TinyCLR_Gpio_PinValue::High

#define RUN_APP_PIN PIN(A, 4)
#define RUN_APP_PULL TinyCLR_Gpio_PinDriveMode::InputPullUp
#define RUN_APP_STATE TinyCLR_Gpio_PinValue::High

#define RAM_BOOTLOADER_HOLD_ADDRESS         0x266FFFF0
#define RAM_BOOTLOADER_HOLD_VALUE           0x8DB4DA67

#define AT91_AHB_CLOCK_HZ               (400*1000*1000) // 400 MHz
#define AT91_SYSTEM_PERIPHERAL_CLOCK_HZ          (AT91_AHB_CLOCK_HZ / 3) // 133MHz (Peripheral Clock - MCK)

#define SRAM_MEMORY_Base                    0x00300000
#define SRAM_MEMORY_Size                    (32*1024)
#define SDRAM_MEMORY_Base                   0x20000000
#define SDRAM_MEMORY_Size                   (128*1024*1024)

#define FLASH_MEMORY_Base                   0x00000000
#define FLASH_MEMORY_Size                   0x00420000

#define INCLUDE_ADC
#define AT91_ADC_PINS                     { { PIN(B,11), PS(D) }, { PIN(B,12), PS(D) }, { PIN(B,13), PS(D) }, { PIN(B,14), PS(D) }, { PIN(B,15), PS(D) }, { PIN(B,16), PS(D) }, { PIN(A,17), PS(D) }, { PIN(B,6), PS(D) }, { PIN(B,7), PS(D) }, { PIN(B,8), PS(D) }, { PIN(B,9), PS(D) }, { PIN(B,10), PS(D) } }

#define INCLUDE_I2C
#define AT91_I2C_SCL_PINS                  { { PIN(A,31),  PS(A) } }
#define AT91_I2C_SDA_PINS                  { { PIN(A,30),  PS(A) } }

#define INCLUDE_PWM
#define MAX_PWM_PER_CONTROLLER            1
#define TOTAL_PWM_CONTROLLER              4
#define AT91_PWM_PINS   { { { PIN(C,18),  PS(C) } }, { { PIN(C,19),  PS(C) } }, { { PIN(C,20),  PS(C) } }, { { PIN(C,21),  PS(C) } } }

#define INCLUDE_SPI
#define TOTAL_SPI_CONTROLLERS              2
#define AT91_SPI_MISO_PINS                { { PIN(A,11),  PS(A) }, { PIN(A,21),  PS(B) } }
#define AT91_SPI_MOSI_PINS                { { PIN(A,12),  PS(A) }, { PIN(A,22),  PS(B) } }
#define AT91_SPI_SCLK_PINS                { { PIN(A,13),  PS(A) }, { PIN(A,13),  PS(B) } }

#define INCLUDE_UART
#define TOTAL_UART_CONTROLLERS            6
#define AT91_UART_TX_BUFFER_SIZE          (16*1024)
#define AT91_UART_RX_BUFFER_SIZE          (16*1024)
#define AT91_UART_TX_PINS                 { { PIN(A, 9),  PS(A) } , { PIN(A, 0),  PS(A) }, { PIN(A, 5),  PS(A) } , { PIN(A, 7),  PS(A) } , { PIN(C, 8),  PS(C) } , { PIN(C,16),  PS(C) } }
#define AT91_UART_RX_PINS                 { { PIN(A,10),  PS(A) } , { PIN(A, 1),  PS(A) }, { PIN(A, 6),  PS(A) } , { PIN(A, 8),  PS(A) } , { PIN(C, 9),  PS(C) } , { PIN(C,17),  PS(C) } }
#define AT91_UART_RTS_PINS                { { PIN_NONE , PS_NONE }, { PIN(A, 2),  PS(A) }, { PIN_NONE , PS_NONE }, { PIN_NONE , PS_NONE }, { PIN_NONE , PS_NONE }, { PIN_NONE , PS_NONE } }
#define AT91_UART_CTS_PINS                { { PIN_NONE , PS_NONE }, { PIN(A, 3),  PS(A) }, { PIN_NONE , PS_NONE }, { PIN_NONE , PS_NONE }, { PIN_NONE , PS_NONE }, { PIN_NONE , PS_NONE } }

#define INCLUDE_USBCLIENT
#define TOTAL_USB_CONTROLLER            1
#define AT91_USB_QUEUE_SIZE             16


#define INCLUDE_DISPLAY


#if 1

// #define PLATFORM_ARM_DEFINED

// Macro
//#define GLOBAL_LOCK(x)             AT91_SmartPtr_IRQ x
// #define DISABLE_INTERRUPTS()       AT91_SmartPtr_IRQ::ForceDisabled()
// #define ENABLE_INTERRUPTS()        AT91_SmartPtr_IRQ::ForceEnabled()

// #if defined(_DEBUG)
// #define ASSERT(x)                  while (!(x))
// #define ASSERT_IRQ_MUST_BE_OFF()   ASSERT(!AT91_SmartPtr_IRQ::GetState())
// #define ASSERT_IRQ_MUST_BE_ON()    ASSERT( AT91_SmartPtr_IRQ::GetState())
// #else
// #define ASSERT_IRQ_MUST_BE_OFF()
// #define ASSERT_IRQ_MUST_BE_ON()
// #endif

// #define INTERRUPT_START         AT91_Interrupt_Started();
// #define INTERRUPT_END           AT91_Interrupt_Ended();

// Device
#define HAL_SYSTEM_NAME "G400"


// Macro
#define PORT_PIN(port,pin)                   (((int)port)*32 + (pin))
#define _P(port, pin)                        PORT_PIN(GPIO_PORT##port, pin)
#define _P_NONE_                             GPIO_PIN_NONE
#define GPIO_PORTA                           0
#define GPIO_PORTB                           1
#define GPIO_PORTC                           2
#define GPIO_PORTD                           3

// GPIO
#define TOTAL_GPIO_PORT                      (GPIO_PORTD + 1)
#define TOTAL_GPIO_PINS                      (TOTAL_GPIO_PORT*32)


// ADC
//#define TOTAL_ADC_CONTROLLERS             12
//#define AT91_ADC_PINS                     {_P(B,11),_P(B,12),_P(B,13),_P(B,14),_P(B,15),_P(B,16),_P(A,17),_P(B,6),_P(B,7),_P(B,8),_P(B,9),_P(B,10)}
//#define AT91_ADC_ALT_MODE                 {AT91_Gpio_PeripheralSelection::PeripheralD, AT91_Gpio_PeripheralSelection::PeripheralD, AT91_Gpio_PeripheralSelection::PeripheralD, AT91_Gpio_PeripheralSelection::PeripheralD, AT91_Gpio_PeripheralSelection::PeripheralD, AT91_Gpio_PeripheralSelection::PeripheralD, AT91_Gpio_PeripheralSelection::PeripheralD, AT91_Gpio_PeripheralSelection::PeripheralD, AT91_Gpio_PeripheralSelection::PeripheralD, AT91_Gpio_PeripheralSelection::PeripheralD, AT91_Gpio_PeripheralSelection::PeripheralD, AT91_Gpio_PeripheralSelection::PeripheralD}

// I2C
// #define AT91_I2C_SCL_PIN                  _P(A,31)
// #define AT91_I2C_SDA_PIN                  _P(A,30)
// #define AT91_I2C_SCL_ALT_MODE             AT91_Gpio_PeripheralSelection::PeripheralA
// #define AT91_I2C_SDA_ALT_MODE             AT91_Gpio_PeripheralSelection::PeripheralA

// PWM
// #define MAX_PWM_PER_CONTROLLER            1
// #define TOTAL_PWM_CONTROLLER              4
// #define AT91_PWM                          { {PWM_CHANNEL_MODE_REGISTER(0), PWM_DUTY_REGISTER(0), PWM_CHANNEL_UPDATE_REGISTER(0), {_P(C,18)}, {AT91_Gpio_PeripheralSelection::PeripheralC}, { false }, 0.0, {0.0} } ,\
                                            // {PWM_CHANNEL_MODE_REGISTER(1), PWM_DUTY_REGISTER(1), PWM_CHANNEL_UPDATE_REGISTER(1), {_P(C,19)}, {AT91_Gpio_PeripheralSelection::PeripheralC}, { false }, 0.0, {0.0} } ,\
                                            // {PWM_CHANNEL_MODE_REGISTER(2), PWM_DUTY_REGISTER(2), PWM_CHANNEL_UPDATE_REGISTER(2), {_P(C,20)}, {AT91_Gpio_PeripheralSelection::PeripheralC}, { false }, 0.0, {0.0} } ,\
                                            // {PWM_CHANNEL_MODE_REGISTER(3), PWM_DUTY_REGISTER(3), PWM_CHANNEL_UPDATE_REGISTER(3), {_P(C,21)}, {AT91_Gpio_PeripheralSelection::PeripheralC}, { false }, 0.0, {0.0} } }
// SPI


// UART

// Debug
#define DEBUG_TEXT_PORT                      USB1
#define STDIO                                USB1
#define DEBUGGER_PORT                        USB1
#define MESSAGING_PORT                       USB1

#define LMODE_PIN                       	_P(A,25)
#define LMODE_USB_STATE                 	TinyCLR_Gpio_PinValue::High

// Loader
#define RUNAPP_PIN                          _P(A,4)
#define RUNAPP_STATE                        TinyCLR_Gpio_PinValue::High

#define UART_DEBUGGER_INDEX                 0
#define USB_DEBUGGER_INDEX                  0

// #define RAM_BOOTLOADER_HOLD_ADDRESS         0x266FFFF0
// #define RAM_BOOTLOADER_HOLD_VALUE           0x8DB4DA67

// OEM information
#define OEM_STRING                          "GHI Electronics, LLC\0"
#define OEM_VERSION_MAJOR                   0
#define OEM_VERSION_MINOR                   6
#define OEM_VERSION_PATCH                   0

#define INCLUDE_GPIO



#include <AT91.h>

#endif