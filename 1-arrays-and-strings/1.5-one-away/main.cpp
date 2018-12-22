#include <iostream>
#include <string>
using std::cout;
using std::string;


bool oneAway(string a, string b) {
	string longer(a);
	string shorter(b);

	if (longer.size() < shorter.size())
		longer.swap(shorter);

	if (longer.size() - shorter.size() > 1)
		return false;

	bool foundDiff = false;
	for (int si = 0, li = 0; si < shorter.size() && li < longer.size(); si++, li++) {
		if (shorter[si] != longer[li]) {
			if (foundDiff)
				return false;
			foundDiff = true;
			if (shorter.size() != longer.size())
				si--;
		}
	}

	return foundDiff || longer.size() != shorter.size();
}

int main(int argc, char* argv[]) {
	std::string *s1 = new std::string(argv[1]);
	std::string *s2 = new std::string(argv[2]);

	if (oneAway(*s1, *s2))
		cout << "They are one change apart";
	else
		cout << "They are not one change apart";
	cout << '\n';

	return 0;
}