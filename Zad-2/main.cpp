#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

struct Stack
{
    int* array;
    int size;
    int pointer;
    bool empty;
};

void init(Stack *stack)
{
    stack->size = 2;
    stack->pointer = 0;
    stack->array = new int[stack->size];
    stack->empty = 1;
}

void push(Stack *stack, int number)
{
    if (stack->pointer == stack->size)
    {
        int* array = new int[2*stack->size];
        for (int i = 0; i < stack->size; ++i)
        {
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

int pop(Stack *stack)
{
    int temp;
    if (stack->pointer > 0)
    {
        stack->pointer--;
        temp = stack->array[stack->pointer];
    }

    if(stack->pointer==0)
    {
        stack->empty=1;
    }

    return temp;
}



void load_data (string nazwa, Stack *stack)
{
    ifstream plik;
    plik.open(nazwa.c_str());

    if (plik.good())
    {
        int liczba;
        while(!plik.eof())
        {
            plik>>liczba;
            push (stack, liczba);
        }
        plik.close();
    }
    else
    {
        cout<<"blad otwarcia pliku"<<endl;
    }
}

void sort_stack(Stack *stack)
{
    for (int i=0; i<stack->size-1; i++)
    {
        int i_min=i;
        for(int j=i+1; j<stack->size; j++)
        {
            if(stack->array[j]<stack->array[i_min])
            {
                i_min=j;
            }
        }
        int temp;
        temp=stack->array[i];
        stack->array[i]=stack->array[i_min];
        stack->array[i_min]=temp;
    }
}

void save_to_file (string nazwa, Stack *stack)
{
    ofstream plik;
    plik.open(nazwa.c_str());

    while(stack->empty!=1)
    {
        plik<<pop(stack)<<endl;
    }
    plik.close();
}

int main()
{
    Stack s;
    init(&s);
    load_data("Dane/data.txt", &s);
    sort_stack(&s);
    save_to_file("Dane/wyniki.txt", &s);

    return 0;
}
