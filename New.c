
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
int main(){

}
typedef struct ST_cardData_t
{
	char cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
	OK,
	WRONG_NAME,
	WRONG_EXP_DATE,
	WRONG_PAN
}EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	char temp[25];
	printf("**Please Enter The CardHolder Name: ");
	scanf("%s",cardData->cardHolderName);

	/* Checking if the length of the string is between 19 and 25 characters. If it is, it assigns the
	adress of temp to cardData->cardHolderName. */
	if (strlen(temp) > 19 && strlen(temp) < 25)
	{
		cardData->cardHolderName= temp;
		printf("error %s", temp);
		return OK;
	}
	else
	{
		return WRONG_NAME;
	}
}
/**
 * It checks if the string is a date in the format dd/mm/yyyy
 *
 * @param string The string to be checked.
 *
 * @return 1 if the format is correct, 0 if not
 */
int s_isdate(char* string)
{
	int n = strlen(string);
	int counter = 0;
	int month = atoi(string); //taking month to integer
	for (int i = 0; i < n; i++) //checking the format
	{
		if (isdigit(string[i]) != 0)
			counter++; //counter is the number of digits in format
	}
	if (counter == 4 && string[2] == '/' && month <13)
		return 1;

	return 0;
}

//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