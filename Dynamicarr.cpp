#include <iostream>
#include <stdexcept>
using namespace std;

class DynamicArray {
private:
    int* data;
    int capacity;
    int size;
    float resizeFactor;

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(float factor = 2.0) : capacity(1), size(0), resizeFactor(factor) {
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        if (size == capacity) {
            resize(capacity * resizeFactor);
        }
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void deleteAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void rotateRight(int k) {
        k = k % size;
        if (k == 0) return;
        int* temp = new int[k];
        for (int i = 0; i < k; i++) {
            temp[i] = data[size - k + i];
        }
        for (int i = size - 1; i >= k; i--) {
            data[i] = data[i - k];
        }
        for (int i = 0; i < k; i++) {
            data[i] = temp[i];
        }
        delete[] temp;
    }

    void reverse() {
        for (int i = 0; i < size / 2; i++) {
            swap(data[i], data[size - i - 1]);
        }
    }

    void append(int value) {
        if (size == capacity) {
            resize(capacity * resizeFactor);
        }
        data[size++] = value;
    }

    void prepend(int value) {
        insertAt(0, value);
    }

    DynamicArray merge(const DynamicArray& other) {
        DynamicArray result(size + other.size);
        for (int i = 0; i < size; i++) {
            result.append(data[i]);
        }
        for (int i = 0; i < other.size; i++) {
            result.append(other.data[i]);
        }
        return result;
    }

    DynamicArray interleave(const DynamicArray& other) {
        DynamicArray result;
        int minSize = min(size, other.size);
        for (int i = 0; i < minSize; i++) {
            result.append(data[i]);
            result.append(other.data[i]);
        }
        for (int i = minSize; i < size; i++) {
            result.append(data[i]);
        }
        for (int i = minSize; i < other.size; i++) {
            result.append(other.data[i]);
        }
        return result;
    }

    int getMiddle() const {
        if (isEmpty()) {
            throw out_of_range("Array is empty");
        }
        return data[size / 2];
    }

    int indexOf(int value) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    void split(int index, DynamicArray& first, DynamicArray& second) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        first = DynamicArray();
        second = DynamicArray();
        for (int i = 0; i < index; i++) {
            first.append(data[i]);
        }
        for (int i = index; i < size; i++) {
            second.append(data[i]);
        }
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << std::endl;
    }
};

int main() {
    DynamicArray arr;

    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    arr.append(5);

    arr.print(); 

    arr.insertAt(2, 10);
    arr.print(); 

    arr.deleteAt(3);
    arr.print(); 

    cout << "Size: " << arr.getSize() << endl; // 5
    cout << "Is Empty: " << (arr.isEmpty() ? "Yes" : "No") << endl; // No

    arr.rotateRight(2);
    arr.print(); 

    arr.reverse();
    arr.print(); 

    arr.prepend(20);
    arr.print(); 

    DynamicArray arr2;
    arr2.append(100);
    arr2.append(200);
    arr2.append(300);

    DynamicArray merged = arr.merge(arr2);
    merged.print(); 

    DynamicArray interleaved = arr.interleave(arr2);
    interleaved.print(); 

    cout << "Middle Element: " << arr.getMiddle() << std::endl; 

    cout << "Index of 10: " << arr.indexOf(10) << std::endl; 
    cout << "Index of 50: " << arr.indexOf(50) << std::endl; 

    DynamicArray firstHalf, secondHalf;
    arr.split(3, firstHalf, secondHalf);
    firstHalf.print(); 
    secondHalf.print(); 

    return 0;
}
