#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <limits>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <array>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

map<int, set<int> > access;
vector<vector<int> > G;
vector<pair<int, int> > employees;
int N, M;

bool isValid(int i, int j)
{
  return i >= 0 && i < N && j >= 0 && j < M;
}

void dfs(int x, int y, int areaId)
{
  std::stack<pair<int, int> > stack;
  stack.push(make_pair(x, y));

  while (!stack.empty())
  {
    auto current = stack.top();
    stack.pop();
    int i = current.first;
    int j = current.second;

    if (G[i][j] >= 2)
      continue; // visited or obstacle
    if (G[i][j] == 1)
    {
      access.at(areaId).insert(i * M + j);
      continue;
    }
    G[i][j] = areaId;

    if (isValid(i - 1, j))
      stack.push(make_pair(i - 1, j));

    if (isValid(i + 1, j))
      stack.push(make_pair(i + 1, j));

    if (isValid(i, j - 1))
      stack.push(make_pair(i, j - 1));

    if (isValid(i, j + 1))
      stack.push(make_pair(i, j + 1));
  }
}

void findEmployees()
{
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (G[i][j] == 1) {
        // cout << i << " " << j << "\n";
        employees.push_back(make_pair(i, j));
      }
      // cout << endl;
}

vector<pair<int, int> > shortestDistance()
{
  N = G.size();
  M = G[0].size();

  findEmployees();

  int areaId = 3;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    {
      if (G[i][j] == 0)
      {
        access[areaId] = set<int>();
        dfs(i, j, areaId++);
      }
    }

  int B = employees.size();
  int min = numeric_limits<int>::max();
  multimap<int, pair<int, int> > result;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
    {
      int id = G[i][j];
      if (id > 2 && access.at(id).size() == B)
      {
        int dist = 0;
        for (auto b : employees)
        {
          dist += abs(i - b.first) + abs(j - b.second);
        }
        min = std::min(dist, min);
        result.insert(make_pair(min, make_pair(i, j)));
      }
    }
  }

  int resultMin = result.begin()->first;

  vector<pair<int, int> > resultVector;

  for (auto it = result.begin(); it != result.end(); it++) {
    cout << it->first << " " << it->second.first << " " << it->second.second << endl;
    if (it->first == resultMin) {
      resultVector.push_back(it->second);
    }
  }

  cout << endl;

  return resultVector;
}

int main()
{
  ofstream fout("output.txt");
  ifstream fin;

  fin.open("input.txt");
  // fin.open("micro_kitchens_medium_input.txt");

  string arr_count_temp;
  getline(fin, arr_count_temp);

  vector<string> arr_temp = split(rtrim(arr_count_temp));

  int const W = stoi(ltrim(rtrim(arr_temp[0])));
  int const H = stoi(ltrim(rtrim(arr_temp[1])));
  int const N = stoi(ltrim(rtrim(arr_temp[2])));

  vector<vector<int> > arr(H);

  for (int i = 0; i < H; i++)
  {
    string line;
    getline(fin, line);

    vector<string> arr_temp = split(rtrim(line));

    for (int j = 0; j < W; j++)
    {
      if (arr_temp[j] == ".") {
        arr[i].push_back(0);
      } else if (arr_temp[j] == "w") {
        arr[i].push_back(2);
      } else {
        arr[i].push_back(1);
      }
    }
  }

  G = arr;
  auto result = shortestDistance();

  for (auto pair : result) {
    fout << "(" << pair.second << ", " << pair.first << ")" << " ";
  }

  fout << "\n";
  fout.close();

  return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
