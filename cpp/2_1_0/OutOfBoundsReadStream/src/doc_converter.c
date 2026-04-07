#include "doc_converter.h"

char get_doc_char_at(unsigned char *doc_data, int doc_size, int text_offset,
                     int char_index) {
  if (doc_data == NULL) {
    return (char)0xff;
  }

  return (char)doc_data[text_offset + char_index];
}
