#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int bookID;
    char title[100];
    char author[100];
    int quantity;
    float price;
};

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add New Book\n");
    printf("2. View All Books\n");
    printf("3. Search Book by ID\n");
    printf("4. Search Book by Title\n");
    printf("5. Update Book Details\n");
    printf("6. Delete Book Record\n");
    printf("7. Calculate Total Inventory Value\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

int isFileEmpty(FILE *file) {
    fseek(file, 0, SEEK_END);
    return ftell(file) == 0;
}

void addBook() {
    FILE *file = fopen("books.txt", "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    struct Book book;
    printf("Enter Book ID: ");
    scanf("%d", &book.bookID);

    FILE *tempFile = fopen("books.txt", "r");
    if (tempFile) {
        struct Book tempBook;
        while (fread(&tempBook, sizeof(struct Book), 1, tempFile)) {
            if (tempBook.bookID == book.bookID) {
                printf("Error: Book with this ID already exists!\n");
                fclose(tempFile);
                fclose(file);
                return;
            }
        }
        fclose(tempFile);
    }

    printf("Enter Title: ");
    getchar();  
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = 0;  

    printf("Enter Author: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = 0; 

    printf("Enter Quantity: ");
    scanf("%d", &book.quantity);
    if (book.quantity < 0) {
        printf("Quantity cannot be negative. Setting it to 0.\n");
        book.quantity = 0;
    }

    printf("Enter Price: ");
    scanf("%f", &book.price);
    if (book.price < 0) {
        printf("Price cannot be negative. Setting it to 0.0.\n");
        book.price = 0.0;
    }

    fwrite(&book, sizeof(struct Book), 1, file);
    printf("Book added successfully!\n");

    fclose(file);
}

void viewBooks() {
    FILE *file = fopen("books.txt", "r");
    if (!file) {
        printf("Error opening file or file is empty!\n");
        return;
    }

    if (isFileEmpty(file)) {
        printf("No books available in the system.\n");
        fclose(file);
        return;
    }

    struct Book book;
    printf("\nID\tTitle\t\tAuthor\t\tQuantity\tPrice\n");
    while (fread(&book, sizeof(struct Book), 1, file)) {
        printf("%d\t%s\t%s\t%d\t\t%.2f\n", book.bookID, book.title, book.author, book.quantity, book.price);
    }

    fclose(file);
}

void searchBookByID() {
    int bookID;
    printf("Enter Book ID to search: ");
    scanf("%d", &bookID);

    FILE *file = fopen("books.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.bookID == bookID) {
            printf("\nBook Found!\n");
            printf("ID: %d\n", book.bookID);
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Quantity: %d\n", book.quantity);
            printf("Price: %.2f\n", book.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", bookID);
    }

    fclose(file);
}

void searchBookByTitle() {
    char title[100];
    printf("Enter Title to search: ");
    getchar();  
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;  

    FILE *file = fopen("books.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (strstr(book.title, title)) {
            printf("\nBook Found!\n");
            printf("ID: %d\n", book.bookID);
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Quantity: %d\n", book.quantity);
            printf("Price: %.2f\n", book.price);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found with title containing '%s'.\n", title);
    }

    fclose(file);
}

void updateBook() {
    int bookID;
    printf("Enter Book ID to update: ");
    scanf("%d", &bookID);

    FILE *file = fopen("books.txt", "r+");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.bookID == bookID) {
            printf("Book found!\n");
            printf("Current Quantity: %d\n", book.quantity);
            printf("Enter new Quantity: ");
            scanf("%d", &book.quantity);
            if (book.quantity < 0) {
                printf("Quantity cannot be negative. Setting it to 0.\n");
                book.quantity = 0;
            }

            printf("Current Price: %.2f\n", book.price);
            printf("Enter new Price: ");
            scanf("%f", &book.price);
            if (book.price < 0) {
                printf("Price cannot be negative. Setting it to 0.\n");
                book.price = 0.0;
            }

            fseek(file, -sizeof(struct Book), SEEK_CUR);
            fwrite(&book, sizeof(struct Book), 1, file);
            printf("Book details updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", bookID);
    }

    fclose(file);
}

void deleteBook() {
    int bookID;
    printf("Enter Book ID to delete: ");
    scanf("%d", &bookID);

    FILE *file = fopen("books.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile) {
        printf("Error opening file!\n");
        return;
    }

    struct Book book;
    int found = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.bookID != bookID) {
            fwrite(&book, sizeof(struct Book), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("books.txt");
        rename("temp.txt", "books.txt");
        printf("Book record deleted successfully!\n");
    } else {
        printf("Book with ID %d not found.\n", bookID);
    }
}

void calculateTotalInventoryValue() {
    FILE *file = fopen("books.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    struct Book book;
    float totalValue = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        totalValue += (book.quantity * book.price);
    }

    printf("Total Inventory Value: %.2f\n", totalValue);

    fclose(file);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBookByID();
                break;
            case 4:
                searchBookByTitle();
                break;
            case 5:
                updateBook();
                break;
            case 6:
                deleteBook();
                break;
            case 7:
                calculateTotalInventoryValue();
                break;
            case 8:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
