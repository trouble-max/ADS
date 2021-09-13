//https://informatics.msk.ru/mod/statements/view.php?id=53942&chapterid=112984#1

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
        int sz;
    public:
    queue(){
        head = NULL;
        curr = NULL;
        sz = 0;
    }

    int front(){
        return head->val;
    }

    void push(int x){
        sz++;
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

    void push_front(int x){
        sz++;
        node * item = new node(x);
        if(head == NULL){
            head = item;
            curr = head;
        }else{
            head->prev = item;
            item->next = head;
            head = item;
        }
    }

    void pop(){
        sz--;
        head = head->next;
        if(head != NULL) head->prev = NULL;
    }

    int size(){
      return sz;
    }

    void clear(){
      node * curr1 = head;
      while(curr1 != NULL){
        curr1 = curr1->next;
        if(curr1 != NULL) curr1->prev = NULL;
      }
      head = curr1;
    }

    void print(){
        node * curr1 = head;
        while(curr1 != NULL){
            cout << curr1->val << " ";
            curr1 = curr1->next;
        }
        cout << endl;
    }

};

int main(){
    queue * q1 = new queue();
    queue * q2 = new queue();

    char c;
    int n, x;

    cin >> n;

    while(n != 0){
        cin >> c;
        if(c == '+'){
            cin >> x;
            q2->push(x);
        } else if(c == '*'){
            cin >> x;
            q2->push_front(x);
            
        } else if(c == '-'){
            cout << q1->front() << endl;
            q1->pop();
        }
        if(q1->size() < q2->size()){
            q1->push(q2->front());
            q2->pop();
        }n--;
    }

    return 0;
}