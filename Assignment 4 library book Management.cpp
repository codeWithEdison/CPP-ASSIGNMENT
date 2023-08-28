#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Book {
public:
    // Properties of the Book class
    Book(const std::string& isbn, const std::string& title, const std::string& author, int copyrightDate, const std::string& genre)
        : isbn(isbn), title(title), author(author), copyrightDate(copyrightDate), checkedOut(false), genre(genre) {}

    // Getter methods
    const std::string& getISBN() const { return isbn; }
    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }
    const std::string& getGenre() const { return genre; }
    bool isCheckedOut() const { return checkedOut; }

    // Check out and check in methods
    void checkOut() const { checkedOut = true; }
    void checkIn() const { checkedOut = false; }

    // Comparison operators for Book objects
    bool operator==(const Book& other) const { return isbn == other.isbn; }
    bool operator!=(const Book& other) const { return !(*this == other); }

    // Friend function to display Book details
    friend std::ostream& operator<<(std::ostream& os, const Book& book);

private:
    std::string isbn;
    std::string title;
    std::string author;
    int copyrightDate;
    mutable bool checkedOut; // 'mutable' to allow modification in const methods
    std::string genre;
};

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title: " << book.title << "\nAuthor: " << book.author << "\nISBN: " << book.isbn << "\nGenre: " << book.genre;
    return os;
}

class Patron {
public:
    // Properties of the Patron class
    Patron(const std::string& userName, const std::string& cardNumber) : userName(userName), cardNumber(cardNumber), owedFees(0) {}

    // Getter methods
    const std::string& getUserName() const { return userName; }
    const std::string& getCardNumber() const { return cardNumber; }
    int getOwedFees() const { return owedFees; }

    // Method to check if patron owes fees
    bool owesFees() const { return owedFees > 0; }

    // Method to set owed fees
    void setFees(int fees) { owedFees = fees; }

    // Comparison operators for Patron objects
    bool operator==(const Patron& other) const { return cardNumber == other.cardNumber; }
    bool operator!=(const Patron& other) const { return !(*this == other); }

private:
    std::string userName;
    std::string cardNumber;
    int owedFees;
};

class Transaction {
public:
    // Properties of the Transaction class
    Transaction(const Book& book, const Patron& patron, const std::string& activity) : book(book), patron(patron), activity(activity) {}

private:
    Book book;
    Patron patron;
    std::string activity;
};

class Library {
public:
    // Methods for adding books and patrons
    void addBook(const Book& book) { books.push_back(book); }
    void addPatron(const Patron& patron) { patrons.push_back(patron); }

    // Method to check out a book
    void checkOutBook(const Book& book, const Patron& patron);

    // Method to get names of patrons owing fees
    std::vector<std::string> getOwingPatronNames() const;

private:
    std::vector<Book> books;
    std::vector<Patron> patrons;
    std::vector<Transaction> transactions;
};

void Library::checkOutBook(const Book& book, const Patron& patron) {
    auto bookIter = std::find(books.begin(), books.end(), book);
    auto patronIter = std::find(patrons.begin(), patrons.end(), patron);

    // Check if the book and patron exist in the library
    if (bookIter == books.end() || patronIter == patrons.end()) {
        std::cout << "Error: Book or patron not found in the library." << std::endl;
        return;
    }

    // Check if the patron owes fees
    if (patron.owesFees()) {
        std::cout << "Error: Patron owes fees and cannot check out the book." << std::endl;
        return;
    }

    // Check out the book and record the transaction
    book.checkOut();
    transactions.push_back(Transaction(book, patron, "Check Out"));
}

std::vector<std::string> Library::getOwingPatronNames() const {
    std::vector<std::string> owingPatronNames;
    for (const auto& patron : patrons) {
        if (patron.owesFees()) {
            owingPatronNames.push_back(patron.getUserName());
        }
    }
    return owingPatronNames;
}

int main() {
    Library library;

    Book book1("123456789", "Sample Book 1", "Author 1", 2023, "Fiction");
    Book book2("987654321", "Sample Book 2", "Author 2", 2022, "Nonfiction");
    Patron patron1("User 1", "111");
    Patron patron2("User 2", "222");

    // Adding books and patrons to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addPatron(patron1);
    library.addPatron(patron2);

    // Checking out books
    library.checkOutBook(book1, patron1);
    library.checkOutBook(book2, patron2);

    // Getting names of patrons owing fees
    std::vector<std::string> owingPatronNames = library.getOwingPatronNames();
    if (owingPatronNames.empty()) {
        std::cout << "No patrons owe fees." << std::endl;
    } else {
        std::cout << "Patrons owing fees: ";
        for (const std::string& name : owingPatronNames) {
            std::cout << name << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
