class MyCircularQueue {
public:
int * arr;
int qfront, rear, size;
    MyCircularQueue(int k) {
        arr=new int [k];
        qfront=rear=-1;
        size=k;
        
    }
    
    bool enQueue(int value) {
        if ((qfront ==0 && rear==size-1)|| (rear==qfront-1)) return false;
        else {
            if (qfront ==-1){
                qfront=rear=0;
                arr[rear]=value;
            }
            else if (rear==size-1 && qfront!=0){
                rear=0;
                arr[rear]=value;
            }
            else {
                arr[++rear]=value;
            }
        }
        return true;
        
    }
    
    bool deQueue() {
        if (qfront==-1)return 0;
        else if (qfront==rear) qfront=rear=-1;

        else if (qfront==size-1) qfront=0;
        else ++qfront;
        return 1;
        
    }
    
    int Front() {
        if (qfront==-1) return -1;
        else return arr[qfront];
        
    }
    
    int Rear() {
        if (rear==-1) return -1;
        else return arr[rear];
        
    }
    
    bool isEmpty() {
        if (qfront==-1) return 1;
        else return 0;
        
    }
    
    bool isFull() {
        int num=0;
        if ((qfront==0 && rear==size-1)|| (rear==qfront-1)) return 1;
        else return num;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */