/*
LeetCode 705. 设计哈希集合
难度：简单
算法：链地址法（数组 + 链表）
时间复杂度：O(n/k)，k=桶数
空间复杂度：O(n + k)
*/
#include <vector>
#include <list>
using namespace std;

class MyHashSet {
private:
    int bucket_count;
    vector<list<int>> buckets;

    int hash(int key) {
        return key % bucket_count;
    }

public:
    MyHashSet() {
        bucket_count = 769;
        buckets.resize(bucket_count);
    }

    void add(int key) {
        int index = hash(key);
        // find是STL算法，查找链表中是否已有key
        auto it = find(buckets[index].begin(), buckets[index].end(), key);
        if (it == buckets[index].end()) {
            buckets[index].push_back(key);
        }
    }

    void remove(int key) {
        int index = hash(key);
        auto it = find(buckets[index].begin(), buckets[index].end(), key);
        if (it != buckets[index].end()) {
            buckets[index].erase(it);
        }
    }

    bool contains(int key) {
        int index = hash(key);
        auto it = find(buckets[index].begin(), buckets[index].end(), key);
        return it != buckets[index].end();
    }
};
