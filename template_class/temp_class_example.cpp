#include <iostream>

// You can define multiple template classes together
// template<class T, class R> 

template<class T>
class Stack
{
    private:
        T *stk;
        int top;
        int size;

    public:
        Stack(int size)
        {
            this->size = size;
            top = -1;
            stk = new T[size];
        }
        void push(T x);
        T pop();
};

template<class T>
void Stack<T>::push(T x)
{
    if (top == size - 1) std::cout << "Stack is full";
    else stk[top++] = x;
}

template<class T>
T Stack<T>::pop()
{
    int x = 0;
    if (top == -1) std::cout << "Stack is empty";
    else x = stk[top--];
    return x;
}

int main()
{
    Stack<char> s(10);
    s.pop();
    s.push(2);
    s.push(40);
    s.pop();
    return 0;
}