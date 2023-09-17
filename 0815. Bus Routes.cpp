//bfs + undirected graph (bus routes(buses) are nodes and its bus stops are basis of transition acting as edges)
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if( target==source )return 0;

        unordered_map<int,bool>visitedStops;
        unordered_map<int,bool>visitedBuses;                        //marks already visited bus stops
        map<int,vector<int>>busesVisiting;                          //stores the indices of buses visiting stop [i].
        vector<bool>destination(routes.size(),false);               //bus routes consisiting of bus stop 'target'

        for(int i=0;i<routes.size();i++){ 
            for(int j=0;j<routes[i].size();j++){
                busesVisiting[routes[i][j]].emplace_back(i);
            }
        }

        for(int targets: busesVisiting[target])
            destination[targets] = true;

        queue <pair<int,int>> bfs;

        for(int sources: busesVisiting[source]){
            bfs.push({sources,1});
        }

        while( ! bfs.empty() ){
            int bus = bfs.front().first;
            int dist = bfs.front().second;
            if(destination[bus]){
                return dist;
            }
            bfs.pop();           
            for(int stops : routes[bus]){
                if( visitedStops.find(stops) == visitedStops.end() ){
                    visitedStops[stops] = true;
                    for(int buses: busesVisiting[stops]){   
                        if( visitedBuses.find(buses) == visitedBuses.end() ){
                            visitedBuses[buses]=true;
                            bfs.push({buses,dist+1});
                        }                 
                    }
                }
            }
        }

        return -1;
    }
};
