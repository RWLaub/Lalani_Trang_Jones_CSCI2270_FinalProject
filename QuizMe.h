#ifndef QUIZME_H
#define QUIZME_H
#include <iostream>
#include <vector>

struct FlashCard {

    std::string key;
    std::string definition;
    FlashCard *next;
    FlashCard *previous;

};

class QuizMe {

    public:
        QuizMe();
        ~QuizMe();
        void buildSample();
        void addCard(std::string key, std::string definition);
        void findCard(std::string key, std::string definition);
        void deleteCard(std::string key);
        void printAll();
        void deleteAll();
        void editCard(std::string key);
        void uploadCards();
        void quiz();

    protected:

    private:
        FlashCard *head;
        FlashCard *current;

};

#endif // QUIZME_H