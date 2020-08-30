#include <vector>
using namespace std;
class priorityQueue
{
    vector<int> pq;

public:
    priorityQueue()
    {
    }
    int getSize()
    {
        return this->pq.size();
    }
    bool isEmpty()
    {
        return this->pq.size() == 0;
    }
    int getMin()
    {
        if (isEmpty())
        {
            return -1;
        }
        return this->pq[0];
    }
    void insert(int data)
    {
        pq.push_back(data);
        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    int removeMin() {
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        while (parentIndex < pq.size())
        {
            int leftchild = (2 * parentIndex) + 1;
            int rightchild = (2 * parentIndex) + 2;
            if(leftchild>=pq.size()){
                break;
            }
            if (pq[parentIndex] > min(pq[leftchild], pq[rightchild]))
            {
                int childIndex = (pq[leftchild]<pq[rightchild])?leftchild:rightchild;
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
                parentIndex = childIndex;
            }else{
                break;
            }
            
        }
        return ans;
    }
};