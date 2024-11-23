#include <stdio.h>
#include <string.h>

struct Invoice {
    char partNumber[20];        
    char partDescription[50];   
    int quantity;               
    float pricePerItem;         
};

float calculateInvoiceAmount(struct Invoice invoice) {
    if (invoice.quantity <= 0) {
        invoice.quantity = 0;
    }
    if (invoice.pricePerItem <= 0) {
        invoice.pricePerItem = 0;
    }

    return invoice.quantity * invoice.pricePerItem;
}

int main() {
    struct Invoice invoice = {
        "A123",        
        "Hammer",      
        10,            
        15.50          
    };

    float totalAmount = calculateInvoiceAmount(invoice);

    printf("Invoice Details:\n");
    printf("Part Number: %s\n", invoice.partNumber);
    printf("Part Description: %s\n", invoice.partDescription);
    printf("Quantity: %d\n", invoice.quantity);
    printf("Price per Item: $%.2f\n", invoice.pricePerItem);
    printf("Total Invoice Amount: $%.2f\n", totalAmount);

    struct Invoice invalidInvoice = {
        "B456",        
        "Nails",       
        -5,            
        -2.50         
    };

    float invalidAmount = calculateInvoiceAmount(invalidInvoice);

    printf("\nInvalid Invoice Details:\n");
    printf("Part Number: %s\n", invalidInvoice.partNumber);
    printf("Part Description: %s\n", invalidInvoice.partDescription);
    printf("Quantity: %d\n", invalidInvoice.quantity);
    printf("Price per Item: $%.2f\n", invalidInvoice.pricePerItem);
    printf("Total Invoice Amount: $%.2f\n", invalidAmount);

    return 0;
}
