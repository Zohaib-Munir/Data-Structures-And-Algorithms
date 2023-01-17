#include<iostream>
using namespace std;
class InPlaceHeapSort{
    public:
    void buildHeap(int * array , int size){
        for(int i=1; i<size;i++){
            int child =i;

            while(child > 0){
                int parent = (child-1)/2;
                if(array[parent] < array[child]){
                    swap(array[child], array[parent]);
                    child = parent;
                }
                else{
                    break;
                }
            }
        }
    }

    void removeMax(int *array , int size){
        

        while(size >=1){
            swap(array[0], array[size-1]);
            size--;
            
            int parent =0;

            while(true){
                int left = (2*parent)+1;
                int right = (2*parent)+2;
                int minimum = parent;

                if(left < size && array[left] > array[minimum]){
                    minimum = left;
                }
                if(right < size && array[right] > array[minimum]){
                    minimum = right;
                }
                if(minimum == parent){
                    break;
                }
                swap(array[parent], array[minimum]);
                parent = minimum;
            }
        }
    }
};
int main(){
    

    int array[] = {14,45,66,2,7,35,52,9,1};
    InPlaceHeapSort ip;
    ip.buildHeap(array,9);
    ip.removeMax(array,9);

    for(int i=0; i<9;i++){
        cout<<array[i]<<" ";
    }
 
    return 0;
}