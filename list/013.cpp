/*******************************************
 * 内容：（1）双向循环链表的定义内容 （2）操作：头插法、尾插法、遍历、删除、查找
 * Kang_2024.11.12
 *******************************************/
#include <iostream>
using namespace std;

// 双向循环链表的节点类型
struct Node
{
    Node(int val = 0)
        : val_(val), next_(nullptr), pre_(nullptr)
    {
    }
    int val_;    // 数据域
    Node *next_; // 后继指针域
    Node *pre_;  // 前驱指针域
};

// 双向循环链表
class DoubleCircleLink
{
public:
    DoubleCircleLink()
    {
        head_ = new Node();
        head_->next_ = head_;
        head_->pre_ = head_;
    }

    ~DoubleCircleLink()
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

public:
    // 头插法  O(1)
    void insertHead(int val)
    {
        Node *new_node = new Node(val);
        new_node->next_ = head_->next_;
        new_node->pre_ = head_;
        head_->next_->pre_ = new_node;
        head_->next_ = new_node;
    }

    // 尾插法
    void insertTail(int val)
    {
        Node *p = head_->pre_;
        Node *new_node = new Node(val);
        new_node->pre_ = p;
        p->next_ = new_node;
        new_node->next_ = head_;
        head_->pre_ = new_node;
    }
    
    // 节点删除
    void remove(int val)
    {
        Node *p = head_->next_;
        while(p!=head_)
        {
            if(p->val_==val)
            {
                p->pre_->next_ = p->next_;
                p->next_->pre_ = p->pre_;
                delete p;
                return;
            }
            else
            {
                p = p->next_;
            }
        }
    }

    // 节点的搜索
    bool find(int val)
    {
        Node *p = head_->next_;
        while(p!=head_)
        {
            if(p->val_==val)
            {
                return true;
            }
            else
            {
                p = p->next_;
            }
        }
        return false;
    }

    // 链表节点的输出
    void show()
    {
        Node *p=head_->next_;
        while(p!=head_)
        {
            cout << p->val_<< " ";
            p = p->next_;
        }
        cout << endl;
    }

private:
    Node *head_;
};

int main()
{

    return 0;
}
