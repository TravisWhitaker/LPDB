#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dbase.h>
#include <hash.h>

int main()
{
	FILE *serial;
	serial = fopen("lol","wb");
	master masterList;
	masterList.length = 10000000;
	masterList.albums = malloc(sizeof(album)*10000000);
	if(masterList.albums == NULL)
	{
		printf("malloc failed\n");
		return 0;
	}
	fwrite(&(masterList.length),sizeof(unsigned long int),1,serial);
	fwrite(masterList.albums,sizeof(album),masterList.length,serial);
	fclose(serial);
	return 0;
}
