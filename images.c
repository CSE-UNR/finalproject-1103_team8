// Authors: Reina Antaredjo
// Assignment: Final Project 
// Date: 5/3/24
 #define Current "starting_image.txt"
 #define New "new_image.txt"
 #define totalh 150
 #define totalw 150

 void menu();
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
	printf(" \n");
	printf(" Choose from one of the options above: ");
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
	 			scanf(" %c", &choice)
	 			
	 			if (choice == 'y' || choice == 'Y'){
	 			   saveImage();
	 			} else {
	 			   menuDisplay();
	 			}
	 			break;
	 		}
	 	} while (1);		
	return;
}

void cropImage(){

	return ;
}

void brightenImage(){

	return; 
}

void dimImage() {

	return;
}

void saveImage() {

	return;
}

void loadImage(){ 
  FILE* enterImage;
  printf("Loading image \n");
  enterImage = fopen(Current, "r");
  char arr [totalh][totalw];
  int row, col;
  for(row = 0; row < totalh; row++){
   for(col = 0; col < totalw; col++){
   fgets(enterImage "%s" arr[row][col]);
   }
   for(row = 0; row < totalh; row++){
   for(col = 0; col < totalw; col++){
   printf("%s" arr[row][col]);
   }
  
  
  }
 
  
  
  
 

}

