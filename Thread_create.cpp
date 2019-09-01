#include <iostream>
#include <thread>
Using namespace std;

void helloFunction() 
{
    cout << "Hello C++11 from function." << std::endl;
}

class HelloFunctionObject 
{
public:
    void operator()() const 
    {
        cout << "Hello C++11 from a function object." << std::endl;
    }
};

int main() {
    // 线程执行函数 helloFunction
    thread t1(helloFunction);
    // 线程执行函数对象 helloFunctionObject
    HelloFunctionObject helloFunctionObject;
    thread t2(helloFunctionObject);
    thread t3([] //lambda方式
    {
        cout << "Hello C++11 from lambda function." << endl; 
    });

//加入线程
    t1.join();
    t2.join();
    t3.join();
    cout << endl;
};
