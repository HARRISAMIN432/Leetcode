from collections import defaultdict, deque

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for i in edges:
            graph[i[0]].append(i[1])
            graph[i[1]].append(i[0])
        vis: List[bool] = [False] * n
        q = deque()
        ans: int = 0
        for i in range(0, n):
            if not vis[i]:
                vis[i] = True
                q.append(i)
                g: List[int] = []
                g.append(i)
                while q:
                    node = q.popleft()
                    for neigh in graph[node]:
                        if not vis[neigh]:
                            vis[neigh] = True
                            g.append(neigh)
                            q.append(neigh)
                if sum(len(graph[node]) for node in g) == len(g) * (len(g) - 1):
                    ans += 1
        return ans
                        


        
        