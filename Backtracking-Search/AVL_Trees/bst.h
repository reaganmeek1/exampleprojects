#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>

/**
 * A templated class for a Node in a search tree.
 * The getters for parent/left/right are virtual so
 * that they can be overridden for future kinds of
 * search trees, such as Red Black trees, Splay trees,
 * and AVL trees.
 */
template <typename Key, typename Value>
class Node
{
public:
    Node(const Key& key, const Value& value, Node<Key, Value>* parent);
    virtual ~Node();

    const std::pair<const Key, Value>& getItem() const; // get item to see if its in the list, cannot edit
    std::pair<const Key, Value>& getItem();//get item to edit it
    const Key& getKey() const;
    const Value& getValue() const; //get value to see it , not edit
    Value& getValue(); // get value to edit it -- location is value, change location

    virtual Node<Key, Value>* getParent() const;
    virtual Node<Key, Value>* getLeft() const;
    virtual Node<Key, Value>* getRight() const;

    void setParent(Node<Key, Value>* parent);
    void setLeft(Node<Key, Value>* left);
    void setRight(Node<Key, Value>* right);
    void setValue(const Value &value);

protected:
    std::pair<const Key, Value> item_; //item is each node in the list
    Node<Key, Value>* parent_;
    Node<Key, Value>* left_;
    Node<Key, Value>* right_;
};

/*
  -----------------------------------------
  Begin implementations for the Node class.
  -----------------------------------------
*/

/**
* Explicit constructor for a node.
*/

//makes  a node
template<typename Key, typename Value>
Node<Key, Value>::Node(const Key& key, const Value& value, Node<Key, Value>* parent) :
    item_(key, value),
    parent_(parent),
    left_(NULL),
    right_(NULL)
{

}

/**
* Destructor, which does not need to do anything since the pointers inside of a node
* are only used as references to existing nodes. The nodes pointed to by parent/left/right
* are freed by the BinarySearchTree.
*/
template<typename Key, typename Value>
Node<Key, Value>::~Node()
{
    //clear();


    

}

/**
* A const getter for the item.
*/
template<typename Key, typename Value>
const std::pair<const Key, Value>& Node<Key, Value>::getItem() const
{
    return item_;
}

/**
* A non-const getter for the item.
*/
template<typename Key, typename Value>
std::pair<const Key, Value>& Node<Key, Value>::getItem()
{
    return item_;
}

/**
* A const getter for the key.
*/
template<typename Key, typename Value>
const Key& Node<Key, Value>::getKey() const
{
    return item_.first;
}

/**
* A const getter for the value.
*/
template<typename Key, typename Value>
const Value& Node<Key, Value>::getValue() const
{
    return item_.second;
}

/**
* A non-const getter for the value.
*/
template<typename Key, typename Value>
Value& Node<Key, Value>::getValue()
{
    return item_.second;
}

/**
* An implementation of the virtual function for retreiving the parent.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getParent() const
{
    return parent_;
}

/**
* An implementation of the virtual function for retreiving the left child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getLeft() const
{
    return left_;
}

/**
* An implementation of the virtual function for retreiving the right child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getRight() const
{
    return right_;
}

/**
* A setter for setting the parent of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setParent(Node<Key, Value>* parent)
{
    parent_ = parent;
}

/**
* A setter for setting the left child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setLeft(Node<Key, Value>* left)
{
    left_ = left;
}

/**
* A setter for setting the right child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setRight(Node<Key, Value>* right)
{
    right_ = right;
}

/**
* A setter for the value of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setValue(const Value& value)
{
    item_.second = value;
}

/*
  ---------------------------------------
  End implementations for the Node class.
  ---------------------------------------
*/

/**
* A templated unbalanced binary search tree.
*/
template <typename Key, typename Value>
class BinarySearchTree
{
public:
    BinarySearchTree(); //TODO
    virtual ~BinarySearchTree(); //TODO
    virtual void insert(const std::pair<const Key, Value>& keyValuePair); //TODO
    virtual void remove(const Key& key); //TODO
    void clear(); //TODO
    void clear_node(Node<Key,Value>* node);
    bool isBalanced() const; //TODO
    bool isBalancedHelp(Node<Key,Value>* root) const;
    void print() const;
    bool empty() const;

    template<typename PPKey, typename PPValue>
    friend void prettyPrintBST(BinarySearchTree<PPKey, PPValue> & tree);
public:
    /**
    * An internal iterator class for traversing the contents of the BST.
    */
    class iterator  // TODO
    {
    public:
        iterator();

        std::pair<const Key,Value>& operator*() const;
        std::pair<const Key,Value>* operator->() const;

        bool operator==(const iterator& rhs) const;
        bool operator!=(const iterator& rhs) const;

        iterator& operator++();

    protected:
        friend class BinarySearchTree<Key, Value>;
        iterator(Node<Key,Value>* ptr);
        Node<Key, Value> *current_;//current value of the iterator
    };

public:
    iterator begin() const;
    iterator end() const;
    iterator find(const Key& key) const;
    Value& operator[](const Key& key);
    Value const & operator[](const Key& key) const;

protected:
    // Mandatory helper functions
    Node<Key, Value>* internalFind(const Key& k) const; // TODO
    Node<Key, Value> *getSmallestNode() const;  // TODO
    static Node<Key, Value>* predecessor(Node<Key, Value>* current); // TODO
    // Note:  static means these functions don't have a "this" pointer
    //        and instead just use the input argument.

    // Provided helper functions
    virtual void printRoot (Node<Key, Value> *r) const;
    virtual void nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2) ;

    // Add helper functions here
    static Node<Key, Value>* successor(Node<Key, Value>* currernt);


protected:
    Node<Key, Value>* root_;
    // You should not need other data members
};

/*
--------------------------------------------------------------
Begin implementations for the BinarySearchTree::iterator class.
---------------------------------------------------------------
*/

/**
* Explicit constructor that initializes an iterator with a given node pointer.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator(Node<Key,Value> *ptr)
{
    // TODO
    // std::cout<<"it. constructor long" << std::endl;
    current_ = ptr;



    //constructor just needs to set 
    //iterator is a class that wraps around a pointer
    //use iterator to go around avl tree
    //current is a pointer to a node, so can get a value at each node

    //call successor() to incrememnt the iterator
    
}

/**
* A default constructor that initializes the iterator to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator() 
{

    // TODO
    // std::cout<<"it. constructor " << std::endl;
    
    //initialize iterator to null
    current_ = NULL;


    //



}

/**
* Provides access to the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> &
BinarySearchTree<Key, Value>::iterator::operator*() const
{
    return current_->getItem();
}

/**
* Provides access to the address of the item.
*/


// for one of them and keep looking for successor and return it, call successor (you have to make it)
//successor is smallest node thats buggest than current node, so get the first/second, so the key. 

template<class Key, class Value>
std::pair<const Key,Value> *
BinarySearchTree<Key, Value>::iterator::operator->() const
{
    return &(current_->getItem());
}

/**
* Checks if 'this' iterator's internals have the same value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator==(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO

    if(this->current_ == NULL && rhs.current_ == NULL){ 
        // std::cout << "not equals 1" << std::endl;
        return true;


    }
    else if(this->current_ == NULL || rhs.current_ == NULL)
    {
        // std::cout << "not equals 2" << std::endl;
        return false;
    }
    
   else if(this->current_->getValue() == rhs.current_->getValue()){
        return true;
    }
    else{
        return false;
    }

    //return address
    //== , compare addresses correctly
    //can't comapre keys, but comapre the pointers to each other
}

/**
* Checks if 'this' iterator's internals have a different value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator!=(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    //rhs just passed by reference so use dot operator
    // TODO
    // std::cout << "not equals" << std::endl;
    // std::cout << "this arrow current = " << this->current_ << std::endl;
    // std::cout << "rhs  = " << rhs.current_ << std::endl;
    if(this->current_ == NULL && rhs.current_ == NULL){
        // std::cout << "not equals 1" << std::endl;
        return false;


    }
    else if(this->current_ == NULL || rhs.current_ == NULL)
    {
        // std::cout << "not equals 2" << std::endl;
        return true;
    }
    
    else if(this->current_->getValue() == rhs.current_->getValue()){
        // std::cout << "not equals 3" << std::endl;
        return false;
    }
    else{
        // std::cout << "not equals 4" << std::endl;
        return true;
    }

    //

}


/**
* Advances the iterator's location using an in-order sequencing
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator&
BinarySearchTree<Key, Value>::iterator::operator++()
{
    // TODO
    //there is a helper function to help with ++
    //this is when you use the successor
   
    current_ = successor(current_);
   // return current_;


}

//make pred and succ before making iterator


/*
-------------------------------------------------------------
End implementations for the BinarySearchTree::iterator class.
-------------------------------------------------------------
*/

/*
-----------------------------------------------------
Begin implementations for the BinarySearchTree class.
-----------------------------------------------------
*/

/**
* Default constructor for a BinarySearchTree, which sets the root to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::BinarySearchTree() 
{
    // TODO
    //set the root to null
    root_ = nullptr;
    //
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree()
{
    // TODO

}

/**
 * Returns true if tree is empty
*/
template<class Key, class Value>
bool BinarySearchTree<Key, Value>::empty() const
{
    return root_ == NULL;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::print() const
{
    printRoot(root_);
    std::cout << "\n";
}

/**
* Returns an iterator to the "smallest" item in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::begin() const
{
    
    BinarySearchTree<Key, Value>::iterator begin(getSmallestNode());
    return begin;
}

/**
* Returns an iterator whose value means INVALID
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::end() const
{
    BinarySearchTree<Key, Value>::iterator end(NULL);
    return end;
}

/**
* Returns an iterator to the item with the given key, k
* or the end iterator if k does not exist in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::find(const Key & k) const
{
    Node<Key, Value> *curr = internalFind(k);
    BinarySearchTree<Key, Value>::iterator it(curr);
    return it;
}

/**
 * @precondition The key exists in the map
 * Returns the value associated with the key
 */
template<class Key, class Value>
Value& BinarySearchTree<Key, Value>::operator[](const Key& key)
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}
template<class Key, class Value>
Value const & BinarySearchTree<Key, Value>::operator[](const Key& key) const
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}

/**
* An insert method to insert into a Binary Search Tree.
* The tree will not remain balanced when inserting.
* Recall: If key is already in the tree, you should 
* overwrite the current value with the updated value.
*/
template<class Key, class Value>
void BinarySearchTree<Key, Value>::insert(const std::pair<const Key, Value> &keyValuePair)
{
    // TODO
    //wherever you're stuck, add it
    //if already in list overwrite
    Key tkey = keyValuePair.first;
    Value tvalue = keyValuePair.second;
    Node<Key,Value>* tempnode = root_;

   //case 1
    if(root_ == nullptr)
    {   
        //Node blah = new
        root_ = new Node<Key,Value>(tkey, tvalue , nullptr);
        return ;
    
    }

    bool inserted = false;
    while(!(inserted)){
        if(tkey < tempnode->getKey()){
            if(tempnode -> getLeft() == nullptr){
                Node<Key,Value>* node = new Node<Key,Value>(tkey, tvalue, tempnode);
                tempnode->setLeft(node);
                inserted = true;
            }
            else{
                tempnode = tempnode->getLeft();

            }
        }
        else if(tkey > tempnode->getKey()){
            if(tempnode -> getRight() == nullptr){
                Node<Key,Value>* node = new Node<Key,Value>(tkey, tvalue, tempnode);
                tempnode->setRight(node);
                inserted = true;

            }
            else{
                tempnode = tempnode ->getRight();
            }
        }
        else if(tkey == tempnode->getKey()){
            tempnode->setValue(tvalue);
            inserted = true;

        }
    }

    return;




    //     if(tempnode->getKey() == tkey){
    //         tempnode->setValue(tvalue);
    //         inserted = true;
    //     }

    //     if(tkey < tempnode->getKey() && tempnode->getLeft() == nullptr){
    //         //its the left most node, so its left child will be the node we are inserting
            

    //     }
    //     else{
    //         tempnode = tempnode->getLeft();
    //     }

    //     if(tkey > tempnode->getKey() && tempnode->getRight() == nullptr){
    //         Node<Key,Value>* node = new Node<Key,Value>(tkey, tvalue, tempnode);
    //         tempnode->setRight(node);
    //         inserted = true;
    //     }
    //     else{
    //         tempnode = tempnode -> getRight();
    //     }
    // }

    //link the parent

    //if just one node
    // if(fake_root->getParent() == nullptr && fake_root->getRight() == nullptr && fake_root->getLeft() == nullptr){
    //     if(keyValuePair.first < fake_root->getKey()){//if new less than root, go left
    //         Node<Key,Value>* newnode = new Node(keyValuePair.first, keyValuePair.second, root_);
    //         fake_root.setLeft(newnode);

            

    //     }
    //     else{
    //         fake_root.setRight(keyValuePair);
    //         Node<Key,Value>* newnode = new Node(keyValuePair.first, keyValuePair.second, root_);

    //     }
    // }

    // //2nd case, if more than one node, 

    // while(fake_root->getLeft() != nullptr || if(fake_root->getRight() != nullptr) ){

    //   //  if(keyValuePair.first < fake_root->getKey()){//if new less than root, go left
    //         fake_root.setLeft(keyValuePair);
    //         Node<Key,Value>* newnode = new Node(keyValuePair.first, keyValuePair.second, root_);


    //         }
    //         else{
    //             fake_root.setRight(keyValuePair);
    //             Node<Key,Value>* newnode = new Node(keyValuePair.first, keyValuePair.second, root_);
    //         }

    // }

    //

    //if less

   



    

    //if tree empty, create node

    

}


/**
* A remove method to remove a specific key from a Binary Search Tree.
* Recall: The writeup specifies that if a node has 2 children you
* should swap with the predecessor and then remove.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::remove(const Key& key)
{
    // TODO
    //given the key, make an iterator to iterate through the BST, and find which node has that key, from there do the cases. no need to rebalance
    //wait dont use an iterator, just do internalFind, gets a pointer to the node with the specified key:


    //dont iterate at all, just use direct pointers
    //first step is to find the node that has the key
    //if you have two children, swap current with predecessor and then delete current node which is at predecessor, because it becomes new pred. 
    //do insert before remove
    //else, nodeswap

    //delete[current];

    //follow the slides


    if(this->root_ == nullptr){
        return;
    }

    Node<Key,Value>* node =  internalFind(key);//should this be avl node in this setting?

    if(node == NULL){
        return;
    }

    //2 child case
    if(node->getLeft() != nullptr && node->getRight() != nullptr){
       Node<Key,Value>* temppred = predecessor(node);
      
       nodeSwap(temppred, node);

    }


    Node<Key,Value>* p = node->getParent();


  
    if(p == nullptr){
        return;
        
    }
    // else{
    //     if(node == p->getLeft()){
    //     diff = 1;
    //     }
    //     else if(node == p->getRight()){
    //         diff = -1;
    //     }

    // }
    

    if(node->getLeft() != nullptr){

        if(node == p->getLeft()){
                p->setLeft(node->getLeft());
                node->getLeft()->setParent(p);
                delete node;

            }
            else{
            
                //curent is parent's right child
                p->setRight(node->getLeft());
                node->getLeft()->setParent(p); 
                delete node;
 
            }


    }
    else if(node->getRight() != nullptr){
        if(node == p->getLeft()){

            //if the current node is the parent's left
            p->setLeft(node->getRight());
            node->getRight()->setParent(p);
            // if(node->getRight()->getLeft() != nullptr){
            //     node->getRight()->getLeft()->setLeft(nullptr);
            // }
            delete node;
     

        }
        else{//current is parent's right child
            p->setRight(node->getRight());
            node->getRight()->setParent(p);
            delete node;
  
        }

    }

    //no children case
    else if(node->getRight() == nullptr && node->getLeft() == nullptr){
        
        if(node == p->getRight()){

            p->setRight(nullptr);
        }
        else{
        //current node is left child of parent

            p->setLeft(nullptr);
        }
        delete node;
    


    }




//     std::cout<< key << std::endl;

//     if(root_ == nullptr){
//         return;
//     }

//     Node<Key,Value>* current_node = internalFind(key);

//     if(current_node == NULL){

//         return;
//     }

//     //if n has 2 children
//     // if(current_node->getLeft() != nullptr && current_node->getRight()!=nullptr){
//     //     nodeSwap(predecessor(current_node), current_node);
//     //     delete predecessor(current_node);

//     // }

//     std::cout<<"parent: " << current_node->getParent() << " left child: " << current_node->getLeft() << ". right child: " <<current_node->getRight() << std::endl;

//     Node<Key,Value>* p = current_node->getParent();

//     if(p == nullptr){
//         if(current_node->getLeft()!= nullptr){
//             if(current_node->getRight()!= nullptr)
//             {
//                 Node<Key,Value>* temppred = predecessor(current_node);
//                 nodeSwap(temppred, current_node);
//                 if(current_node == current_node->getParent()->getLeft()){
//                     current_node->getParent()->setLeft(current_node->getLeft());
//                     if(current_node->getLeft() != nullptr){
//                         current_node->getLeft()->setParent(current_node->getParent()) ;

//                     }
                    

//                 }
//                 else{
//                     current_node->getParent()->setRight(current_node->getLeft());
//                     if(current_node->getLeft() != nullptr){
//                         current_node->getLeft()->setParent(current_node->getParent());

//                     }
                   
//                 }
//                 root_ = temppred;

//                 delete current_node;
//                 return;

//             }
//             //
//             else{
//                 //down set current ->parent
//                 if(current_node->getLeft()->getRight() == NULL){
//                     root_ = current_node->getLeft();

//                 }
//                 else{
//                     root_ = current_node->getLeft()->getRight();// woudl this work?
//                 }
//                 //used to just be root_ = current_node->getLeft
                
//                 root_->setParent(nullptr);
//                 delete current_node;
//                 return;

//             }
//         }
//         //root only has a right child
//         else if(current_node->getRight() != nullptr){
//             root_ = current_node->getRight();
//             root_->setParent(nullptr);
//             if(root_->getLeft()!=nullptr){
//                 root_->getLeft()->setParent(root_);

//             }
//             else if(root_->getRight() != nullptr){
//                 root_->getRight()->setParent(root_);
//             }
//             delete current_node;
//             return;
//         }
        

//         //no children, no parent
//         else if(current_node->getRight() == nullptr && current_node->getLeft() == nullptr){
//             //current_node->setLeft(nullptr);
//             // current_node->setRight(nullptr);
//             // current_node->setParent(nullptr);
//             root_ = nullptr;
//             delete current_node;
//             return;
//         }

//     }

//     //if current node has a left child

//     //if the node has a parent
//     if(current_node->getLeft()!= nullptr){
//         if(current_node->getRight() != nullptr){
//             //TWO CHILDREN with a parent

//             // if(p == nullptr){
//             //     Node<Key,Value>* temppred = predecessor(current_node);
//             //     nodeSwap(temppred, current_node);
//             //     if(current_node== current_node->getParent()->getLeft()){
//             //         current_node->getParent()->setLeft(current_node->getLeft());
//             //         if(current_node->getLeft() != nullptr){
//             //             current_node->getLeft()->setParent(current_node->getParent()) ;

//             //         }
                    

//             //     }
//             //     else{
//             //         current_node->getParent()->setRight(current_node->getLeft());
//             //         if(current_node->getLeft() != nullptr){
//             //             current_node->getLeft()->setParent(current_node->getParent());

//             //         }
                   
//             //     }

//             //     delete current_node3


//             // }
//             // and a right child, so has 2 children
//             // else{
//                 Node<Key,Value>* temppred = predecessor(current_node);
//                 nodeSwap(temppred, current_node);
//                 std::cout<<"Swapping w pred" << std::endl;
              
//                 if(current_node->getLeft() != nullptr){
//                     current_node->getLeft()->setParent(current_node->getParent());//is parent current node or temppred?
//                     current_node->getParent()->setRight(current_node->getLeft());


//                 }
//                 else{
//                      if(current_node == current_node->getParent()->getRight()){
//                     current_node->getParent()->setRight(nullptr);
                    
//                     }
//                     else{
//                     current_node->getParent()->setLeft(nullptr);

//                     }

//                 }
//                 //current_node->getParent()->setRight(current_node->getLeft());
               
//                 delete current_node;
                
                
//                 return;
//             // }

//         }
//         else{
//             //ONLY HAS A LEFT CHILD

//             //current node only has a left child, so connect left childs pointers to current node's parent pointers
//             // if(p == nullptr){
//             //     root_ = current_node->getLeft();
//             //     root_->setParent(nullptr);
//             //     delete current_node;
//             // }


//             //current is its parent's LEFT CHILD
//             if(current_node == p->getLeft()){
//                 p->setLeft(current_node->getLeft());
//                 current_node->getLeft()->setParent(p);
//                 delete current_node;
//                 return;

//             }
//             else{
            
//                 //curent is parent's rihgt child
//                 p->setRight(current_node->getLeft());
//                 current_node->getLeft()->setParent(p);   
//                 delete current_node;
//                 return;
//             }
          
//         }
       
//     }
//     ///RIGHTT

//     //if current node has a rigth child
//     else if(current_node->getRight() != nullptr){
//         // if(p == nullptr){
//         //     root_ = current_node->getRight();
//         //     root_->setParent(nullptr);
//         //     delete current_node;


//         // }
       
//         //current only has right child
//         if(current_node == p->getLeft()){
//             std::cout<<"should behere" << std::endl;
//                 //if the current node is the parent's left
//             p->setLeft(current_node->getRight());
//             current_node->getRight()->setParent(p);
//             if(current_node->getRight()->getLeft() != nullptr){
//                 current_node->getRight()->getLeft()->setLeft(nullptr);

//             }
//             delete current_node;
//             return;

//         }
//         else{//current is parent's right child
//             p->setRight(current_node->getRight());
//             current_node->getRight()->setParent(p);
//             delete current_node;
//             return;
//         }

        
//     }
//     //no children, but has a parent
//     //right now, saying the node has no children, but has a parent, 
//     else if(current_node->getRight() == nullptr && current_node->getLeft() == nullptr){
//         // current_node->setLeft(nullptr);
//         // current_node->setRight(nullptr);
//         // current_node->setParent(nullptr);
//         // if(current_node = current_node->getParent()->getRight()){
//         //     current_node->getParent()->setRight(nullptr);

//         //  }
//         // else if(current_node = current_node->getParent()->getLeft()){
//         //     current_node->getParent()->setLeft(nullptr);
//         // }
//         std::cout<<"yes"<<std::endl;

//         if(current_node == p->getRight()){
//             std::cout<<"wrong"<<std::endl;
//             p->setRight(nullptr);
//         }
//         else{
//             std::cout<<"right"<<std::endl;
//             p->setLeft(nullptr);
//         }
//         delete current_node;
//         return;

//     }

//     std::cout<<"did nothing" <<std::endl;

    
   





//     //2 children
    


// //     //1 child
// //     if(current_node->getLeft() != nullptr || current_node->getRight()!=nullptr){
// //         if(current_node->getRight() != nullptr){
// //             //if has a rigth child
// //             current_node->getRight()->setParent(current_node->getParent());
// //             delete current_node;

// //         }
// //         else if(current_node->getLeft() != nullptr){
// //             //if has a left child
// //             current_node->getLeft()->setParent(current_node->getParent());
// //             delete current_node;
// //         }
// //     }
// //     //0 children
// //     else if(current_node->getLeft() == nullptr && current_node->getRight() ==nullptr){
// //         if(current_node == current_node->getParent()->getLeft()){
// //             //current is paren'ts left child, set left child pointer to 9
// //             current_node->getParent()->setLeft(nullptr);
        
// //         }
// //         else if(current_node == current_node->getParent()->getRight()){
// //             current_node->getParent()->setRight(nullptr);

// //         }
// //         delete current_node;
// //     }


    
// // }
}


template<class Key, class Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::predecessor(Node<Key, Value>* current)
{
    // TODO
    //predecessor could be a parent
    //first case
    //when only one child, 
    //same thing as successor copied
    //predecessor is the closest one thats smallest

    //iterate through the list  
    

    current->getItem();

    if(current->getLeft() != NULL){
        //if left child
        Node<Key,Value>* temp = current->getLeft();
        while(temp->getRight() != NULL){
            temp = temp->getRight();
        }
        return temp;


    }
    else{
        //no left child
        while(current->getParent()->getRight() != current){
            current = current->getParent();
            
            if(current->getParent() == NULL){
                return NULL;
            }

            
        }
        return current->getParent();//returning the first time it branches right, if a right child, it will be true immediately, if a left child, it wont be

        //to traverse internally, only use find, pred, and succ
    }


    //given a node, if it has a left child, the pred is the right most node of the left tree

}

template<class Key, class Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::successor(Node<Key, Value>* current){
 
   

    if(current->getRight() != NULL){
        Node<Key,Value>* temp = current->getRight();
        while(temp->getLeft() != NULL){
            temp = temp->getLeft();
        }
        return temp;


    }
    else if(current->getLeft() != NULL)
    {
        //walk up through tree to find predecessor ancestor way
        while(current->getParent()->getLeft() != current)
        {
            current = current->getParent();
            if(current->getParent()==NULL){
                return NULL;
            }
        }

        return current->getParent();
    }
    else{
        return NULL;

    }
        
    

}

/**
* A method to remove all contents of the tree and
* reset the values in the tree for use again.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear()
{
    // TODO

    clear_node(root_);
    root_ = nullptr;
    
    

    //oh god. 


    

}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear_node(Node<Key,Value>* node){

    if (node == nullptr){
        return;
    }
    
    else if(node->getRight()!=nullptr){
        Node<Key,Value>* temp_right = node->getRight();
        clear_node(temp_right);
    }

    else if(node->getLeft()!=nullptr){
        Node<Key,Value>* temp_left = node->getLeft();
        clear_node(temp_left);

    }
    

    delete node;
    
    


}




/**
* A helper function to find the smallest node in the tree.
*/
template<typename Key, typename Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::getSmallestNode() const
{
    // TODO
    
    Node<Key, Value>* curr = root_;
    
    if(root_ == NULL){
        // std::cout<<"here"<<std::endl;
        return NULL;
        
    }
    while(curr->getLeft() != nullptr){
        curr = curr->getLeft();
    }
    return curr;
}

/**
* Helper function to find a node with given key, k and
* return a pointer to it or NULL if no item with that key
* exists
*/
template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::internalFind(const Key& key) const
{
    // TODO
    Node<Key,Value>* tempnode = root_;
    Key tkey = key;

    bool found = false;
    // if(tempnode == NULL ){
    //     return tempnode;
    // }

    while(!(found)){
        if(tempnode->getKey() == tkey){
            //return tempnode;
            found = true;
        }

        else if(tkey < tempnode->getKey()){
            if(tempnode->getLeft() == nullptr){
                return NULL;

            }
            else{
                tempnode = tempnode->getLeft();

            }
            
        }
        else if(tkey > tempnode -> getKey()){
            if(tempnode->getRight() == nullptr)
            {
                return NULL;

            }
            else{
                tempnode = tempnode->getRight();

            }
            
        }
        

       
    }

 
    return tempnode;


}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isBalancedHelp(Node<Key,Value>* root) const
{
    //look for height
    //if height(right subtree) = height (l;eft subtree) <= 1 return true
    //

    //find height of right subtree
    // find height of left subtree

    int right_height  = 0;
    int left_height = 0;
   
    Node<Key,Value>* cur = root;
    
    if(cur == NULL){
        return true;
    }

    
    

    if(cur->getRight() != NULL){
        right_height ++; 
        
        
    }

    if(cur->getLeft() != NULL){
        left_height++;
        
         
    }
    if(((right_height - left_height) < 1 && (right_height - left_height) > -1) && isBalancedHelp(cur->getLeft()) && isBalancedHelp(cur->getRight())){
        //recursive calls should be in return statement;
        return true;
    }
    else{
        return false;
    }

// }
}

/**
 * Return true iff the BST is balanced.
 */
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isBalanced() const
{
    // TODO
    
    //maybe iterate through the whole list, and check height??? sounds good to mee!!!

    //create an iterator

    //needs recursion :()

    return isBalancedHelp(root_);
}



template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2)
{
    if((n1 == n2) || (n1 == NULL) || (n2 == NULL) ) {
        return;
    }
    Node<Key, Value>* n1p = n1->getParent();
    Node<Key, Value>* n1r = n1->getRight();
    Node<Key, Value>* n1lt = n1->getLeft();
    bool n1isLeft = false;
    if(n1p != NULL && (n1 == n1p->getLeft())) n1isLeft = true;
    Node<Key, Value>* n2p = n2->getParent();
    Node<Key, Value>* n2r = n2->getRight();
    Node<Key, Value>* n2lt = n2->getLeft();
    bool n2isLeft = false;
    if(n2p != NULL && (n2 == n2p->getLeft())) n2isLeft = true;


    Node<Key, Value>* temp;
    temp = n1->getParent();
    n1->setParent(n2->getParent());
    n2->setParent(temp);

    temp = n1->getLeft();
    n1->setLeft(n2->getLeft());
    n2->setLeft(temp);

    temp = n1->getRight();
    n1->setRight(n2->getRight());
    n2->setRight(temp);

    if( (n1r != NULL && n1r == n2) ) {
        n2->setRight(n1);
        n1->setParent(n2);
    }
    else if( n2r != NULL && n2r == n1) {
        n1->setRight(n2);
        n2->setParent(n1);

    }
    else if( n1lt != NULL && n1lt == n2) {
        n2->setLeft(n1);
        n1->setParent(n2);

    }
    else if( n2lt != NULL && n2lt == n1) {
        n1->setLeft(n2);
        n2->setParent(n1);

    }


    if(n1p != NULL && n1p != n2) {
        if(n1isLeft) n1p->setLeft(n2);
        else n1p->setRight(n2);
    }
    if(n1r != NULL && n1r != n2) {
        n1r->setParent(n2);
    }
    if(n1lt != NULL && n1lt != n2) {
        n1lt->setParent(n2);
    }

    if(n2p != NULL && n2p != n1) {
        if(n2isLeft) n2p->setLeft(n1);
        else n2p->setRight(n1);
    }
    if(n2r != NULL && n2r != n1) {
        n2r->setParent(n1);
    }
    if(n2lt != NULL && n2lt != n1) {
        n2lt->setParent(n1);
    }


    if(this->root_ == n1) {
        this->root_ = n2;
    }
    else if(this->root_ == n2) {
        this->root_ = n1;
    }

}

/**
 * Lastly, we are providing you with a print function,
   BinarySearchTree::printRoot().
   Just call it with a node to start printing at, e.g:
   this->printRoot(this->root_) // or any other node pointer

   It will print up to 5 levels of the tree rooted at the passed node,
   in ASCII graphics format.
   We hope it will make debugging easier!
  */

// include print function (in its own file because it's fairly long)
#include "print_bst.h"

/*
---------------------------------------------------
End implementations for the BinarySearchTree class.
---------------------------------------------------
*/

#endif
