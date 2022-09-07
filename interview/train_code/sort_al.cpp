#include<bits/stdc++.h>

using namespace std;

void merge_(vector<int>&nums,int left ,int mid ,int right ,vector<int>&temp){
    int i = left, j = mid + 1,k = 0;
    while(i <= mid && j <=right){
        if(nums[i] >= nums[j]){
            temp[k++] = nums[j++];
        }else{
            temp[k++] = nums[i++];
        }
    }
    while(i <= mid){
        temp[k++] = nums[i++];
    }
    while(j <= right){
        temp[k++] = nums[j++];
    }
    for(int m = left,k = 0; m <= right;m++,k++){
        nums[m] = temp[k];
    }
}
void merge_sort(vector<int>&nums,int left ,int right ,vector<int>&temp){
    if(left >= right) return ;
    int mid = left + (right - left) / 2;
    merge_sort(nums,left,mid,temp);
    merge_sort(nums,mid + 1, right,temp);
    merge_(nums,left,mid,right,temp);
}

int partion(vector<int>&nums,int low ,int high){
    int pivotkey = nums[low];
    while(low < high){
        while(low < high && nums[high] >= pivotkey) high--;
        swap(nums[low],nums[high]);
        while(low < high && nums[low] <= pivotkey) low++;
        swap(nums[low],nums[high]);
    }
    return low;
}



void quick_sort(vector<int>&nums,int low ,int high){
    if(low >= high) return ;
    int pivot = partion(nums,low,high);
    quick_sort(nums,low,pivot - 1);
    quick_sort(nums,pivot + 1,high);
}

void heap_adjust(vector<int>&nums,int len ,int index){
    if(index > len) return;
    int left_index = 2 * index + 1;
    int right_index = 2 * index + 2;
    int smallest = index;
    if(left_index <= len && nums[smallest] > nums[left_index]){
        smallest = left_index;
    }
    if(right_index <= len && nums[smallest] > nums[right_index]){
        smallest = right_index;
    }
    if(smallest != index){
        swap(nums[index],nums[smallest]);
        heap_adjust(nums,len,smallest);
    }
}

void heap_sort(vector<int>&nums,int len){
    int parent_index = (len - 1) / 2;
    for(int i = parent_index ; i >= 0;i--){
        heap_adjust(nums,len,i);
    }

    for(int i = len; i > 0;i--){
        swap(nums[i],nums[0]);
        heap_adjust(nums,i,0);
    }
}


int main(){
    vector<int>nums={12,3,4,6,6,6,78,10,53,4,6,10};
    vector<int>temp(nums.size(),0);
    //merge_sort(nums,0,nums.size() - 1,temp);
    //quick_sort(nums,0,nums.size() - 1);
    heap_sort(nums,nums.size() - 1);
    for(auto p : nums){
        cout << p << " ,";
    }
    system("pause");
    return 0;
}


class LRUCache {
public:
    list<pair<int,int>>cache;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    int m_cap;
    LRUCache(int capacity) {
        m_cap = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            auto temp = *mp[key];
            cache.erase(mp[key]);
            mp.erase(key);
            cache.push_front(temp);
            mp[key] = cache.begin();
            return temp.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            cache.erase(mp[key]);
            mp.erase(key);
        }else if(cache.size() >= m_cap){
            auto temp = cache.back();
            cache.pop_back();
            mp.erase(temp.first);
        }
        cache.push_front({key,value});
        mp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */