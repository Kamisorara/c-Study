//
// Created by Kamisora on 2022/9/25.
//

#include "swap.h"


int swap(int num1, int num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl;

}