#pragma once
#include <string>
#include <vector>
using namespace std;

struct Node{
    Node* next=nullptr;
    Node* timePre=nullptr;
    Node* timeNext=nullptr;
    int key=0;
    string value;
};

struct Data{ int key; string value; };
class LinkedHashMap;
vector<Data> traverseByTime(const LinkedHashMap& obj);
vector<Data> traverseByIndex(const LinkedHashMap& obj);

class LinkedHashMap{
public:
    int len;
    Node** array;
    Node* beg;
    Node* current;
    vector<Data> (*forEachMethod)(const LinkedHashMap&);
    LinkedHashMap(int _len_, bool forEachByTime);
    ~LinkedHashMap();
    void insert(int key, string value);
    void remove(int key, string value);
    vector<string> ask(int key) const;
    vector<Data> forEach() const;
};
