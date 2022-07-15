#include "libbikes.h"

int openLog(FILE* arq, char* path, char* dirName, log_b* bikelog, int i){
    char buffer[MAXSIZE];

    strcat(strcpy(buffer, path), dirName);

    arq = fopen(buffer, "r");

    if (!arq){
      
        perror ("Erro ao abrir arquivo") ;
        return 1;
        
    }
    
    leNomeBike(arq, buffer, bikelog, i);
    printLog(arq);
    fclose(arq);
    return 0;
}

void leNomeBike(FILE *arq, char* path, log_b* bikelog, int i){
    char* token = malloc(sizeof(char)*MAXSIZE);
    char* nome = malloc(sizeof(char)*MAXSIZE);
    bikelog[i].gearname = malloc(sizeof(char)*MAXSIZE);
    if(token==NULL){
        printf("Erro na criacao do token");
    }
    fgets(token, MAXSIZE, arq);
    char* aux = token;

    token = strtok(token, ": ");
    token = strtok(NULL, " ");

    while(token){
        strcat(nome, token);
        strcat(nome, " ");
        token = strtok(NULL, " ");
    }
    strtok(nome, "\n");
    strcpy(bikelog[i].gearname,nome);
    free(nome);
    free(aux);
}

void printLog(FILE* arq){

    char line[LINESIZE+1];

    fgets (line, LINESIZE, arq);    
    //printf(" %s", line);

}

int countLogs(DIR* dirstream, char* path){
    struct dirent *direntry;   
    int count = 0;
    while ((direntry = readdir(dirstream))){
        if(direntry->d_type==DT_REG){
            count++;
        }
    }        

    rewinddir(dirstream);  
    return count;
}

void readLogs(DIR* dirstream, char* path, log_b* bikelog){
    struct dirent *direntry;   
    FILE* arq=NULL;
    int i = 0;

    while ((direntry = readdir(dirstream))){
        if(direntry->d_type!=DT_DIR){
            bikelog[i].archivename = direntry->d_name;
            printf("Currently reading: %s ...\n", direntry->d_name);
            openLog(arq, path, direntry->d_name, bikelog,i);
            i++;
        }
    }          
}
