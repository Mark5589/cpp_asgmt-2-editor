//
// Created by mark  gurin on 2019-04-17.
// Editor - terminal UI - operate the loop() methods which waits to user input
// after the input the right method from Document should be fired
//
/**
 * links
 * string to char* - https://stackoverflow.com/questions/7352099/stdstring-to-char
 * */

#ifndef TRAGIL2_EDITOR_EDITOR_H
#define TRAGIL2_EDITOR_EDITOR_H

#include "Document.h"
#include <iostream>




class Editor {
public:
    enum class Command{p, n , perP , number, a, i, c, d, TEXT, sOldNew, Q ,unDefine, starter, stopWrite};

    /** : enum command : (all commands should be entered with lower case chars.)
 * P - print the current line
 * N - prints line number of current line followed by TAB followed by current line
 * (%P) perP - prints all lines
 *(7) SEVEN - makes line #7 the current line
 * A - appends new text after the current line
 * I - inserts new text before the current line
 * C - changes the current line for text that follows
 * D - deletes the current line
 *(/text) TEXT - searches forward after current line for the specified text.The search wraps to the beginning of the buffer and continues down to the current line, if necessary
 *(s/old/new) sOldNew - replaces old string with new in current line(google:C++splitortoken)
 * Q - Quits the editor without saving*/
private:
    Document mDocument;
    Command mCurrCommand;
    std::string mUserInput;
    int isNumber(const std::string&);
    int isStringSwichOldNew(const std::string&);
    void commandHandler(const Command& cmd, const std::string& s);

    void commandP();
    void commandN();
    void commandPerP();
    void commandNumber(const std::string &s);
    void commandA();
    void commandI();
    void commandC();
    void commandD();
    void commandTEXT(const std::string& s);
    void commandREPLACE(const std::string&);
//    void commandQ();


public:
    Editor();
    void loop();
    Command inputToCommand(const std::string&);


};





#endif //TRAGIL2_EDITOR_EDITOR_H
