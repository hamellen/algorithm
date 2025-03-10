// Graph_data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

struct VertexCost {

	
	int vertex;
	int cost;

};

struct Vertex {


};

vector<Vertex> v;
vector<vector<int>> adjacent;
vector<bool> visited;


//void dfs(int start) {
//
//	if (visited[start]) {
//		return;
//	}
//	visited[start] = true;
//	cout <<"탐색 성공: "<< start << endl;
//
//	if (v[start].edges.size() > 0) {//다른 길로 가는 루트가 존재할경우 
//		
//		auto it = find(v.begin(), v.end(), *(v[start].edges[0]));
//		dfs(it - v.begin());
//	}
//	
//}

//adjacent = vector<vector<int>>(6);//인접리스트

void dfs(int start) {//재귀용법

	if (visited[start]) {
		return;
	}
	visited[start] = true;
	cout << start << endl;

	if (adjacent[start].size() > 0) {

		for (const int& ele : adjacent[start]) {
			dfs(ele);
		}
	}

}

void bfs(int start) {//자료구조 queue 를 사용함 

	vector<int> parents(6, -1);//누구에 의해 발견되었는지 
	vector<int> distance(6, 0);//출발점에서의 거리 

	
	queue<int> q;
	q.push(start);
	visited[start] = true;

	parents[start] = start;

	while (q.empty()==false) {

		start = q.front();
		q.pop();

		cout << start << endl;
		for (const int& ele : adjacent[start]) {
			if (visited[ele] == true) {
				continue;
			}
			q.push(ele);
			visited[ele] = true;
			parents[ele] = start;
			distance[ele] = distance[start] + 1;
		}
	}


}

//다익스트라-bfs에서의 가중치 개념 추가,각 지점까지 가는데 최소 거리 측정,인접 행렬 사용

void Dijikstra(int start) {//이해 못함 

	list<VertexCost> discovered;//발견목록 
	vector<int> minimal(6, INT32_MAX);//시작지점에서 정점별 최소거리 

	discovered.push_back(VertexCost{start,0});//시작지점
	minimal[start] = 0;//시작지점

	while (discovered.empty() == false) {

		list<VertexCost>::iterator bestIt;
		int bestCost = INT32_MAX;//일부러 최대치 설정

		for (auto it = discovered.begin(); it != discovered.end(); it++) {

			if (it->cost < bestCost) {
				bestCost = it->cost;
				bestIt = it;
			}

		}//원점에서 가장 적은 거리에 있는 노드 탐색 

		int cost = bestIt->cost;
		start = bestIt->vertex;
		discovered.erase(bestIt);//가장 작은 거리에 있는 노드를 찾았으니 삭제 

		if (minimal[start] < cost) {//혹시 모를지도 모르는 상황 대비 
			continue;
		}

		for (int there = 0; there < 6; there++) {//start 로부터 각각 연결 되어있는 정점탐색,start로부터 연결된 정점없을시 추가 없음 

			if (adjacent[start][there] == -1) {//연결 안되있음 
				continue;
			}

			int nextcost = minimal[start] + adjacent[start][there];//최소한의 가중치로 판별된 start의 가중치로부터 연결되어있는 노드까지의 가중치 더함 
			if (nextcost >= minimal[there]) {//연결되어있는 노드까지의 가중치가 minimal[there] 보다 크면 안됨 
				continue;
			}
			minimal[there] = nextcost;//최소거리 설정 

			discovered.push_back(VertexCost{ there,nextcost });//발견목록에 새로 추가 
		}

	}

	cout << minimal[3] << endl;

}

int main()
{
	v.resize(6);
	adjacent = vector<vector<int>>(6,vector<int>(6,-1));
	visited = vector<bool>(6, false);
	
	adjacent[0][1] = 15;
	adjacent[0][3] = 35;
	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;
	adjacent[3][4] = 5;
	adjacent[4][5] = 5;

	Dijikstra(0);



}

