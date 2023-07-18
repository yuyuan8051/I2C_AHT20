#ifndef __DHT20_H__
#define __DHT20_H__

#include "main.h"
#include "i2c.h"

// AHT20重置寄存器
void AHT20_ResetRegister(uint8_t addr);

// 初始化AHT20
void AHT20_Init(void);

// 获取温度和湿度
uint8_t AHT20_Read();

#endif
