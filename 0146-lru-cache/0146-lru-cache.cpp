#import <list>;
#import <unordered_map>
using namespace std;
class LRUCache {
public:
    int capacity;
    list<pair<int,int>>cache;
    unordered_map<int,list<pair<int,int>>::iterator>mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it==mp.end()){
            return -1;
        }
        cache.splice(cache.begin(),cache,it->second);

        return  it->second->second;
        
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it!=mp.end()){
            it->second->second = value;

            cache.splice(cache.begin(),cache,it->second);
            return;
        }
        cache.push_front({key,value});
        mp[key]=cache.begin();

        if(cache.size()>capacity){
            auto lru = cache.back();
            mp.erase(lru.first);
            cache.pop_back();
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */