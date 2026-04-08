#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_container_layers(char **layer_data, int layer_count, int layer_index,
                           int max_layer_size) {
  if (layer_data == NULL) {
    return -1;
  }

  char *target_layer = layer_data[layer_index];

  char temp_buffer[256];

  strcpy(temp_buffer, target_layer);

  int processed_size = (int)strlen(temp_buffer);

  if (processed_size > max_layer_size) {
    return -1;
  }

  return processed_size;
}
