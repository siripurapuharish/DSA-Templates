/*
=========================================
DIJKSTRA PATTERN
=========================================
*/

class Solution {
public:

    // Graph:
    // adj[u] = {{v, weight}, ...}

    vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src){

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){

            auto [currDist, node] = pq.top();
            pq.pop();

            // Ignore outdated states
            if(currDist > dist[node])
                continue;

            for(auto &[adjNode, wt] : adj[node]){

                int newDist = currDist + wt;

                if(newDist < dist[adjNode]){

                    dist[adjNode] = newDist;
                    pq.push({newDist, adjNode});
                }
            }
        }

        return dist;
    }
};

/*
=========================================
PATTERN RECOGNITION
=========================================

1. Minimum Distance

2. Minimum Cost

3. Minimum Time

4. Cheapest Route

5. Shortest Path

6. Non-negative Edge Weights

7. Best Path Optimization

==> THINK DIJKSTRA

Time Complexity
O((V + E) log V)
=========================================

1) First Find out the state 

dist[node] = Best ans till this node

Minimum Distance
Maximum Probability
Maximum Health
Minimum Cost
-----------------------------------------

2) Priority Queue (Min or Max)

According to the requirement

MIN Heap :-     (min effort)
dist[] = INF
if(newValue < dist[next])  ---> Relaxation

MAX Heap :-      (Max cost)
dist[] = -1/0/-INF
if(newValue > dist[next])  ---> Relaxation
-------------------------------------------

3)Outdated State Check

Minimum Version :-
if(currDist > dist[node])
    continue;

Maximum Version :-
if(currValue < best[node])
    continue;

-----------------------------------------
FOLLOW UPS
-----------------------------------------

1. Network Delay Time
Classic Dijkstra


2. Path With Minimum Effort
Transition changes
newEffort =
max(currEffort, edgeWeight)


3. Path With Maximum Probability
Max Heap
Store probability.


4. Find Safe Walk Through Grid
Max Heap
Store remaining health.


5. Minimum Cost to Make Valid Path
0-1 BFS / Dijkstra


6. Swim in Rising Water
Transition
newTime =
max(currTime, grid[nr][nc]

7. Minimum Obstacle Removal
0-1 BFS

8. Cheapest Flights Within K Stops
Dijkstra + Stops State

-----------------------------------------

Q6.

How to derive Dijkstra?

Answer these 5 questions:

1. What is my state?

2. Am I minimizing or maximizing?

3. Worst initial answer?

4. Heap type?

5. Relaxation formula?

Everything else is identical.

*/