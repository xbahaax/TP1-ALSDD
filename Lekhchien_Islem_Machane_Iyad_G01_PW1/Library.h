#ifndef LIBRARY_H
#define LIBRARY_H

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;



typedef struct Book {
    int id;
    char title[100];
    char author[100];
    int copies;
    struct Book *next;
    struct Book *prev;
} Book;

typedef struct Borrower {
    int id;
    char name[100];
    struct Borrower *next;
    struct Borrower *prev;
} Borrower;

typedef struct Loan {
    struct Borrower *borrower;
    struct Book *book;
    int priority;
    Date borrow_date;
    Date return_date;
    int overdue;
    struct Loan *next;
} Loan;

// Book functions
int getBookID(Book *b);
char* getBookTitle(Book *b);
char* getBookAuthor(Book *b);
int getBookCopies(Book *b);
Book* getBookNext(Book *b);
Book* getBookPrev(Book *b);
void setBookID(Book *b, int id);
void setBookTitle(Book *b, char title[]);

void setBookAuthor(Book *b, char author[]);

void setBookCopies(Book *b, int copies);

void setBookNext(Book *b, Book *next);

void setBookPrev(Book *b, Book *prev);


void setBook(Book *b, int id, char title[], char author[], int copies );




// Borrower functions
int getBorrowerID(Borrower *b);

char* getBorrowerName(Borrower *b);

Borrower* getBorrowerNext(Borrower *b);

Borrower* getBorrowerPrev(Borrower *b);

void setBorrowerID(Borrower *b, int id);

void setBorrowerName(Borrower *b, char name[]);

void setBorrowerNext(Borrower *b, Borrower *next);

void setBorrowerPrev(Borrower *b, Borrower *prev);


void setBorrower(Borrower *b, int id, char name[]);

Borrower* getLoanBorrower(Loan *l);

Book* getLoanBook(Loan *l);
Date getBorrowDate(Loan *l);

Date getReturnDate(Loan *l);

int getLoanPriority(Loan *l);

int getLoanOverdue(Loan *l);

Loan* getLoanNext(Loan *l);

void setLoanBorrower(Loan *l, Borrower *b);

void setLoanBook(Loan *l, Book *b);

void setBorrowDate(Loan *l, Date borrow_date);

void setReturnDate(Loan *l, Date return_date);

void setLoanPriority(Loan *l, int priority);

void setLoanOverdue(Loan *l, int overdue);

void setLoanNext(Loan *l, Loan *next);
void setLoan(Loan *l, Borrower *b, Book *bk, int priority,int overdue);
// Date functions
int getDateYear(Date d);
int getDateMonth(Date d);

int getDateDay(Date d);

void setDateYear(Date *d, int year);

void setDateMonth(Date *d, int month);

void setDateDay(Date *d, int day);

// Free functions
void freeBooks(Book *head);

void freeBorrowers(Borrower *head);

void freeLoans(Loan *head);
int BooksLenght(Book *head);

int BorrowersLenght(Borrower *head);
int LoansLenght(Loan *head);



Book* insertBook(Book *head, int id, char title[], char author[], int copies);



Borrower* insertBorrower(Borrower *head, int id, char name[]);

Loan* insertLoan(Loan *head, Borrower *b, Book *bk, int priority, Date borrow_date, Date return_date,int overdue);
int compare_date(Loan *l);
// Update overdue function to use the correct functions
void overdue(Loan *l);

// Function to check if a book exists
Book* findBookById(Book *bookList, int id);
// Function to check if a borrower exists
Borrower* findBorrowerById(Borrower *borrowerList, int id);

// Add these functions after the existing findBorrowerById function

// Function to check if a book is available for borrowing
int isBookAvailable(Book *book);

// Function to check if a loan exists
Loan* findActiveLoan(Loan *loanList, int bookId, int borrowerId);

// Function to validate a loan request
int validateLoanRequest(Book *book, Borrower *borrower, Loan *activeLoanList);
Date addDaysToDate(Date date, int days);
// Function to compare two dates
int compareDates(Date date1, Date date2);

void pauseScreen();

int getIntInput(const char *prompt);

void getStringInput(const char *prompt, char *buffer, int size);
void displayMenu(Book **books, Loan **activeloans, Loan **pendingloans, Loan **returnedloans, Borrower **borrowers) ;

void BookMenu(Book **b) ;
void LoansMenu(Loan **active, Loan **pending, Loan **returned, Borrower **b, Book *bk);
void FilesMenu(Book **bk,Loan **active,Loan **pending,Loan **returned,Borrower **b);

void statisticsMenu(Book **bk,Borrower **b,Loan **active,Loan **pending,Loan **returned);

void addBook(Book **bookList);
void addBorrower(Borrower **borrowerList) ;
void AddLoan(Borrower **borrowerList, Loan **activeLoanList,Loan **pendingLoanList, Book *bookList);

// Function to display all loans (active, pending, and returned)
void print_AllLoans(Loan *activeLoanList, Loan *pendingLoanList, Loan *returnedLoanList);

void print_ligne();

void print_header_books();
void print_book_ligne(Book *b);

void print_header_borrowers();

void print_borrower_ligne(Borrower *b);

void print_header_loan();

char* formatDate(Date d) ;

void print_loan_ligne(Loan *l) ;
void print_header_returned_loans();
void print_returned_loan_ligne(Loan *l);


void print_books(Book *b) ;
void print_borrowers(Borrower *b);
void print_Loans(Borrower *b, Book *bk, Loan *l);



void searchBooksByName(Book *bookList);
void loadBooksFromFile(const char *filename, Book **bookList);
void processBorrowerData(char *line, Borrower **borrowerList) ;
void processBorrowBook(char *line, Borrower **borrowerList, Loan **activeLoanList,
                        Loan **pendingLoanList, Book *bookList);
void processReturnBook(char *line, Loan **activeLoanList, Loan **pendingLoanList,
    Loan **returnedLoanList, Book *bookList) ;


void loadLibraryData(const char *filename, Borrower **borrowerList, Loan **activeLoanList,
    Loan **pendingLoanList, Loan **returnedLoanList, Book *bookList);
void processReturnBookConsole(Loan **activeLoanList, Loan **pendingLoanList,
    Loan **returnedLoanList, Book *bookList);

void Herosec();

#endif
