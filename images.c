// Authors: Reina Antaredjo, Milana Shahnazarian
// Assignment: Final Project 
// Date: 5/7/24

#include <stdio.h>
#include <stdbool.h>
#define total 100
#define MAX_SIZE 100

void menuDisplay();
void displayImage(char arr[total][total]);
void editImage(char arr[total][total]);
void cropImage(char arr[total][total]);
void dimImage(char arr[total][total]);
void brightenImage(char arr[total][total]);
void saveImage();

 int main(){
	int option;
	char end;
	do{ 
	printf("**ERINSTAGRAM** \n");
	menuDisplay();
	
	scanf("%d", &option);
	
	switch(option) {
		case 1:
			FILE *imageFile;
			char nameofFile[100];
			char line[MAX_SIZE];
			
			int index;
	
			scanf("%c", &end);
			printf("what is the name of the image file?");
			fgets(nameofFile, MAX_SIZE, stdin);
	
			for (int i=0; nameofFile[i] != '\0'; i++) {
			index = i;
			}
			nameofFile[index] = nameofFile[index+1];
			imageFile = fopen(nameofFile, "r");
			
			if (imageFile == NULL) {
				printf("no files exist. \n");
				
			}
			printf("Image successfully loaded! \n");
			fclose(imageFile);
			
			break;
		case 2:
			displayImage(); 
			break;
		case 3:
			
			editMenu(); 
			break;
		case 0:
			printf("Goodbye!"); 
			break;
		}
	} while (option != 0);
}

void menuDisplay(){

	printf("1. load image \n");
	printf("2. display image \n");
	printf("3. edit image \n");
	printf("0. exit \n");
	printf(" ");
	printf("Choose from one of the options above: ");
}

void displayImage(char arr[total][total]){
	 int row, col;
	
	for(row = 0; row < total; row++){
   	for(col = 0; col < total; col++){
  	 printf("%s", &arr[row][col]);
   	}
	}
}

void editImage(char arr[total][total]){
	int option;
	
	do{ 
	 printf("**Editing** \n");
	 printf("1. crop image \n");
	 printf("2. dim image \n");
	 printf("3. brighten image \n");
	 printf("0. return to main menu \n");
	 printf("Choose from one of the options above: ");
	 
	 scanf("%d", &option);
	 
	 switch(option) {
	 	case '1':
	 		cropImage(arr);
	 		break;
	 	case '2':
	 		dimImage(arr);
	 		break;
	 	case '3':
	 		brightenImage(arr);
	 		break;
	 	case '0':
	 		if (option != 0){
	 			char choice;
	 			printf("would you like to save file? (y/n)");
	 			scanf(" %c", &choice);
	 			
	 			if (choice = 'y'){
	 			   saveImage();
	 			} else if(choice = 'Y'){
	 			 saveImage();
	 			}
	 			else {
	 			   menu();
	 			}
	 			break;
	 		}
	 	} 
	return;
	}while (option != 0);
}

void cropImage(char arr[total][total]){
int startRow,  startCol,  endRow, endCol;
int rows = endRow - startRow + 1;
    int cols = endCol - startCol + 1;
    if (startRow < 0 || startCol < 0 || endRow >= rows || endCol >= cols || startRow > endRow || startCol > endCol) {
        printf("Invalid crop coordinates.\n");
        return;
    }
   
    
    

    
    int croppedImage[total][total];

    
    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            croppedImage[i - startRow][j - startCol] =  arr[i][j];
        }
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = croppedImage[i][j];
        }
    }

}

void brightenImage(char arr[total][total]){
    int rows, cols;
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < 255) {
                arr[i][j]++;
            }
        }
    }
}

void dimImage(char arr[total][total]){
 int rows, cols;
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > 0) {
                arr[i][j]--;
            }
        }
	}
}

void saveImage() {
  FILE* enterImage;
  printf("Saving image \n");
  enterImage = fopen(Current, "w");
  char arr [total][total];
  int row, col;
  for(row = 0; row < total; row++){
   for(col = 0; col < total; col++){
   fgets(arr[row], total, enterImage);
   }
   for(row = 0; row < total; row++){
   for(col = 0; col < total; col++){
   printf("%d",arr[row][col]);
   }
   }
   }
   }

