#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary


};
template <typename T>
Stack<T>::Stack(){
    //constructor, creates an empty stack

}




template <typename T>
Stack<T>::~Stack(){
    //destructor

}


template <typename T>
bool Stack<T>::empty() const{
    //if size of list == 0, return true
    if(std::vector<T>::size() == 0){
        return true;
    }
    else{
        return false;
    }

}

template <typename T>
size_t Stack<T>::size() const{
    size_t size;
    size = std::vector<T>::size();
    return size;


}
template <typename T>
void Stack<T>::push(const T& item){
    Stack<T>::push_back(item);

}
template <typename T>
void Stack<T>::pop(){
    //if empty, throw underflow error
    if(Stack<T>::empty() == true){
        throw std::underflow_error("Vector empty, underflow error");
    }
    else{
        this->pop_back();
    }
}

template <typename T>
const T& Stack<T>::top() const{
    //if empty, throw underflow error'
    if(Stack<T>::empty() == true){
        throw std::underflow_error("Vector empty, underflow error");
    }
    // else{
    //     return this->back();
    // }
    return Stack<T>::back();

}



#endif
