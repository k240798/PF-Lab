#include <stdio.h>

int main() {
		/*Write a C program that reads a student’s score and classifies it into a grade. The grading
	scheme is as follows:
	 90-100: A
	 80-89: B
	 70-79: C
	 60-69: D
	 Below 60: F */
	int score;
	printf("Enter score: ");
	scanf("%d", &score);
	
	if (score >= 90 && score <= 100) {
		printf("A");
	}
	else if (score >= 80 && score < 90) {
		printf("B");
	}
	else if (score >= 70 && score < 80) {
		printf("C");
	}
	else if (score >= 60 && score < 70) {
		printf("D");
	}
	else if (score < 60) {
		printf("F");
	}
	return 0;
}