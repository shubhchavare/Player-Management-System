#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Player
{
    int PlayerId;
    char PlayerName[20];
    int JerseyNo;
    char JerseyColor[20];
    int MatchesPlayed;
    int Runs;
};

void AddPlayer(struct Player* player, int n);
void DeletePlayer(struct Player* player, int n);
void UpdatePlayer(struct Player* player, int n);
void SearchPlayer(struct Player* player, int n);
void DisplayPlayer(struct Player* player, int n);

void main()
{   
    printf("**********Welcome to Player Management System*************\n");
    int choice,n;
    printf("\nEnter number of players you want to add : \n");
    scanf("%d", &n);
    struct Player* player = (struct Player*)malloc(n * sizeof(struct Player));

    do
    {
        printf("\nEnter your choice : \n1.Add Player \n2.Delete Player \n3.Update Player \n4.Search Player \n5.Display Player \n6.Exit.\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: AddPlayer(player,n);
                    break;
            case 2: DeletePlayer(player,n);
                    break;
            case 3: UpdatePlayer(player,n);
                    break;
            case 4: SearchPlayer(player,n);
                    break;
            case 5: DisplayPlayer(player,n); 
                    break;
            default: printf("Exit");
        }
    } while(choice != 6);  
    free(player);
}

void AddPlayer(struct Player* player, int n)
{
    int i;
    printf("\nInside Add Player...");
    for(i = 0; i < n; i++)
    {
        printf("\nEnter player id : ");
        scanf("%d", &player[i].PlayerId);
        printf("\nEnter player name : ");
        scanf("%s", player[i].PlayerName);
        printf("\nEnter player Jersey number : ");
        scanf("%d", &player[i].JerseyNo);
        printf("\nEnter jersey color : ");
        scanf("%s", player[i].JerseyColor);
        printf("\nEnter matches played : ");
        scanf("%d", &player[i].MatchesPlayed);
        printf("\nEnter runs scored : ");
        scanf("%d",&player[i].Runs);
    }
}

void DeletePlayer(struct Player* player, int n)
{
	int id,i,found=-1;
    printf("\nInside Delete Player...");
    printf("\nEnter the playerid you want to delete :\t");
    scanf("%d",&id);
    
    for(i=0;i<n;i++)
    {
    	if(player[i].PlayerId==id)
    	{
    		found = i;
    		break;
		}
	}
	
		if(found == -1)
		{
			printf("player not found...!");
			return;
		}
		
		for(i=found;i<n-1;i++)
		{
			player[i]=player[i+1];
		}
		n--;
}

void UpdatePlayer(struct Player* player, int n)
{
	int i,found=-1,id;
    printf("\nInside Update Player...");
    printf("\nEnter the playerid you want to update :\t");
    scanf("%d",&id);
    for(i=0;i<n;i++)
    {
    	if(player[i].PlayerId==id)
    	{
    		found = i;
    		break;
		}
	}
		if(found == -1)
		{
			printf("player not found...!");
			return;
		}
		
		 printf("\nEnter player id : ");
        scanf("%d", &player[found].PlayerId);
        printf("\nEnter player name : ");
        scanf("%s", player[found].PlayerName);
        printf("\nEnter player Jersey number : ");
        scanf("%d", &player[found].JerseyNo);
        printf("\nEnter jersey color : ");
        scanf("%s", player[found].JerseyColor);
        printf("\nEnter matches played : ");
        scanf("%d", &player[found].MatchesPlayed);
        printf("\nEnter runs scored : ");
        scanf("%d",&player[found].Runs);
}

void SearchPlayer(struct Player* player, int n)
{
	int i,found=-1,id;
    printf("\nInside Search Player...");
    printf("\nEnter the playerid you want to search :\t");
    scanf("%d",&id);
    
    for(i=0;i<n;i++)
    {
    	if(player[i].PlayerId==id)
    	{
    		found = i;
    		break;
		}
	}
		if(found == -1)
		{
			printf("player not found...!");
			return;
		}
		
		printf("\nPlayer %d:\t", found + 1);
        printf("\n\tPlayer id : %d", player[found].PlayerId);
        printf("\n\tPlayer name : %s ", player[found].PlayerName);
        printf("\n\tJersey number %d: ", player[found].JerseyNo);
        printf("\n\tJersey color %s: ", player[found].JerseyColor);
        printf("\n\tMatches played %d: ", player[found].MatchesPlayed);
	
}

void DisplayPlayer(struct Player* player, int n)
{
    int i;
    printf("\nInside Display Player...");
    for(i = 0; i < n; i++)
    {
        printf("\nPlayer %d:\t", i + 1);
        printf("\n\tPlayer id : %d", player[i].PlayerId);
        printf("\n\tPlayer name : %s ", player[i].PlayerName);
        printf("\n\tJersey number %d: ", player[i].JerseyNo);
        printf("\n\tJersey color %s: ", player[i].JerseyColor);
        printf("\n\tMatches played %d: ", player[i].MatchesPlayed);
    }
}

