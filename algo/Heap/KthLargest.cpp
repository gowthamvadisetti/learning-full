class Heap {
    private:
    int * heap_arr = NULL;
    int heap_size;
    int heap_max_size;
    void swap(int index1, int index2)
    {
        int temp = heap_arr[index1];
        heap_arr[index1] = heap_arr[index2];
        heap_arr[index2] = temp; 
    }
    public:
    Heap(int heap_max)
    {
        heap_arr = new int[heap_max];
        heap_size = 0;
        heap_max_size = heap_max;
    }
    int Size()
    {
        return heap_size;
    }
    int Top()
    {
        return heap_arr[0];
    }
    void MinHeapify(int index)
    {
        int min_index = index;
        if(2*index+1 < heap_size && heap_arr[2*index+1] < heap_arr[min_index])
        {
            min_index = 2*index+1;
        }
        if(2*index+2 < heap_size && heap_arr[2*index+2] < heap_arr[min_index])
        {
            min_index = 2*index+2;
        }
        if(min_index != index)
        {
            swap(index, min_index);
            MinHeapify(min_index);
        }
        return;
    }
    int ExtractMin()
    {
        //cout << "heap size: " << heap_size << heap_arr[0] << heap_arr[1] << heap_arr[2] <<  endl;
        int minval = heap_arr[0];
        heap_size--;
        heap_arr[0] = heap_arr[heap_size];
        MinHeapify(0);
        return minval;
    }
    void BalancedInsert(int val)
    {
        heap_arr[0] = val;
        MinHeapify(0);
        return;
    }
    void Insert(int val)
    {
        int curr_index = heap_size;
        heap_arr[curr_index] = val;
        heap_size++;
        while(curr_index != 0)
        {
            int parent_index = (curr_index - 1)/2;
            if(heap_arr[curr_index] >= heap_arr[parent_index])
            {
                break;
            }
            else
            {
                swap(curr_index, parent_index);
            }
            curr_index = parent_index;
        }
        
        return;
    }
    
    
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        Heap *curr_heap = new Heap(k);
        //curr_heap->Insert(2);
        //curr_heap->Insert(1);
        //curr_heap->Insert(3);
        //cout << curr_heap->ExtractMin() << endl;
        //cout << curr_heap->ExtractMin() << endl;
        //cout << curr_heap->ExtractMin() << endl;
        for(int i = 0;i < nums.size();i++)
        {
            if(curr_heap->Size() < k)
            {
                curr_heap->Insert(nums[i]);
            }
            else
            {
                if(nums[i] > curr_heap->Top())
                {
                    //curr_heap->ExtractMin();
                    curr_heap->BalancedInsert(nums[i]);
                }
            }
        }
        return curr_heap->Top();
    }
};