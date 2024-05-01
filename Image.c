//Vytis Etchegoyhen & Jaeiz Ocampo

#include <stdio.h>
#define MAX_SIZE 1000
#define FILE_NAME "image_file.txt"
//index

//=====================================================================================================================
void load(int rowsize, int colsize, int array[][colsize], FILE* fptr);
void display(int rowsize, int colsize, int array[][colsize], FILE* fptr);
int main(){
	//char image[1000][1000];
	int image[MAX_SIZE][MAX_SIZE];
	char choice;
	FILE* imagefileptr;
	
	imagefileptr = fopen(FILE_NAME, "r");
	
	printf("**ERINSTAGRAM**\n");
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit Program\n");
	printf("\nChoose from one of the options above: ");
	scanf("%c", &choice);
	
	if (choice == '1'){
		//load new image	
		
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
void load(int rowsize, int colsize, int array[][colsize], FILE* fptr){
	for(int i = 0; i < rowsize; i++){
		for(int j = 0; j < colsize; j++){
			fscanf(fptr, "%d", array[i][j]);
		}
	}
}
void display(int rowsize, int colsize, int array[][colsize], FILE* fptr){
	char convertImage[MAX_SIZE][MAX_SIZE];
	
}
//=====================================================================================================================

