class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v(arr);
        sort(begin(v), end(v));
        
        set<int> s(v.begin(), v.end());
        v.assign(s.begin(), s.end());
        
        for(auto i = s.begin(); i != s.end(); i++){
            cout << *i << " ";
        }
        
        unordered_map<int, int> m;
        
        for(int i = 0 ; i < v.size(); i++){
            m[v[i]] = i+1;
        }
        
        for(int i = 0; i < arr.size(); i++){
            arr[i] = m[arr[i]];
        }
        
        return arr;
    }
};