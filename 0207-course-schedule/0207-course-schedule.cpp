class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adjList, vector<int> &vis, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;


        for(auto &n : adjList[node]){
            if(!vis[n]){
                if(dfs(n, adjList, vis, pathVis)){
                    return true;
                }
            }
            else if(pathVis[n]){
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);

        for(auto &e : prerequisites){
            adjList[e[0]].push_back(e[1]);
        }
        vector<int> vis(numCourses);
        vector<int> pathVis(numCourses);

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adjList, vis, pathVis))
                    return false;
            }
        }
        return true;
    }
};