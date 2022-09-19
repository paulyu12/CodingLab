#include <iostream>

using namespace std;

int test(int arr[]) {
    return sizeof arr;
}

int main() {

    int arr[] = {1, 2, 3};
    int *parr = arr;

    cout << "sizeof arr[]: " << sizeof arr << endl;
    cout << "sizeof parr: " << sizeof parr << endl; // 指针的 size: 64 bit 编译器为 8, 32 位编译器为 4
    cout << "sizeof parameter arr[]: " << test(arr) << endl;
    cout << "length of arr: " << sizeof arr / sizeof(int) << endl; // 计算数组的元素个数

    return 0;

}