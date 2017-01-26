/*
 *	cards_refactored.c
 *	Takes the first two characters of user input as a card name
 *	Computes blackjack card count
*/

// Inefficient implementation: 
// playing with a variety of ways to pass around vars

#include <stdio.h>
#include <stdlib.h>

int end = 0;

// Get a card name from the user as char input
int get_card_input(char *prompt) {
	char card_name[3];
	int card_val = 0;

	puts(prompt);
	scanf("%2s", card_name);

	// Switch over input card names and match to int value
	switch(card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			card_val = 10;
			break;
		case 'A':
			card_val = 11;
			break;
		case 'X':
			end = 1;
			break;
		default:
			card_val = atoi(card_name);
			if ((card_val < 1) || (card_val > 10)) {
				puts("Input is not a valid card value.");
			}
	}

	return card_val;
}


void compute_count(int val, int *count) {
	// Check for card value and match to count operation
	if ((val > 2) && (val < 7)) {
		*count = *count + 1;
	} else if (val == 10) {
		*count = *count - 1;
	}
} 

// Run the card counter and print the count
int main()
{
	int count = 0;
	int val = 0;

	while (end == 0) {
		// Get input
		val = get_card_input("Enter a card: "); 

		// Compute count
		compute_count(val, &count);

		// Print count
		printf("Current count: %i\n", count);

	}
	return 0;
}