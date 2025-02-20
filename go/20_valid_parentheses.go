package main

func isValid(s string) bool {
	var stack []rune
	for _, c := range s {
if c == '{' || c == '(' || c == '[' {
			stack.PushBack(c)
		} else if c == '}' {
			if stack.Back().Value == '{' {
				stack.Remove(stack.Back())
			} else {
				return false
			}
		} else if c == ')' {
			if stack.Back().Value == ')' {
				stack.Remove(stack.Back())
			} else {
				return false
			}
		} else if c == ']' {
			if stack.Back().Value == '[' {
				stack.Remove(stack.Back())
			} else {
				return false
			}
		}
	}
	return stack.Len() == 0
	}
	return len(stack) == 0
}
