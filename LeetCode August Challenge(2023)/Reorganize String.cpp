class Solution {
public:
    std::string reorganizeString(std::string s) {
        std::unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        std::vector<std::vector<int>> maxHeap;
        for (auto entry : count) {
            maxHeap.push_back({-entry.second, entry.first});
        }
        heapify(maxHeap);
        std::vector<int> prev;
        std::string res = "";
        while (!maxHeap.empty() || !prev.empty()) {
            if (!prev.empty() && maxHeap.empty()) {
                return "";
            }
            std::vector<int> top = heapPop(maxHeap);
            res += static_cast<char>(top[1]);
            top[0]++;
            if (!prev.empty()) {
                heapPush(maxHeap, prev);
                prev.clear();
            }
            if (top[0] != 0) {
                prev = top;
            }
        }
        return res;
    }
private:
    void heapify(std::vector<std::vector<int>>& heap) {
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(heap, i);
        }
    }
    void heapifyDown(std::vector<std::vector<int>>& heap, int index) {
        int n = heap.size();
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if (left < n && heap[left][0] < heap[largest][0]) {
            largest = left;
        }
        if (right < n && heap[right][0] < heap[largest][0]) {
            largest = right;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(heap, largest);
        }
    }
    std::vector<int> heapPop(std::vector<std::vector<int>>& heap) {
        int n = heap.size();
        std::vector<int> top = heap[0];
        heap[0] = heap[n - 1];
        heap.pop_back();
        heapifyDown(heap, 0);
        return top;
    }
    void heapPush(std::vector<std::vector<int>>& heap, std::vector<int>& element) {
        heap.push_back(element);
        heapifyUp(heap, heap.size() - 1);
    }
    void heapifyUp(std::vector<std::vector<int>>& heap, int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index][0] >= heap[parent][0]) {
                break;
            }
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
    }
};