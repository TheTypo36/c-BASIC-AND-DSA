template <typename T>
class Deque
{

    T *data;
    int front;
    int rear;
    int size;

public:
    Deque(int capacity)
    {
        data = new T[capacity];
        front = -1;
        rear = -1;
        size = capacity;
    }
    T getFront()
    {
        if (front == -1 && rear == - 1)
        {
         
            return 0;
        }
        return data[front];
    }
    T getRear()
    {
        if (front == -1&& rear ==- 1)
        {
            return 0;
        }
        return data[rear];
    }
    void insertFront(T x)
    {
        if ((front == rear + 1) || (front == 0 && rear == size - 1))
        {
            printf("%d\n", -1);
            return;
        }
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            data[front] = x;
        }
        else if (front == 0)
        {
            front = size - 1;
            data[front] = x;
        }
        else
        {
            front--;
            data[front] = x;
        }
    }
    void insertRear(T x)
    {
        if ((front == rear + 1) || (front == 0 && rear == size - 1))
        {
            printf("%d\n", -1);
            return;
        }
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            data[rear] = x;
        }
        else if (rear == size - 1)
        {
            rear = 0 ;
            data[rear] = x;
        }
        else
        {
            rear++;
            data[rear] = x;
        }
    }
    void deleteFront()
    {
        if (front == -1 && rear == -1)
        {
            printf("%d\n", -1);
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    void deleteRear()
    {
        if (front == -1 && rear == -1)
        {
            printf("%d\n", -1);
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = size-1;
        }
        else {
            rear --;
        }
        
    }
};