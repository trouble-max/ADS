//https://informatics.msk.ru/mod/statements/view.php?id=53942&chapterid=52#1

#include <iostream>
#include <string>

using namespace std;

struct node{
  string val;
  node * next;
  node * prev;
  node(string x){
    val = x;
    next = NULL;
    prev = NULL;
  }
};

struct stack{
  private:
    node * top;
  public:
    stack(){
      top = NULL;
    }

    string back(){
      return top->val;
    }

    void push(string x){
      node * item = new node(x);
      if(top != NULL){
        top->next = item;
        item->prev = top;
        top = item;
      }
      else top = item;
    }

    void pop(){
      top = top->prev;
      if(top != NULL) top->next = NULL;
    }

    int size(){
      int count = 0;
      node * curr = top;
      while(curr != NULL){
        curr = curr->prev;
        count++;
      }
      return count;
    }

    void clear(){
      node * curr = top;
      while(curr != NULL){
        curr = curr->prev;
        if(curr != NULL) curr->next = NULL;
      }
      top = curr;
    }
    
    string second_num(){
        return (top->prev)->val;
    }
};

int main(){
    string s;

    int temp;

    stack * st = new stack();

    while(cin >> s){
        if(s == "+" || s == "-" || s == "*"){
            int x, y;
            x = stoi(st->second_num());
            y = stoi(st->back());
            if(s == "+"){
                temp = x + y;
                st->pop();
                st->pop();
                st->push(to_string(temp));
            } else if(s == "-"){
                temp = x - y;
                st->pop();
                st->pop();
                st->push(to_string(temp));
            } else{
                temp = x * y;
                st->pop();
                st->pop();
                st->push(to_string(temp));
            }
        } else st->push(s);
    }

    cout << st->back();

    return 0;
}