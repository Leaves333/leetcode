package main

func partition(head *ListNode, x int) *ListNode {

	if head == nil {
		return head
	}

	var smol_head *ListNode = nil
	var smol_cur *ListNode = nil
	var big_head *ListNode = nil
	var big_cur *ListNode = nil

	cur := head
	for cur != nil {
		if cur.Val < x {
			if smol_head == nil {
				smol_head = cur
				smol_cur = cur
			} else {
				smol_cur.Next = cur
				smol_cur = smol_cur.Next
			}
		} else {
			if big_head == nil {
				big_head = cur
				big_cur = cur
			} else {
				big_cur.Next = cur
				big_cur = big_cur.Next
			}
		}
		cur = cur.Next
	}

	if smol_head == nil {
		big_cur.Next = nil
		return big_head
	} else {
		smol_cur.Next = big_head
		if big_cur != nil {
			big_cur.Next = nil
		}
		return smol_head
	}
}
