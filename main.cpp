#include <iostream>
#include <string>
#include <array>
#include <cctype>

using namespace std;

int main() {
    size_t bookCount{};
    char choice{};
    const int max_library_books{ 100 };
    array<string, max_library_books> book_titles;
    array<string, max_library_books> book_authors;
    array<int, max_library_books> publication_years;


    do {
        cout << "============== Library management system ==============" << endl;
        cout << "\n-----------------------------------------\n";
        cout << "The Library contains " << bookCount << " books" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Please chose one of the following options:" << endl;
        cout << "   1. Add new book\n";
        cout << "   2. View all books\n";
        cout << "   3. Search for a book\n";
        cout << "   4. Delete a book\n";
        cout << "   5. Exit\n";
        cout << "----------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        cout << "----------------------" << endl;


        if (choice == '1') {
            if (bookCount < max_library_books) {
                string temp_book_title;
                string temp_author_name;
                int temp_publish_year;

                cout << "Add book title: "; getline(cin, temp_book_title);
                book_titles[bookCount] = temp_book_title;
                cout << "Add the Author name: "; getline(cin, temp_author_name);
                book_authors[bookCount] = temp_author_name;
                cout << "Add publication year: "; cin >> temp_publish_year;
                publication_years[bookCount] = temp_publish_year;
                cin.ignore();
                cout << "-----------------------------------------\n";
                cout << "Book \"" << temp_book_title << "\" " << "\""
                    << temp_author_name << "\" " << "(" << temp_publish_year << ")"
                    << " Added Successfully.";
                cout << "\n--------------------------------------------------------------------------\n" << endl;
                bookCount++;
            }
            else {
                cout << "The library is full, Cannot add more books.\n";
            }
        }
        else if (choice == '2') {
            if (bookCount > 0) {
                for (size_t i{ 0 }; i < bookCount; ++i) {
                    cout << "-Book " << i + 1 << " Title: " << book_titles.at(i)
                        << ", Author: " << book_authors.at(i) << ", Published: "
                        << publication_years.at(i) << endl;
                }
            }
            else {
                cout << "The library is empty, No books to show." << endl;
            }
            cout << "--------------------------------------------------------------------------\n" << endl;
        }
        else if (choice == '3') {
            if (bookCount == 0) {
                cout << "The library is empty, No books to search." << endl;
            }
            else {
                string temp_keyword;
                string temp_lower_title;
                string temp_lower_author;
                string search_keyword;
                bool found = false;
                cout << "Enter a Keyword to search for a book (title - author): ";
                getline(cin, search_keyword);
                temp_keyword = search_keyword;
                cout << "-----------------------------------------\n";
                for (char& c : temp_keyword) c = tolower(c);

                for (size_t i{ 0 }; i < bookCount; ++i) {
                    temp_lower_title = book_titles[i];
                    temp_lower_author = book_authors[i];

                    // To make every single char small in every single string.
                    for (char& c : temp_lower_title) c = tolower(c);
                    for (char& c : temp_lower_author) c = tolower(c);

                    // Now time to check if the keyword existing.
                    if (temp_lower_title.find(temp_keyword) != std::string::npos ||
                        temp_lower_author.find(temp_keyword) != std::string::npos) {
                        cout << "Book " << i + 1 << ": " << book_titles.at(i) << ", Author: "
                            << book_authors.at(i) << " Published: " << publication_years.at(i) << endl;
                        found = true;
                    }
                }
                if (!found)
                    cout << "No book found matching the Keyword: " << search_keyword << endl;
            }
            cout << "--------------------------------------------------------------------------\n" << endl;
        }
        else if (choice == '4') {
            if (bookCount == 0) {
                cout << "The library is empty, no books to delete." << endl;
            }
            else {
                string temp_delete_word;
                cout << "Enter the title of the book, you want to delete: ";
                getline(cin, temp_delete_word);
                cout << "----------------------" << endl;

                bool deleted = false;
                for (size_t i{ 0 }; i < bookCount; ++i) {
                    if (temp_delete_word == book_titles[i]) {
                        for (size_t j{ i }; j < bookCount - 1; ++j) {
                            book_titles.at(j) = book_titles.at(j + 1);
                            book_authors.at(j) = book_authors.at(j + 1);
                            publication_years.at(j) = publication_years.at(j + 1);
                        }
                        bookCount--;
                        deleted = true;
                        break;
                    }
                }
                if (!deleted)
                    cout << "Book \"" << temp_delete_word << "\" not found. Title does not match any book." << endl;
                else
                    cout << "Book \"" << temp_delete_word << "\" " << "has been deleted successfully." << endl;
            }
            cout << "--------------------------------------------------------------------------\n" << endl;
        }
    } while (choice != '5');

    cout << endl;
    return 0;
}