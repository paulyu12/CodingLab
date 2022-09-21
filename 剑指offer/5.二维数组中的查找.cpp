#include <iostream>

using namespace std;

bool Find(int* matrix, int rows, int columns, int number) {

    int i = 0, j = columns - 1;

    while (i < rows && j >= 0) {
        if (*(matrix + i * rows + j) == number) {
            return true;
        }
        else if (*(matrix + i * rows + j) < number) {
            i ++;
        }
        else {
            j --;
        }
    }

    return false;

}