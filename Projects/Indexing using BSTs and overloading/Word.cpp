/**************************************************************
 * File:    Word.cpp
 * Project: CMSC 341 - Project 2 - Index Creator
 * Author : Kusum Sharma
 * Date   : 17-June-2020
 * Section: 01
 * E-mail:  ks17@umbc.edu
 *************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Word.h"
using namespace std;

Word::Word(){
  count = 0;
  wordText = "";
  type = "";
}

Word::Word(string inWord, int lineNumber){
  count = 0;
  lineNumber = lineNumbers.empty();
  wordText = inWord;
  type = "";
}

void Word::CountWord(int lineNumber){
  //check queue size
  if (lineNumbers.size() == 0){
    lineNumbers.push(lineNumber);}
  else if (lineNumbers.back() != lineNumber){
    lineNumbers.push(lineNumber);
  }
  //add count
  count++;
}

string Word::GetWord() const{
  return wordText;
}

queue<int>Word::GetLine() const{
  return lineNumbers;}

string Word::GetWordType() const{
  return type;
}

void Word::SetWordType(const string& bst){
  type = bst;
}

int Word::GetCount()const{
  return count;}

bool operator< (const Word &LHS,const Word &RHS){
  if (LHS.GetWord() < RHS.GetWord())
    return true;
  else
    return false;
}

Word Word::operator= (const Word &RHS){
  wordText = RHS.wordText;
  lineNumbers = RHS.lineNumbers;
  return *this;
}

bool Word::operator== (const Word &RHS){
 
  if ((wordText == RHS.wordText) && (lineNumbers == RHS.lineNumbers))
    return true;
  else
    return false;
}

ostream& operator<< (ostream &out, const Word &inWord){
  int numCh = 24; // 24 characters from the start to the :
  int size;
  size = sizeof(inWord);
  int end = 3; //last three spaces for count
  if (inWord.GetWordType() == "i"){
    out << inWord.GetWord();
    while ( numCh > (size+end)){
      out << ".";
      numCh--;
    }
    if (inWord.GetCount() < 10){
      out<<".";}
    out << inWord.GetCount() << ":";
    
    while(!(inWord.GetLine()).empty()){
      out<<(inWord.GetLine()).front()<<" ";
      (inWord.GetLine()).pop();}
  }
  else{
    out << inWord.GetWord();}
  out << endl;
  return out;
}

/*private:
  int count;
  queue<int> lineNumbers;
  string wordText;
*/
