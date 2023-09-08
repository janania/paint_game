

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool isValidFormat(const int numArgsNeeded, const int numArgsRead, bool isLastElement);

int getValidInt(const bool isLastElementOnLine);
char getValidChar(const bool isLastElementOnLine);
double getValidDouble(const bool isLastElementOnLine);

int getPosInt(const bool isLastElementOnLine);
int badGetPosint(const bool isLastElementOnLine);
double getValidDoubleInRange(const double lowerBound, const double upperBound, const bool isLastElementOnLine);

/**
 *
 * @param numArgsNeeded: the number of format placeholders that needed to have been read in the last scanf
 * @param numArgsRead: the actual number of placeholders that were read from scanf, ie its return value
 * @param isLastElementOnLine: true if this is the last value that should be on this line of input
 * @return: true if the input is correctly formatted and false otherwise
 */


 bool isValidFormat(const int num_args_needed, const int num_args_read,
	 bool should_be_last_value_on_line){
	 bool format_is_correct = num_args_read == num_args_needed;
	 if(should_be_last_value_on_line){
		char should_be_newline = '?';
		scanf("%c", &should_be_newline);
		format_is_correct = format_is_correct && should_be_newline == '\n';
	 }
	 return format_is_correct;
 }

/**
 * Get an integer from the user but close the program if one is not entered
 * @param isLastElementOnLine : true if this is the last value that should be on this line of input
 * @return a valid integer
 */
int getValidInt(const bool isLastElementOnLine) {
  const int numArgsNeeded = 1;
  int numArgsRead;
  int num;

  numArgsRead = scanf(" %d", &num);
  if (isValidFormat(numArgsNeeded, numArgsRead, isLastElementOnLine)) {
    return num;
  } else {
    printf("Format Error\n");
    exit(0);
  }
}

/**
 * Get a character  from the user but close the program if one is not entered
 * @param isLastElementOnLine : true if this is the last value that should be on this line of input
 * @return a valid character
 */
char getValidChar(const bool isLastElementOnLine) {
  const int numArgsNeeded = 1;
  int numArgsRead;
  char theCharacter;

  numArgsRead = scanf(" %c", &theCharacter);
  if (isValidFormat(numArgsNeeded, numArgsRead, isLastElementOnLine)) {
    return theCharacter;
  } else {
    printf("Format Error\n");
    exit(0);
  }
}

/**
 * Get a double from the user but close the program if one is not entered
 * @param isLastElementOnLine : true if this is the last value that should be on this line of input
 * @return a valid double
 */
double getValidDouble(const bool isLastElementOnLine) {
  const int numArgsNeeded = 1;
  int numArgsRead;
  double num;

  numArgsRead = scanf(" %lf", &num);
  if (isValidFormat(numArgsNeeded, numArgsRead, isLastElementOnLine)) {
    return num;
  } else {
    printf("Format Error\n");
    exit(0);
  }
}

/**
 * Get an positive integer from the user but close the program if one is not entered
 * @param isLastElementOnLine : true if this is the last value that should be on this line of input
 * @return a valid positive integer
 */
int getPosInt(const bool isLastElementOnLine) {
  // first get a valid integer
  int num = getValidInt(isLastElementOnLine);
  // then check it meets the desired conditions
  if (num > 0) {
    return num;
  } else {
    printf("Number wasn't positive\n");
    exit(0);
  }
}

/**
 * An attempt to get a positive integer from the user but is incorrect
 * @param isLastElementOnLine : true if this is the last value that should be on this line of input
 * @return a valid positive integer
 */
int badGetPosint(const bool isLastElementOnLine) {
  int num = 20; //cat
  int nar;
  nar = scanf("%d", &num);
  if (num > 0) {  // bad. checking the value of num before we know we got it
    return num;
  } else if (!isValidFormat(1, nar, isLastElementOnLine)) {
    printf("Formatting error\n");
    exit(0);
  } else {
    printf("Number wasn't positive\n");
    exit(0);
  }
}

/**
 * Get a double between lower bound and upper bound inclusive
 * @param lowerBound
 * @param upperBound
 * @param isLastElementOnLine : true if this is the last value that should be on this line of input
 * @return: a double between lower bound and upper bound
 */
double getValidDoubleInRange(const double lowerBound, const double upperBound, const bool isLastElementOnLine) {
  // first get a valid double
  double num = getValidDouble(isLastElementOnLine);

  // then check that it meets the constraints
  if (num >= lowerBound && num <= upperBound) {
    return num;
  } else {
    printf("Number not in range.\n");
    exit(0);
  }

  int getPosInt(){
	int num;
    do{
    num = getValidInt("Enter a positive number: ");
     }while(!(num > 0));

    return num;
    }




int getNegInt(){
  int num;
  do{
    num = getValidInt("Enter a negative number: ");
  }while(!(num < 0));

  return num;
}

int getIntAtLeast(int min_val, const char* prompt){
  int num;
  do{
    num = getValidInt(prompt);
  }while(!(num >= min_val));

  return num;
}

double getDoubleAtLeast(double min_val, const char* prompt){
  double num;
  do{
    num = getValidDouble(prompt);
  }while(!(num >= min_val));

  return num;
}


}

int stop(){
	exit(0);
}

void wrapper(){
	stop();
}

