/*
LeetCode 146. LRU 缓存
难度：中等
算法：哈希表 + 双向链表（STL list + unordered_map）
时间复杂度：get/put O(1)
空间复杂度：O(capacity)
*/
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    // list存(key, value)，最新的在头部
    list<pair<int, int>> cache_list;
    // unordered_map存key -> list迭代器
    unordered_map<int, list<pair<int, int>>::iterator> cache_map;

    void move_to_front(int key) {
        auto it = cache_map[key];
        // splice：把节点从原位置移到list头部，O(1)
        cache_list.splice(cache_list.begin(), cache_list, it);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache_map.find(key) == cache_map.end()) {
            return -1;
        }
        move_to_front(key);
        return cache_map[key]->second;
    }

    void put(int key, int value) {
        if (cache_map.find(key) != cache_map.end()) {
            cache_map[key]->second = value;
            move_to_front(key);
            return;
        }
        if (cache_list.size() == capacity) {
            // 淘汰最久未使用：list尾部
            int oldest_key = cache_list.back().first;
            cache_list.pop_back();
            cache_map.erase(oldest_key);
        }
        cache_list.push_front({key, value});
        cache_map[key] = cache_list.begin();
    }
};
