#include "vl53l0xMulti.h"
#include "main.h"
// _____________________________________________
VL53L0xMulti::VL53L0xMulti(I2C_HandleTypeDef *i2c_hdl, unsigned int vl53_count)
	: VL53L0xMultiBase(i2c_hdl)
{
    if (vl53_count <= VL53_MAX_COUNT)   m_vl53_count = vl53_count;
    else                                m_vl53_count = VL53_MAX_COUNT;
}

// _____________________________________________
uint8_t VL53L0xMulti::get_vl53_count()
{
    return m_vl53_count;
}

// _____________________________________________
VL53L0x * VL53L0xMulti::get_vl53(uint8_t index)
{
    if (index >= VL53_MAX_COUNT) return &m_vl53[0];
	return &m_vl53[index];
}

// _____________________________________________
void VL53L0xMulti::set_reset_pin(uint8_t vl53_index, bool pin_state)
{
	switch(vl53_index) {
	case 0:
		HAL_GPIO_WritePin(Stor1_GPIO_Port, Stor1_Pin, (GPIO_PinState)pin_state);
		break;
	case 1:
		HAL_GPIO_WritePin(Stor2_GPIO_Port, Stor2_Pin, (GPIO_PinState)pin_state);
		break;
    case 2:
        // provision
        break;
    case 3:
        // provision
        break;
    default:
		break;
	}
}

// _____________________________________________
uint8_t VL53L0xMulti::get_i2c_address(uint8_t vl53_index)
{
    const uint8_t addr[VL53_MAX_COUNT] = { 0x52, 0x50, 0x48, 0x46 };
    if (vl53_index >= VL53_MAX_COUNT) return addr[0];
	return addr[vl53_index];
}



