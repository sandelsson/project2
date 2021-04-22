# project2
2/3 of the project assignments for the course: CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi

There will be 4 different functions:
my-cat, my-grep, my-zip and my-unzip.

my-cat
Prints out the contents of files that user gives as command line arguments. There's 3 different files in the my-cat-folder that are used for testing the program. If no arguments given, the progam returns 0.

my-grep
Function to find lines from a file that contain user-given searchword. The function follows the syntax given in instructions (prompt> ./my-grep foo bar.txt). Here the first argument is the word you're searching from the file(s) and the following arguments are the files where you're looking for. There could be more than one input file. My-grep-folder includes 2 different textfiles that are used for testing. If only one command line argument is given, the program assumes it's the searchword. In this situation user must proceed to type in some lines manually and type in "0" when done. Then the program finds the searchword from the manually typed lines.

my-zip
Compresses all given files to output file using RLE. Compresses only the first lines of the file like in the example. Last given argument given by user is used as outputfile and files before that are used as input files. There are test.txt and test2.txt files ready for testing the program.

my-unzip
Decompresses given file and prints it's content to stdout. File needs to follow the syntax used in my-zip. There are test_input.z file ready for testing the program.

Santeri Ruuskanen; Joonas Kukonlehto
