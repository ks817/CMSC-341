/**************************************************************                
 * File:    Word.h    
 * Project: CMSC 341 - Project 2 - Index Creator
 * Author : Kusum Sharma
 * Date   : 17-June-2020
 * Section: Lecture-01
 * E-mail:  ks17@umbc.edu
 *                                                                
 * Word Class definition.
 **************************************************************/

#ifndef WORD_H
#define WORD_H
#include <string>
#include <queue>
using namespace std;

class Word {
public:
  
  Word();
  Word(string inWord, int lineNumber = 0);
  void CountWord(int lineNumber);
  string GetWord() const;
  queue<int>GetLine() const;
  string GetWordType() const;
  void SetWordType(const string &bst);
  int GetCount() const;
  friend bool operator< (const Word &LHS, const Word &RHS);
  Word operator= (const Word &RHS);
  bool operator== (const Word &RHS);
  friend ostream& operator <<(ostream &out, const Word &inWord);

private:
  int count;
  queue<int> lineNumbers;
  string wordText;
  string type;
};

#endif
