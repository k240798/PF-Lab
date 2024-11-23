#include <stdio.h>

struct phone {
    int areaCode;
    int exchange;
    int number;
};

void displayPhoneNumber(struct phone p) {
    printf("My number is (%d) %d-%d\n", p.areaCode, p.exchange, p.number);
}

int main() {
    struct phone myPhone = {212, 767, 8900}; 
    struct phone yourPhone;  

    printf("Enter area code: ");
    scanf("%d", &yourPhone.areaCode);

    printf("Enter exchange: ");
    scanf("%d", &yourPhone.exchange);

    printf("Enter number: ");
    scanf("%d", &yourPhone.number);

    displayPhoneNumber(myPhone);
    printf("Your number is (%d) %d-%d\n", yourPhone.areaCode, yourPhone.exchange, yourPhone.number);

    return 0;
}
