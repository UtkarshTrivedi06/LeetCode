#include <stdbool.h>
#include <stdlib.h>

void dfs(int room, bool* visited, int** rooms, int* roomsColSize) {
    visited[room] = true;
    for (int i = 0; i < roomsColSize[room]; i++) {
        int next = rooms[room][i];
        if (!visited[next])
            dfs(next, visited, rooms, roomsColSize);
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = calloc(roomsSize, sizeof(bool));
    dfs(0, visited, rooms, roomsColSize);
    for (int i = 0; i < roomsSize; i++)
        if (!visited[i]) return false;
    return true;
}
