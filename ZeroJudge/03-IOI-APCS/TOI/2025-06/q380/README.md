# 解題紀錄

## v1-1 CE

- 初版
- `std::pair` 沒有內建哈希算法，是不可哈希的物件，所以無法放入 `std::unordered_set`

## v1-2 TLE

- 由於 `std::pair` 沒有內建哈希算法，在盡可能不大幅修改程式碼的情況下，棄用 `std::unordered_set`，改用 `std::set`

```diff
- std::unordered_set<Point> visited;
+ std::set<Point> visited;
```

## v1-3 TLE

- `std::set` 天生就比較慢，所以直接給 `std::pair` 添加對應的 hash 算法，這樣就能用 `std::unordered_set` 了

```cpp
struct PointHash {
    size_t operator()(const std::pair<int, int> &p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};
```

```diff
- std::unordered_set<Point> visited;
+ std::unordered_set<Point, PointHash> visited;
```

## v1-4 AC(0.1s, 31.5MB)

- 棄用 `std::unordered_set` 和 `std::set`，改為 `std::vector`，期望能透過減少 cache miss 加速執行效率
