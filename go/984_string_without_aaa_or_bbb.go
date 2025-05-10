package main

func strWithout3a3b(a int, b int) string {
	ans := ""
	for a > b {
		ans += "aab"
		a -= 2
		b -= 1
	}
	for b > a {
		ans += "abb"
		a -= 1
		b -= 2
	}
	for _ = range a {
		ans += "ab"
	}
	return ans
}
