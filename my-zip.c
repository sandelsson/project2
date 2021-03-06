/*******************************************************************/
/* Käyttäjärjestelmät ja systeemiohjelmointi
 * Harjoitusprojekti: Project 2 
 * Done by: Kukonlehto Joonas, Ruuskanen Santeri
 * Date: 7.4.2021
 * Source: https://www.geeksforgeeks.org/run-length-encoding/, 
https://stackoverflow.com/questions/19173442/reading-each-line-of-file-into-array/19174415
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RLEN 50

/* This program compresses one or multiple file(s) into one, it only compresses
the files first line as in the example. Last given argument is the output file 
and all files before that are used as input files. */

/* Returns the Run Length Encoded string for the
source string src */

/*source https://www.geeksforgeeks.org/run-length-encoding/ */

char *encode(char *src){
	int rLen = 0;
	char count[MAX_RLEN];
	int len = strlen(src);

	/* If all characters in the source string are different,
	then size of destination string would be twice of input string.
	For example if the src is "abcd", then dest would be "a1b1c1d1"
	For other inputs, size would be less than twice. */
	char* dest = (char*)malloc(sizeof(char) * (len * 2 + 1));

	int i, j = 0, k;

	/* traverse the input string one by one */
    for (i = 0; i < len; i++) {
 
        /* Count the number of occurrences of the new character */
        rLen = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            rLen++;
            i++;
        }
 
        /* Store rLen in a character array count[] */
        sprintf(count, "%d", rLen);
 
        /* Copy the count[] to destination */
        for (k = 0; *(count + k); k++, j++) {
            dest[j] = count[k];
        }
        /* Copy the first occurrence of the new character */
        dest[j++] = src[i];
    }
 
    /*terminate the destination string */
    dest[j] = '\0';
    return dest;
}
 
/* source: https://stackoverflow.com/questions/19173442/reading-each-line-of-file-into-array/19174415 */

char *read_file(char filename[40]){
    int lines_allocated = 128;
    int max_line_len = 100;

    /* Allocate lines of text */
    char **words = (char **)malloc(sizeof(char*)*lines_allocated);
    if (words==NULL)
        {
        fprintf(stderr,"Out of memory (1).\n");
        exit(1);
        }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        {
        fprintf(stderr,"Error opening file.\n");
        exit(2);
        }

    int i;
    for (i=0;1;i++)
        {
        int j;

        /* Have we gone over our line allocation? */
        if (i >= lines_allocated)
            {
            int new_size;

            /* Double our allocation and re-allocate */
            new_size = lines_allocated*2;
            words = (char **)realloc(words,sizeof(char*)*new_size);
            if (words==NULL)
                {
                fprintf(stderr,"Out of memory.\n");
                exit(3);
                }
            lines_allocated = new_size;
            }
        /* Allocate space for the next line */
        words[i] = malloc(max_line_len);
        if (words[i]==NULL)
            {
            fprintf(stderr,"Out of memory (3).\n");
            exit(4);
            }
        if (fgets(words[i],max_line_len-1,fp)==NULL)
            break;

        /* Get rid of CR or LF at end of line */
        for (j=strlen(words[i])-1;j>=0 && (words[i][j]=='\n' || words[i][j]=='\r');j--)
            ;
        words[i][j+1]='\0';
        }
    /* Close file */
    fclose(fp);
    return *words;

}

int main(int argc, char *argv[])
{

	char inputfile[40];
	char outputfile[40];
	char *res;
	FILE *fp_write = NULL;

	/*Checks that the user gave recuired amount of arguments */	

	if (argc < 3){
		fprintf(stderr,  "my-zip: <file1> <file2>... \n");
		exit(1);
	}
	
	/*Opening file and error handling */

	strcpy(outputfile, argv[argc-1]);
    	fp_write = fopen(outputfile, "w");
	if (fp_write == NULL) {
		fprintf(stderr, "error: cannot open file '%s'\n", outputfile);
		exit(1);	
	}
	
	int i;
	
	/* Writing the result to output file */

	for(i = 1; i < argc-1; i++){
		strcpy(inputfile, argv[i]);
		char *words = read_file(inputfile);
		res = encode(&words[0]);
		fprintf(fp_write, "%s", res);
		
	}
	
	printf("Thank you for using our program you can check the results from %s file.\n", outputfile);
	
	return 0;
}
