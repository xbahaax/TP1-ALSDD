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

// Structure to simplify working with dates
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Structure to store Books ( doubly linked list )
typedef struct Book {
    int id;
    char title[100];
    char author[100];
    int copies;
    struct Book *next;
    struct Book *prev;
} Book;

// Strcuture to store Borrowers
typedef struct Borrower {
    int id;
    char name[100];
    struct Borrower *next;
    struct Borrower *prev;
} Borrower;

// Strcuture to Store ALL loans transactions (Global structure )
typedef struct Loan {
    struct Borrower *borrower;
    struct Book *book;
    int priority;
    Date borrow_date;
    Date return_date;
    int overdue;
    struct Loan *next;
} Loan;

// --------------------------------- Abstracht Machine Part -----------------------------------------------------

// Books structre Functions

// Function to get a Book ID
int getBookID(Book *b);

// Function to get a Book Title
char* getBookTitle(Book *b);

// Function to get a Book Author
char* getBookAuthor(Book *b);

// Function to get a Book Copies
int getBookCopies(Book *b);

// Function to get a Next Book structure Pointer
Book* getBookNext(Book *b);

// Function to get a Previous Book structure Pointer
Book* getBookPrev(Book *b);

// Function to set a Book ID
void setBookID(Book *b, int id);

// Function to set a Book Title
void setBookTitle(Book *b, char title[]);

// Function to set a Book Author
void setBookAuthor(Book *b, char author[]);

// Function to set a Book Copies
void setBookCopies(Book *b, int copies);

// Function to set a Next Book structure Pointer
void setBookNext(Book *b, Book *next);

// Function to set a Previous Book structure Pointer
void setBookPrev(Book *b, Book *prev);

// Function to set a whole Book structure
void setBook(Book *b, int id, char title[], char author[], int copies );




// Borrower Structure functions

// Function to get a Borrower ID
int getBorrowerID(Borrower *b);

// Function to get a Borrower Name
char* getBorrowerName(Borrower *b);

// Function to get a Next Borrower structure Pointer
Borrower* getBorrowerNext(Borrower *b);

// Function to get a Previous Borrower structure Pointer
Borrower* getBorrowerPrev(Borrower *b);

// Function to set a Borrower ID
void setBorrowerID(Borrower *b, int id);

// Function to set a Borrower Name
void setBorrowerName(Borrower *b, char name[]);

// Function to set a Next Borrower structure Pointer
void setBorrowerNext(Borrower *b, Borrower *next);

// Function to set a Previous Borrower structure Pointer
void setBorrowerPrev(Borrower *b, Borrower *prev);

// Function to set a whole Borrower structure
void setBorrower(Borrower *b, int id, char name[]);



// Loan Structure functions

// Function to get a Loan Borrower Structure Pointer
Borrower* getLoanBorrower(Loan *l);

// Function to get a Loan Book Structure Pointer
Book* getLoanBook(Loan *l);

// Function to get the Borrow Date of a Loan Structure
Date getBorrowDate(Loan *l);

// Function to get the Return Date of a Loan Structure
Date getReturnDate(Loan *l);

// Function to get the priority of a Loan Structure
int getLoanPriority(Loan *l);

// Function to get the status of a Loan Structure
int getLoanOverdue(Loan *l);

// Function to get the next Loan structure Pointer
Loan* getLoanNext(Loan *l);

// Function to set a Loan Borrower Structure Pointer
void setLoanBorrower(Loan *l, Borrower *b);

// Function to set a Loan Book Structure Pointer
void setLoanBook(Loan *l, Book *b);

// Function to set the Borrow Date of a Loan Structure
void setBorrowDate(Loan *l, Date borrow_date);

// Function to set the Return Date of a Loan Structure
void setReturnDate(Loan *l, Date return_date);

// Function to set the priority of a Loan Structure
void setLoanPriority(Loan *l, int priority);

// Function to set the status of a Loan Structure
void setLoanOverdue(Loan *l, int overdue);

// Function to set the next Loan structure Pointer
void setLoanNext(Loan *l, Loan *next);

// Function to set a whole Loan structure
void setLoan(Loan *l, Borrower *b, Book *bk, int priority,int overdue);





// Date functions
// Function to get the year of a Date structure
int getDateYear(Date d);

// Function to get the month of a Date structure
int getDateMonth(Date d);

// Function to get the day of a Date structure
int getDateDay(Date d);

// Function to set the year of a Date structure
void setDateYear(Date *d, int year);

// Function to set the month of a Date structure
void setDateMonth(Date *d, int month);

// Function to set the day of a Date structure
void setDateDay(Date *d, int day);


// -------------------------------------- Abstraction LEVEL 2-------------------------------------------------

// Free functions

// Function to free a book linked list
void freeBooks(Book *head);

// Function to free a browwers linked list
void freeBorrowers(Borrower *head);

// Function to free a loan linked list
void freeLoans(Loan *head);

// Length Functions

// Function to calculate the length of a Book linked list
int BooksLenght(Book *head);

// Function to calculate the length of a Borrower linked list
int BorrowersLenght(Borrower *head);

// Function to calculate the length of a Loans linked list
int LoansLenght(Loan *head);

// Insertion in lists Function

// Function to insert a book in a book linked lists
Book* insertBook(Book *head, int id, char title[], char author[], int copies);

// Function to insert a borrower in a borrowers linked list
Borrower* insertBorrower(Borrower *head, int id, char name[]);

// Function to insert a loan in a loans linked list
Loan* insertLoan(Loan *head, Borrower *b, Book *bk, int priority, Date borrow_date, Date return_date,int overdue);

//Some Dates functions

// Function to compare the return date with the actual date
int compare_date(Loan *l);

// Function to compare 2 dates strcutures
int compareDates(Date date1, Date date2);

// Function to add a number of days to a date to manipulate the return date easily
Date addDaysToDate(Date date, int days);


// ----------------------------------- General Utils Functions-----------------------------------------

// Function to print all active overdued loans
void overdue(Loan *l);

// Function to check if a book exists by id and gets it addresse
Book* findBookById(Book *bookList, int id);

// Function to check if a borrower exists by id and gets it addresse
Borrower* findBorrowerById(Borrower *borrowerList, int id);



// Function to check if a book is available for borrowing by checking number of copies
int isBookAvailable(Book *book);

// Function to check if a loan exists
Loan* findActiveLoan(Loan *loanList, int bookId, int borrowerId);

// Function to validate a loan request by takinng into account the book availability and the borrower status
int validateLoanRequest(Book *book, Borrower *borrower, Loan *activeLoanList);


// ------------------------------------Menu Functions------------------------------------------------

// Function to make a pause screen after outputs
void pauseScreen();

// Function to get integer input to easily get inputs
int getIntInput(const char *prompt);

// Function to get string input to easily get inputs
void getStringInput(const char *prompt, char *buffer, int size);

// Function to format the Date strcuture for output
char* formatDate(Date d) ;

// Function to Display the main menu
void displayMenu(Book **books, Loan **activeloans, Loan **pendingloans, Loan **returnedloans, Borrower **borrowers) ;

// Function to Display the sub Menu for books manipulation
void BookMenu(Book **b) ;

// Function to Display the sub Menu for borrowers manipulation
void LoansMenu(Loan **active, Loan **pending, Loan **returned, Borrower **b, Book *bk);

// Function to Display the sub Menu for Files manipulation
void FilesMenu(Book **bk,Loan **active,Loan **pending,Loan **returned,Borrower **b);

// Function to Display the sub Menu for library statistics
void statisticsMenu(Book **bk,Borrower **b,Loan **active,Loan **pending,Loan **returned);

// Function to Display the sub Menu for borrowers manipulation
void BorrowersMenu(Borrower **b);

// Function to manipulate adding a book via the user interface
void addBook(Book **bookList);

// Function to manipulate adding a borrower via the user interface
void addBorrower(Borrower **borrowerList) ;

// Function to manipulate adding a loan via the user interface
void AddLoan(Borrower **borrowerList, Loan **activeLoanList,Loan **pendingLoanList, Book *bookList);

// Function to display all loans (active, pending, and returned)
void print_AllLoans(Loan *activeLoanList, Loan *pendingLoanList, Loan *returnedLoanList);

// Function to display a table line
void print_ligne();

// Function to display a table books header
void print_header_books();

// Function to display a table book line
void print_book_ligne(Book *b);

// Function to display a table borrowers header
void print_header_borrowers();

// Function to display a table borrowers line
void print_borrower_ligne(Borrower *b);

// Function to display a table loans header
void print_header_loan();

// Function to display a table loans line
void print_loan_ligne(Loan *l) ;

// Function to display a table returned loans header
void print_header_returned_loans();

// Function to display a table returned loans line
void print_returned_loan_ligne(Loan *l);

// Function to print the books table
void print_books(Book *b) ;

// Function to print the borrowers table
void print_borrowers(Borrower *b);

// Function to print a loans table
void print_Loans(Borrower *b, Book *bk, Loan *l);


// Function to search for a book by title and display results as table
void searchBooksByName(Book *bookList);

// Function to process returning a book via user interface
void AddReturn(Loan **activeLoanList, Loan **pendingLoanList,
    Loan **returnedLoanList, Book *bookList);

// Function to display opening interface
void Herosec();

// Function to display Return system explanation
void ReturnSystemExplanation();


// -------------------------------File manipulation Functions -------------------------------------//

// Function to process books from the file
void loadBooksFromFile(const char *filename, Book **bookList);

// Function to process borrowers from the file
void processBorrowerData(char *line, Borrower **borrowerList) ;

// Function to process borrowing books from the file
void processBorrowBook(char *line, Borrower **borrowerList, Loan **activeLoanList,
                        Loan **pendingLoanList, Book *bookList);

// Function to process returned books from the file
void processReturnBook(char *line, Loan **activeLoanList, Loan **pendingLoanList,
    Loan **returnedLoanList, Book *bookList) ;

// Function to process Library Data from the file
void loadLibraryData(const char *filename, Borrower **borrowerList, Loan **activeLoanList,
    Loan **pendingLoanList, Loan **returnedLoanList, Book *bookList,int choice);


#endif
