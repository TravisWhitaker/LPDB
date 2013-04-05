#include <stdio.h>

#include <openssl/sha.h>

int main()
{
	unsigned char data[12] = "0123456789a\0";
	unsigned char output[21];
	SHA1(data,12,output);
	return 0;
}
