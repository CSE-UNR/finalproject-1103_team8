// Authors: Reina Antaredjo, Milana Shahnazarian
// Assignment: Final Project 
// Date: 5/3/24
 #define Current "starting_image.txt"
 #define New "new_image.txt"
 #define total 150


 void menu();
 void displayImage();
 void editImage();
 void cropImage();
 void brightenImage();
 void dimImage();
 void saveImage();
 void loadImage();
 
 

#include <stdio.h>
int main() {
	int option;
		
	do{
	printf("Welcome to Erinstagram! \n");
	menuDisplay();
	scanf("%d", &option);
	
	switch (option){
		case '1':
			loadImage();
			break;
		case '2':
			displayImage();
			break;
		case '3':
			editImage();
			break;
		case '0':
			printf("goodbye !!");
			break;
		}
	} while (option != 0);
	
	return 0;
}

void menu(){

	printf("1. load image \n");
	printf("2. display image \n");
	printf("3. edit image \n");
	printf("0. exit \n");
	printf(" ");
	printf(" Choose from one of the options above: ");
}

void displayImage();
	printf("\n");
	for (int i = 0; i < rows; i++) {
		printf("%s", images[i]);
	}
}

void editImage(){
	int option;
	
	do{ 
	 printf("**Editing** \n");
	 printf("1. crop image \n");
	 printf("2. dim image \n");
	 printf("3. brighten image \n");
	 printf("0. return to main menu \n");
	 printf("\n");
	 printf("Choose from one of the options above: ");
	 
	 scanf("%d", &option);
	 
	 switch(option) {
	 	case '1':
	 		cropImage();
	 		break;
	 	case '2':
	 		dimImage();
	 		break;
	 	case '3':
	 		brightenImage();
	 		break;
	 	case '0':
	 		if (option != 0){
	 			char choice;
	 			printf("would you like to save file? (y/n)");
	 			scanf(" %c", &choice);
	 			
	 			if (choice = 'y' || choice = 'Y'){
	 			   saveImage();
	 			} else {
	 			   menuDisplay();
	 			}
	 			break;
	 		}
	 	} while (1);		
	return;
	}
}

void cropImage(int startRow, int startCol, int endRow, int endCol) {
    if (startRow < 0 || startCol < 0 || endRow >= rows || endCol >= cols || startRow > endRow || startCol > endCol) {
        printf("Invalid crop coordinates.\n");
        return;
    }

    
    rows = endRow - startRow + 1;
    cols = endCol - startCol + 1;

    
    int croppedImage[MAX_SIZE][MAX_SIZE];

    
    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            croppedImage[i - startRow][j - startCol] = image[i][j];
        }
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[i][j] = croppedImage[i][j];
        }
    }

}

void brightenImage(){
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (image[i][j] < 255) {
                image[i][j]++;
            }
        }
    }
}

void dimImage() {
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (image[i][j] > 0) {
                image[i][j]--;
            }
        }
	}
}

void saveImage() {
	char filename[100];
	FILE *fp;
	
	printf("What would you like to name this file? (including the extenstions)");
	scanf("%s", filename);
	
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("error with file. \n");
	return;
	}
	
	fprintf(fp, "%s\n", image[i]);

	fclose(fp);
	
	printf("Image saved successfully. ");
}

void loadImage(){ 
  FILE* enterImage;
  printf("Loading image \n");
  enterImage = fopen(Current, "r");
  char arr [total][total];
  int row, col;
  for(row = 0; row < total; row++){
   for(col = 0; col < total; col++){
   fgets(&arr[row][col], total, enterImage);
   }
   for(row = 0; row < total; row++){
   for(col = 0; col < total; col++){
   printf("%d",arr[row][col]);
   }
  
  
  }
 
}
}

