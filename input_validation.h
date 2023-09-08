#ifndef INPUT_VALIDATION_H
  #define INPUT_VALIDATION_H
	#include <stdbool.h>
	bool isValidFormat(const int numArgsRead, const int numArgsNeed);
	char getValidChar(const char* prompt);
	int getValidInt(int l, int c);
	double getValidDouble(const char* prompt);
	bool inbetween(int val, int lowerBound, int upperBound);
	int getValidIntInRange(int lowerBound, int upperBound);
#endif