# QuizMe

## Project Summary
QuizMe is a program that allows you to quiz yourself through virtual flashcards. You can add, delete, and edit cards, while also have the obvious ability of testing yourself through the flashcards. The program uses a linked list to store all the cards. The user can choose to upload the cards onto the included text file so the program may pull these cards every time it is run. Enjoy.

## How	to	Run
Download the files from this repo and run the following on a terminal:

For OSX:
```
g++ -std=c++11 Main.cpp QuizMe.cpp
./a.out quizcards.txt
```

For Windows:
```
g++ -std=c++11 Main.cpp QuizMe.cpp
./a.exe quizcards.txt
```

## Dependencies

## System Requirements
This program works for Windows, OSX, and Linux.

## Group	Members
Faisal Lalani <br />
Phi Trang <br />
Adam Jones <br />

## Contributors
Ryan Hartsfield

##Changes
1. Fixed cin.ignore() bug
2. Fixed non-standard input -> infinite loop
3. Added constructors to FlashCard struct
4. Modified code to reflect above change
5. Removed some possible memory leaks in delete methods

## Open	Issues/Bugs
1. Error message for people not adding a text file at command line
