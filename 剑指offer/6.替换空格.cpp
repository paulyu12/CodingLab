#include <iostream>

using namespace std;

/**
 * 替换空格
 * @param str
 * @param length length 是字符数组 str 的申请空间，需要在替换空格前后都是足量的
 */
void ReplaceBlank(char str[], int length) {
    int numOfSpace = 0, len = 0;
    for (int i = 0; str[i] != '\0'; i ++) {
        len ++;
        if (str[i] == ' ') {
            numOfSpace ++;
        }
    }

    int newLen = len + 2 * numOfSpace;
    if (newLen > length) {
        return;
    }

    int rawStrIndex = len - 1, newStrIndex = newLen - 1;
    while (rawStrIndex >= 0 && newStrIndex > rawStrIndex) {
        if (str[rawStrIndex] == ' ') {
            str[newStrIndex --] = '0';
            str[newStrIndex --] = '2';
            str[newStrIndex --] = '%';
        }
        else {
            str[newStrIndex --] = str[rawStrIndex];
        }

        rawStrIndex --;
    }
}
