# C++从入门到入土

![](https://img2.baidu.com/it/u=2732260051,406278259&fm=253&fmt=auto&app=138&f=JPG?w=889&h=500)

其实基本语法都是差不多的，这边都不再多介绍了

------

## C++ 使用外部文件引入

### 1.创建头文件和源文件

**(头文件写函数声明，源文件中写函数定义）**

下面举个栗子

**头文件** swap.h

```c++
#include <iostream>

using namespace std;

int swap(int num1, int num2);
```

源文件 swap.cpp

```c++
#include "swap.h"


int swap(int num1, int num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl;

}
```

一顿操作完之后在main.cpp 中写

```c++
#include "sourcefile/swap.h" //引入自定义头文件 用"" 来引入
```

然后引入完头文件后在就可以直接使用自定义的函数了

---

## 指针

没错又到了C/C艹 最经典的函数指针部分了

### 指针的基本使用

废话不说了直接上代码

```c++
#include <iostream>

using namespace std;

int main() {
    //1.定义指针
    int a = 10;
    //指针定义的语法： 数据类型 * 指针变量名
    int *p;
    //让指针记录变量a 的地址
    p = &a;  //&是一个取址的符号，这行代码的意思就是让指针p 取到变量a的地址
    //打印变量a 的地址和指针p的地址康康
    cout << "a's momory address:" << &a << endl;
    cout << "p's memory address:" << p << endl;


    //2.使用指针
    //可以通过解引用的方式来找到指针指向的内存
    //指针前加 * 表示解引用，找到指针指向的内存中的数据
    *p = 1000;
    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;
    return 0;
}
```

```c++
result:
a's momory address:0x61fe14
p's memory address:0x61fe14
a=1000
*p=1000
```

### 指针所占内存空间

不管是什么数据类型指针都是如下所示：

32位系统的指针一般站**4个字节**

64位系统的指针占**8个字节**

```c++
#include <iostream>

using namespace std;

int main() {
    //1.定义指针
    int a = 10;
    //指针定义的语法： 数据类型 * 指针变量名
    int *p;
    //让指针记录变量a 的地址
    p = &a;  //&是一个取址的符号，这行代码的意思就是让指针p 取到变量a的地址

    cout << "sizeof(int *)" << sizeof(int *) << endl;  //sizeof 查看内存占用大小
    cout << "sizeof(double *)" << sizeof(double *) << endl;  //sizeof 查看内存占用大小
    cout << "sizeof(string *)" << sizeof(string *) << endl;  //sizeof 查看内存占用大小
    cout << "sizeof(char *)" << sizeof(char *) << endl;  //sizeof 查看内存占用大小
    cout << "sizeof(p)" << sizeof(p) << endl;  //sizeof 查看内存占用大小

    return 0;
}
```

```c++
result:
sizeof(int *)8
sizeof(p)8
```

### 空指针和野指针

#### 空指针

指针指向内存中**编号为0**的空间（用于初始化指针变量）（空指针指向的内存是不可以访问的）

```c++
#include <iostream>

using namespace std;

int main() {
    //定义空指针
    int *p = NULL;


    //空指针是不可以访问的
    //0~255 之间的内存编号是系统占用的，因此不可以访问
    *p = 100;

    return 0;
}
```

**这样写是会报错的！！！**

#### 野指针

指针指向非法的内存空间

```c++
#include <iostream>

using namespace std;

int main() {
    //定义空指针
    int *p = (int *) 0x1100;
    cout << *p << endl;
    return 0;
}
```

### const 修饰指针

1. const 修饰指针 --- 常量指针 (指针的**指向**可以修改，但是指针指向的值不能修改)
2. const 修饰常量 --- 指针常量(不可以修改指针的方向，但是可以修改指针的指向的值)
3. const 既修饰**指针**又修饰**常量**(指针的指向和值**都**不能修改)

#### 常量指针

```c++
#include <iostream>

using namespace std;

int main() {
	int a = 10;
	int b = 20;
    
    const int *p = &a; //指针常量，指针的指向可以修改，但是指针指向的值不能修改
	*p = &b;
    cout << *p << endl;
    return 0;
}
```

#### 指针常量

```c++
#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int b = 20;
    int *const p = &a; //看 const 屁股后面跟的是谁 如果屁股后面跟着的是常量，那么这个指针就是指针常量
    //指针常量的特点是不可以修改指针的方向，但是可以修改指针的指向的值
    *p = 20;
//    *p = &b;不能这么写

    return 0;
}
```

#### 既指向指针又指向常量

```c++
#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int b = 20;
    const int *const p = &a; //这就是const 既指向指针又指向值
    //特点是指针的指向和值都不能修改
    return 0;
}
```

### 指针和数组

路利用指针访问数组中的元素

```c++
#include <iostream>

using namespace std;

int main() {

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "one:" << arr[0] << endl;

    //创建指针 指向arr数组
    int *p = arr;
    //利用指针访问数组的第一个元组
    cout << " user point first element is :" << *p << endl;
    p++;
    //让指针偏移8个字节
    cout << " user point second element is :" << *p << endl;

    return 0;
}
```

利用指针遍历数组

```c++
#include <iostream>

using namespace std;

int main() {

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //创建指针 指向arr数组
    int *p = arr;
    for (int i = 0; i < 10; i++) {
        cout << *p << endl;
        p++;
    }
    return 0;
}
```

### 指针和函数

上面学习函数的时候学过函数的值传递，发现swap交换位置能改变形参的值，但是无法影响实参的值，接下来对这个函数进行修改，将指针传入

```c++
#include <iostream>

using namespace std;

//创建函数
void swap(int *pa, int *pb) {
    int tmep = *pa;
    *pa = *pb;
    *pb = tmep;
}


int main() {
    int a = 10;
    int b = 20;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    //传入值的时候注意传入的是值的地址
    swap(&a, &b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    return 0;
}
```

```c++
result:
a=10
b=20
a=20
b=10
```

可见**地址传递**可以改变实参的值

### 小test：使用函数指针的方式实现冒泡排序

```c++
#include <iostream>

using namespace std;

//创建函数
void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {
    int arr[10] = {1, 6, 4, 6, 7, 8, 4, 4, 3, 3};
    //函数调用时，int 地址的传递需要加&,数组的传递默认为其地址，所以不用加&
    bubbleSort(arr, 10);
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}
```

## 结构体

结构体属于用户自定义的数据类型，允许用户存储不同的数据类型（学过 Java 的话这个结构体就像Java 里的**实体类**）

```c++
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
    Student s1;
    //struct Student s1; //结构体对象创建时 struct 关键字可以不写
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
```

### 结构体数组

```c++
#include <iostream>

using namespace std;

//定义结构体数组
struct Student {

    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;

};

int main() {
    //创建结构体数组
    Student stuArray[3] = {
            {"zhangsan", 18, 100},
            {"lisi",     28, 100},
            {"kakka",    38, 199}};

    //遍历结构体数组
    for (int i = 0; i < 3; ++i) {
        cout << stuArray[i].name << endl;
        //接下来的遍历以此类推
    }

    //给结构体数组中元组赋值

    return 0;
}
```

### 结构体指针

- 通过利用操作符 ->  通过结构体指针访问结构体属性

```c++
#include <iostream>

using namespace std;

//定义结构体数组
struct Student {

    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;

};


int main() {
    //创建结构体变量
    Student student = {"Zhangsan", 18, 100};

    //通过指针指向结构体变量
    Student *p_student = &student;

    //通过指针访问结构体变量
    cout << p_student->name << endl; //指针通过箭头进行访问结构体变量
    

    return 0;
}
```

### 结构体嵌套结构体

结构体成员可以是另一个结构体

```c++
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
//定义老师结构体
struct teacher {
    int id;
    string name;
    int age;
    struct Student stu; //在上边定义了学生结构体
};
int main() {
    //结构体嵌套结构体
    //创建老师
    teacher t;
    t.name = "Luoxiang";
    t.age = 40;
    t.id = 1000;
    t.stu.name = "Zhangsan"; //老师结构体内有学生结构体所以直接调用就可以，很像Java中的链式调用
    t.stu.age = 100;
    t.stu.score = 100;
    return 0;
}
```

### 结构体做函数参数

具体代码如下

```c++
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

```

### 结构体const使用场景

**作用：**用const来防止误操作

相对于值传递，指针的大小就占用8个字节的大小（64位系统）

```c++
//学生结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//const使用场景
void printStudent(const student *stu) //加const防止函数体中的误操作
{
	//stu->age = 100; //操作失败，因为加了const修饰
	cout << "姓名：" << stu->name << " 年龄：" << stu->age << " 分数：" << stu->score << endl;

}

int main() {

	student stu = { "张三",18,100 };

	printStudent(&stu);

	system("pause");

	return 0;
}
```

还记得我们上面讲的一大堆的 常量和指针的关系嘛

这里加的就是常量指针它的特性就是可以修改指针的指向，但是不能修改指针的所指向的值

## new 操作符

C++中利用new 操作符在堆区中开辟数据

堆区开辟数据，由程序员手动开辟，手动释放，释放利用操作符delete (和Java简直就是一摸一样)

```c++
#include <iostream>

using namespace std;

//在堆区利用new 创建int
int *func() {
    //在堆区创建int数据
    //返回的是一个int 类型的指针
    int *pInt = new int(10);
    return pInt;
}

//在堆区利用new 开辟数组
int *func2() {
    int *pInt = new int[10];
    //给数组中的元素进行赋值
    for (int i = 0; i < 10; ++i) {
        pInt[i] = i + 100;
    }
    return pInt;
}

int main() {
    //new 基本语法
    int *pInt = func();
    cout << pInt << endl;
    cout << pInt << endl;
    cout << pInt << endl;
    //堆中开辟的数据，需要程序员自己去释放
    delete pInt;
    cout << "delete latter:" << pInt << endl;

    //创建堆区数组
    int *p_arr2 = func2();
    cout << p_arr2 << endl;
    //释放堆区数组,要使用delete[]
    delete[] p_arr2;
    return 0;
}
```

## 引用

给变量起别名

**用法** ： 数据类型 & 别名 = 原名

```c++
#include <iostream>

using namespace std;


int main() {
    int a = 10;
    //创建引用
    int &b = a;
    cout << "a = " << a << endl;
    //可以通过b 修改 a 的值 因为 a,b现在都指向同一块内存
    b = 20;
    cout << "b = " << a << endl;
    return 0;
}
```

```C++
result:
a = 10
b = 20
```

### 引用的注意事项

- 引用必须初始化
  - 引用在初始化后不可以再改变

```c++
#include <iostream>

using namespace std;


int main() {
    int a = 10;
    //创建引用
    int &b = a; //应用必须初始化
//    int &b; (不可以这么写)
    int c = 30;

    b = c;  //等号是赋值操作不是更改引用
    cout << b << endl;
    return 0;
}
```

### 引用做函数参数

可以简化指针修改实参

>  (其实可以把引用理解为指针常量，可以修改值，但是不能修改指向的地址)

```c++
#include <iostream>

using namespace std;

//实现交换函数
//1.值传递
void swap01(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

//地址传递
void swap02(int *p_a, int *p_b) {
    int temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;
}

//引用传递
void swap03(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 1;
    int b = 11;

//    swap01(a, b); //值传递  发现值并没有进行变化
//    swap02(&a, &b); //地址传递 发现值发生交换了
//    swap03(a, b); //发现值也发生交换了
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
```

### 引用作为函数的返回值

- 注意：不要返回局部变量引用
- 用法： 函数调用作为左值

不要返回局部变量引用

```c++
#include <iostream>

using namespace std;

//创建一个函数返回局部引用
int & function() {
    int a = 10; //创建一个局部变量，存放在第四区，栈区中
    return a;
}


int main() {
    int &i = function();
    cout << i << endl;
    return 0;
}
```

函数调用作为左值

```c++
#include <iostream>

using namespace std;


//在函数调用时可以作为左值
int & function() {
    static int a = 10; //创建一个静态变量存放在全局区，这里的数据在程序结束后由系统释放
    return a;

}


int main() {
    int &i = function();
    cout << i << endl;
    function() = 1000; //在函数调用时可以作为左值
    cout << i << endl; //发现最后变成1000了 所以在函数调用时可以作为左值
    return 0;
}
```

### 引用的本质

>  引用的本质在C++内部实现一个指针常量

当我们在使用引用时，如果被编译器识别到会自动转换转换成一个指针常量,指针常量的指向是不可改的，这也就说明了为什么引用不可以更改指向

```c++
//发现是引用，转换为 int* const ref = &a;
void func(int& ref){
	ref = 100; // ref是引用，转换为*ref = 100
}
int main(){
	int a = 10;
    
    //自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
	int& ref = a; 
	ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;
    
	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;
    
	func(a);
	return 0;
}
```

结论：C++推荐用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了

### 常量引用

**作用：**常量引用主要用来修饰形参，防止误操作

在函数形参列表中，可以加==const修饰形参==，防止形参改变实参

```c++
#include <iostream>

using namespace std;

//打印函数
void function(const int &num) {
    //num = 100; //在形参上加入const 就不可以修改了
    cout << num << endl;
}

int main() {
    //常量引用
    //使用场景，用来修饰形参，防止误操作
    int a = 10;
    const int &ref = 110; //加入const 后 编译器将代码修改为 int temp =10; const int & ref = temp;
//    ref = 20; 加入const 后ref就变成了只读，不可以修改
    function(ref);

    return 0;
}
```

