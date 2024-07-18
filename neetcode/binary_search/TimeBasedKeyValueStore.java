import java.util.ArrayList;
import java.util.HashMap;

class Pair {

    private int timestamp;
    private String value;

    public Pair(int timestamp, String value) {
        this.timestamp = timestamp;
        this.value = value;
    }

    public int getTimestamp() {
        return timestamp;
    }

    public String getValue() {
        return value;
    }

}

class TimeMap {

    private HashMap<String, ArrayList<Pair>> map;

    public TimeMap() {
        map = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if (!map.containsKey(key)) {
            map.put(key, new ArrayList<>());
        }
        map.get(key).add(new Pair(timestamp, value));
    }
    
    public String get(String key, int timestamp) {

        if (!map.containsKey(key)) {
            return "";
        }

        ArrayList<Pair> list = map.get(key);
        int low = -1, high = list.size() - 1;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (list.get(mid).getTimestamp() <= timestamp) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }

        if (low == -1) {
            return "";
        }
        else {
            return list.get(low).getValue();
        }

    }
}
