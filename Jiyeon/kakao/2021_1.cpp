#include <string>
#include <vector>

using namespace std;

/*
 * 정답률이 57퍼라고..??..
 * O(n)으로 잘 풀린다
 */

string solution(string new_id) {
	string answer = "";

	bool formerIsDot = false;
	for (char c : new_id) {
		if(('A' <= c) && (c <= 'Z'))
			c = c + ('a' - 'A');
		if(!((('a' <= c) && (c <= 'z')) || (('0' <= c) && (c <= '9')) || (c == '-')
					|| (c == '_') || (c == '.')))
			continue;
		if(c == '.') {
			if(formerIsDot)
				continue;
			else
				formerIsDot = true;
		} else {
			formerIsDot = false;
		}
		answer += c;
	}
	if ((answer.length() > 0) && (answer[0] == '.'))
		answer = answer.substr(1);
	if ((answer.length() > 0) && (answer[answer.length()-1] == '.'))
		answer = answer.substr(0, answer.length()-1);
	if (answer == "")
		answer = "a";
	answer = answer.substr(0, 15);
	if ((answer.length() > 0) && (answer[answer.length()-1] == '.'))
		answer = answer.substr(0, answer.length()-1);
	while(answer.length() <= 2) {
		answer += answer[answer.length()-1];
	}

	return answer;
}
