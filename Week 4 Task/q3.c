#include<stdio.h>

    /* An online shopping store is providing discounts on items due to a seasonal sale. If the cost of
    items is less than 1500, a discount of up to 7% will be applied. If the cost of shopping is
    between 1500 and 3000, a 12% discount will be applied. For shopping between 3000 and 5000,
    a 22% discount will be applied. For amounts over 5000, a 30% discount will be applied.
    Print the original amount, the amount saved due to the discount, and the amount after
    applying the discount. */

    int main() {
        float price, discount, discount_rate, total;

        printf("Enter the cost of items: ");
        scanf("%f", &price);

        if (price < 1500) {
            discount_rate = 0.07;
        }
        else if (price >= 1500 && price < 3000) {
            discount_rate = 0.12;
        }
        else if (price >= 3000 && price <= 5000) {
            discount_rate = 0.22;
        }
        else if (price > 5000) {
            discount_rate = 0.30;
        }

        discount = price * discount_rate;
        total = price - discount;

        printf("Original Amount: %.2f\n", price);
        printf("Discount: %.2f\n", discount);
        printf("Final Amount: %.2f\n", total);

        return 0;
    }