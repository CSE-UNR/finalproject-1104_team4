//Vytis Etchegoyhen & Jaeiz Ocampo

#include <stdio.h>

#define Y_SIZE 100
#define X_SIZE 100

#define FILE_NAME "test_image.txt"
//index
void load(char image_array[][X_SIZE], FILE* imagefileptr, int *colm, int *row);
void display(char image_array[][X_SIZE], FILE* imagefileptr, int *colm);
void crop(int rowSize, int colSize, char image_array[][X_SIZE]);
//=====================================================================================================================
int main(){
	char image_array[Y_SIZE][X_SIZE];
	int colm, row;
	char choice;
	
	int pass = 0;
	char filename[100];
	
	FILE* imagefileptr;
	
	while(pass == 0){
		printf("**ERINSTAGRAM**\n");
		printf("1: Load image\n");
		printf("2: Display image\n");
		printf("3: Edit image\n");
		printf("0: Exit Program\n");
		printf("\nChoose from one of the options above: ");
		scanf(" %c", &choice);
		
		if (choice == '1'){
			//load new image
			printf("What is the name of the image file? ");
			scanf("%s", filename);
			imagefileptr = fopen(filename, "r");
			
			if (imagefileptr != NULL){
				load(image_array, imagefileptr, &colm, &row);
				
			}else{
				printf("Could not find an image with that filename.\n");
				
			}
		}else if (choice == '2'){
			//display current image
			display(image_array, imagefileptr, &colm);
			
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
				display(image_array, imagefileptr, &colm);
				crop(row, colm, image_array);
				
				
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
	}

	fclose(imagefileptr);	
return 0;
}
//=====================================================================================================================
void load(char image_array[][X_SIZE], FILE* imagefileptr, int *colm, int *row){
	
	for(int j = 0; j <= X_SIZE; j++){
		for(int i = 0; i >= 0; i++){
			fscanf(imagefileptr, "%c", &image_array[j][i]);
			if(image_array[j][0] == '\n' || image_array[j][0] == '\0'){
				*colm = j;
				goto end;
				
			}else if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
				*row = i;
				break;
			}
		}
	}
	end:
	printf("\nImage successfully loaded!\n\n");
	return;
}
void display(char image_array[][X_SIZE], FILE* imagefileptr, int *colm){
	
	for(int j = 0; j < *colm; j++){
		printf("\n");
		for(int i = 0; i >= 0; i++){
			printf("%c", image_array[j][i]);
			if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
				break;
			}
		}
	}
	printf("\n\n");
return;
}
void crop(int rowSize, int colSize, char image_array[][X_SIZE]){
	
	char newArray[Y_SIZE][X_SIZE];
	int newleftcol, newrightcol, newtoprow, newbottomrow;
	printf("The image you want to crop is %d x %d.\n", colSize, rowSize);
	//printf("The row and column values start in the upper lefthand corner.\n");
	printf("\nWhich column do you want to be the new left side? ");
	scanf("%d", &newleftcol);
	printf("\nWhich column do you want to be the right left side? ");
	scanf("%d", &newrightcol);
	printf("\nWhich row do you want to be the new top? ");
	scanf("%d", &newtoprow);
	printf("\nWhich row do you want to be the new bottom? ");
	scanf("%d", &newbottomrow);
	
	
	
	
}

