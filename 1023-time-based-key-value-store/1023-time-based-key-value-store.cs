public class TimeMap {
    
    private Dictionary<string, List<(int, string)>> dic;
    int value;
    int timestamp;

    public TimeMap() {
        dic = new Dictionary<string, List<(int, string)>>();
    }
    
    public void Set(string key, string value, int timestamp) {
        if (!dic.ContainsKey(key)) {
            dic[key] = new List<(int, string)>();
        }
        dic[key].Add((timestamp, value));
    }
    
    public string Get(string key, int timestamp) {
        if (!dic.ContainsKey(key)) return "";

        var list = dic[key];
        int left = 0, right = list.Count - 1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid].Item1 <= timestamp) {
                result = list[mid].Item2;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.Set(key,value,timestamp);
 * string param_2 = obj.Get(key,timestamp);
 */