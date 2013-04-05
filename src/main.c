#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dbase.h>
#include <hash.h>

int main()
{
	master masterList;
	masterList.length = 101;
	masterList.albums = malloc(sizeof(album)*101);
	if(masterList.albums == NULL)
	{
		printf("malloc failed\n");
	}
	return 0;
}
