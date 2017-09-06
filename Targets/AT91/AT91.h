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

#include <stdio.h>
#include <string.h>

#include <defines.h>
#include <TinyCLR.h>
#include <DeviceSelector.h>

//
//  PERIPHERAL ID DEFINITIONS FOR AT91SAM9X35
//
#define AT91C_ID_FIQ		((unsigned int)  0) // Advanced Interrupt Controller (FIQ)
#define AT91C_ID_SYS		((unsigned int)  1) // System Interrupt
#define AT91C_ID_PIOA_PIOB	((unsigned int)  2) // Parallel IO Controller A and B
#define AT91C_ID_PIOC_PIOD	((unsigned int)  3) // Parallel IO Controller C and D
#define AT91C_ID_SMD		((unsigned int)  4) // SMD Soft Modem - not yet supported
#define AT91C_ID_USART0		((unsigned int)  5) // USART 0
#define AT91C_ID_USART1		((unsigned int)  6) // USART 1
#define AT91C_ID_USART2		((unsigned int)  7) // USART 2
#define AT91C_ID_TWI		AT91C_ID_TWI0       // only support one I2C
#define AT91C_ID_TWI0		((unsigned int)  9) // Two-Wire Interface 0
#define AT91C_ID_TWI1		((unsigned int) 10) // Two-Wire Interface 1
#define AT91C_ID_TWI2		((unsigned int) 11) // Two-Wire Interface 2
#define AT91C_ID_HSMCI0		((unsigned int) 12) // High Speed Multimedia Card Interface 0
#define AT91C_ID_SPI0		((unsigned int) 13) // Serial Peripheral Interface
#define AT91C_ID_SPI1		((unsigned int) 14) // Serial Peripheral Interface
#define AT91C_ID_UART0		((unsigned int) 15) // UART 0
#define AT91C_ID_UART1		((unsigned int) 16) // UART 1
#define AT91C_ID_TC0_TC1	((unsigned int) 17) // Timer Counter 0, 1, 2, 3, 4, 5
#define AT91C_ID_PWM		((unsigned int) 18) // Pulse Width Modulation Controller
#define AT91C_ID_ADC		((unsigned int) 19) // ADC Controller
#define AT91C_ID_DMAC0		((unsigned int) 20) // DMA Controller 0
#define AT91C_ID_DMAC1		((unsigned int) 21) // DMA Controller 1
#define AT91C_ID_UHPHS		((unsigned int) 22) // USB Host High Speed
#define AT91C_ID_UDPHS		((unsigned int) 23) // USB Device High Speed
#define AT91C_ID_EMAC		((unsigned int) 24) // Ethernet MAC
#define AT91C_ID_LCDC		((unsigned int) 25) // LCD Controller
#define AT91C_ID_HSMCI1		((unsigned int) 26) // High Speed Multimedia Card Interface 1
#define AT91C_ID_SSC		((unsigned int) 28) // Synchronous Serial Controller
#define AT91C_ID_CAN0		((unsigned int) 29) // CAN Controller 0
#define AT91C_ID_CAN1		((unsigned int) 30) // CAN Controller 1
#define AT91C_ID_IRQ0		((unsigned int) 31) // Advanced Interrupt Controller (IRQ0)

//
// BASE ADDRESS DEFINITIONS FOR AT91SAM9RL64
//
#define AT91C_BASE_SYS          0xFFFFE600 // (SYS) Base Address
#define AT91C_BASE_DMAC0        0xFFFFEC00 // Hydra original address 0xFFFFE600 // (DMAC)Address						- Not same Memory Address
#define AT91C_BASE_DDRS         0xFFFFE800 // (DDRS) Address
#define AT91C_BASE_SDRAMC       0xFFFFEA00 // (SDRAMC) Base Address
#define AT91C_BASE_SMC          0xFFFFEC00 // (SMC) Base Address
#define AT91C_BASE_MATRIX       0xFFFFEE00 // (MATRIX) Base Address				- Not same Memory Address
#define AT91C_BASE_AIC          0xFFFFF000 // (AIC) Base Address
#define AT91C_BASE_PDC_DBGU     0xFFFFF300 // (PDC_DBGU) Base Address
#define AT91C_BASE_DBGU         0xFFFFF200 // (DBGU) Base Address
#define AT91C_BASE_PIOA         0xFFFFF400 // (PIOA) Base Address
#define AT91C_BASE_PIOB         0xFFFFF600 // (PIOB) Base Address
#define AT91C_BASE_PIOC         0xFFFFF800 // (PIOC) Base Address
#define AT91C_BASE_PIOD         0xFFFFFA00 // (PIOD) Base Address
#define AT91C_BASE_CKGR         0xFFFFFC20 // (CKGR) Base Address
#define AT91C_BASE_PMC          0xFFFFFC00 // (PMC) Base Address
#define AT91C_BASE_RSTC         0xFFFFFE00 // (RSTC) Base Address				- Not same Memory Address
#define AT91C_BASE_RSTC_SR      0xFFFFFD04
#define AT91C_BASE_RSTC_MR      0xFFFFFD08
#define AT91C_BASE_SHDWC        0xFFFFFD10 // (SHDWC) Base Address
#define AT91C_BASE_RTTC         	0xFFFFFD20 // (RTTC) Base Address
#define AT91C_BASE_PITC         	0xFFFFFE30 // (PITC) Base Address
#define AT91C_BASE_WDTC         	0xFFFFFE40 // (WDTC) Base Address
#define AT91C_BASE_SCKCR        	0xFFFFFE50 // (SCKCR) Base Address
#define AT91C_BASE_GPBR         	0xFFFFFD60 // (GPBR) Base Address
#define AT91C_BASE_TC0         		0xF8008000 // Hydra original address 0xFFFA0000 // (TC0) Base Address
#define AT91C_BASE_TC1          	0xFFFA0040 // (TC1) Base Address
#define AT91C_BASE_TC2          	0xFFFA0080 // (TC2) Base Address
#define AT91C_BASE_TCB0         	0xFFFA0000 // (TCB0) Base Address
#define AT91C_BASE_PDC_MCI      	0xFFFA4100 // (PDC_MCI) Base Address
#define AT91C_BASE_MCI          	0xF0008000 // Hydra original address 0xFFFA4000 // (MCI) Base Address
#define AT91C_BASE_TWI0         	0xF8010000 // Hydra original address 0xFFFA8000 // (TWI1) Base Address
#define AT91C_BASE_TWI1         	0xF8014000 // Hydra original address 0xFFFAC000 // (TWI2) Base Address
#define AT91C_BASE_TWI2         	0xF8018000 // (TWI3) Base Address
#define AT91C_BASE_TWI          	AT91C_BASE_TWI0 // Support one I2C controller only
#define AT91C_BASE_USART0          	0xF801C000 // Hydra original address 0xFFFB0000 // (US0) Base Address				- Not same Memory Address
#define AT91C_BASE_USART1          	0xF8020000 // Hydra original address 0xFFFB4000 // (US1) Base Address				- Not same Memory Address
#define AT91C_BASE_USART2          	0xF8024000 // Hydra original address 0xFFFB8000 // (US2) Base Address				- Not same Memory Address
#define AT91C_BASE_UART0			0xF8040000
#define AT91C_BASE_UART1			0xF8044000
#define AT91C_BASE_PDC_US3      	0xFFFBC100 // (PDC_US3) Base Address
#define AT91C_BASE_US3          	0xF8008000 // Hydra original address 0xFFFBC000 // (US3) Base Address				- Not same Memory Address
#define AT91C_BASE_PDC_SSC0     	0xFFFC0100 // (PDC_SSC0) Base Address
#define AT91C_BASE_SSC0         	0xFFFC0000 // (SSC0) Base Address
#define AT91C_BASE_PDC_SSC1     	0xFFFC4100 // (PDC_SSC1) Base Address
#define AT91C_BASE_SSC1         	0xFFFC4000 // (SSC1) Base Address
#define AT91C_BASE_PWMC         	0xF8034000 // Hydra original address 0xFFFC8000 // (PWMC) Base Address				- Not same Memory Address
#define AT91C_BASE_PDC_SPI0     	0xFFFCC100 // (PDC_SPI0) Base Address
#define AT91C_BASE_SPI0         	0xF0000000 // (SPI0) Base Address // Hydra original address 0xFFFCC000
#define AT91C_BASE_SPI1         	0xF0004000 // (SPI1) Base Address
#define AT91C_BASE_TSADCC       	0xFFFD0000 // (ADC touch screen) Base Address
#define AT91C_BASE_UDP          	0xF803C000 // 0xFFFD4000 // (UDP) Base Address - Changed on G400
#define AT91C_BASE_AC97         	0xFFFD8000 // (UDP) Base Address
#define AT91C_BASE_ITCM         	0x00100000 // (ITCM) Base Address
#define AT91C_BASE_DTCM         	0x00200000 // (DTCM) Base Address
#define AT91C_BASE_LCDC         	0xF8038000 // Hydra original address 0x00500000 // (LCDC) Base Address
#define AT91C_BASE_UDP_DMA			0x00500000 // Hydra original address 0x00600000 // (UDP DMA) Base Address
#define AT91C_BASE_EMAC				0xF802C000

// RTSC bit defines
#define AT91C_RTSC__PROCRST     0x01         // processor reset bit
#define AT91C_RTSC__PERRST      0x04         // Peripheral reset bit
#define AT91C_RTSC__EXTRST      0x08         // asserts NRST pin
#define AT91C_RSTC__RESET_KEY   0xA5000000   // reset key
#define AT91C_RTSC_SR__SRCMP    (1ul < 17)   // Software Reset Command in progress
#define AT91C_RTSC_SR__NRSTL    (1ul < 16)   // Registers the NRST Pin Level at Master Clock (MCK)
#define AT91C_RTSC_SR__RSTTYP   (7ul <  8)   // Reset Type mask
#define AT91C_RTSC_SR__BODSTS   (1ul <  1)   // Brownout Detection Status
#define AT91C_RTSC_SR__URSTS    (1ul <  0)   // User Reset Status

// SHDWC bit defines
#define AT91C_SHDWC__SHUTDOWN_KEY   0xA5000000   // reset key
#define AT91C_SHDWC__SHDW           0x01         // processor reset bit

struct AT91_PMC {
    static const uint32_t c_Base = AT91C_BASE_PMC;

    /****/ volatile uint32_t PMC_SCER;                // System Clock Enable Register

    /****/ volatile uint32_t PMC_SCDR;                // System Clock Disable Register

    /****/ volatile uint32_t PMC_SCSR;                // System Clock Status Register

    /****/ volatile uint32_t Reserved0[1];            //

    /****/ volatile uint32_t PMC_PCER;                // Peripheral Clock Enable Register

    /****/ volatile uint32_t PMC_PCDR;                // Peripheral Clock Disable Register

    /****/ volatile uint32_t PMC_PCSR;                // Peripheral Clock Status Register

    /****/ volatile uint32_t PMC_CKGR_UCKR;            // UTMI Clock Register

    /****/ volatile uint32_t PMC_CKGR_MOR;            // Main Oscillator Register
    static const    uint32_t CKGR_MOSCEN = (0x1 << 0);       // (CKGR) Main Oscillator Enable
    static const    uint32_t CKGR_OSCBYPASS = (0x1 << 1);       // (CKGR) Main Oscillator Bypass
    static const    uint32_t CKGR_OSCOUNT = (0xFF << 8);      // (CKGR) Main Oscillator Start-up Time


    /****/ volatile uint32_t PMC_CKGR_MCFR;  // Main Clock  Frequency Register
    static const    uint32_t CKGR_MAINF = (0xFFFF << 0);     // (CKGR) Main Clock Frequency
    static const    uint32_t CKGR_MAINRDY = (0x1 << 16);       // (CKGR) Main Clock Ready


    /****/ volatile uint32_t PMC_CKGR_PLLAR;  // PLL Register


    static const    uint32_t CKGR_DIV = (0xFF << 0);     // (CKGR) Divider Selected
    static const    uint32_t CKGR_DIV_0 = (0x0);           // (CKGR) Divider output is 0
    static const    uint32_t CKGR_DIV_BYPASS = (0x1);           // (CKGR) Divider is bypassed
    static const    uint32_t CKGR_PLLCOUNT = (0x3F << 8);     // (CKGR) PLL Counter
    static const    uint32_t CKGR_OUT = (0x3 << 14);     // (CKGR) PLL Output Frequency Range
    static const    uint32_t CKGR_OUT_0 = (0x0 << 14);     // (CKGR) Please refer to the PLL datasheet
    static const    uint32_t CKGR_OUT_1 = (0x1 << 14);     // (CKGR) Please refer to the PLL datasheet
    static const    uint32_t CKGR_OUT_2 = (0x2 << 14);     // (CKGR) Please refer to the PLL datasheet
    static const    uint32_t CKGR_OUT_3 = (0x3 << 14);     // (CKGR) Please refer to the PLL datasheet
    static const    uint32_t CKGR_MUL = (0x7FF << 16);   // (CKGR) PLL Multiplier
    static const    uint32_t CKGR_USBDIV = (0x3 << 28);     // (CKGR) Divider for USB Clocks
    static const    uint32_t CKGR_USBDIV_0 = (0x0 << 28);     // (CKGR) Divider output is PLL clock output
    static const    uint32_t CKGR_USBDIV_1 = (0x1 << 28);     // (CKGR) Divider output is PLL clock output divided by 2
    static const    uint32_t CKGR_USBDIV_2 = (0x2 << 28);     // (CKGR) Divider output is PLL clock output divided by 4

    /****/ volatile uint32_t Reserved1[1];            //

    /****/ volatile uint32_t PMC_MCKR;  // Master Clock Register
    static const    uint32_t PMC_CSS = (0x3 << 0);   //  (PMC) Programmable Clock Selection
    static const    uint32_t PMC_CSS_SLOW_CLK = (0x0);         //  (PMC) Slow Clock is selected
    static const    uint32_t PMC_CSS_MAIN_CLK = (0x1);         //  (PMC) Main Clock is selected
    static const    uint32_t PMC_CSS_PLLA_CLK = (0x2);         //  (PMC) Clock from PLL1 is selected = (SAM9 only);
    static const    uint32_t PMC_CSS_PLL_CLK = (0x3);         //  (PMC) Clock from PLL is selected
    static const    uint32_t PMC_PRES = (0x7 << 2);   //  (PMC) Programmable Clock Prescaler
    static const    uint32_t PMC_PRES_CLK = (0x0 << 2);   //  (PMC) Selected clock
    static const    uint32_t PMC_PRES_CLK_2 = (0x1 << 2);   //  (PMC) Selected clock divided by 2
    static const    uint32_t PMC_PRES_CLK_4 = (0x2 << 2);   //  (PMC) Selected clock divided by 4
    static const    uint32_t PMC_PRES_CLK_8 = (0x3 << 2);   //  (PMC) Selected clock divided by 8
    static const    uint32_t PMC_PRES_CLK_16 = (0x4 << 2);   //  (PMC) Selected clock divided by 16
    static const    uint32_t PMC_PRES_CLK_32 = (0x5 << 2);   //  (PMC) Selected clock divided by 32
    static const    uint32_t PMC_PRES_CLK_64 = (0x6 << 2);   //  (PMC) Selected clock divided by 64
    static const    uint32_t PMC_MDIV = (0x3 << 8);   //  (PMC) Master Clock Division
    static const    uint32_t PMC_MDIV_1 = (0x0 << 8);   //  (PMC) The master clock and the processor clock are the same
    static const    uint32_t PMC_MDIV_2 = (0x1 << 8);   //  (PMC) The processor clock is twice as fast as the master clock
    static const    uint32_t PMC_MDIV_3 = (0x2 << 8);   //  (PMC) The processor clock is four times faster than the master clock

    /****/ volatile uint32_t Reserved3[3];  // TQD: Just a note PMC_USB and PMC_SMD are in here

    /****/ volatile uint32_t PMC_PCKR[2];   // Programmable Clock Register

    /****/ volatile uint32_t Reserved4[6];  //

    /****/ volatile uint32_t PMC_IER;   // Interrupt Enable Register
    static const    uint32_t PMC_MOSCS = (0x1 << 0);       // (PMC) MOSC Status/Enable/Disable/Mask
    static const    uint32_t PMC_LOCKA = (0x1 << 1);       // (PMC) PLL Status/Enable/Disable/Mask =(SAM9 Only);
    static const    uint32_t PMC_LOCK = (0x1 << 2);       // (PMC) PLL Status/Enable/Disable/Mask
    static const    uint32_t PMC_MCKRDY = (0x1 << 3);       // (PMC) MCK_RDY Status/Enable/Disable/Mask
    static const    uint32_t PMC_PCK0RDY = (0x1 << 8);       // (PMC) PCK0_RDY Status/Enable/Disable/Mask
    static const    uint32_t PMC_PCK1RDY = (0x1 << 9);       // (PMC) PCK1_RDY Status/Enable/Disable/Mask
    static const    uint32_t PMC_PCK2RDY = (0x1 << 10);       // (PMC) PCK2_RDY Status/Enable/Disable/Mask
    static const    uint32_t PMC_PCK3RDY = (0x1 << 11);       // (PMC) PCK3_RDY Status/Enable/Disable/Mask
    static const    uint32_t PMC_LOCKU = (0x1 << 6);           //(PMC) USB clock locked
    /****/ volatile uint32_t PMC_IDR;   // Interrupt Disable Register

    /****/ volatile uint32_t PMC_SR;    // Status Register

    /****/ volatile uint32_t PMC_IMR;   // Interrupt Mask Register

    /****/ volatile uint32_t Reserved5[3]; // Reserved

    /****/ volatile uint32_t PMC_PLLICPR; // Charge Pump Current Register
    static const    uint32_t PMC_PLLICPR__PLLA = (0x1 << 0);
    static const    uint32_t PMC_PLLICPR__PLLB = (0x1 << 16);

    __inline void EnableSystemClock(uint32_t clkIds)
    {
        PMC_SCER = clkIds;
    }

    __inline void DisableSystemClock(uint32_t clkIds)
    {
        PMC_SCDR = clkIds;
    }

    __inline void EnablePeriphClock(uint32_t periphIds)
    {
        PMC_PCER = (1 << periphIds);
    }

    __inline void DisablePeriphClock(uint32_t periphIds)
    {
        PMC_PCDR = (1 << periphIds);
    }


};


// MMU
struct ARM9_MMU
{
    static const uint32_t c_TTB_size = 0x4000;

    static const uint32_t c_MMU_L1_Fault = 0x00;
    static const uint32_t c_MMU_L1_Coarse = 0x11;
    static const uint32_t c_MMU_L1_Section = 0x12;
    static const uint32_t c_MMU_L1_Fine = 0x13;
    static const uint32_t c_MMU_L1_size = 1 << 20;

    static const uint32_t c_AP__NoAccess = 0;
    static const uint32_t c_AP__Client = 1;
    static const uint32_t c_AP__Reserved = 2;
    static const uint32_t c_AP__Manager = 3;

    //--//

    static uint32_t* GetL1Entry(uint32_t* base, uint32_t address);
    static void    InitializeL1(uint32_t* baseOfTTBs);
    static uint32_t  GenerateL1_Section(uint32_t address, uint32_t AP, uint32_t domain, bool Cachable, bool Buffered, bool Xtended = false);
    static void    GenerateL1_Sections(uint32_t* baseOfTTBs, uint32_t mappedAddress, uint32_t physAddress, int32_t size, uint32_t AP, uint32_t domain, bool Cachable, bool Buffered, bool Xtended = false);
};

void AT91_MMU_Initialize();
void AT91_CPU_InvalidateTLBs();
void AT91_CPU_EnableMMU(void* TTB);
void AT91_CPU_DisableMMU();
bool AT91_CPU_IsMMUEnabled();
void AT91_CPU_BootstrapCode();

// Cache
void AT91_Cache_FlushCaches();
void AT91_Cache_DrainWriteBuffers();
void AT91_Cache_InvalidateCaches();
void AT91_Cache_EnableCaches();
void AT91_Cache_DisableCaches();
template <typename T> void AT91_Cache_InvalidateAddress(T* address);
size_t AT91_Cache_GetCachableAddress(size_t address);
size_t AT91_Cache_GetUncachableAddress(size_t address);

// GPIO
enum class AT91_Gpio_Direction : uint8_t {
    Input = 0,
    Output = 1,
};

enum class AT91_Gpio_PinFunction : uint8_t {
    PinFunction0 = 0,
    PinFunction1 = 1,
    PinFunction2 = 2,
    PinFunction3 = 3,
};

enum class AT91_Gpio_PinMode : uint8_t {
    PullUp = 0,
    Reserved = 1,
    Inactive = 2,
    PullDown = 3
};

void AT91_Gpio_Reset();
const TinyCLR_Api_Info* AT91_Gpio_GetApi();
TinyCLR_Result AT91_Gpio_Acquire(const TinyCLR_Gpio_Provider* self);
TinyCLR_Result AT91_Gpio_Release(const TinyCLR_Gpio_Provider* self);
TinyCLR_Result AT91_Gpio_EnableAlternatePin(int32_t pin, TinyCLR_Gpio_PinDriveMode resistor, uint32_t alternate);
TinyCLR_Result AT91_Gpio_Read(const TinyCLR_Gpio_Provider* self, int32_t pin, TinyCLR_Gpio_PinValue& value);
TinyCLR_Result AT91_Gpio_Write(const TinyCLR_Gpio_Provider* self, int32_t pin, TinyCLR_Gpio_PinValue value);
TinyCLR_Result AT91_Gpio_SetDebounceTimeout(const TinyCLR_Gpio_Provider* self, int32_t pin, int32_t debounceTime);
TinyCLR_Result AT91_Gpio_SetDriveMode(const TinyCLR_Gpio_Provider* self, int32_t pin, TinyCLR_Gpio_PinDriveMode mode);
TinyCLR_Result AT91_Gpio_AcquirePin(const TinyCLR_Gpio_Provider* self, int32_t pin);
bool AT91_Gpio_IsDriveModeSupported(const TinyCLR_Gpio_Provider* self, int32_t pin, TinyCLR_Gpio_PinDriveMode mode);
TinyCLR_Gpio_PinDriveMode AT91_Gpio_GetDriveMode(const TinyCLR_Gpio_Provider* self, int32_t pin);
int32_t AT91_Gpio_GetDebounceTimeout(const TinyCLR_Gpio_Provider* self, int32_t pin);
int32_t AT91_Gpio_GetPinCount(const TinyCLR_Gpio_Provider* self);
TinyCLR_Result AT91_Gpio_SetValueChangedHandler(const TinyCLR_Gpio_Provider* self, int32_t pin, TinyCLR_Gpio_ValueChangedHandler ISR);
TinyCLR_Result AT91_Gpio_ReleasePin(const TinyCLR_Gpio_Provider* self, int32_t pin);
void AT91_Gpio_EnableOutputPin(int32_t pin, bool initialState);
void AT91_Gpio_EnableInputPin(int32_t pin, TinyCLR_Gpio_PinDriveMode resistor);
bool AT91_Gpio_OpenPin(int32_t pin);
bool AT91_Gpio_ClosePin(int32_t pin);
bool AT91_Gpio_ReadPin(int32_t pin);
void AT91_Gpio_WritePin(int32_t pin, bool value);
bool AT91_Gpio_ConfigurePin(int32_t pin, AT91_Gpio_Direction pinDir, AT91_Gpio_PinFunction alternateFunction, AT91_Gpio_PinMode pullResistor);

// ADC
const TinyCLR_Api_Info* AT91_Adc_GetApi();
void AT91_Adc_Reset();
int32_t AT91_Adc_GetControllerCount();
int32_t AT91_Adc_GetPin(int32_t channel);
AT91_Gpio_PinFunction AT91_Adc_GetPinFunction(int32_t channel);
TinyCLR_Result AT91_Adc_Acquire(const TinyCLR_Adc_Provider* self);
TinyCLR_Result AT91_Adc_Release(const TinyCLR_Adc_Provider* self);
TinyCLR_Result AT91_Adc_AcquireChannel(const TinyCLR_Adc_Provider* self, int32_t channel);
TinyCLR_Result AT91_Adc_ReleaseChannel(const TinyCLR_Adc_Provider* self, int32_t channel);
TinyCLR_Result AT91_Adc_ReadValue(const TinyCLR_Adc_Provider* self, int32_t channel, int32_t& value);
int32_t AT91_Adc_GetChannelCount(const TinyCLR_Adc_Provider* self);
int32_t AT91_Adc_GetResolutionInBits(const TinyCLR_Adc_Provider* self);
int32_t AT91_Adc_GetMinValue(const TinyCLR_Adc_Provider* self);
int32_t AT91_Adc_GetMaxValue(const TinyCLR_Adc_Provider* self);
TinyCLR_Adc_ChannelMode AT91_Adc_GetChannelMode(const TinyCLR_Adc_Provider* self);
TinyCLR_Result AT91_Adc_SetChannelMode(const TinyCLR_Adc_Provider* self, TinyCLR_Adc_ChannelMode mode);
bool AT91_Adc_IsChannelModeSupported(const TinyCLR_Adc_Provider* self, TinyCLR_Adc_ChannelMode mode);

//DAC
const TinyCLR_Api_Info* AT91_Dac_GetApi();
void AT91_Dac_Reset();
TinyCLR_Result AT91_Dac_Acquire(const TinyCLR_Dac_Provider* self);
TinyCLR_Result AT91_Dac_Release(const TinyCLR_Dac_Provider* self);
TinyCLR_Result AT91_Dac_AcquireChannel(const TinyCLR_Dac_Provider* self, int32_t channel);
TinyCLR_Result AT91_Dac_ReleaseChannel(const TinyCLR_Dac_Provider* self, int32_t channel);
TinyCLR_Result AT91_Dac_WriteValue(const TinyCLR_Dac_Provider* self, int32_t channel, int32_t value);
int32_t AT91_Dac_GetChannelCount(const TinyCLR_Dac_Provider* self);
int32_t AT91_Dac_GetResolutionInBits(const TinyCLR_Dac_Provider* self);
int32_t AT91_Dac_GetMinValue(const TinyCLR_Dac_Provider* self);
int32_t AT91_Dac_GetMaxValue(const TinyCLR_Dac_Provider* self);

// PWM
struct PwmController {
    int32_t                     id;
    int32_t                     channel[MAX_PWM_PER_CONTROLLER];
    int32_t                     subChannel[MAX_PWM_PER_CONTROLLER];
    uint32_t                    gpioPin[MAX_PWM_PER_CONTROLLER];
    AT91_Gpio_PinFunction      gpioAlternateFunction[MAX_PWM_PER_CONTROLLER];
    uint32_t                    outputEnabled[MAX_PWM_PER_CONTROLLER];
    uint32_t                    *matchAddress[MAX_PWM_PER_CONTROLLER];
    bool                        invert[MAX_PWM_PER_CONTROLLER];
    double                      frequency;
    double                      dutyCycle[MAX_PWM_PER_CONTROLLER];
};
const TinyCLR_Api_Info* AT91_Pwm_GetApi();
void AT91_Pwm_Reset();
void AT91_Pwm_ResetController(int32_t controller);
PwmController* AT91_Pwm_GetControllers();
TinyCLR_Result AT91_Pwm_Acquire(const TinyCLR_Pwm_Provider* self);
TinyCLR_Result AT91_Pwm_Release(const TinyCLR_Pwm_Provider* self);
int32_t AT91_Pwm_GetGpioPinForChannel(const TinyCLR_Pwm_Provider* self, int32_t pin);
TinyCLR_Result AT91_Pwm_SetDesiredFrequency(const TinyCLR_Pwm_Provider* self, double& frequency);
TinyCLR_Result AT91_Pwm_AcquirePin(const TinyCLR_Pwm_Provider* self, int32_t pin);
TinyCLR_Result AT91_Pwm_ReleasePin(const TinyCLR_Pwm_Provider* self, int32_t pin);
TinyCLR_Result AT91_Pwm_EnablePin(const TinyCLR_Pwm_Provider* self, int32_t pin);
TinyCLR_Result AT91_Pwm_DisablePin(const TinyCLR_Pwm_Provider* self, int32_t pin);
TinyCLR_Result AT91_Pwm_SetPulseParameters(const TinyCLR_Pwm_Provider* self, int32_t pin, double dutyCycle, bool invertPolarity);
double AT91_Pwm_GetMinFrequency(const TinyCLR_Pwm_Provider* self);
double AT91_Pwm_GetMaxFrequency(const TinyCLR_Pwm_Provider* self);
double AT91_Pwm_GetActualFrequency(const TinyCLR_Pwm_Provider* self);
int32_t AT91_Pwm_GetPinCount(const TinyCLR_Pwm_Provider* self);

//SPI
const TinyCLR_Api_Info* AT91_Spi_GetApi();
void AT91_Spi_Reset();
bool AT91_Spi_Transaction_Start(int32_t controller);
bool AT91_Spi_Transaction_Stop(int32_t controller);
bool AT91_Spi_Transaction_nWrite8_nRead8(int32_t controller);
TinyCLR_Result AT91_Spi_Acquire(const TinyCLR_Spi_Provider* self);
TinyCLR_Result AT91_Spi_Release(const TinyCLR_Spi_Provider* self);
TinyCLR_Result AT91_Spi_SetActiveSettings(const TinyCLR_Spi_Provider* self, int32_t chipSelectLine, int32_t clockFrequency, int32_t dataBitLength, TinyCLR_Spi_Mode mode);
TinyCLR_Result AT91_Spi_Read(const TinyCLR_Spi_Provider* self, uint8_t* buffer, size_t& length);
TinyCLR_Result AT91_Spi_Write(const TinyCLR_Spi_Provider* self, const uint8_t* buffer, size_t& length);
TinyCLR_Result AT91_Spi_TransferFullDuplex(const TinyCLR_Spi_Provider* self, const uint8_t* writeBuffer, size_t& writeLength, uint8_t* readBuffer, size_t& readLength);
TinyCLR_Result AT91_Spi_TransferSequential(const TinyCLR_Spi_Provider* self, const uint8_t* writeBuffer, size_t& writeLength, uint8_t* readBuffer, size_t& readLength);
int32_t AT91_Spi_GetChipSelectLineCount(const TinyCLR_Spi_Provider* self);
int32_t AT91_Spi_GetMinClockFrequency(const TinyCLR_Spi_Provider* self);
int32_t AT91_Spi_GetMaxClockFrequency(const TinyCLR_Spi_Provider* self);
TinyCLR_Result AT91_Spi_GetSupportedDataBitLengths(const TinyCLR_Spi_Provider* self, int32_t* dataBitLengths, size_t& dataBitLengthsCount);

//Uart
const TinyCLR_Api_Info* AT91_Uart_GetApi();
void AT91_Uart_Reset();
int32_t AT91_Uart_GetTxPin(int32_t portNum);
int32_t AT91_Uart_GetRxPin(int32_t portNum);
int32_t AT91_Uart_GetRtsPin(int32_t portNum);
int32_t AT91_Uart_GetCtsPin(int32_t portNum);
AT91_Gpio_PinFunction AT91_Uart_GetTxAlternateFunction(int32_t portNum);
AT91_Gpio_PinFunction AT91_Uart_GetRxAlternateFunction(int32_t portNum);
AT91_Gpio_PinFunction AT91_Uart_GetRtsAlternateFunction(int32_t portNum);
AT91_Gpio_PinFunction AT91_Uart_GetCtsAlternateFunction(int32_t portNum);
bool AT91_Uart_TxHandshakeEnabledState(int portNum);
void AT91_Uart_TxBufferEmptyInterruptEnable(int portNum, bool enable);
void AT91_Uart_RxBufferFullInterruptEnable(int portNum, bool enable);
TinyCLR_Result AT91_Uart_Acquire(const TinyCLR_Uart_Provider* self);
TinyCLR_Result AT91_Uart_Release(const TinyCLR_Uart_Provider* self);
TinyCLR_Result AT91_Uart_SetActiveSettings(const TinyCLR_Uart_Provider* self, uint32_t baudRate, uint32_t dataBits, TinyCLR_Uart_Parity parity, TinyCLR_Uart_StopBitCount stopBits, TinyCLR_Uart_Handshake handshaking);
TinyCLR_Result AT91_Uart_Flush(const TinyCLR_Uart_Provider* self);
TinyCLR_Result AT91_Uart_Read(const TinyCLR_Uart_Provider* self, uint8_t* buffer, size_t& length);
TinyCLR_Result AT91_Uart_Write(const TinyCLR_Uart_Provider* self, const uint8_t* buffer, size_t& length);
TinyCLR_Result AT91_Uart_SetPinChangedHandler(const TinyCLR_Uart_Provider* self, TinyCLR_Uart_PinChangedHandler handler);
TinyCLR_Result AT91_Uart_SetErrorReceivedHandler(const TinyCLR_Uart_Provider* self, TinyCLR_Uart_ErrorReceivedHandler handler);
TinyCLR_Result AT91_Uart_SetDataReceivedHandler(const TinyCLR_Uart_Provider* self, TinyCLR_Uart_DataReceivedHandler handler);
TinyCLR_Result AT91_Uart_GetBreakSignalState(const TinyCLR_Uart_Provider* self, bool& state);
TinyCLR_Result AT91_Uart_SetBreakSignalState(const TinyCLR_Uart_Provider* self, bool state);
TinyCLR_Result AT91_Uart_GetCarrierDetectState(const TinyCLR_Uart_Provider* self, bool& state);
TinyCLR_Result AT91_Uart_GetClearToSendState(const TinyCLR_Uart_Provider* self, bool& state);
TinyCLR_Result AT91_Uart_GetDataReadyState(const TinyCLR_Uart_Provider* self, bool& state);
TinyCLR_Result AT91_Uart_GetIsDataTerminalReadyEnabled(const TinyCLR_Uart_Provider* self, bool& state);
TinyCLR_Result AT91_Uart_SetIsDataTerminalReadyEnabled(const TinyCLR_Uart_Provider* self, bool state);
TinyCLR_Result AT91_Uart_GetIsRequestToSendEnabled(const TinyCLR_Uart_Provider* self, bool& state);
TinyCLR_Result AT91_Uart_SetIsRequestToSendEnabled(const TinyCLR_Uart_Provider* self, bool state);

//Deployment
const TinyCLR_Api_Info* AT91_Deployment_GetApi();
TinyCLR_Result AT91_Flash_Acquire(const TinyCLR_Deployment_Provider* self, bool &supportXIP);
TinyCLR_Result AT91_Flash_Release(const TinyCLR_Deployment_Provider* self);
TinyCLR_Result AT91_Flash_Read(const TinyCLR_Deployment_Provider* self, uint32_t address, size_t length, uint8_t* buffer);
TinyCLR_Result AT91_Flash_Write(const TinyCLR_Deployment_Provider* self, uint32_t address, size_t length, const uint8_t* buffer);
TinyCLR_Result AT91_Flash_EraseBlock(const TinyCLR_Deployment_Provider* self, uint32_t sector);
TinyCLR_Result AT91_Flash_IsBlockErased(const TinyCLR_Deployment_Provider* self, uint32_t sector, bool &erased);
TinyCLR_Result AT91_Flash_GetBytesPerSector(const TinyCLR_Deployment_Provider* self, uint32_t address, int32_t& size);
TinyCLR_Result AT91_Flash_GetSectorMap(const TinyCLR_Deployment_Provider* self, const uint32_t*& addresses, const uint32_t*& sizes, size_t& count);
bool AT91_Flash_PageProgram(uint32_t byteAddress, uint32_t NumberOfBytesToWrite, const uint8_t * pointerToWriteBuffer);
bool AT91_Flash_IsSupportsXIP(const TinyCLR_Deployment_Provider* self);
uint32_t AT91_Flash_GetPartId();

// Interrupt
//////////////////////////////////////////////////////////////////////////////
// AT91_AIC
//
struct AT91_AIC
{
    static const uint32_t c_Base = AT91C_BASE_AIC;

    /****/ volatile uint32_t AIC_SMR[32];    // Source Mode Register
    static const    uint32_t AIC_PRIOR = (0x7 << 0); // (AIC) Priority Level
    static const    uint32_t AIC_PRIOR_LOWEST = (0x0); // (AIC) Lowest priority level
    static const    uint32_t AIC_PRIOR_HIGHEST = (0x7); // (AIC) Highest priority level
    static const    uint32_t AIC_SRCTYPE = (0x3 << 5); // (AIC) Interrupt Source Type
    static const    uint32_t AIC_SRCTYPE_INT_HIGH_LEVEL = (0x0 << 5); // (AIC) Internal Sources Code Label High-level Sensitive
    static const    uint32_t AIC_SRCTYPE_EXT_LOW_LEVEL = (0x0 << 5); // (AIC) External Sources Code Label Low-level Sensitive
    static const    uint32_t AIC_SRCTYPE_INT_POSITIVE_EDGE = (0x1 << 5); // (AIC) Internal Sources Code Label Positive Edge triggered
    static const    uint32_t AIC_SRCTYPE_EXT_NEGATIVE_EDGE = (0x1 << 5); // (AIC) External Sources Code Label Negative Edge triggered
    static const    uint32_t AIC_SRCTYPE_HIGH_LEVEL = (0x2 << 5); // (AIC) Internal Or External Sources Code Label High-level Sensitive
    static const    uint32_t AIC_SRCTYPE_POSITIVE_EDGE = (0x3 << 5); // (AIC) Internal Or External Sources Code Label Positive Edge triggered



    /****/ volatile uint32_t AIC_SVR[32];    // Source Vector Register

    /****/ volatile uint32_t AIC_IVR;        // IRQ Vector Register

    /****/ volatile uint32_t AIC_FVR;        // FIQ Vector Register

    /****/ volatile uint32_t AIC_ISR;        // Interrupt Status Register

    /****/ volatile uint32_t AIC_IPR;        // Interrupt Pending Register

    /****/ volatile uint32_t AIC_IMR;        // Interrupt Mask Register

    /****/ volatile uint32_t AIC_CISR;       // Core Interrupt Status Register
    static const    uint32_t AIC_NFIQ = (0x1 << 0); // (AIC) NFIQ Status
    static const    uint32_t AIC_NIRQ = (0x1 << 1); // (AIC) NIRQ Status

    /****/ volatile uint32_t Reserved6[2];

    /****/ volatile uint32_t AIC_IECR;       // Interrupt Enable Command Register

    /****/ volatile uint32_t AIC_IDCR;       // Interrupt Disable Command Register
    static const    uint32_t AIC_IDCR_DIABLE_ALL = 0xFFFFFFFF; // disable all

    /****/ volatile uint32_t AIC_ICCR;       // Interrupt Clear Command Register
    static const    uint32_t AIC_ICCR_CLEAR_ALL = 0xFFFFFFFF; // clear all

    /****/ volatile uint32_t AIC_ISCR;       // Interrupt Set Command Register

    /****/ volatile uint32_t AIC_EOICR;      // End of Interrupt Command Register

    /****/ volatile uint32_t AIC_SPU;        // Spurious Vector Register

    /****/ volatile uint32_t AIC_DCR;        // Debug Control Register (Protect)
    static const    uint32_t AIC_DCR_PROT = (0x1 << 0); // (AIC) Protection Mode
    static const    uint32_t AIC_DCR_GMSK = (0x1 << 1); // (AIC) General Mask

    /****/ volatile uint32_t Reserved7[1];

    /****/ volatile uint32_t AIC_FFER;       // Fast Forcing Enable Register

    /****/ volatile uint32_t AIC_FFDR;       // Fast Forcing Disable Register

    /****/ volatile uint32_t AIC_FFSR;       // Fast Forcing Status Register


    bool IsInterruptPending()
    {
        if (AIC_IPR & AIC_IMR)
        {
            return true;
        }

        return false;
    }
};

//
// AT91_AIC
//////////////////////////////////////////////////////////////////////////////

typedef void(*AT91_Interrupt_Handler)(void* arg);

struct AT91_Interrupt_Callback {

public:
    void* EntryPoint;
    void* Argument;

public:
    void Initialize(uint32_t* EntryPoint, void* Argument) {
        this->EntryPoint = (void*)EntryPoint;
        this->Argument = Argument;
    }

    void Execute() const {
        AT91_Interrupt_Handler EntryPoint = (AT91_Interrupt_Handler)this->EntryPoint;

        void* Argument = this->Argument;

        if (EntryPoint) {
            EntryPoint(Argument);
        }
    }
};

class AT91_SmartPtr_IRQ {

    uint32_t m_state;

public:
    AT91_SmartPtr_IRQ() { Disable(); };
    ~AT91_SmartPtr_IRQ() { Restore(); };

    bool WasDisabled();
    void Acquire();
    void Release();
    void Probe();

    static uint32_t GetState();

private:
    void Disable();
    void Restore();
};

const TinyCLR_Api_Info* AT91_Interrupt_GetApi();
TinyCLR_Result AT91_Interrupt_Acquire(TinyCLR_Interrupt_StartStopHandler onInterruptStart, TinyCLR_Interrupt_StartStopHandler onInterruptEnd);
TinyCLR_Result AT91_Interrupt_Release();
bool AT91_Interrupt_Activate(uint32_t Irq_Index, uint32_t *ISR, void* ISR_Param);
bool AT91_Interrupt_Deactivate(uint32_t Irq_Index);
bool AT91_Interrupt_Enable(uint32_t Irq_Index);
bool AT91_Interrupt_Disable(uint32_t Irq_Index);
bool AT91_Interrupt_EnableState(uint32_t Irq_Index);
bool AT91_Interrupt_InterruptState(uint32_t Irq_Index);


bool AT91_Interrupt_GlobalIsDisabled();
bool AT91_Interrupt_GlobalEnable(bool force);
bool AT91_Interrupt_GlobalDisable(bool force);

void AT91_Interrupt_GlobalRestore();
void AT91_Interrupt_GlobalWaitForInterrupt();

void AT91_Interrupt_ForceInterrupt(uint32_t Irq_Index);

extern TinyCLR_Interrupt_StartStopHandler AT91_Interrupt_Started;
extern TinyCLR_Interrupt_StartStopHandler AT91_Interrupt_Ended;

// I2C
const TinyCLR_Api_Info* AT91_I2c_GetApi();
void AT91_I2c_Reset();
TinyCLR_Result AT91_I2c_Acquire(const TinyCLR_I2c_Provider* self);
TinyCLR_Result AT91_I2c_Release(const TinyCLR_I2c_Provider* self);
TinyCLR_Result AT91_I2c_SetActiveSettings(const TinyCLR_I2c_Provider* self, int32_t slaveAddress, TinyCLR_I2c_BusSpeed busSpeed);
TinyCLR_Result AT91_I2c_ReadTransaction(const TinyCLR_I2c_Provider* self, uint8_t* buffer, size_t& length, TinyCLR_I2c_TransferStatus& result);
TinyCLR_Result AT91_I2c_WriteTransaction(const TinyCLR_I2c_Provider* self, const uint8_t* buffer, size_t& length, TinyCLR_I2c_TransferStatus& result);
TinyCLR_Result AT91_I2c_WriteReadTransaction(const TinyCLR_I2c_Provider* self, const uint8_t* writeBuffer, size_t& writeLength, uint8_t* readBuffer, size_t& readLength, TinyCLR_I2c_TransferStatus& result);
void AT91_I2c_StartTransaction();
void AT91_I2c_StopTransaction();

// Time
//////////////////////////////////////////////////////////////////////////////
// AT91 Timer Channel
//
struct AT91_TC {

    static const uint32_t c_Base = AT91C_BASE_TC0;

    /****/ volatile uint32_t TC_CCR;    // Channel Control Register
    static const    uint32_t TC_CLKEN = (0x1 << 0);// (TC) Counter Clock Enable Command
    static const    uint32_t TC_CLKDIS = (0x1 << 1);// (TC)Counter Clock Disable Command
    static const    uint32_t TC_SWTRG = (0x1 << 2);// (TC)Software Trigger Command

    /****/ volatile uint32_t TC_CMR;    // Channel Mode Register (Capture Mode / Waveform Mode)
    static const    uint32_t TC_CLKS = (0x7 << 0);// (TC)Clock Selection
    static const    uint32_t     TC_CLKS_TIMER_DIV1_CLOCK = (0x0);// (TC)Clock selected: TIMER_DIV1_CLOCK
    static const    uint32_t     TC_CLKS_TIMER_DIV2_CLOCK = (0x1);// (TC)Clock selected: TIMER_DIV2_CLOCK
    static const    uint32_t     TC_CLKS_TIMER_DIV3_CLOCK = (0x2);// (TC)Clock selected: TIMER_DIV3_CLOCK
    static const    uint32_t     TC_CLKS_TIMER_DIV4_CLOCK = (0x3);// (TC)Clock selected: TIMER_DIV4_CLOCK
    static const    uint32_t     TC_CLKS_TIMER_DIV5_CLOCK = (0x4);// (TC)Clock selected: TIMER_DIV5_CLOCK
    static const    uint32_t     TC_CLKS_XC0 = (0x5);// (TC)Clock selected: XC0
    static const    uint32_t     TC_CLKS_XC1 = (0x6);// (TC)Clock selected: XC1
    static const    uint32_t     TC_CLKS_XC2 = (0x7);// (TC)Clock selected: XC2
    static const    uint32_t TC_CLKI = (0x1 << 3);// (TC)Clock Invert
    static const    uint32_t TC_BURST = (0x3 << 4);// (TC)Burst Signal Selection
    static const    uint32_t     TC_BURST_NONE = (0x0 << 4);// (TC)The clock is not gated by an external signal
    static const    uint32_t     TC_BURST_XC0 = (0x1 << 4);// (TC)XC0 is ANDed with the selected clock
    static const    uint32_t     TC_BURST_XC1 = (0x2 << 4);// (TC)XC1 is ANDed with the selected clock
    static const    uint32_t     TC_BURST_XC2 = (0x3 << 4);// (TC)XC2 is ANDed with the selected clock
    static const    uint32_t TC_CPCSTOP = (0x1 << 6);// (TC)Counter Clock Stopped with RC Compare
    static const    uint32_t TC_LDBSTOP = (0x1 << 6);// (TC)Counter Clock Stopped with RB Loading
    static const    uint32_t TC_CPCDIS = (0x1 << 7);// (TC)Counter Clock Disable with RC Compare
    static const    uint32_t TC_LDBDIS = (0x1 << 7);// (TC)Counter Clock Disabled with RB Loading
    static const    uint32_t TC_ETRGEDG = (0x3 << 8);// (TC)External Trigger Edge Selection
    static const    uint32_t     TC_ETRGEDG_NONE = (0x0 << 8);// (TC)Edge: None
    static const    uint32_t     TC_ETRGEDG_RISING = (0x1 << 8);// (TC)Edge: rising edge
    static const    uint32_t     TC_ETRGEDG_FALLING = (0x2 << 8);// (TC)Edge: falling edge
    static const    uint32_t     TC_ETRGEDG_BOTH = (0x3 << 8);// (TC)Edge: each edge
    static const    uint32_t TC_EEVTEDG = (0x3 << 8);// (TC)External Event Edge Selection
    static const    uint32_t     TC_EEVTEDG_NONE = (0x0 << 8);// (TC)Edge: None
    static const    uint32_t     TC_EEVTEDG_RISING = (0x1 << 8);// (TC)Edge: rising edge
    static const    uint32_t     TC_EEVTEDG_FALLING = (0x2 << 8);// (TC)Edge: falling edge
    static const    uint32_t     TC_EEVTEDG_BOTH = (0x3 << 8);// (TC)Edge: each edge
    static const    uint32_t TC_EEVT = (0x3 << 10);// (TC)External Event  Selection
    static const    uint32_t     TC_EEVT_TIOB = (0x0 << 10);// (TC)Signal selected as external event: TIOB TIOB direction: input
    static const    uint32_t     TC_EEVT_XC0 = (0x1 << 10);// (TC)Signal selected as external event: XC0 TIOB direction: output
    static const    uint32_t     TC_EEVT_XC1 = (0x2 << 10);// (TC)Signal selected as external event: XC1 TIOB direction: output
    static const    uint32_t     TC_EEVT_XC2 = (0x3 << 10);// (TC)Signal selected as external event: XC2 TIOB direction: output
    static const    uint32_t TC_ABETRG = (0x1 << 10);// (TC)TIOA or TIOB External Trigger Selection
    static const    uint32_t TC_ENETRG = (0x1 << 12);// (TC)External Event Trigger enable
    static const    uint32_t TC_WAVESEL = (0x3 << 13);// (TC)Waveform  Selection
    static const    uint32_t     TC_WAVESEL_UP = (0x0 << 13);// (TC)UP mode without atomatic trigger on RC Compare
    static const    uint32_t     TC_WAVESEL_UPDOWN = (0x1 << 13);// (TC)UPDOWN mode without automatic trigger on RC Compare
    static const    uint32_t     TC_WAVESEL_UP_AUTO = (0x2 << 13);// (TC)UP mode with automatic trigger on RC Compare
    static const    uint32_t     TC_WAVESEL_UPDOWN_AUTO = (0x3 << 13);// (TC)UPDOWN mode with automatic trigger on RC Compare
    static const    uint32_t TC_CPCTRG = (0x1 << 14);// (TC)RC Compare Trigger Enable
    static const    uint32_t TC_WAVE = (0x1 << 15);// (TC)
    static const    uint32_t TC_ACPA = (0x3 << 16);// (TC)RA Compare Effect on TIOA
    static const    uint32_t     TC_ACPA_NONE = (0x0 << 16);// (TC)Effect: none
    static const    uint32_t     TC_ACPA_SET = (0x1 << 16);// (TC)Effect: set
    static const    uint32_t     TC_ACPA_CLEAR = (0x2 << 16);// (TC)Effect: clear
    static const    uint32_t     TC_ACPA_TOGGLE = (0x3 << 16);// (TC)Effect: toggle
    static const    uint32_t TC_LDRA = (0x3 << 16);// (TC)RA Loading Selection
    static const    uint32_t     TC_LDRA_NONE = (0x0 << 16);// (TC)Edge: None
    static const    uint32_t     TC_LDRA_RISING = (0x1 << 16);// (TC)Edge: rising edge of TIOA
    static const    uint32_t     TC_LDRA_FALLING = (0x2 << 16);// (TC)Edge: falling edge of TIOA
    static const    uint32_t     TC_LDRA_BOTH = (0x3 << 16);// (TC)Edge: each edge of TIOA
    static const    uint32_t TC_ACPC = (0x3 << 18);// (TC)RC Compare Effect on TIOA
    static const    uint32_t     TC_ACPC_NONE = (0x0 << 18);// (TC)Effect: none
    static const    uint32_t     TC_ACPC_SET = (0x1 << 18);// (TC)Effect: set
    static const    uint32_t     TC_ACPC_CLEAR = (0x2 << 18);// (TC)Effect: clear
    static const    uint32_t     TC_ACPC_TOGGLE = (0x3 << 18);// (TC)Effect: toggle
    static const    uint32_t TC_LDRB = (0x3 << 18);// (TC)RB Loading Selection
    static const    uint32_t     TC_LDRB_NONE = (0x0 << 18);// (TC)Edge: None
    static const    uint32_t     TC_LDRB_RISING = (0x1 << 18);// (TC)Edge: rising edge of TIOA
    static const    uint32_t     TC_LDRB_FALLING = (0x2 << 18);// (TC)Edge: falling edge of TIOA
    static const    uint32_t     TC_LDRB_BOTH = (0x3 << 18);// (TC)Edge: each edge of TIOA
    static const    uint32_t TC_AEEVT = (0x3 << 20);// (TC)External Event Effect on TIOA
    static const    uint32_t     TC_AEEVT_NONE = (0x0 << 20);// (TC)Effect: none
    static const    uint32_t     TC_AEEVT_SET = (0x1 << 20);// (TC)Effect: set
    static const    uint32_t     TC_AEEVT_CLEAR = (0x2 << 20);// (TC)Effect: clear
    static const    uint32_t     TC_AEEVT_TOGGLE = (0x3 << 20);// (TC)Effect: toggle
    static const    uint32_t TC_ASWTRG = (0x3 << 22);// (TC)Software Trigger Effect on TIOA
    static const    uint32_t     TC_ASWTRG_NONE = (0x0 << 22);// (TC)Effect: none
    static const    uint32_t     TC_ASWTRG_SET = (0x1 << 22);// (TC)Effect: set
    static const    uint32_t     TC_ASWTRG_CLEAR = (0x2 << 22);// (TC)Effect: clear
    static const    uint32_t     TC_ASWTRG_TOGGLE = (0x3 << 22);// (TC)Effect: toggle
    static const    uint32_t TC_BCPB = (0x3 << 24);// (TC)RB Compare Effect on TIOB
    static const    uint32_t     TC_BCPB_NONE = (0x0 << 24);// (TC)Effect: none
    static const    uint32_t     TC_BCPB_SET = (0x1 << 24);// (TC)Effect: set
    static const    uint32_t     TC_BCPB_CLEAR = (0x2 << 24);// (TC)Effect: clear
    static const    uint32_t     TC_BCPB_TOGGLE = (0x3 << 24);// (TC)Effect: toggle
    static const    uint32_t TC_BCPC = (0x3 << 26);// (TC)RC Compare Effect on TIOB
    static const    uint32_t     TC_BCPC_NONE = (0x0 << 26);// (TC)Effect: none
    static const    uint32_t     TC_BCPC_SET = (0x1 << 26);// (TC)Effect: set
    static const    uint32_t     TC_BCPC_CLEAR = (0x2 << 26);// (TC)Effect: clear
    static const    uint32_t     TC_BCPC_TOGGLE = (0x3 << 26);// (TC)Effect: toggle
    static const    uint32_t TC_BEEVT = (0x3 << 28);// (TC)External Event Effect on TIOB
    static const    uint32_t     TC_BEEVT_NONE = (0x0 << 28);// (TC)Effect: none
    static const    uint32_t     TC_BEEVT_SET = (0x1 << 28);// (TC)Effect: set
    static const    uint32_t     TC_BEEVT_CLEAR = (0x2 << 28);// (TC)Effect: clear
    static const    uint32_t     TC_BEEVT_TOGGLE = (0x3 << 28);// (TC)Effect: toggle
    static const    uint32_t TC_BSWTRG = ((uint32_t)0x3 << 30);// (TC)Software Trigger Effect on TIOB
    static const    uint32_t     TC_BSWTRG_NONE = ((uint32_t)0x0 << 30);// (TC)Effect: none
    static const    uint32_t     TC_BSWTRG_SET = ((uint32_t)0x1 << 30);// (TC)Effect: set
    static const    uint32_t     TC_BSWTRG_CLEAR = ((uint32_t)0x2 << 30);// (TC)Effect: clear
    static const    uint32_t     TC_BSWTRG_TOGGLE = ((uint32_t)0x3 << 30);// (TC)Effect: toggle

    /****/ volatile uint32_t Reserved0[2];

    /****/ volatile uint32_t TC_CV;     // Counter Value

    /****/ volatile uint32_t TC_RA;     // Register A

    /****/ volatile uint32_t TC_RB;     // Register B

    /****/ volatile uint32_t TC_RC;     // Register C

    /****/ volatile uint32_t TC_SR;     // Status Register
    static const    uint32_t TC_COVFS = (0x1 << 0);// (TC)Counter Overflow
    static const    uint32_t TC_LOVRS = (0x1 << 1);// (TC)Load Overrun
    static const    uint32_t TC_CPAS = (0x1 << 2);// (TC)RA Compare
    static const    uint32_t TC_CPBS = (0x1 << 3);// (TC)RB Compare
    static const    uint32_t TC_CPCS = (0x1 << 4);// (TC)RC Compare
    static const    uint32_t TC_LDRAS = (0x1 << 5);// (TC)RA Loading
    static const    uint32_t TC_LDRBS = (0x1 << 6);// (TC)RB Loading
    static const    uint32_t TC_ETRGS = (0x1 << 7);// (TC)External Trigger
    static const    uint32_t TC_CLKSTA = (0x1 << 16);// (TC)Clock Enabling
    static const    uint32_t TC_MTIOA = (0x1 << 17);// (TC)TIOA Mirror
    static const    uint32_t TC_MTIOB = (0x1 << 18);// (TC)TIOA Mirror

    /****/ volatile uint32_t TC_IER;    // Interrupt Enable Register

    /****/ volatile uint32_t TC_IDR;    // Interrupt Disable Register

    /****/ volatile uint32_t TC_IMR;    // Interrupt Mask Register
};

//
// AT91 Timer Channel
const TinyCLR_Api_Info* AT91_Time_GetApi();
TinyCLR_Result AT91_Time_Acquire(const TinyCLR_Time_Provider* self);
TinyCLR_Result AT91_Time_Release(const TinyCLR_Time_Provider* self);
TinyCLR_Result AT91_Time_GetInitialTime(const TinyCLR_Time_Provider* self, int64_t& utcTime, int32_t& timeZoneOffsetMinutes);
uint64_t AT91_Time_TicksToTime(const TinyCLR_Time_Provider* self, uint64_t ticks);
uint64_t AT91_Time_TimeToTicks(const TinyCLR_Time_Provider* self, uint64_t time);
uint64_t AT91_Time_MillisecondsToTicks(const TinyCLR_Time_Provider* self, uint64_t ticks);
uint64_t AT91_Time_MicrosecondsToTicks(const TinyCLR_Time_Provider* self, uint64_t microseconds);
uint64_t AT91_Time_GetCurrentTicks(const TinyCLR_Time_Provider* self);
TinyCLR_Result AT91_Time_SetCompare(const TinyCLR_Time_Provider* self, uint64_t processorTicks);
TinyCLR_Result AT91_Time_SetCompareCallback(const TinyCLR_Time_Provider* self, TinyCLR_Time_TickCallback callback);
void AT91_Time_DelayNoInterrupt(const TinyCLR_Time_Provider* self, uint64_t microseconds);
void AT91_Time_Delay(const TinyCLR_Time_Provider* self, uint64_t microseconds);
void AT91_Time_GetDriftParameters(const TinyCLR_Time_Provider* self, int32_t* a, int32_t* b, int64_t* c);

// Power
const TinyCLR_Api_Info* AT91_Power_GetApi();
void AT91_Power_SetHandlers(void(*stop)(), void(*restart)());
void AT91_Power_Sleep(const TinyCLR_Power_Provider* self, TinyCLR_Power_Sleep_Level level);
void AT91_Power_Reset(const TinyCLR_Power_Provider* self, bool runCoreAfter);
TinyCLR_Result AT91_Power_Acquire(const TinyCLR_Power_Provider* self);
TinyCLR_Result AT91_Power_Release(const TinyCLR_Power_Provider* self);

//UsbClient
const TinyCLR_Api_Info* AT91_UsbClient_GetApi();
void AT91_UsbClient_Reset();
void AT91_UsbClient_PinConfiguration();
TinyCLR_Result AT91_UsbClient_Acquire(const TinyCLR_UsbClient_Provider* self);
TinyCLR_Result AT91_UsbClient_Release(const TinyCLR_UsbClient_Provider* self);
TinyCLR_Result AT91_UsbClient_Open(const TinyCLR_UsbClient_Provider* self, int32_t & stream, TinyCLR_UsbClient_StreamMode mode);
TinyCLR_Result AT91_UsbClient_Close(const TinyCLR_UsbClient_Provider* self, int32_t stream);
TinyCLR_Result AT91_UsbClient_Write(const TinyCLR_UsbClient_Provider* self, int32_t stream, const uint8_t* data, size_t& length);
TinyCLR_Result AT91_UsbClient_Read(const TinyCLR_UsbClient_Provider* self, int32_t stream, uint8_t* data, size_t& length);
TinyCLR_Result AT91_UsbClient_Flush(const TinyCLR_UsbClient_Provider* self, int32_t stream);
TinyCLR_Result AT91_UsbClient_SetDataReceivedHandler(const TinyCLR_UsbClient_Provider* self, TinyCLR_UsbClient_DataReceivedHandler handler);

TinyCLR_Result AT91_UsbClient_SetDeviceDescriptor(const TinyCLR_UsbClient_Provider* self, const void* descriptor, int32_t length);
TinyCLR_Result AT91_UsbClient_SetConfigDescriptor(const TinyCLR_UsbClient_Provider* self, const void* descriptor, int32_t length);
TinyCLR_Result AT91_UsbClient_SetStringDescriptor(const TinyCLR_UsbClient_Provider* self, TinyCLR_UsbClient_StringDescriptorType type, const wchar_t* value);
TinyCLR_Result AT91_UsbClient_SetOsExtendedPropertyHandler(const TinyCLR_UsbClient_Provider* self, TinyCLR_UsbClient_OsExtendedPropertyHandler handler);

// LCD
void AT91_Display_Reset();
const TinyCLR_Api_Info* AT91_Display_GetApi();
TinyCLR_Result AT91_Display_Acquire(const TinyCLR_Display_Provider* self, uint32_t width, uint32_t height);
TinyCLR_Result AT91_Display_Release(const TinyCLR_Display_Provider* self);
TinyCLR_Result AT91_Display_SetLcdConfiguration(const TinyCLR_Display_Provider* self, bool outputEnableIsFixed, bool outputEnablePolarity, bool pixelPolarity, uint32_t pixelClockRate, bool horizontalSyncPolarity, uint32_t horizontalSyncPulseWidth, uint32_t horizontalFrontPorch, uint32_t horizontalBackPorch, bool verticalSyncPolarity, uint32_t verticalSyncPulseWidth, uint32_t verticalFrontPorch, uint32_t verticalBackPorch);
TinyCLR_Result AT91_Display_DrawBuffer(const TinyCLR_Display_Provider* self, int32_t x, int32_t y, int32_t width, int32_t height, const uint8_t* data, TinyCLR_Display_Format dataFormat);
TinyCLR_Result AT91_Display_WriteString(const TinyCLR_Display_Provider* self, const char* buffer);
int32_t AT91_Display_GetWidth(const TinyCLR_Display_Provider* self);
int32_t AT91_Display_GetHeight(const TinyCLR_Display_Provider* self);
TinyCLR_Display_InterfaceType AT91_Display_GetType(const TinyCLR_Display_Provider* self);

//Startup
void AT91_Startup_InitializeRegions();
void AT91_Startup_GetHeap(uint8_t*& start, size_t& length);
int32_t AT91_Startup_GetLModePin();
int32_t AT91_Startup_GetDeviceId();
TinyCLR_Gpio_PinValue AT91_Startup_GetLModeUsbState();

struct AT91
{
    /*
        static const uint32_t c_UncachableMask = 0x80000000;

        static AT91_EIM     & EIM()             { return *(AT91_EIM     *)(size_t)(      AT91_EIM     ::c_Base                                      ); }
        static AT91_SC      & SC()              { return *(AT91_SC      *)(size_t)(      AT91_SC      ::c_Base                                      ); }
        static AT91_CMU     & CMU  (         )  { return *(AT91_CMU     *)(size_t)(      AT91_CMU     ::c_Base                                      ); }
        static AT91_PWM     & PWM()             { return *(AT91_PWM     *)(size_t)(      AT91_PWM     ::c_Base                                      ); }
        static AT91_DMA     & DMA()             { return *(AT91_DMA     *)(size_t)(      AT91_DMA     ::c_Base                                      ); }
    */
    //    static AT91_I2C     & I2C()             { return *(AT91_I2C     *)(size_t)(      AT91_I2C     ::c_Base                                      ); }
    static AT91_AIC     & AIC() { return *(AT91_AIC     *)(size_t)(AT91_AIC::c_Base); }
    //    static AT91_PIO     & PIO( int sel )    { return *(AT91_PIO     *)(size_t)(AT91_PIO     ::c_Base + AT91_PIO::c_Base_Offset * sel ); }
    static AT91_PMC     & PMC() { return *(AT91_PMC     *)(size_t)(AT91_PMC::c_Base); }
    //    static AT91_SPI     & SPI( int sel )    { if ( sel==0 ) return *(AT91_SPI     *)(size_t)(AT91_SPI::c_Base_1);
    //                                                  else      return *(AT91_SPI     *)(size_t)(AT91_SPI::c_Base_2);                              }

    static AT91_TC      & TIMER(int sel) { return *(AT91_TC*)(size_t)(AT91_TC::c_Base + (sel * 0x40)); }
    //    static AT91_WATCHDOG& WTDG()            { return *(AT91_WATCHDOG*)(size_t)(AT91_WATCHDOG::c_Base                                      ); }
    //***************************************************************************************************************************************************************************************************************
        // static AT91_USART   & USART( int sel )
        // {
            // if(sel == 0)
                // return *(AT91_USART*)(size_t)(AT91_USART::c_Base_dbg);
            // else if((sel > 0) && (sel < 4))
                // return *(AT91_USART   *)(size_t)(AT91_USART::c_Base_usart + ((sel - 1) * 0x4000));
            // else
                // return *(AT91_USART   *)(size_t)(AT91_USART::c_Base_uart + ((sel - 4) * 0x4000));
        // }
    //***************************************************************************************************************************************************************************************************************
    // static AT91_UDP     & UDP()             { return *(AT91_UDP     *)(size_t)(AT91_UDP     ::c_Base                                      ); }

    // #if defined(PLATFORM_ARM_SAM9261_ANY) || defined(PLATFORM_ARM_SAM9RL64_ANY)
        // static AT91_LCDC    & LCDC()            { return *(AT91_LCDC    *)(size_t)(AT91_LCDC    ::c_Base                                      ); }

        // static AT91_SDRAMC  & SDRAMC()          { return *(AT91_SDRAMC  *)(size_t)(AT91_SDRAMC  ::c_Base                                      ); }
        // static AT91_SMC     & SMCTRL()          { return *(AT91_SMC     *)(size_t)(AT91_SMC     ::c_Base                                      ); }
        // static AT91_MATRIX  & MATRIX()          { return *(AT91_MATRIX  *)(size_t)(AT91_MATRIX  ::c_Base                                      ); }
    // #endif
        // static AT91_DDRS     & DDRS()             { return *(AT91_DDRS     *)(size_t)(AT91_DDRS     ::c_Base                                      ); }
        // static AT91_PIT     & PIT()             { return *(AT91_PIT     *)(size_t)(AT91_PIT     ::c_Base                                      ); }
        //--//

};
