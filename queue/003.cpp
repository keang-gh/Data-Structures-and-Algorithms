/*********************************
 * 内容：用两个队列实现一个栈,支持push、top、pop、empty
 * 思路：q2用来存储已经调整好的栈的数据，s1存放新入栈的元素
 * Kang_2024.11.23
 ********************************/
#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    MyStack()
    {
        q1 = new queue<int>;
        q2 = new queue<int>;
    }

    ~MyStack()
    {
        delete q1;
        delete q2;
        q1 = nullptr;
        q2 = nullptr;
    }

    void push(int val)
    {
        q1->push(val);
        while(!q2->empty())
        {
            q1->push(q2->front());
            q2->pop();
        }

        queue<int> *tmp = q1;
        q1 = q2;
        q2 = tmp;
    }

    void pop()
    {
        q2->pop();
    }

    int top()
    {
        return q2->front();
    }

    bool empty()
    {
        return q2->empty();
    }

private:
    queue<int> *q1;   // 存放空的队列
    queue<int> *q2;   // 存放调整好的数据的队列
};

int main()
{
    MyStack s;
    cout << s.empty() << endl;
    s.push(3);
    s.push(2);
    s.push(4);
    s.push(53);
    cout << s.empty() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    return 0;
}
