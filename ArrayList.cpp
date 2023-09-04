#include <iostream>

using namespace std;

class ArrayList{
  int length; int size;
  int* array; int* current;
  
  public:
    ArrayList(int size){
        this->size = size;
        array = new int[size];
        current = array;
        length = 0;
    }
    ArrayList(){
        array = new int[size];
        current = array;
        length = 0;
    }
    
    void setSize(int size){
        this->size = size; 
    }
    int getSize(){
        return size;
    }
    
    void start(){
        current = array;
    }
    void tail(){
        current = (array+(size-1));
    }
    void next(){
        current++;
    }
    void back(){
        current--;
    }
    void add(int value){
        if(length == size) {cout << "Size Full"; return;}
    
        *(array+length) = value;
        length++;
    }
    void createList(){
        if(size == 0) return;
        
        array = new int[size];
        current = array;
        length = 0;
    }
    //WORKING
    void insert(int pos, int value){
        if(pos > size  || pos < 0) return;
        if(length == size) return;
        
        current = (array+length);
        for(int i = length ; i >= pos ; i--){
            *(current) = *(current-1);
            back();
        }
        
        *(array+pos-1) = value;
        length++;
    }
    
    void removeItem(int pos){
        if(pos > size  || pos < 0) return;
        
        current = (array+pos-1);
        for(int i = pos ; i < (length - 1) ; i++){
            *current = *(current+i);
            next();
        }
        
        length--;
    }
    
    int get(int pos){ return *(array+pos-1); }
    
    void update(int pos, int value){
        *(array+pos-1) = value;
    }
    
    void find(int value){
        start();
        for(int i = 0 ; i < length ; i++){
            if(*current == *(array+i)){
                cout << "Found Value";
                return;
            }
            next();
        }
        cout << "Didn't Found Value";
        return;
    }
    
    void clear(){
        delete [] array;
        
        createList();
    }
    
    void print(){
        start();
        for(int i = 0 ; i < length ; i++){
            cout << *(current+i) << endl;
        }
    }
    
    //copy i don't get it
};

int main() {
    // Write C++ code here
    ArrayList a1(5);
    a1.add(1);
    a1.add(2);
    a1.add(3);
    a1.add(4);
    // a1.add(5);
    // a1.add(6);
    a1.print();
    // a1.clear();
    // a1.print();
    cout << "get " << a1.get(2) << endl;
    a1.find(4);
    
    // cout << endl << "update" << endl;
    // a1.update(4, 7);
    // a1.print();
    
    cout << endl << "insert " << endl;
    a1.insert(1, 0);
    a1.print();
    // cout << "remove " << endl;a
    // a1.removeItem(2);
    // a1.print();
    
    return 0;
}