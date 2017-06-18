class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        
        int len = timePoints.size();
        int ans = getMinutes(timePoints[0]) + 24*60 - getMinutes(timePoints[len-1]);
    
        for(int i = 1;i < len ;++ i)
            ans = min(ans,getMinutes(timePoints[i]) - getMinutes(timePoints[i-1]));
        return ans;
    }
    
    int getMinutes(string & timePoint){
        return ((timePoint[0]-'0')*10 + timePoint[1] -'0')*60 + (timePoint[3] - '0')*10 + timePoint[4]-'0';
    }
};