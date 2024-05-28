// 兩個已排序的陣列, 如何求其中位數 ->
// n2+1, 2n -> 3n+1猜想
// https://www.cnblogs.com/grandyang/p/4465932.html
// 解法三
package main

import (
	"fmt"
	"math"
)

func main() {
	// input1 := []int{1, 2, 3, 4, 5, 6}
	// input2 := []int{2, 5, 7, 9, 10, 12, 15}
	input1 := []int{1, 2, 3, 4}
	input2 := []int{}
	fmt.Println(exec(input1, input2))
}
func checkCondition() {

}
func exec(inputSliceN []int, inputSliceM []int) float64 {
	lengthOfN := len(inputSliceN) - 1 // for indexing
	lengthOfM := len(inputSliceM) - 1
	if lengthOfN < lengthOfM {
		// 考慮兩個長度差很多的情況, 只需要跑O(lg(min(m,n))) 即可
		exec(inputSliceM, inputSliceN)
	}
	if lengthOfM == -1 {
		lengthOfN += 1
		fmt.Println("?", lengthOfN, math.Ceil(0.5), inputSliceN[(lengthOfN-1)/2], (lengthOfN)/2)
		ceilNumber := int(math.Floor(float64(lengthOfN-1) / 2))
		fmt.Println(ceilNumber, lengthOfN)
		return float64(inputSliceN[ceilNumber]+inputSliceN[lengthOfN/2]) / 2
	}

	var left, right int
	left = 0
	right = lengthOfM * 2
	for left <= right {
		mid2 := (left + right) / 2
		mid1 := lengthOfN + lengthOfM - (left+right)/2
		fmt.Println(mid1)
		var LMin, LMax float64
		LMin = -1000
		if LMin != 0 {
			LMin = float64(inputSliceN[(mid1-1)/2])
		}
		LMax = -1000
		if LMax != 0 {
			LMax = float64(inputSliceM[(mid2-1)/2])
		}
		var RMin, RMax float64
		RMin = -10000
		RMax = -10000
		if RMin != float64(lengthOfN)*2 {
			RMin = float64(inputSliceN[mid1/2])
		}
		if RMax != float64(lengthOfM)*2 {
			RMax = float64(inputSliceM[mid2/2])
		}
		if LMin > RMax {
			left = mid2 + 1
		} else if LMax > RMin {
			right = mid2 - 1
		} else {
			// fmt.Println("here", max(int(LMin), int(LMax)), min(int(RMin), int(RMax)))
			fmt.Println(LMin, LMax, RMin, RMax)
			return float64(max(int(LMin), int(LMax))+min(int(RMin), int(RMax))) / 2
		}

		// Lmin = float64(mid1) == 0 ? -10000 :
	}
	return -1
}
func max(x int, y int) int {
	if x > y {
		return x
	}
	return y
}
func min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}
