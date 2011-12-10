#include <iostream>
#include <math.h>
#include <fstream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

struct Stack {
  int* array;
  int size;
  int pointer;
  bool empty;
};

void init(Stack *stack) {
  stack->size = 2;
  stack->pointer = 0;
  stack->array = new int[stack->size];
  stack->empty = 1;

}

void push(Stack *stack, int number){
  if (stack->pointer == stack->size) {
    int* array = new int[2*stack->size];
    for (int i = 0; i < stack->size; ++i) {
      array[i] = stack->array[i];
    }
    delete[] stack->array;
    stack->array = array;
    stack->size = 2*stack->size;
    array = NULL;
  }
  stack->array[stack->pointer] = number;
  stack->pointer++;
  stack->empty = 0;
}

int pop(Stack *stack) {
  int temp = -1;
  if (stack->pointer > 0) {
    stack->pointer--;
    temp = stack->array[stack->pointer];
  }

  if(stack->pointer==0){
  stack->empty=1;
  }

  return temp;
}

bool isEmpty(Stack *stack){
return stack->empty;
}

int main() {
  Stack s;
  init(&s);
  cout<<isEmpty(&s)<<endl;
  for (int i = 0; i < 100; ++i) {

    push(&s, i);
    if (i%10 == 0) {
      cout << "Dla i = "<< i << " stack.size = " << s.size << endl;
    }
  }
  for (int i = 0; i < 100; ++i) {

    cout << pop(&s) << endl;
  }

  return 0;
}
