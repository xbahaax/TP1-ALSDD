#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.h"

int main() {
    Book *bookList = NULL;
    Borrower *borrowerList = NULL;
    Loan *activeLoanList = NULL;
    Loan *pendingLoanList = NULL;
    Loan *returnedLoanList = NULL;

    // Load books and library data from files
    loadBooksFromFile("C:\\Users\\DELL\\Desktop\\Back\\CodeBlocks-TP\\Lekhchien_Islem_Machane_Iyad_G01_PW1\\books_data.txt", &bookList);
    loadLibraryData("C:\\Users\\DELL\\Desktop\\Back\\CodeBlocks-TP\\Lekhchien_Islem_Machane_Iyad_G01_PW1\\library_data.txt", &borrowerList, &activeLoanList, &returnedLoanList, bookList); // Corrected to use bookList
    pauseScreen();
    int choice;
    do {
        system(CLEAR_SCREEN);
        displayMenu();
        choice = getIntInput("");

        switch (choice) {
            case 1:
                addBook(&bookList);
                break;
            case 2:
                print_books(bookList);
                break;
            case 3:
                addBorrower(&borrowerList);
                break;
            case 4:
                print_borrowers(borrowerList);
                break;
            case 5:
                addLoan(&activeLoanList, &pendingLoanList, bookList, borrowerList);
                break;
            case 6:
                print_AllLoans(activeLoanList, pendingLoanList, returnedLoanList);
                break;
            case 7:
                returnBook(&activeLoanList, &pendingLoanList, &returnedLoanList, bookList);
                break;
            case 8:
                overdue(activeLoanList);
                pauseScreen();
                break;
            case 9:
                searchBooksByName(bookList);
                break;
            case 10:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                pauseScreen();
        }

    } while (choice != 10);

    // Free Memory
    freeBooks(bookList);
    freeBorrowers(borrowerList);
    freeLoans(activeLoanList);
    freeLoans(pendingLoanList);
    freeLoans(returnedLoanList);

    return 0;
}
