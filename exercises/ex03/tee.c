/*
* tee.c
* Kathryn Hite
* Implementation of tee command
* Flags:
* 			-a: appends output to the end of a file, does not overwrite
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	char read_c;
	char read_line[100]; // Read in standard line length
	int append_flag;

	// Read the command line input flags
	while((read_c = getopt(argc, argv, "a")) != EOF) {
		switch(read_c) {

			case 'a':
				printf("Append Mode \n");
				append_flag = 1;
				break;

			default:
				return 1;
		}
	}

	// Read the list of file arguments
  	argc -= optind;
	argv += optind;
	FILE *file_set[argc];

	// Create array of file pointers
	int files;
	printf("Reading files: \n");
	for (files = 0; files < argc; files++) {
		printf("%s\n", argv[files]);
        file_set[files] = fopen(argv[files], (append_flag ? "a" : "w"));
	}
	printf("\n");

	// Output to stdout and files
	while (scanf ("%79[^\n]\n", file_set) == 1) {

    	for (files = 0; files < argc; files++) {
     		fprintf(file_set[files], "%s\n", read_line);
    	}

    	printf("%s\n", read_line);

	}

  	// Exit files
  	for (files = 0; files < argc; files++) {
    	fclose(file_set[files]);
  	}

	return 0;
}

/*
* 3) I worked through the implementation process by first reading the 
* provided resources as well as a few other sites to figure out how tee 
* works and what flags I needed to implement.  After the functionality was 
* outlined, I filled in the individual parts of the solution and tested as 
* often as possible.  I ended up going back and reading through the HFC 
* chapter once more because it had been a while, which slowed me down a bit.
* With a more complex implementation and more time, I would have also broken 
* the program down into more functions with extended capabilities.
* 
* 4) The original version provides more command line arguments and is
* is implemented using structs and other cleaner structures than what I 
* ended up with.
*/