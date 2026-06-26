class Node
{
public:
    int key, val;
    Node *next;
    Node *prev;

    Node(int _key, int _val)
    {
        key = _key;
        val = _val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache
{
public:
    unordered_map<int, Node *> mp;
    int cap;
    Node *head, *tail;

    LRUCache(int capacity)
    {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNode(Node *node)
    { // adding is easy
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key)
    {

        if (mp.find(key) == mp.end())
            return -1;

        Node *node = mp[key];

        deleteNode(node);
        addNode(node);

        return node->val;
    }

    void put(int key, int value)
    {

        if (mp.find(key) != mp.end())
        {

            Node *node = mp[key];
            node->val = value;

            deleteNode(node);
            addNode(node);

            return;
        }

        // Cache full
        if (mp.size() == cap)
        {

            Node *lru = tail->prev;

            deleteNode(lru);
            mp.erase(lru->key);

            delete lru;
        }

        Node *newNode = new Node(key, value);

        addNode(newNode);
        mp[key] = newNode;
    }
};