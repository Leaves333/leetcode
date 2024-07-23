import java.util.HashMap;
import java.util.Map;

class Solution {
    public Node copyRandomList(Node head) {
        
		Map<Node, Node> nodeMap = new HashMap<Node, Node>();
		nodeMap.put(null, null);

		Node cur = head;
		while (cur != null) {
			nodeMap.put(cur, new Node(cur.val));
			cur = cur.next;
		}

		cur = head;
		while (cur != null) {
			nodeMap.get(cur).next = nodeMap.get(cur.next);
			nodeMap.get(cur).random = nodeMap.get(cur.random);
			cur = cur.next;
		}

		return nodeMap.get(head);

    }
}
