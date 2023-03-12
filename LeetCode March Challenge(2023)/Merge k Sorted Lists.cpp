class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0)
            return NULL;
        vector<pair<int, ListNode*>> arr; 
        for(int i = 0; i < k; i++) {
            ListNode* curr_list = lists[i];
            while(curr_list != NULL) {
                arr.push_back({curr_list -> val, curr_list});
                curr_list = curr_list -> next;
            }
        }
        if(arr.size() == 0)
            return NULL;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 1; i++) {
            arr[i].second -> next = arr[i + 1].second;
        }
        arr[arr.size() - 1].second -> next = NULL;
        return arr[0].second;
    }
};