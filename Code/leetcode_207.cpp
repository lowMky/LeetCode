class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int vis[numCourses];
        vector<int> pre[numCourses];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<numCourses;++i)
            pre[i].clear();

        for(int i=0,sz=prerequisites.size();i<sz;++i)
            pre[prerequisites[i].first].push_back(prerequisites[i].second);

        for(int i=0;i<numCourses;++i)
            if(!vis[i]){
                if(!dfs(i,vis,pre))
                    return false;
            }
        return true;
    }

    bool dfs(int u,int *vis,vector<int> *pre){
        vis[u] = -1;
        for(int i=0,sz=pre[u].size();i<sz;++i){
            int v = pre[u][i];
            if(!vis[v]){
                if(!dfs(v,vis,pre)) return false;
            }
            else if(vis[v] == -1) return false;
        }
        vis[u] = 1;
        return true;
    }
};

