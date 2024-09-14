#include <stdio.h>

int main(){
	/* Question 6:
	Write a C program using nested if statements to compare two numbers: if the first number is greater,
	check if it&#39;s over 100 to print &quot;First number is significantly larger&quot; or &quot;First number is larger&quot;; if less,
	check if it&#39;s negative to print &quot;First number is negative and smaller&quot; or &quot;First number is smaller&quot;; if equal,
	print &quot;Both numbers are equal.*/
	int num1, num2;
	printf("Enter two numbers: ");
	scanf("%d%d",&num1, &num2);
	if (num1 > num2) {
		if (num1 > 100) {
			printf("First number is larger.");
		}	
		
	}
	else if (num1 < num2) {
		if (num1 < 0) {
			printf("First number is negative.");
		}	
	}
	else if (num1 == num2) {
		printf("Both numbers are equal.");
	}
	return 0;
}