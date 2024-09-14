#include<stdio.h>

    /*Write a C program to input electricity unit charges and calculate the total electricity bill
    according to the given conditions:
    1. For the first 30 units: Rs. 0.60/unit
    2. For the next 80 units: Rs. 0.85/unit
    3. For the next 100 units: Rs. 1.30/unit
    4. For units above 210: Rs. 1.60/unit
    An additional surcharge of 15% is added to the bill.*/

    int main() {
        float units, bill, surcharge;

        printf("Enter the total number of units consumed this month: ");
        scanf("%f", &units);

        if (units <= 30) {
            bill = 0.60 * units;
        }
        else if (units >= 30 && units <= 110) {
            bill = (0.60 *30) + (0.85 * (units - 30));
        }
        else if (units >= 110 && units <= 210) {
            bill = (0.60 * 30) + (0.85 * 80) + (1.30 * (units - 110));
        }
        else {
            bill = (0.60 * 30) + (0.85 * 80) + (1.30 * 100) + (1.60 * (units - 210));
        }

        surcharge = bill * 0.15;
        bill = bill + surcharge;
        printf("Total electricity bill is Rs %.2f", bill);

        return 0;
    }