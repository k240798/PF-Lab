#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    double length;
    double width;
};

double perimeter(struct Rectangle rect) {
    return 2 * (rect.length + rect.width);
}

double area(struct Rectangle rect) {
    return rect.length * rect.width;
}

void check(struct Rectangle rect) {
    if (rect.length <= 0.0 || rect.length >= 20.0 || rect.width <= 0.0 || rect.width >= 20.0) {
        printf("Error: Length and width must be greater than 0 and less than 20.\n");
        exit(1); 
    }
}

int main() {
    struct Rectangle rect;

    printf("Enter the length of the rectangle: ");
    scanf("%lf", &rect.length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &rect.width);

    check(rect);

    printf("Perimeter: %.2lf\n", perimeter(rect));
    printf("Area: %.2lf\n", area(rect));

    return 0;
}
