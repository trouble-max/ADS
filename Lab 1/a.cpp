//https://informatics.msk.ru/mod/statements/view.php?id=53942#1

#include <iostream>

using namespace std;

struct node{
  int val;
  node * next;
  node * prev;
  node(int x){
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

    int back(){
      return top->val;
    }

    void push(int x){
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
};

int main(){
  string s;

  stack * st = new stack;

  while(cin >> s){
    if(s == "exit"){
      cout << "bye" << endl;
      break;
    }
    else if(s == "push"){
      int x;
      cin >> x;
      st->push(x);
      cout << "ok" << endl;
    }
    else if(s == "pop"){
      int x = st->size();
      if(x == 0){
        cout << "error" << endl;
      } 
      else{
        cout << st->back() << endl;
        st->pop();
      }
    }
    else if(s == "back"){
      int x = st->size();
      if(x == 0){
        cout << "error" << endl;
      } else cout << st->back() << endl;
    }
    else if(s == "size"){
      cout << st->size() << endl;
    }
    else if(s == "clear"){
      cout << "ok" << endl;
      st->clear();
    }
  }

  return 0;
}