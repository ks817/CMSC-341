#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "BinarySearchTree.h"
#include "Indexer.h"
#include "Word.h"

using namespace std;

Indexer::Indexer(string filterName, string dataFile){
  filterfile = filterName;
  datafile = dataFile;
  //filterfile = "gsl.txt";
  //datafile = "input1.txt";
  filteredBST = new BinarySearchTree<Word>();
  indexedBST = new BinarySearchTree<Word>();
  //  char* c = const_cast<char*>(filterfile.c_str());
  //FileExists(c);
}

//will build the BSTs and show the proper output.  This method should not
//directly do the work but should be using other methods you define.
void Indexer::DoIndex(){
  //a)	Build the filteredBST.
  //b)	Build the indexedBST.
  //c)	Output the results.

  //convert char to string
  char* filter = const_cast<char*>(filterfile.c_str());
  char* data = const_cast<char*>(datafile.c_str());

  if (FileExists(filter) && FileExists(data)){
    ofstream filtered;
    filtered.open("filterResults.txt");
    *filteredBST = FileFilterReader<Word>(filterfile);
    filteredBST->printTree();
    filtered.close();
    
    ofstream indexed;
    indexed.open("input.txt");
    *indexedBST = FileWordReader<Word>(datafile);
    indexedBST->printTree();
    indexed.close();
  }
  else{
    cout<<"Exceptions"<<endl;}
  //destruct
  delete filteredBST;
  filteredBST = nullptr;
  delete indexedBST;
  indexedBST = nullptr;  
}

bool Indexer::FileExists(char* filename){
  string words;
  //convert char into a string
  //char* filename = const_cast<char*>(filename.c_str());
  ifstream myFile;
  myFile.open(filename);
  if (myFile.fail())
    return false;
  cout<<"file exists? " <<(bool)myFile<<endl;
  myFile.close();
  return true;
}

template<typename Comparable>
BinarySearchTree<Comparable> Indexer::FileFilterReader(string filename){
  string words;
  ifstream myFile;
  myFile.open(filename);
  while (myFile>>words){
    Word filter = Word(words);
    //set type to filtered tree
    filter.SetWordType("f");
    filteredBST->insert(words);
  }
  myFile.close();
  return *filteredBST;
}

template<typename Comparable>
BinarySearchTree<Comparable> Indexer::FileWordReader(string filename){
  ifstream myFile;
  myFile.open(filename);
  string line = "";
  string space = " ";
  string words = "";
  string newWord = "";
  int count = 0;                                                               
  while(!myFile.eof()){ //while not end of the file
    getline(myFile, line);
    count ++;
    for(int i = 0; i < sizeof(line); i++){
      if(line[i] == space[0]){
	words = "";
      }
      else{
	words = words + words[i];
      }
    }
    //make words lowercase and remove puct;
    newWord = RemovePunct(words);
    //check to see if word should be filtered out
    Word wordObj = Word(newWord);
    wordObj.SetWordType("i"); //set type to indexed tree
    if (!filteredBST->contains(newWord)){
      //word.setCurrLineNum(count);
      indexedBST->insert(wordObj);
    }
  myFile.close();
  return *indexedBST;
  }
}

string RemovePunct(string &word){
  string newWord;
  string lowerCase = "";
  //lowerCase = tolower(word[0]);
  for (int i = 0; i < sizeof(word); i++){
    if (!ispunct(word[i])){
      newWord += word[i];}
  }
  for (int j = 0; j< sizeof(newWord); j++){
    lowerCase = tolower(newWord[j]);
  }
  return lowerCase;
}
  
// private:
//BinarySearchTree<Word> filteredBST;
//BinarySearchTree<Word> indexedBST;
//string datafile;
//string filterfile;
