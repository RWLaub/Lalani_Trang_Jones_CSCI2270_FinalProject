#include "QuizMe.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

/******************************
    FUNCTION PROTOTYPES
******************************/

void readFile(string file);
int displayMenu();

/******************************
         VARIABLES
******************************/

QuizMe test;

/******************************
           MAIN
******************************/

int main(int argc, char* argv[]) {

    test.buildSample(); // Creates a sample card for the user

    readFile(argv[1]); // Reads the text file for any saved cards

    int option = 0; // What option the user selects from menu

    // Important variables:
    string front;
    string back;
    string newkey;
    string newdef;

    while(option != 10) {

        option = displayMenu();

        if(option == 1) {

            // Add a card

            cout << "Front of card:" << endl;
            //cin.ignore(); Ignoring the first char
            getline(cin, front);
            cout << "Back of card:" << endl;
            getline(cin, back);
            cout << front << " " << back << endl;
            test.addCard(front, back);

        } else if(option == 2) {

            // Upload new cards

            test.uploadCards(); // Sends to text file

        } else if(option == 3) {

            // Find card

            cout << "Front of card:" << endl;
            cin.ignore();
            getline(cin, front);

            test.findCard(front);

        } else if(option == 4) {

            // Edit card

            cout << "Front of card to edit:" << endl;
            cin.ignore();
            getline(cin, front);
            cout << "Change front to:" << endl;
            getline(cin, newkey);
            cout << "Change back to:" << endl;
            getline(cin, newdef);
            test.editCard(front, newkey, newdef);

        } else if(option == 5) {

            // Print all cards

            test.printAll();

        } else if(option == 6) {

            // Delete a card

            cout << "Front of card:" << endl;
            cin.ignore();
            getline(cin, front);
            test.deleteCard(front);

        } else if(option == 7) {

            // Delete all cards

            test.deleteAll(); // Deletes from text file as well

        } else if(option == 8) {

            // Get the total number of cards

            test.total();

        } else if(option == 9) {

            // Quiz yourself!

            test.quiz();

        } else if(option == 10) {

            // Quit

            cout << "Goodbye!" << endl;

        }

    }

}

/******************************
          MENU
******************************/

int displayMenu() {

    cout << "*** MENU ***" << endl;
    cout << "1. Add card" << endl;
    cout << "2. Upload cards" << endl;
    cout << "3. Find card" << endl;
    cout << "4. Edit card" << endl;
    cout << "5. Print all cards" << endl;
    cout << "6. Delete card" << endl;
    cout << "7. Delete all cards" << endl;
    cout << "8. Count cards" << endl;
    cout << "9. Quiz Me!" << endl;
    cout << "10. Quit" << endl;

    int option;
    cin >> option;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return option;
}

/*************************
       FILE VOODOO
*************************/

void readFile(string file) {

  ifstream inFile;

	string line;
	string word;

    int wordCount;

    string key;
    string definition;

	inFile.open(file);

	if(inFile.good()) {

		while(getline(inFile, line)) {

			stringstream ss(line);
            wordCount = 0;

			while(getline(ss, word, ',')) {

                // First word is front, second is back

                wordCount++;

                if(wordCount == 1) {

                    key = word;

                } else {

                    definition = word;
                    test.addCard(key, definition);

                }

            }

        }

	} else {

		cout << "Error opening the file!" << endl;

	}

	inFile.close();

}
