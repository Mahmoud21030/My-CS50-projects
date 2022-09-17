
#include <string.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
	//ST_cardData_t user1;
	//getCardHolderName(&user1);
	//getCardPAN(&user1);
	//getCardExpiryDate(&user1);
	//

	char string[] = "123456789";
	int n = strlen(string);
	uint8_t array[strlen(string)];
	for (int i = 0; i < n; i++)
	{
		array[i] = string[i] - '0';
			printf("%i",array[i]);
	}


}


//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