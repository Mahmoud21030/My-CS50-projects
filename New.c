#include <stdio.h>

/**
 * It takes the card data and gets the card holder name.
 *
 *  cardData a pointer to a structure of type ST_cardData_t.
 */
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	char temp[25];
	printf("**Please Enter The CardHolder Name ");
	gets(temp);
/* Checking the length of the string and if it is less than 20 or greater than 24 it will print an
error. */
	if(strlen(temp)<20 && strlen(temp) > 24)
		printf("error %s ", temp);

}
//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