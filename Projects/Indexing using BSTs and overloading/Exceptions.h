/**************************************************************
 * File:    Exceptions.h
 * Project: CMSC 341 - Project 2 - Index Creator
 * Author : Kusum Sharma
 * Date   : 17-June-2020
 * Section: Lecture-01
 * E-mail:  ks17@umbc.edu
 *
 * MyExceptions Class definition.
 *
 *************************************************************/
#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
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

    /**********************************************************************
     * Name: GetMessage
     * PreCondition: None.  
     * 
     * PostCondition:  Returns error message.
     *********************************************************************/
    const std::string GetMessage() { return m_message; }
    
private:
    
    std::string m_message; //Error message.
};

#endif
