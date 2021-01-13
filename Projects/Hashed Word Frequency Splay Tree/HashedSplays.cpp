#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include "Exceptions.h"
#include "SplayTree.h"
#include "Node.h"
#include "HashedSplays.h"

using namespace std;

HashedSplays::HashedSplays(int size){
  m_trees = size;
  table = new SplayTree<Node>[size];
}

HashedSplays::~HashedSplays(){
  delete[] table;
}

void HashedSplays::FileReader(string inFileName){
  string inLine;
  //open the given file
  ifstream myFile;
  myFile.open(inFileName.c_str());

  //if file is invalid throw exception
  if(!myFile){
    throw IllegalArgumentException();
  }
  
  cout << "Building hashed splay..." << endl;
  while(getline(myFile, inLine)){
    string word;

    //analyze the line of words using istringstream
    istringstream iss(inLine);

    while( iss>>word){
      string newWord = "";
      int length = word.length();
      
      for(int i = 0; i < length; i++) {
	if(isalpha(word.at(i)) || (word.at(i) == '-'|| (word.at(i) == '\''))) {
	  newWord += word.at(i);
	}
      }
      //call strip in Util
      newWord = Util::Strip(newWord);
      
      string str1; //first letter of the string
      
      if(newWord.length() > 0) {
	
	//remove \ if its the first character of the string
	if(newWord.at(0) == '\''){
	  newWord = newWord.substr(1, newWord.length() - 1);
	}
	
	//get the first letter	  
	str1 = newWord.at(0);

	//get the index of first letter
	int index = GetIndex(str1);
	
	if(index >= 0 && index <= 25){
	  //insert word and increase frequency
	  Node newNode(newWord, 0);
	  if(!table[index].contains(newNode)){
	    table[index].insert(newNode);
	  }
	  table[index].frequency(newNode);
	}
      }
    }
  }
  myFile.close();
}

void HashedSplays::PrintTree(int index){
  int minBound = 0;
  int maxBound = 25; //maximun number of alphabet
  
  //if index isnt valid throw exception
  if (index < minBound || index > maxBound){
    throw ArrayIndexOutOfBoundsException();
  }
  
  //print tree and the number of splays
  table[index].printTree();
  cout <<"This tree has had " << table[index].GetNumSplays() << " splays."<<endl;
  
}

void HashedSplays::PrintTree(string letter){
  int minBound = 0;
  int maxBound = 25;

  int i = GetIndex(letter);
  //if not invalid index
  if (i != -1){
    if (i >= minBound && i <= maxBound){
      table[i].printTree();
      cout << "This tree has had " << table[i].GetNumSplays()<< " splays." << endl;
    }
    
    else{
      throw ArrayIndexOutOfBoundsException();}
  }
}

void HashedSplays::PrintHashCounts(){
  
  for (int i = 0; i < m_trees-1; i++){
    //print the root of the tree
    table[i].printRoot();}
}

void HashedSplays::FindAll(string inPart){
  
  cout << "Printing the results of nodes that start with \'" << inPart << "\'" << endl;
  
  int i = GetIndex(inPart);
  
    //Check if index is valid
    if(i < 0 || i > 25) {
      throw ArrayIndexOutOfBoundsException();
    }
    
    //make all string lowercase and create a new node
    string newWord = Util::Lower(inPart);
    Node node(newWord, 0);
    
    //search for matches and print them
    table[i].printMatch(node);
}
 

int HashedSplays::GetIndex(string inLetter){

  int capStart = 65;
  int capEnd = 90;
  int smallStart = 97;
  int smallEnd = 122;
  //convert into char for ASCII value
  char letter = inLetter.at(0);

  //check if it is uppercase
  if( letter <= capEnd && letter >= capStart){
    return letter-capStart;
  }
  else if( letter <= smallEnd && letter >= smallStart){
    return letter - smallStart;
  }
  else{
    return -1;
    } 
}
