package main

import "fmt"

func merge(arr []int, l int, r int, mid int) {
	var temp = make( []int, r - l + 1)
	i := l
	j := mid + 1
	k := 0
	for ; i <= mid && j <= r; {
		if(arr[i] <= arr[j]) {
			temp[k] = arr[i]
			i++
			k++
		} else {
			temp[k] = arr[j]
			j++
			k++
		}
	}
	for ; i <= mid; {
		temp[k] = arr[i]
		i++
		k++
	}
	for ; j <= r; {
		temp[k] = arr[j]
		i++
		j++
	}
	for i := l; i <= r; i++ {
		arr[i] = temp[i - l]
	}
	return
}

func mergeSort(arr []int, l int, r int) {
	var mid int = (l + r)/2
	if (l < r) {
		// fmt.Println("l ", l, "r ", r, "mid ", mid)
		mergeSort(arr, l, mid)
		mergeSort(arr, mid + 1, r)
		merge(arr, l, r, mid)
	}
	return
}

func main() {
	var a [5]int
	a[1] = -1
	a[2] = 7
	a[3] = -9
	a[4] = 14
	fmt.Println("a[0] val:", a[0])
	fmt.Println("a[3] val:", a[3])
	fmt.Println("Sorting the array!!!")
	mergeSort(a[:], 0, len(a) - 1)
	fmt.Println("a[0] val:", a[0])
	fmt.Println("a[3] val:", a[3])
}