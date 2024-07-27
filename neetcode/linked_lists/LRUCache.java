import java.util.HashMap;

class CacheNode {

    public int key;
    public int value;
    public CacheNode next;
    public CacheNode prev;

    public CacheNode(int key, int value) {
        this.key = key;
        this.value = value;
    }

}

class LRUCache {

    private int capacity;
    private int currentSize;
    private HashMap<Integer, CacheNode> map;

    private CacheNode head;
    private CacheNode tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.currentSize = 0;
        this.map = new HashMap<>();
        this.head = new CacheNode(-1, -1);
        this.tail = new CacheNode(-1, -1);
        head.next = tail;
        tail.prev = head;
    }

    private void remove(CacheNode node) {
        node.next.prev = node.prev;
        node.prev.next = node.next;
    }

    private void insert(CacheNode node) {
        CacheNode tmp = head.next;
        node.prev = head;
        node.next = tmp;
        head.next = node;
        tmp.prev = node;
    }

    public int get(int key) {

        // check if key exists
        CacheNode node = map.get(key);
        if (node == null) {
            return -1;
        }

        // update most recently used
        remove(node);
        insert(node);

        return node.value;

    }

    public void put(int key, int value) {

        // if the key already exists, update its value and move it to the front
        if (map.containsKey(key)) {
            map.get(key).value = value;
            CacheNode node = map.get(key);
            remove(node);
            insert(node);
            return;
        }

        // evict least recently used if size exceeds capacity
        if (currentSize >= capacity) {
            map.remove(tail.prev.key);
            remove(tail.prev);
        }

        // add node to the cache
        CacheNode node = new CacheNode(key, value);
        insert(node);
        map.put(key, node);
        currentSize++;

    }

}
