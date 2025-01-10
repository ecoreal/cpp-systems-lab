////version1.0
//
////#include<iostream>
////#include<vector>
////#include<cstring>
////#include<algorithm> 
//////#include<limits>
////using namespace std;
////#define INF 1e9
////
////int parent[101];
////int rnk[101];
////struct edge
////{
////	int id;
////	int vi;
////	int vj;
////	int weight;
////	edge(int a,int b,int c,int d):id(a),vi(b),vj(c),weight(d){};
////	edge()
////	{
////		id = vi = vj = weight = 0;
////	}
////	bool operator<(edge &other)
////	{
////		return this->weight<other.weight;
////	}
////};
////
////void init(int n)
////{
////	for(int i = 0;i<n;i++)
////	{
////		parent[i] = i;
////		rnk[i] = 0;
////	}
////}
////
////int find(int x)
////{
////	if(x!=parent[x])
////	{
////		parent[x] = find(parent[x]);
////	}
////	return parent[x];
////}
////
////void Union(int x,int y)
////{
////	int rx = find(x);
////	int ry = find(y);
////	if(rx==ry) return;
////	
////	if(rnk[rx]<rnk[ry])
////	{
////		parent[rx] = ry;
////	//	rnk[ry]++; 
////	}
////	else
////	{
////		if(rnk[rx]==rnk[ry])
////		{
////			rnk[rx]++;
////		}
////		parent[ry] = rx;
////	}
////}
////class compare_id
////{
////	public:
////		bool operator()(const edge& e1,const edge& e2)
////		{
////			return e1.id<e2.id;
////		}
////	
////};
////
////int main()
////{
////	freopen("in.txt","r",stdin);
////	int num_node,num_edge;
////	cin>>num_node>>num_edge;
////	vector<edge>v_edge;
////	
////	init(num_edge);
////	
////	int a,b,c,d;
////	while(num_edge--)
////	{
////		cin>>a>>b>>c>>d;
////		v_edge.push_back(edge(a,b,c,d));
////	}
////	sort(v_edge.begin(),v_edge.end());
////	
////	vector<edge>ans;
////	int count_ans = 0;
////	int tube = 1;
////	int i = 0; 
////	while(tube<num_node)
////	{
////		edge temp = v_edge[i];
////		int vi = temp.vi;
////		int vj = temp.vj;
////		
////		int uni = parent[vi];
////		int unj = parent[vj];
////		if(uni!=unj)
////		{
////			ans.push_back(v_edge[i]);
////			tube++;
////			count_ans+= temp.weight;
////			find(uni);
////			find(unj);
////			Union(uni,unj);
////		}
////		i++;
////	}
////	
////	sort(ans.begin(),ans.end(),compare_id());
////	for(vector<edge>::iterator it = ans.begin();it!=ans.end();it++)
////	{
////		printf("%d ",(*it).id);
////	}
////	puts("");
////	printf("%d",count_ans);
//// } 
//

//version2.0
//
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm> 
////#include<limits>
//using namespace std;
//#define INF 1e9
//
//int parent[10];
//int rnk[10];
//struct edge
//{
//	int id;
//	int vi;
//	int vj;
//	int weight;
//	edge(int a,int b,int c,int d):id(a),vi(b),vj(c),weight(d){};
//	edge()
//	{
//		id = vi = vj = weight = 0;
//	}
//	bool operator<(edge &other)
//	{
//		return this->weight<other.weight;
//	}
//};
//
//void init(int n)
//{
//	for(int i = 0;i<n;i++)
//	{
//		parent[i] = i;
//		rnk[i] = 0;
//	}
//}
//
//int find(int x)
//{
//	if(x!=parent[x])
//	{
//		parent[x] = find(parent[x]);
//	}
//	return parent[x];
//}
//
//void Union(int x,int y)
//{
//	int rx = find(x);
//	int ry = find(y);
//	if(rx==ry) return;
//	
//	if(rnk[rx]<rnk[ry])
//	{
//		parent[rx] = ry;
//		rnk[ry]++; 
//	}
//	else
//	{
//		// if(rnk[rx]==rnk[ry])
//		// {
//		// 	rnk[rx]++;
//		// }
//        rnk[rx]++;
//		parent[ry] = rx;
//	}
//}
//class compare_id
//{
//	public:
//		bool operator()(const edge& e1,const edge& e2)
//		{
//			return e1.id<e2.id;
//		}
//	
//};
//
//int main()
//{
////	freopen("in.txt","r",stdin);
//	int num_node,num_edge;
//	cin>>num_node>>num_edge;
//	vector<edge>v_edge;
//	
//	init(num_node);
//	
//	int a,b,c,d;
//	while(num_edge--)
//	{
//		cin>>a>>b>>c>>d;
//		v_edge.push_back(edge(a,b,c,d));
//	}
//	sort(v_edge.begin(),v_edge.end());
//	
//	vector<edge>ans;
//	int count_ans = 0;
//	int tube = 1;
//	int i = 0; 
//	while(tube<num_node)
//	{
//		edge temp = v_edge[i];
//		int vi = temp.vi;
//		int vj = temp.vj;
//		
//		int uni = parent[vi];
//		int unj = parent[vj];
//		if(uni!=unj)
//		{
//			ans.push_back(v_edge[i]);
//			tube++;
//			count_ans+= temp.weight;
//			Union(uni,unj);
//		}
//		i++;
//	}
//	
//	sort(ans.begin(),ans.end(),compare_id());
//	for(vector<edge>::iterator it = ans.begin();it!=ans.end();it++)
//	{
//		printf("%d ",(*it).id);
//	}
//	puts("");
//	printf("%d",count_ans);
// } 
// 

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm> 
//#include<limits>
using namespace std;
#define INF 1e9

int parent[10];
int rnk[10];
struct edge
{
	int id;
	int vi;
	int vj;
	int weight;
	edge(int a,int b,int c,int d):id(a),vi(b),vj(c),weight(d){};
	edge()
	{
		id = vi = vj = weight = 0;
	}
	bool operator<(edge &other)
	{
		return this->weight<other.weight;
	}
};

void init(int n)
{
	for(int i = 0;i<n;i++)
	{
		parent[i] = i;
		rnk[i] = 0;
	}
}

int find(int x)
{
	if(x!=parent[x])
	{
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void Union(int x,int y)
{
	int rx = find(x);
	int ry = find(y);
	if(rx==ry) return;
	
	if(rnk[rx]<rnk[ry])
	{
		parent[rx] = ry;
		rnk[ry]++; 
	}
	else
	{
		// if(rnk[rx]==rnk[ry])
		// {
		// 	rnk[rx]++;
		// }
        rnk[rx]++;
		parent[ry] = rx;
	}
}
class compare_id
{
	public:
		bool operator()(const edge& e1,const edge& e2)
		{
			return e1.id<e2.id;
		}
	
};
void update()
{
    for(int i = 0;i<10;i++)
    {
        if(parent[i]!=i)
        {
            parent[i] = find(parent[i]);
        }
    }
}

int main()
{
//	freopen("in.txt","r",stdin);
	int num_node,num_edge;
	cin>>num_node>>num_edge;
	vector<edge>v_edge;
	
	init(num_node);
	
	int a,b,c,d;
	while(num_edge--)
	{
		cin>>a>>b>>c>>d;
		v_edge.push_back(edge(a,b,c,d));
	}
	sort(v_edge.begin(),v_edge.end());
	
	vector<edge>ans;
	int count_ans = 0;
	int tube = 1;
	int i = 0; 
	while(tube<num_node)
	{
		edge temp = v_edge[i];
		int vi = temp.vi;
		int vj = temp.vj;
		
		int uni = parent[vi];
		int unj = parent[vj];
		if(uni!=unj)
		{
			ans.push_back(v_edge[i]);
			tube++;
			count_ans+= temp.weight;
			Union(uni,unj);
            update();
		}
		i++;
	}
	
	sort(ans.begin(),ans.end(),compare_id());
	for(vector<edge>::iterator it = ans.begin();it!=ans.end();it++)
	{
		printf("%d ",(*it).id);
	}
	puts("");
	printf("%d",count_ans);
 } 
