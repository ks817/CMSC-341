/* File: Llama.cpp
   Short for Linked-List Array Mixed Amalgamated Stack
*/
#ifndef LLAMA_CPP
#define LLAMA_CPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "LlamaNode.h"
#include "Llama.h"

using namespace std ;

// Name: Llama()
// Desc: this is the default constructor for the Llama class
// PreCondition: N/A
// PostCondition: creates a new LlamaNode and initializes pvt variables
template <class T, int LN_SIZE>
Llama<T, LN_SIZE>::Llama(){
  m_ptr = new LlamaNode<T, LN_SIZE>;
  m_ptr->m_next = nullptr; //set ptr to equal null
  m_extra = nullptr;
  m_size = 0; //starting size
  m_sizeNode = LN_SIZE; //set the node's size equal LN_SIZE
  m_capacity = m_sizeNode;
  m_index = -1; 
  isExtra = false;
}

// Name: Llama(const Llama<T,LN_SIZE>& other)
// Desc: this is the copy constructor for the Llama class
// PreCondition: other has Llama object  
// PostCondition: it makes a complete copy of the Llama Stack given in the
//                parameter
template <class T, int LN_SIZE>
Llama<T, LN_SIZE>::Llama(const Llama<T,LN_SIZE>& other) { //copy constructor
  
  LlamaNode<T, LN_SIZE>* node, *top, *curr;
  node = nullptr;
  top = nullptr;
  curr = nullptr;

  curr = new LlamaNode<T, LN_SIZE>;
  top = curr;
  m_ptr = curr;

  //if there is extra node
  if(other.isExtra) {
    node = new LlamaNode<T, LN_SIZE>;
    m_extra = node;
    m_extra->m_next = top;
    isExtra = true;}
  
  //call other stack and see if it isnt empty
  if (other.m_size != 0) {
    for (int i = 0; i < LN_SIZE; i++) {
      m_ptr->arr[i] = other.m_ptr->arr[i];
    }
    LlamaNode<T, LN_SIZE>* otherNode = other.m_ptr;
    while (otherNode->m_next != nullptr) {
    curr = new LlamaNode<T, LN_SIZE>;
    curr->m_next = nullptr;
    m_ptr->m_next = curr;
    m_ptr = m_ptr->m_next;
    curr = nullptr;
    otherNode = otherNode->m_next;
    for (int j = 0; j < LN_SIZE; j++) {
      m_ptr->arr[j] = otherNode->arr[j];}}

  //update pvt variables
  m_ptr = top; 
  m_index = other.m_index;
  m_size = other.m_size;
  m_sizeNode = other.m_sizeNode;
  m_capacity = other.m_capacity;
  isExtra = other.isExtra;
  }
}

// Name: ~Llama()
// Desc: this is a destructor for the Llama class
// PreCondition: there is an existing llamaNode
// PostCondition: all dynamically allocated memory associated with
//                the host object are deallocated
template <class T, int LN_SIZE>
Llama<T, LN_SIZE>::~Llama() {

  //if there is an extra node, delete it
  if (isExtra) {
    delete m_extra;
    m_extra = nullptr;}
  
  while (m_ptr != nullptr) {
    LlamaNode<T, LN_SIZE>* node;
    node = m_ptr->m_next;
    delete m_ptr;
    m_ptr = node;}
  
  m_ptr = nullptr;
}

//template <class T, int LN_SIZE>
//bool Llama<T, LN_SIZE>::isFull() const {
//return (m_sizeNode >= LN_SIZE);
//}

// Name: size()
// Desc: returns the number of items in the Llama Stack. 
// PreCondition: N/A
// PostCondition: returns m_size 
template <class T, int LN_SIZE>
int Llama<T, LN_SIZE>::size() {
  return m_size; //return the size of the stack
}

// Name: dump()
// Desc: used for debugging
// PreCondition: N/A
// PostCondition: print out all pertinent information regarding the host
//                Llama stack to cerr, including the number of LlamaNodes
//                that have ever been created and destroyed
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::dump() {

  int index = m_index;

  cout << "***** Llama Stack Dump ******" << "\nLN_SIZE = " << m_sizeNode <<
    "\n# of items in the stack = "<< m_size << "\n# of nodes created = " <<
    m_ptr->newCount << "\n# of nodes destroyed " << m_ptr->deleteCount << "\n\n";
  
  if (isExtra)
    cout << "This stack has an extra node: "<<&m_ptr->arr[index]<<"\n\n";
  
  else
    cout << "This stack does not have an extra node.\n\n";
  
  if (m_ptr != nullptr) {

    LlamaNode<T, LN_SIZE>* node = m_ptr;
    cout << "Stack contents, top to bottom" << endl;
    
    while (node != nullptr) {
      cout << "----- " << node << " -----\n";
      while (index >= 0){
	cout << node->arr[index]<<endl;
	index--;
	//m_index++;
      }
      //move on to next node
      node = node->m_next;
      index = m_sizeNode - 1;
    }
  }
  cout << "----- bottom of stack -----\n\n";
  cout << "*****************************\n";
  
}

// Name: push(const T& data)
// Desc: adds data to the top of the stack
// PreCondition: A copy of data should be made
// PostCondition: the data is added to the top of the stack
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::push(const T& data) {
  //  int index = -1;
  //make copy of the data
  T copy = data;
  
  //check if node is full; if not then push copy
  if (m_index < (m_sizeNode-1)){
    m_ptr->arr[++m_index] = copy;
    //    cout <<"   main : "<< m_ptr->arr[m_index] <<endl;
  }
  
  else {
    m_index = 0;
    // check if extra else create a new node
    if(!isExtra){
      LlamaNode<T, LN_SIZE>* node = new LlamaNode<T, LN_SIZE>;
      //m_capacity += m_sizeNode;
      node->m_next = m_ptr;
      m_ptr = node;
      m_ptr->arr[m_index] = copy;
      // m_index++;
      //cout<<"not extra///" << m_ptr->arr[m_index]<< " -> " << endl;
    }
    
    // if there is extra node then set m_ptr equal to extra
    if(isExtra){
      m_extra->m_next = m_ptr;
      m_ptr = m_extra;
      m_extra = NULL;
      isExtra = false; //there is no more extra node
      m_ptr->arr[m_index] = copy;
      //++m_index;
      //cout<<"extra///" << m_ptr->arr[m_index]<< " -> ";
    }
    else{
      m_ptr->arr[m_index]=copy;
    }
  }
  m_size++;
}

// Name: pop()
// Desc: removes and returns the item at the top of the Llama Stack
// PreCondition: N/A
// PostCondition: removes and returns the item at the top of the Llama Stack
//                and if stack is empty,throws a LlamaUnderflow exception
template <class T, int LN_SIZE>
T Llama<T, LN_SIZE>::pop() {
  
  int halfNode = (m_sizeNode/2);
  //check if stack is empty by checking m_index and m_ptr
  if (m_index == -1 && (m_ptr->m_next == nullptr)){
    m_size = 0;
    throw LlamaUnderflow ("Stack is empty.");
  }

  //if stack isnt empty and only the 1st requirement is met
  else if (m_index == -1) {
    if ((!isExtra) && ( m_ptr->m_next != nullptr)) {
      m_extra = m_ptr;
      m_ptr = m_ptr->m_next;
      m_index = m_sizeNode - 1;
      isExtra = true;
    }
  }
  
  T pop = m_ptr->arr[m_index--];
  //if it is extra and m_index is less than half of node's size
  if ((isExtra) && m_index < halfNode) {
    m_extra->m_next = nullptr;
    delete m_extra;
    m_extra = nullptr;
    isExtra = false;
    m_capacity -= m_sizeNode;
  }

  //if not extra , not null and m_index equals -1
  if ((!isExtra) && (m_ptr->m_next != nullptr)&&(m_index == -1)) {
    isExtra = true;
    m_extra = m_ptr;
    m_ptr = m_ptr->m_next;
    m_index = (m_sizeNode - 1);
  }
  m_size--;
  return pop;
}

// Name: dup()
// Desc: duplicates the top of the stack
// PreCondition: N/A
// PostCondition: dups items or throws LlamaUnderflow
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::dup() {    //  (top) A B C D -> A A B C D

  // if the stack is empty, throw a LlamaUnderflow exception. 
  if (m_size == 0)
    throw LlamaUnderflow("Cannot dup an empty stack.");

  else
    this->push(m_ptr->arr[m_index]);
}

// Name: swap()
// Desc: exchanges the top two items of the stack
// PreCondition: N/A
// PostCondition: swaps items or throws LlamaUnderflow
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::swap() {   //  (top) A B C D -> B A C D

  int twoItems = 2;

  //if there are fewer than two items in the stack, throw a LlamaUnderflow exception. 
  if (m_size < twoItems) {
    throw LlamaUnderflow("Stack has fewer than two items so cannot swap."); }
    
  else {
    T item1 = this->pop();
    T item2 = this->pop();
    this->push(item1);
    this->push(item2); }
}

// Name: rot()
// Desc: permutes the top three items of the stack
// PreCondition: N/A
// PostCondition: rotates top three elements or throws LlamaUnderflow
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::rot() {    //  (top) A B C D -> C A B D

  int threeItems = 3;
  
  //if there are fewer than three items in the stack, throw a LlamaUnderflow exception
  if (m_size < threeItems) {
    throw LlamaUnderflow("Stack has fewer than three items so cannot rotate."); }
  
  else{
    //pop the 3 items
    T item1 = this->pop(); 
    T item2 = this->pop();
    T item3 = this->pop();

    //rotate
    this->push(item2); 
    this->push(item1);
    this->push(item3); }
}

// Name: peek(int offset)
// Desc: returns the value of an item in the stack
// PreCondition: offset must be an integer
// PostCondition: returns peeked items at offset pos
template <class T, int LN_SIZE>
T Llama<T, LN_SIZE>::peek(int offset) const {
  int count = 0;
  int index = (m_index - offset);
  T peeked;
  int mod = (m_size % m_sizeNode);
  int max = mod + m_sizeNode ;
  LlamaNode<T, LN_SIZE>* node = m_ptr;
  
  //if the offset is too large, peek() should throw a LlamaUnderflow exception
  if (offset > (m_size - 1)) {
    throw LlamaUnderflow("offset is too high for peek");}

  
  //if offset is less than, return 
  if (offset < mod){
    //cout <<"printing from peek "<< node->arr[index]<< endl;
    peeked = node->arr[index];
    return peeked;
  }
  
  while (offset > (max-1)) {
    node = node->m_next;
    max += m_sizeNode; //increase capacity
    count++;}
  peeked = node->arr[max-offset-1]; //return the element this index
  return peeked;
}

// Name: const Llama<T,LN_SIZE>& operator=(const Llama<T,LN_SIZE>& rhs)
// Desc: this is the overloaded assignment operator
// PreCondition: rhs has Llama object
// PostCondition: A complete copy of the right hand side of the assignment
//                is placed in the host object
template <class T, int LN_SIZE>
const Llama<T,LN_SIZE>& Llama<T, LN_SIZE>:: operator=(const Llama<T,LN_SIZE>& rhs) {

  if (this != &rhs) {

    // if its an extra node delete it and set equal to nullptr
    if (isExtra){
      delete m_extra;
      m_extra = nullptr;}
    
    while (m_ptr != nullptr) {
      LlamaNode<T, LN_SIZE>* temp;
      temp = m_ptr->m_next;
      delete m_ptr;
      m_ptr = temp;}
    
    m_ptr = nullptr;

    LlamaNode<T, LN_SIZE>* node, *top, *curr;
    node = nullptr;
    top = nullptr;
    curr = nullptr;
    //LlamaNode<T, LN_SIZE>* node, top, curr = nullptr;
    //copy
    curr = new LlamaNode<T, LN_SIZE>;
    top = curr;
    m_ptr = curr;   
    if(rhs.isExtra) {
      node = new LlamaNode<T, LN_SIZE>;
      m_extra = node;
      m_extra->m_next = top;
      isExtra = true;}
    
    //call other stack and see if it isnt empty
    if (rhs.m_size != 0) {
      for (int i = 0; i < LN_SIZE; i++) {
	m_ptr->arr[i] = rhs.m_ptr->arr[i];
      }
      LlamaNode<T, LN_SIZE>* otherNode = rhs.m_ptr;
      while (otherNode->m_next != nullptr) {
	curr = new LlamaNode<T, LN_SIZE>;
	curr->m_next = nullptr;
	m_ptr->m_next = curr;
	m_ptr = m_ptr->m_next;
	curr = nullptr;
	otherNode = otherNode->m_next;
	for (int j = 0; j < LN_SIZE; j++) {
	  m_ptr->arr[j] = otherNode->arr[j];}}
      
      //update pvt variables
      m_ptr = top; 
      m_index = rhs.m_index;
      m_size = rhs.m_size;
      m_sizeNode = rhs.m_sizeNode;
      m_capacity = rhs.m_capacity;
      isExtra = rhs.isExtra;
    }
  }
  return *this;  
}

#endif
