#ifndef RBBST_H
#define RBBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    signed char getBalance () const;
    void setBalance (signed char balance);
    void updateBalance(signed char diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    signed char balance_;
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor and setting
* the color to red since every new node will be red when it is first inserted.
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{
    //set the color to red? whatt he fuck?.

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
signed char AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(signed char balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(signed char diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
    
protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);
    // Add helper functions here
    virtual void right_rotate(AVLNode<Key,Value>* node);
    virtual void left_rotate(AVLNode<Key,Value>* node);
    virtual void insert_fix(AVLNode<Key,Value>* parent, AVLNode<Key,Value>* node);
    virtual void remove_fix(AVLNode<Key,Value>* node, signed char diff);
    virtual bool is_zigzig(AVLNode<Key,Value>* grandparent, AVLNode<Key,Value>* parent, AVLNode<Key,Value>* node);
    virtual bool is_zigzag(AVLNode<Key,Value>* grandparent, AVLNode<Key,Value>* parent, AVLNode<Key,Value>* node);
    



};

/*
 * Recall: If key is already in the tree, you should 
 * overwrite the current value with the updated value.
 */
template<class Key, class Value>
void AVLTree<Key, Value>::insert(const std::pair<const Key, Value> &new_item)
{ 
    // TODO

    Key tkey = new_item.first;
    Value tvalue = new_item.second;
    
    AVLNode<Key,Value>* node_new = new AVLNode<Key,Value>(tkey, tvalue, nullptr);
    

    if(this->root_ == nullptr)
    {   
        //Node blah = new
        this->root_ = node_new;
        node_new->setBalance(0);
        return;
        //should be correct
    
    }

    AVLNode<Key,Value>* tempnode = static_cast<AVLNode<Key, Value>*>(this->root_);
    AVLNode<Key,Value>* parent = nullptr;
  

    bool inserted = false;
    while(!(inserted)){
        parent = tempnode;
        if(tkey < parent->getKey()){
            if(parent -> getLeft() == nullptr){
                std::cout<<"does it get here 1?" << std::endl;
                //node = new AVLNode<Key,Value>(tkey, tvalue, tempnode);
                parent->setLeft(node_new);
                node_new->setParent(parent);
                node_new->setBalance(0);
                std::cout<<"p bal" << parent->getBalance() << std::endl;

      
                inserted = true;

            }
            else{
                tempnode = parent->getLeft();

            }
        }
        
        else if(tkey > parent->getKey()){
            std::cout<<"does it get here? 2" << std::endl;
            if(parent -> getRight() == nullptr){
               // node = new AVLNode<Key,Value>(tkey, tvalue, tempnode);
                parent->setRight(node_new);
                node_new->setParent(parent);
                node_new->setBalance(0);
                //balance checks
                
                inserted = true;
                
                // if(node->getParent()->getBalance() == -1){
                //     static_cast<AVLNode<Key,Value>*>(node)->getParent()->setBalance('0');
                //     return;

                // }
                // else if(node->getParent()->getBalance() == 1){
                //     static_cast<AVLNode<Key,Value>*>(node)->getParent()->setBalance('0');
                //     return;
                // }
                // else if(node->getParent()->getBalance() == 0){
                //     static_cast<AVLNode<Key,Value>*>(node)->updateBalance(node->getBalance());
                //     insert_fix(static_cast<AVLNode<Key,Value>*>(node)->getParent(),static_cast<AVLNode<Key,Value>*>(node));
                //     return;
                // }
                
                

                }
            else{
                tempnode = parent ->getRight();
                std::cout<<"should go right bc " << tkey << "greater" << std::endl;
            }
        }
        
        else if(tkey == tempnode->getKey()){
            std::cout<<"does it get here? 3" << std::endl;
            tempnode->setValue(tvalue);
            tempnode->setBalance(0);
           // static_cast<AVLNode<Key,Value>*>(tempnode)->setBalance(0);
            std::cout<<" same thing inserted and balance checked" << std::endl;
            // delete node_new;
            node_new = tempnode;
            inserted = true;



        }

        //check balance after insertion!

        
        // else if(node->getParent()->getBalance() == 0){
        //     node->updateBalance(node->getBalance());
        //     insert_fix(node->getParent(),node);
        //     return;
        // }
    }


    if(parent->getBalance() == -1 || parent->getBalance() == 1){
        parent->setBalance(0);
        return;

    }
    else{
        //if node is left heavy
        if(parent->getLeft() == node_new){
            parent->setBalance(-1);
        }

        //if node right heavy
        if(parent->getRight() == node_new){
            parent->setBalance(1);
        }
        insert_fix(parent, node_new);
    }



};

/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */




template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    signed char tempB = static_cast<AVLNode<Key,Value>*>(n1)->getBalance();
    static_cast<AVLNode<Key,Value>*>(n1)->setBalance(n2->getBalance());
    static_cast<AVLNode<Key,Value>*>(n2)->setBalance(tempB);
};


    


template<class Key, class Value>
void AVLTree<Key, Value>::insert_fix(AVLNode<Key,Value>* p, AVLNode<Key,Value>* n){
    //in this case, par
    if( p == NULL || p->getParent() == NULL){
        return;
    }

    AVLNode<Key,Value>* g = p->getParent();

    std::cout<<"insert fix called" << std::endl;

    //if p is left child of g
    if( p == g->getLeft() ){
        g->updateBalance(-1);
        //case 1
        if(static_cast<AVLNode<Key,Value>*>(g)->getBalance() == 0){
            return;
        }
        else if(static_cast<AVLNode<Key,Value>*>(g)->getBalance() == -1){
            std::cout<<"here?" << std::endl;
            insert_fix(g, p);//recursion!!
        }
        else if(static_cast<AVLNode<Key,Value>*>(g)->getBalance() == -2){
            if(is_zigzig(g,p,n) == true){
                right_rotate(g);
                static_cast<AVLNode<Key,Value>*>(p)->setBalance(0);
                static_cast<AVLNode<Key,Value>*>(g)->setBalance(0);

            }
            else if(is_zigzag(g,p,n) == true){
                std::cout<<"zigzag called" << std::endl;
                left_rotate(p);
                right_rotate(g);
                if(static_cast<AVLNode<Key,Value>*>(n)->getBalance() == -1){
                    static_cast<AVLNode<Key,Value>*>(p)->setBalance(0);
                    static_cast<AVLNode<Key,Value>*>(g)->setBalance(1);
                    static_cast<AVLNode<Key,Value>*>(n)->setBalance(0);
                }
                else if(n->getBalance() == 0){
                    static_cast<AVLNode<Key,Value>*>(p)->setBalance(0);
                    static_cast<AVLNode<Key,Value>*>(g)->setBalance(0);
                    static_cast<AVLNode<Key,Value>*>(n)->setBalance(0);
                }
                else if(n->getBalance() == 1){
                    static_cast<AVLNode<Key,Value>*>(p)->setBalance(-1);
                    static_cast<AVLNode<Key,Value>*>(g)->setBalance(0);
                    static_cast<AVLNode<Key,Value>*>(n)->setBalance(0);
                }
            }
        }
    }
    //parent is right child of grandparent
    else if(p->getParent()->getRight() == p){
        
        g->updateBalance(1);
        //case 1
        

        if(static_cast<AVLNode<Key,Value>*>(g)->getBalance() == 0){
            std::cout<<"in case 1 4 insert fix?" << std::endl;
            return;
        }
        //case 2
        

        else if(static_cast<AVLNode<Key,Value>*>(g)->getBalance() == 1){
            std::cout<<"in case 2 4 insert fix?" << std::endl;
            std::cout<<"here 2"<< std::endl;
            insert_fix(g,p);//recurse

        }
        //case 3
        
        else if(static_cast<AVLNode<Key,Value>*>(g)->getBalance() == 2){
            std::cout<<"in case 3 4 insert fix?" << std::endl;
            //if zig zig
            
            if(is_zigzig(g,p,n) == true){
                
                left_rotate(g);
                static_cast<AVLNode<Key,Value>*>(p)->setBalance(0);
                static_cast<AVLNode<Key,Value>*>(g)->setBalance(0);

            }
            //if zig zag
            if(is_zigzag(g,p,n) == true){
                //case 3a
                std::cout<<"zigzag called" << std::endl;
                right_rotate(p);
                left_rotate(g);
                if(static_cast<AVLNode<Key,Value>*>(n)->getBalance() == 1){
                    static_cast<AVLNode<Key,Value>*>(n)->setBalance(0);
                    static_cast<AVLNode<Key,Value>*>(g)->setBalance(-1);
                    static_cast<AVLNode<Key,Value>*>(p)->setBalance(0);

                }
                else if(n->getBalance() == 0){
                    static_cast<AVLNode<Key,Value>*>(p)->setBalance(0);
                    static_cast<AVLNode<Key,Value>*>(g)->setBalance(0);
                    static_cast<AVLNode<Key,Value>*>(n)->setBalance(0);

                }
                else if(n->getBalance() == -1){
                    static_cast<AVLNode<Key,Value>*>(p)->setBalance(1);
                    static_cast<AVLNode<Key,Value>*>(g)->setBalance(0);
                    static_cast<AVLNode<Key,Value>*>(n)->setBalance(0);
                }
            }
        }




    }


};

template<class Key, class Value>
bool AVLTree<Key, Value>::is_zigzig(AVLNode<Key,Value>* grandparent, AVLNode<Key,Value>* parent, AVLNode<Key,Value>* node){
    if( parent == grandparent->getLeft()){
        if(node == parent->getLeft()){
            return true;
        }
        else{
            return false;
        }
        
    }
    else if(parent == grandparent->getRight()){
        if(node == parent->getRight()){
            return true;
        }

        else{
            return false;
        }
    }
};

template<class Key, class Value>
bool AVLTree<Key, Value>::is_zigzag(AVLNode<Key,Value>* grandparent, AVLNode<Key,Value>* parent, AVLNode<Key,Value>* node){
    if( parent == grandparent->getRight()){
        std::cout<<"is zig zag called" << std::endl;
        if(node == parent->getLeft()){
            return true;
        }
        else{
            return false;
        }
        
    }
    else if( parent == grandparent->getLeft()){
        if(node == parent->getRight()){
            return true;
        }
        else{
            return false;
        }
    }
};

template<class Key, class Value>
void AVLTree<Key, Value>::right_rotate(AVLNode<Key,Value>* node){

    //METHOD 1!!!

    //checking og node parent to reestablish the connection later on
    // AVLNode<Key,Value>* og_node = node;
    // AVLNode<Key,Value>* og_parent = node->getParent();

    
    // if(og_parent!= NULL){
    //     AVLNode<Key,Value>* tempnode = og_parent;
    //     bool is_right = is_right_child(node, og_parent);
    //     bool if_left = is_left_child(node,og_parent );

    // }
    // else{
    //     AVLNode<Key,Value>* tempnode = node->getParent();

    // }
    std::cout<<"right rotate called" << std::endl;
    AVLNode<Key,Value>* x = node->getLeft();
    AVLNode<Key,Value>* r = x->getRight();

    //actual rotation

    x->setRight(node);
    node->setLeft(r);
    
    if(r == NULL){

    


    }
    else{
        node->setLeft(r);
        r->setParent(node);

    }



    //actual rotation
    
    

    //6 pairs of pointers you need to change:

    
    if(node->getParent() == NULL){
        this->root_ = x;
        
    }
    else if(node->getParent()->getRight() == node){
        node->getParent()->setRight(x);
    }
    else{
        node->getParent()->setLeft(x);
    }

    x->setParent(node->getParent());
    

    node->setParent(x);
   
   
    
    

    // r->setParent(node);
    // x->setParent(tempnode);

    //if you right rotate you assume a node has a child, grandparent, etc. 
    //need to figure out which orientation of rotation you are doing
    //this method only works for 1/2 of the orientation options:
        
        //in terms of zigzig
        //for zig zig, you always perform right rotate on the grandparent
        //works for zigzig when node is rc of parent, parent is rc of grandparent

        //for zig zag:
        //node has to be left of parent, parent has to be right of grandparent
        
        //confused as to how you would know these orientations, as which node you are rotating, either parent or grandparent, changes. Should I check to see which one works?





    

    
    
    

    //if og node had a parent, need to set that's right and left accordingly

    

    

    //check whether og node is left or right 





};

template<class Key, class Value>
void AVLTree<Key, Value>::left_rotate(AVLNode<Key,Value>* node){

    std::cout<<"left rotate called" <<std::endl;

    AVLNode<Key,Value>* x = node->getRight();
    AVLNode<Key,Value>* r = x->getLeft();


    //actual rotation
    x->setLeft(node);
    node->setRight(r);

    if(r == NULL){


    }
    else{
        r->setParent(node);
        node->setRight(r);
    }
    

    //6 pairs of pointers you need to change:

    if(node->getParent() == NULL){
        this->root_ = x;

    }
    else if(node->getParent()->getLeft() == node){
        node->getParent()->setLeft(x);
    }
    else{
        node->getParent()->setRight(x);
    }

    x->setParent(node->getParent());
    

    node->setParent(x);


};


//dont think you need these anymore
// template<class Key, class Value>
// bool is_right_child(AVLNode<Key,Value>* node,AVLNode<Key,Value>* parent ){
//     if(node == parent->getRight()){
//         return true;
//     }
// }

// template<class Key, class Value>
// bool is_left_child(AVLNode<Key,Value>* node,AVLNode<Key,Value>* parent ){
//     if(node == parent->getLeft()){
//         return true;
//     }
// }







//tomorrow do some exercises to make sure it works, and implement right rotate and left rotate
//


template<class Key, class Value>
void AVLTree<Key, Value>::remove(const Key& key){

    //TODO
    if(this->root_ == nullptr){
        return;
    }

    AVLNode<Key,Value>* current_node =  static_cast<AVLNode<Key,Value>*>(BinarySearchTree<Key,Value>::internalFind(key));//should this be avl node in this setting?
    signed char sixteen = 16;
   
    if(current_node == NULL){

        return;
    }

    signed char diff = 0;



    AVLNode<Key,Value>* p = current_node->getParent();

    if(p == nullptr){
        if(current_node->getLeft()!= nullptr){
            if(current_node->getRight()!= nullptr)
            {
                AVLNode<Key,Value>* temppred = static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key,Value>::predecessor(current_node));
                nodeSwap(temppred, current_node);
                if(current_node == current_node->getParent()->getLeft()){
                    current_node->getParent()->setLeft(current_node->getLeft());
                    if(current_node->getLeft() != nullptr){
                        current_node->getLeft()->setParent(current_node->getParent()) ;

                    }
                    

                }
                else{
                    current_node->getParent()->setRight(current_node->getLeft());
                    if(current_node->getLeft() != nullptr){
                        current_node->getLeft()->setParent(current_node->getParent());

                    }
                   
                }
                this->root_ = temppred;
                delete current_node;
                remove_fix(temppred, 1);
                return;

            }
            //
            else{
                //down set current ->parent
                if(current_node->getLeft()->getRight() == NULL){
                    this->root_ = current_node->getLeft();

                }
                else{
                    this->root_ = current_node->getLeft()->getRight();// woudl this work?
                }
                //used to just be this->root_ = current_node->getLeft
                
                this->root_->setParent(nullptr);
                delete current_node;
                return;

            }
        }
        //root only has a right child
        else if(current_node->getRight() != nullptr){
            this->root_ = current_node->getRight();
            this->root_->setParent(nullptr);
            if(this->root_->getLeft()!=nullptr){
                this->root_->getLeft()->setParent(this->root_);

            }
            else if(this->root_->getRight() != nullptr){
                this->root_->getRight()->setParent(this->root_);
            }
            delete current_node;

            return;
        }
        

        //no children, no parent
        else if(current_node->getRight() == nullptr && current_node->getLeft() == nullptr){
            //current_node->setLeft(nullptr);
            // current_node->setRight(nullptr);
            // current_node->setParent(nullptr);
            this->root_ = nullptr;
            delete current_node;
            return;
        }

    }

    //if current node has a left child

    //if the node has a parent, 
    //so parent not null

    //diff -> update balance fxn

    if(current_node->getLeft()!= nullptr){
        if(current_node->getRight() != nullptr){
            //TWO CHILDREN with a parent
                AVLNode<Key,Value>* temppred =  static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key,Value>::predecessor(current_node));
                nodeSwap(temppred, current_node);
    
              
                if(current_node->getLeft() != nullptr){
                    current_node->getLeft()->setParent(current_node->getParent());//is parent current node or temppred?
                    current_node->getParent()->setLeft(current_node->getLeft());
                    diff = 1;


                }
                else{
                    //current node has a right
                     if(current_node == current_node->getParent()->getRight()){
                         //current node is right child
                        current_node->getParent()->setRight(nullptr);
                        diff = -1;
                    
                    }
                    else{
                        //current node is left child
                        current_node->getParent()->setLeft(nullptr);
                        diff = 1;

                    }

                }
                //current_node->getParent()->setRight(current_node->getLeft());
                remove_fix(p, diff);
                delete current_node;
                
                
                return;
            // }

        }
        else{
         

            //current is its parent's LEFT CHILD
            if(current_node == p->getLeft()){
                p->updateBalance(1);
                p->setLeft(current_node->getLeft());
                current_node->getLeft()->setParent(p);
                diff = 1;
                remove_fix(p, diff);
                delete current_node;
                return;

            }
            else{
            
                //curent is parent's right child
                p->setRight(current_node->getLeft());
                current_node->getLeft()->setParent(p); 
                diff = -1;
                remove_fix(p, diff); 
                delete current_node;
                return;
            }
          
        }
       
    }
    ///RIGHTT

    //if current node has a rigth child
    else if(current_node->getRight() != nullptr){
      
        //current only has right child
        if(current_node == p->getLeft()){

            //if the current node is the parent's left
            p->setLeft(current_node->getRight());
            current_node->getRight()->setParent(p);
            if(current_node->getRight()->getLeft() != nullptr){
                current_node->getRight()->getLeft()->setLeft(nullptr);
            }
            diff = 1;
            remove_fix(p, diff);
            delete current_node;
            return;

        }
        else{//current is parent's right child
            p->setRight(current_node->getRight());
            current_node->getRight()->setParent(p);
            diff = -1;
            remove_fix(p, diff);
            delete current_node;
            return;
        }

        
    }
    //no children, but has a parent
    //right now, saying the node has no children, but has a parent, 
    else if(current_node->getRight() == nullptr && current_node->getLeft() == nullptr){
    


        //current node is right child of parent
        if(current_node == p->getRight()){

            p->setRight(nullptr);
            diff = -1;
        }
        else{
        //current node is left child of parent

            p->setLeft(nullptr);
            diff = 1;
        }
        remove_fix(p, diff);
        delete current_node;
        return;

    }

};

template<class Key, class Value>
void AVLTree<Key, Value>::remove_fix(AVLNode<Key,Value>* node, signed char diff){

    std::cout<<"remove fix called"<<std::endl;
    if(node == NULL){
        return;
    }

    //store og parent so you know you have it to recurse on
    AVLNode<Key,Value>* p = node->getParent();
    signed char nextdiff = 0;

    if(node->getParent() != NULL){

        if(node == node->getParent()->getLeft()){
            nextdiff = 1;
        }
        else if(node == node->getParent()->getRight()){
            nextdiff = -1;
        }
    }


    

    AVLNode<Key,Value>* c; 
    //case 1    
    if(node->getBalance() + diff == -2){
        //case 1a -- zig zig case
        c = node->getLeft();
        if(c->getBalance() == -1){
            std::cout<<"Are we here? c1" << std::endl;
            right_rotate(node);
            node->setBalance(0);
            c->setBalance(0);
            remove_fix(p, nextdiff);
        }

        //case 1b -- zig zig case
        else if(c->getBalance()== 0){
            std::cout<<"Are we here? c1b" << std::endl;
            right_rotate(node);
            node->setBalance(-1);
            c->setBalance(1);
        }
        //case 1c -- zig zag case
        else if(c->getBalance() == 1){
            std::cout<<"Are we here? c1c" << std::endl;
            AVLNode<Key,Value>* g = c->getRight();
            left_rotate(c);
            right_rotate(node);
            if(g->getBalance() == 1){
                node->setBalance(0);
                c->setBalance(-1);
                g->setBalance(0);
            }
            if(g->getBalance() == 0){
                node->setBalance(0);
                c->setBalance(0);
                g->setBalance(0);
            }
            if(g->getBalance() == -1){
                node->setBalance(1);
                c->setBalance(0);
                g->setBalance(0);
            }
            remove_fix(p, nextdiff);
        }

    }

    //case 2
    else if((node->getBalance() + diff) == -1){
        std::cout<<"Are we here? c2" << std::endl;
        node->setBalance(-1);
    }

    //case 3
    
    else if((node->getBalance() + diff) == 0){
        std::cout<<"Are we here? c3" << std::endl;
        node->setBalance(0);
        remove_fix(p, nextdiff);
    }




    //MIRRORED CODE

    //case 1

    if((node->getBalance()+diff) == 2){
        c = node->getRight();
        //case 1a -- zig zig case
        if(c->getBalance() == 1){
            left_rotate(node);
            node->setBalance(0);
            c->setBalance(0);
            remove_fix(p, nextdiff);

        }

        //case 1b -- zig zig case
        else if(c->getBalance() == 0){
            left_rotate(node);
            node->setBalance(1);
            c->setBalance(-1);

        }
        
        //case 1c -- zig zag
        else if(c->getBalance()== -1){
            AVLNode<Key,Value>* g = c->getLeft();
            right_rotate(c);
            left_rotate(node);
            
            if(g->getBalance() == -1){
                node->setBalance(0);
                c->setBalance(1);
                g->setBalance(0);
            }
            
            else if(g->getBalance() == 0){
                node->setBalance(0);
                c->setBalance(0);
                g->setBalance(0);
            }
            
            else if(g->getBalance() == 1){
                node->setBalance(-1);
                c->setBalance(0);
                g->setBalance(0);

            }
            remove_fix(p, nextdiff);
        }
    }

    //case 2
    else if((node->getBalance() + diff) == 1){
        node->setBalance(1);
    }

    //case 3
    else if((node->getBalance() + diff) == 0){
        node->setBalance(0);
        remove_fix(p, nextdiff);
    }




};


#endif
