// Authors: Reina Antaredjo, Milana Shahnazarian
// Assignment: Final Project 
// Date: 5/7/24

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MAX_ROWS 100
#define MAX_COLS 25
#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

void menuDisplay();
void displayImage(FILE *imageFile, char filename[]);
void editMenu(char image[MAX_ROWS][MAX_COLS], int *rows, int *cols);
void cropImage(char image[MAX_ROWS][MAX_COLS], int *rows, int *cols);
void dimImage(char image[MAX_ROWS][MAX_COLS], int rows, int cols);
void brightenImage(char image[MAX_ROWS][MAX_COLS], int rows, int cols);
void saveImage(char image[MAX_ROWS][MAX_COLS], int rows, int cols);

int main() {
    int option;
    char end;
    char image[MAX_ROWS][MAX_COLS];
    char filename[MAX_FILENAME_LENGTH];
    int rows = 0, cols = 0;
    FILE *imageFile;

    do {
        printf("\n**ERINSTAGRAM** \n");
        menuDisplay();

        scanf("%d", &option);
        getchar();

        switch(option) {
            case 1:
                FILE *imageFile;
			char nameofFile[100];
			char line[MAX_SIZE];
			
			int index;
	
			
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
            	if (imageFile == NULL){
            		printf("Error: No image loaded. \n");
            	} else {
                	displayImage(imageFile, nameofFile);
    		}
                break;
            case 3:
                editMenu(image, &rows, &cols);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 0);
    return 0;
}

void menuDisplay() {
    printf("1. Load a new image\n");
    printf("2. Display the current image\n");
    printf("3. Edit the current image\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void displayImage(FILE *imageFile, char filename[]) {
    char let;
    
    imageFile = fopen(filename, "r");
    while (fscanf(imageFile, "%c", &let) == 1) {
        printf("%c", let);
    }
    
    fclose(imageFile);
}

void editMenu(char image[MAX_ROWS][MAX_COLS], int *rows, int *cols) {
    int editOption;
    do {
        printf("\nEdit Menu:\n");
        printf("1. Crop image\n");
        printf("2. Dim image\n");
        printf("3. Brighten image\n");
        printf("0. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &editOption);

        switch(editOption) {
            case 1:
                cropImage(image, rows, cols);
                break;
            case 2:
                dimImage(image, *rows, *cols);
                break;
            case 3:
                brightenImage(image, *rows, *cols);
                break;
            case 0:
                printf("Returning to main menu.\n");
                menuDisplay();
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (editOption != 0);
}
    

void cropImage(char image[MAX_ROWS][MAX_COLS], int *rows, int *cols) {
    int startX, startY, endX, endY;
    char saveChoice;
    char filename[MAX_FILENAME_LENGTH];

   
    printf("Enter the starting row index for cropping: ");
    scanf("%d", &startX);
    printf("Enter the starting column index for cropping: ");
    scanf("%d", &startY);
    printf("Enter the ending row index for cropping: ");
    scanf("%d", &endX);
    printf("Enter the ending column index for cropping: ");
    scanf("%d", &endY);

   
    if (startX < 0 || startY < 0 || endX >= *rows || endY >= *cols || startX > endX || startY > endY) {
        printf("Invalid crop coordinates.\n");
        return;
    }

    
    *rows = endX - startX + 1;
    *cols = endY - startY + 1;

   
    char croppedImage[MAX_ROWS][MAX_COLS];
    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            croppedImage[i - startX][j - startY] = image[i][j];
        }
    }

    
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            image[i][j] = croppedImage[i][j];
        }
    }

    printf("Image cropped successfully.\n");
    
    printf("Do you want to save image? (y/n): ");
    scanf("%c ", &saveChoice);
    
    if(saveChoice == 'y'){
    	saveImage(image, *rows, *cols);
    	}
}

void dimImage(char image[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int dimAmount = 1;
    char saveChoice;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           
            if (image[i][j] >= '!' && image[i][j] <= '~') {
                image[i][j] -= dimAmount;
                
                if (image[i][j] < '!') {
                    image[i][j] = '!';
                }
            }
            
        }
    }

    printf("Image dimmed successfully.\n");
    
    printf("Do you want to save the dimmed image to a file? (y/n): ");
    scanf(" %c", &saveChoice);

    if (saveChoice == 'y' || saveChoice == 'Y') {
        saveImage(image, rows, cols);
    }
}

void brightenImage(char image[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int brightenAmount;
    char saveChoice;
    char filename[MAX_FILENAME_LENGTH];

   
    printf("Enter the amount to brighten the image (e.g., 1 for one step brightening): ");
    scanf("%d", &brightenAmount);

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            if (image[i][j] >= '!' && image[i][j] <= '~') {
                image[i][j] += brightenAmount;
                
                if (image[i][j] > '~') {
                    image[i][j] = '~';
                }
            }
        }
    }

    printf("Image brightened successfully.\n");

   
    printf("Do you want to save the brightened image to a file? (y/n): ");
    scanf(" %c", &saveChoice);

    if (saveChoice == 'y' || saveChoice == 'Y') {
        saveImage(image, rows, cols);
    }
}

void saveImage(char image[MAX_ROWS][MAX_COLS], int rows, int cols) {
    char filename[MAX_FILENAME_LENGTH];

   
    printf("Enter the filename to save the image: ");
    scanf("%s", filename);

    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%c", image[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Image saved to %s successfully.\n", filename);
}
