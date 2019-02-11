#include"header.h"
int main()
{
	cricket_team first_team;
	first_team.print_team();
	cricket_team second_team("fin.txt");
	second_team.print_team();
	second_team.latest_score();
	int result=first_team.compare(second_team);
	cout<<result;
	first_team.input_score(500);
	return 0;
}