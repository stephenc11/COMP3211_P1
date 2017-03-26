#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;
typedef vector<int> vi;
typedef std::pair<int, int> pii;
typedef vector<pii> vp;

/*Utility Function*/
void appendString(string& str, int cur){
      char C;
      if (cur == 0){
          C = 83;
          str+=C;
          str+=" ";
      }
      else if (cur == 8){
          str +="G1 ";
      }
      else if (cur == 9){
          str +="G2 ";
      }
      else{
           C = cur - 1 + 65;
           str+=C;
           str+=" ";
      }
};//Configure Output String

/*Breadth First Tree Search*/
string BFS(vp* g){
	string str;
	int cur;
	deque<int> dq;
	dq.push_back(0);
	while(!dq.empty()){
		cur = dq.front();
		dq.pop_front();	
		appendString(str,cur);
		if (cur == 7 || cur == 8 || cur == 9) break;
		for (auto c:g[cur]){
			int v = c.first;
			dq.push_back(v);
		}
	}
	return str;
};

/*Depth First Tree Search*/
string DFS(vp* g){
	string str;
	int cur;
	vector<int> visited;
	visited.assign(100, 0);
	deque<int> dq;
	dq.push_back(0);
	visited[0] = 1;
	while(!dq.empty()){
		cur = dq.back();
		if (visited[cur] >= 3) {
			appendString(str, -18);
			appendString(str, -18);
			appendString(str, -18);
			break;
		}//break after looping for three times
		dq.pop_back();	
		appendString(str,cur);
		visited[cur] ++;	
		if (cur == 7 || cur == 8 || cur == 9) break;
		if (g[cur].size() == 0) continue;
		int i = g[cur].size() - 1;
		for (;i >= 0; i--){
			dq.push_back(g[cur][i].first);
		}
	}
	return str;
};

/*Uniform-cost Tree Search*/
string UCTS(vp* g){
	string str;
	int u,depth;
	std::priority_queue<pii, vp, greater<pii> > Q;
	int* Dist = new int[100];
	for (int i = 0; i < 100; i++){
		Dist[i] = 88888888;	
	}
	Dist[0] = 0;
	Q.push({0,0});
	while(!Q.empty()){
		depth = Q.top().first;
		u = Q.top().second;
		Q.pop();
		appendString(str, u);	
		if (u == 7 | u == 8| u == 9)
			break;	
		for(auto c : g[u]){
			int v = c.first;
			int w = c.second;
			Q.push({depth + w, v});
		}
	}
	return str;
};

/*A-star Tree Search*/
string ASTS(vp* g, vi& heu){

	string str;
	std::priority_queue<pii, vp, greater<pii> > Q;
	int* Dist = new int[100];
	for (int i = 0; i < 100; i++){
		Dist[i] = 88888888;	
	}
	Dist[0] = 0;
	Q.push({heu[0],0});
	while(!Q.empty()){
		int u = Q.top().second;
		Q.pop();
		appendString(str, u);	
		if (u == 7 | u == 8| u == 9)
			break;	
		for(auto c : g[u]){
			int v = c.first;
			int w = c.second;
			Dist[v] = Dist[u] + w;
			Q.push({Dist[v] + heu[v],v});
		}
	}
	return str;
}

/*A-star Graph Search*/
string ASGS(vp* g, vi& heu){

	string str;
	std::priority_queue<pii, vp, greater<pii> > Q;
	int* Dist = new int[100];
	for (int i = 0; i < 100; i++){
		Dist[i] = 88888888;	
	}
	Dist[0] = 0;
	Q.push({heu[0],0});
	while(!Q.empty()){
		int u = Q.top().second;
		Q.pop();
		appendString(str, u);	
		if (u == 7 | u == 8| u == 9)
			break;	
		for(auto c : g[u]){
			int v = c.first;
			int w = c.second;
			if (Dist[v] + heu[v] > Dist[u] + heu[u] + w){
				Dist[v] = Dist[u] + w;
				Q.push({Dist[v] + heu[v],v});
			}
		}
	}
	return str;
}

int main(int , char** argv) {
	int edge_num, node_num;
	int h;
	int n1,n2,wei;
	vi heu;//heuristics 

	ifstream fin(argv[1]);
	fin>>node_num>>edge_num;	
	
	vp* graph;//graph stored as adjacency lists 	
	graph = new vp[node_num+2];

	while(0 < node_num){
		fin >> h;
		heu.push_back(h);
		node_num--;
	}	
	
	for (int i = 0; i < edge_num; i++){
		fin >> n1 >> n2 >> wei;	
		graph[n1].push_back({n2,wei});
	}

	cout <<"Breadth First Tree Search: "<< BFS(graph) << endl;
	cout <<"Depth First Tree Search:   " << DFS(graph) << endl;
	if (!strcmp(argv[1],"Graph4") || !strcmp(argv[1],"Graph5")){
	cout <<"Uniform-cost Tree Search:  "<< UCTS(graph) << endl;	
	cout <<"A* Tree Search:            " <<  ASTS(graph,heu) << endl;
	cout <<"A* Graph Search:           " << ASGS(graph,heu) << endl;}

	return 0;
}
