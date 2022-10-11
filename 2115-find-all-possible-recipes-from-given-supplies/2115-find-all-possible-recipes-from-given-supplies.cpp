typedef vector<vector<string>> vvs;
typedef vector<string> vs;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, vector<pair<string, int>>> graphStructure;

class Solution {
public:
    
    umsi calculateIndegrees(vs& recipes, vvs& ingredients) {
        umsi recipeIndegrees;
        for(int i = 0 ; i < recipes.size(); i++) {
            recipeIndegrees.insert({recipes[i], ingredients[i].size()});
        }
        return recipeIndegrees;
    }
    
    graphStructure buildGraph(vs& recipes, vvs& ingredients, umsi& indegrees) {
        graphStructure graph;
        for(int i = 0 ; i < ingredients.size(); i++) {
            for(int j = 0 ; j < ingredients[i].size(); j++) {
                if(graph.count(ingredients[i][j])) {
                    graph[ingredients[i][j]].push_back({recipes[i], indegrees[recipes[i]]});
                } else {
                    graph.insert({ingredients[i][j], {{recipes[i], indegrees[recipes[i]]}}});
                } 
            }
        }
        return graph;
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vs result;
        umsi indegrees = calculateIndegrees(recipes, ingredients);
        graphStructure graph = buildGraph(recipes, ingredients, indegrees);
        
        queue<string> q;
        for(int i = 0 ; i < supplies.size(); i++) {
            q.push(supplies[i]);
        }
        
        while(!q.empty()) {
            string ingredient = q.front();
            q.pop();
            
            for(int i = 0 ; i < graph[ingredient].size(); i++) {
                // reduce the number of ingredients required for the recipes used by this ingredient by 1;
                indegrees[graph[ingredient][i].first] -= 1 ;
                // cout << graph[ingredient][i].second;
                if(indegrees[graph[ingredient][i].first] == 0) {
                    result.push_back(graph[ingredient][i].first);
                    q.push(graph[ingredient][i].first);
                }
            }
        }
        
        return result;
    }
};