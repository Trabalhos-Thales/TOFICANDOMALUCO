#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000
#define LINESIZE 1024

typedef struct log{
    char* archivename;
    char* gearname;
    char* date;
    int tamanho;
}log_b;

typedef struct bike{
    char* name;
    log_b* log;
}nodo_b;

int countLogs(DIR* dirstream, char* path);

void readLogs(DIR* dirstream, char* path, log_b* bikelog);

int openLog(FILE* arq, char* path, char* dirName, log_b* bikelog, int i);

void printLog(FILE* arq);

void leNomeBike(FILE *arq, char* path, log_b* bikelog, int i);