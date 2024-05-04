// Authors: Reina Antaredjo
// Assignment: Final Project 
// Date: 5/3/24
 #define Current "starting_image.txt"
 #define New "new_image.txt"
 #define totalh 150
 #define totalw 150

 void menu();
 void cropImage();
 void brightenImage();
 void dimImage();
 void saveImage();
 void loadImage();
 
 

#include <stdio.h>
int main() {
 printf("Welcome to Erinstagram! \n");
 loadImage();


	return 0;
}

void menu(){



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

