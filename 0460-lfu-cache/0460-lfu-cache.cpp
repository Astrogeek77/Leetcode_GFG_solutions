class LFUCache
{
    public:
    // 1. A map that map frequence to a DLL, the list stores<key, value> pair and recently used order
    // 2. A map that map keys to freq, list iterator pair
    unordered_map<int, list<pair<int, int>>> freqs;
    unordered_map<int, pair<int, list< pair<int, int>>::iterator>> map;

    int capacity, minFreq;

    LFUCache(int cap) 
    {
        capacity = cap;
        minFreq = 0;
    }

    int get(int key)
    {
        if (map.count(key))
        {
           	// Get value if the value corresponding to the key exists
            int freq = map[key].first;
            auto it = map[key].second;
            int value = it->second;

           	// Update frequency and maintain least recently used order
            freqs[freq].erase(it);
            freqs[freq + 1].push_back({ key, value });

            //update map
            map[key].first = freq + 1;
            map[key].second = --freqs[freq + 1].end();

           	// Update minFreq
            if (freqs[minFreq].size() == 0) minFreq++;

            return value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (capacity <= 0) return;

        if (get(key) != -1)
        {
           	// Note: frequency is already updated in get() function call last line.
            auto it = map[key].second;
            it->second = value;
        }
        else
        {
            if (map.size() == capacity)
            {
               	// remove least frequently and least recently used key
                auto it = freqs[minFreq].begin();
                int removeKey = it->first;
                freqs[minFreq].erase(it);

                map.erase(removeKey);
            }

            minFreq = 1;
            freqs[minFreq].push_back({ key, value });

            map[key].first = minFreq;
            map[key].second = --freqs[minFreq].end();
        }
    }
};

/**
 *Your LFUCache object will be instantiated and called as such:
 *LFUCache* obj = new LFUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 */