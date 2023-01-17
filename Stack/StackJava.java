public class StackJava {
        private int nextIndex;
        private int capacity;
        private int[] array;
    
        StackJava(){
            capacity =4;
            array = new int[capacity];
            nextIndex =0;
        }
    
    
        public boolean isEmpty(){
            return nextIndex==0;
        }
    
    
        public boolean isFull(){
            return nextIndex==capacity;
        }
    
    
        public int getCapacity(){
            return capacity;
        }
    
    
        public int getSize(){
            return nextIndex;
        }
    
    
        public void push(int data){
            if(nextIndex == capacity){
                int[] newArray = new int[2*capacity];
                for(int i=0; i<capacity;i++){
                    newArray[i] = array[i];
                }
                array = newArray;
                capacity = capacity*2;
            }
            array[nextIndex] = data;
            nextIndex++;
        }
    
    
        public void pop(){
            if(isEmpty()){
                System.out.println("Empty Stack");
                return;
            }   
            nextIndex--;
        }
    
    
        public int top(){
            if(isEmpty()){
                return -1;
            }
           return array[nextIndex-1];
        }
    
        public void display(){
            while (!isEmpty()) {
                System.out.print(top()+" ");
                pop();
            }
            System.out.println();
        }
    }
