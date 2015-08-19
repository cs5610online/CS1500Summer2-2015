
#include <iostream>
using namespace std;

class Data
{
private:
    int data;
public:
    Data(int d) {
        this->data = d;
    }
    int getData() { return data; }
    void display()
    {
        cout << data << endl;
    }
};

class Node {
protected:
    Node * left = NULL;
    Node * right = NULL;
    Data * data;
public:
    Node(){}
    Node(Data * data) : Node(data, NULL, NULL)
    {
    }
    Node(Data * data, Node * left, Node * right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    Node * getLeft() { return left; }
    Node * getRight() { return right; }
    Data * getData() { return data; }
    void display()
    {
        data->display();
    }
};

class Queue {
protected:
    Node * *array;
    int front = 0, back = 0, size, count=0;
public:
    Queue(int size)
    {
        array = new Node*[size];
        this->size = size;
    }
    void enqueue(Node * node)
    {
        if(!isFull() && node != NULL)
        {
            array[back] = node;
            back = (back + 1) % size;
            count++;
        }
    }
    Node * dequeue()
    {
        Node * node = NULL;
        if(!isEmpty())
        {
            node = array[front];
            front = (front + 1) % size;
            count--;
        }
        return node;
    }
    bool isFull()
    {
        return count >= size;
    }
    bool isEmpty()
    {
        return count == 0;
    }
};

void breadthFirstTraversal(Node * root)
{
    Queue * queue = new Queue(100);
    queue->enqueue(root);
    
    while(!queue->isEmpty())
    {
        Node * node = queue->dequeue();
        node->display();
        queue->enqueue(node->getLeft());
        queue->enqueue(node->getRight());
    }
}

Data * breadthFirstSearch(Node * root, int needle)
{
    Queue * queue = new Queue(100);
    queue->enqueue(root);
    
    while(!queue->isEmpty())
    {
        Node * node = queue->dequeue();
        if(node->getData()->getData() == needle)
            return node->getData();
        queue->enqueue(node->getLeft());
        queue->enqueue(node->getRight());
    }
    return NULL;
}

int main(int argc, const char * argv[])
{
    Data * d10 = new Data(10);
    Data * d20 = new Data(20);
    Data * d30 = new Data(30);
    Data * d40 = new Data(40);
    Data * d50 = new Data(50);
    Data * d60 = new Data(60);
    Data * d70 = new Data(70);
    Data * d80 = new Data(80);
    Data * d90 = new Data(90);
    Data * d100 = new Data(100);
    Data * d110 = new Data(110);
    Data * d120 = new Data(120);
    Data * d130 = new Data(130);
    Data * d140 = new Data(140);
    Data * d150 = new Data(150);
    
    Node * n10 = new Node(d10);
    Node * n30 = new Node(d30);
    Node * n50 = new Node(d50);
    Node * n70 = new Node(d70);
    Node * n90 = new Node(d90);
    Node * n110 = new Node(d110);
    Node * n130 = new Node(d130);
    Node * n150 = new Node(d150);

    Node * n20 = new Node(d20, n10, n30);
    Node * n60 = new Node(d60, n50, n70);
    Node * n100 = new Node(d100, n90, n110);
    Node * n140 = new Node(d140, n130, n150);

    Node * n40 = new Node(d40, n20, n60);
    Node * n120 = new Node(d120, n100, n140);

    Node * n80 = new Node(d80, n40, n120);
    
    breadthFirstTraversal(n80);
    
    cout << "===" << endl;
    Data * found = breadthFirstSearch(n80, 123);
    if(found != NULL)
        found->display();
    else
        cout << "Not Found" << endl;
}
