// Copyright Microsoft Corporation
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

#include "AT91.h"

struct AT91_I2c_Configuration {

    int32_t                  address;
    uint8_t                  clockRate;     // primary clock factor to generate the i2c clock
    uint8_t                  clockRate2;   // additional clock factors, if more than one is needed for the clock (optional)
};

struct AT91_I2c_Transaction {
    bool                        isReadTransaction;
    bool                        repeatedStart;
    bool                        isDone;

    uint8_t                     *buffer;

    size_t                      bytesToTransfer;
    size_t                      bytesTransferred;

    TinyCLR_I2c_TransferStatus  result;
};

#define I2C_TRANSACTION_TIMEOUT 2000 // 2 seconds

static AT91_I2c_Configuration g_I2cConfiguration;
static AT91_I2c_Transaction   *g_currentI2cTransactionAction;
static AT91_I2c_Transaction   g_ReadI2cTransactionAction;
static AT91_I2c_Transaction   g_WriteI2cTransactionAction;

static TinyCLR_I2c_Provider i2cProvider;
static TinyCLR_Api_Info i2cApi;

const TinyCLR_Api_Info* AT91_I2c_GetApi() {
    i2cProvider.Parent = &i2cApi;
    i2cProvider.Index = 0;
    i2cProvider.Acquire = &AT91_I2c_Acquire;
    i2cProvider.Release = &AT91_I2c_Release;
    i2cProvider.SetActiveSettings = &AT91_I2c_SetActiveSettings;
    i2cProvider.Read = &AT91_I2c_ReadTransaction;
    i2cProvider.Write = &AT91_I2c_WriteTransaction;
    i2cProvider.WriteRead = &AT91_I2c_WriteReadTransaction;

    i2cApi.Author = "GHI Electronics, LLC";
    i2cApi.Name = "GHIElectronics.TinyCLR.NativeApis.AT91.I2cProvider";
    i2cApi.Type = TinyCLR_Api_Type::I2cProvider;
    i2cApi.Version = 0;
    i2cApi.Count = 1;
    i2cApi.Implementation = &i2cProvider;

    return &i2cApi;
}

void AT91_I2c_InterruptHandler(void *param) {
    uint8_t address;
    
}
void AT91_I2c_StartTransaction() {    
    if (!g_WriteI2cTransactionAction.repeatedStart || g_WriteI2cTransactionAction.bytesTransferred == 0) {
       
    }
    else {
        
    }

}

void AT91_I2c_StopTransaction() {
   

    g_currentI2cTransactionAction->isDone = true;

}

TinyCLR_Result AT91_I2c_ReadTransaction(const TinyCLR_I2c_Provider* self, uint8_t* buffer, size_t& length, TinyCLR_I2c_TransferStatus& result) {
    int32_t timeout = I2C_TRANSACTION_TIMEOUT;

    g_ReadI2cTransactionAction.isReadTransaction = true;
    g_ReadI2cTransactionAction.buffer = buffer;
    g_ReadI2cTransactionAction.bytesToTransfer = length;
    g_ReadI2cTransactionAction.isDone = false;
    g_ReadI2cTransactionAction.repeatedStart = false;
    g_ReadI2cTransactionAction.bytesTransferred = 0;

    g_currentI2cTransactionAction = &g_ReadI2cTransactionAction;

    AT91_I2c_StartTransaction();

    while (g_currentI2cTransactionAction->isDone == false && timeout > 0) {
        AT91_Time_Delay(nullptr, 1000);

        timeout--;
    }

    if (g_currentI2cTransactionAction->bytesTransferred == length)
        result = TinyCLR_I2c_TransferStatus::FullTransfer;
    else if (g_currentI2cTransactionAction->bytesTransferred < length && g_currentI2cTransactionAction->bytesTransferred > 0)
        result = TinyCLR_I2c_TransferStatus::PartialTransfer;

    length = g_currentI2cTransactionAction->bytesTransferred;

    return timeout > 0 ? TinyCLR_Result::Success : TinyCLR_Result::TimedOut;
}

TinyCLR_Result AT91_I2c_WriteTransaction(const TinyCLR_I2c_Provider* self, const uint8_t* buffer, size_t& length, TinyCLR_I2c_TransferStatus& result) {
    int32_t timeout = I2C_TRANSACTION_TIMEOUT;

    g_WriteI2cTransactionAction.isReadTransaction = false;
    g_WriteI2cTransactionAction.buffer = (uint8_t*)buffer;
    g_WriteI2cTransactionAction.bytesToTransfer = length;
    g_WriteI2cTransactionAction.isDone = false;
    g_WriteI2cTransactionAction.repeatedStart = false;
    g_WriteI2cTransactionAction.bytesTransferred = 0;

    g_currentI2cTransactionAction = &g_WriteI2cTransactionAction;

    AT91_I2c_StartTransaction();

    while (g_currentI2cTransactionAction->isDone == false && timeout > 0) {
        AT91_Time_Delay(nullptr, 1000);

        timeout--;
    }

    if (g_currentI2cTransactionAction->bytesTransferred == length)
        result = TinyCLR_I2c_TransferStatus::FullTransfer;
    else if (g_currentI2cTransactionAction->bytesTransferred < length && g_currentI2cTransactionAction->bytesTransferred > 0)
        result = TinyCLR_I2c_TransferStatus::PartialTransfer;

    length = g_currentI2cTransactionAction->bytesTransferred;

    return timeout > 0 ? TinyCLR_Result::Success : TinyCLR_Result::TimedOut;
}

TinyCLR_Result AT91_I2c_WriteReadTransaction(const TinyCLR_I2c_Provider* self, const uint8_t* writeBuffer, size_t& writeLength, uint8_t* readBuffer, size_t& readLength, TinyCLR_I2c_TransferStatus& result) {
    int32_t timeout = I2C_TRANSACTION_TIMEOUT;

    g_WriteI2cTransactionAction.isReadTransaction = false;
    g_WriteI2cTransactionAction.buffer = (uint8_t*)writeBuffer;
    g_WriteI2cTransactionAction.bytesToTransfer = writeLength;
    g_WriteI2cTransactionAction.isDone = false;
    g_WriteI2cTransactionAction.repeatedStart = true;
    g_WriteI2cTransactionAction.bytesTransferred = 0;

    g_ReadI2cTransactionAction.isReadTransaction = true;
    g_ReadI2cTransactionAction.buffer = readBuffer;
    g_ReadI2cTransactionAction.bytesToTransfer = readLength;
    g_ReadI2cTransactionAction.isDone = false;
    g_ReadI2cTransactionAction.repeatedStart = false;
    g_ReadI2cTransactionAction.bytesTransferred = 0;

    g_currentI2cTransactionAction = &g_WriteI2cTransactionAction;

    AT91_I2c_StartTransaction();

    while (g_currentI2cTransactionAction->isDone == false && timeout > 0) {
        AT91_Time_Delay(nullptr, 1000);

        timeout--;
    }

    if (g_WriteI2cTransactionAction.bytesTransferred != writeLength) {
        writeLength = g_WriteI2cTransactionAction.bytesTransferred;
        result = TinyCLR_I2c_TransferStatus::PartialTransfer;
    }
    else {
        readLength = g_ReadI2cTransactionAction.bytesTransferred;

        if (g_currentI2cTransactionAction->bytesTransferred == readLength)
            result = TinyCLR_I2c_TransferStatus::FullTransfer;
        else if (g_currentI2cTransactionAction->bytesTransferred < readLength && g_currentI2cTransactionAction->bytesTransferred > 0)
            result = TinyCLR_I2c_TransferStatus::PartialTransfer;
    }

    return timeout > 0 ? TinyCLR_Result::Success : TinyCLR_Result::TimedOut;
}

TinyCLR_Result AT91_I2c_SetActiveSettings(const TinyCLR_I2c_Provider* self, int32_t slaveAddress, TinyCLR_I2c_BusSpeed busSpeed) {
    uint32_t rateKhz;

    if (busSpeed == TinyCLR_I2c_BusSpeed::FastMode)
        rateKhz = 400; // FastMode
    else if (busSpeed == TinyCLR_I2c_BusSpeed::StandardMode)
        rateKhz = 100; // StandardMode
    else
        return TinyCLR_Result::NotSupported;

    uint32_t divider = 0;

    g_I2cConfiguration.clockRate = (uint8_t)divider; // low byte
    g_I2cConfiguration.clockRate2 = (uint8_t)(divider >> 8); // high byte
    g_I2cConfiguration.address = slaveAddress;

    return TinyCLR_Result::Success;
}

TinyCLR_Result AT91_I2c_Acquire(const TinyCLR_I2c_Provider* self) {    
    if (!AT91_Gpio_OpenPin(AT91_I2C_SDA_PIN) || !AT91_Gpio_OpenPin(AT91_I2C_SCL_PIN))
        return TinyCLR_Result::SharingViolation;

    AT91_Gpio_ConfigurePin(AT91_I2C_SDA_PIN, AT91_Gpio_Direction::Input, AT91_I2C_SDA_ALT_MODE, AT91_Gpio_PinMode::Inactive);
    AT91_Gpio_ConfigurePin(AT91_I2C_SCL_PIN, AT91_Gpio_Direction::Input, AT91_I2C_SCL_ALT_MODE, AT91_Gpio_PinMode::Inactive);

    return TinyCLR_Result::Success;
}

TinyCLR_Result AT91_I2c_Release(const TinyCLR_I2c_Provider* self) {
    
    AT91_Gpio_ClosePin(AT91_I2C_SDA_PIN);
    AT91_Gpio_ClosePin(AT91_I2C_SCL_PIN);

    return TinyCLR_Result::Success;
}

void AT91_I2c_Reset() {
    AT91_I2c_Release(&i2cProvider);
}

