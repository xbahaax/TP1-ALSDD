#include "Library.h"

int getBookID(Book *b)
{
    return b->id;
}


char* getBookTitle(Book *b)
{
    return b->title;
}

char* getBookAuthor(Book *b)
{
    return b->author;
}

int getBookCopies(Book *b)
{
    return b->copies;
}


Book* getBookNext(Book *b)
{
    return b->next;
}

Book* getBookPrev(Book *b)
{
    return b->prev;
}

void setBookID(Book *b, int id)
{
    b->id = id;
}

void setBookTitle(Book *b, char title[])
{
    strcpy(b->title, title);
}

void setBookAuthor(Book *b, char author[])
{
    strcpy(b->author, author);
}

void setBookCopies(Book *b, int copies)
{
    b->copies = copies;
}

void setBookNext(Book *b, Book *next)
{
    b->next = next;
}

void setBookPrev(Book *b, Book *prev)
{
    b->prev = prev;
}


void setBook(Book *b, int id, char title[], char author[], int copies ) {
    setBookID(b, id);
    setBookTitle(b, title);
    setBookAuthor(b, author);
    setBookCopies(b, copies);
}




int getBorrowerID(Borrower *b)
{
    return b->id;
}

char* getBorrowerName(Borrower *b)
{
    return b->name;
}

Borrower* getBorrowerNext(Borrower *b)
{
    return b->next;
}

Borrower* getBorrowerPrev(Borrower *b)
{
    return b->prev;
}

void setBorrowerID(Borrower *b, int id)
{
    b->id = id;
}

void setBorrowerName(Borrower *b, char name[])
{
    strcpy(b->name, name);
}

void setBorrowerNext(Borrower *b, Borrower *next)
{
    b->next = next;
}

void setBorrowerPrev(Borrower *b, Borrower *prev)
{
    b->prev = prev;
}


void setBorrower(Borrower *b, int id, char name[]) {
    setBorrowerID(b, id);
    setBorrowerName(b, name);
}

// Loan functions
Borrower* getLoanBorrower(Loan *l)
{
    return l->borrower;
}

Book* getLoanBook(Loan *l)
{
    return l->book;
}

Date getBorrowDate(Loan *l)
{
    return l->borrow_date;
}

Date getReturnDate(Loan *l)
{
    return l->return_date;
}

int getLoanPriority(Loan *l)
{
    return l->priority;
}

int getLoanOverdue(Loan *l)
{
    return l->overdue;
}

Loan* getLoanNext(Loan *l)
{
    return l->next;
}

void setLoanBorrower(Loan *l, Borrower *b)
{
    l->borrower = b;
}

void setLoanBook(Loan *l, Book *b)
{
    l->book = b;
}

void setBorrowDate(Loan *l, Date borrow_date)
{
    l->borrow_date = borrow_date;
}

void setReturnDate(Loan *l, Date return_date)
{
    l->return_date = return_date;
}

void setLoanPriority(Loan *l, int priority)
{
    l->priority = priority;
}

void setLoanOverdue(Loan *l, int overdue)
{
    l->overdue = overdue;
}

void setLoanNext(Loan *l, Loan *next) { l->next = next; }
void setLoan(Loan *l, Borrower *b, Book *bk, int priority,int overdue) {
    setLoanBorrower(l, b);
    setLoanBook(l, bk);
    setLoanPriority(l, priority);
    setLoanOverdue(l,overdue);
}

// Date functions
int getDateYear(Date d)
{
    return d.year;
}

int getDateMonth(Date d)
{
    return d.month;
}

int getDateDay(Date d)
{
    return d.day;
}

void setDateYear(Date *d, int year)
{
    d->year = year;
}

void setDateMonth(Date *d, int month)
{
    d->month = month;
}

void setDateDay(Date *d, int day)
{
    d->day = day;
}

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

int BooksLenght(Book *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = getBookNext(head);
        }
        return count;
}

int BorrowersLenght(Borrower *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = getBorrowerNext(head);
        }
        return count;
}

int LoansLenght(Loan *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = getLoanNext(head);
        }
        return count;
}



Book* insertBook(Book *head, int id, char title[], char author[], int copies) {
    Book *newBook = NULL;
    while (newBook == NULL ) {
        newBook = (Book*) malloc(sizeof(Book));
    }
    setBook(newBook, id, title, author, copies);
    setBookNext(newBook, NULL);
    setBookPrev(newBook, NULL);
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
    while (newBorrower == NULL ) {
        newBorrower = (Borrower*) malloc(sizeof(Borrower));

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


Loan* insertLoan(Loan *head, Borrower *b, Book *bk, int priority, Date borrow_date, Date return_date,int overdue) {
    Loan *newLoan = NULL;
    while (newLoan == NULL) {
        newLoan = (Loan*) malloc(sizeof(Loan));
    }
    setLoan(newLoan, b, bk, priority,overdue);
    setBorrowDate(newLoan, borrow_date);
    setReturnDate(newLoan, return_date);
    setLoanNext(newLoan, NULL);
    setLoanOverdue(newLoan,overdue);

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

    // Getting the return date of the loan
    int return_year = getDateYear(getReturnDate(l));
    int return_month = getDateMonth(getReturnDate(l));
    int return_day = getDateDay(getReturnDate(l));

    // Compare years first , if return year is before current year then it is overdue
    if (return_year < current_year) return 1;  // Overdue


    //  compare months
    if (return_month < current_month) return 1;  // Overdue

    // Then comparing the day
    if (return_day < current_day) return 1;  // Overdue

    return 0;  // Not overdue
}


void overdue(Loan *l) {
    while (l != NULL) {
        if (compare_date(l)) {
            printf("\nLoan is Overdued !!! - Borrower: %s, Book: %s\n",
                getBorrowerName(getLoanBorrower(l)),  // Use getLoanBorrower
                getBookTitle(getLoanBook(l)));
        }
        l = getLoanNext(l);
    }
}



Book* findBookById(Book *bookList, int id) {
    Book *b = bookList;
    while (b != NULL) {
        if (getBookID(b) == id) return b;
        b = getBookNext(b);
    }
    return NULL;
}


Borrower* findBorrowerById(Borrower *borrowerList, int id) {
    Borrower *br = borrowerList;
    while (br != NULL) {
        if (getBorrowerID(br) == id) return br; // Return the borrower pointer
        br = getBorrowerNext(br);
    }
    return NULL;// NULL then borrower dosent exist
}




int isBookAvailable(Book *book) {
    if (book != NULL && getBookCopies(book) > 0) {
        return 1;  // Book is available
    }
    return 0;// Book is not available
}


Loan* findActiveLoan(Loan *loanList, int bookId, int borrowerId) {
    Loan *current = loanList;
    while (current != NULL) {
        if (getBookID(getLoanBook(current)) == bookId &&
            getBorrowerID(getLoanBorrower(current)) == borrowerId) {
            return current;// returning the loan if The book id and borrower id matches
        }
        current = getLoanNext(current);
    }
    return NULL;// NULL then loan dosent exist
}


int validateLoanRequest(Book *book, Borrower *borrower, Loan *activeLoanList) {
    if (book == NULL || borrower == NULL) {
        return 0; // Invalid book or borrower
    }

    if (!isBookAvailable(book)) {
        return -1; // Book not available
    }

    if (findActiveLoan(activeLoanList, getBookID(book), getBorrowerID(borrower))) {
        return -2; // Borrower already has this book , so he cant make a request on the book while borrowing it
    }

    return 1; // Valid request
}


Date addDaysToDate(Date date, int days) {
    date.day += days;

    while (date.day > 30) {
        date.day -= 30;
        date.month++;

        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }

    return date;
}


// Function to compare two dates
int compareDates(Date date1, Date date2) {
    if (date1.year < date2.year) {
        return -1; // return -1 if the date1 is < date2
    } else if (date1.year > date2.year) {
        return 1;// return 1 if the date1 is > date2
    } else {
        if (date1.month < date2.month) {
            return -1; // return -1 if the date1 is < date2
        } else if (date1.month > date2.month) {
            return 1;// return 1 if the date1 is > date2
        } else {
            if (date1.day < date2.day) {
                return -1; // return -1 if the date1 is < date2
            } else if (date1.day > date2.day) {
                return 1;// return 1 if the date1 is > date2
            } else {
                return 0;// Those two dates are equal
            }
        }
    }
}


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
            while (getchar() != '\n'); // Clear the input and requesting to re enter it until getting a valid input
        }
    }
    return value;// return the input
}

void getStringInput(const char *prompt, char *buffer, int size) {
    // Display the prompt message to the user
    printf("%s", prompt);

    // Clear any leftover characters in the input buffer (especially newlines from previous inputs)
    while (getchar() != '\n'); 

    // Read a string from the user, ensuring it does not exceed 'size - 1' characters
    fgets(buffer, size, stdin);

    // Remove the newline character ('\n') that fgets() stores at the end of input, if any
    buffer[strcspn(buffer, "\n")] = 0;
}


void displayMenu(Book **books, Loan **activeloans, Loan **pendingloans, Loan **returnedloans, Borrower **borrowers) {
    int choice;
    do {
        system(CLEAR_SCREEN);
        printf("\n========== LIBRARY MANAGEMENT SYSTEM ===========\n");
        printf("|    1. Book Management                        |\n");
        printf("|    2. Loans Management                       |\n");
        printf("|    3. Files Management                       |\n");
        printf("|    4. Borrower Management                    |\n");
        printf("|    5. Library Statistics                     |\n");
        printf("|    6. Check Overdue                          |\n");
        printf("|    7. Exit System                            |\n");
        printf("================================================\n");
        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1:
                BookMenu(books);
                break;
            case 2:
                LoansMenu(activeloans, pendingloans, returnedloans, borrowers, *books);
                break;
            case 3:
                FilesMenu(books,activeloans,pendingloans,returnedloans,borrowers);
                break;
            case 4:
                BorrowersMenu(borrowers);
                break;
            case 5:
                statisticsMenu(books,borrowers,activeloans,pendingloans,returnedloans);
                break;
            case 6:
                overdue(*activeloans);
                pauseScreen();
                break;
            case 7:
                printf("Exiting system...\n");
                return;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }
    } while (1);
}

void BookMenu(Book **b) {
    int choice;
    do {
        system(CLEAR_SCREEN);
        printf("\n========== BOOK MANAGEMENT ===================\n");
        printf("|    1. List Books                             |\n");
        printf("|    2. Add a Book                             |\n");
        printf("|    3. Search a Book                          |\n");
        printf("|    4. Return to Main Menu                    |\n");
        printf("==============================================\n");
        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1:
                print_books(*b);
                break;
            case 2:
                addBook(b);
                break;
            case 3:
                searchBooksByName(*b);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }
    } while (1);
}

void LoansMenu(Loan **active, Loan **pending, Loan **returned, Borrower **b, Book *bk) {
    int choice;
    do {
        system(CLEAR_SCREEN);
        printf("\n========== LOANS MANAGEMENT ====================\n");
        printf("|    1. List Loans                              |\n");
        printf("|    2. Add a Loan                              |\n");
        printf("|    3. Return a Loan                           |\n");
        printf("|    4. Explanation about the Return System     |\n");
        printf("|    5. Return to Main Menu                     |\n");
        printf("=================================================\n");
        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1:
                print_AllLoans(*active, *pending, *returned);
                break;
            case 2:
                AddLoan(b, active, pending, bk);
                pauseScreen();
                break;
            case 3:
                AddReturn(active, pending, returned, bk);
                pauseScreen();
                break;
            case 4:
                printReturnSystemExplanation();
                pauseScreen();
            break;
            case 5:
                return;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }
    } while (1);
}

void FilesMenu(Book **bk, Loan **active, Loan **pending, Loan **returned, Borrower **b) {
    int choice;
    char filename[256];  // Move filename declaration outside the switch-case

    do {
        system(CLEAR_SCREEN);
        printf("\n========== FILES MANAGEMENT ====================\n");
        printf("|   1. Load Books From File                     |\n");
        printf("|   2. Load Loans Transactions From File        |\n");
        printf("|   3. Return to Main Menu                      |\n");
        printf("===============================================\n");
        
        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1:
                // Ensure to clear the buffer before getting string input
                getStringInput("Enter the file name: ", filename, sizeof(filename));
                loadBooksFromFile(filename, bk);
                break;

            case 2:
                // Ensure to clear the buffer before getting string input
                getStringInput("Enter the file name: ", filename, sizeof(filename));
                loadLibraryData(filename, b, active, pending, returned, *bk);
                pauseScreen();
                break;

            case 3:
                return;

            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }
    } while (1);
}


void statisticsMenu(Book **bk,Borrower **b,Loan **active,Loan **pending,Loan **returned) {
    int choice;
    do {
        system(CLEAR_SCREEN);
        printf("\n========== STATISTICS ========================\n");
        printf("|   1. Display Total Number of Books          |\n");
        printf("|   2. Display Total Number of Borrowers      |\n");
        printf("|   3. Display Total Number of Active Loans   |\n");
        printf("|   4. Display Total Number of Pending Loans  |\n");
        printf("|   5. Display Total Number of Returned Loans |\n");
        printf("|   6. Return to Main Menu                    |\n");
        printf("===============================================\n");
        choice = getIntInput("Enter your choice: ");
        switch (choice)
        {
        case 1:
            printf("Total number of books: %d\n", BooksLenght(*bk));
            pauseScreen();
            break;
        case 2:
            printf("Total number of borrowers: %d\n", BorrowersLenght(*b));
            pauseScreen();
            break;
        case 3:
            printf("Total number of active loans: %d\n", LoansLenght(*active));
            pauseScreen();
            break;
        case 4:
            printf("Total number of pending loans: %d\n", LoansLenght(*pending));
            pauseScreen();
            break;
        case 5:
            printf("Total number of returned loans: %d\n", LoansLenght(*returned));
            pauseScreen();
            break;
        case 6:
            return;
        default:
            printf("Invalid choice. Please choose a valid option.\n");
            break;
        }
    }while(1);
}

void BorrowersMenu(Borrower **b){
    int choice;
    do {
        system(CLEAR_SCREEN);
        printf("\n========== BORROWERS ==========================\n");
        printf("|   1. Add a new borrower                      |\n");
        printf("|   2. List borrowers                          |\n");
        printf("|   3. Return to Main Menu                     |\n");
        printf("===============================================\n");
        choice = getIntInput("Enter your choice: ");
        switch (choice)
        {
            case 1:
                addBorrower(b);
                pauseScreen();
            break;
            case 2:
                print_borrowers(*b);
            break;
            case 3:
                return;
            default:
            printf("Invalid choice. Please choose a valid option.\n");
}
}while (1);
}


void addBook(Book **bookList) {
    int id, copies;
    char title[100], author[100];

    id = getIntInput("Enter Book ID: "); // Get book ID from user
    if (findBookById(*bookList, id) != NULL) {
        printf("Book with ID %d already exists.\n", id);
        pauseScreen();
        return;
    }
    getStringInput("Enter Title: ", title, sizeof(title)); // Get book title from user
    getStringInput("Enter Author: ", author, sizeof(author)); // Get book author from user
    copies = getIntInput("Enter Copies: ");// Get book copies from user

    Book *newBook = insertBook(*bookList, id, title, author, copies);
    *bookList = newBook;
    printf("Book added successfully!\n");// Message of success
    pauseScreen();
}

void addBorrower(Borrower **borrowerList) {
    int id;
    char name[100];

    id = getIntInput("Enter Borrower ID: ");// Get borrower ID from user
    if (findBorrowerById(*borrowerList, id) != NULL) { // Check if borrower already exists
        printf("Borrower with ID %d already exists.\n", id);
        pauseScreen();
        return;
    }
    getStringInput("Enter Name: ", name, sizeof(name)); // Get borrower name from user

    Borrower *newBorrower = insertBorrower(*borrowerList, id, name);
    *borrowerList = newBorrower;
    printf("Borrower added successfully!\n");// Message of success
    pauseScreen();
}


void AddLoan(Borrower **borrowerList, Loan **activeLoanList,
    Loan **pendingLoanList, Book *bookList) {
    
    int book_id, borrower_id, priority;
    Date date, return_date;

    // Get Book ID from user
    printf("\n--- Process Book Borrow ---\n");
    book_id = getIntInput("Enter Book ID: ");

    // Get Borrower ID from user
    borrower_id = getIntInput("Enter Borrower ID: ");

    // Get Borrow Date from user with validation
    printf("Enter Borrow Date (YYYY-MM-DD): ");
    while (scanf("%d-%d-%d", &date.year, &date.month, &date.day) != 3) {
        while (getchar() != '\n');  // Clear input buffer
        printf("Invalid date format. Please enter in YYYY-MM-DD format: ");
    }
    while (getchar() != '\n');  // Clear input buffer after date input

    // Get Priority from user
    priority = getIntInput("Enter Priority: ");

    // Process the borrowing
    Borrower *borrower = findBorrowerById(*borrowerList, borrower_id);
    Book *book = findBookById(bookList, book_id);

    // Check if the borrower or book is invalid
    if (!borrower || !book) {
        printf("\nError: ");
        if (!borrower) printf("Borrower ID %d not found. ", borrower_id);
        if (!book) printf("Book ID %d not found.", book_id);
        printf("\n");
        return;
    }

    // Calculate the return date (14 days later)
    return_date = addDaysToDate(date, 14);

    // Validate loan request
    int validationResult = validateLoanRequest(book, borrower, *activeLoanList);

    // Handle loan approval or pending request based on validation
    if (validationResult == 1) {
        *activeLoanList = insertLoan(*activeLoanList, borrower, book, priority, date, return_date, 0);
        setBookCopies(book, getBookCopies(book) - 1);
        printf("\nSuccessfully borrowed Book ID %d by Borrower ID %d\n", book_id, borrower_id);
        printf("Due Date: %d-%02d-%02d\n", return_date.year, return_date.month, return_date.day);
    } else {
        *pendingLoanList = insertLoan(*pendingLoanList, borrower, book, priority, date, return_date, 0);
        printf("\nAdded to pending requests: Book ID %d, Borrower ID %d\n", book_id, borrower_id);
        printf("Reason: %s\n",
            validationResult == -1 ? "No copies available" :
            (validationResult == -2 ? "Book already borrowed by this borrower" : "Invalid request"));
        printf("Priority: %d\n", priority);
    }
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
        print_header_returned_loans();
        print_ligne();

        Loan *current = returnedLoanList;
        while (current != NULL) {
            print_returned_loan_ligne(current);
            print_ligne();
            current = getLoanNext(current);
        }
    } else {
        printf("\nNo returned loans available.\n");
    }

    pauseScreen();
}


void print_ligne() {
    printf("-------------------------------------------------------------------------------------------------------\n");
}

void print_header_books() {
    printf("| %-8s | %-50s | %-24s | %-8s |\n",
           "Book Id", "Book Name",  "Author", "Copies");
}

void print_book_ligne(Book *b) {
    printf("| %-8d | %-50s | %-24s | %-8d |\n",
           getBookID(b), getBookTitle(b),  getBookAuthor(b), getBookCopies(b));
}

void print_header_borrowers() {
    printf("| %-30s | %-66s |\n",
           "Borrower Id", "Borrower Name");
}

void print_borrower_ligne(Borrower *b) {
    printf("| %-30d | %-66s |\n",
           getBorrowerID(b), getBorrowerName(b));
}

void print_header_loan() {
    printf("| %-20s | %-37s | %-11s | %-11s | %-8s |\n",
           "Borrower Name", "Book Name", "Borrow Date", "Return Date", "Priority");
}

char* formatDate(Date d) {
    static char dateStr[20];
    sprintf(dateStr, "%d/%d/%d", getDateDay(d), getDateMonth(d), getDateYear(d));
    return dateStr;
}

void print_loan_ligne(Loan *l) {
    printf("| %-20s | ", getBorrowerName(getLoanBorrower(l)));
    printf("%-37s | ", getBookTitle(getLoanBook(l)));
    printf("%-11s | ", formatDate(getBorrowDate(l)));
    printf("%-11s | ", formatDate(getReturnDate(l)));
    printf("%-8d |\n", getLoanPriority(l));
}
void print_header_returned_loans() {
    printf("| %-20s | %-37s | %-11s | %-11s | %-8s |\n",
           "Borrower Name", "Book Name", "Borrow Date", "Return Date", "Overdue");
}

void print_returned_loan_ligne(Loan *l) {
    printf("| %-20s | ", getBorrowerName(getLoanBorrower(l)));
    printf("%-37s | ", getBookTitle(getLoanBook(l)));
    printf("%-11s | ", formatDate(getBorrowDate(l)));
    printf("%-11s | ", formatDate(getReturnDate(l)));
    printf("%-8s |\n", getLoanOverdue(l) ? "YES" :"NO" );
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
            // making a lower case copy of the book title to ensure all results are displayed
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

            // looks for search term substring
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
            return;
        }
    } else {
        printf("\nNo books available.\n");
    }
    return;
    pauseScreen();
}

void loadBooksFromFile(const char *filename, Book **bookList) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) { // Opening the file
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    int lineNumber = 0;
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        if (line[0] == '#') { // Skip comments defined with # at the start of the line
            printf("Skipping comment line %d\n", lineNumber);
            continue;
        }

        int id, copies;
        char title[100], author[100];

        if (sscanf(line, "ADD_BOOK %d \"%[^\"]\" \"%[^\"]\" %d", &id, title, author, &copies) == 4) {
            if (findBookById(*bookList, id) == NULL) {
                *bookList = insertBook(*bookList, id, title, author, copies);
                printf("Added book ID %d: %s by %s\n", id, title, author);
            } else if (findBookById(*bookList, id)!= NULL) { // case where book id isnt available
                printf("Book with ID %d already exists.\n", id);
            } else {
                printf("Error parsing line %d: unable to add book\n", line);
            }
        }
    }
    pauseScreen();
    fclose(file);
    return;
}

void processBorrowerData(char *line, Borrower **borrowerList) {
    int id;
    char name[100];

    if (sscanf(line, "ADD_BORROWER %d %s", &id, name) == 2) {
        if (findBorrowerById(*borrowerList, id) == NULL) {// checking if browwer id is available ( multiple names are Ok)
            *borrowerList = insertBorrower(*borrowerList, id, name);
            printf("Added borrower ID %d: %s\n", id, name);
        } else if (findBorrowerById(*borrowerList, id) != NULL) {
            printf("Borrower with ID %d already exists.\n", id);
        } else {
            printf("Error parsing line %s: unable to add borrower\n",line);
    }
}
}

void processBorrowBook(char *line, Borrower **borrowerList, Loan **activeLoanList,
                        Loan **pendingLoanList, Book *bookList) {
    int borrower_id, book_id, priority;
    Date date;
    Date return_date;

    if (sscanf(line, "BORROW_BOOK %d %d %d-%d-%d %d", &book_id, &borrower_id,
                &date.year, &date.month, &date.day, &priority) == 6) {

        Borrower *borrower = findBorrowerById(*borrowerList, borrower_id);
        Book *book = findBookById(bookList, book_id);

        if (!borrower || !book) { // checking for books and borrowers
            printf("Error: Borrower or book not found : %s \n", line);
            return;
        }
        return_date = addDaysToDate(date,14);// calculating return date which is 14 days after the borrow
        int validationResult = validateLoanRequest(book, borrower, *activeLoanList);
        // Check if the loan request is valid (validationResult == 1 means everything is fine)

        if (validationResult == 1) {
            // Add loan to active list and decrement available book copies
            *activeLoanList = insertLoan(*activeLoanList, borrower, book, priority, date, return_date, 0);
            setBookCopies(book, getBookCopies(book) - 1);
            // Inform user of successful loan
            printf("Successfully borrowed Book ID %d by Borrower ID %d\n", book_id, borrower_id);
        } else {
            // If the loan request is invalid, book not available , it goes to pending
            *pendingLoanList = insertLoan(*pendingLoanList, borrower, book, priority, date, return_date, 0);
            // Inform user why the loan was added to pending
            printf("Added to pending requests: Book ID %d, Borrower ID %d\n", book_id, borrower_id);
            printf("Reason: %s\n", 
                validationResult == -1 ? "No copies available" : "Book already borrowed"  );
        }
    }
}

void processReturnBook(char *line, Loan **activeLoanList, Loan **pendingLoanList,
    Loan **returnedLoanList, Book *bookList) {
    int borrower_id, book_id, overdue;
    Date date;

    // Parse the input line for book return details
    if (sscanf(line, "RETURN_BOOK %d %d %d-%d-%d", &book_id, &borrower_id,
                &date.year, &date.month, &date.day) == 5) {
        
        // find if the loan exists in active loans
        Loan *loan = findActiveLoan(*activeLoanList, book_id, borrower_id);
        
        if (loan != NULL) {
            Book *book = findBookById(bookList, book_id);
            
            // for proper removal from the active list
            Loan *prevActive = NULL;
            Loan *current = *activeLoanList;
            while (current != NULL && current != loan) {
                prevActive = current;
                current = getLoanNext(current);
            }

            // Check if the book is overdue
            overdue = (compareDates(date, getReturnDate(loan)) > 0) ? 1 : 0;

            // Move loan to returned loan list
            *returnedLoanList = insertLoan(*returnedLoanList, getLoanBorrower(loan),
                                        getLoanBook(loan), getLoanPriority(loan),
                                        getBorrowDate(loan), date, overdue);
            printf("Returned book ID %d by borrower ID %d\n", book_id, borrower_id);

            // Remove loan from active loan list
            if (prevActive) {
                setLoanNext(prevActive, getLoanNext(loan));
            } else {
                *activeLoanList = getLoanNext(loan);
            }

            // Process the highest priority pending loan for this book
            Loan *pendingLoan = *pendingLoanList;
            Loan *prevPending = NULL;
            Loan *highestPriorityLoan = NULL;
            Loan *highestPrevPending = NULL;
            int highestPriority = -1;

            // Find the highest priority pending loan for this book
            while (pendingLoan != NULL) {
                if (getBookID(getLoanBook(pendingLoan)) == book_id &&
                    getLoanPriority(pendingLoan) > highestPriority) {
                    highestPriority = getLoanPriority(pendingLoan);
                    highestPriorityLoan = pendingLoan;
                    highestPrevPending = prevPending;
                }
                prevPending = pendingLoan;
                pendingLoan = getLoanNext(pendingLoan);
            }

            if (highestPriorityLoan != NULL) {
                // Remove from pending list
                if (highestPrevPending != NULL) {
                    setLoanNext(highestPrevPending, getLoanNext(highestPriorityLoan));
                } else {
                    *pendingLoanList = getLoanNext(highestPriorityLoan);
                }

                // Set dates for the new active loan
                setBorrowDate(highestPriorityLoan, date);
                Date return_date = addDaysToDate(date, 14);
                setReturnDate(highestPriorityLoan, return_date);

                // Add to active list 
                setLoanNext(highestPriorityLoan, *activeLoanList);
                *activeLoanList = highestPriorityLoan;

                printf("Book loaned to next pending borrower (Priority: %d)!\n", 
                    getLoanPriority(highestPriorityLoan));
            } else {
                // No pending loans, increase book copies
                if (book != NULL) {
                    setBookCopies(book, getBookCopies(book) + 1);
                    printf("Book returned, copies increased to %d!\n", getBookCopies(book));
                }
            }

            // Free the original loan node 
            free(loan);
            return;
        }
    }
    
    // If the loan was not found or the input is invalid, print an error
    printf("Error: The loan was not found or invalid input: %s\n", line);
}


void loadLibraryData(const char *filename, Borrower **borrowerList, Loan **activeLoanList,
    Loan **pendingLoanList, Loan **returnedLoanList, Book *bookList) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#') {
        continue;
        }

        strtok(line, "\n");

        // if the command is "add_borrower" execute the proceesBrowwerData function
        if (strstr(line, "ADD_BORROWER")) {
            processBorrowerData(line, borrowerList);
        }
        // if the command is "add_loan" execute the processBorrowBook function
        else if (strstr(line, "BORROW_BOOK")) {
            processBorrowBook(line, borrowerList, activeLoanList, pendingLoanList, bookList);
        }
        // if the command is "return_book" execute the processReturnBook function
        else if (strstr(line, "RETURN_BOOK")) {
            processReturnBook(line, activeLoanList, pendingLoanList, returnedLoanList, bookList);
        }
        }

fclose(file);
}


void AddReturn(Loan **activeLoanList, Loan **pendingLoanList,
    Loan **returnedLoanList, Book *bookList) {
    int borrower_id, book_id, overdue;
    Date date;

    // Get Book ID from user input
    book_id = getIntInput("Enter Book ID: ");

    // Get Borrower ID from user input
    borrower_id = getIntInput("Enter Borrower ID: ");

    // Get Return Date in YYYY-MM-DD format
    printf("Enter Return Date (YYYY-MM-DD): ");
    while (scanf("%d-%d-%d", &date.year, &date.month, &date.day) != 3 ) {
        while (getchar() != '\n'); // Clear invalid input
        printf("Invalid date format or invalid date. Please enter in YYYY-MM-DD format: ");
    }
    while (getchar() != '\n'); // Clear input buffer after date input

    // Search for the loan in the active loan list
    Loan *loan = *activeLoanList;
    Loan *prev = NULL;
    Book *book = findBookById(bookList, book_id);

    // Find the loan in the active list
    while (loan != NULL) {
        if (getBookID(getLoanBook(loan)) == book_id &&
            getBorrowerID(getLoanBorrower(loan)) == borrower_id) {
            break;
        }
        prev = loan;
        loan = getLoanNext(loan);
    }

    if (loan != NULL) {
        // Check if the book is overdue
        overdue = (compareDates(date, getReturnDate(loan)) > 0) ? 1 : 0;

        // Move the loan to the returned loan list
        *returnedLoanList = insertLoan(*returnedLoanList, getLoanBorrower(loan),
            getLoanBook(loan), getLoanPriority(loan),
            getBorrowDate(loan), date, overdue);

        printf("\nReturned book ID %d by borrower ID %d\n", book_id, borrower_id);

        // Remove the loan from the active loan list
        if (prev) {
            setLoanNext(prev, getLoanNext(loan));
        } else {
            *activeLoanList = getLoanNext(loan);
        }

        // Now, try to find and process the highest priority pending loan for the same book
        Loan *pendingLoan = *pendingLoanList;
        Loan *prevPending = NULL;
        Loan *highestPriorityLoan = NULL;
        Loan *highestPrevPending = NULL;
        int highestPriority = -1;

        while (pendingLoan != NULL) {
            if (getBookID(getLoanBook(pendingLoan)) == book_id &&
                getLoanPriority(pendingLoan) > highestPriority) {
                highestPriority = getLoanPriority(pendingLoan);
                highestPriorityLoan = pendingLoan;
                highestPrevPending = prevPending;
            }
            prevPending = pendingLoan;
            pendingLoan = getLoanNext(pendingLoan);
        }

        // If there's a pending loan with a higher priority, process it
        if (highestPriorityLoan != NULL) {
            // Remove from pending list
            if (highestPrevPending != NULL) {
                setLoanNext(highestPrevPending, getLoanNext(highestPriorityLoan));
            } else {
                *pendingLoanList = getLoanNext(highestPriorityLoan);
            }

            // Set dates for the new active loan
            setBorrowDate(highestPriorityLoan, date);
            Date return_date = addDaysToDate(date, 14);
            setReturnDate(highestPriorityLoan, return_date);

            // Add to active list (without creating a new node)
            setLoanNext(highestPriorityLoan, *activeLoanList);
            *activeLoanList = highestPriorityLoan;

            printf("Book loaned to next pending borrower (Priority: %d)!\n",
                getLoanPriority(highestPriorityLoan));
        } else {
            // No pending loans, increment book copies
            if (book != NULL) {
                setBookCopies(book, getBookCopies(book) + 1);
                printf("Book returned, copies increased to %d!\n", getBookCopies(book));
            }
        }

        // Free the original loan node (only if we didn't reuse the pending loan)
        if (highestPriorityLoan != loan) {
            free(loan);
        }
        return;
    }

    // If no active loan was found for the specified book and borrower
    printf("\nError: No active loan found for Book ID %d and Borrower ID %d\n", book_id, borrower_id);
}

void Herosec(){
    system("cls");
    printf("\t\t\t\t%ccole nationale sup%crieur d'informatique \n",130,130);
    printf("\t\t\t  .----------------.  .----------------.  .----------------.\n");
    printf("\t\t\t | .--------------. || .--------------. || .--------------. |\n");
    printf("\t\t\t | |  _________   | || |    _______   | || |     _____    | |\n");
    printf("\t\t\t | | |_   ___  |  | || |   /  ___  |  | || |    |_   _|   | |\n");
    printf("\t\t\t | |   | |_  \\_|  | || |  |  (__ \\_|  | || |      | |     | |\n");
    printf("\t\t\t | |   |  _|  _   | || |   \'.___`-.   | || |      | |     | |\n");
    printf("\t\t\t | |  _| |___/ |  | || |  |`\\____) |  | || |     _| |_    | |\n");
    printf("\t\t\t | | |_________|  | || |  |_______.\'  | || |    |_____|   | |\n");
    printf("\t\t\t | |              | || |              | || |              | |\n");
    printf("\t\t\t | \'--------------\' || \'--------------\' || \'--------------\' |\n");
    printf("\t\t\t  \'----------------\'  \'----------------\'  \'----------------\'\n");
    Sleep(1000);
    printf("\t\t\t\tCPI - 1%cre Ann%ce - Ann%ce Universitaire 2024/2025 \n", 138, 130, 130);
    printf("\t\t\t ____________________________________________________________\n");
    printf("\t\t\t|                                                            |\n");
    printf("\t\t\t| Designed & Coded By : Lekhchine Islem Bahaa Eddine         |\n");
    printf("\t\t\t|                                  &                         |\n");
    printf("\t\t\t|                             Machane Mohamed Iyad           |\n");
    printf("\t\t\t|                                                            |\n");
    printf("\t\t\t|                                                            |\n");
    printf("\t\t\t|         \tSECTION : A           GROUPE: 01             |\n");
    printf("\t\t\t|                      \t  TP1 ALSDD                          |\n");
    printf("\t\t\t|      \t Library Management System (LMS)                     |\n");
    printf("\t\t\t|                                                            |\n");
    printf("\t\t\t|                                                            |\n");
    printf("\t\t\t| Supervised by: Ms. Artabaz Saliha                          |\n");
    printf("\t\t\t|____________________________________________________________|\n\n\n");
    printf("\t\t\t _____________________________________________________________\n");
    printf("\t\t\t| Note!! Press the 'ENTER' key to access the Menu             |\n");
    printf("\t\t\t|_____________________________________________________________|\n");
}

void printReturnSystemExplanation() {
    printf("\n=== BOOK RETURN SYSTEM EXPLANATION ===\n");
    printf("1. RETURN PROCESS:\n");
    printf("   - The default borrow period is 14 days , which is setted by the system when borrowing a book\n");
    printf("   - Enter Book ID and Borrower ID\n");
    printf("   - Enter the return date (YYYY-MM-DD)\n");
    printf("   - System verifies the active loan exists\n");
    printf("   - Records the return and checks for overdue status\n\n");
    
    printf("2. AFTER RETURN:\n");
    printf("   a) If pending requests exist:\n");
    printf("      * Processes highest priority request automatically\n");
    printf("      * The borrow date of the pending request is set to the return date of the returned book\n");
    printf("      * New loan starts immediately (14-day due date)\n");
    printf("      * Book stays checked out\n\n");
    
    printf("   b) If no pending requests:\n");
    printf("      * Available copies increase by 1\n");
    printf("      * Book becomes available for new loans\n\n");
    
    printf("3. OVERDUE MANAGEMENT:\n");
    printf("   - Overdue status is determined at return time\n");
    printf("   - All active loans can be checked for overdue status\n");
    printf("     from the main menu option:\n");
    printf("     * 'Check Overdue Loans'\n");
    printf("     * Shows all loans past their due date\n");
    printf("     * Updated daily based on system date\n\n");
    
    printf("4. RECORD KEEPING:\n");
    printf("   - Returned books move to loan history\n");
    printf("   - Overdue returns remain in system records\n");
    printf("===============================\n\n");
}
