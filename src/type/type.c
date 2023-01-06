#include "include/type.h"

const char * type_to_string(type the_type) {
  switch(the_type) {
    case INT:    return "Int";
    case DOUBLE: return "Double";
    case CHAR:   return "Char";
  }
  return NULL;
}

void print_value(void * the_value, type the_type) {
  switch(the_type) {
    case INT:    printf("%d", *((int *)the_value));    break;
    case DOUBLE: printf("%f", *((double *)the_value)); break;
    case CHAR:   printf("%c", *((char *)the_value));   break;
    default:
      fprintf(stderr, "[LIETRAL_VALUE]: Something Went Wrong\nExiting\n");
      exit(1);
  }
}
