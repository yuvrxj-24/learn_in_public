#include<iostream>
#include<vector>
#include<list>
using namespace std;


class stack
{
    vector<int> v;

public:
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        v.pop_back();

    }
    int top() {
        return v[v.size()-1];
    }
    bool empty(){
        return v.size() ==0;
    }
};
class stack1
{
    list<int> ll;
    public:

    void push(int val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    int top(){
        return ll.front();
    }
    bool empty(){
        return ll.size()==0;
    }

};
int main()
{   

    stack s;
    s.push(9);
    s.push(6);
    s.push(3);
    while (!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<< endl;
    

    stack1 s1;
    s1.push(90);
    s1.push(60);
    s1.push(30);
    while (!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
    cout<< endl;
    return 0;


}