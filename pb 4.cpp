#include <iostream>
#include <stack>
#include <string>
bool esteCorect(std::string paranteze)
{
	std::stack<char> stiva;
	for (char paranteza : paranteze)
	{
		if (paranteza == '(' || paranteza == '[' || paranteza == '{')
		{
			stiva.push(paranteza);
		}
		else if (paranteza == ')' || paranteza == ']' || paranteza == '}')
		{
			if (stiva.empty())
			{
				return false;
			}
			char ultimaParantezaDeschisa = stiva.top();
			stiva.pop();
			if (ultimaParantezaDeschisa == '{' && !stiva.empty())
				return false;
			else if (ultimaParantezaDeschisa == '[' && !stiva.empty() && stiva.top() == '(')
				return false;
			if ((paranteza == ')' && ultimaParantezaDeschisa != '(') ||
				(paranteza == ']' && ultimaParantezaDeschisa != '[') ||
				(paranteza == '}' && ultimaParantezaDeschisa != '{')) {
				return false;
			}
		}
	}
	return stiva.empty();
}
int main() {
	std::string paranteze1 = "[{()()}]";
	std::string paranteze2 = "(){[]}()";
	std::string paranteze3 = "[()]()";
	std::cout << paranteze1 << " este corect: " << esteCorect(paranteze1) << std::endl;
	std::cout << paranteze2 << " este corect: " << esteCorect(paranteze2) << std::endl;
	std::cout << paranteze3 << " este corect: " << esteCorect(paranteze3) << std::endl;
	return 0;
}