//https://informatics.msk.ru/mod/statements/view.php?id=53942&chapterid=58#1

#include <iostream>

using namespace std;

struct node{
    int val;
    node * next;
    node * prev;
    node(int x){
        val = x;
        prev = NULL;
        next = NULL;
    }
};

struct queue{
    private:
        node * head;
        node * curr;
    public:
    queue(){
        head = NULL;
        curr = NULL;
    }

    int front(){
        return head->val;
    }

    void push(int x){
        node * item = new node(x);
        if(head == NULL){
            head = item;
            curr = head;
        }else{
            curr->next = item;
            item->prev = curr;
            curr = item;
        }
    }

    void pop(){
        head = head->next;
        if(head != NULL) head->prev = NULL;
    }

    int size(){
      int count = 0;
      node * curr1 = head;
      while(curr1 != NULL){
        curr1 = curr1->next;
        count++;
      }
      return count;
    }

    void clear(){
      node * curr1 = head;
      while(curr1 != NULL){
        curr1 = curr1->next;
        if(curr1 != NULL) curr1->prev = NULL;
      }
      head = curr1;
    }

};

int main(){
    string s;

    queue * q = new queue();

    while(cin >> s){
        if(s == "exit"){
            cout << "bye" << endl;
            break;
        }
        else if(s == "push"){
            int x;
            cin >> x;
            q->push(x);
            cout << "ok" << endl;
        }
        else if(s == "pop"){
            int x = q->size();
            if(x == 0){
                cout << "error" << endl;
            } 
            else{
                cout << q->front() << endl;
                q->pop();
            }
        }
        else if(s == "front"){
            int x = q->size();
            if(x == 0){
                cout << "error" << endl;
            } else cout << q->front() << endl;
        }
        else if(s == "size"){
            cout << q->size() << endl;
        }
        else if(s == "clear"){
            cout << "ok" << endl;
            q->clear();
        }
    }

    return 0;
}