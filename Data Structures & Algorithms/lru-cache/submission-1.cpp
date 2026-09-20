class LRUCache {
public:
    LRUCache(int capacity) {
        this->max_capacity = capacity;     
    }
    
    int get(int key) {
        if (!this->umap.contains(key)) return -1;

        this->usage.erase(umap[key].second);
        this->usage.push_back(key);
        this->umap[key].second = --usage.end();
        return this->umap[key].first;

    }
    
    void put(int key, int value) {
        if (this->umap.contains(key)) {
            this->usage.erase(this->umap[key].second);
        } else if (this->usage.size() == this->max_capacity) {
            int lru = usage.front();
            usage.pop_front();
            umap.erase(lru);
        }
        this->usage.push_back(key);
        this->umap[key] = {value, --usage.end()};
    }

private:
    list<int> usage;
    unordered_map<int, pair<int, list<int>::iterator>> umap;
    int max_capacity;


};
