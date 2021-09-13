//https://informatics.msk.ru/mod/statements/view.php?id=53942&chapterid=49#1

#include <iostream>

using namespace std;

struct node{
    string val;
    node * next;
    node * prev;
    node(string x){
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

    string front(){
        return head->val;
    }

    void push(string x){
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
    int x;
    string s;

    queue * q1 = new queue();
    queue * q2 = new queue();
    queue * q3 = new queue();

    while(cin >> x){
        cin >> s;
        if(x == 9){
            q1->push(s);
        }
        else if(x == 10){
            q2->push(s);
        }
        else if(x == 11){
            q3->push(s);
        }
    }

    while( q1->size() != 0){
        cout << 9 << " " <<  q1->front() << endl;
        q1->pop();
    }
    while(q2->size() != 0){
        cout << 10 << " " << q2->front() << endl;
        q2->pop();
    }
    while(q3->size() != 0){
        cout << 11 << " " << q3->front() << endl;
        q3->pop();
    }
}