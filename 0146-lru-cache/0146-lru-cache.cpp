class Node
{
    public:
    int key, value;
    Node* prev, *next;
    Node(int k, int v)
    {
        key = k;
        value=v;
        prev= NULL;
        next= NULL;
        
    }
};
class LRUCache {
public:
    int cap;
    Node* head, *tail;
    map<int,Node*>mp;
    LRUCache(int capacity) {
        head = new Node(-1,-1);
        tail= new Node(-1,-1);
        head->next= tail;
        tail->next= head;
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        else 
        {
            Node* delNode= mp[key];
            deleteNode(delNode);
            insert(delNode);
            return delNode->value;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* delNode= mp[key];
            deleteNode(delNode);
            delNode->value= value;
            insert(delNode);
        }
        else 
        {
            Node* temp= new Node(key,value);
            if(mp.size()<cap)
            {
                
                insert(temp);
            }
            else 
            {
                deleteNode(tail->prev);
                insert(temp);
            }
        }
    }
    
    void insert(Node* temp)
    {
        Node* a= head->next;
        mp[temp->key]= temp;
        temp->next= a;
        a->prev= temp;
        head->next= temp;
        temp->prev= head;
    }
    
    void deleteNode(Node *temp)
    {
        mp.erase(temp->key);
        Node* b= temp->next, *a= temp->prev;
        a->next= b;
        b->prev= a;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */