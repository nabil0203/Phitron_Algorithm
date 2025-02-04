// https://leetcode.com/problems/keys-and-rooms/description/




class Solution {
public:
    bool visited_array[1005];

    void bfs(int src, vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(src);

        visited_array[src] = true;

        while (!q.empty()) {
            int par = q.front();
            q.pop();

            // cout << par << " ";

            for (int child : rooms[par]) {
                if (visited_array[child] == false) {
                    q.push(child);
                    visited_array[child] = true;
                }
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        memset(visited_array, false, sizeof(visited_array));

        bfs(0, rooms);

        for(int i=0; i< rooms.size(); i++)
        {
            if(!visited_array[i])
                return false;      
        }
        return true;
    }  
};