# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer}
class Heap
	def initialize(heap_max)
		@heap_arr = Array.new(heap_max)
		@heap_size = 0
		@heap_max_size = heap_max
	end
	def swap(index1, index2)
		temp = @heap_arr[index1]
		@heap_arr[index1] = @heap_arr[index2]
		@heap_arr[index2] = temp
	end
	def Size()
		return @heap_size
	end
	def Top()
		return @heap_arr[0]
	end
	def MinHeapify(index)
		min_index = index
		if 2*index+1 < @heap_size and @heap_arr[2*index+1] < @heap_arr[min_index]
			min_index = 2*index+1
		end
		if 2*index+2 < @heap_size and @heap_arr[2*index+2] < @heap_arr[min_index]
			min_index = 2*index+2
		end
		if min_index != index
			swap(min_index, index)
			MinHeapify(min_index)
		end
	end
	def BalancedInsert(val)
		@heap_arr[0] = val
		MinHeapify(0)
	end
	def Insert(val)
        # puts(@heap_size)
		curr_index = @heap_size
		@heap_arr[curr_index] = val
		@heap_size += 1
		while curr_index != 0
			parent_index = (curr_index - 1)/2
            # print(parent_index, curr_index)
			if @heap_arr[parent_index] < @heap_arr[curr_index]
				break
			else
				swap(curr_index, parent_index)
			end
			curr_index = parent_index
		end
        # puts(@heap_size)
	end
end
def find_kth_largest(nums, k)
    # print(nums.size())
	curr_heap = Heap.new(k)
    for i in 0...nums.size()
        # puts(i)
    	if curr_heap.Size() < k
    		curr_heap.Insert(nums[i])
    	else
    		if nums[i] > curr_heap.Top()
    			curr_heap.BalancedInsert(nums[i])
            end
    	end
    end
    return curr_heap.Top()
end