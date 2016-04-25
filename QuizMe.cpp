#include "QuizMe.h"
#include <iostream>
#include <fstream>
using namespace std;

QuizMe::QuizMe() {

    head = NULL;
    current = NULL;

}

QuizMe::~QuizMe() {


}

void QuizMe::buildSample() {

    string sampleKey = "What is the meaning of life?";
    string sampleDefinition = "42";

    FlashCard *card = new FlashCard;
    card -> key = sampleKey;
    card -> definition = sampleDefinition;
    card -> next = NULL;
    head = card;

}

void QuizMe::addCard(string key, string definition) {

    current = head;
    FlashCard *card = new FlashCard;

    if(head == NULL){
        card -> key = key;
        card -> definition = definition;
        card -> next = NULL;
        card -> previous = NULL;
        head = card;
        return;
    }
    else {

        while(current -> next != NULL) {

            current = current -> next;

        }

    }


    card -> key = key;
    card -> definition = definition;
    card -> next = NULL;
    current -> next = card;
    card -> previous = current;

}

void QuizMe::printAll() {

    current = head;
    if (head == NULL){
        cout << "You have no cards!" << endl;
        return;
    }
    else{
        while(current != NULL) {

            cout << current -> key << " " << current -> definition << endl;
            current = current -> next;

        }
    }

}

void QuizMe::uploadCards() {

    current = head -> next;

    ofstream file;
    file.open ("quizcards.txt");

    while(current != NULL) {

        file << current -> key;
        file << ",";
        file << current -> definition << "\n";
        current = current -> next;

    }

    file.close();
    cout << "Successfully uploaded to file." << endl;

}

void QuizMe::deleteCard(string key) {

	bool found = false;
	FlashCard *del = new FlashCard;
	FlashCard *search = new FlashCard;
	search = head;

	// find the flashCard to delete
	while (!found && search != NULL) {
		if (search->key == key) {
			found = true;
		}
		else {
			search = search->next;
		}
	}

	if (found) {
		if(head -> next == NULL){
            del = head;
            head -> next = NULL;
            head -> previous = NULL;
            head = NULL;
            delete del;
		}
		else{
		if (search == head) {
			del = head;
			head = head->next;
			head->previous = NULL;
			delete del;
		}
		// if the deleted node is a head
		else if (search->next == NULL) {
			search->previous->next = NULL;
			delete search;
		}
		// otherwise just rearrange the pointers.
		else {
			search->previous->next = search->next;
			search->next->previous = search->previous;
			delete search;
		}
		}
	}
	else {
		cout << "The card: " << key << " does not exist" << endl;
	}
}

void QuizMe::deleteAll() {

	FlashCard *temp = new FlashCard;

	while(head != NULL) {

		temp = head;
		head = head->next;
		cout << "Deleting card: " << temp->key << endl;
		delete temp;

	}
	head = NULL;
	current = NULL;

    ofstream ofs;
    ofs.open("quizcards.txt", ofstream::out | ofstream::trunc);
    ofs.close();

}

void QuizMe::quiz() {
    if(head == NULL){
        cout << "You have no cards!" << endl;
    }
    else{
    current = head;
    double right = 0;
    double wrong = 0;

    while(current != NULL) {

        string answer;
        cout << current -> key << endl;
        cin.ignore();
        getline(cin, answer);

        if(current->definition.compare(answer) != 0) {

            cout << "WRONG ANSWER!" << endl;
            wrong++;

        } else {

            cout << "CORRECT!" << endl;
            right++;

        }

        current = current -> next;

    }

    cout << "You got " << right << " right and " << wrong << " wrong." << endl;
    cout << "Overall score: " << (right/(right+wrong))*100 << "%" << endl;
    }
}

void QuizMe::findCard(string key) {
    FlashCard *ptr = head;
    bool found = false;
    while (ptr != NULL){
        if (ptr->key==key){
            cout << "Back of card: " << endl;
            cout << ptr->definition << endl;
            found = true;
        }
        ptr = ptr->next;
    }
    if (!found){
        cout << "Card not found" << endl;
    }
}

void QuizMe::editCard(string key,string newkey, string newdef){

    FlashCard *ptr = head;
    bool found = false;
    while (ptr != NULL){
        if (ptr->key==key){
            ptr->key = newkey;
            ptr->definition = newdef;
            found = true;
            cout << "Successfully changed card." << endl;
        }
        ptr = ptr->next;
    }
    if (!found){
        cout << "Card not found" << endl;
    }

}

void QuizMe::total(){
    int counter = 0;
    FlashCard *ptr = head;
    while (ptr != NULL){
        counter++;
        ptr=ptr->next;
    }
    cout << "Total number of cards: " << counter << endl;
}
