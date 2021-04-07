/*******************************************************************/
/* Käyttäjärjestelmät ja systeemiohjelmointi
 * Harjoitusprojekti: Project 2 
 * Done by: Kukonlehto Joonas, Ruuskanen Santeri
 * Date: 6.4.2021
 * Source:
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 100






//Function for reading users input when only the search_word has been given
//Basically adding all the input strings that contain the search_word and the printing out the list

int search_stdin(char search_word[40]){
	printf("Type in some inputs and enter '0' (zero) when you're done!\n\n");


	char *line = NULL;
	size_t len = 0;
     	
     	char matching_lines[MAX][MAX];
     	
     	//printf("DEBUG 0 \n");
     
     
     	int i = 0;
     	//while(getline(&line, &len, stdin)) {
     	while(getline(&line, &len, stdin) != -1) {
     		//printf("%s\n", line);
     		if (strcmp(line, "0\n") == 0){
     			break;
     		}
     	
     		if(strstr(line, search_word) != NULL) {
        		//printf("%s", line);
        		strcpy(matching_lines[i], line);
        	}
        	i++;
     
     	}
     	free(line);
     	
     	//printf("DEBUG1\n");
     	
     	fprintf(stdout, "\n\nThese are the input-lines that contained the word '%s'\n\n", search_word);
     	
     	for(int x = 0; x < i; x++){
     		printf("%s", matching_lines[x]);
     	
     	}
     	
     	fprintf(stdout, "\n\n\n");
     	
     	
     	
     	
     	return 0;




}





//Function for searching file for lines containing the search_word

void search_file(char filename[40], char search_word[40]){


	FILE *fp = fopen(filename, "r");
	if(fp == NULL) {
		perror("Unable to open file!");
		exit(0);
	}
	
	
	    
     
     char *line = NULL;
     size_t len = 0;
     
     
     
     printf("These are the lines that contained the word '%s' in %s-file\n\n", search_word, filename);
     
     
     
     while(getline(&line, &len, fp) != -1) {
     	
     	if(strstr(line, search_word) != NULL) {
        	printf("%s", line);
        }
     
     }
     
     printf("\n\n");
     
      
 
     fclose(fp);
     free(line);


}
	



int main(int argc, char *argv[]){

	char search_word[MAX];
	char filename[MAX];
	
	/*printf("debuggaus 1\n");
	
	strcpy(search_word, argv[1]);
	printf("search word strcpy ok\n");
	strcpy(search_word, argv[2]);
	*/
	
	if (argc < 2){
		printf("Invalid number of parameters.\nUser format <word><file> ( file is voluntary )\n\n");
		exit(0);
	}


	

	
	
	if (argc == 2){
		strcpy(search_word, argv[1]);
		//printf("You only gave the word you're looking for but not file\n");
		search_stdin(search_word);
		return 0;
	}
	
	//printf("DEBUG1\n");
	//printf("%d\n", argc);
	if (argc > 2){
		for(int i = 2; i < argc; i++){
			strcpy(search_word, argv[1]);
			//printf("search word strcpy ok\n");
			strcpy(filename, argv[i]);
			//printf("Filename strcpy ok\n");
			search_file(filename, search_word);
		
		}
	}
	
	//printf("DEBUG2\n");
	
	
	fprintf(stdout, "Thank you for using the program!!\n");
	return 0;
			
	
	

}




