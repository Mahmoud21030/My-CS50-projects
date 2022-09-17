#include <stdio.h>

/**
 * It takes the card data and gets the card holder name.
 *
 *  cardData a pointer to a structure of type ST_cardData_t.
 */
/**
 * It returns 1 if all the characters in the string are alphabetic, and 0 otherwise
 *
 * @param string The string to be checked.
 *
 * @return the number of characters in the string that are alphabetic.
 */
int s_isalpha(char* string)
{
	int n = strlen(string);
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (isalpha(string[i]) != 0)
		counter++;
	}
	return counter == n;
}

//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