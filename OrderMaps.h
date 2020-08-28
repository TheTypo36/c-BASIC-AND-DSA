template <typename K,typename V>
class OrderMaps
{
private:
    K key;
    V value;
    OrderMaps<K,V> left;
    OrderMaps<K,V> right;

    OrderMaps(){
        key = NULL;
        value = NULL;
        right = NULL;
        left = NULL;
    }

public:
    OrderMaps(/* args */){
        
    }
    ~OrderMaps();
};

