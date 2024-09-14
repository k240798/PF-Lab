#include <stdio.h>

int main(){
		/*Question 4:
	Given a positive integer denoting n, do the following:
	a. If 1=n=20, print the English words corresponding to the numbers (e.g., "one"; for 1,
	"twenty"; for 20).
	b. If n&gt;20, print &quot;Number greater than 20. */
	int number;
	printf("Enter an integer: ");
	scanf("%d", &number);
	
	switch(number){
		case 0:
			printf("Zero");
			break;
		case 1:
			printf("One");
			break;
		case 2:
			printf("Two");
			break;
		case 3:
			printf("Three");
			break;
		case 4:
			printf("Four");
			break;
		case 5:
			printf("Five");
			break;
		case 6:
			printf("Six");
			break;
		case 7:
			printf("Seven");
			break;
		case 8:
			printf("Eight");
			break;
		case 9:
			printf("Nine");
			break;
		case 10:
			printf("Ten");
			break;
		case 11:
			printf("Eleven");
			break;
		case 12:
			printf("Twelve");
			break;
		case 13:
			printf("Thirteen");
			break;
		case 14:
			printf("Fourteen");
			break;
		case 15:
			printf("Fifteen");
			break;
		case 16:
			printf("Sixteen");
			break;
		case 17:
			printf("Seventeen");
			break;
		case 18:
			printf("Eighteen");
			break;
		case 19:
			printf("Nineteen");
			break;
		case 20:
			printf("Twenty");
			break;
		default:
			printf("Number greater than 20");
	}

	return 0;
}