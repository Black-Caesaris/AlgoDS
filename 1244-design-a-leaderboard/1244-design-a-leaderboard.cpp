class Leaderboard {
public:
    
    unordered_map<int, int> playerScore;
    Leaderboard() {

    }
    
    void addScore(int playerId, int score) {
        if(!playerScore.count(playerId)){
            playerScore.insert({playerId, score});
        }else{
            playerScore[playerId] += score;
        }
    }
    
    int top(int K) {
        priority_queue<int, vector<int>, greater<int>> topK;

        for(auto i = playerScore.begin(); i != playerScore.end(); i++){
            cout << i->first << " " << i->second << endl;
            if(topK.size() < K){
                topK.push(i->second);
            }else{
                if(topK.top() < i->second){
                    topK.pop();
                    topK.push(i->second);
                }
            }
        }
        
        int result = 0;
        while(topK.size() != 0){
            result += topK.top();
            topK.pop();
        }
        
        return result;
    }
    
    void reset(int playerId) {
        playerScore.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */