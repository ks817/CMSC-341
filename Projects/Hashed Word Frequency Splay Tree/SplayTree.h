#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include "dsexceptions.h"
#include "Node.h"
#include <iostream>        // For NULL
using namespace std;

// SplayTree class
//
// CONSTRUCTION: with no parameters
//
// ******************PUBLIC OPERATIONS**************************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// void printRoot( )      --> Print root and the number of nodes
// ******************ERRORS**************************************
// Throws UnderflowException as warranted

template <typename Comparable>
class SplayTree
{
  public:
    SplayTree( )
    {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = nullNode;
	numNodes = 0;
	numSplays = 0;
    }

    SplayTree( const SplayTree & rhs )
    {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = nullNode;
        *this = rhs;
    }

    ~SplayTree( )
    {
        makeEmpty( );
        delete nullNode;
    }

    /**
     * Find the smallest item in the tree.
     * Not the most efficient implementation (uses two passes), but has correct
     *     amortized behavior.
     * A good alternative is to first call find with parameter
     *     smaller than any item in the tree, then call findMin.
     * Return the smallest item or throw UnderflowException if empty.
     */
    const Comparable & findMin( )
    {
        if( isEmpty( ) )
            throw UnderflowException( );

        BinaryNode *ptr = root;

        while( ptr->left != nullNode )
            ptr = ptr->left;

        splay( ptr->element, root );
        return ptr->element;
    }

    /**
     * Find the largest item in the tree.
     * Not the most efficient implementation (uses two passes), but has correct
     *     amortized behavior.
     * A good alternative is to first call find with parameter
     *     larger than any item in the tree, then call findMax.
     * Return the largest item or throw UnderflowException if empty.
     */
    const Comparable & findMax( )
    {
        if( isEmpty( ) )
            throw UnderflowException( );

        BinaryNode *ptr = root;

        while( ptr->right != nullNode )
            ptr = ptr->right;

        splay( ptr->element, root );
        return ptr->element;
    }


    bool contains( const Comparable & x )
    {
        if( isEmpty( ) )
            return false;
        splay( x, root );
        return root->element == x;
    }
  
  //added fuction
  //searches the tree for matches and returns Node 
  const Comparable search(const Comparable & x)
  {
    //numSplays++;
    //if tree is empty return Node("",1)
    if (isEmpty()){
      cout << "Empty Tree" << endl;
      return Node("", 1);
    }  
    else{
      //call splay
      splay(x, root);
      return root->element;
    }
  }
  
  //added fuction
  //looks for matches and prints them
  void printMatch(const Comparable &x) {
    while(!this->isEmpty()) {
      //add frequency
      frequency(x);
      //look for matches and get a node to compare using search()
      Comparable match = search(x);
      string str = Util::Lower(match.GetWord().substr(0, x.GetWord().size()));
      //compare
      if(str == x.GetWord()) {
	cout << match << endl;
      }
      remove(match);
    }
  }
  
  bool isEmpty( ) const
  {
    return root == nullNode;
  }

  //added fuction
  //bootstrap printRoot() to call private printRoot()
  void printRoot() const
  {
    printRoot(root);
  }
  
  void printTree( ) const
  {
    if( isEmpty( ) )
      cout << "Empty tree" << endl;
    else
      printTree( root );
  }

    void makeEmpty( )
    {
    /******************************
     * Comment this out, because it is prone to excessive
     * recursion on degenerate trees. Use alternate algorithm.
        
        reclaimMemory( root );
        root = nullNode;
     *******************************/
        while( !isEmpty( ) )
        {
            findMax( );        // Splay max item to root
            remove( root->element );
        }
    }
  
  //added fuction 
  //bootstrap insert method ; made given insert() private
  void insert( const Comparable & x ){
    insert(x, this->root);
  }
  
  //added fuction 
  //counts frequency
  void frequency( const Comparable & x ){
    //if same increase frequency                                               
    if (root->element == x){
      this->root->element.IncrementFrequency();
    }
   }
  
  /*  void insert( const Comparable & x)
    {
      //frequency(x);
      //numSplays++;
        static BinaryNode *newNode = NULL;

        if( newNode == NULL )
            newNode = new BinaryNode;
        newNode->element = x;

        if( root == nullNode )
        {
            newNode->left = newNode->right = nullNode;
            root = newNode;
        }
        else
        {
            splay( x, root );
            if( x < root->element )
            {
                newNode->left = root->left;
                newNode->right = root;
                root->left = nullNode;
                root = newNode;
            }
            else
            if( root->element < x )
            {
                newNode->right = root->right;
                newNode->left = root;
                root->right = nullNode;
                root = newNode;
            }
            else
                return;
        }

        newNode = NULL;   // So next insert will call new
	numNodes++;

	}*/
  
    void remove( const Comparable & x )
    {
        BinaryNode *newTree;

            // If x is found, it will be at the root
        if( !contains( x ) )
            return;   // Item not found; do nothing

        if( root->left == nullNode )
            newTree = root->right;
        else
        {
            // Find the maximum in the left subtree
            // Splay it to the root; and then attach right child
            newTree = root->left;
            splay( x, newTree );
            newTree->right = root->right;
        }
        delete root;
	numNodes--;
        root = newTree;
    }

  const SplayTree & operator=( const SplayTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }

        return *this;
    }
  
  //int GetNumNodes ()
  //{
  //return numNodes;
  //}

  //added fuction
  //returns number of splays
  int GetNumSplays ()
  {
    return numSplays;
  }
 

private:
  //keep track of the number of nodes and splays to print later
    int numNodes = 0;
    int numSplays = 0;
  
    struct BinaryNode
    {
        Comparable  element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( ) : left( NULL ), right( NULL ) { }
        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
            : element( theElement ), left( lt ), right( rt ) { }
    };

    BinaryNode *root;
    BinaryNode *nullNode;

    /**
     * Internal method to reclaim internal nodes in subtree t.
     * WARNING: This is prone to running out of stack space.
     */
    void reclaimMemory( BinaryNode * t )
    {
        if( t != t->left )
        {
            reclaimMemory( t->left );
            reclaimMemory( t->right );
            delete t;
        }
    }
    
    /**
     * Internal method to print a subtree t in sorted order.
     * WARNING: This is prone to running out of stack space.
     */
   void printTree( BinaryNode *t ) const
    {
        if( t != t->left )
        {
            printTree( t->left );
            cout << t->element << endl;
            printTree( t->right );
        }
    }
  
  //added fuction
  //checks if tree is empty else prints root
  void printRoot( BinaryNode *t ) const
  {
    if( isEmpty( ) ){
      cout << "This tree starts with has no nodes." <<endl;
    }
    else
      {
        cout <<"This tree starts with " << t->element <<"and has : "<< numNodes << " nodes." << endl;
      }
  }

  
    /**
     * Internal method to clone subtree.
     * WARNING: This is prone to running out of stack space.
     */
    BinaryNode * clone( BinaryNode * t ) const
    {
        if( t == t->left )  // Cannot test against nullNode!!!
            return nullNode;
        else
            return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
    }

        // Tree manipulations
    void rotateWithLeftChild( BinaryNode * & k2 )
    {
        BinaryNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }

    void rotateWithRightChild( BinaryNode * & k1 )
    {
        BinaryNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }
    void insert( const Comparable & x, BinaryNode*& t)
    {
      //frequency(x);                                                          
      //numSplays++;                                                            
        static BinaryNode *newNode = NULL;

        if( newNode == NULL )
            newNode = new BinaryNode;
        newNode->element = x;

        if( root == nullNode )
        {
            newNode->left = newNode->right = nullNode;
            root = newNode;
        }
        else
        {
            splay( x, t );
            if( x < root->element )
            {
                newNode->left = root->left;
                newNode->right = root;
                root->left = nullNode;
                root = newNode;
            }
            else
            if( root->element < x )
            {
                newNode->right = root->right;
                newNode->left = root;
                root->right = nullNode;
                root = newNode;
            }
            else
                return;
        }

        newNode = NULL;   // So next insert will call new                       
        numNodes++;

    }
     /**
     * Internal method to perform a top-down splay.
     * The last accessed node becomes the new root.
     * This method may be overridden to use a different
     * splaying algorithm, however, the splay tree code
     * depends on the accessed item going to the root.
     * x is the target item to splay around.
     * t is the root of the subtree to splay.
     */
    void splay( const Comparable & x, BinaryNode * & t )
  {
       
        BinaryNode *leftTreeMax, *rightTreeMin;
        static BinaryNode header;

        header.left = header.right = nullNode;
        leftTreeMax = rightTreeMin = &header;

        nullNode->element = x;   // Guarantee a match

        for( ; ; )
            if( x < t->element )
            {
                if( x < t->left->element )
                    rotateWithLeftChild( t );
                if( t->left == nullNode )
                    break;
                // Link Right
                rightTreeMin->left = t;
                rightTreeMin = t;
                t = t->left;
            }
            else if( t->element < x )
            {
                if( t->right->element < x )
                    rotateWithRightChild( t );
                if( t->right == nullNode )
                    break;
                // Link Left
                leftTreeMax->right = t;
                leftTreeMax = t;
                t = t->right;
            }
            else
                break;

        leftTreeMax->right = t->left;
        rightTreeMin->left = t->right;
        t->left = header.right;
        t->right = header.left;
	numSplays++;
    }
};

#endif
