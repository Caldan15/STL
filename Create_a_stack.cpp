#include <iostream>
#include <vector>
using namespace std;

//Creating a container
template <class A>

class Stack {

//Creating a Vector
private:
  vector<A> box;

public:
//Push, Pop, empty and size functions
 int size() {
    return box.size();
  }
  void push(A value) {
    box.push_back(value);
  }
  A pop() {
    A value = box.back();
    box.pop_back();
    return value;
  }
  bool empty() {
    return box.empty();
  }
};

int main() {

  Stack<int> a;
//Pushing values
  a.push(15);
  a.push(20);
  a.push(25);
//Printing the size of the stack(Vector)
  cout<<"Size of the stack : "<<a.size()<<endl;
//Printing the values of the stack
  while (!a.empty()) {
    cout << a.pop() << endl;
  }

  return 0;
}
