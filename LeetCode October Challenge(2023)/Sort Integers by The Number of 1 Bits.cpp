class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto customComparator = [this](int a, int b) {
            int onesA = countOnes(a);
            int onesB = countOnes(b);
            if (onesA != onesB) {
                return onesA > onesB;
            }
            return a > b;
        };

        priority_queue<int, vector<int>, decltype(customComparator)> priorityQueue(customComparator);
        for (int n : arr) {
            priorityQueue.push(n);
        }

        vector<int> res;
        while (!priorityQueue.empty()) {
            res.push_back(priorityQueue.top());
            priorityQueue.pop();
        }

        return res;
    }

    int countOnes(int num) {
        int count = 0;
        while (num) {
            num &= (num - 1);
            count++;
        }
        return count;
    }    
};