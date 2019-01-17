#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<long long int,long long int> pii;
vector<pii> adjList1[10000000];
int dist1[10000000];

const long long int INF1 = 1e9;

vector<string> split1(const string& s, char delimiter){
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   
   while (getline(tokenStream, token, delimiter))
      tokens.push_back(token);
   
   return tokens;
}

int shortestTime(string filename, int source, int destination){
	
	
	long long int amt_nodes, amt_arcs;
	string line;
	ifstream myfile (filename);
	
	if (myfile.is_open()){
		while (getline (myfile,line)){
    		if (line[0] != 'c'){
        		vector <string> line_space_split1;
    			line_space_split1 = split1(line,' ');
    			
				switch(line[0]){
					
					case('p'):
						amt_nodes = stoi(line_space_split1[2]);
						amt_arcs = stoi(line_space_split1[3]);
						//cout<<amt_nodes<<" "<<amt_arcs<<endl;
						break;
						
					case('a'):
						long long int a = stoi(line_space_split1[1]);
						long long int b = stoi(line_space_split1[2]);
						long long int c = stoi(line_space_split1[3]);
						//cout<<a<<" "<<b<<" "<<c<<" "<<endl;
						adjList1[a].push_back({b,c});
						//Two way activate this
						adjList1[b].push_back({a,c});
						break;
				}
			}
    	}
    	
	myfile.close();
	}
	
	else 
		cout << "Unable to open file";
		
  	priority_queue<pii> pq;
  	
	//long long int source;
	
//	cout << "Please input your starting station: ";
//	cin >> source;
	long long int currNode, currCost, nxt, cost;

	for(long long int i = 0; i <= amt_nodes; i++) 
		dist1[i] = INF1;
		
	dist1[source] = 0;
	pq.push({0,source});
	
	while(!pq.empty()){
		pii f = pq.top(); pq.pop();
		currNode = f.se;
		currCost = f.fi;
		
		if(currCost > dist1[currNode]) 
			continue;
		
		for(pii v: adjList1[currNode]){
			nxt = v.fi, cost = v.se;
			if(dist1[currNode] + cost < dist1[nxt]){
				dist1[nxt] = dist1[currNode] + cost;
				pq.push({ -dist1[nxt], nxt });
			}
		}
	}
	int min = dist1[destination] / 60;
	int seconds = dist1[destination] % 60;
	cout << "The time taken from " << source << " to " << destination << " is approximately " << min << " minutes " << "and " << seconds << " seconds." << endl;
	cout << endl;
}

int shortestTimeB(string filename, int source, int destination){
	long long int amt_nodes, amt_arcs;
	string line;
	ifstream myfile (filename);
  	if (myfile.is_open()){
    	while ( getline (myfile,line) ){
    		if (line[0] != 'c'){
        		vector<string> line_space_split1;
    			line_space_split1 = split1(line,' ');
				switch(line[0]){
					case('p'):
						amt_nodes = stoi(line_space_split1[2]);
						amt_arcs = stoi(line_space_split1[3]);
						break;
					case('a'):
						long long int a = stoi(line_space_split1[1]);
						long long int b = stoi(line_space_split1[2]);
						long long int c = stoi(line_space_split1[3]);
						adjList1[a].push_back({b,c});
						adjList1[b].push_back({a,c});
						break;

				}
			}
    	}
    	myfile.close();
  	}
  	else cout << "Unable to open file";

	
	for(int i=0;i<=amt_nodes;i++) dist1[i] = INF1;
	dist1[source] = 0;
 
	for(long long int k=0;k<amt_nodes-1;k++){
		for(long long int i=0;i<amt_nodes;i++){
			for(pii f :adjList1[i]){
				long long int nxt = f.fi, cost = f.se;
				if(dist1[i] + cost < dist1[nxt]){
					dist1[nxt] = dist1[i] + cost;
				}
			}
		}
	}

	if(dist1[destination] >= 10000000){
		cout<<"unable to compute using bellman"<<endl;
	}else{
		int min = dist1[destination] / 60;
		int seconds = dist1[destination] % 60;
		cout << "The time taken from " << source << " to " << destination << " is approximately " << min << " minutes " << "and " << seconds << " seconds." << endl;
		cout << endl;
	}

}
