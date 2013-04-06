#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dbase.h>
#include <hash.h>

char recordSeparator = 0x1E;
char extention[7] = "/.lpdb\0";

int main()
{
	FILE *database;

	master masterList;
	masterList.albums = NULL;
	masterList.length = 0;

	printf("Reticulating splines...\n");
	char *homedir = getenv("HOME");
	char *dbfile = malloc(4097);
	for(unsigned short int i=0;i<4090;i++)
	{
		if(*(homedir+i) == '\0')
		{
			for(unsigned short int j=0;j<7;j++)
			{
				*(dbfile+i+j) = extention[j];
			}
			break;
		}
		*(dbfile+i) = *(homedir+i);
	}
	database = fopen(dbfile,"rb");
	if(database == NULL)
	{
		printf("No .lpdb file found, creating new database...\n");
		database = fopen(dbfile,"wb");
		if(database == NULL)
		{
			printf("Couldn't create database file.\n");
			return 0;
		}
		printf("Done.\n");
	}
	else
	{
		rewind(database);
		char ch;
		char *thisname = NULL;
		char *thisartist = NULL;
		while(1)
		{
			ch = (char)(fgetc(database));
			if(ch == EOF)
			{
				break;
			}
			if(ch == recordSeparator)
			{
				masterList.length++;
				masterList.albums = realloc(masterList.albums,sizeof(album)*masterList.length);
				int namesize = 0;
				while(1)
				{
					ch = (char)(fgetc(database));
					if(ch == EOF)
					{
						printf("Database is corrupt.\nEOF inside of record name.\n");
						return 0;
					}
					else if(ch == '\0')
					{
						fseek(database,(-1)*(namesize+1),SEEK_CUR);
						thisname = malloc(namesize+1);
						for(unsigned int i=0;i<(namesize+1);i++)
						{
							*(thisname+i) = (char)fgetc(database);
						}
						break;
					}
					else
					{
						namesize++;
					}
				}
				(masterList.albums+(masterList.length-1))->name = thisname;
				int artistsize = 0;
				while(1)
				{
					ch = (char)fgetc(database);
					if(ch == EOF)
					{
						printf("Database is corrupt.\nEOF inside of record artist.\n");
						return 0;
					}
					else if(ch == '\0')
					{
						fseek(database,(-1)*(artistsize+1),SEEK_CUR);
						thisartist = malloc(artistsize+1);
						for(unsigned int i=0;i<(artistsize+1);i++)
						{
							*(thisartist+i) = (char)fgetc(database);
						}
						break;
					}
					else
					{
						artistsize++;
					}
				}
				(masterList.albums+(masterList.length-1))->artist = thisartist;
				char yearchars[2];
				yearchars[0] = (char)fgetc(database);
				yearchars[1] = (char)fgetc(database);
				(masterList.albums+(masterList.length-1))->year = *(unsigned short int*)yearchars;
				printf("Just added this album year: %d\n",(masterList.albums+(masterList.length-1))->year);
			}
			else
			{
				printf("Database is corrupt.\nExtra characters between records.\n");
				return 0;
			}
		}
	}
	free(dbfile);
	fclose(database);
	return 0;
}
