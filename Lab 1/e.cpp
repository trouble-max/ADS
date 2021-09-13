//https://informatics.msk.ru/mod/statements/view.php?id=53942&chapterid=50#1

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
    int count = 0;

    queue * q1 = new queue();
    queue * q2 = new queue();

    for(int i = 0; i <= 4; i++){
        int x;
        cin >> x;
        q1->push(x);
    }

    for(int i = 0; i <= 4; i++){
        int x;
        cin >> x;
        q2->push(x);
    }

    while(q1->size() != 0 && q2->size() != 0 && count <= 1000000){
        int x = q1->front(), y = q2->front();
        if(x == 0 && y == 9){
            q1->push(x);
            q1->push(y);
        } else if(x == 9 && y == 0){
            q2->push(x);
            q2->push(y);
        } else if(x > y){
            q1->push(x);
            q1->push(y);
        } else{
            q2->push(x);
            q2->push(y);
        }
        q1->pop();
        q2->pop();
        count++;
    }

    if(q1->size() == 0) cout << "second " << count;
    else if(q2->size() == 0) cout << "first " << count;
    else cout << "botva";
 
    return 0;
}