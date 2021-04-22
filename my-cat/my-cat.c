/*******************************************************************/
/* Käyttäjärjestelmät ja systeemiohjelmointi
 * Harjoitusprojekti: Project 2 
 * Done by: Kukonlehto Joonas, Ruuskanen Santeri
 * Date: 5.4.2021
 * Source:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void read_file(int argc, int i, char filename[40]){
    char line[200];
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp==NULL){
        printf("my-cat: cannot open file %s\n", filename);
        //printf("Error when trying to open '%s' -file\n", filename);
        exit(0);
    }
    
    for(;;){
        if (fgets(line,150, fp) == NULL){
            break;
        }
        printf("%s", line);
    }
    printf("\n");
    fclose(fp);
}


int main(int argc, char *argv[]){
    //FILE *fp;
    //strcpy(filename, argv[1]);

    //fp = fopen(argv[1], "r");
    
    if (argc==1){
    	return 0;
    }

    char filename[40];

    for(int i = 1; i < argc; i++){
        strcpy(filename, argv[i]);
        printf("%d. input file contents: \n\n", i);
        read_file(i, argc, filename);
            
    }
    }

