/*******************************
 * 内容：用两个栈实现队列
 * 实现思路：s1专门用来push，如果做pop与peek操作，都从s2的栈顶直接操作，如果s2是空的，把s1里面的元素全部倒到s2。
 * 复杂度分析：所有操作的均摊时间复杂度：O(1)
 * Kang_2024.12.09
 *******************************/
#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }

private:
    stack<int> s1;
    stack<int> s2;
};

int main()
{
    MyQueue q;
    cout << q.empty()<< endl;
    q.push(13);
    q.push(17);
    q.push(23);
    q.push(123);
    q.push(73);
    cout << q.empty()<< endl;
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;

    return 0;
}