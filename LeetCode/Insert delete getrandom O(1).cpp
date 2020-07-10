class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
     srand(time(0));   
    }
    
    unordered_map<int,int> m;
    vector<int> v;
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) == m.end()){
            v.emplace_back(val);
            int n = v.size();
            m[val] = n-1;
            return true;
        } 
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()){
            return false;
        }
        m[v.back()] = m[val];
        v[m[val]] = v.back();
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % v.size();
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
