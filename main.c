#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "node.h"
#include "buildTree.h"
#include "traversals.h"

int main(int argc, char* argv[])
{
  FILE *fp;
  FILE *tempFP;
  
  char *outFileBaseName;
  char inputLine[300];
  char *fileName;

  tempFP = fopen("tempFile", "w");
  
  switch (argc) {
      case 1:
        fp = stdin;
        outFileBaseName = "out";

      //ask user for keyboard input
        if (isatty(0)) {
            printf("Please enter one string at a time (lowercase) You may hit ctrl+D at any time to exit: \n");
        }
        while (scanf(" %s[^ \t\n]%*c", inputLine) == 1 && argc == 1){
          if (isatty(0)){
            int i;
            for(i = 0; inputLine[i] != '\0'; ++i){
              if(!islower(inputLine[i])){
                printf("\nInvalid input, only lowercase letters allowed\n");
                exit(EXIT_FAILURE);
              }
            }
            printf("Please enter another string: \n");
          }
          fprintf(tempFP, "%s\n", inputLine);
        }
        if (feof(fp)){
        printf("reading in complete\n");
        fclose(fp);
        fclose(tempFP);
        }
      break;

      case 2:
        fileName = argv[1];
        fp = fopen(fileName, "r");
        outFileBaseName = malloc(sizeof(argv[1]));
        outFileBaseName = argv[1];

        if (fp == NULL){
          printf("Error: unable to open file");
          exit(EXIT_FAILURE);
        }

        while(fscanf(fp, " %s[^ \t\n]%*c", inputLine) == 1 && argc > 1){
          int i;
          // checks for non-lowercase letters
          for(i = 0; inputLine[i] != '\0'; ++i){
            if(!islower(inputLine[i])){
              printf("\nInvalid input, only lowercase letters allowed\n");
              exit(EXIT_FAILURE);
            }
          }
          fprintf(tempFP, "%s\n", inputLine);
        }

        if (feof(fp)){
          printf("\nFile read complete.\n\n");
          fclose(fp);
          fclose(tempFP);
        }
      break;
      default:
        printf("Error: Incorrect number of arguments\n");
        printf("usage: ./P0 > filename, ./P0 filename, ./P0 for user input\n");
        exit(EXIT_FAILURE);
      break;
  } 
  
  tempFP = fopen("tempFile", "r");

  if (tempFP == NULL){
    printf("Error opening tempfile. \n");
    exit(EXIT_FAILURE);
  }
  buildTree(tempFP);
	fclose(tempFP);
  traverseInOrder(root, outFileBaseName);
  traversePreOrder(root, outFileBaseName);
  traverseLevelOrder(root, outFileBaseName);
  printf("Completed. output files %s.levelorder %s.preorder and %s.inorder\n", outFileBaseName, outFileBaseName, outFileBaseName);
  return 0;
}
