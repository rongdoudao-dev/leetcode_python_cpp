"""
LeetCode 705. 设计哈希集合
难度：简单
算法：链地址法（数组 + 链表）
时间复杂度：O(n/k)，k=桶数
空间复杂度：O(n + k)
"""


class MyHashSet:
    def __init__(self):
        """
        链地址法：固定桶数，每个桶是一个列表
        """
        self._bucket_count: int = 769
        self._buckets: list[list[int]] = [[] for _ in range(self._bucket_count)]

    def _hash(self, key: int) -> int:
        return key % self._bucket_count

    def add(self, key: int) -> None:
        bucket_index: int = self._hash(key)
        if key not in self._buckets[bucket_index]:
            self._buckets[bucket_index].append(key)

    def remove(self, key: int) -> None:
        bucket_index: int = self._hash(key)
        if key in self._buckets[bucket_index]:
            self._buckets[bucket_index].remove(key)

    def contains(self, key: int) -> bool:
        bucket_index: int = self._hash(key)
        return key in self._buckets[bucket_index]
