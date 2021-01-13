#ifndef _LLAMA_H_
#define _LLAMA_H_

/* File: Llama.h
   This file has the class declaration for the LlamaNode class
   for Project 1. See project description for details.
   You may add public and private data members to the Llama class.
   You may add public and private member functions to the Llama class.
*/


#include <stdexcept>
#include <string>
#include "LlamaNode.h"

using namespace std ;


class LlamaUnderflow : public std::out_of_range {

   public:

   LlamaUnderflow(const string& what) : std::out_of_range(what) { }

} ;


template <class T, int LN_SIZE>
class Llama {

   public:
  
  // Name: Llama()
  // Desc: this is the default constructor for the Llama class
  // PreCondition: N/A
  // PostCondition: creates a new LlamaNode and initializes pvt variables
   Llama() ;
  
  // Name: Llama(const Llama<T,LN_SIZE>& other)
  // Desc: this is the copy constructor for the Llama class
  // PreCondition: other has Llama object
  // PostCondition: it makes a complete copy of the Llama Stack given in the
  //                parameter 
   Llama(const Llama<T,LN_SIZE>& other) ;   // copy constructor

  // Name: ~Llama()
  // Desc: this is a destructor for the Llama class
  // PreCondition: there is an existing llamaNode
  // PostCondition: all dynamically allocated memory associated with
  //                the host object are deallocated
   ~Llama() ;

  // Name: size()
  // Desc: returns the number of items in the Llama Stack.
  // PreCondition: N/A
  // PostCondition: returns m_size
  int size() ;
  
  // Name: dump()
  // Desc: used for debugging
  // PreCondition: N/A
  // PostCondition: print out all pertinent information regarding the host
  //                Llama stack to cerr, including the number of LlamaNodes
  //                that have ever been created and destroyed
   void dump() ;

  // Name: push(const T& data)
  // Desc: adds data to the top of the stack
  // PreCondition: A copy of data should be made
  // PostCondition: the data is added to the top of the stack
   void push(const T& data) ;
  
  // Name: pop()
  // Desc: removes and returns the item at the top of the Llama Stack
  // PreCondition: N/A
  // PostCondition: removes and returns the item at the top of the Llama Stack
  //                and if stack is empty,throws a LlamaUnderflow exception
   T pop() ;

  // Name: dup()
  // Desc: duplicates the top of the stack
  // PreCondition: N/A
  // PostCondition: dups items or throws LlamaUnderflow
   void dup() ;    //  (top) A B C D -> A A B C D
  
  // Name: swap()
  // Desc: exchanges the top two items of the stack
  // PreCondition: N/A
  // PostCondition: swaps items or throws LlamaUnderflow
   void swap() ;   //  (top) A B C D -> B A C D

  // Name: rot()
  // Desc: permutes the top three items of the stack
  // PreCondition: N/A
  // PostCondition: rotates top three elements or throws LlamaUnderflow
   void rot() ;    //  (top) A B C D -> C A B D

  // Name: peek(int offset)
  // Desc: returns the value of an item in the stack
  // PreCondition: offset must be an integer
  // PostCondition: returns peeked items at offset pos
   T peek(int offset) const ;


  // Name: const Llama<T,LN_SIZE>& operator=(const Llama<T,LN_SIZE>& rhs)
  // Desc: this is the overloaded assignment operator
  // PreCondition: rhs has Llama object
  // PostCondition: A complete copy of the right hand side of the assignment
  //                is placed in the host object
   const Llama<T,LN_SIZE>& operator=(const Llama<T,LN_SIZE>& rhs) ;

   private:
  
   //
   // Add your private member functions & private data mebers here:
   //
  LlamaNode<T, LN_SIZE>* m_ptr; // pointer 
  LlamaNode<T, LN_SIZE>* m_extra; // extra node pointer
  int m_size;
  int m_sizeNode;
  int m_capacity;
  int  m_index; //set it equal to -1 
  bool isExtra; //true when there is an extra node
} ;


#include "Llama.cpp"


#endif
