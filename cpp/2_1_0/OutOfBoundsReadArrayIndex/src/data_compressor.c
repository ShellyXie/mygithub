#include "data_compressor.h"

/**
 * 解压缩数据
 *
 * 使用 RLE 算法解压数据。
 */
int decompress_data(unsigned char *compressed_data, int compressed_len,
                    unsigned char *output_buffer, int output_size) {
  if (compressed_data == NULL || output_buffer == NULL || compressed_len <= 0 ||
      output_size <= 0) {
    return -1;
  }

  int input_index = 0;
  int output_index = 0;

  while (input_index < compressed_len) {
    unsigned char count = compressed_data[input_index];
    unsigned char value = compressed_data[input_index + 1];
    input_index += 2;

    for (int i = 0; i < (int)count; i++) {
      if (output_index < output_size) {
        output_buffer[output_index++] = value;
      } else {
        if (input_index < compressed_len) {
          return -1;
        }
        break;
      }
    }
  }

  return output_index;
}
