#include <iostream>
#include <vector>
using namespace std;

class Book
{
private:
    int bookID;
    string title;
    string author;
    int copies;

public:
    Book(int id, string t, string a, int c)
    {
        bookID = id;
        title = t;
        author = a;
        copies = c;
    }

    int getID() { return bookID; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getCopies() { return copies; }

    bool issueCopy()
    {
        if (copies > 0)
        {
            copies--;
            return true;
        }
        return false;
    }

    void returnCopy()
    {
        copies++;
    }

    void display()
    {
        cout << "ID: " << bookID
             << " | Title: " << title
             << " | Author: " << author
             << " | Copies: " << copies << endl;
    }
};

class User
{
private:
    int studentID;
    string name;
    vector<int> borrowedBooks;

public:
    User(int id, string n)
    {
        studentID = id;
        name = n;
    }

    int getStudentID() { return studentID; }
    string getName() { return name; }

    void borrowBook(int bookID)
    {
        borrowedBooks.push_back(bookID);
    }

    void returnBook(int bookID)
    {
        for (int i = 0; i < borrowedBooks.size(); i++)
        {
            if (borrowedBooks[i] == bookID)
            {
                borrowedBooks.erase(borrowedBooks.begin() + i);
                return;
            }
        }
    }

    void showBorrowedBooks()
    {
        cout << "\n Borrowed Books by " << name << ":\n";
        if (borrowedBooks.empty())
        {
            cout << "No books borrowed.\n";
        }
        else
        {
            for (int id : borrowedBooks)
            {
                cout << "Book ID: " << id << endl;
            }
        }
    }
};

struct BorrowRecord
{
    int studentID;
    int bookID;
    int issueDay;
    int dueDay;
};

class Library
{
private:
    vector<Book> books;
    vector<User> users;
    vector<BorrowRecord> records;

    const int borrowDays = 7;
    const int finePerDay = 50;

public:
    void addBook()
    {
        int id, copies;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Copies: ";
        cin >> copies;

        books.push_back(Book(id, title, author, copies));
        cout << "Book added successfully!\n";
    }

    void addUser()
    {
        int id;
        string name;

        cout << "\nEnter Student ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        users.push_back(User(id, name));
        cout << "Student added successfully!\n";
    }

    void searchBook()
    {
        int choice;
        string keyword;

        cout << "\nSearch Book By:";
        cout << "\n1. Title";
        cout << "\n2. Author";
        cout << "\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        cout << "Enter keyword: ";
        getline(cin, keyword);

        cout << "\nSearch Results:\n";
        bool found = false;

        for (auto &b : books)
        {
            if ((choice == 1 && b.getTitle().find(keyword) != string::npos) ||
                (choice == 2 && b.getAuthor().find(keyword) != string::npos))
            {
                b.display();
                found = true;
            }
        }

        if (!found)
            cout << " No matching books found.\n";
    }

    User *findUser(int studentID)
    {
        for (auto &u : users)
        {
            if (u.getStudentID() == studentID)
                return &u;
        }
        return NULL;
    }

    Book *findBook(int bookID)
    {
        for (auto &b : books)
        {
            if (b.getID() == bookID)
                return &b;
        }
        return NULL;
    }

    void issueBook()
    {
        int studentID, bookID;
        cout << "\nEnter Student ID: ";
        cin >> studentID;

        cout << "Enter Book ID to issue: ";
        cin >> bookID;

        User *user = findUser(studentID);
        Book *book = findBook(bookID);

        if (user == NULL)
        {
            cout << "Student not found!\n";
            return;
        }

        if (book == NULL)
        {
            cout << " Book not found!\n";
            return;
        }

        if (book->issueCopy())
        {
            int issueDay;
            cout << "Enter Issue Day (example: 1-30): ";
            cin >> issueDay;

            BorrowRecord rec;
            rec.studentID = studentID;
            rec.bookID = bookID;
            rec.issueDay = issueDay;
            rec.dueDay = issueDay + borrowDays;

            records.push_back(rec);
            user->borrowBook(bookID);

            cout << " Book issued successfully!\n";
            cout << " Due Day: " << rec.dueDay << " (Issue Day + " << borrowDays << " days)\n";
        }
        else
        {
            cout << " No copies available!\n";
        }
    }

    void returnBook()
    {
        int studentID, bookID;
        cout << "\nEnter Student ID: ";
        cin >> studentID;

        cout << "Enter Book ID to return: ";
        cin >> bookID;

        User *user = findUser(studentID);
        Book *book = findBook(bookID);

        if (user == NULL)
        {
            cout << " Student not found!\n";
            return;
        }

        if (book == NULL)
        {
            cout << " Book not found!\n";
            return;
        }

        for (int i = 0; i < records.size(); i++)
        {
            if (records[i].studentID == studentID && records[i].bookID == bookID)
            {

                int returnDay;
                cout << "Enter Return Day (example: 1-30): ";
                cin >> returnDay;

                if (returnDay > records[i].dueDay)
                {
                    int lateDays = returnDay - records[i].dueDay;
                    int fine = lateDays * finePerDay;

                    cout << "⚠ Late return!\n";
                    cout << "Late Days: " << lateDays << endl;
                    cout << "Fine: Rs " << fine << endl;
                }
                else
                {
                    cout << "Returned on time. No fine.\n";
                }

                book->returnCopy();
                user->returnBook(bookID);
                records.erase(records.begin() + i);

                cout << " Book returned successfully!\n";
                return;
            }
        }

        cout << " This book was not issued by this student!\n";
    }

    void displayTotalBooks()
    {
        cout << "\nTotal number of books in library: " << books.size() << endl;
    }

    void showAllBooks()
    {
        cout << "\n----- Library Books -----\n";
        for (auto &b : books)
        {
            b.display();
        }
    }

    void showStudentBorrowedBooks()
    {
        int studentID;
        cout << "\nEnter Student ID: ";
        cin >> studentID;

        User *user = findUser(studentID);
        if (user == NULL)
        {
            cout << " Student not found!\n";
            return;
        }

        user->showBorrowedBooks();
    }
};

int main()
{
    Library lib;
    int choice;

    do
    {
        cout << "\n===== Library System =====";
        cout << "\n1. Add Book";
        cout << "\n2. Add Student(User)";
        cout << "\n3. Search Book (Title/Author)";
        cout << "\n4. Issue Book (Due Day)";
        cout << "\n5. Return Book (Fine Calculation)";
        cout << "\n6. Display Total Books";
        cout << "\n7. Show All Books";
        cout << "\n8. Show Student Borrowed Books";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            lib.addBook();
            break;
        case 2:
            lib.addUser();
            break;
        case 3:
            lib.searchBook();
            break;
        case 4:
            lib.issueBook();
            break;
        case 5:
            lib.returnBook();
            break;
        case 6:
            lib.displayTotalBooks();
            break;
        case 7:
            lib.showAllBooks();
            break;
        case 8:
            lib.showStudentBorrowedBooks();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
