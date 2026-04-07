#include "vm_config_parser.h"
#include <stdarg.h>

/**
 * 内部辅助函数，使用 vsscanf 进行格式化解析
 */
static int parse_helper(const char *config_line, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int items = vsscanf(config_line, format, args);
  va_end(args);
  return items;
}

int parse_vm_config(const char *config_line,
                    struct vm_hardware_config *hw_config) {
  if (config_line == NULL || hw_config == NULL || strlen(config_line) == 0) {
    return -1;
  }

  // 初始化结构体
  memset(hw_config, 0, sizeof(struct vm_hardware_config));

  const char *format =
      "cpu_model=%[^,],memory_mb=%d,disk_path=%[^,],network_adapter=%s";

  int result =
      sscanf(config_line, format, hw_config->cpu_model, &hw_config->memory_mb,
             hw_config->disk_path, hw_config->network_adapter);

  if (result != 4) {
    return -1;
  }

  return 0;
}
