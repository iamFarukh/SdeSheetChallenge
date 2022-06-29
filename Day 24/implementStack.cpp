// Stack class.
class Stack {
    int *arr;
    int topp;
    int size;
    
public:
    
    Stack(int capacity) {
        this->size = capacity;
        arr = new int[size];
        topp = -1;
    }

    void push(int num) {
        if(size - topp != 1) {
            topp++;
            arr[topp] = num;
        }
    }

    int pop() {
        if(topp != -1) {
            int x = arr[topp];
            topp--;
            return x;
        }
        else {
            return -1;
        }
    }
    
    int top() {
        if(topp != -1) {
            int x = arr[topp];
            return x;
        }
        else {
            return -1;
        }
    }
    
    int isEmpty() {
        if(topp == -1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    
    int isFull() {
        if(size - topp == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
};
