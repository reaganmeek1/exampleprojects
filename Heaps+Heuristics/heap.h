#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;


private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  // void swap(int a, int b);//swaps the values already a thing std::swap()
  int m_count;
  PComparator comp; 
  void heapify(int parent);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int index){
//index is parent
    int first_child = index;

   //comp(first_child, second_child)

      //min heap
      

    for(int i = 1; i <= m_count; ++i){
      if(index*m_count + i < data.size()){
        int second_child = index*m_count + i;
        if(!(comp(data[first_child], data[second_child]))){
          //data[second_child] > data[first_child]
          first_child = second_child;
        }

      }

    }


    if(first_child!= index){
      //data[index] > data[first_child]
      std::swap(data[index], data[first_child]);
      heapify(first_child);

    }

    



}

//constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  m_count = m;
  comp = c;


}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){



}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("no elements in the heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];



}

//c(compare 1, compare 2), then that returns true, and do which one 


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()//moving downwards
{
  //you have the root and the last thing, remove the root (goal), put last thing in the root, and you pop out the last thing, so the worst thing is now on the top. need best child index (2*i + ), now youre checking children, if you're wordt than child, seg fault. But, bc youre 
  //if index above a certain point, its not full. 
  if(empty()){


    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("no elements in the heap");

  }

  //remove the root: 
  //data.pop_back(data[0]);
  //take in 2 items
  //swap first and last
  std::swap(data[0], data.back());
  data.pop_back();
  heapify(0);




}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){

  data.push_back(item);
  //push back an item, then check above it to make sure its not better than parent, find parent, and get current index. for each child check if better than parent, if yes, just swap. 
  //if size is 1, dojt even swap just return
  // if(data.size() == 1){
  //   return;
  // }
  int idx = data.size() -1;
  //find the parent located @ (i-1)/2
  int parent = (idx-1)/m_count;

  while(comp(data[idx],data[parent])){
    std::swap(data[idx], data[parent]);
    idx = parent;
    parent = (idx-1)/m_count;
   //swap
   //update indx to be parent
   //udate parent
   
    }

  }
  
    





template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{

  if(data.size() == 0){
    return true;
    
  }
  return false;
} 

#endif



//whole idea is to check whether min then max, and then use the bool values to do min or max heap

//write helper function called swap and takes in 2 indexes and replaces the values at the indexes

//write recursive heapify function, starts w root, and looks at each child, if any fail/or pass the comp, swap the child and the root

//push doesnt use heapify, only pop would 
