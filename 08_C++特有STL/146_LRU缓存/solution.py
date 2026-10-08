"""
LeetCode 146. LRU 缓存
难度：中等
算法：哈希表 + 双向链表（OrderedDict）
时间复杂度：get/put O(1)
空间复杂度：O(capacity)
"""
from collections import OrderedDict


class LRUCache:
    def __init__(self, capacity: int):
        """
        OrderedDict：move_to_end移到末尾，popitem删除最旧（队首）
        """
        self._capacity: int = capacity
        self._cache: OrderedDict[int, int] = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self._cache:
            return -1
        self._cache.move_to_end(key)
        return self._cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self._cache:
            self._cache.move_to_end(key)
        self._cache[key] = value
        if len(self._cache) > self._capacity:
            self._cache.popitem(last=False)
