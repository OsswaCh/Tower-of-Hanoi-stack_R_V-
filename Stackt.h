#include <stdexcept> 
#include <iostream>

template <class T>
class Stackt {
private:
    int top;
    int maxSize;
    T* stk;

public:
    Stackt(int size) {
        if (size < 0)
            throw std::invalid_argument("stack size invalid");
        maxSize = size;
        stk = new T[maxSize];
        top = -1;
    }

    ~Stackt() {
        delete[] stk;
    }

    void push(T element) {
        if (isFull())
            throw std::runtime_error("stack is full!");

        top = top + 1;
        stk[top] = element;
    }

    T pop() {
        if (isEmpty())
            throw std::runtime_error("stack is empty!");

        T lastElement = stk[top];
        top--;
        return lastElement;
    }

    T head() {
        if (isEmpty())
            throw std::runtime_error("stack is empty!");

        return stk[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void printStack() {
        if (isEmpty())
            std::cout << "Stack is empty" <<std::endl;
        else
            for (int i = top; i >= 0; i--)
                std::cout << stk[i] << std::endl;
    }
};
