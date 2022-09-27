#include <iostream>

using namespace std;


//定义学生结构体
struct Student {

    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;

};

//值传递
void printStudent1(struct Student student) {
    //值传递修改值是不会对实参造成改变的
    student.age = 100;

    cout << student.name << endl;
}

//地址传递
void printStudent2(struct Student *p_student) {
    cout << p_student->name << endl;
    //地址传递修改值的话是会对实参造成改变的
    p_student->age = 1000;
}

int main() {
    //结构体做函数参数
    Student student = {"Zhangsan", 18, 100};
    //结构体值传递
    printStudent1(student);
    //结构体地址传递
    printStudent2(&student);

    return 0;
}
