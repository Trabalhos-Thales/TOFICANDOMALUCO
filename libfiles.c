#include "libfiles.h"

int openFile(FILE* arq, char* path, char* dirName){
    char buffer[MAXSIZE];
    strcat(strcpy(buffer, path), dirName);
    //memccpy(memccpy(buffer, path, '\0', MAXSIZE) -1, dirName, '\0', MAXSIZE);
    
   printf("%s\n",buffer);
    arq = fopen(buffer, "r");

    if (!arq){
      
        perror ("Erro ao abrir arquivo") ;
        return 1;
    
    }

    printFile(arq);
    fclose(arq);
    return 0;
}

void printFile(FILE* arq){

    char line[LINESIZE+1];

    fgets (line, LINESIZE, arq);

    //while (!feof(arq)){
    
    printf(" %s", line);

    //}
    
}

void readDirectory(DIR* dirstream){
    struct dirent *direntry;   
    // varre as entradas do diretório aberto
    for (;;){
    // pega a próxima entrada
    direntry = readdir (dirstream) ;
 
    // se for nula, encerra a varredura
    if (! direntry)
        break ;
 
    // mostra conteúdo da entrada
    printf ("%s\t\n", direntry->d_name);
    }        
}

void readDirectoryFiles(DIR* dirstream, char* path){
    struct dirent *direntry;   
    FILE* arq=NULL;
    printf("%s\n", path);
    for (;;){
        // pega a próxima entrada
        direntry = readdir (dirstream) ; 

        // se for nula, encerra a varredura
        if (! direntry)
            break ;

                
        if(direntry->d_type!=DT_DIR){
            printf("Currently reading: %s ...\n", direntry->d_name);
            openFile(arq, path, direntry->d_name);
            fclose(arq);
        }
    }          

}