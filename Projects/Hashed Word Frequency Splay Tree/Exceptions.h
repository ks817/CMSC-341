/**************************************************************                
 * File:    Exceptions.h                                                       
 * Project: CMSC 341 - Project 3  
 * Author : Kusum Sharma                                                
 * Date   : 12-July-2020
 * Section: Lecture-01                                                        
 * E-mail:  ks17@umbc.edu                                                      
 * 
 * Exceptions Class definition.                                               
 *
 *************************************************************/
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>

class Exceptions {
public:
    /**********************************************************************
     * Name: MyExceptions (Constructor)     
     * PreCondition: String containing error description.
     *                       
     * PostCondition:  Error object
     *********************************************************************/
    Exceptions(std::string message): m_message(message) {
    }
  virtual ~Exceptions() throw() {}
    /**********************************************************************
     * Name: GetMessage
     * PreCondition: None.
     *
     * PostCondition:  Returns error message.
     *********************************************************************/
  virtual  std::string GetMessage()= 0;
  //{ return m_message; }

  //private:
  std::string m_message; //Error message.
};

#endif
