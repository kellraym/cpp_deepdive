#include <iostream>

class StackOverFlow: std::exception{};
class StackUnderFlow: std::exception{};

class Stack
{
    private:
        int *stk;
        int top = -1;
        int size;

    public:
        Stack(int size)
        {
            this->size = size;
            stk = new int[size];
        }

        void push(int x)
        {
            if (top == size - 1) throw StackOverFlow();
            top++;
            stk[top] = x;
        }

        int pop()
        {
            if (top == -1) throw StackUnderFlow();
            return stk[top--];
        }
};

int main()
{
    Stack s(5);

    try
    {
        // s.pop();
        s.push(4);
        s.push(3);
        s.push(2);
        s.push(10);
        s.push(9);
        s.push(10);
    }
    catch(StackOverFlow e)
    {
        std::cout << "Stack Overflow\n";
    }
    catch(StackUnderFlow e)
    {
        std::cout << "Stack Underflow\n";
    }

    std::cout << "Bye";
    return 0;
}