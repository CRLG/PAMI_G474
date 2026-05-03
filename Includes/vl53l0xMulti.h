#ifndef _VL53L0X_MULTI_H_
#define _VL53L0X_MULTI_H_
#include "vl53l0x.h"
#include "vl53l0xMultiBase.h"

class VL53L0xMulti : public VL53L0xMultiBase
{
public :
#define VL53_MAX_COUNT 4
    VL53L0xMulti(I2C_HandleTypeDef *i2c_hdl, unsigned int vl53_count=VL53_MAX_COUNT);

    VL53L0x m_vl53[VL53_MAX_COUNT];

    /*virtual*/uint8_t get_vl53_count() override;
    /*virtual*/VL53L0x *get_vl53(uint8_t index) override;
    /*virtual*/void set_reset_pin(uint8_t vl53_index, bool pin_state) override;
    /*virtual*/uint8_t get_i2c_address(uint8_t vl53_index) override;

private :
    unsigned int m_vl53_count; // représente le nombre réel de VL53 utilisés dans l'application
};

#endif // _VL53L0X_MULTI_H_
