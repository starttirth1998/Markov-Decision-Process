
//Tirth Maniar
#include<bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1 && arg1){
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1 && arg1, Args &&... args){
	const char* comma = strchr(names+1,','); cerr.write(names,comma-names) << " : " << arg1 << " | "; __f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define ALL(c) c.begin(),c.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) (container.find(element) != container.end())
				// For Set and Map
#define cpresent(container, element) (find(all(container),element) != container.end())
				// For Vector
				// Use v.clear() to remove all elements
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
				// Better to use v.empty() instead of comparing with 0 to check if empty
#define F first
#define S second
			// For pair
#define mod 1000000007
#define sd(x) scanf("%d",&x)
#define pd(x) printf("%d\n",x)
#define sll(x) scanf("%lld",&x)
#define pll(x) printf("%lld\n",x)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long long ll;
typedef vector<int> VI;
typedef vector< VI > VVI;    	// 2-d array
typedef pair<int,int> PII;
typedef vector<PII> VPII;

inline int mult(int x,int y){return ((ll)x*y)%mod;}
int power(int x,int y){int ret=1; while(y){ if(y&1) ret = mult(ret,x); x = mult(x,x); y = y/2;} return ret;}
int gcd(int a,int b){ if(b) return gcd(b,a%b); return a;}
VI prime;
void generateprime(int n){ int i,j; VI num(n+5); num[1]=1; for(i=4;i<n;i=i+2) num[i]=1;
	for(i=3;i<n;i++){ if(num[i]==0) { for(j=3*i;j<n;j=j+2*i) num[j] = 1;}} num[0] = 0;
	for(i=2; i<n; i++){ if(num[i]==0) prime.PB(i); num.clear();}
}

int rMax = 3, cMax = 3;

double U[10][10];
double Up[10][10];
double R[10][10];
char Pi[10][10];

int maxindex(double a[], int a_length)
{
  int b=0;
  for(int i=1; i<a_length; i++)
      b = (a[b] > a[i]) ? b : i;
  return b;
}

double aNorth(int r,int c)
{
	if((r == 0) || (r == 3 && c == 2) || (r == 1 && c == 0) || (r == 1 && c == 1) || (r == 1 && c == 3))
		return U[r][c];
	return U[r-1][c];
}

double aSouth(int r,int c)
{
	if((r == rMax) || (r == 1 && c == 2))
		return U[r][c];
	return U[r+1][c];
}

double aEast(int r,int c)
{
	if((c == cMax) || (r == 2 && c == 1) || (r == 0 && c == 0) || (r == 0 && c == 2))
		return U[r][c];
	return U[r][c+1];
}

double aWest(int r,int c)
{
	if((c == 0) || (r == 2 && c == 3) || (r == 0 && c == 2) || (r == 0 && c == 1))
		return U[r][c];
	return U[r][c-1];
}

void print()
{
	for(int r=0;r<=rMax;r++)
	{
		for(int c=0;c<=cMax;c++)
		{
			printf("%lf ",U[r][c]);
		}
		printf("\n");
	}
	printf("\n");
	int temp;
	//cin >> temp;
}

int main()
{
	int X = 64;	// team number
	int N = 10000;
	double Ra = (-0.05)*X;
	double gamma = 1;
	double delta = (0.05)*X;
	double pGood = 0.8;
	double pBad = 0.1;

	//delta = 0.000001;
	int r,c;
	double del = 0;

	for(r=0;r<=rMax;r++)
	{
		for(c=0;c<=cMax;c++)
		{
			Up[r][c] = 0;
			R[r][c] = Ra;
		}
	}
	R[0][2] = X;
	R[2][1] = -X;
	R[0][0] = 0;
	R[0][1] = 0;
	R[0][3] = 0;
	R[2][2] = 0;

	int n = 0;
	do
	{
		for(r=0;r<=rMax;r++)
		{
			for(c=0;c<=cMax;c++)
			{
				if ((r==0 && c==2) || (r==2 && c==1) || (r==0 && c==0) || (r==0 && c==1) || (r==0 && c==3) || (r==2 && c==2))
				{
		      Up[r][c] = R[r][c];
		    }
				U[r][c] = Up[r][c];
			}
		}
		trace(n,del,delta,Ra);
		//cout << n << endl;
		print();
		n++;
		del = 0;
		for(r=0;r<=rMax;r++)
		{
			for(c=0;c<=cMax;c++)
			{
				int a_size=4;
		    double a[a_size];
		    if ((r==0 && c==2) || (r==2 && c==1) || (r==0 && c==0) || (r==0 && c==1) || (r==0 && c==3) || (r==2 && c==2))
				{
		      Up[r][c] = R[r][c];
		    }
		    else
				{
	        a[0] = R[r][c] + aNorth(r,c)*pGood + aWest(r,c)*pBad + aEast(r,c)*pBad;
	        a[1] = R[r][c] + aSouth(r,c)*pGood + aWest(r,c)*pBad + aEast(r,c)*pBad;
	        a[2] = R[r][c] + aWest(r,c)*pGood + aSouth(r,c)*pBad + aNorth(r,c)*pBad;
	        a[3] = R[r][c] + aEast(r,c)*pGood + aSouth(r,c)*pBad + aNorth(r,c)*pBad;

					//printf("%d %d\n",r,c);
					//printf("N:%lf + %lf*%lf + %lf*%lf + %lf*%lf = %lf\n",R[r][c],aNorth(r,c),pGood,aWest(r,c),pBad,aEast(r,c),pBad,a[0]);
					//printf("E:%lf + %lf*%lf + %lf*%lf + %lf*%lf = %lf\n",R[r][c],aEast(r,c),pGood,aSouth(r,c),pBad,aNorth(r,c),pBad,a[3]);
					//printf("S:%lf + %lf*%lf + %lf*%lf + %lf*%lf = %lf\n",R[r][c],aSouth(r,c),pGood,aWest(r,c),pBad,aEast(r,c),pBad,a[1]);
					//printf("W:%lf + %lf*%lf + %lf*%lf + %lf*%lf = %lf\n",R[r][c],aWest(r,c),pGood,aSouth(r,c),pBad,aNorth(r,c),pBad,a[2]);
					trace(r,c,a[0],a[1],a[2],a[3]);

	        int best = maxindex(a,a_size);

	        Up[r][c] = gamma * a[best];

	        Pi[r][c] = (best==0 ? 'N' : (best==1 ? 'S' : (best==2 ? 'W': 'E')));
		    }
				double diff = abs(Up[r][c] - U[r][c]);
				if(diff > del)
					del = diff;
			}
		}
	}while(del > delta && n < N);
	trace(n,del,delta,Ra);
	for(r=0;r<=rMax;r++)
	{
		for(c=0;c<=cMax;c++)
		{
			if ((r==0 && c==2) || (r==2 && c==1) || (r==0 && c==0) || (r==0 && c==1) || (r==0 && c==3) || (r==2 && c==2))
			{
				Up[r][c] = R[r][c];
			}
			U[r][c] = Up[r][c];
		}
	}
	/*for(r=0;r<=rMax;r++)
	{
		for(c=0;c<=cMax;c++)
		{
			printf("%c ",Pi[r][c]);
		}
		printf("\n");
	}
	printf("\n");*/
	print();
	n++;
	trace(n);
	//cout << n << endl;

	del = 0;
	for(r=0;r<=rMax;r++)
	{
		for(c=0;c<=cMax;c++)
		{
			int a_size=4;
			double a[a_size];
			if ((r==0 && c==2) || (r==2 && c==1) || (r==0 && c==0) || (r==0 && c==1) || (r==0 && c==3) || (r==2 && c==2))
			{
				Up[r][c] = R[r][c];
			}
			else
			{
				a[0] = R[r][c] + aNorth(r,c)*pGood + aWest(r,c)*pBad + aEast(r,c)*pBad;
				a[1] = R[r][c] + aSouth(r,c)*pGood + aWest(r,c)*pBad + aEast(r,c)*pBad;
				a[2] = R[r][c] + aWest(r,c)*pGood + aSouth(r,c)*pBad + aNorth(r,c)*pBad;
				a[3] = R[r][c] + aEast(r,c)*pGood + aSouth(r,c)*pBad + aNorth(r,c)*pBad;

				//printf("%d %d\n",r,c);
				//printf("N:%lf + %lf*%lf + %lf*%lf + %lf*%lf = %lf\n",R[r][c],aNorth(r,c),pGood,aWest(r,c),pBad,aEast(r,c),pBad,a[0]);
				//printf("E:%lf + %lf*%lf + %lf*%lf + %lf*%lf = %lf\n",R[r][c],aEast(r,c),pGood,aSouth(r,c),pBad,aNorth(r,c),pBad,a[3]);
				//printf("S:%lf + %lf*%lf + %lf*%lf + %lf*%lf = %lf\n",R[r][c],aSouth(r,c),pGood,aWest(r,c),pBad,aEast(r,c),pBad,a[1]);
				//printf("W:%lf + %lf*%lf + %lf*%lf + %lf*%lf = %lf\n",R[r][c],aWest(r,c),pGood,aSouth(r,c),pBad,aNorth(r,c),pBad,a[2]);
				trace(r,c,a[0],a[1],a[2],a[3]);

				int best = maxindex(a,a_size);

				Up[r][c] = gamma * a[best];

				Pi[r][c] = (best==0 ? 'N' : (best==1 ? 'S' : (best==2 ? 'W': 'E')));
			}
		}
	}
	for(r=0;r<=rMax;r++)
	{
		for(c=0;c<=cMax;c++)
		{
			if ((r==0 && c==2) || (r==2 && c==1) || (r==0 && c==0) || (r==0 && c==1) || (r==0 && c==3) || (r==2 && c==2))
			{
				Up[r][c] = R[r][c];
			}
			U[r][c] = Up[r][c];
		}
	}
	print();
return 0;
}
