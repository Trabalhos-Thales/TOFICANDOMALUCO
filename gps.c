#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "libfiles.h"
#include "libbikes.h"

#define MAX 1000

int main(int argc, char** argv){

    char* path = NULL;
    int option;
    int nlogs;
    
    opterr = 0;

    while((option = getopt(argc, argv, "d:")) != -1){
        switch (option){
            case 'd':
            path = optarg;
            break;
        }        
    }

    DIR *dirstream = opendir(path);

    if(!dirstream)
        fprintf(stderr,"Erro ao abrir o Diretorio");
        
    nlogs=countLogs(dirstream,path);

    log_b** bikelogs = malloc(sizeof(log_b)*nlogs);

    printf("\nDIRETORIO: %s\n", path);
    printf("TOTAL DE LOGS: %d\n", nlogs);
    printf("\n////INICIO DA LEITURA////\n\n");

    readLogs(dirstream,path, bikelogs);

    printf("\n////FIM DA LEITURA////\n");
        
    free(bikelogs);
   
    closedir(dirstream);


    return 0;

}
