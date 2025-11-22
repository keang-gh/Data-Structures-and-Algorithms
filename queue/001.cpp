/*****************************************
 * 内容：环形队列的实现|入队、出队、获取队头/对尾元素、判断队空、返回元素个数
 * Kang_2024.10.20
 *****************************************/
#include <iostream>
using namespace std;

// 环形队列
class Queue
{
public:
    Queue(int size = 10)
        : cap_(size), front_(0), rear_(0), size_(0)
    {
        p_que_ = new int[cap_];
    }

    ~Queue()
    {
        delete[] p_que_;
        p_que_ = nullptr;
    }

public:
    // 入队
    void push(int val)
    {
        if ((rear_ + 1) % cap_ == front_)
        {
            expand(2 * cap_);
        }

        p_que_[rear_] = val;
        rear_ = (rear_ + 1) % cap_;
        size_++;
    }

    // 出队
    void pop()
    {
        if (front_ == rear_)
        {
            throw "queue is empty!";
        }
        front_ = (front_ + 1) % cap_; // 环形队列要转起来
        size_--;
    }

    // 获取队头元素
    int front() const
    {
        if (front_ == rear_)
            throw "queue is empty!";
        return p_que_[front_];
    }

    // 获取队尾元素
    int back() const
    {
        if (front_ == rear_)
            throw "queue is empty!";
        return p_que_[(rear_ - 1 + cap_) % cap_];
    }

    // 判断队空
    bool empty() const
    {
        return front_ == rear_;
    }

    // 队列元素个数
    int size() const
    {
        // return size_;
        //  如果没有成员size_,要遍历统计
        int size = 0;
        for (int i = front_; i != rear_; i = (i + 1) % cap_)
        {
            size++;
        }
        return size;
    }

private:
    int *p_que_;
    int cap_;   // 空间容量
    int size_;  // 队列元素个数
    int front_; // 队头
    int rear_;  // 队尾

private:
    // 扩容接口
    void expand(int size)
    {
        int *p = new int[size];
        int i = 0;
        for (int j = front_; j != rear_; i++, j = (j + 1) % cap_)
        {
            p[i] = p_que_[j];
        }
        delete[] p_que_;
        p_que_ = p;
        cap_ = size;
        front_ = 0;
        rear_ = i;
    }
};

int main()
{
    int arr[]{12, 3, 44, 39, 56, 78, 66, 12, 33, 55};
    Queue que;

    for (int ele : arr)
    {
        que.push(ele);
    }

    cout << que.front() << endl;
    cout << que.back() << endl;

    que.push(100);
    que.push(200);
    que.push(300);

    cout << que.front() << endl;
    cout << que.back() << endl;

    return 0;
}