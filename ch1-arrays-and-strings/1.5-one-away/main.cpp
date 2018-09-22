#include <iostream>
#include <string>

bool charChange(const std::string& s1, const std::string& s2) {
	if (s1.size() != s2.size())
		return false;

	bool changeNeeded = false;

	for (int i = 0; i < s1.size(); i++) {
		if (s1.at(i) != s2.at(i)) {
			if (changeNeeded)
				return false;
			else
				changeNeeded = true;
		}
	}

	return true;
}

bool charInsert(const std::string& s1, const std::string& s2) {
	int lenDiff = s1.size() > s2.size() ? s1.size() - s2.size() : s2.size() - s1.size();
	
	if (lenDiff != 1)
		return false;
	
	bool changeNeeded = false;
	int i, j;
	for(i = 0, j = 0; i < s1.size() && j < s2.size(); i++, j++) {
		if (s1.at(i) != s2.at(j)) {
			if (changeNeeded)
				return false;
			else {
				changeNeeded = true;
				if (s1.size() > s2.size()) {
					i++;
				}
				else {
					j++;
				}
			}
		}
	}

	return true;
}

bool oneAway(const std::string& s1, const std::string& s2) {
	return charChange(s1, s2) || charInsert(s1, s2);
}

int main(int argc, char* argv[]) {
	std::string *s1 = new std::string(argv[1]);
	std::string *s2 = new std::string(argv[2]);

	if (oneAway(*s1, *s2))
		std::cout << "They are one change apart";
	else
		std::cout << "They are not one change apart";
	std::cout << std::endl;

	return 0;
}