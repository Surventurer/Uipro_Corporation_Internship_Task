#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

// Base Person class
class Person {
protected:
    string name;
    int id;
    string contact;

public:
    Person() : id(0) {}
    Person(int id, string name, string contact) : id(id), name(name), contact(contact) {}
    
    virtual ~Person() {}
    
    int getId() const { return id; }
    string getName() const { return name; }
    string getContact() const { return contact; }
    
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setContact(string contact) { this->contact = contact; }
};

// Student class inheriting from Person
class Student : public Person {
private:
    string course;
    string enrollmentDate;

public:
    Student() {}
    Student(int id, string name, string contact, string course, string enrollmentDate) 
        : Person(id, name, contact), course(course), enrollmentDate(enrollmentDate) {}
    
    string getCourse() const { return course; }
    string getEnrollmentDate() const { return enrollmentDate; }
    
    void setCourse(string course) { this->course = course; }
    void setEnrollmentDate(string date) { this->enrollmentDate = date; }
    
    string toString() const {
        return to_string(id) + "|" + name + "|" + contact + "|" + course + "|" + enrollmentDate;
    }
    
    void fromString(const string& data) {
        stringstream ss(data);
        string item;
        
        if (getline(ss, item, '|')) id = stoi(item);
        if (getline(ss, item, '|')) name = item;
        if (getline(ss, item, '|')) contact = item;
        if (getline(ss, item, '|')) course = item;
        if (getline(ss, item, '|')) enrollmentDate = item;
    }
};

// Book class
class Book {
private:
    int bookId;
    string title;
    string author;
    string isbn;
    bool isIssued;
    int issuedToStudentId;

public:
    Book() : bookId(0), isIssued(false), issuedToStudentId(0) {}
    Book(int id, string title, string author, string isbn) 
        : bookId(id), title(title), author(author), isbn(isbn), isIssued(false), issuedToStudentId(0) {}
    
    // Getters
    int getBookId() const { return bookId; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getIsbn() const { return isbn; }
    bool getIsIssued() const { return isIssued; }
    int getIssuedToStudentId() const { return issuedToStudentId; }
    
    // Setters
    void setBookId(int id) { this->bookId = id; }
    void setTitle(string title) { this->title = title; }
    void setAuthor(string author) { this->author = author; }
    void setIsbn(string isbn) { this->isbn = isbn; }
    void setIsIssued(bool issued) { this->isIssued = issued; }
    void setIssuedToStudentId(int studentId) { this->issuedToStudentId = studentId; }
    
    string toString() const {
        return to_string(bookId) + "|" + title + "|" + author + "|" + isbn + "|" + 
               (isIssued ? "1" : "0") + "|" + to_string(issuedToStudentId);
    }
    
    void fromString(const string& data) {
        stringstream ss(data);
        string item;
        
        if (getline(ss, item, '|')) bookId = stoi(item);
        if (getline(ss, item, '|')) title = item;
        if (getline(ss, item, '|')) author = item;
        if (getline(ss, item, '|')) isbn = item;
        if (getline(ss, item, '|')) isIssued = (item == "1");
        if (getline(ss, item, '|')) issuedToStudentId = stoi(item);
    }
};

// Transaction class
class Transaction {
private:
    int transactionId;
    int bookId;
    int studentId;
    string issueDate;
    string dueDate;
    string returnDate;
    double lateFee;

public:
    Transaction() : transactionId(0), bookId(0), studentId(0), lateFee(0.0) {}
    Transaction(int tId, int bId, int sId, string iDate, string dDate) 
        : transactionId(tId), bookId(bId), studentId(sId), issueDate(iDate), 
          dueDate(dDate), returnDate(""), lateFee(0.0) {}
    
    // Getters
    int getTransactionId() const { return transactionId; }
    int getBookId() const { return bookId; }
    int getStudentId() const { return studentId; }
    string getIssueDate() const { return issueDate; }
    string getDueDate() const { return dueDate; }
    string getReturnDate() const { return returnDate; }
    double getLateFee() const { return lateFee; }
    
    // Setters
    void setTransactionId(int id) { this->transactionId = id; }
    void setReturnDate(string date) { this->returnDate = date; }
    void setLateFee(double fee) { this->lateFee = fee; }
    
    string toString() const {
        return to_string(transactionId) + "|" + to_string(bookId) + "|" + to_string(studentId) + "|" + 
               issueDate + "|" + dueDate + "|" + returnDate + "|" + to_string(lateFee);
    }
    
    void fromString(const string& data) {
        stringstream ss(data);
        string item;
        
        if (getline(ss, item, '|')) transactionId = stoi(item);
        if (getline(ss, item, '|')) bookId = stoi(item);
        if (getline(ss, item, '|')) studentId = stoi(item);
        if (getline(ss, item, '|')) issueDate = item;
        if (getline(ss, item, '|')) dueDate = item;
        if (getline(ss, item, '|')) returnDate = item;
        if (getline(ss, item, '|')) lateFee = stod(item);
    }
};

// Admin Library Management System class
class LibraryManagementSystem {
private:
    vector<Book> books;
    vector<Student> students;
    vector<Transaction> transactions;
    const string BOOKS_FILE = "books.dat";
    const string STUDENTS_FILE = "students.dat";
    const string TRANSACTIONS_FILE = "transactions.dat";
    const string ADMIN_PASSWORD = "admin123";

    // File handling methods
    void loadBooksFromFile() {
        ifstream file(BOOKS_FILE);
        if (!file.is_open()) return;
        
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                Book book;
                book.fromString(line);
                books.push_back(book);
            }
        }
        file.close();
    }
    
    void saveBooksToFile() {
        ofstream file(BOOKS_FILE);
        for (const auto& book : books) {
            file << book.toString() << endl;
        }
        file.close();
    }
    
    void loadStudentsFromFile() {
        ifstream file(STUDENTS_FILE);
        if (!file.is_open()) return;
        
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                Student student;
                student.fromString(line);
                students.push_back(student);
            }
        }
        file.close();
    }
    
    void saveStudentsToFile() {
        ofstream file(STUDENTS_FILE);
        for (const auto& student : students) {
            file << student.toString() << endl;
        }
        file.close();
    }
    
    void loadTransactionsFromFile() {
        ifstream file(TRANSACTIONS_FILE);
        if (!file.is_open()) return;
        
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                Transaction transaction;
                transaction.fromString(line);
                transactions.push_back(transaction);
            }
        }
        file.close();
    }
    
    void saveTransactionsToFile() {
        ofstream file(TRANSACTIONS_FILE);
        for (const auto& transaction : transactions) {
            file << transaction.toString() << endl;
        }
        file.close();
    }
    
    // Utility methods
    string getCurrentDate() {
        time_t now = time(0);
        char* dt = ctime(&now);
        string date = dt;
        date.pop_back(); // Remove newline
        return date;
    }
    
    string getDueDate() {
        time_t now = time(0);
        now += 14 * 24 * 60 * 60; // Add 14 days
        char* dt = ctime(&now);
        string date = dt;
        date.pop_back(); // Remove newline
        return date;
    }
    
    int getNextBookId() {
        int maxId = 0;
        for (const auto& book : books) {
            if (book.getBookId() > maxId) {
                maxId = book.getBookId();
            }
        }
        return maxId + 1;
    }
    
    int getNextStudentId() {
        int maxId = 0;
        for (const auto& student : students) {
            if (student.getId() > maxId) {
                maxId = student.getId();
            }
        }
        return maxId + 1;
    }
    
    int getNextTransactionId() {
        int maxId = 0;
        for (const auto& transaction : transactions) {
            if (transaction.getTransactionId() > maxId) {
                maxId = transaction.getTransactionId();
            }
        }
        return maxId + 1;
    }

public:
    LibraryManagementSystem() {
        loadBooksFromFile();
        loadStudentsFromFile();
        loadTransactionsFromFile();
    }
    
    ~LibraryManagementSystem() {
        saveBooksToFile();
        saveStudentsToFile();
        saveTransactionsToFile();
    }
    
    bool adminLogin() {
        string password;
        cout << "\n=== ADMIN LOGIN ===" << endl;
        cout << "Enter admin password: ";
        cin >> password;
        
        if (password == ADMIN_PASSWORD) {
            cout << "Login successful!" << endl;
            return true;
        } else {
            cout << "Invalid password!" << endl;
            return false;
        }
    }
    
    // Book Management Methods
    void addBook() {
        string title, author, isbn;
        
        cout << "\n=== ADD NEW BOOK ===" << endl;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);
        cout << "Enter ISBN: ";
        getline(cin, isbn);
        
        Book newBook(getNextBookId(), title, author, isbn);
        books.push_back(newBook);
        saveBooksToFile();
        
        cout << "Book added successfully with ID: " << newBook.getBookId() << endl;
    }
    
    void displayAllBooks() {
        cout << "\n=== ALL BOOKS ===" << endl;
        cout << setw(5) << "ID" << setw(25) << "Title" << setw(20) << "Author" 
             << setw(15) << "ISBN" << setw(10) << "Status" << endl;
        cout << string(75, '-') << endl;
        
        for (const auto& book : books) {
            cout << setw(5) << book.getBookId() 
                 << setw(25) << book.getTitle().substr(0, 24)
                 << setw(20) << book.getAuthor().substr(0, 19)
                 << setw(15) << book.getIsbn()
                 << setw(10) << (book.getIsIssued() ? "Issued" : "Available") << endl;
        }
    }
    
    void searchBook() {
        int choice;
        cout << "\n=== SEARCH BOOK ===" << endl;
        cout << "1. Search by ID" << endl;
        cout << "2. Search by Title" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            int id;
            cout << "Enter book ID: ";
            cin >> id;
            
            auto it = find_if(books.begin(), books.end(), 
                [id](const Book& b) { return b.getBookId() == id; });
            
            if (it != books.end()) {
                cout << "\nBook found:" << endl;
                cout << "ID: " << it->getBookId() << endl;
                cout << "Title: " << it->getTitle() << endl;
                cout << "Author: " << it->getAuthor() << endl;
                cout << "ISBN: " << it->getIsbn() << endl;
                cout << "Status: " << (it->getIsIssued() ? "Issued" : "Available") << endl;
            } else {
                cout << "Book not found!" << endl;
            }
        } else if (choice == 2) {
            string title;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            
            cout << "\nSearch results:" << endl;
            bool found = false;
            for (const auto& book : books) {
                if (book.getTitle().find(title) != string::npos) {
                    cout << "ID: " << book.getBookId() << ", Title: " << book.getTitle() 
                         << ", Author: " << book.getAuthor() << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No books found with that title!" << endl;
            }
        }
    }
    
    void deleteBook() {
        int id;
        cout << "\n=== DELETE BOOK ===" << endl;
        cout << "Enter book ID to delete: ";
        cin >> id;
        
        auto it = find_if(books.begin(), books.end(), 
            [id](const Book& b) { return b.getBookId() == id; });
        
        if (it != books.end()) {
            if (it->getIsIssued()) {
                cout << "Cannot delete book. It is currently issued!" << endl;
            } else {
                cout << "Book '" << it->getTitle() << "' deleted successfully!" << endl;
                books.erase(it);
                saveBooksToFile();
            }
        } else {
            cout << "Book not found!" << endl;
        }
    }
    
    // Student Management Methods
    void registerStudent() {
        string name, contact, course;
        
        cout << "\n=== REGISTER STUDENT ===" << endl;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter contact number: ";
        getline(cin, contact);
        cout << "Enter course: ";
        getline(cin, course);
        
        Student newStudent(getNextStudentId(), name, contact, course, getCurrentDate());
        students.push_back(newStudent);
        saveStudentsToFile();
        
        cout << "Student registered successfully with ID: " << newStudent.getId() << endl;
    }
    
    void displayStudentList() {
        cout << "\n=== STUDENT LIST ===" << endl;
        cout << setw(5) << "ID" << setw(20) << "Name" << setw(15) << "Contact" 
             << setw(15) << "Course" << setw(20) << "Enrollment Date" << endl;
        cout << string(75, '-') << endl;
        
        for (const auto& student : students) {
            cout << setw(5) << student.getId() 
                 << setw(20) << student.getName().substr(0, 19)
                 << setw(15) << student.getContact()
                 << setw(15) << student.getCourse().substr(0, 14)
                 << setw(20) << student.getEnrollmentDate().substr(0, 19) << endl;
        }
    }
    
    void searchStudent() {
        int id;
        cout << "\n=== SEARCH STUDENT ===" << endl;
        cout << "Enter student ID: ";
        cin >> id;
        
        auto it = find_if(students.begin(), students.end(), 
            [id](const Student& s) { return s.getId() == id; });
        
        if (it != students.end()) {
            cout << "\nStudent found:" << endl;
            cout << "ID: " << it->getId() << endl;
            cout << "Name: " << it->getName() << endl;
            cout << "Contact: " << it->getContact() << endl;
            cout << "Course: " << it->getCourse() << endl;
            cout << "Enrollment Date: " << it->getEnrollmentDate() << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }
    
    void deleteStudent() {
        int id;
        cout << "\n=== DELETE STUDENT ===" << endl;
        cout << "Enter student ID to delete: ";
        cin >> id;
        
        // Check if student has any issued books
        bool hasIssuedBooks = any_of(transactions.begin(), transactions.end(),
            [id](const Transaction& t) { 
                return t.getStudentId() == id && t.getReturnDate().empty(); 
            });
        
        if (hasIssuedBooks) {
            cout << "Cannot delete student. Student has issued books!" << endl;
            return;
        }
        
        auto it = find_if(students.begin(), students.end(), 
            [id](const Student& s) { return s.getId() == id; });
        
        if (it != students.end()) {
            cout << "Student '" << it->getName() << "' deleted successfully!" << endl;
            students.erase(it);
            saveStudentsToFile();
        } else {
            cout << "Student not found!" << endl;
        }
    }
    
    // Issue/Return Methods
    void issueBook() {
        int bookId, studentId;
        
        cout << "\n=== ISSUE BOOK ===" << endl;
        cout << "Enter book ID: ";
        cin >> bookId;
        cout << "Enter student ID: ";
        cin >> studentId;
        
        // Find book
        auto bookIt = find_if(books.begin(), books.end(), 
            [bookId](const Book& b) { return b.getBookId() == bookId; });
        
        if (bookIt == books.end()) {
            cout << "Book not found!" << endl;
            return;
        }
        
        if (bookIt->getIsIssued()) {
            cout << "Book is already issued!" << endl;
            return;
        }
        
        // Find student
        auto studentIt = find_if(students.begin(), students.end(), 
            [studentId](const Student& s) { return s.getId() == studentId; });
        
        if (studentIt == students.end()) {
            cout << "Student not found!" << endl;
            return;
        }
        
        // Issue book
        bookIt->setIsIssued(true);
        bookIt->setIssuedToStudentId(studentId);
        
        Transaction transaction(getNextTransactionId(), bookId, studentId, 
                              getCurrentDate(), getDueDate());
        transactions.push_back(transaction);
        
        saveBooksToFile();
        saveTransactionsToFile();
        
        cout << "Book '" << bookIt->getTitle() << "' issued to " 
             << studentIt->getName() << " successfully!" << endl;
        cout << "Due date: " << transaction.getDueDate() << endl;
    }
    
    void returnBook() {
        int bookId;
        
        cout << "\n=== RETURN BOOK ===" << endl;
        cout << "Enter book ID: ";
        cin >> bookId;
        
        // Find book
        auto bookIt = find_if(books.begin(), books.end(), 
            [bookId](const Book& b) { return b.getBookId() == bookId; });
        
        if (bookIt == books.end()) {
            cout << "Book not found!" << endl;
            return;
        }
        
        if (!bookIt->getIsIssued()) {
            cout << "Book is not issued!" << endl;
            return;
        }
        
        // Find transaction
        auto transIt = find_if(transactions.begin(), transactions.end(),
            [bookId](const Transaction& t) { 
                return t.getBookId() == bookId && t.getReturnDate().empty(); 
            });
        
        if (transIt != transactions.end()) {
            transIt->setReturnDate(getCurrentDate());
            
            // Calculate late fee (simplified - $1 per day late)
            // In real implementation, you'd properly calculate date difference
            cout << "Book returned successfully!" << endl;
            cout << "Return date: " << transIt->getReturnDate() << endl;
        }
        
        bookIt->setIsIssued(false);
        bookIt->setIssuedToStudentId(0);
        
        saveBooksToFile();
        saveTransactionsToFile();
    }
    
    void displayIssuedBooks() {
        cout << "\n=== ISSUED BOOKS ===" << endl;
        cout << setw(8) << "Book ID" << setw(25) << "Title" << setw(12) << "Student ID" 
             << setw(20) << "Student Name" << setw(15) << "Issue Date" << endl;
        cout << string(80, '-') << endl;
        
        for (const auto& transaction : transactions) {
            if (transaction.getReturnDate().empty()) {
                auto bookIt = find_if(books.begin(), books.end(),
                    [&transaction](const Book& b) { 
                        return b.getBookId() == transaction.getBookId(); 
                    });
                
                auto studentIt = find_if(students.begin(), students.end(),
                    [&transaction](const Student& s) { 
                        return s.getId() == transaction.getStudentId(); 
                    });
                
                if (bookIt != books.end() && studentIt != students.end()) {
                    cout << setw(8) << transaction.getBookId()
                         << setw(25) << bookIt->getTitle().substr(0, 24)
                         << setw(12) << transaction.getStudentId()
                         << setw(20) << studentIt->getName().substr(0, 19)
                         << setw(15) << transaction.getIssueDate().substr(0, 14) << endl;
                }
            }
        }
    }
    
    void showMainMenu() {
        cout << "\n====== LIBRARY MANAGEMENT SYSTEM ======" << endl;
        cout << "1. Book Management" << endl;
        cout << "2. Student Management" << endl;
        cout << "3. Issue/Return Management" << endl;
        cout << "4. Reports" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
    }
    
    void showBookMenu() {
        cout << "\n=== BOOK MANAGEMENT ===" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Delete Book" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
    }
    
    void showStudentMenu() {
        cout << "\n=== STUDENT MANAGEMENT ===" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. Display Student List" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
    }
    
    void showIssueReturnMenu() {
        cout << "\n=== ISSUE/RETURN MANAGEMENT ===" << endl;
        cout << "1. Issue Book" << endl;
        cout << "2. Return Book" << endl;
        cout << "3. Display Issued Books" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
    }
    
    void showReportsMenu() {
        cout << "\n=== REPORTS ===" << endl;
        cout << "1. All Books Report" << endl;
        cout << "2. All Students Report" << endl;
        cout << "3. Issued Books Report" << endl;
        cout << "4. Transaction History" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
    }
    
    void showTransactionHistory() {
        cout << "\n=== TRANSACTION HISTORY ===" << endl;
        cout << setw(5) << "T.ID" << setw(8) << "Book ID" << setw(8) << "Std ID" 
             << setw(15) << "Issue Date" << setw(15) << "Return Date" << setw(10) << "Status" << endl;
        cout << string(70, '-') << endl;
        
        for (const auto& transaction : transactions) {
            cout << setw(5) << transaction.getTransactionId()
                 << setw(8) << transaction.getBookId()
                 << setw(8) << transaction.getStudentId()
                 << setw(15) << transaction.getIssueDate().substr(0, 14)
                 << setw(15) << (transaction.getReturnDate().empty() ? "Not Returned" : 
                                 transaction.getReturnDate().substr(0, 14))
                 << setw(10) << (transaction.getReturnDate().empty() ? "Active" : "Closed") << endl;
        }
    }
    
    void run() {
        if (!adminLogin()) {
            return;
        }
        
        int choice;
        while (true) {
            showMainMenu();
            cin >> choice;
            
            switch (choice) {
                case 1: {
                    int bookChoice;
                    while (true) {
                        showBookMenu();
                        cin >> bookChoice;
                        
                        switch (bookChoice) {
                            case 1: addBook(); break;
                            case 2: displayAllBooks(); break;
                            case 3: searchBook(); break;
                            case 4: deleteBook(); break;
                            case 5: goto mainMenu;
                            default: cout << "Invalid choice!" << endl;
                        }
                    }
                    break;
                }
                case 2: {
                    int studentChoice;
                    while (true) {
                        showStudentMenu();
                        cin >> studentChoice;
                        
                        switch (studentChoice) {
                            case 1: registerStudent(); break;
                            case 2: displayStudentList(); break;
                            case 3: searchStudent(); break;
                            case 4: deleteStudent(); break;
                            case 5: goto mainMenu;
                            default: cout << "Invalid choice!" << endl;
                        }
                    }
                    break;
                }
                case 3: {
                    int issueChoice;
                    while (true) {
                        showIssueReturnMenu();
                        cin >> issueChoice;
                        
                        switch (issueChoice) {
                            case 1: issueBook(); break;
                            case 2: returnBook(); break;
                            case 3: displayIssuedBooks(); break;
                            case 4: goto mainMenu;
                            default: cout << "Invalid choice!" << endl;
                        }
                    }
                    break;
                }
                case 4: {
                    int reportChoice;
                    while (true) {
                        showReportsMenu();
                        cin >> reportChoice;
                        
                        switch (reportChoice) {
                            case 1: displayAllBooks(); break;
                            case 2: displayStudentList(); break;
                            case 3: displayIssuedBooks(); break;
                            case 4: showTransactionHistory(); break;
                            case 5: goto mainMenu;
                            default: cout << "Invalid choice!" << endl;
                        }
                    }
                    break;
                }
                case 5:
                    cout << "Thank you for using Library Management System!" << endl;
                    return;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
            mainMenu:;
        }
    }
};

int main() {
    cout << "Welcome to Library Management System" << endl;
    cout << "=====================================" << endl;
    
    LibraryManagementSystem lms;
    lms.run();
    
    return 0;
}