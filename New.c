/**
 * It generates a random number, then checks if it's a valid credit card number, and if it is, it
 * returns it
 *
 * @param x the number of digits you want to generate
 *
 * @return A pointer to a string of characters.
 */
uint8_t* CardGenerator(int x)
{
	int n =15+x;
	time_t t;
	srand((unsigned)time(&t));



	int* array = calloc(4,n+1);

	array[n]=0;

	unsigned long long card = 0;

	for (int i = 0; i < n; i++)
	{
		int r = rand() % 9 +1;
		array[i] = r;
		card *= 10;
		card += r;


	}
	n ++;
	int sum = 0;
	for (int i = n - 1; i >= 0; i -= 2) // sum of number start from the last index and step 2
		sum += array[i];
	for (int i = n - 2; i >= 0; i -= 2)
		/* sum of 2 * number start from the digit next to the last
		index and step 2*/
	{
		if ((2 * array[i]) > 9)
		{
			sum += (2 * array[i]) % 10 + (2 * array[i]) / 10;
		}
		else
		{
			sum += 2 * array[i];
		}
	}

	/* Intializes random number generator */
	uint8_t* final = calloc(1, n + 2);
	sprintf(final, "%llu%i", card, (10 - (sum % 10)) % 10);
	free(array);
	return final;
}

/**
 * The function checks if the credit card number is valid or not.
 *
 * @param string a string of numbers
 *
 * @return The function isValidCard() returns the first digit of the sum of the digits of the card
 * number.
 */
int isValidCard(char* string)
{
	int n = strlen(string);

	uint8_t* array = calloc(4, n);
	for (int i = 0; i < n; i++) //convert from string to array of uint8_t
	{
		array[i] = string[i] - '0';
	}
	int sum = 0;
	for (int i = n - 1; i >= 0; i -= 2) // sum of number start from the last index and step 2
		sum += array[i];
	for (int i = n - 2; i >= 0; i -= 2)
		/* sum of 2 * number start from the digit next to the last
		index and step 2*/
	{
		if ((2 * array[i]) > 9)
		{
			sum += (2 * array[i]) % 10 + (2 * array[i]) / 10;
		}
		else
		{
			sum += 2 * array[i];
		}
	}
	free(array);
	return (sum % 10); /*if the frist digit of sum is 0 then output is 0 value otherwise non zero number*/
}

//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