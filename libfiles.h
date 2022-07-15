#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 1024
#define MAXSIZE 1000

int openFile(FILE* arq, char* path, char* dirName);

void printFile(FILE* arq);

void readDirectory(DIR* dirstream);

void readDirectoryFiles(DIR* dirstream, char* path);