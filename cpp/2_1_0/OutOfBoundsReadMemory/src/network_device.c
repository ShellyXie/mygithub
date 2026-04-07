#include "network_device.h"

/**
 * 从网络设备配置参数数组中获取指定索引的参数值
 */
int get_device_config_param(int config_params[50], int param_index,
                            int *param_value) {
  if (param_value == NULL) {
    return -1;
  }

  if (param_index < 128) {
    *param_value = config_params[param_index];
    return 0;
  }

  return -1;
}
