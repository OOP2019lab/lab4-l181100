#include <iostream>
#include<conio.h>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

class cricket_team
{
string * member_names;
int no_of_members;
char *Team_name;
int score_of_last_10_matches[10];
int rank;
string Captain;
public:
	cricket_team();
	cricket_team(string, int);
	cricket_team(string);
	void set_Captain(string);
	void set_Rank(int);
	void set_Team_name(string);
	void set_no_of_members(int);
	string get_Captain();
	int get_Rank();
	string get_Team_name();
	int get_no_of_members();
	void input_team_member(string );
	void input_score(int);
	float avg_score();
	void latest_score();
	void print_team();
	bool compare(cricket_team);
	void input();
	~cricket_team();
};
