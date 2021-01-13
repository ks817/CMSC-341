#ifndef DS_EXCEPTIONS_H
#define DS_EXCEPTIONS_H

#include <iostream>
#include "Exceptions.h"

using namespace std;

class UnderflowException: public Exceptions {
public:
  UnderflowException() throw() : Exceptions("Underflow exception"){}
  virtual string GetMessage(){
    return m_message;
  }
};

class IllegalArgumentException: public Exceptions {
public:
  IllegalArgumentException() throw() : Exceptions("Illegal Argument Exception"){}
  virtual string GetMessage(){
    return m_message;
  }
};

class ArrayIndexOutOfBoundsException: public Exceptions {
public:
  ArrayIndexOutOfBoundsException() throw() : Exceptions("Array index is out of bound"){}
  virtual string GetMessage(){
    return m_message;
  }
};

class IteratorOutOfBoundsException: public Exceptions {
public:
  IteratorOutOfBoundsException() throw() : Exceptions("Iterator is Out Of Bounds Exception"){}
  virtual string GetMessage(){
    return m_message;
  }
};

class IteratorMismatchException: public Exceptions {
public:
  IteratorMismatchException() throw() : Exceptions("Iterator Mismatch Exception"){}
  virtual string GetMessage(){
    return m_message;
  }
};

class IteratorUninitializedException: public Exceptions {
public:
  IteratorUninitializedException() throw() : Exceptions("Iterator Uninitialized Exception"){}
  virtual string GetMessage(){
    return m_message;
  }
};

#endif

