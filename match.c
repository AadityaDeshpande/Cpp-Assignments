#include<stdio.h>  
#include<string.h>
#include<time.h>
#define c_len 30

typedef struct Player   
{  
      int pid;
      char pname[c_len];
      char skill[c_len];
      int Not_Out = 1;
      int score;
      int wickets;
      int overs;
      
}player;

  
typedef struct Team  
{  
    char tname[c_len];
    int Team_score;  
    player p_list[4];  
}team;



player setPlayerData(player person)
{
	printf("Enter player id : \n");
	scanf("%d",&person.pid);
	
	printf("Enter player name : \n");
	scanf("%s",person.pname);
	
	printf("Enter player skill (bat\\ball) : \n");
	scanf("%s",person.skill);
	
	return person;
}
  
team setTeamData(team mob)
{

	printf("Enter team name : \n");
	scanf("%s",mob.tname);
	
	for(int i = 0; i < 4; i++)
	{
	
		mob.p_list[i] = setPlayerData(mob.p_list[i]);	
	
	}
	
	return mob;
}  

void getTeamData(team mob)
{
	printf("Team name is := %s \n",(mob.tname));
	
	for(int i = 0 ; i < 4 ; i++)
	{
		printf("player id : %d \n",mob.p_list[i].pid);
	
		printf("player name : %s \n",mob.p_list[i].pname);
	
		printf("player skill (bat\\ball) : %s \n",mob.p_list[i].skill);
		
	}
}
 

void playMatch (team t1 , team t2, int overs)
{
	int toss;
	toss = myRandom(2);
	if(toss == 0)
	{
	printf("Team %s Won a toss and will do batting\n",t1.tname);
	}
	else if (toss == 1)
	{
	printf("Team %s Won a toss and will do batting\n",t2.tname);
	}
	
	
	
	//return NULL; //winner team
}



//find all bats man that are not out and will play 
//find all baller after each over 

// record team score

//same code just swapped teams

//one with greater team score wins.




int myRandom(int Max) 
{
	srand(time(NULL));
	
 //return (rand()%(Max-Min) + Min); 
 return (rand()%Max);
}
 
  
  
int main ()  
{
	/*
	team hero;
	hero = setTeamData(hero);
	getTeamData(hero);
	*/
	
	team teams[2];
	
	for(int i = 0 ; i < 2 ; i++)
	{
		teams[i] = setTeamData(teams[i]);
		getTeamData(teams[i]);	
	}
	
	printf("\n\n");
	
	for(int i = 0 ; i < 2 ; i++)
	getTeamData(teams[i]);	
	
	playMatch (teams[0],teams[1],2);
	
	
  return 0;
}    
