#ifndef HASHEDSPLAYS_H
#define HASHEDSPLAYS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include "Exceptions.h"
#include "SplayTree.h"
#include "Node.h"

using namespace std;
class HashedSplays {

 public:
  HashedSplays(int size);
  ~HashedSplays();
  void FileReader(string inFileName);
  void PrintTree(int index);
  void PrintTree(string letter);
  void PrintHashCounts();
  void FindAll(string inPart);
  int GetIndex(string inLetter);

 private:
  SplayTree<Node> *table;
  int m_trees;
};

#endif

