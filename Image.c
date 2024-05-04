//Vytis Etchegoyhen & Jaeiz Ocampo

#include <stdio.h>
#define Y_SIZE 100
#define X_SIZE 100
#define FILE_NAME "test_image.txt"
//index
void load(int row_size, int col_size, int image_array[][col_size], FILE* imagefileptr);
void display(int row_size, int col_size, int image_array[][col_size], FILE* imagefileptr);
//=====================================================================================================================
int main(){
	//char image[1000][1000];
	int image_array[Y_SIZE][X_SIZE];
	char choice;
	int row_size;
	int col_size;
	
	char filename[100];
	int pass = 0;
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
				load(row_size, col_size, image_array, imagefileptr);
				printf("Image successfully loaded!\n\n");
				
			}else{
				printf("Could not find an image with that filename.\n");
				
			}
		}else if (choice == '2'){
			//display current image
			display(row_size, col_size, image_array, imagefileptr);
			
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
	}

	fclose(imagefileptr);	
return 0;
}
//=====================================================================================================================
void load(int row_size, int col_size, int image_array[][col_size], FILE* imagefileptr){
	
	for(row_size = 0; row_size < X_SIZE; row_size++){
		for(col_size = 0; col_size < Y_SIZE; col_size++){
			fscanf(imagefileptr, "%d", &image_array[row_size][col_size]);
		}
	}
}
void display(int row_size, int col_size, int image_array[][col_size], FILE* imagefileptr){
	
	printf("\n\n");
	for(int i = row_size; i >= 0; i--){
		for(int j = col_size; j >= 0; j--){
			printf("%d", image_array[i][j]);
		}
	}
	printf("\n\n\n");
}
