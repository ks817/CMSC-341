/* File: Driver.cpp
   UMBC CMSC 341 Summer 2020 Project 1
   Basic tests for the Llama class.
   This driver program tests Llama Stacks using strings.
*/

#include "Llama.h"
#include <iostream>
#include <string>
using namespace std ;

int main() {

  Llama<string, 5> str;
  
  cout <<"\n**** Push Test ***\n";
  cout << " push bc\n";
  cout << " push um\n";
  cout << " push r\n";
  cout << " push io\n";
  cout << " push ju\n";
  cout << " push rma\n";
  cout << " push sha\n";
  cout << " push m\n";
  cout << " push su\n";
  cout << " push ku\n";
  
  str.push("bc");
  str.push("um");
  str.push("r");
  str.push("io");
  str.push("jun");

  str.push("rma");
  str.push("sha");
  str.push("m");
  str.push("su");
  str.push("ku");

  str.push("341");
  str.push("cmsc");

  str.dump();
  
  string s;

  cout<< "\n**** Pop Test ***\n";
  s = str.pop();
  cout<< "popped " << s << endl;
  s = str.pop();
  cout<< "popped " << s << endl;
  s = str.pop();
  cout<< "popped " << s << endl;
  s= str.pop();
  cout<< "popped " << s << endl;
  s= str.pop();
  cout<< "popped " << s << endl;
  
  str.dump();

  cout<< "\n**** Pop Test ***\n";
  s = str.pop();
  cout<< "popped " << s	<< endl;
  s = str.pop();
  cout<< "popped " << s	<< endl;

  str.dump();

  //test copy constructor
  Llama<string, 5> st(str);
  st.dump();
  
  cout<< "\n**** Pop Test //copy constructor****\n";
  cout << "pop in copied stack\n";
  cout<< "\n**** Pop Test ***\n";
  s = st.pop();
  cout<< "popped " << s	<< endl;
  s = st.pop();
  cout<< "popped " << s	<< endl;
  s = st.pop();
  cout<< "popped " << s	<< endl;
  
  st.dump();

  cout<<"\n*** Overloaded = Test ***\n";
  cout<<"Sets new stack(st) = old stack(str)\n";
  st = str;
  st.dump();

  //pop the rest of str
  cout<< "\n**** Pop Test ***\n";
  s = str.pop();
  cout<< "popped " << s	<< endl;
  s = str.pop();
  cout<< "popped " << s	<< endl;
  s = str.pop();
  cout<< "popped " << s << endl;
  s = str.pop();
  cout<< "popped " << s << endl;
  s = str.pop();
  cout << "popped " << s << endl;
  
  try{
    s = st.pop();
    cout << "popped " << s << endl;}
  catch(LlamaUnderflow &e){
    cout << "\n****************************"<<endl;
    cout<< "Llama Stack error: "<< e.what() << endl;
    cout << "****************************\n" << endl;}

  cout << "\n***** Dup Exception Test *****\n";
  try{
    st.dup();}
  catch(LlamaUnderflow &e){
    cout << "\n****************************"<<endl;
    cout<< "Llama Stack error: " << e.what() << endl;
    cout << "****************************\n" << endl;}

  st.dump();

  str.push("hi");
  str.push("hello");
  str.push("namaste");
  str.push("annyeonghaseyo");
  str.push("hola");

  str.dump();
  
  cout<< "\n**** Peek Test ***\n";
  s = str.peek(0);
  cout<< "peeked " << s << endl;
  s = str.peek(1);
  cout<< "peeked " << s << endl;
  s = str.peek(2);
  cout<< "peeked " << s << endl;
  s= str.peek(3);
  cout<< "peeked " << s << endl;
  s= str.peek(4);
  cout<< "peeked " << s << endl;

  try{
    s = str.peek(5);
    cout << "peeked " << s << endl;}
  catch(LlamaUnderflow &e){
    cout << "\n****************************"<<endl;
    cout<< "Llama Stack error: " << e.what() << endl;
    cout << "****************************\n" << endl;}
  
  str.dump();
  
  cout<< "\n**** Swap Test ***\n";
  str.swap();
  str.dump();
  
  cout<< "\n**** Dup Test ***\n";
  str.dup();
  str.dump();
  
  cout<< "\n**** Rot Test ***\n";
  str.rot();
  str.dump();
  
  return 0;
}
