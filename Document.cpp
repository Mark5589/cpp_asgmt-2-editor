//
// Created by mark  gurin on 2019-04-17.
// backend API that deal with user calls.
//

#include "Document.h"
#include <iostream>
#include <algorithm>

Document::Document() {
    this->mCurrentLine = 0;
//    std::cout << "documetn counstruct" << std::endl;
}

void Document::setCurrentLine(const int & index) {
    if(this->mDocumentStrings.size() >= index){
        this->mCurrentLine = index;
    }
}

int Document::getCurrentLine() const {
    return this->mCurrentLine;
}

std::string Document::getDocumentLine() {
    if(this->mDocumentStrings.size() == 0) return "";

    if(this->mCurrentLine == 0){
        return this->mDocumentStrings.at(this->mCurrentLine );
    }
    return this->mDocumentStrings.at(this->mCurrentLine -1); // -1 testing
}

bool Document::setNewString(const std::string& old, const std::string& newString){
    std::string curString = this->mDocumentStrings.at(this->mCurrentLine);


    return false;
}

int Document::getDocumentLinesNum() {
    return this->mDocumentStrings.size();
}

std::vector<std::string> Document::getDocument() {
    return this->mDocumentStrings;
}

void Document::incCurrentLine() {
    this->mCurrentLine += 1;
}

void Document::insertLineByIndex(const int& index, const std::string& s) {
    if(index > this->mCurrentLine){
        this->mDocumentStrings.push_back(s);
        this->mCurrentLine = this->mDocumentStrings.size() - 1;
    }else if(index < this->mCurrentLine){ // before the current line.
        this->mDocumentStrings.insert(this->mDocumentStrings.begin() + this->mCurrentLine -1 , s);
    }
}

void Document::insertNewLine(const std::string& s, const int& place){
    int before = 0;
    int after = 1;
    if(place == after){ // append new string after the current.
        this->mDocumentStrings.insert(this->mDocumentStrings.begin() + getCurrentLine(), s);
        incCurrentLine();

    }else if(place == before){  // insert before the current line.
        this->mDocumentStrings.insert(this->mDocumentStrings.begin() + getCurrentLine() - 1, s);

    }
}

void Document::changeCurrentDocumentLine(const std::string &s) {
    this->mDocumentStrings[this->mCurrentLine -1] = s;
}

void Document::deleteCurrentElement() {
    this->mDocumentStrings.erase(this->mDocumentStrings.begin() + this->mCurrentLine - 1);
    if(this->mCurrentLine != 1) {this->mCurrentLine--;}

}

std::string Document::getLineByIndex(const int & i) {

    return this->mDocumentStrings[i];
}




