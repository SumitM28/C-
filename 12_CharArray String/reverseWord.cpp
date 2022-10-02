#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string reverse_words(string s)
{
	int left = 0, i = 0, n = s.size();

	while (s[i] == ' ')
		i++;

	left = i;

	while (i < n) {
		if (i + 1 == n || s[i] == ' ') {
			int j = i - 1;
			if (i + 1 == n)
				j++;

			while (left < j)
				swap(s[left++], s[j--]);

			left = i + 1;
		}
		if (i > left && s[left] == ' ')
			left = i;

		i++;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{

	string str = "Be a game changer the world is already "
				"full of players";

	str = reverse_words(str);

	cout << str;

	return 0;
}
