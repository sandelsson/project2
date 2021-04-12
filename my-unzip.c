/*******************************************************************/
/* Käyttäjärjestelmät ja systeemiohjelmointi
 * Harjoitusprojekti: Project 2 
 * Done by: Kukonlehto Joonas, Ruuskanen Santeri
 * Date: 12.4.2021
 * Source:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]){
	char letter [10];
	int number;
	char filename[40];
	int error;

	/*Checks that the user gave the right amount of arguments */ 

	if (argc != 2){
		fprintf(stderr,  "my-unzip input_file.z\n");
		exit(1);
	}	

	strcpy(filename, argv[1]);
	
	/*Opening the file and error handling */	

	FILE *fp = fopen(filename, "r");
	if(fp == NULL) {
		fprintf(stderr, "Unable to open file!\n");
		exit(1);
	}

	/*Goes throug the line taking the integer and letter after it and prints
	the letter x amount of times, error handling if fscanf doenst get 2 values*/

	while ((error = fscanf(fp, "%d%c", &number, letter)) != EOF){	
		if (error != 2 ){
		fprintf(stderr, "Input doesnt follow the required syntax of dcdc... (d = Integer, c = Char \n");
		exit(1);
		}		
		
		for (int i=0; i < number; i++) {
			printf("%s", letter);
		
		}	
	} 	

	printf("\n");
	fclose(fp);
	return 0;

}


	
	



