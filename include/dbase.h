#ifndef DBASE
#define DBASE

typedef struct
{
	char *name;
	char *artist;
	unsigned short int year;
} album;

typedef struct
{
	album *albums;
	unsigned long int length;
} master;

typedef struct
{
	album **albums;
	unsigned long int length;
} nameTable;

typedef struct
{
	album **albums;
	unsigned long int length;
} artistTable;

typedef struct
{
	album **albums;
	unsigned long int length;
} yearTable;

#endif
