/*
    Main file of file cipher project
*/

#include "file_cipher.h"

int main(){

    char *fileName = malloc(MAX_FILE_NAME * sizeof(char));
    if (fileName == NULL){
        printf("Memory allocation failed. \n");
        return 1;
    }

    int choice;
    int c;
    do{
        printf("\n File Cipher \n");
        printf("1. Encrypt. \n");
        printf("2. Decrypt. \n");
        printf("3. File Management.\n");
        printf("4. Exit program.\n");
        printf("Choice (1-4):");
        
        if ((scanf("%d", &choice)) != 1 || choice < 1 || choice > 4){
            printf("Invalid Input. Choice between 1 and 4.\n");
            while ((c = getchar()) == '\n' && c == EOF);
            continue;
        }
        while ((c = getchar()) == '\n' && c == EOF);   

        switch (choice)
        {
        case 1:
            printf("Enter file name to encrypt: ");
            if (fgets(fileName, sizeof(fileName), stdin) == NULL){
                perror("fgets");
                free(fileName);
                return 1;
            }

            fileName[strcspn(fileName, "\n")] = '\0';
            strcat(fileName, ".txt");

            FILE *inputFile = fopen(fileName, "r");
            if (inputFile == NULL){
                perror(fileName);
                free(fileName);
            }

            // call encrypt function here 

            //fclose(inputFile);

            break;
        
        case 2:
            break;
        
        case 3:
            break;

        case 4:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid Input.\n");
            break;
        }
        
    } while (choice != 4);

    free(fileName);
    return 0;
}