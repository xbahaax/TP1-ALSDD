#include "Library.h"


int main(){

    Book *bookList = NULL;
    Borrower *borrowerList = NULL;
    Loan *activeLoanList = NULL;
    Loan *pendingLoanList = NULL;
    Loan *returnedLoanList = NULL;
    Herosec();
    pauseScreen();
    displayMenu(&bookList,&activeLoanList,&pendingLoanList,&returnedLoanList,&borrowerList);

    freeBooks(bookList);
    freeBorrowers(borrowerList);
    freeLoans(activeLoanList);
    freeLoans(pendingLoanList);
    freeLoans(returnedLoanList);
    return 0;
}
