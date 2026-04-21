#include "LinkedHashMap.hpp"
#include <algorithm>

LinkedHashMap::LinkedHashMap(int _len_, bool forEachByTime){
    len = _len_;
    beg = nullptr;
    current = nullptr;
    array = new Node*[len];
    for(int i=0;i<len;++i) array[i] = nullptr;
    forEachMethod = forEachByTime ? traverseByTime : traverseByIndex;
}

LinkedHashMap::~LinkedHashMap(){
    if(!array) return;
    for(int i=0;i<len;++i){
        Node* p = array[i];
        while(p){ Node* nxt=p->next; delete p; p=nxt; }
        array[i]=nullptr;
    }
    delete [] array; array=nullptr; beg=nullptr; current=nullptr;
}

void LinkedHashMap::insert(int key, string value){
    Node* node = new Node(); node->key=key; node->value=value;
    node->next = array[key]; array[key]=node;
    node->timePre = current; node->timeNext=nullptr;
    if(current) current->timeNext = node;
    current = node; if(!beg) beg=node;
}

void LinkedHashMap::remove(int key, string value){
    Node* prev=nullptr; Node* p=array[key];
    while(p){
        if(p->value==value){
            if(prev) prev->next=p->next; else array[key]=p->next;
            if(p->timePre) p->timePre->timeNext = p->timeNext; else beg = p->timeNext;
            if(p->timeNext) p->timeNext->timePre = p->timePre; else current = p->timePre;
            delete p; return;
        }
        prev=p; p=p->next;
    }
}

vector<string> LinkedHashMap::ask(int key) const{
    vector<string> res; Node* p=array[key];
    while(p){ res.push_back(p->value); p=p->next; }
    return res;
}

vector<Data> LinkedHashMap::forEach() const{ return forEachMethod(*this); }

vector<Data> traverseByTime(const LinkedHashMap& obj){
    vector<Data> out; Node* p=obj.beg; while(p){ out.push_back(Data{p->key,p->value}); p=p->timeNext; }
    return out;
}

vector<Data> traverseByIndex(const LinkedHashMap& obj){
    vector<Data> out; for(int i=0;i<obj.len;++i){ Node* p=obj.array[i]; while(p){ out.push_back(Data{p->key,p->value}); p=p->next; } }
    return out;
}
