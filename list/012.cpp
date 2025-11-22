/************************************* 
* 内容：（1）双向链表的定义 （2）操作：头插法、尾插法、遍历、删除、查找
* 周康 2024.11.12
**************************************/

#include<iostream>
using namespace std;

// 定义双向链表的节点类型
struct Node
{
    Node(int val=0)
        :val_(val)
        ,next_(nullptr)
        ,pre_(nullptr)
    {}
    int val_;      // 数据域
    Node *next_;    // 后继节点
    Node *pre_;     // 前驱节点
};

// 双向链表
class DoubleLink
{
public:
    DoubleLink()
    {
        head_ = new Node();
    }

    ~DoubleLink()
    {
        Node *p = head_;
        while(p!=nullptr)
        {
            head_=head_->next_;
            delete p;
            p = head_;   // 哨兵节点，不存储有效数据
        }
    }

public:
    // 头插法   
    void insertHead(int val)
    {
        Node *new_node = new Node(val);
        new_node->next_ = head_->next_;
        new_node->pre_ = head_;
        if(head_->next_!=nullptr)
        {
            head_->next_->pre_ = new_node;
        }
        head_->next_ = new_node;
    }

    // 尾插法
    void insertTail(int val)
    {
        Node *p = head_;
        while(p->next_!=nullptr)
        {
            p = p->next_;
        }

        // p->尾节点
        Node *new_node = new Node(val);
        p->next_ = new_node;
        new_node->pre_= p;
    }

    // 节点删除
    void remove(int val)
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if(p->val_==val)
            {
                p->pre_->next_ = p->next_;
                if(p->next_!=nullptr)
                {
                    p->next_->pre_ = p->pre_;
                }
                delete p;
                return;
                // 如果是删除所有val的节点
                // Node *next=p->next_;
                // delete p;
                // p=next;
            }
            else
            {
                p = p->next_;
            }
        }
    }

    // 节点搜索
    bool find(int val)
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if(p->val_==val)
            {
                return true;
            }
            p = p->next_;
        }
        return false;
    }

    // 链表节点的输出函数
    void show()
    {
        Node *p = head_->next_;
        while(p)
        {
            cout << p->val_ << " ";
            p = p->next_;
        }
        cout << endl;
    }

private:
    Node *head_;   // 指向头节点
};

int main()
{
    DoubleLink dl;
    dl.insertTail(20);
    dl.insertTail(12);
    dl.insertTail(30);
    dl.insertTail(23);
    dl.insertTail(9);
    dl.insertTail(92);
    //dl.show();

    // dl.insertHead(999);
    // dl.show();

    // dl.remove(9);
    // dl.show();

    // dl.remove(999);
    // dl.remove(92);
    // dl.show();

    cout << dl.find(301) << endl;

    return 0;
}