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
                c = True
                for i in range(len(g)):
                    if not c:
                        break
                    for j in range(len(g)):
                        if i != j:
                            found = False
                            for k in graph[g[i]]:
                                if k == g[j]:
                                    found = True
                                    break
                            if not found:
                                c = False
                                break
                if c:
                    ans = ans + 1
        return ans
                        


        
        