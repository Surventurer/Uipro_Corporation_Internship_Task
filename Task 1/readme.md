# Admin Library Management System (Console-Based)

## Project Overview
A comprehensive C++ console-based application designed to manage library operations including book management, student registration, and book issue/return processes. The system uses object-oriented programming principles and file handling for data persistence.

## Features Implemented

### 🔐 Authentication System
- Password-protected admin login
- Default admin password: `admin123`

### 📚 Book Management Module
- **Add New Book**: Register new books with auto-generated IDs
- **Display All Books**: View complete book inventory with availability status
- **Search Books**: Search by Book ID or Title with partial matching
- **Delete Books**: Remove books (with validation for issued books)

### 👨‍🎓 Student Management Module
- **Register Student**: Add new students with auto-generated IDs
- **Display Student List**: View all registered students
- **Search Student**: Find student by ID
- **Delete Student**: Remove student records (with validation for issued books)

### 📖 Issue/Return Management Module
- **Issue Book**: Assign books to students with automatic due date calculation
- **Return Book**: Process book returns with date tracking
- **Display Issued Books**: View all currently issued books with student details

### 📊 Reports Module
- **All Books Report**: Complete inventory listing
- **All Students Report**: Complete student database
- **Issued Books Report**: Current active book issues
- **Transaction History**: Complete issue/return history

### 💾 File Handling System
- **Persistent Storage**: All data saved in `.dat` files
- **Automatic Loading**: Data automatically loaded on startup
- **Data Files**:
  - `books.dat` - Book records
  - `students.dat` - Student records
  - `transactions.dat` - Transaction history

## Object-Oriented Programming Features

### Class Hierarchy
```
Person (Base Class)
├── Student (Derived Class)
```

### Core Classes
- **Person**: Base class with common attributes (id, name, contact)
- **Student**: Inherits from Person, adds course and enrollment date
- **Book**: Manages book information and issue status
- **Transaction**: Tracks book issue/return operations
- **LibraryManagementSystem**: Main system controller

### OOP Concepts Implemented
- **Inheritance**: Student class inherits from Person
- **Encapsulation**: Private data members with public getter/setter methods
- **Abstraction**: Clean interface hiding implementation details
- **Polymorphism**: Virtual destructors and method overriding

### 📁 File Structure
```
project_folder/
├── main.cpp                                (Main source code)
├── library_system.exe/library_system       (Compiled executable)
├── books.dat                               (Auto-generated data file)
├── students.dat                            (Auto-generated data file)
├── transactions.dat                        (Auto-generated data file)
└── readme.md                               (Documentation)
```
## Installation & Setup

### 1. Compilation
```bash
# Using GCC
g++ -o library_system main.cpp
```

### 2. Execution
```bash
# Linux/Mac
./library_system

# Windows
library_system.exe
```

### 3. First Run Setup
- The system will create data files automatically on first run
- Default admin password: `admin123`
- Data files (`books.dat`, `students.dat`, `transactions.dat`) will be created in the same directory

## Usage Instructions

### 1. Login
- Enter admin password: `admin123`
- System will validate credentials before proceeding

### 2. Navigation
- Use numeric menu options to navigate
- Follow on-screen prompts for data entry
- Press Enter after each input

### 3. Book Management
```
Main Menu → Book Management
1. Add books with title, author, and ISBN
2. View all books with availability status
3. Search by ID or title (supports partial matching)
4. Delete books (only if not issued)
```

### 4. Student Management
```
Main Menu → Student Management
1. Register students with name, contact, and course
2. View all registered students
3. Search students by ID
4. Delete students (only if no active issues)
```

### 5. Issue/Return Operations
```
Main Menu → Issue/Return Management
1. Issue books by entering Book ID and Student ID
2. Return books by entering Book ID
3. View all currently issued books
```

### 6. Reports
```
Main Menu → Reports
1. Complete book inventory
2. All student records
3. Currently issued books
4. Complete transaction history
```

## Data Management

### File Structure
```
books.dat format: ID|Title|Author|ISBN|IsIssued|IssuedToStudentID
students.dat format: ID|Name|Contact|Course|EnrollmentDate
transactions.dat format: TransactionID|BookID|StudentID|IssueDate|DueDate|ReturnDate|LateFee
```

### Data Validation
- Duplicate ID prevention through auto-increment
- Book availability checking before issue
- Student existence validation
- Active transaction validation before deletion

## Error Handling

### Input Validation
- Numeric input validation for menu choices
- File access error handling
- Data format validation during file operations

### Business Logic Validation
- Cannot delete issued books
- Cannot delete students with active issues
- Cannot issue already issued books
- Cannot return non-issued books

## Sample Data

### Sample Books
```
1. "The Great Gatsby" by F. Scott Fitzgerald
2. "To Kill a Mockingbird" by Harper Lee
3. "1984" by George Orwell
4. "Pride and Prejudice" by Jane Austen
5. "The Catcher in the Rye" by J.D. Salinger
6. "Lord of the Flies" by William Golding
7. "The Hobbit" by J.R.R. Tolkien
8. "Brave New World" by Aldous Huxley
9. "The Chronicles of Narnia" by C.S. Lewis
10. "Harry Potter and the Sorcerer's Stone" by J.K. Rowling
```

### Sample Students
```
1. John Doe | Computer Science | 555-0101  
2. Jane Smith | Mathematics | 555-0102  
3. Mike Johnson | Physics | 555-0103  
4. Sarah Wilson | Chemistry | 555-0104  
5. David Brown | Biology | 555-0105  
6. Emily Davis | English Literature | 555-0106  
7. Robert Miller | History | 555-0107  
8. Lisa Anderson | Psychology | 555-0108  
9. Kevin Taylor | Engineering | 555-0109  
10. Amanda White | Business Administration | 555-0110 
```

## Advanced Features

### Due Date Management
- Automatic due date calculation (14 days from issue)
- Date tracking for all transactions
- Future enhancement ready for late fee calculation

### Transaction History
- Complete audit trail of all operations
- Issue and return date tracking
- Student-book relationship mapping

### Search Functionality
- Case-insensitive partial matching for book titles
- Multiple search criteria support
- Efficient search algorithms

## Troubleshooting

### Common Issues

#### 1. File Access Errors
**Problem**: Cannot create or access data files
**Solution**: 
- Ensure write permissions in application directory
- Run as administrator if necessary
- Check disk space availability

#### 2. Compilation Errors
**Problem**: Compiler errors during build
**Solution**:
- Ensure C++11 or later standard
- Check all required headers are available
- Verify compiler installation

#### 3. Data Corruption
**Problem**: Invalid data in files
**Solution**:
- Delete `.dat` files to reset data
- Manually edit files following the format specification
- Restart application to regenerate files

#### 4. Memory Issues
**Problem**: Application crashes or slow performance
**Solution**:
- Monitor system resources
- Restart application periodically
- Clear transaction history if too large

## Development Information

### Development Time
- **Estimated**: 5-10 days
- **Submitted on**: 15 June 2025

### Code Statistics
- **Lines of Code**: ~800 lines
- **Classes**: 5 main classes
- **Methods**: 25+ member functions
- **File Operations**: Complete CRUD operations

### Testing Scenarios
1. **Basic Operations**: Add, view, search, delete for books and students
2. **Issue/Return Flow**: Complete book circulation process
3. **Data Persistence**: File save/load operations
4. **Error Handling**: Invalid inputs and edge cases
5. **Business Rules**: Validation of business logic constraints

## Support & Maintenance

### Contact Information
- For technical issues, refer to code comments
- For bug reports, include steps to reproduce

### License
This project is developed as an Task demonstrating C++ programming concepts and Admin library management system design for the company UIPRO CORPORATION PVT. LTD. under Ankur Aditya sir.
