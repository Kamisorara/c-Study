#include <iostream>

using namespace std;

//定义结构体
struct Student {
    //成员列表
    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;
} s3; //3.第三种创建方式在创建结构体时顺便创建一个结构体对象

int main() {
    //通过学生类创建具体学生
    //1.第一种方式
    struct Student s1;
    //新创建的结构体是没有值的，给结构体复制
    s1.name = "Zhangsan";
    s1.age = 18;
    s1.age = 100;

    cout << "name:" << s1.name << "age:" << s1.age << "score:" << s1.score << endl;


    //2.第二种方式
    struct Student s2 = {"Lisi", 19, 100};
    cout << "name:" << s2.name << "age:" << s2.age << "score:" << s2.score << endl;

    return 0;
}
