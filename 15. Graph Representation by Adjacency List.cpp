#include <iostream>
using namespace std;

/*Node Class*/
class Node {
private:
    int object;
    Node* nextNode;

public:
    int get() {
        return object;
    }
    void set(int addObject) {
        object = addObject;
    }

    Node* getNext() {
        return nextNode;
    }
    void setNext(Node* nextNode) {
        this->nextNode = nextNode;
    }
};

/*List Class*/
class List {
private:
    Node* headNode;
    Node* currentNode;
    Node* lastCurrentNode;
    int size;

public:
    /*Constructor*/
    List() {
        headNode = new Node();
        headNode->setNext(NULL);
        currentNode = NULL;
        lastCurrentNode = NULL;
        size = 0;
    }
    /*Destructor*/
    ~List() {
        Node* currentNode = headNode->getNext();
        Node* newNode;
        while (currentNode != NULL) {
            newNode = currentNode->getNext();
            delete currentNode;
            currentNode = newNode;
        }
        delete headNode;
    }

    /*Other member functions*/
    void add(int addObject);
    bool next();
    int get();
    friend void traverse(List list);
};


class ArrayList {
private:
    List list;

public:
    void addList(int vertex) {
        list.add(vertex);
    }
    void print() {
        traverse(list);
    }
};

/*add function*/
void List::add(int addObject) {
    Node* newNode = new Node();
    newNode->set(addObject);
    if (currentNode != NULL) {
        newNode->setNext(currentNode->getNext());
        currentNode->setNext(newNode);
        lastCurrentNode = currentNode;
        currentNode = newNode;
    }
    else {
        newNode->setNext(NULL);
        headNode->setNext(newNode);
        lastCurrentNode = headNode;
        currentNode = newNode;
    }
    size++;
}

/*get function*/
int List::get() {
    if (currentNode != NULL) {
        return currentNode->get();
    }
    // Handle this case, for example, by throwing an exception or returning a default value
    throw "List is empty or current node is NULL";
}

/*next function*/
bool List::next() {
    if (currentNode != NULL) {
        lastCurrentNode = currentNode;
        currentNode = currentNode->getNext();
    }
    else {
        return false;
    }
    if (currentNode == NULL || size == 0) {
        return false;
    }
    else {
        return true;
    }
}

/*traverse function*/
void traverse(List list) {
    Node* currentNode = list.headNode->getNext();
    int i = 0;
    while (currentNode != NULL) {
        cout <<currentNode->get() << "\t";
        currentNode = currentNode->getNext();
    }
    cout<<"\n";
}

int main() {
    int v, e;
    char type;

    cout << "Please tell that graph is directed or undirected? Tell by the letter d or u: ";
    cin >> type;
    cout << "Please enter the number of vertices: ";
    cin >> v;
    cout << "Please enter the number of edges: ";
    cin >> e;

    ArrayList arrList[v + 1];
    cout << "Please enter the vertices which have edges between them:\n";
    for (int i = 1; i <= e; i++) {
        int j, k;
        cout << "Node: ";
        cin >> j;
        cout << "with ";
        cin >> k;
        arrList[j].addList(k);
        if (type == 'u') {
            arrList[k].addList(j);
        }
    }

    for (int i = 1; i <= v; i++) {
        cout << "For "<<i<<":\t";
        arrList[i].print();
        cout << endl;
    }
}
