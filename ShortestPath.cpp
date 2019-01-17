#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<long long int,long long int> pii;
vector<pii> adjList[10000000];
int dist[10000000];

const long long int INF = 1e9;

vector<string> split(const string& s, char delimiter){
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   
   while (getline(tokenStream, token, delimiter))
      tokens.push_back(token);
   
   return tokens;
}

int shortestDistance(string filename, int source, int destination){

	long long int amt_nodes, amt_arcs;
	string line;
	ifstream myfile (filename);
	
	if (myfile.is_open()){
		while (getline (myfile,line)){
    		if (line[0] != 'c'){
        		vector <string> line_space_split;
    			line_space_split = split(line,' ');
    			
				switch(line[0]){
					
					case('p'):
						amt_nodes = stoi(line_space_split[2]);
						amt_arcs = stoi(line_space_split[3]);
						//cout<<amt_nodes<<" "<<amt_arcs<<endl;
						break;
						
					case('a'):
						long long int a = stoi(line_space_split[1]);
						long long int b = stoi(line_space_split[2]);
						long long int c = stoi(line_space_split[3]);
						//cout<<a<<" "<<b<<" "<<c<<" "<<endl;
						adjList[a].push_back({b,c});
						//Two way activate this
						adjList[b].push_back({a,c});
						break;
				}
			}
    	}
    	
	myfile.close();
	}
	
	else 
		cout << "Unable to open file";
		
  	priority_queue<pii> pq;
	long long int currNode, currCost, nxt, cost;

	for(long long int i = 0; i <= amt_nodes; i++) 
		dist[i] = INF;
		
	dist[source] = 0;
	pq.push({0, source});
	
	while(!pq.empty()){
		pii f = pq.top(); pq.pop();
		currNode = f.se;
		currCost = f.fi;
		
		if(currCost > dist[currNode]) 
			continue;
		
		for(pii v: adjList[currNode]){
			nxt = v.fi, cost = v.se;
			if(dist[currNode] + cost < dist[nxt]){
				dist[nxt] = dist[currNode] + cost;
				pq.push({ -dist[nxt], nxt });
			}
		}
	}
	
//	long long int destination;
//	cout << "Please input your destination station: ";
//	cin >> destination;
	
	//	//g->findNameByID(st);
	//	g->findNameByID(t);
	
	cout << "Shortest distance from " << source << " to " << destination << " is " << dist[destination] << " meters " << endl;
	
	int price = 3000; // base rate of the train

	if(dist[destination] <= 34999){
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
		
	else if(dist[destination] >= 35000 && dist[destination] <= 44999){
		price += 1000;
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
	
	else if(dist[destination] >= 45000 && dist[destination] <= 54999){
		price += 2000;
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
	
	else if(dist[destination] >= 55000 && dist[destination] <= 64999){
		price += 3000;
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
	
	else if(dist[destination] >= 65000 && dist[destination] <= 74999){
		price += 4000;
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
	
	else if(dist[destination] >= 75000 && dist[destination] <= 84999){
		price += 5000;
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
}



int shortestDistanceB(string filename, int source, int destination){
	
	long long int amt_nodes, amt_arcs;
	string line;
	
	ifstream myfile (filename);
	
  	if (myfile.is_open()){
    	while ( getline (myfile,line) ){
    		if (line[0] != 'c'){
        		vector<string> line_space_split;
    			line_space_split = split(line,' ');
				switch(line[0]){
					
					case('p'):
						amt_nodes = stoi(line_space_split[2]);
						amt_arcs = stoi(line_space_split[3]);
						//cout<<amt_nodes<<" "<<amt_arcs<<endl;
						break;
						
					case('a'):
						long long int a = stoi(line_space_split[1]);
						long long int b = stoi(line_space_split[2]);
						long long int c = stoi(line_space_split[3]);
						adjList[a].push_back({b,c});
						//Two way activate this
						adjList[b].push_back({a,c});
						break;
				}
			}
    	}
    	myfile.close();
	}
	
	else 
		cout << "Unable to open file";

	
	for(int i=0;i<=amt_nodes;i++) 
		dist[i] = INF;
		
	dist[source] = 0;
 
	for(long long int k = 0; k <amt_nodes-1; k++){
		
		for(long long int i=0;i<amt_nodes;i++){
			
			for(pii f :adjList[i]){
				
				long long int nxt = f.fi, cost = f.se;
				if(dist[i] + cost < dist[nxt]){
					dist[nxt] = dist[i] + cost;
				}
			}
		}
	}

	if(dist[destination] >= 10000000)
		cout<<"unable to compute using bellman" << endl;
		
	else
		cout << "Shortest distance from " << source << " to " << destination << " is " << dist[destination] << " meters " << endl;
	
	int price = 3000; // base rate of the train

	if(dist[destination] <= 34999){
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
		
	else if(dist[destination] >= 35000 && dist[destination] <= 44999){
		price += 1000;
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
	
	else if(dist[destination] >= 45000 && dist[destination] <= 54999){
		price += 2000;
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
	
	else if(dist[destination] >= 55000 && dist[destination] <= 64999){
		price += 3000;
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
	
	else if(dist[destination] >= 65000 && dist[destination] <= 74999){
		price += 4000;
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
	
	else if(dist[destination] >= 75000 && dist[destination] <= 84999){
		price += 5000;
		cout << "Ticket price per person for this trip is Rp." << price << endl;
		cout << endl;
	}
	return 0;
	
}




