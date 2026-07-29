#pragma once
#include <stddef.h>
int secure_random_int(int max);
void secure_random_bytes(unsigned char *buf,size_t len);
