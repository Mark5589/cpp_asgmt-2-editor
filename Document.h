//
// Created by mark  gurin on 2019-04-17.
//

#ifndef TRAGIL2_EDITOR_DOCUMENT_H
#define TRAGIL2_EDITOR_DOCUMENT_H

#include "string"
#include "vector"

class Document {

private:
    std::vector<std::string> mDocumentStrings;
    int mCurrentLine;

public:
    Document();
    void setCurrentLine(const int&);
    void incCurrentLine();
    void insertLineByIndex(const int&,const std::string&);
    void insertNewLine(const std::string& s, const int& place);
    void changeCurrentDocumentLine(const std::string&);
    void deleteCurrentElement();
    int getCurrentLine() const;
    int getDocumentLinesNum();
    std::string getDocumentLine();
    std::vector<std::string> getDocument();

    bool setNewString(const std::string&,const std::string&);
};


#endif //TRAGIL2_EDITOR_DOCUMENT_H
