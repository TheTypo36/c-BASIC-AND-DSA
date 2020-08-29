#include <string.h>
using namespace std;
template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};
template <typename V>
class OurMap
{
    MapNode<V> **bucketArray;
    int size;
    int bucNum;

public:
    OurMap()
    {
        size = 0;
        bucNum = 5;
        bucketArray = new MapNode<V> *[bucNum];
        for (int i = 0; i < bucNum; i++)
        {
            bucketArray[i] = NULL;
        }
    }
    ~OurMap()
    {
        for (int i = 0; i < bucNum; i++)
        {
            delete bucketArray[i];
        }
        delete[] bucketArray;
    }
    int getSize()
    {
        return size;
    }

private:
    int getBucketIndex(string key)
    {
        int coefficient = 1;
        int bucketIndex = 0;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            bucketIndex += key[i] * coefficient;
            bucketIndex = bucketIndex % bucNum;
            coefficient = coefficient * 37;
            coefficient = coefficient % bucNum;
        }
        return bucketIndex % bucNum;
    }
    void rehash()
    {
        MapNode<V> **temp = bucketArray;
        bucketArray = new MapNode<V> *[bucNum * 2];
        for (int i = 0; i < 2 * bucNum; i++)
        {
            bucketArray[i] = NULL;
        }
        int oldBucketNum = bucNum;
        bucNum = bucNum * 2;
        size = 0;
        for (int i = 0; i < oldBucketNum; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketNum; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    double getLoadFactor()
    {
        return (1.0 * size) / bucNum;
    }
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = bucketArray[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        MapNode<V> *newNode = new MapNode<V>(key, value);
        head = bucketArray[bucketIndex];
        newNode->next = head;
        bucketArray[bucketIndex] = newNode;
        size++;
        double loadFactor = (1.0 * size) / bucNum;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }
    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = bucketArray[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<int> *head = bucketArray[bucketIndex];
        MapNode<int> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    bucketArray[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                head->next = NULL;
                V returnValue = head->value;
                delete head;
                size--;
                return returnValue;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};