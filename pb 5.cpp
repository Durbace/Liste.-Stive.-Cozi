#include <iostream>
#include <queue>
#include <string>
struct stiva
{
	std::queue<char> q1, q2;
	void Push(char val)
	{
		q2.push(val);
		while (!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		std::swap(q1, q2);
	}
	void Pop()
	{
		while (!q1.empty())
			q1.pop();
	}
};
bool parantezareCorecta(std::string paranteze)
{
	stiva st;
	for (char paranteza : paranteze)
	{
		if (paranteza == '(' || paranteza == '[' || paranteza == '{')
			st.Push(paranteza);
		else if (paranteza == ')' || paranteza == ']' || paranteza == '}')
		{
			if (st.q1.empty())
				return false;
			char ultimaParantezaDeschisa = st.q1.front();
			st.q1.pop();
			if (ultimaParantezaDeschisa == '{' && !st.q1.empty())
				return false;
			else if (ultimaParantezaDeschisa == '[' && !st.q1.empty() && st.q1.front() == '(')
				return false;
			if ((paranteza == ')' && ultimaParantezaDeschisa != '(')
				|| (paranteza == ']' && ultimaParantezaDeschisa != '[')
				|| (paranteza == '}' && ultimaParantezaDeschisa != '{'))
				return false;
		}
	}
	return st.q1.empty();
}
int main()
{
	std::string paranteze1 = "[()]";
	std::string paranteze2 = "}[()]";
	std::string paranteze3 = "[{()}]";
	std::cout << "Parantezare corecta: " << parantezareCorecta(paranteze1) << std::endl;
	std::cout << "Parantezare corecta: " << parantezareCorecta(paranteze2) << std::endl;
	std::cout << "Parantezare corecta: " << parantezareCorecta(paranteze3) << std::endl;
	return 0;
}