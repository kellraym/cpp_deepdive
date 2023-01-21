#include <iostream>

int recursive_lin_search(int A[], int n, int key)
{
    if (n == -1)
    {
        return n;
    }

    if (A[n] == key)
    {
        return n;
    }
    return recursive_lin_search(A, n - 1, key);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << recursive_lin_search(arr, 5, 6);
    return 0;
}