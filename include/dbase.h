#ifndef DBASE
#define DBASE

typedef struct
{
	char name[866];
	char artist[151];
	unsigned int year;
} album;

typedef struct
{
	album *albums;
	unsigned int length;
} master;

typedef struct
{
	album **albums;
	unsigned int length;
} nameTable;

typedef struct
{
	album **albums;
	unsigned int length;
} artistTable;

typedef struct
{
	album **albums;
	unsigned int length;
} yearTable;

#endif
