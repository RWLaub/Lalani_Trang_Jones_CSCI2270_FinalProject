#ifndef QUIZME_H
#define QUIZME_H
#include <iostream>
#include <vector>

struct FlashCard {

    std::string key;
    std::string definition;
    FlashCard *next;
    FlashCard *previous;
    FlashCard() {}
    FlashCard(std::string k, std::string def) {
        key = k;
        definition = def;
        next = NULL;
        previous = NULL;
    }
};

class QuizMe {

    public:
        QuizMe();
        ~QuizMe();
        void buildSample();
        void addCard(std::string key, std::string definition);
        void findCard(std::string key);
        void deleteCard(std::string key);
        void printAll();
        void deleteAll();
        void editCard(std::string key,std::string newkey,std::string newdefinition);
        void uploadCards();
        void quiz();
        void total();
        bool isEmpty();

    protected:

    private:
        FlashCard *head;
        FlashCard *current;

};

#endif // QUIZME_H
