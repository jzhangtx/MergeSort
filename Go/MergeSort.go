package main

import "fmt"

func MergePart(arr []int, start int, end int) {
	if end-start <= 1 {
		return
	}

	mid := (start + end) / 2
	MergePart(arr, start, mid)
	MergePart(arr, mid, end)

	a1 := make([]int, mid-start)
	for i := 0; i < mid-start; i++ {
		a1[i] = arr[start+i]
	}

	a2 := make([]int, end-mid)
	for i := 0; i < end-mid; i++ {
		a2[i] = arr[mid+i]
	}

	i := 0
	j := 0
	for i < len(a1) && j < len(a2) {
		if a1[i] < a2[j] {
			arr[start] = a1[i]
			i++
		} else {
			arr[start] = a2[j]
			j++
		}
		start++
	}
	for ; i < len(a1); i++ {
		arr[start] = a1[i]
		start++
	}
	for ; j < len(a2); j++ {
		arr[start] = a2[j]
		start++
	}
}

func MergeSort(arr []int) {
	MergePart(arr, 0, len(arr))
}

func main() {
	for {
		fmt.Print("Number of elements: ")
		count := 0
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := make([]int, count)
		fmt.Print("The array to be sorted: ")
		for i := 0; i < count; i++ {
			fmt.Scan(&vec[i])
		}

		MergeSort(vec)
		fmt.Print("The sorted array is ")
		fmt.Println(vec)
	}
}
