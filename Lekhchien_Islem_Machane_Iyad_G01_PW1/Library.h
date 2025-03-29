
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
int getBookID(Book *b) { return b->id; }
char* getBookTitle(Book *b) { return b->title; }
char* getBookAuthor(Book *b) { return b->author; }
int getBookCopies(Book *b) { return b->copies; }
Book* getBookNext(Book *b) { return b->next; }
Book* getBookPrev(Book *b) { return b->prev; }
void setBookID(Book *b, int id) { b->id = id; }
void setBookTitle(Book *b, char title[]) { strcpy(b->title, title); }
void setBookAuthor(Book *b, char author[]) { strcpy(b->author, author); }
void setBookCopies(Book *b, int copies) { b->copies = copies; }
void setBookNext(Book *b, Book *next) { b->next = next; }
void setBookPrev(Book *b, Book *prev) { b->prev = prev; }
void setBook(Book *b, int id, char title[], char author[], int copies ) {
    setBookID(b, id);
    setBookTitle(b, title);
    setBookAuthor(b, author);
    setBookCopies(b, copies);
}



// BookTheme functions


// Borrower functions
int getBorrowerID(Borrower *b) { return b->id; }
char* getBorrowerName(Borrower *b) { return b->name; }
Borrower* getBorrowerNext(Borrower *b) { return b->next; }
Borrower* getBorrowerPrev(Borrower *b) { return b->prev; }
void setBorrowerID(Borrower *b, int id) { b->id = id; }
void setBorrowerName(Borrower *b, char name[]) { strcpy(b->name, name); }
void setBorrowerNext(Borrower *b, Borrower *next) { b->next = next; }
void setBorrowerPrev(Borrower *b, Borrower *prev) { b->prev = prev; }
void setBorrower(Borrower *b, int id, char name[]) {
    setBorrowerID(b, id);
    setBorrowerName(b, name);
}

// Loan functions
Borrower* getLoanBorrower(Loan *l) { return l->borrower; }
Book* getLoanBook(Loan *l) { return l->book; }
Date getBorrowDate(Loan *l) { return l->borrow_date; }
Date getReturnDate(Loan *l) { return l->return_date; }
int getLoanPriority(Loan *l) { return l->priority; }
int getLoanOverdue(Loan *l) { return l->overdue; }
Loan* getLoanNext(Loan *l) { return l->next; }
void setLoanBorrower(Loan *l, Borrower *b) { l->borrower = b; }
void setLoanBook(Loan *l, Book *b) { l->book = b; }
void setBorrowDate(Loan *l, Date borrow_date) { l->borrow_date = borrow_date; }
void setReturnDate(Loan *l, Date return_date) { l->return_date = return_date; }
void setLoanPriority(Loan *l, int priority) { l->priority = priority; }
void setLoanOverdue(Loan *l, int overdue) { l->overdue = overdue; }
void setLoanNext(Loan *l, Loan *next) { l->next = next; }
void setLoan(Loan *l, Borrower *b, Book *bk, int priority) {
    setLoanBorrower(l, b);
    setLoanBook(l, bk);
    setLoanPriority(l, priority);
}

// Date functions
int getDateYear(Date d) { return d.year; }
int getDateMonth(Date d) { return d.month; }
int getDateDay(Date d) { return d.day; }
void setDateYear(Date *d, int year) { d->year = year; }
void setDateMonth(Date *d, int month) { d->month = month; }
void setDateDay(Date *d, int day) { d->day = day; }

// Free functions
void freeBooks(Book *head) {
    Book *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void freeBorrowers(Borrower *head) {
    Borrower *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void freeLoans(Loan *head) {
    Loan *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}




// Update insertBook to pass the book pointer
Book* insertBook(Book *head, int id, char title[], char author[], int copies) {
    Book *newBook = NULL;
    int attempts = 0;
    while (newBook == NULL && attempts < 3) {
        newBook = (Book*) malloc(sizeof(Book));
        attempts++;
    }
    if (newBook == NULL) {
        printf("Memory allocation failed for new book after %d attempts.\n", attempts);
        return head;
    }
    setBook(newBook, id, title, author, copies);
    setBookNext(newBook, NULL);
    setBookPrev(newBook, NULL);
    // Rest of the existing insertBook function remains the same
    if (head == NULL || getBookID(head) > id) {
        setBookNext(newBook, head);
        if (head != NULL) setBookPrev(head, newBook);
        return newBook;
    }

    Book *current = head;
    while (getBookNext(current) != NULL && getBookID(getBookNext(current)) < id)
        current = getBookNext(current);

    setBookNext(newBook, getBookNext(current));
    if (getBookNext(current) != NULL)
        setBookPrev(getBookNext(current), newBook);
    setBookNext(current, newBook);
    setBookPrev(newBook, current);

    return head;
};




Borrower* insertBorrower(Borrower *head, int id, char name[]) {
    Borrower *newBorrower = NULL;
    int attempts = 0;
    while (newBorrower == NULL && attempts < 3) {
        newBorrower = (Borrower*) malloc(sizeof(Borrower));
        attempts++;
    }
    if (newBorrower == NULL) {
        printf("Memory allocation failed for new borrower after %d attempts.\n", attempts);
        return head;
    }
    setBorrower(newBorrower, id, name);
    setBorrowerNext(newBorrower, NULL);
    setBorrowerPrev(newBorrower, NULL);

    if (head == NULL || getBorrowerID(head) > id) {
        setBorrowerNext(newBorrower, head);
        if (head != NULL) setBorrowerPrev(head, newBorrower);
        return newBorrower;
    }

    Borrower *current = head;
    while (getBorrowerNext(current) != NULL && getBorrowerID(getBorrowerNext(current)) < id) {
        current = getBorrowerNext(current);
    }

    setBorrowerNext(newBorrower, getBorrowerNext(current));
    if (getBorrowerNext(current) != NULL) {
        setBorrowerPrev(getBorrowerNext(current), newBorrower);
    }
    setBorrowerNext(current, newBorrower);
    setBorrowerPrev(newBorrower, current);

    return head;
}


Loan* insertLoan(Loan *head, Borrower *b, Book *bk, int priority, Date borrow_date, Date return_date) {
    Loan *newLoan = (Loan*) malloc(sizeof(Loan));
    if (newLoan == NULL) {
        printf("Memory allocation failed for new loan.\n");
        return head; // Return the original list if allocation fails
    }
    setLoan(newLoan, b, bk, priority);
    setBorrowDate(newLoan, borrow_date);
    setReturnDate(newLoan, return_date);
    setLoanNext(newLoan, NULL);

    if (head == NULL || getLoanPriority(head) > priority) {
        setLoanNext(newLoan, head);
        return newLoan;
    }

    Loan *current = head;
    while (getLoanNext(current) != NULL && getLoanPriority(getLoanNext(current)) <= priority) {
        current = getLoanNext(current);
    }

    setLoanNext(newLoan, getLoanNext(current));
    setLoanNext(current, newLoan);

    return head;
}

int compare_date(Loan *l) {
    time_t t;
    struct tm *current_time;

    time(&t);
    current_time = localtime(&t);

    int current_day = current_time->tm_mday;
    int current_month = current_time->tm_mon + 1;
    int current_year = current_time->tm_year + 1900;

    // Using getter functions instead of direct struct access
    int return_year = getDateYear(getReturnDate(l));
    int return_month = getDateMonth(getReturnDate(l));
    int return_day = getDateDay(getReturnDate(l));

    // Compare years first
    if (return_year < current_year) return 1;  // Overdue


    // Same year, compare months
    if (return_month < current_month) return 1;  // Overdue


    if (return_day < current_day) return 1;  // Overdue

    return 0;  // Not overdue
}

// Update overdue function to use the correct functions
void overdue(Loan *l) {
    while (l != NULL) {
        if (compare_date(l)) {
            printf("\nLoan - Borrower: %s, Book: %s, Priority: %d\n",
                getBorrowerName(getLoanBorrower(l)),  // Use getLoanBorrower
                getBookTitle(getLoanBook(l)),         // Use getLoanBook
                getLoanPriority(l));
        }
        l = getLoanNext(l);
    }
}


// Function to check if a book exists
Book* findBookById(Book *bookList, int id) {
    Book *b = bookList;
    while (b != NULL) {
        if (getBookID(b) == id) return b;
        b = getBookNext(b);
    }
    return NULL;
}

// Function to check if a borrower exists
Borrower* findBorrowerById(Borrower *borrowerList, int id) {
    Borrower *br = borrowerList;
    while (br != NULL) {
        if (getBorrowerID(br) == id) return br;
        br = getBorrowerNext(br);
    }
    return NULL;
}



#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif




// Function prototypes
void pauseScreen();
int getIntInput(const char *prompt);
void getStringInput(const char *prompt, char *buffer, int size);
void displayMenu();
void addBook(Book **bookList);
void addBorrower(Borrower **borrowerList);
void addLoan(Loan **activeLoanList, Loan **pendingLoanList, Book *bookList, Borrower *borrowerList);
void returnBook(Loan **activeLoanList, Loan **pendingLoanList, Loan **returnedLoanList, Book *bookList);
void print_PendingLoans(Loan *l);
void print_ReturnedLoans(Loan *l);
void print_ActiveLoans(Loan *l);
void print_AllLoans(Loan *activeLoanList, Loan *pendingLoanList, Loan *returnedLoanList);
void print_ligne();
void print_header_books();
void print_book_ligne(Book *b);
void print_header_borrowers();
void print_borrower_ligne(Borrower *b);
void print_header_loan();
char* formatDate(Date d);
void print_loan_ligne(Loan *l);
void print_books(Book *b);
void print_borrowers(Borrower *b);
void print_Loans(Borrower *b, Book *bk, Loan *l);
void searchBooksByName(Book *bookList);


void pauseScreen() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n'); // Clear the buffer
    getchar(); // Wait for the actual Enter key press
}

int getIntInput(const char *prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            break;
        } else {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }
    return value;
}

void getStringInput(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    scanf(" ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

void displayMenu() {
    printf("\n========== LIBRARY MANAGEMENT SYSTEM ==========\n");
    printf("1. Add Book\n");
    printf("2. List Books\n");
    printf("3. Add Borrower\n");
    printf("4. List Borrowers\n");
    printf("5. Add Loan\n");
    printf("6. List All Loans\n");
    printf("7. Return Book\n");
    printf("8. Check Overdue\n");
    printf("9. Search Books by Title\n");
    printf("10. Exit\n");
    printf("==============================================\n");
    printf("Enter your choice: ");
}

void addBook(Book **bookList) {
    int id, copies;
    char title[100], author[100];

    id = getIntInput("Enter Book ID: ");
    if (findBookById(*bookList, id) != NULL) {
        printf("Book with ID %d already exists.\n", id);
        pauseScreen();
        return;
    }
    getStringInput("Enter Title: ", title, sizeof(title));
    getStringInput("Enter Author: ", author, sizeof(author));
    copies = getIntInput("Enter Copies: ");

    Book *newBook = insertBook(*bookList, id, title, author, copies);
    if (newBook == NULL) {
        printf("Failed to add book due to memory allocation error.\n");
        pauseScreen();
        return;
    }
    *bookList = newBook;
    printf("Book added successfully!\n");
    pauseScreen();
}

void addBorrower(Borrower **borrowerList) {
    int id;
    char name[100];

    id = getIntInput("Enter Borrower ID: ");
    if (findBorrowerById(*borrowerList, id) != NULL) {
        printf("Borrower with ID %d already exists.\n", id);
        pauseScreen();
        return;
    }
    getStringInput("Enter Name: ", name, sizeof(name));

    Borrower *newBorrower = insertBorrower(*borrowerList, id, name);
    if (newBorrower == NULL) {
        printf("Failed to add borrower due to memory allocation error.\n");
        pauseScreen();
        return;
    }
    *borrowerList = newBorrower;
    printf("Borrower added successfully!\n");
    pauseScreen();
}

void addLoan(Loan **activeLoanList, Loan **pendingLoanList, Book *bookList, Borrower *borrowerList) {
    int borrower_id, book_id, priority;
    Date borrow_date, return_date;
    Borrower *borrower;
    Book *book;

    borrower_id = getIntInput("Enter Borrower ID: ");
    borrower = findBorrowerById(borrowerList, borrower_id);
    if (borrower == NULL) {
        printf("Borrower with ID %d does not exist.\n", borrower_id);
        pauseScreen();
        return;
    }

    book_id = getIntInput("Enter Book ID: ");
    book = findBookById(bookList, book_id);
    if (book == NULL) {
        printf("Book with ID %d does not exist.\n", book_id);
        pauseScreen();
        return;
    }

    priority = getIntInput("Enter Loan Priority: ");
    printf("Enter Borrow Date (dd mm yyyy): ");
    scanf("%d %d %d", &borrow_date.day, &borrow_date.month, &borrow_date.year);

    // Set return date to 14 days after borrow date
    return_date = borrow_date;

    // Add 14 days to the borrow date using setter functions
    int new_day = getDateDay(borrow_date) + 14;
    int new_month = getDateMonth(borrow_date);
    int new_year = getDateYear(borrow_date);

    // Handle month/year rollover
    if (new_day > 30) {  // Simple approach (doesn't account for varying month lengths)
        new_day -= 30;
        new_month += 1;
        if (new_month > 12) {
            new_month = 1;
            new_year += 1;
        }
    }

    setDateDay(&return_date, new_day);
    setDateMonth(&return_date, new_month);
    setDateYear(&return_date, new_year);

    printf("Return Date set to: %d/%d/%d (14 days after borrow date)\n",
        getDateDay(return_date), getDateMonth(return_date), getDateYear(return_date));

    // Check if there are copies available to borrow
    if (getBookCopies(book) > 0) {
        // Decrement the number of copies available
        setBookCopies(book, getBookCopies(book) - 1);
        printf("Number of copies of '%s' reduced to %d\n", getBookTitle(book), getBookCopies(book));

        // Add to active loans
        *activeLoanList = insertLoan(*activeLoanList, borrower, book, priority, borrow_date, return_date);
        printf("Loan added successfully to active loans!\n");
    } else {
        // No copies available, add to pending loans
        *pendingLoanList = insertLoan(*pendingLoanList, borrower, book, priority, borrow_date, return_date);
        printf("No copies available. Loan added to pending list!\n");
    }

    pauseScreen();
}

// Function to return a book
void returnBook(Loan **activeLoanList, Loan **pendingLoanList, Loan **returnedLoanList, Book *bookList) {
    int book_id, borrower_id;
    Loan *current, *prev = NULL, *toReturn = NULL;

    book_id = getIntInput("Enter Book ID to return: ");
    borrower_id = getIntInput("Enter Borrower ID: ");

    // Find the loan in active loans
    current = *activeLoanList;
    while (current != NULL) {
        if (getBookID(getLoanBook(current)) == book_id &&
            getBorrowerID(getLoanBorrower(current)) == borrower_id) {
            // Found the loan to return
            if (prev == NULL) {
                *activeLoanList = getLoanNext(current);
            } else {
                setLoanNext(prev, getLoanNext(current));
            }
            toReturn = current;
            setLoanNext(toReturn, NULL);
            break;
        }
        prev = current;
        current = getLoanNext(current);
    }

    if (toReturn == NULL) {
        printf("Loan not found in active loans!\n");
        pauseScreen();
        return;
    }

    // Get the book from the loan
    Book *book = getLoanBook(toReturn);

    // Check if there are pending loans for this book
    Loan *pendingLoan = NULL;
    Loan *highestPriorityLoan = NULL;
    int highestPriority = -1;

    current = *pendingLoanList;
    prev = NULL;

    // Find the highest priority pending loan for this book
    while (current != NULL) {
        if (getBookID(getLoanBook(current)) == book_id) {
            if (getLoanPriority(current) > highestPriority) {
                highestPriority = getLoanPriority(current);
                highestPriorityLoan = current;
                pendingLoan = prev;
            }
        }
        prev = current;
        current = getLoanNext(current);
    }

    // Get return date as input instead of using current date
    Date returnDate;
    printf("Enter Return Date (dd mm yyyy): ");
    scanf("%d %d %d", &returnDate.day, &returnDate.month, &returnDate.year);

    // Add the returned loan to returned list
    *returnedLoanList = insertLoan(*returnedLoanList, getLoanBorrower(toReturn),
                                  getLoanBook(toReturn), getLoanPriority(toReturn),
                                  getBorrowDate(toReturn), returnDate);

    if (highestPriorityLoan != NULL) {
        // Remove from pending list
        if (pendingLoan == NULL) {
            *pendingLoanList = getLoanNext(highestPriorityLoan);
        } else {
            setLoanNext(pendingLoan, getLoanNext(highestPriorityLoan));
        }
        setLoanNext(highestPriorityLoan, NULL);

        // Use the return date of the active loan as the borrow date for the pending loan
        Date borrow_date = returnDate;
        setBorrowDate(highestPriorityLoan, borrow_date);

        // Calculate new return date (14 days from borrow date)
        Date return_date = borrow_date;
        int new_day = getDateDay(borrow_date) + 14;
        int new_month = getDateMonth(borrow_date);
        int new_year = getDateYear(borrow_date);

        if (new_day > 30) {
            new_day -= 30;
            new_month += 1;
            if (new_month > 12) {
                new_month = 1;
                new_year += 1;
            }
        }

        setDateDay(&return_date, new_day);
        setDateMonth(&return_date, new_month);
        setDateYear(&return_date, new_year);
        setReturnDate(highestPriorityLoan, return_date);

        // Add to active loans
        *activeLoanList = insertLoan(*activeLoanList, getLoanBorrower(highestPriorityLoan),
                                    getLoanBook(highestPriorityLoan), getLoanPriority(highestPriorityLoan),
                                    getBorrowDate(highestPriorityLoan), getReturnDate(highestPriorityLoan));

        printf("Book loaned to next person in pending list (Priority: %d)!\n",
               getLoanPriority(highestPriorityLoan));
        printf("New loan period: %s to %s\n",
               formatDate(getBorrowDate(highestPriorityLoan)),
               formatDate(getReturnDate(highestPriorityLoan)));

        // Free the pending loan
        free(highestPriorityLoan);
    } else {
        // No pending loans, increment book copies
        setBookCopies(book, getBookCopies(book) + 1);
        printf("Book returned and copies incremented to %d!\n", getBookCopies(book));
    }

    // Free the returned loan
    free(toReturn);

    printf("Book returned successfully!\n");
    pauseScreen();
}

// Function to print pending loans
void print_PendingLoans(Loan *l) {
    if (l != NULL) {
        printf("\n========== PENDING LOANS ==========\n");
        print_ligne();
        print_header_loan();
        print_ligne();

        while (l != NULL) {
            print_loan_ligne(l);
            print_ligne();
            l = getLoanNext(l);
        }
    } else {
        printf("\nNo pending loans available.\n");
    }

    pauseScreen();
}

// Function to print returned loans
void print_ReturnedLoans(Loan *l) {
    if (l != NULL) {
        printf("\n========== RETURNED LOANS ==========\n");
        print_ligne();
        print_header_loan();
        print_ligne();

        while (l != NULL) {
            print_loan_ligne(l);
            print_ligne();
            l = getLoanNext(l);
        }
    } else {
        printf("\nNo returned loans available.\n");
    }

    pauseScreen();
}

// Update the existing print_Loans function to show it's for active loans
void print_ActiveLoans(Loan *l) {
    if (l != NULL) {
        printf("\n========== ACTIVE LOANS ==========\n");
        print_ligne();
        print_header_loan();
        print_ligne();

        while (l != NULL) {
            print_loan_ligne(l);
            print_ligne();
            l = getLoanNext(l);
        }
    } else {
        printf("\nNo active loans available.\n");
    }

    pauseScreen();
}

// Function to display all loans (active, pending, and returned)
void print_AllLoans(Loan *activeLoanList, Loan *pendingLoanList, Loan *returnedLoanList) {
    printf("\n========== ALL LOANS ==========\n");

    // Print active loans
    if (activeLoanList != NULL) {
        printf("\n--- ACTIVE LOANS ---\n");
        print_ligne();
        print_header_loan();
        print_ligne();

        Loan *current = activeLoanList;
        while (current != NULL) {
            print_loan_ligne(current);
            print_ligne();
            current = getLoanNext(current);
        }
    } else {
        printf("\nNo active loans available.\n");
    }

    // Print pending loans
    if (pendingLoanList != NULL) {
        printf("\n--- PENDING LOANS ---\n");
        print_ligne();
        print_header_loan();
        print_ligne();

        Loan *current = pendingLoanList;
        while (current != NULL) {
            print_loan_ligne(current);
            print_ligne();
            current = getLoanNext(current);
        }
    } else {
        printf("\nNo pending loans available.\n");
    }

    // Print returned loans
    if (returnedLoanList != NULL) {
        printf("\n--- RETURNED LOANS ---\n");
        print_ligne();
        print_header_loan();
        print_ligne();

        Loan *current = returnedLoanList;
        while (current != NULL) {
            print_loan_ligne(current);
            print_ligne();
            current = getLoanNext(current);
        }
    } else {
        printf("\nNo returned loans available.\n");
    }

    pauseScreen();
}


void print_ligne() {
    printf("------------------------------------------------------------------------------------------------\n");
}

void print_header_books() {
    printf("| %-8s | %-46s | %-24s | %-4s |\n",
           "Book Id", "Book Name",  "Author", "Copies");
}

void print_book_ligne(Book *b) {
    printf("| %-8d | %-46s | %-24s  | %-4d |\n",
           getBookID(b), getBookTitle(b),  getBookAuthor(b), getBookCopies(b));
}

void print_header_borrowers() {
    printf("| %-30s | %-59s |\n",
           "Borrower Id", "Borrower Name");
}

void print_borrower_ligne(Borrower *b) {
    printf("| %-30d | %-59s |\n",
           getBorrowerID(b), getBorrowerName(b));
}

void print_header_loan() {
    printf("| %-17s | %-32s | %-11s | %-11s | %-9s |\n",
           "Borrower Name", "Book Name", "Borrow Date", "Return Date", "Priority");
}

char* formatDate(Date d) {
    static char dateStr[20];
    sprintf(dateStr, "%d/%d/%d", getDateDay(d), getDateMonth(d), getDateYear(d));
    return dateStr;
}

void print_loan_ligne(Loan *l) {
    printf("| %-17s | ", getBorrowerName(getLoanBorrower(l)));
    printf("%-32s | ", getBookTitle(getLoanBook(l)));
    printf("%-11s | ", formatDate(getBorrowDate(l)));
    printf("%-11s | ", formatDate(getReturnDate(l)));
    printf("%-9d |\n", getLoanPriority(l));
}

void print_books(Book *b) {
    if (b != NULL) {
        print_ligne();
        print_header_books();
        print_ligne();

        while (b != NULL) {
            print_book_ligne(b);
            print_ligne();
            b = getBookNext(b);
        }
    } else {
        printf("\nNo books available.\n");
    }

    pauseScreen();
}

void print_borrowers(Borrower *b) {
    if (b != NULL) {
        print_ligne();
        print_header_borrowers();
        print_ligne();

        while (b != NULL) {
            print_borrower_ligne(b);
            print_ligne();
            b = getBorrowerNext(b);
        }
    } else {
        printf("\nNo borrowers available.\n");
    }

    pauseScreen();
}

void print_Loans(Borrower *b, Book *bk, Loan *l) {
    if (l != NULL) {
        print_ligne();
        print_header_loan();
        print_ligne();

        while (l != NULL) {
            print_loan_ligne(l);
            print_ligne();
            l = getLoanNext(l);
        }
    } else {
        printf("\nNo Loans available.\n");
    }

    pauseScreen();
};




void searchBooksByName(Book *bookList) {
    char searchTerm[100];
    int found = 0;

    getStringInput("Enter book title to search: ", searchTerm, sizeof(searchTerm));

    if (bookList != NULL) {
        print_ligne();
        print_header_books();
        print_ligne();

        Book *current = bookList;
        while (current != NULL) {
            // Case-insensitive search (convert both to lowercase for comparison)
            char bookTitle[100];
            char searchTermLower[100];

            strcpy(bookTitle, getBookTitle(current));
            strcpy(searchTermLower, searchTerm);

            // Convert to lowercase
            for (int i = 0; bookTitle[i]; i++) {
                if (bookTitle[i] >= 'A' && bookTitle[i] <= 'Z')
                    bookTitle[i] += 32;
            }

            for (int i = 0; searchTermLower[i]; i++) {
                if (searchTermLower[i] >= 'A' && searchTermLower[i] <= 'Z')
                    searchTermLower[i] += 32;
            }

            // Check if search term is contained in the book title
            if (strstr(bookTitle, searchTermLower) != NULL) {
                print_book_ligne(current);
                print_ligne();
                found = 1;
            }

            current = getBookNext(current);
        }

        if (!found) {
            printf("|No books found matching %-69s|\n", searchTerm);
            print_ligne();
        }
    } else {
        printf("\nNo books available.\n");
    }

    pauseScreen();
}


void loadBooksFromFile(const char *filename, Book **bookList) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    int lineNumber = 0;
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        if (line[0] == '#') {
            printf("Skipping comment line %d\n", lineNumber);
            continue;
        }

        int id, copies;
        char title[100], author[100];

        if (sscanf(line, "ADD_BOOK %d \"%[^\"]\" \"%[^\"]\" %d", &id, title, author, &copies) == 4) {
            if (findBookById(*bookList, id) == NULL) {
                *bookList = insertBook(*bookList, id, title, author, copies);
                printf("Added book ID %d: %s by %s\n", id, title, author);
            } else {
                printf("Book with ID %d already exists.\n", id);
            }
        }
    }

    fclose(file);
}

void loadLibraryData(const char *filename, Borrower **borrowerList, Loan **activeLoanList, Loan **returnedLoanList, Book *bookList) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    int lineNumber = 0;
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        if (line[0] == '#') {
            printf("Skipping comment line %d\n", lineNumber);
            continue;
        }

        int id, borrower_id, book_id, priority;
        char name[100];
        Date date;

        if (sscanf(line, "ADD_BORROWER %d %s", &id, name) == 2) {
            if (findBorrowerById(*borrowerList, id) == NULL) {
                *borrowerList = insertBorrower(*borrowerList, id, name);
                printf("Added borrower ID %d: %s\n", id, name);
            } else {
                printf("Borrower with ID %d already exists.\n", id);
            }
        } else if (sscanf(line, "BORROW_BOOK %d %d %d-%d-%d %d", &book_id, &borrower_id, &date.year, &date.month, &date.day, &priority) == 6) {
            Borrower *borrower = findBorrowerById(*borrowerList, borrower_id);
            Book *book = findBookById(bookList, book_id);
            if (borrower == NULL) {
                printf("Error: Borrower with ID %d not found.\n", borrower_id);
                continue;
            }
            if (book == NULL) {
                printf("Error: Book with ID %d not found.\n", book_id);
                continue;
            }
            if (borrower && book) {
                *activeLoanList = insertLoan(*activeLoanList, borrower, book, priority, date, date);
                printf("Borrowed book ID %d by borrower ID %d\n", book_id, borrower_id);
            } else {
                printf("Borrower or Book not found for BORROW_BOOK transaction.\n");
            }
        } else if (sscanf(line, "RETURN_BOOK %d %d %d-%d-%d", &book_id, &borrower_id, &date.year, &date.month, &date.day) == 5) {
            Loan *loan = *activeLoanList;
            while (loan != NULL) {
                if (getBookID(getLoanBook(loan)) == book_id && getBorrowerID(getLoanBorrower(loan)) == borrower_id) {
                    *returnedLoanList = insertLoan(*returnedLoanList, getLoanBorrower(loan), getLoanBook(loan), getLoanPriority(loan), getBorrowDate(loan), date);
                    printf("Returned book ID %d by borrower ID %d\n", book_id, borrower_id);
                    break;
                }
                loan = getLoanNext(loan);
            }
        }
    }

    fclose(file);
}
