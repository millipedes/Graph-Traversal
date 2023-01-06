#ifndef TYP_H
#define TYP_H

#include <stdio.h>
#include <stdlib.h>
#include "../../main/include/constants_macros.h"

typedef enum {
  INT,
  DOUBLE,
  CHAR,
} type;

const char * type_to_string(type the_type);
void print_value(void * the_value, type the_type);

#endif
