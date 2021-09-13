//https://informatics.msk.ru/mod/statements/view.php?id=53942&chapterid=51#1

#include <iostream>
#include <string>

using namespace std;

struct node{
  char val;
  node * next;
  node * prev;
  node(char x){
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

    char back(){
      return top->val;
    }

    void push(char x){
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

    bool check = false;

    stack * st = new stack();

    cin >> s;

    for(int i = 0; i < s.size(); i++){
        int x = st->size();
        if(s[i] == ')'){
            if(x == 0 || st->back() != '('){
                st->push(s[i]);
                break;
            }
            st->pop();
        } else if(s[i] == ']'){
            if(x == 0 || st->back() != '['){
                st->push(s[i]);
                break;
            }
            st->pop();
        } else if(s[i] == '}'){
            if(x == 0 || st->back() != '{'){
                st->push(s[i]);
                break;
            }
            st->pop();
        } else st->push(s[i]);
    }

    cout << ((st->size() == 0) ? "yes" : "no");

    return 0;
}