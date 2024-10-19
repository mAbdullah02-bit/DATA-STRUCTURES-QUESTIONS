#include<iostream>

using namespace std;

int pyramidsum(int n) {
	int sum = 0;
	int c = 0, k = 0;

	for (int i = 1; i <= n; i++)
	{  
		for (int k = n*2; k > i; k--) { cout << "  "; }

		for (int j = 1; j <= c+i; j++)
		{
			if (j<=i)
			{
				cout << j<<" ";
				sum += j;
				k = j - 1;
			}
			else
			{

				cout << k<<" ";
				sum += k;
				k--;
			}
		}
		cout << endl;
		c++;
	}

	return sum;

}

int main() {

	int n;
	cin >> n;
cout<<	pyramidsum(n)<<endl;

	return 0;
}