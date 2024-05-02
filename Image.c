//Vytis Etchegoyhen & Jaeiz Ocampo

#include <stdio.h>
#define MAX_SIZE 1000
#define FILE_NAME "test_image.txt"
//index
void load(int rowsize, int colsize, int array[][colsize], FILE* fptr);
void display(int rowsize, int colsize, int array[][colsize], FILE* fptr);
//=====================================================================================================================
int main(){
	//char image[1000][1000];
	int image[MAX_SIZE][MAX_SIZE];
	char choice;
	int colsize;
	int rowsize;
	FILE* imagefileptr;
	
	printf("**ERINSTAGRAM**\n");
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit Program\n");
	printf("\nChoose from one of the options above: ");
	scanf("%c", &choice);
	
	if (choice == '1'){
		//load new image
		char filename[30];
		printf("What is the name of the image file? ");
		while(fgets(filename, 30, stdin) != NULL){
		}
		
		
	//I'm working on this bit so that it opens the file we input in the prompt...
		imagefileptr = fopen(filename, "r");
		if (imagefileptr != NULL){
			printf("Input file open\n");
		}else{
			printf("Input file does not exist.\nGoodbye!\n");
		}
	}else if (choice == '2'){
		//display current image
		
		
	}else if (choice == '3'){
		//edit current image
		printf("**Edit Current Image**\n");
		printf("1: Crop image\n");
		printf("2: Dim image\n");
		printf("3: Brighten image\n");
		printf("0: Return to main menu\n");
		printf("\nChoose from one of the options above: ");
		scanf(" %c", &choice);
		
		if (choice == '1'){
			//crop
			
		}else if (choice == '2'){
			//dim
			
		}else if (choice == '3'){
			//lighten
			
		}else if (choice == '4'){
			//rotate 90*
			
		}else{
			printf("\nGoodbye!\n\n");
			return 0;
		}
	}else{
		printf("\nGoodbye!\n\n");
		return 0;
	}

	fclose(imagefileptr);	
return 0;
}
//=====================================================================================================================
void load(int rowsize, int colsize, int array[][colsize], FILE* fptr){
	//finding the row and col sizes
	colsize = 0;
	rowsize = 0;
	for(int i = 0; i != '\0'; i++){
		colsize++;
	}
	//using the row and col sizes
	for(int i = 0; i < rowsize; i++){
		for(int j = 0; j < colsize; j++){
			//fscanf(fptr, "%d", array[i][j]);
		}
	}
}
void display(int rowsize, int colsize, int array[][colsize], FILE* fptr){
	char convertImage[MAX_SIZE][MAX_SIZE];
	
}
