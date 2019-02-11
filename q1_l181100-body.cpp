#include"header.h"

cricket_team:: cricket_team()
{
	member_names=nullptr;
	no_of_members=-5;
	Team_name=nullptr;
	for(int i=0; i<10; i++)
	{
		score_of_last_10_matches[i] = -5;
	}
	rank=-5;
	Captain = "";
}

cricket_team:: cricket_team(string name, int members)
{
	int L;
	member_names=nullptr;
	if(members>0 && members<12)
	{
		no_of_members = members;
	}
	else 
	{
		no_of_members = -5;
	}

	Captain="";
	rank=-5;
	Team_name=nullptr;
	L=name.length();
	Team_name=new char[L+1];
	strcpy(Team_name,name.c_str());
	for(int i=0; i<10; i++)
	{
		score_of_last_10_matches[i]=-5;
	}

}
cricket_team::cricket_team(string filename)
{
	ifstream fin;
	int n;
	string arr;
	fin.open(filename);
		while(!fin.eof())
		{
			getline(fin,arr,':');
			getline(fin,arr);
			int len=arr.length();
			Team_name=new char[len+1];
			strcpy(Team_name,arr.c_str());
			getline(fin,arr,':');
			fin>>n;
			if(n>0 && n<12)
				no_of_members=n;
			else 
				no_of_members=-5;
			member_names=new string[no_of_members];
			for(int i=0; i<no_of_members; i++)
			{
				getline(fin,arr);
				member_names[i]=arr;
			}
			getline(fin,arr,':');
			fin>>n;
			if (n>0)
				rank=n;
			else 
				rank=0;
			getline(fin,arr,':');
			getline(fin,arr);
			Captain=arr;
			getline(fin,arr,':');
			for(int i=0; i<10; i++)
			{
				getline(fin,arr,',');
				n = stoi(arr);
				score_of_last_10_matches[i]=n;
			}
		}
}
void cricket_team::set_Captain(string name)
{
	Captain=name;
}
void cricket_team::set_Rank(int rank1)
{
	if (rank1>0)
		rank=rank1;
	else
		rank=-5;
}
void cricket_team :: set_Team_name(string name)
{
	if(Team_name!=nullptr)
	{
		delete Team_name;
	}
	int len=name.length();
	Team_name=nullptr;
	Team_name=new char[len+1];
	strcpy(Team_name,name.c_str());
}

void cricket_team:: input() 
{
	cout<<"Press 2 to take input from file \n";
	cout<<"Press 1 to take input from user\n";

	int x=0;
	cin>>x;

	if (x==1)
	{
		ifstream fin;
		string file;
		string arr;
		int num;
		cout<<"Enter name of file from which you want to raed data : \n";
		cin>>file;
		fin.open(file);
		if(!fin.is_open())
			cout<<"File did not open"<<endl;
		while(!fin.eof())
		{
			getline(fin,arr,':');
			getline(fin,arr);
			int len=arr.length();
			Team_name=new char[len+1];
			strcpy(Team_name,arr.c_str());
			getline(fin,arr,':');
			fin>>num;
			if(num>0 && num<12)
				no_of_members=num;
			else 
				no_of_members=-5;
			member_names=new string[no_of_members];
			for(int i=0; i<no_of_members; i++)
			{
				getline(fin,arr);
				member_names[i]=arr;
			}
			getline(fin,arr,':');
			fin>>num;
			if (num>0)
				rank=num;
		}
	}
	if (x==2)
	{
		string arr1; 
		cout<<"Enter namer of team : \n";
		cin>>arr1;
		int len=arr1.length();
		Team_name=new char[len+1];
		strcpy(Team_name,arr1.c_str());
		cout<<"Enter rank : \n";
		cin>>rank;
		cout<<"Enter captain name : \n";
		getline(cin,Captain);
		cout<<"numbers of teams are : \n";
		cin>>no_of_members;
		member_names=new string[no_of_members];
		cout<<"Enter names of members : \n";
		for (int i=0; i<no_of_members;i++)
		{
			getline(cin,member_names[i]);
		}
		cout<<"Enter  previous 10 scores: \n";
		for(int i=0; i<10; i++)
			cin>>score_of_last_10_matches[i];
	}
}

void cricket_team:: set_no_of_members(int n) 
{
	if(n>0 && n<12)
		no_of_members=n;
	else 
		no_of_members=0;
	member_names=new string[no_of_members];
}

int cricket_team:: get_Rank()
{
	return rank;
}

string cricket_team:: get_Captain()
{
	return Captain;
}

int cricket_team:: get_no_of_members()
{
	return no_of_members;
}

string cricket_team:: get_Team_name()
{
	return Team_name;
}

void cricket_team:: input_team_member(string name)
{
	bool arr_is_full=false;
	for (int i=0; i<no_of_members;i++)
		if (member_names[i]!="")
			arr_is_full=true;
		else
			arr_is_full=false;
	if (arr_is_full==false)
	{
		for (int i=0; i<no_of_members;i++)
		{
			if (member_names[i]=="")
			{
				member_names[i]=name;
			}
		}
	}
	else
		cout<<"Array is full. No space left for new members \n";
}
void cricket_team:: input_score(int number) 
{
	bool check=false;
	for (int i=0; i<10; i++)
	{
		if(score_of_last_10_matches[i]==-5)
			check=false;
		else
			check=true;
	}

	if (check==false)
	{
		if (number>=0)
		{
			for(int i=0; i<10; i++)
			{
				if(score_of_last_10_matches[i]==-1)
				{
					score_of_last_10_matches[i]=number;
					check=true;
				}
			}
		}
	}
	else
	{
		if (number>-5)
		{

			for(int i=0; i<10; i++)
				score_of_last_10_matches[i]=score_of_last_10_matches[i+1];
			score_of_last_10_matches[10]==number;
		}
	}
}
float cricket_team:: avg_score()
{
	float sum = 0;
	float average = 0;
	for(int i=0; i<10; i++)
	{
		sum=sum+score_of_last_10_matches[i];
	}
	average = sum/10;
	if (average>0)
		return average;
	else
		return 0;
}
void cricket_team:: latest_score() 
{
	if(Team_name!=nullptr)
	{
		cout<<"Team Name: ";
		for(int i=0; Team_name[i]!='\0';i++)
			cout<<Team_name[i];
		cout<<endl;
	}
	cout<<"captain of team is : \n" ;
	cout<<Captain<<endl;
	cout<<"Latest score: \n";
	for(int i=9; i>=0;i--)
		if (score_of_last_10_matches[i]!=-5)
		{
			cout<<score_of_last_10_matches[i]<<endl;
			break;
		}
}
void cricket_team:: print_team() 
{
	if(Team_name!=nullptr)
	{
		cout<<"Team Names are  : \n";
		for (int i=0; Team_name[i]!='\0';i++)
			cout<<Team_name[i]<<endl;
	}

	cout<<"Rank : \n";
	cout<<rank<<endl;
	cout<<"Captain : \n";
	cout<<Captain<<endl;
	if (member_names!=nullptr)
	{
		cout<<"No of members are : \n";
		cout<< no_of_members<<endl;
		for (int i=0; i<no_of_members;i++)
		{
			cout<<member_names[i];
		}
	}
}



cricket_team:: ~cricket_team()
{
	delete[] member_names;
	delete[] Team_name;
}