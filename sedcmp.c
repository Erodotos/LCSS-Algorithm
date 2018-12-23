/** @file sedcmp.c 
 *  @brief Find string distance simillarity. 
 * 
 * This program takes as input 2 files which contain
 * 2 different strings. After reading these strings,
 * it calculates using a recursive algorithm, the 
 * distance between them and finally prints to the user
 * the minimum edits required in order the 2 strings 
 * be the same.
 * 
 *  @author Erodotos Demetriou 
 *  @bug No known bugs. 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

//Function prototypes
int D(char *, char *, int, int);
int min (int , int, int);

/** @brief This is the main function of the program
 *         
 *  This is the first function which is triggerd when the 
 *  program lunches. First of all main() check if the given
 *  arguments to the command line are correct. Then 2 FILE
 *  pointers are created in order to read from files the 
 *  strings we want to compare. If files are not found then 
 *  the proper message is returned to the user. Finally this 
 *  function calls other functions which calculate the desired
 *  result. 
 * 
 *  @param argc The number of given arguments
 *  @param *argv[] An array which contains the arguments given
 *  @return int. 
 */

int main(int argc, char const *argv[]){

	// Check commandline arguments
   if (argc != 3) {
      printf("Error in given arguments!\n");
      return EXIT_FAILURE;
   }

	// The following arrays are created to store the names of the
   // files we want to imports as data.
   char file1[100] = {};
   char file2[100] = {};

   strcpy(file1,argv[1]);
   strcpy(file2,argv[2]);

	//Create file pointers
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	fp1 = fopen(file1, "r");
	fp2 = fopen(file2, "r");

	char buffer[100];

	//Read the first file
	fgets(buffer, 100, fp1);
	int length = strlen(buffer);

	//According to the size of the string we read we allocate the
	//proper memory.
	char *string1 = (char *)malloc(length*sizeof(char));
	strcpy(string1,buffer);

	//Read the second file
	fgets(buffer, 100, fp2);
	length = strlen(buffer);

	//According to the size of the string we read we allocate the
	//proper memory.
	char *string2 = (char *)malloc(length*sizeof(char));
	strcpy(string2,buffer);

	//Print the results
	printf("Minimun edits required to convert is %d\n", D(string1, string2, strlen(string1), strlen(string2)));

	//Free the 2 char pointers which contain the strings we compared
	free(string1);
	free(string2);

   return 0;
}

/** @brief This recursive function calculates the min edits
 *  required to make these strings the same.
 *         
 *  It takes as input the string pointers as well as string's
 *  lengths. The breaks the problem into 3 segments and creates
 *  a tree like structure with 3 branches each in order to check
 *  all the letters of the strings. More info about the functionality 
 *  of the algorithm can b found in the code above each instaction.
 * 
 *  @param argc The number of given arguments
 *  @param *argv[] An array which contains the arguments given
 *  @return int. 
 */

int D(char *str1 , char *str2 , int m ,int n){
 
   // Check if the first string in empty. So it will stop searching for 
   // differences
   if (m == 0) return n; 

   // Check if the first string in empty. So it will stop searching for 
   // differences
   if (n == 0) return m; 

   // If last letters are the same, the difference is whatever is
   // required to edit the rest of the strings.
   if (str1[m-1] == str2[n-1]) 
      return D(str1, str2, m-1, n-1); 

   // Recursive step is here.
   return 1 + min(D(str1, str2, m, n-1), D(str1, str2, m-1, n), D(str1, str2, m-1, n-1)); 
} 

/** @brief This function returns the smallest amon 3 numbers
 *       
 *  This method actually implements 2 times the MACRO 
 *  #define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
 * 
 *  @param x The first number
 *  @param y The second number
 *  @param z The third number
 *  @return int. 
 */
int min(int x, int y, int z) { 
   return MIN(MIN(x, y), z); 
} 
 
