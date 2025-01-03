package main

import "fmt"

type BSTIterator struct {
	stack []*TreeNode
}

func Constructor(root *TreeNode) BSTIterator {
	it := BSTIterator{}
	it.stack = []*TreeNode{root}

	cur := root
	for cur.Left != nil {
		it.stack = append(it.stack, cur.Left)
		cur = cur.Left
	}
	return it
}

func (this *BSTIterator) Next() int {

	top := this.stack[len(this.stack)-1]
	this.stack = this.stack[:len(this.stack)-1]

	cur := top
	if cur.Right != nil {
		this.stack = append(this.stack, cur.Right)
		cur = cur.Right
		for cur.Left != nil {
			this.stack = append(this.stack, cur.Left)
			cur = cur.Left
		}
	}
	return top.Val
}

func (this *BSTIterator) HasNext() bool {
	return len(this.stack) != 0
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
