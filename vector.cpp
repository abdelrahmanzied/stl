#include <iostream>
using namespace std;

template <class t>
class Vector {

    t *arr;
    int Capacity,Size;

public:

    Vector() {
        arr = new t[1];
        Capacity = 1;
        Size = 0;
    }

    ~Vector() {clear();}

    void push_back(int value) {

        if (Size == Capacity) {
            t *temp = new t[2 * Capacity];

            for (int i = 0; i < Capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            Capacity *= 2;
            arr = temp;
        }

        arr[Size] = value;
        Size++;
    }

    void push(t value, int index) {
        if (index == Capacity)
            push_back(value);
        else
            arr[index] = value;
    }

    void assign(int size, t value) {
        Capacity = size * 2;
        Size = 0;
        for (int i=0; i<size; i++)
            push_back(value);

    }

    void pop() {Size--;}

    t get(int index)
    {
        if (index < Size)
            return arr[index];
    }

    int capacity() { return Capacity;}
    int size() { return Size;}

    void clear() {
        Capacity =1;
        Size = 0;
        delete[] arr;
    }

    t begin() {return arr[0];}
    t end() {return arr[Size - 1];}

    bool empety() {
        if (Size == 0) return 1;
        else return 0;
    }

    void print() {
        for (int i=0; i<Size; i++)
            cout << arr[i] << "\t";
        cout << endl;
    }

};

int main() {



    Vector<int> v;
    v.assign(7, 16);
    v.print();



    return 0;
}