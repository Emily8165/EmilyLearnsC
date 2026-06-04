#ifndef HEX_H
#define HEX_H

int hexlet_to_int(char letter);

char int_to_hex(int val);

int hex_to_dec(char *hex);

char *_dec_to_hex(int dec, char *result, int iter);

char *dec_to_hex(int dec);

#endif