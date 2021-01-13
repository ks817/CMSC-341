/**************************************************************                
 * File:    Indexer.h 
 * Project: CMSC 341 - Project 2 - Index Creator
 * Author : Kusum Sharma
 * Date   : 17-June-2020
 * Section: Lecture-01
 * E-mail:  ks17@umbc.edu
 * 
 * Indexer Class definition.
 **************************************************************/

#ifndef INDEXER_H
#define INDEXER_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "BinarySearchTree.h"
#include "Word.h"
using namespace std;

class Indexer {
 public:
  Indexer(string filterName, string dataFile);
  void DoIndex();
  bool FileExists(char* filename);
  template <typename Comparable>
  BinarySearchTree<Comparable> FileFilterReader(string filename);
  template <typename Comparable>
  BinarySearchTree<Comparable> FileWordReader(string filename);
  string RemovePunct(string &word);

 private:
  BinarySearchTree<Word> *filteredBST;
  BinarySearchTree<Word> *indexedBST;
  string datafile;
  string filterfile;
};
#endif
