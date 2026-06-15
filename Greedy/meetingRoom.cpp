class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here
        vector<tuple<int, int, int>> meetings;
        for (int i = 0; i < start.size(); i++) {
            meetings.push_back({end[i], start[i], i + 1}); 
           
        }

        sort(meetings.begin(), meetings.end());

        vector<int> result;
        int lastEnd = -1;

        for (auto& m : meetings) {
            int e = get<0>(m);
            int s = get<1>(m);
            int idx = get<2>(m);
            if (s > lastEnd) { 
                result.push_back(idx); 
                lastEnd = e; 
            }
        }
        return result;
    }
};