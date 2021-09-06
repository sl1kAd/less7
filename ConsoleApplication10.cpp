#include <iostream>

using namespace std;

void Ex2(char*, int);
void Ex21(char*, int, int);


void Ex1()
{
    int const n = 12;

    int* arr = new int[n];

    cout << "Enter an array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] % 2 == 0 && arr[j] % 2 == 0 && arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << "Output of the program: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;

    system("pause");
}


int main()
{
    Ex1();

    Ex2();

}


void Ex2(char* items, int count)
{
    Ex21(items, 0, count - 1);
}

 
void Ex21(char* items, int left, int right)
{
    register int i, j;

    char x, y;

    i = left; j = right;

    x = items[(left + right) / 2]; 

    do
    {
        while ((items[i] < x) && (i < right))
        {
            i++;
        }
        while ((x < items[j]) && (j > left))
        {
            j--;
        }

        if (i <= j)
        {
            y = items[i];

            items[i] = items[j];

            items[j] = y;

            i++; j--;
        }

    }     while (i <= j);

    if (left < j)
    {
        Ex21(items, left, j);
    }

    if (i < right)
    {
        Ex21(items, i, right);
    }
}