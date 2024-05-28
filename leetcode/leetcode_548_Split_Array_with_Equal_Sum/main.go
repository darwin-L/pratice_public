package main

import "fmt"

// 分割三個數組, 每個數取 前1後1的元素, 並且數字的關係是 0 < i, i + 1 < j, j + 1 < k < n - 1
// 主要是盡量減少i,j,k的迴圈數即可, 好好的把限制式處理進迴圈條件
func main() {
	testSlice := []int{1, 2, 1, 2, 1, 2, 1}
	Slicelength := checkCondition(testSlice)
	result := exec(testSlice, Slicelength)
	fmt.Println(result)

}

func checkCondition(inputSlice []int) int {
	checkLen := len(inputSlice)
	if checkLen > 2000 || checkLen < 7 { // 小於7的不可能分割成4個數組了
		panic("length of input wrong")
	}
	for i := range inputSlice {
		if inputSlice[i] > 1000000 || inputSlice[i] < -1000000 {
			panic("element value error")
		}
	}
	return checkLen
}
func exec(inputSlice []int, Slicelength int) bool {
	var sumSlice []int
	var i, j, k int
	sumSlice = append(sumSlice, 0)    // FIXME: 第0位佔位符
	for i = 1; i < Slicelength; i++ { //將第一個條件的每個和求出來
		sumSlice = append(sumSlice, (inputSlice[i-1] + inputSlice[i]))
	}
	jOffset := 2
	for j = (1 + jOffset); j < Slicelength-(1+jOffset); j++ { // j的起始位置加上條件的offset, 結束條件減少offset, 並開始做比對
		var sumSlice2 []int
		for i = 1; i < j-1; i++ {
			if sumSlice[i-1] == (sumSlice[j-1] - sumSlice[i]) {
				sumSlice2 = append(sumSlice2, sumSlice[i-1])
			}
		}
		for k = j + 1; k < Slicelength-1; k++ { //最後一個不用跑
			if (sumSlice[k-1]-sumSlice[j]) == (sumSlice[k+1]-sumSlice[k]) && len(sumSlice2) > 0 {
				return true
			}
		}
	}
	fmt.Println(sumSlice)
	return false

}
