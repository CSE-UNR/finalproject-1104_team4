//test file

#include <stdio.h>
#define FILE_NAME "test.txt"
#define MAXSIZE 500
//index

//====================================================================
void load(FILE* fptr, int maxrows, int col, int array[][col], int* rows, int* cols);


int main(){
	FILE* imageptr;
	imageptr = fopen(FILE_NAME, "r");
	int image[MAXSIZE][MAXSIZE], rowResult, colResult, choice;
	
	load(imageptr, MAXSIZE, MAXSIZE, image, &rowResult, &colResult);
	
	
	printf("1. size, 2. array ");
	scanf("%d", &choice);
	if(choice == 1){
		printf("row: %d col: %d \n", rowResult, colResult);
	}else if(choice ==2){
		for(int i = 0; i < rowResult; i++){
			for(int j = 0; j < colResult; j++){
				printf("%d", image[i][j]);
			}
		printf("\n");
	}
	
	}
	
	
	fclose(imageptr);
	return 0;
	
}
void load(FILE* fptr, int maxrows, int col, int array[][col], int* rows, int* cols){
	
	char temp;
	int index = 0;
	int index2 = 0;
	
	while(fscanf(fptr, "%d", &array[index][index2]) == 1){
		index2++;
		if(fscanf(fptr, "%c", &temp)==1){
			index++;
			index2 = 0;
		}
	}
	
	*rows = index;
	*cols = index2;
}

