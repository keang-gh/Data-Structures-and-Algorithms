/*************************************
 * 内容：优先级队列
 * Kang_2024.11.23
 ************************************/
#include <iostream>
#include <functional>
#include <cstring>
using namespace std;

// 优先队列的实现  priority_queue(push pop top empty size)
class PriorityQueue
{
public:
    using Comp = function<bool(int, int)>;
    PriorityQueue(int cap = 20, Comp comp = greater<int>())
        : size_(0), cap_(cap), comp_(comp)
    {
        que_ = new int[cap_];
    }

    PriorityQueue(Comp comp = greater<int>())
        : size_(0), cap_(20), comp_(comp)
    {
        que_ = new int[cap_];
    }

    ~PriorityQueue()
    {
        delete[] que_;
        que_ = nullptr;
    }

    // 入堆
    void push(int val)
    {
        // 判断扩容
        if (size_ == cap_)
        {
            int *p = new int[2 * cap_];
            memcpy(p, que_, cap_ * sizeof(int));
            delete[] que_;
            que_ = p;
            cap_ *= 2;
        }

        if (size_ == 0)
        {
            // 只有一个元素，不用进行堆的上浮调整
            que_[size_] = val;
        }
        else
        {
            // 堆里面有多个元素，需要进行上浮调整
            siftUp(size_, val);
        }
        size_++;
    }
private:
    // 入堆上浮调整
    void siftUp(int i,int val)
    {
        while(i>0)  // 最多计算到根节点（0号位）
        {
            int father = (i - 1) / 2;
            if(comp_(val,que_[father]))
            {
                que_[i] = que_[father];
                i = father;
            }
            else
            {
                break;
            }
        }
        que_[i] = val;
    }

private:
    int *que_;  // 指向动态扩容的数组
    int size_;  // 数组元素的个数
    int cap_;   // 数组的总空间大小
    Comp comp_; // 比较器对象
};

int main()
{

    return 0;
}
