#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// STRUCT
struct Book {
    string title;
    string author;
    int year; 
    string genre;
    string status;
};

// GLOBAL VARIABLES
int loginChoice, adminChoice, guestChoice, confirm, bookNumber, another_admin, another_guest;
string username, password, titletoSearch;


// ADMIN FUNCTIONS
void admin();
void addBooks(const Book & newBook);
void deleteBooks(int bookNumber);
void updateBooks(int bookNumber);
void showAvailableBooks();

// GUEST FUNCTIONS
void guest();
void rentBook(int bookNumber);
void returnBook(int bookNumber);
void searchTitle(string titletoSearch);

// CONSOLE FUNCTIONS
void clearSystem();

// MAIN FUNCTION / LOGIN
int main(){
    
    clearSystem();

    // MAIN LOGIN PROMPT
    cout << "\t\t\t\t\t\t==================================================================" << '\n';
    cout << "\t\t\t\t\t\t=               WELCOME TO THE ILOILO SHAREHOLDERS               =" << '\n';
    cout << "\t\t\t\t\t\t=                        LIBRARY SYSTEM                          =" << '\n';
    cout << "\t\t\t\t\t\t=                                                                = " << '\n';
    cout << "\t\t\t\t\t\t=                 PLEASE SELECT A LOGIN OPTION:                  = " << '\n';
    cout << "\t\t\t\t\t\t=                 ENTER 1 TO LOGIN AS ADMIN                      = " << '\n';
    cout << "\t\t\t\t\t\t=                 ENTER 2 TO LOGIN AS GUEST                      = " << '\n';
    cout << "\t\t\t\t\t\t=                 ENTER 0 TO LOGIN AS CANCEL LOGIN               = " << '\n';
    cout << "\t\t\t\t\t\t==================================================================" << '\n';

    
    cin >> loginChoice;
    
    switch(loginChoice){
            case 1:
            clearSystem();
            
                do {
                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                    cout << "\t\t\t\t\t\t=     PLEASE ENTER YOUR USERNAME (OR ENTER EXIT TO CANCEL)    =" << '\n';
                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                    cin >> username;
                    clearSystem();


                            if (username == "Exit" || username == "exit") {
                                cout << "\t\t\t\t\t\t===============================================================" << '\n';
                                cout << "\t\t\t\t\t\t=                    EXITING ADMIN LOGIN                      =" << '\n';
                                cout << "\t\t\t\t\t\t===============================================================" << '\n';
                                break; 
                            }

                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                    cout << "\t\t\t\t\t\t=     PLEASE ENTER YOUR PASSWORD (OR ENTER EXIT TO CANCEL)    =" << '\n';
                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                    cin >> password;
                    clearSystem();


                            if (password == "Exit" || password == "exit") {
                                cout << "\t\t\t\t\t\t===============================================================" << '\n';
                                cout << "\t\t\t\t\t\t=                    EXITING ADMIN LOGIN                      =" << '\n';
                                cout << "\t\t\t\t\t\t===============================================================" << '\n';
                                break; 
                            }

                        if (username == "winter123" && password == "admin123") {
                            admin(); // if username and password matches, direct to admin login page
                            
                            break; // Exit the loop after detecting matching credentials
                        } else {
                            cout << "\t\t\t\t\t\t===============================================================" << '\n';
                            cout << "\t\t\t\t\t\t=               INVALID USERNAME OR PASSWORD                  =" << '\n';
                            cout << "\t\t\t\t\t\t=        ENTER 1 TO TRY AGAIN OR ENTER 0 TO END PROGRAM       =" << '\n';
                            cout << "\t\t\t\t\t\t===============================================================" << '\n';
                            cin >> confirm;

                            clearSystem();


                                if (confirm == 0 ) {
                                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                                    cout << "\t\t\t\t\t\t=                    EXITING ADMIN LOGIN                      =" << '\n';
                                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                                    break;
                                } else if (confirm != 1 && confirm != 0){
                                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                                    cout << "\t\t\t\t\t\t=                 PLEASE ONLY ENTER 1 OR 0                    =" << '\n';
                                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                                } else {
                                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                                    cout << "\t\t\t\t\t\t=              CHOSEN OPTION: REDO ADMIN LOGIN                =" << '\n';
                                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                                }
                        }

                } while (confirm == 1); 

        break;
        
        case 2:
        clearSystem();
        guest();
        break;

        default:
        clearSystem();

        cout << "\t\t\t\t\t\t===============================================================" << '\n';
        cout << "\t\t\t\t\t\t=                    INVALID OPTION SELECTED                  =" << '\n';
        cout << "\t\t\t\t\t\t=                     PROGRAM WILL END NOW                    =" << '\n';
        cout << "\t\t\t\t\t\t===============================================================" << '\n';
        break;
    }

    return 0;
}

// ADMIN FUNCTION DECLARATIONS
void admin(){
    string filename = "books.txt";
    
    do {
    clearSystem();
    cout << "\t\t\t\t\t\t===============================================================" << '\n';
    cout << "\t\t\t\t\t\t=           USERNAME AND PASSWORD MATCH CREDENTIALS           =" << '\n';
    cout << "\t\t\t\t\t\t=        WELCOME BACK ADMIN! WHAT WOULD YOU LIKE TO DO?       =" << '\n';
    cout << "\t\t\t\t\t\t=                                                             =" << '\n';
    cout << "\t\t\t\t\t\t=           ENTER 1 TO ADD A NEW BOOK TO THE LIBRARY          =" << '\n';
    cout << "\t\t\t\t\t\t=          ENTER 2 TO DELETE A BOOK FROM THE LIBRARY          =" << '\n';
    cout << "\t\t\t\t\t\t=      ENTER 3 TO UPDATE ANY CURRENT BOOK IN THE LIBRARY      =" << '\n';
    cout << "\t\t\t\t\t\t=      ENTER 4 TO CHECK CURRENT BOOK STATUS IN THE LIBRARY    =" << '\n';
    cout << "\t\t\t\t\t\t=                  ENTER 0 TO EXIT THE PROGRAM                =" << '\n';
    cout << "\t\t\t\t\t\t===============================================================" << '\n';
    cin >> adminChoice;

    cin.ignore();

        switch(adminChoice){
            case 1:{
            clearSystem();

            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=                CHOSEN OPTION: ADD A NEW BOOK                =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            Book newBook;
            
            cout << "Enter the title of the book you want to add: ";
            getline(cin, newBook.title);
            
            cout << "Enter the author of the book that you want to add: ";
            getline(cin, newBook.author);
            
            cout << "Enter the year the book was published (Ex. 2024) : ";
            cin >> newBook.year;
                
                if (newBook.year > 2024 && newBook.year < 1500){
                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                    cout << "\t\t\t\t\t\t=                     INVALID DATE ENTERED                    =" << '\n';
                    cout << "\t\t\t\t\t\t===============================================================" << '\n';
                }
            
            cin.ignore();
        
            cout << "Enter the genre of the book that you want to add:  ";
            getline(cin, newBook.genre);

            clearSystem();
        
            addBooks(newBook);

            showAvailableBooks();

            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=              WOULD YOU LIKE TO DO SOMETHING ELSE?           =" << '\n';
            cout << "\t\t\t\t\t\t=                                                             =" << '\n';
            cout << "\t\t\t\t\t\t=              ENTER -1 TO GO BACK TO THE ADMIN MENU          =" << '\n';
            cout << "\t\t\t\t\t\t=              ENTER OTHERWISE TO EXIT PROGRAM                =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            cin >> another_admin;
            break;
        }
            case 2:
            clearSystem();

            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=                CHOSEN OPTION: DELETE A BOOK                 =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            showAvailableBooks();

            cout << "Please enter the book number that you would like to delete: ";
            cin >> bookNumber;
            cin.ignore();

            deleteBooks(bookNumber);
                if (bookNumber != 0) {
                showAvailableBooks(); 
                }
            

            cout << "\n\n\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=             WOULD YOU LIKE TO DO SOMETHING ELSE?            =" << '\n';
            cout << "\t\t\t\t\t\t=                                                             =" << '\n';
            cout << "\t\t\t\t\t\t=             ENTER -1 TO GO BACK TO THE ADMIN MENU           =" << '\n';
            cout << "\t\t\t\t\t\t=             ENTER OTHERWISE TO EXIT PROGRAM                 =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            cin >> another_admin;

            break;

            case 3: {
            
            clearSystem();
            
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=              CHOSEN OPTION: UPDATE CURRENT BOOKS            =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            showAvailableBooks();

            cout << "Please enter the book number that you would like to edit: ";
            cin >> bookNumber;
            cin.ignore();

            clearSystem();

            updateBooks(bookNumber);

                if (bookNumber != 0) {
                showAvailableBooks(); 
                }

            cout << "\n\n\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=             WOULD YOU LIKE TO DO SOMETHING ELSE?            =" << '\n';
            cout << "\t\t\t\t\t\t=                                                             =" << '\n';
            cout << "\t\t\t\t\t\t=             ENTER -1 TO GO BACK TO THE ADMIN MENU           =" << '\n';
            cout << "\t\t\t\t\t\t=             ENTER OTHERWISE TO EXIT PROGRAM                 =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            cin >> another_admin;
            break;
            }
            
            case 4:
            clearSystem();

            showAvailableBooks();

            int choice; //prompt to ask user if program can keep moving along
            cout << "Are you done viewing the books?\n";
            cout << "Enter any number to confirm: ";
            cin >> choice;

                if (choice){
                clearSystem();

            cout << "\n\n\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=              WOULD YOU LIKE TO DO SOMETHING ELSE?           =" << '\n';
            cout << "\t\t\t\t\t\t=                                                             =" << '\n';
            cout << "\t\t\t\t\t\t=              ENTER -1 TO GO BACK TO THE ADMIN MENU          =" << '\n';
            cout << "\t\t\t\t\t\t=              ENTER OTHERWISE TO EXIT PROGRAM                =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            cin >> another_admin;
            break;
            }

            case 0:
            clearSystem();

            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=                 CHOSEN OPTION: EXIT PROGRAM                 =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            break; 

            default:
            clearSystem();

            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=                       INVALID OUTPUT                        =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            break;
        }


    } while (another_admin == -1);
}
void addBooks(const Book & newBook){
    
    string filename = "books.txt"; //name of the file which will contain book and book information
    int bookcount = 1; //this will be used for vectors in other functions
    string lines; 
    
    fstream addBooks(filename, ios::out | ios::app); //opening the text file to write

        if(!addBooks.is_open()){
            cout << "Failed to open book file\n";
        }
    
    
    fstream readBooks(filename, ios::in); //opening the text file to read
    
        while (getline(readBooks, lines)) {
            if (lines == "-----------------------------") { 
                bookcount++; //if text file reads this seperator, will increment bookcount for increasing book additions
            }
        }
    readBooks.close();

        if (addBooks.is_open()) { //format in my text file
        addBooks << bookcount << ".\n";
        
        addBooks << "Title: " << newBook.title << '\n';
            
        addBooks << "Author: " << newBook.author << '\n';

        addBooks << "Year Published: " << newBook.year << '\n';   //wanted to add day and month functionality, however was too hard

        addBooks << "Genre: " << newBook.genre << '\n';

        addBooks << "Status: Available" << '\n'; //status must be set to available on new book creation
            
        addBooks << "-----------------------------" << '\n'; //must have the same number of "-" for the while loop earlier

        addBooks.close();

        } else {
            cout << "Failed to add book\n";
        }

        addBooks.close();
}
void deleteBooks(int bookNumber){
    string filename = "books.txt";
    vector <Book> books; 
    string lines;

    fstream readBooks (filename, ios::in); //ios::in meanng to read
        if(!readBooks.is_open()){
            cout << "Cannot open the file to be read";
            return;
        }

    while(getline(readBooks, lines)){

        if (lines.find(".") != string::npos){ //string::npos means character is not found
            Book book;

            //this sequence of getlines will read string data from "books.txt" and store them into a vector using pushback
            getline(readBooks, lines);
            book.title = lines.substr(lines.find(":") + 2);

            getline(readBooks, lines);
            book.author = lines.substr(lines.find(":") + 2);

            getline(readBooks, lines);
            book.year = stoi(lines.substr(lines.find(":") + 2)); //stoi = switch a int variable to a string variable (since year was declared as an int)

            getline(readBooks, lines);
            book.genre = lines.substr(lines.find(":")+ 2);

            getline(readBooks, lines);
            book.status = lines.substr(lines.find(":") + 2);

            books.push_back(book); //save data into the dynamic array (vector)
        }
    } 

        if (bookNumber <= 0 || bookNumber > books.size()){ //error handling.
            cout << "Error: Invalid book number entered\n";
            return;
        }
    
    books.erase(books.begin() + (bookNumber - 1)); //erase the array index that the user inputs.

    fstream writeBooks(filename, ios::out | ios::trunc);
        if(!writeBooks.is_open()){
            cout << "Error: Failed to open the file for writing\n";
        }

        for (size_t i = 0; i < books.size(); ++i){ //for loop to reinput data back to the text file
            writeBooks << (i + 1) << "." << '\n';
            writeBooks << "Title: " << books[i].title << '\n';
            writeBooks << "Author: " << books[i].author << '\n';
            writeBooks << "Year Published: " << books[i].year << '\n';
            writeBooks << "Genre: " << books[i].genre << '\n';
            writeBooks << "Status: " << books[i].status << '\n';
            writeBooks << "-----------------------------" << '\n';
        }

        writeBooks.close();
}
void updateBooks(int bookNumber){
    string filename = "books.txt";
    string lines;
    int currentBookNum = 0;
    vector<string> fileLines;
    int index = -1;
    string updatedTitle, updatedAuthor, updatedGenre;
    int newYear;

    fstream readBooks(filename, ios::in);

 
    if (!readBooks.is_open()) {
        cout << "Error: Could not open book file.\n";
        return;
    }

    while (getline(readBooks, lines)) { //while loop to read contents in the text file
        if (lines.find('.') != string::npos && isdigit(lines[0])) { //if the program detects a "." and a digit greater than 0 in the line,
            currentBookNum++;                                       // will increment currentBookNum by 2
        }
        fileLines.push_back(lines); //save all lines into a vector
    }
    readBooks.close();

    
        if (bookNumber <= 0 || bookNumber > currentBookNum) { //error handling
            cout << "Error: Please input a valid book number.\n";
            return;
        }

    currentBookNum = 0;
    
    // using a for loop to detect the book's index in the vector
    for (size_t i = 0; i < fileLines.size(); ++i) { //for loop to detect the book to update in the dynamic array
        if (fileLines[i].find('.') != string::npos && isdigit(fileLines[i][0])) {
            currentBookNum++;
            if (currentBookNum == bookNumber) {
                index = i;
                break;
            }
        }
    }

    if (index == -1) {
        cout << "Error: Book not found.\n";
        return;
    }

    cout << fileLines[index + 1] << "\n"; //prompt user to enter new data
    cout << "Enter new title (Type KEEP to keep current title): ";
    getline(cin, updatedTitle);
        if (updatedTitle != "KEEP") fileLines[index + 1] = "Title: " + updatedTitle;
        
        clearSystem();



    cout << fileLines[index + 2] << "\n"; //prompt user to enter new data
    cout << "Enter new author (Enter KEEP to keep current author): ";
    getline(cin, updatedAuthor);
        if (updatedAuthor != "KEEP") fileLines[index + 2] = "Author: " + updatedAuthor;
        
        clearSystem();


    
    cout << fileLines[index + 3] << "\n"; //prompt user to enter new data
    cout << "Enter new year published (Enter -1 to keep current): ";
    cin >> newYear;
        if (newYear != -1) fileLines[index + 3] = "Year Published: " + newYear;
        
        cin.ignore();
        
        clearSystem();

    
    cout << fileLines[index + 4] << "\n"; //prompt user to enter new data
    cout << "Enter new genre (Enter KEEP to keep current genre): ";
    getline(cin, updatedGenre);
        if (updatedGenre != "KEEP") fileLines[index + 4] = "Genre: " + updatedGenre;
        
        clearSystem();


    fstream writeBooks(filename, ios::out | ios::trunc);
    if (!writeBooks.is_open()) {
        cout << "Error: Failed to open file for writing.\n";
        return;
    }

    for (size_t i = 0; i < fileLines.size(); ++i) {
    writeBooks << fileLines[i] << '\n';
    }
    
    writeBooks.close();

    
}
void showAvailableBooks(){
    string filename = "books.txt";
    fstream readBooks(filename, ios::in);
    string lines;

    if (!readBooks.is_open()) {
        cout << "Error: Failed to open the file";
        return;
    }

    cout << "\t\t\t\t\t\t===============================================================" << '\n';
    cout << "\t\t\t\t\t\t=               AVAILABLE BOOKS IN THE LIBRARY                =" << '\n';
    cout << "\t\t\t\t\t\t===============================================================" << '\n';
    
    while (getline(readBooks, lines)) { //using a simple while loop to display all lines in the 
        cout << lines << '\n';
    }
    readBooks.close();

}

// GUEST FUNCTION DECLARATIONS
void guest(){
    
    do {
    clearSystem();

    cout << "\t\t\t\t\t\t===============================================================" << '\n';
    cout << "\t\t\t\t\t\t=             USER HAS CHOSEN GUEST LOGIN PATHWAY             =" << '\n';
    cout << "\t\t\t\t\t\t=           WELCOME GUEST! WHAT WOULD YOU LIKE TO DO?         =" << '\n';
    cout << "\t\t\t\t\t\t=                                                             =" << '\n';
    cout << "\t\t\t\t\t\t=               ENTER 1 TO SHOW AVAILABLE BOOKS               =" << '\n';
    cout << "\t\t\t\t\t\t=               ENTER 2 TO RENT A BOOK                        =" << '\n';
    cout << "\t\t\t\t\t\t=               ENTER 3 TO RETURN ANY RENTED BOOKS            =" << '\n';
    cout << "\t\t\t\t\t\t=               ENTER 4 TO SEARCH BOOK BY TITLE               =" << '\n';
    cout << "\t\t\t\t\t\t=               ENTER 0 TO EXIT THE PROGRAM                   =" << '\n';
    cout << "\t\t\t\t\t\t===============================================================" << '\n';
    cin >> guestChoice;

        switch(guestChoice){
            case 1:
            clearSystem();
            showAvailableBooks();

            int choice;
            cout << "Are you done viewing the books?\n";
            cout << "Enter any number to confirm: ";
            cin >> choice;

                if (choice){
                clearSystem();

            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=              WOULD YOU LIKE TO DO SOMETHING ELSE?           =" << '\n';
            cout << "\t\t\t\t\t\t=                                                             =" << '\n';
            cout << "\t\t\t\t\t\t=              ENTER -1 TO GO BACK TO THE ADMIN MENU          =" << '\n';
            cout << "\t\t\t\t\t\t=              ENTER OTHERWISE TO EXIT PROGRAM                =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            cin >> another_guest;
            }
            break; 

            case 2:
            clearSystem();
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=                SELECTED OPTION: RENT A BOOK                 =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            showAvailableBooks();

            cout << "Please enter the number of the book that you want to rent: ";
            cin >> bookNumber;
            rentBook(bookNumber);
            cin.ignore();
            

            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=              WOULD YOU LIKE TO DO SOMETHING ELSE?           =" << '\n';
            cout << "\t\t\t\t\t\t=                                                             =" << '\n';
            cout << "\t\t\t\t\t\t=              PRESS -1 TO GO BACK TO THE ADMIN MENU          =" << '\n';
            cout << "\t\t\t\t\t\t=              ENTER OTHERWISE TO EXIT PROGRAM                =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            cin >> another_guest;
            break;

            case 3: 
            clearSystem();
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=                SELECTED OPTION: RETURN A BOOK               =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            showAvailableBooks();

            cout << "Please enter the number of the book that you want to return: ";
            cin >> bookNumber;

            returnBook(bookNumber);
            cin.ignore();
            

            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=              WOULD YOU LIKE TO DO SOMETHING ELSE?           =" << '\n';
            cout << "\t\t\t\t\t\t=                                                             =" << '\n';
            cout << "\t\t\t\t\t\t=              ENTER -1 TO GO BACK TO THE ADMIN MENU          =" << '\n';
            cout << "\t\t\t\t\t\t=              ENTER OTHERWISE TO EXIT PROGRAM                =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            cin >> another_guest;
            break;

            case 4:
            clearSystem();
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=               SELECTED OPTION: SEARCH BY TITLE              =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';

            searchTitle(titletoSearch);
            

            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=              WOULD YOU LIKE TO DO SOMETHING ELSE?           =" << '\n';
            cout << "\t\t\t\t\t\t=                                                             =" << '\n';
            cout << "\t\t\t\t\t\t=              PRESS -1 TO GO BACK TO THE ADMIN MENU          =" << '\n';
            cout << "\t\t\t\t\t\t=              ENTER OTHERWISE TO EXIT PROGRAM                =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            cin >> another_guest;
            break;

            case 0:
            clearSystem();
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=                    EXITING ADMIN PROGRAM                    =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            break;

            default:
            clearSystem();
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            cout << "\t\t\t\t\t\t=                    INVALID INPUT ENTERED                    =" << '\n';
            cout << "\t\t\t\t\t\t===============================================================" << '\n';
            
            break;
        }


       

    } while (another_guest == -1);

}
void rentBook(int bookNumber) { 
    string filename = "books.txt";
    string line;
    int currentBookNum, year, month, day;
    vector<string> fileLines;
    int index = -1;
    string rentalDate;

    fstream readBooks(filename, ios::in);
    
    if (!readBooks.is_open()) {
        cout << "Error: Could not open book file.\n";
        return;
    }

    //for loop for labelling before being sent in the vector
    while (getline(readBooks, line)) {
        if (line.find('.') != string::npos && isdigit(line[0])) {
            currentBookNum++;
        }
        fileLines.push_back(line);
    }
    readBooks.close();

    
    if (bookNumber <= 0 || bookNumber > currentBookNum) {
        cout << "Error: Please input a valid book number.\n";
        return;
    }

    
    currentBookNum = 0;
    
    // for loop for detecting specific index in the vector
    for (size_t i = 0; i < fileLines.size(); ++i) {
        if (fileLines[i].find('.') != string::npos && isdigit(fileLines[i][0])) {
            currentBookNum++;
            if (currentBookNum == bookNumber) {
                index = i;
                break;
            }
        }
    }

    if (index == -1) {
        cout << "Error: Book not found.\n";
        return;
    }

        //only editing the status line
   if (fileLines[index + 5].find("Status: Available") != string::npos) {
        
        cout << "Enter the rental year (2024): ";
        cin >> year;
        
        cout << "Enter the rental month (1-12): ";
        cin >> month;
        
        cout << "Enter the rental day (1-31): ";
        cin >> day;

            //Error Handling
            if (year < 1500 && year > 2100) {
                cout << "Invalid date entered.\n";
            
            } else if (month < 1 && month < 12){
                cout << "Invalid date entered.\n";
                
            } else if (day < 1 && day > 31) {
                cout << "Invalid date entered.\n";

            } else {
            
            // Formatting
            
            stringstream format;
            format << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day;
            rentalDate = format.str();

            fileLines[index + 5] = "Status: Rented on " + rentalDate;
            }

        
    } else {
        cout << "This book is already rented or unavailable.\n";
        return;
    }
    
   
    
    fstream writeBooks(filename, ios::out | ios::trunc);
    if (!writeBooks.is_open()) {
        cout << "Error: Failed to open file for writing.\n";
        return;
    }

    for (size_t i = 0; i < fileLines.size(); ++i) {
    writeBooks << fileLines[i] << '\n';
    }   

    clearSystem();
    
}
void returnBook(int bookNumber){
    string filename = "books.txt";
    fstream readBooks(filename, ios::in);
    string line;
    int currentBookNum;
    vector<string> fileLines;
    int index = -1;


    // Open file for reading
    if (!readBooks.is_open()) {
        cout << "Error: Could not open book file.\n";
        return;
    }

    // Read all lines into memory and determine book numbers
    while (getline(readBooks, line)) {
        if (line.find('.') != string::npos && isdigit(line[0])) {
            currentBookNum++;
        }
        fileLines.push_back(line);
    }
    readBooks.close();

    // Validate book number
    if (bookNumber <= 0 || bookNumber > currentBookNum) {
        cout << "Error: Please input a valid book number.\n";
        return;
    }

    // Locate the book's index in the file
    currentBookNum = 0;
    for (size_t i = 0; i < fileLines.size(); ++i) {
        if (fileLines[i].find('.') != string::npos && isdigit(fileLines[i][0])) {
            currentBookNum++;
            if (currentBookNum == bookNumber) {
                index = i;
                break;
            }
        }
    }

    if (index == -1) {
        cout << "Error: Book not found.\n";
        return;
    }

    
    cout << fileLines[index + 1] << "\n";
    cout << fileLines[index + 2] << "\n";
    cout << fileLines[index + 3] << "\n";
    cout << fileLines[index + 4] << "\n";
    
    //error handling
        if (fileLines[index + 5].find("Rented on") != string::npos){
        fileLines[index + 5] = "Status: Available"; //only changing the status to "available immediately
        
        
        } else if (fileLines[index + 5].find("Available") != string::npos) {
        cout << "This book is currently not being rented\n";
        
        } else {
        cout << "Book does not exist in this library\n";
        }

    // Open file for writing
    fstream writeBooks(filename, ios::out | ios::trunc);
    if (!writeBooks.is_open()) {
        cout << "Error: Failed to open file for writing.\n";
        return;
    }

    //for loop to input all lines from the vector back to the text file
    for (size_t i = 0; i < fileLines.size(); ++i) {
    writeBooks << fileLines[i] << '\n';
    }
    
    writeBooks.close();

    

}
void searchTitle(string titletoSearch){
    string filename = "books.txt";
    string title;
    
    fstream readFile (filename, ios::in);

        if (!readFile.is_open()){
            cout << "File cannot be opened\n";
        }

    clearSystem();

    cout << "Please enter the title of the book that you are searching for: ";
    cin.ignore();
    getline(cin, title);

    //using bool for detection
    bool bookFound = false;
    
    string lines;

    while (getline(readFile, lines)){
        if (lines.find("Title: ") == 0 && lines.substr(7) == title) {
            bookFound = true;
            cout << "\nBook has been found\n\n";
            cout << lines << '\n';

            //for loop to display the details of the book
            for (int i = 0; i < 4; ++i){
                if (getline(readFile, lines)){
                    cout << lines << '\n';
                }
            }
            break;
        }
    }

    if (!bookFound){
        cout << "Sorry, this book is not available at the library at the moment\n";
    }

}

// CONSOLE DECLARATIONS
void clearSystem(){
#ifdef _WIN32
    system("cls");

#else 
    system("clear");

#endif
}
