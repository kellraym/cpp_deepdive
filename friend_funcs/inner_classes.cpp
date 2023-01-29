#include <iostream>

class Outer
{
    public:
        int a = 10;
        static int b;

        void fun()
        {
            i.show();
        }
        
        class Inner
        {
            public:
                int n = 25;
                void show()
                {
                    std::cout << "Show";
                }
        };

        Inner i;
};

class LinkedList // Node is only used by LinedList so just put it inside LinkedList
{
    class Node
    {
        int data;
        Node *next;
    };

    Node *head;
};



int Outer::b = 20;

int main()
{

    return 0;
}

