
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<time.h>


 void createMatrix(int arr[][4])
{
  int i,j,k,low=1,up=15,temp;
  srand(time(NULL));
  for(i=0;i<4;i++)
  {
      for(j=0;j<4;j++)
      {
          temp=rand()%15+low;

      }
      for(k=0;k<j-1;k++)
      {
          if( temp==arr[i][k])
                  break;
      }
      if(k==j)
        arr[i][j]=temp;
      else
        j--;
  }

  printf("-----------------\n");
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {

      if(i==3 && j==3)
        break;

      else
     {
         if(arr[i][j]<=9)
          printf("| %d ",arr[i][j]);
         else
          printf("| %d",arr[i][j]);
      }

    }
    printf("|\n");

  }

  printf("-----------------\n");
}



/*void showMatrix(int arr[][4])
{
    int i,j;
   printf("-----------------\n");






  printf("-----------------\n");
}*/








int winner(int arr[][4])
{
    int i,j,k=1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]!=k && k!=16)
                break;
            if(j<4)
              break;

        }
        if(j<4)
            return 0;
        else
            return 1;
    }
}

void swap(int *x, int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
    printf(" ");
}

int readEnteredkey()
{
    char c;
    c=getch();
    if(c==37)
        c=getch();
    return c;

}

int shiftup(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(j<4)
            break;
    }
    if(i==3)
        return 0;
    swap(&arr[i][j],&arr[i+1][j]);
      return 1;
}

int shiftdown(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(j<4)
            break;
    }
    if(i==0)
        return 0;
    swap(&arr[i][j],&arr[i-1][j]);
      return 1;
}

int shiftright(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(j<4)
            break;
    }
    if(j==0)
        return 0;
    swap(&arr[i][j],&arr[i][j-1]);
      return 1;
}

int shiftleft(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(j<4)
            break;
    }
    if(j==3)
        return 0;
    swap(&arr[i][j],&arr[i][j+1]);
      return 1;
}

void gameRule(int a[][4])
{

  int i,j,t=1,gm=0,gd=0;

  printf("\t\t\t***** RULE OF THIS GAME *****\t\t\t\n");
  printf("\n1. You can move only 1 step at a time by arrow key\n");
  printf("Move UP\t \t: by Up arrow key");
  printf("\nMove Down\t: by Down arrow key");
  printf("\nMove Left\t: by Left arrow key");
  printf("\nMove Right\t: by Right arrow key");
  printf("\n\n2. You can move number at empty position only");
  printf("\n\n3. For each valid move: your total mnumber of move will decreased by 1");
  printf("Winning Situation: number in a 4X4 matrix should be in order from 1 to 15");
  printf("\n\n\t\t\tWinning Situation:");

  printf("-----------------\n");
   for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      if(i!=4 && j!=4)
      {
        a[i][j]=t;
        t++;
      }
      else
         break;
    }
  }

  printf("-----------------\n");
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {

      if(i==3 && j==3)
        break;

      else
     {
         if(a[i][j]<=9)
          printf("| %d ",a[i][j]);
         else
          printf("| %d",a[i][j]);
      }

    }
    printf("|\n");

  }

  printf("-----------------\n");

  printf("\n\n5. You can exit the game at any time by pressing \'E\' or \'e\'\n\nSo Try to win the game in minimum no of move ");
  printf("\n\n\t\t\t HaPpY Gaming, GooD LucK");
  printf("\n\nEnter any key to start_ _ _ _ _ _ _ _\n");

}
int main()
{
    int arr[4][4]; int maxTry=400,key,t;
    char name[20],check;

    printf("Enter your good name: ");
    fgets(name,20,stdin);
    while(1)
    {
        //createMatrix(arr);
        gameRule(arr);
        while(!winner(arr))
        {

            if(!maxTry)
                break;
            printf("\n\nWelcome: %s ",name);
            printf("\t\t Your Remaining Moves: %d\n\n",maxTry);
            //showMatrix(arr);
            createMatrix(arr);
            key=readEnteredkey();
            switch(key)
            {
            case(69):
                printf("\n\nThanks for playing %s",name);
                printf("\n\nHit the \'Enter\' key to exit.");
                 key=readEnteredkey();
                 exit(0);
            case 38:
                if(shiftup(arr));
                {
                    maxTry--;
                    break;
                }
             case 40:
                if(shiftdown(arr));
                {
                    maxTry--;
                    break;
                }
             case 39:
                if(shiftright(arr));
                {
                    maxTry--;
                    break;
                }
             case 37:
                if(shiftleft(arr));
                {
                    maxTry--;
                    break;
                }
             default:
                printf("\n\n\"Please Enter a valid key which is told you in the game rule\"\n");

            }
        }
        if(!maxTry)
             printf("\n  You Lose !\n");
        else
        {
            printf("\n Congratulations! %s: ",name);
            printf("\n\n You\'ve won the game");

        }
        char check;
        printf("\nDo you want to play again?\n");
        printf("\nEnter y to play again: ");
        scanf("%c",&check);
        if(check!='y' && check!='Y')
            break;
        maxTry=400;

    }
    return 0;
}
