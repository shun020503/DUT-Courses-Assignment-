#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int maze[1001][1001];
bool visited[1001][1001];
int dist[1001][1001];

struct Position
{
    int x;
    int y;
    Position (int a = 0, int b = 0) // Constructor
    {
        x = a;
        y = b;
    }
};

struct Move
{
    int x;
    int y;
    char direct;
    Move (int a = 0, int b = 0, char c = ' ') // Constructor
    {
        x = a;
        y = b;
        direct = c;
    }
};
Move direction[4] = {{0, -1, 'L'}, {0, 1, 'R'}, {-1, 0, 'U'}, {1, 0, 'D'}};
Position previous[1001][1001];


bool isInRange(Position pos)
{
    return (pos.x >= 1 && pos.x <= n && pos.y >= 1 && pos.y <= n);
}


void bfs(int x, int y)
{
    queue <Position> List;
    dist[x][y] = 0;
    visited[x][y] = true;

    List.push(Position(x, y));
    while ((int)List.size() != 0)
    {
        Position current = List.front();
        List.pop();
        for (int i = 0; i < 4; i++) // 4 direction
        {
            Position newPos;
            newPos.x = current.x + direction[i].x;
            newPos.y = current.y + direction[i].y;

            if (isInRange(newPos) == false || visited[newPos.x][newPos.y] == true || maze[newPos.x][newPos.y] == 0) continue;
            dist[newPos.x][newPos.y] = dist[current.x][current.y] + 1;
            visited[newPos.x][newPos.y] = true;
            List.push(newPos);
            previous[newPos.x][newPos.y] = current;
        }
    }
}

void trace()
{
    vector <Position> path;

    Position current(n, n);
    while (current.x != 1 || current.y != 1)
    {
        path.push_back(current);
        current = previous[current.x][current.y];
    }

    reverse(path.begin(), path.end());
    for (auto pos : path)
    {
        for (int i = 0; i < 4; i++)
        {
            Position newPos;
            newPos.x = current.x + direction[i].x;
            newPos.y = current.y + direction[i].y;

            if (newPos.x == pos.x && newPos.y == pos.y)
                cout << direction[i].direct;
        }
        current = pos;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> maze[i][j];
            visited[i][j] = false;
        }
    }

    bfs(1, 1);
    trace();

    return 0;
}
