/**************************************
 * 内容：基于双向循环链表实现链式队列（）
 * Kang_2024.11.14
 **************************************/
#include <iostream>
using namespace std;

// 链式队列
class LinkQueue
{
public:
    LinkQueue()
    {
        head_ = new Node();
        head_->next_ = head_;
        head_->pre_ = head_;
    }

    ~LinkQueue()
    {
        Node *p = head_->next_;
        while (p != head_)
        {
            head_->next_ = p->next_;
            p->next_->pre_ = head_;
            delete p;
            p = head_->next_;
        }
        delete head_;
        head_ = nullptr;
    }

    // 入队
    void push(int val)
    {
        Node *node = new Node(val);
        Node *p = head_->pre_;
        node->next_ = head_;
        node->pre_ = p;
        p->next_ = node;
        head_->pre_ = node;
    }

    // 出队
    void pop()
    {
        Node *p = head_->next_;
        head_->next_ = p->next_;
        p->next_->pre_ = head_;
        delete p;
        p = nullptr;
    }

    // 获取队头元素
    int front() const
    {
        if (head_->next_ == head_)
        {
            throw "queue is empty!";
        }
        return head_->next_->val_;
    }

    // 获取队尾元素
    int back()
    {
        if (head_->next_ == head_)
        {
            throw "queue is empty!";
        }
        return head_->pre_->val_;
    }

    // 判空
    bool empty() const
    {
        return head_->next_ == head_;
    }

private:
    struct Node
    {
        Node(int val = 0)
            : val_(val), next_(nullptr), pre_(nullptr)
        {
        }
        int val_;
        Node *pre_;
        Node *next_;
    };

    Node *head_; // 指向toujiedian
};

int main()
{

    int arr[]{12, 3, 44, 39, 56, 78, 66, 12, 33, 55};
    LinkQueue que;

    for (int ele : arr)
    {
        que.push(ele);
    }

    cout << que.front() << endl;
    cout << que.back() << endl;

    que.push(100);
    que.push(200);
    que.push(800);

    cout << que.front() << endl;
    cout << que.back() << endl;
    return 0;
}
