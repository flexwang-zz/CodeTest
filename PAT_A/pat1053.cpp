#include<stdio.h>
#include<vector>
#include<algorithm>

#define min(a,b) ((a<b)?a:b)

using namespace std;

struct Node
{
	vector<int> children;
	int weight;

	Node(){}
	Node(int w):weight(w){}
};

class Path
{
public:
	vector<int> ws;
	int weight;
	int nextnodeid;

	Path():weight(0){}
	Path(int w)
	{
		ws.push_back(w);

		weight = w;
	}

	Path& operator+=(int w)
	{
		this->ws.push_back(w);
		this->weight += w;

		return *this;
	}

	bool operator<(const Path&path) const
	{
		int size = min(ws.size(), path.ws.size());

		for( int i=0; i<size; i++)
		{
			if( ws[i] > path.ws[i] )
			{
				return true;
			}
			else if( ws[i] < path.ws[i])
			{
				return false;
			}
		}

		return false;
	}

	void print()
	{
		for( int i=0, size=ws.size(); i<size; i++)
		{
			printf("%d", ws[i]);
			if( i != size-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
};

int main()
{
	int nnode, nfather, weight;
	vector<Node> nodes(100);

	scanf("%d %d %d", &nnode, &nfather, &weight);

	for( int i=0; i<nnode; i++)
	{
		scanf("%d", &nodes[i].weight);
	}

	for( int i=0; i<nfather; i++)
	{
		int nodeid;
		int nchildren;
		scanf("%d %d", &nodeid, &nchildren);

		nodes[nodeid].children = vector<int>(nchildren);

		for(int i=0; i<nchildren; i++)
		{
			scanf("%d", &(nodes[nodeid].children[i]));
		}
	}

	vector<Path> paths(1);
	vector<Path> nextlayer;
	vector<Path> result;
	
	paths[0].nextnodeid = 0;

	while(paths.size())
	{
		vector<Path>::iterator iter = paths.begin();
		while(iter != paths.end())
		{
			int id = iter->nextnodeid;
			*iter += nodes[id].weight;

			if( iter->weight > weight)
			{
				iter ++;
				continue;
			}
			else
			{
				int size = nodes[id].children.size();

				if( size <= 0)
				{
					if( iter->weight == weight)
					{
						result.push_back(*iter);
					}
					iter ++;
					continue;
				}
				else
				{
					for( int i=0; i<size; i++)
					{
						Path p = *iter;
						p.nextnodeid = nodes[id].children[i];
						nextlayer.push_back(p);
					}
					iter ++;
				}
			}
		}
		paths = nextlayer;
		nextlayer.clear();
	}

	sort(result.begin(), result.end());

	for( int i=0, size=result.size(); i<size; i++)
	{
		result[i].print();
	}

	return 0;
}
