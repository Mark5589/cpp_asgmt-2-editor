//
// Created by mark  gurin on 2019-04-17.
//

#include "Editor.h"
#include <unistd.h>
#include <string>
#include <iostream>
//usleep(1000000);

using namespace std;


Editor::Editor() {
    std::cout << "editor constructor" << std::endl;
    mDocument;
    this->mUserInput = "";
    this->mCurrCommand = Command::unDefine;
    loop();
}

void Editor::loop() {
    std::string userInput;

    while (this->mCurrCommand != Command::Q) {
        getline(cin, userInput);
        Command c = inputToCommand(userInput);
        this->mCurrCommand = c;

        if(this->mCurrCommand == Command::Q) break;


        commandHandler(this->mCurrCommand, userInput);
        if(this->mCurrCommand != Command::unDefine && c == Command::a){
            commandHandler(this->mCurrCommand, this->mUserInput);
        }
    }

}

Editor::Command Editor::inputToCommand(const std::string &input) {
    if (isNumber(input) != -1) return Command::number;
    else if (isStringSwichOldNew(input) == 1) return Command::sOldNew; // s/Old/New
    else if (input.compare("i") == 0) return Command::i;
    else if (input.compare("p") == 0) return Command::p;
    else if (input.compare("n") == 0) return Command::n;
    else if (input.compare("a") == 0) return Command::a;
    else if (input.compare("%p") == 0) return Command::perP;
    else if (input.compare("c") == 0) return Command::c;
    else if (input.compare("d") == 0) return Command::d;
    else if (input.compare("Q") == 0) return Command::Q;
    else if (input.compare("/text") == 0) return Command::TEXT;
    else return Command::unDefine;
}

int Editor::isNumber(const string &input) {
    std::string::const_iterator it = input.begin();
    while (it != input.end() && std::isdigit(*it)) ++it;
    if (!input.empty() && it == input.end()) {
        return std::stoi(input);
    }
    return -1;
}

int Editor::isStringSwichOldNew(const std::string &s) {
    std::string delimiter = "/";
    if (s.at(0) == 's' && s.at(1) == '/') {
        return 1;
    }
    return -1;
}

void Editor::commandHandler(const Editor::Command &c, const std::string &s) {

        if(Command::p == c ){
            commandP();
        }
        else if(Command::n == c ){
            commandN();
        }
        else if(Command::perP == c ){
            commandPerP();
        }
        else if(Command::number == c ){
            commandNumber(s);
        }
        else if(Command::a == c ){
            commandA();
        }
        else if(Command::i == c ){
            commandI();
        }
        else if(Command::c == c){
            commandC();
        }
        else if(Command::d == c ){
            commandD();
        }
        else if(Command::TEXT == c ){

        }
        else if(Command::sOldNew == c ){
            commandREPLACE(s);
        }
        else{
            __throw_logic_error("[-]command not found");
        }
}


void Editor::commandP() {
    cout << this->mDocument.getDocumentLine() << endl;
}

void Editor::commandN() {
    cout << this->mDocument.getCurrentLine()  << "\t" << this->mDocument.getDocumentLine() << endl;
}

void Editor::commandPerP() {
    cout << "[command %P]" << endl;
    for (int i = 0; i < this->mDocument.getDocumentLinesNum(); ++i) {
        cout << this->mDocument.getDocument().at(i) << endl;
    }

}

void Editor::commandNumber(const std::string &s) {
    cout << "[command Number]" << endl;

    // Sets new current line
    int line = isNumber(s);
    this->mDocument.setCurrentLine(line);
    std::cout << this->mDocument.getDocumentLine() << std::endl;

}

void Editor::commandA() {
    cout << "[commandA]" << endl;
    string input;
    bool firstEnter = true;
    getline(cin, input);
    Command c = inputToCommand(input);
    while(c == Command::unDefine){
        if(firstEnter){
            firstEnter = false;
            this->mDocument.insertNewLine(input, 1);
        }
        getline(cin, input);
        c = inputToCommand(input);
        if(c == Command::unDefine) {this->mDocument.insertNewLine(input,1 );}
        else {
            this->mCurrCommand = c;
            this->mUserInput = input;
            break;
        }
    }
}

void Editor::commandI() {
    cout << "[commandI]" << endl;
    string input;
    getline(cin ,input);
    this->mDocument.insertNewLine(input, 0);
}

void Editor::commandC() {
    cout << "[commandC]" << endl;
    string input;
    getline(cin, input);
    this->mDocument.changeCurrentDocumentLine(input);
}

void Editor::commandD() {
    cout << "[commandD]"<<endl;
    this->mDocument.deleteCurrentElement();
}

void Editor::commandREPLACE(const string& s) {
    std::string tmpp = s;
    char *cstr = &tmpp[0u];
    std::vector<char *> vec;
    char *token = std::strtok(cstr, "/");
    while (token != NULL) {
        vec.push_back(token);
        token = std::strtok(NULL, "/");
    }
    if(vec.size() == 3 && (*vec.at(0) == 's')){
        // old string at(1) , new at(2) - find old start and end index
        std::string currS = this->mDocument.getDocumentLine();
//        std::string currS = "hellllo world";
        std::size_t pos = currS.find(vec.at(1));
        std::string changedString = currS.substr(0,pos) + vec.at(2) + currS.substr(pos + (strlen(vec.at(1)))); // begin to pos + at(2) + begin + sizeAt(2) to end
        this->mDocument.changeCurrentDocumentLine(changedString);

    }


}

//void Editor::commandTEXT() {
//
//}
