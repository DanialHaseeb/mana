from sys import stdin
from collections import deque

def bfs_paths_count(graph, start, N):
    visited = [False] * N
    path_count = [0] * N
    queue = deque([start])
    visited[start] = True
    path_count[start] = 1

    while queue:
        node = queue.popleft()

        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)
            if visited[neighbor]:
                path_count[neighbor] += path_count[node]

    return path_count

def solve(N, M, roads):
    graph = [[] for _ in range(N)]
    for u, v in roads:
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)

    JRP = [0] * N
    for i in range(N):
        path_counts = bfs_paths_count(graph, i, N)
        for j in range(N):
            if i != j:
                JRP[j] += path_counts[j]

    top_crossings = sorted(range(1, N + 1), key=lambda x: (JRP[x-1], -x), reverse=True)[:5]
    return top_crossings

roads = []

inputs = stdin.read().splitlines()
ln = 0

t = int(inputs[ln])
ln += 1

for _ in range(t):
    N, M = map(int, inputs[ln].split())
    ln += 1

    for _ in range(M):
        roads.append(list(map(int, inputs[ln].split())))
        ln += 1

    output = solve(N, M, roads)

    print("\n".join(map(str, output)))
