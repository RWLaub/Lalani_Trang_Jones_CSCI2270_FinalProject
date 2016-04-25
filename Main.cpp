#include "QuizMe.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
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

    test.buildSample();

    readFile(argv[1]);

    int option = 0;
    string front;
    string back;
    string newkey;
    string newdef;

    while(option != 10) {

        option = displayMenu();

        if(option == 1) {

            cout << "Front of card:" << endl;
            cin.ignore();
            getline(cin, front);
            cout << "Back of card:" << endl;
            getline(cin, back);
            test.addCard(front, back);

        } else if(option == 2) {

            test.uploadCards();

        } else if(option == 3) {

            cout << "Front of card:" << endl;
            cin.ignore();
            getline(cin, front);

            test.findCard(front);

        } else if(option == 4) {

            cout << "Front of card to edit:" << endl;
            cin.ignore();
            getline(cin, front);
            cout << "Change front to:" << endl;
            //cin.ignore();
            getline(cin, newkey);
            cout << "Change back to:" << endl;
            //cin.ignore();
            getline(cin, newdef);
            test.editCard(front, newkey, newdef);

        } else if(option == 5) {

            test.printAll();

        } else if(option == 6) {

            cout << "Front of card:" << endl;
            cin.ignore();
            getline(cin, front);
            test.deleteCard(front);

        } else if(option == 7) {

            test.deleteAll();

        } else if(option == 8) {

            test.total();

        } else if(option == 9) {

            test.quiz();

        } else if(option == 10) {

            cout << "Goodbye!" << endl;

        }

    }

}

/******************************
          HELPERS
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
