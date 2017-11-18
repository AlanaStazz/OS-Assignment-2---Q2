//Filecopy Program
//Alana Staszczyszyn & Elijah Tavenor
//OS Design - Assignment 2 Pt 2

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc != 3){
		fprintf(stderr, "Format error; usage: filecopy <input_file_name> <output_file_name>\n");
	}

	//Variables
	int fd[2];		//Stores file descriptors
	pid_t chID;		
	int len;
	char buff[1024];
	int readNum;

	//Make pipe
	pipe(fd);

	//Open the files taken in from cmd line args
	char *inPath = argv[1];
	char *cpyPath = argv[2];

	int inFile = open(inPath, O_RDONLY, 0);

	if(inFile == -1){
		fprintf(stderr, "\n\nERROR: Opening input file failed.");
		exit(1);
	}

	int cpyFile = open(cpyPath, O_CREAT | O_WRONLY, 0666);

	if(cpyFile == -1){
		fprintf(stderr, "\n\nERROR: Opening output file failed.");
		exit(1);
	}

	//Fork the child (hehehehehe...)
	chID = fork();

	//Child process
	if(chID == 0){
		
		//Close output end of pipe while file is being read
		close(fd[1]);

		//Read file		
		read(fd[0], buff, sizeof(buff));

		//Writing to file
		write(cpyFile, buff, strlen(buff));
	}	
	//Parent process
	else{
		//Close input side of pipe
		close(fd[0]);

		//Read from file
		while((readNum = read(inFile,buff, sizeof(buff)) > 0)){
			write(fd[1], buff, sizeof(buff));
		}

		//Close pipe output & exit
		close(fd[1]);
		exit(0);
	}
}

