#include <aht20.h>

#define AHT20_ADDRESS 0x70

/**
 * @brief AHT20初始化命令
 */
void AHT20_InitCmd() {
  uint8_t send_buf[3] = {0xBE, 0x08, 0x00};
  HAL_I2C_Master_Transmit_DMA(&hi2c1, AHT20_ADDRESS, send_buf, 3);
  HAL_Delay(100);
}

/**
 * @brief 初始化AHT20
 */
void AHT20_Init(void) {
  uint8_t read_buf = 0;
  // 等待DHT20上电稳定
  HAL_Delay(40);
  HAL_I2C_Master_Receive(&hi2c1, AHT20_ADDRESS, &read_buf, 1, 10);
  if ((read_buf & 0x08) != 0x08) {
    AHT20_InitCmd();
  }
}

/**
 * @brief 获取温度和湿度
 *
 * @param Temperature 用于接收温度的变量地址
 * @param Humidity 用于接收湿度的变量地址
 *
 * @note 建议获取间隔大于500毫秒
 */
uint8_t AHT20_Read() {
  uint8_t cmd_ac[3] = {0xAC, 0x33, 0x00};
//  int32_t data = 0;
  HAL_I2C_Master_Transmit_DMA(&hi2c1, AHT20_ADDRESS, cmd_ac, 3);
  HAL_Delay(75);
  HAL_I2C_Master_Receive_DMA(&hi2c1, AHT20_ADDRESS, readBuffer, 6);
//  if ((read_buf[0] & 0x80) != 0x80) {
//    data = ((uint32_t)read_buf[3] >> 4) + ((uint32_t)read_buf[2] << 4) + ((uint32_t)read_buf[1] << 12);
//    *Humidity = data * 100.0f / (1 << 20);
//
//    data = (((uint32_t)read_buf[3] & 0x0F) << 16) + (((uint32_t)read_buf[4]) << 8) + (uint32_t)read_buf[5];
//    *Temperature = data * 200.0f / (1 << 20) - 50;
//    return 1;
//  }
  return 0;
}
