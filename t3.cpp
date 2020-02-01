#include <iostream>
#include <iostream>
#include <algorithm>

using namespace std;

struct activity
{
	int start, end;
};

activity activities[100000]; // Up to 100000 activies max

bool value(struct activity a, struct activity b)
{
	if (a.end == b.end) // both activies ends at the same time
		return a.start < b.start; // check if first activity starts first

	// If not, then check if first activity ends first
	return a.end < b.end;
}

int main()
{
	int t;

	cin >> t;
	while (t--)
	{
		int n, end = -1, count = 0, i;
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> activities[i].start >> activities[i].end;

		std::sort(activities, activities + n, value);
		for (i = 0; i < n; i++)
		{
			if (activities[i].start >= end)
			{
				count += 1;
				end = activities[i].end;
			}
		}
		cout << count << endl;
	}

	return 0;
}