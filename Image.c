//Vytis Etchegoyhen & Jaeiz Ocampo

#include <stdio.h>

#define Y_SIZE 100
#define X_SIZE 100

//#define FILE_NAME "test_image.txt"

//index
void load(char image_array[][X_SIZE], FILE* imagefileptr, int *colm, int *row);
void display(char chararray[][X_SIZE], char image_array[][X_SIZE], FILE* imagefileptr, int *colm);
void dim(int int_array[][X_SIZE], char temparray[][X_SIZE], char chararray[][X_SIZE], char image_array[][X_SIZE], FILE* imagefileptr, int *colm, char *filename);
void brighten(int int_array[][X_SIZE], char temparray[][X_SIZE], char chararray[][X_SIZE], char image_array[][X_SIZE], FILE* imagefileptr, int *colm, char *filename);
void crop(char chararray[][X_SIZE], char image_array[][X_SIZE], FILE* imagefileptr, int *colm, char *filename, int rowSize, int colSize);
//=====================================================================================================================
int main(){
	char image_array[Y_SIZE][X_SIZE];
	char chararray[Y_SIZE][X_SIZE];
	char temparray[Y_SIZE][X_SIZE];
	int int_array[Y_SIZE][X_SIZE];
	int colm;
	int row;
	int choice;
	
	int pass = 0;
	char filename[100];
	
	FILE* imagefileptr;
	
	for(int loop = 1; loop > 0; loop++){
		printf("**ERINSTAGRAM**\n");
		printf("1: Load image\n");
		printf("2: Display image\n");
		printf("3: Edit image\n");
		printf("0: Exit Program\n");
		printf("\nChoose from one of the options above: ");
		scanf(" %d", &choice);
		
		if (choice == 1){
			//load new image
			printf("What is the name of the image file? ");
			scanf("%s", filename);
			imagefileptr = fopen(filename, "r");
			
			if (imagefileptr != NULL){
				load(image_array, imagefileptr, &colm, &row);
				fclose(imagefileptr);
				pass = 1;
			}else{
				printf("Could not find an image with that filename.\n");
				
			}
		}else if (choice == 2 && pass == 0){
			printf("Sorry, no image to display\n\n");
		}else if (choice == 2 && pass == 1){
			//display current image
			printf("\n");
			display(chararray, image_array, imagefileptr, &colm);
			printf("\n");
		}else if (choice == 2 && pass == 0){
			printf("Sorry, no image to display\n\n");
				
		}else if (choice == 3 && pass == 1){
			//edit current image
			printf("\n\n**EDITING**\n");
			printf("1: Crop image\n");
			printf("2: Dim image\n");
			printf("3: Brighten image\n");
			printf("0: Return to main menu\n");
			printf("\nChoose from one of the options above: ");
			scanf(" %d", &choice);
			
			if (choice == 1 && pass == 1){
				//crop
				display(chararray, image_array, imagefileptr, &colm);
				crop(chararray, image_array, imagefileptr, &colm, filename, row, colm);
			}else if (choice == 2 && pass == 1){
				//dim
				dim(int_array, temparray, chararray, image_array, imagefileptr, &colm, filename);
				
			}else if (choice == 3 && pass == 1){
				//brighten
				brighten(int_array, temparray, chararray, image_array, imagefileptr, &colm, filename);
				
			}else if (choice == 0 && pass == 1){
				//main menu
				
			}else{
				printf("Invalid option, please try again.");
			}
		}else if (choice == 3 && pass == 0){
			printf("Sorry, no image to edit\n\n");
			
		}else if (choice == 0){
			printf("\nGoodbye!\n\n");
			return 0;
			
		}else{
			printf("Invalid option, please try again.\n");
			display(chararray, image_array, imagefileptr, &colm);
				crop(chararray, image_array, imagefileptr, &colm, filename, row, colm);
		}
	}
	
return 0;
}
//=====================================================================================================================
void load(char image_array[][X_SIZE], FILE* imagefileptr, int *colm, int *row){
	
	for(int j = 0; j <= X_SIZE; j++){
		for(int i = 0; i >= 0; i++){
			fscanf(imagefileptr, "%c", &image_array[j][i]);
			if(image_array[j][0] == '\n' || image_array[j][0] == '\0'){
				*colm = j;
				printf("\nImage successfully loaded!\n\n");
				return;
				
			}else if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
				*row = i;
				break;
			}
		}
	}
	return;
}
void display(char chararray[][X_SIZE], char image_array[][X_SIZE], FILE* imagefileptr, int *colm){
	//convert image array to char array
	for(int j = 0; j < *colm; j++){
		for(int i = 0; i >= 0; i++){
			if (image_array[j][i] == '0'){
				chararray[j][i] = ' ';
			}else if (image_array[j][i] == '1'){
				chararray[j][i] = '.';
			}else if (image_array[j][i] == '2'){
				chararray[j][i] = 'o';
			}else if (image_array[j][i] == '3'){
				chararray[j][i] = 'O';
			}else if (image_array[j][i] == '4'){
				chararray[j][i] = '0';
			}
			if (image_array[j][i] == 5){//null does not work :/
				chararray[j][i] = '\0';
				break;
			}if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
				chararray[j][i] = image_array[j][i];
				break;
			}
		}
	}
	//print character array
	for(int j = 0; j < *colm; j++){
		if (j != *colm && j != 0){
			printf("\n");
		}
		for(int i = 0; i >= 0; i++){
			printf("%c", chararray[j][i]);
			if(chararray[j][i] == '\n' || chararray[j][i] == '\0'){
				break;
			}
		}
	}
	
	printf("\n");
return;
}
void dim(int int_array[][X_SIZE], char temparray[][X_SIZE], char chararray[][X_SIZE], char image_array[][X_SIZE], FILE* imagefileptr, int *colm, char *filename){
	char choose;
	//transer image_array to temparray
	for(int j = 0; j < *colm; j++){
		for(int i = 0; i >= 0; i++){
			temparray[j][i] = image_array[j][i];
			if(temparray[j][i] == '\n' || temparray[j][i] == '\0'){
				break;
			}
		}
	}
	//dim image_array	
	for(int j = 0; j < *colm; j++){
		for(int i = 0; i >= 0; i++){
			if (temparray[j][i] == '0'){
				image_array[j][i] = '0';
			}else if (temparray[j][i] == '1'){
				image_array[j][i] = '0';
			}else if (temparray[j][i] == '2'){
				image_array[j][i] = '1';
			}else if (temparray[j][i] == '3'){
				image_array[j][i] = '2';
			}else if (temparray[j][i] == '4'){
				image_array[j][i] = '3';
			}
			
			if(temparray[j][i] == '\n' || temparray[j][i] == '\0'){
				image_array[j][i] = temparray[j][i];
				break;
			}
		}
	}
	
	display(chararray, image_array, imagefileptr, colm);
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c", &choose);
	if(choose == 'y'){




		//converting char array into integer array
		for(int j = 0; j < *colm; j++){
			for(int i = 0; i >= 0; i++){
				if (image_array[j][i] == '0'){
					int_array[j][i] = 0;
				}else if (image_array[j][i] == '1'){
					int_array[j][i] = 1;
				}else if (image_array[j][i] == '2'){
					int_array[j][i] = 2;
				}else if (image_array[j][i] == '3'){
					int_array[j][i] = 3;
				}else if (image_array[j][i] == '4'){
					int_array[j][i] = 4;
				}
				if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
					int_array[j][i] = 5;//null does not work :/
					break;
				}
			}
		}

		//saving that integer array into a file
		FILE* save;
		
		printf("What do you want to name the image file? (include the extension) ");
		scanf("%s", filename);
		save = fopen(filename, "w");

		for(int j = 0; j < *colm; j++){
			for(int i = 0; i >= 0; i++){
				fprintf(save, "%d", int_array[j][i]);
				if(int_array[j][i] == 5){//null does not work :/
					break;
				}
			}
			fprintf(save, "\n");
		}
		printf("\nImage successfully saved!\n\n");
		fclose(save);
		
		for(int j = 0; j < *colm; j++){
			for(int i = 0; i >= 0; i++){
				image_array[j][i] = temparray[j][i];
				if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
					break;
				}
			}
		}
		return;
		
	}else{
		for(int j = 0; j < *colm; j++){
			for(int i = 0; i >= 0; i++){
				image_array[j][i] = temparray[j][i];
				if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
					break;
				}
			}
		}
	}
	
return;
}
void brighten(int int_array[][X_SIZE], char temparray[][X_SIZE], char chararray[][X_SIZE], char image_array[][X_SIZE], FILE* imagefileptr, int *colm, char *filename){
	char choose;
	//transer image_array to temparray
	for(int j = 0; j < *colm; j++){
		for(int i = 0; i >= 0; i++){
			temparray[j][i] = image_array[j][i];
			if(temparray[j][i] == '\n' || temparray[j][i] == '\0'){
				break;
			}
		}
	}
	//dim image_array	
	for(int j = 0; j < *colm; j++){
		for(int i = 0; i >= 0; i++){
			if (temparray[j][i] == '0'){
				image_array[j][i] = '1';
			}else if (temparray[j][i] == '1'){
				image_array[j][i] = '2';
			}else if (temparray[j][i] == '2'){
				image_array[j][i] = '3';
			}else if (temparray[j][i] == '3'){
				image_array[j][i] = '4';
			}else if (temparray[j][i] == '4'){
				image_array[j][i] = '4';
			}
			
			if(temparray[j][i] == '\n' || temparray[j][i] == '\0'){
				image_array[j][i] = temparray[j][i];
				break;
			}
		}
	}
	
	display(chararray, image_array, imagefileptr, colm);
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c", &choose);
	if(choose == 'y'){




		//converting char array into integer array
		for(int j = 0; j < *colm; j++){
			for(int i = 0; i >= 0; i++){
				if (image_array[j][i] == '0'){
					int_array[j][i] = 0;
				}else if (image_array[j][i] == '1'){
					int_array[j][i] = 1;
				}else if (image_array[j][i] == '2'){
					int_array[j][i] = 2;
				}else if (image_array[j][i] == '3'){
					int_array[j][i] = 3;
				}else if (image_array[j][i] == '4'){
					int_array[j][i] = 4;
				}
				if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
					int_array[j][i] = 5;//null does not work :/
					break;
				}
			}
		}

		//saving that integer array into a file
		FILE* save;
		
		printf("What do you want to name the image file? (include the extension) ");
		scanf("%s", filename);
		save = fopen(filename, "w");

		for(int j = 0; j < *colm; j++){
			for(int i = 0; i >= 0; i++){
				fprintf(save, "%d", int_array[j][i]);
				if(int_array[j][i] == 5){//null does not work :/
					break;
				}
			}
			fprintf(save, "\n");
		}
		printf("\nImage successfully saved!\n\n");
		fclose(save);
		
		for(int j = 0; j < *colm; j++){
			for(int i = 0; i >= 0; i++){
				image_array[j][i] = temparray[j][i];
				if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
					break;
				}
			}
		}
		return;
		
	}else{
		for(int j = 0; j < *colm; j++){
			for(int i = 0; i >= 0; i++){
				image_array[j][i] = temparray[j][i];
				if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
					break;
				}
			}
		}
	}
	
return;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void crop(char chararray[][X_SIZE], char image_array[][X_SIZE], FILE* imagefileptr, int *colm, char *filename, int rowSize, int colSize){
	
	
	char choose;
	int newleftcol, newrightcol, newtoprow, newbottomrow;
	int temp1, temp2;
	
	
	printf("The image you want to crop is %d x %d.\n", colSize, rowSize);
	printf("The row and column values start in the upper lefthand corner.\n");
	printf("\nWhich column do you want to be the new left side? ");
	scanf("%d", &newleftcol);
	printf("\nWhich column do you want to be the right left side? ");
	scanf("%d", &newrightcol);
	printf("\nWhich row do you want to be the new top? ");
	scanf("%d", &newtoprow);
	printf("\nWhich row do you want to be the new bottom? ");
	scanf("%d", &newbottomrow);
	
	int x = newrightcol - newleftcol + 1;
	int y = newbottomrow - newtoprow + 1;
	char newArray[y][x];
	
	for(int a = 0; a < y; a++){
		for(int b = 0; b < x; b++){
			newArray[a][b] = image_array[a+(newtoprow - 1)][b + (newleftcol -1)];
		}
		
	}
	
	//prints the new cropped array (works)
	/*for(int a = 0; a<y; a++){
		for(int b = 0; b<x; b++){
			printf(" %c", newArray[a][b]);
		}
		printf("\n");
	}*/
	
	
	//display(chararray, newArray, imagefileptr, &y);
	/*printf("Would you like to save the file? (y/n) ");
	scanf(" %c", &choose);
	if(choose == 'y'){
	
		FILE* save;
		
		printf("What do you want to name the image file? (include the extension) ");
		scanf("%s", filename);
		save = fopen(filename, "w");
		char newline = '\n';
		for(int j = 0; j < *colm; j++){
			for(int i = 0; i >= 0; i++){
				fprintf(save, "%c", chararray[j][i]);
				if(chararray[j][i] == '\n' || chararray[j][i] == '\0'){
					break;
				}
			}
		}
		printf("\nImage successfully saved!\n\n");
		fclose(save);
		
		for(int j = 0; j < *colm; j++){
			for(int i = 0; i >= 0; i++){
				image_array[j][i] = temparray[j][i];
				if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
					break;
				}
			}
		}
		return;
		
	}else{
		for(int j = 0; j < *colm; j++){
			for(int i = 0; i >= 0; i++){
				image_array[j][i] = temparray[j][i];
				if(image_array[j][i] == '\n' || image_array[j][i] == '\0'){
					break;
				}
			}
		}
	}
	
return;*/
	
}
