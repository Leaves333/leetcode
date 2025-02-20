package main

func findMaxAverage(nums []int, k int) float64 {
	sum := 0.0
	for i := range k - 1 {
		sum += float64(nums[i])
	}

	max_avg := -100000.0
	for i := range len(nums) - k + 1 {
		sum += float64(nums[k+i-1])
		max_avg = max(max_avg, sum/float64(k))
		sum -= float64(nums[i])
	}

	return max_avg
}
