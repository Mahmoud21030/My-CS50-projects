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
	/* Checking if the length of the string is between 19 and 25 characters. If it is, it assigns the
	value of temp to cardData->cardHolderName. */
	if (strlen(temp) > 19 && strlen(temp) < 25)
		cardData->cardHolderName = temp;
		printf("error %s %i", temp);

//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