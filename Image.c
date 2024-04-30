//Vytis Etchegoyhen & Jaeiz Ocampo

#include <stdio.h>
#define FILE_NAME "image_file.txt"
//index

//=====================================================================================================================
int main(){
	char image[1000][1000];
	char choice;

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
	
return 0;
}
//=====================================================================================================================

