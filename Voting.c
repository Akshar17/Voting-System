#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
FILE *Vid;
int count1=0;
int count2=0;
int count3=0;
int count4=0;

void fordelay();
void votedcheck();
void searchid1();
void searchid();
void viewlist();
void apply();
void vote();
void welcome();
void bjp();
void cong();
void aap();
void nota();
void winner();
void winnerbjp();
void wiineraap();
void winnercon();
void winnernota();
void votedcheck();
void voting();
void elsesearch();
void result();


struct
{
    int id;
}check;

void fordelay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
        {
            k=i;
        }
}

void searchid1(int voter)
{
    FILE *p;
    int n;
    p=fopen("Registered.txt","r");
    while(fscanf(p,"%d",&check.id)!=EOF)
        {
            if(voter==check.id)
                {
                    fordelay(1000000000);
                    printf("\n\nID already exists!");
                    fordelay(100000000);
                    printf("\n\nThis id is registered.");
                    fordelay(1000000000);
                    printf("\n\nNext person please.");
                    fordelay(1000000000);
                    system("cls");
                    main();
                }
        }
}


void apply()
{
    FILE *x;
    char address[30],first[10],last[10],fname[10];
    char nation[10],a[7]={"INDIAN"},b[7]={"indian"};
    int applyage=0,voter=0,pincode=0,day,month,year;
    printf("\n\t\t\t**********************");
    printf("\n\t\t\t*    REGISTRATION    *");
    printf("\n\t\t\t**********************");
    printf("\n\nEnter First Name:");
    scanf("%s",first);
    printf("\nEnter Last Name:");
    scanf("%s",last);
    printf("\nEnter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&day,&month,&year);
    printf("\nEnter Age:");
    scanf("%d",&applyage);
    if(applyage>=18)
    {
        printf("\nEnter you Nationality:");
        fflush(stdin);
        gets(nation);
            if(strcmp(nation,a)==0)
                {
                    Vid=fopen("Voterid.txt","a+");
                    printf("\n\tEnter Your Voter ID:");
                    scanf("%d",&voter);
                    printf("\nWe are scanning your Voter ID");
                    fordelay(10000000000);
                    searchid1(voter);
                    printf("\n\nEnter your  Father's\/Mother's\/Husband's First NAME:");
                    scanf("%s",fname);
                    printf("\nEnter your permanent Address:");
                    fflush(stdin);
                    scanf("%s",address);
                    printf("\nEnter Pincode:");
                    fflush(stdin);
                    scanf("%d",&pincode);
                    fprintf(Vid,"%d   %s       %s       %d  %d\\%d\\%d\n",voter,first,last,applyage,day,month,year,address);
                    fclose(Vid);
                    printf("\n\nYOU HAVE SUCCESSFULLY REGISTERED.");
                    printf("\tREMEMBER YOUR VOTER ID");
                    x=fopen("Registered.txt","a");
                    fprintf(x,"%d\n",voter);
                    fclose(x);
                    fordelay(10000000000);
                    system("cls");
                    main();
                }
            else if(strcmp(nation,b)==0)
                {
                    Vid=fopen("Voterid.txt","a");
                    printf("\n\tEnter Your Voter ID:");
                    scanf("%d",&voter);
                    printf("\nWe are scanning your Voter ID");
                    fordelay(100000000000);
                    searchid1(voter);

                    printf("\n\nEnter your  Father's\/Mother's\/Husband's NAME:");
                    scanf("%s",fname);
                    printf("\nEnter your permanent Address:");
                    scanf("%s",address);
                    printf("\nEnter Pincode:");
                    fflush(stdin);
                    scanf("%d",&pincode);
                    fprintf(Vid,"%d   %s       %s       %d  %d\\%d\\%d\n",voter,first,last,applyage,day,month,year,address);
                    fclose(Vid);
                    printf("\n\nYOU HAVE SUCCESSFULLY REGISTERED.");
                    printf("\nREMEMBER YOUR VOTER ID");
                    x=fopen("Registered.txt","a");
                    fprintf(x,"%d\n",voter);
                    fclose(x);
                    fordelay(10000000000);
                    system("cls");
                    main();
                }
            else
                {
                    fordelay(1000000000);
                    printf("\nYou are not an Indian.\n\nYOU CANNOT VOTE.");
                }
    }
    else
    {
        printf("\nYour Age should be greater than or equal to 18.\n\nYOU CANNOT VOTE.");
    }
}

void voting()
{
        int n=0;
        printf("\n\nEnter the total no. of voters:");
        scanf("%d",&n);
        system("cls");
        welcome(n);
getch();
}

void welcome(int n)
{
    FILE *VOTED;
    int age[100],i=0,x,id[100],choice,ex=0,j=0;
    while(i<n)
    {
        printf("\n\t\t\t***********************");
        printf("\n\t\t\t* WELCOME TO ELECTION *");
        printf("\n\t\t\t***********************");
        fordelay(300000000);
        printf("\n\nWe are checking if you are eligible to vote or not.");
        fordelay(900000000);

                    VOTED=fopen("Voted.txt","a");
                    printf("\n\nEnter Your Voter ID:");
                    fflush(stdin);
                    scanf("%d",&id[i]);
                    fprintf(VOTED,"%d\n",id[i]);
                    printf("\nWe are scanning your Voter ID");
                    for(j=0;j<=7;j++)
                    {
                        fordelay(200000000);
                        printf(".");
                    }
                    fordelay(100000000);
                    votedcheck(id[i]);
                    searchid(id[i]);
                    fclose(VOTED);

                    fordelay(100000000);
                    printf("\n\nNext person please.");
                    fordelay(100000000000);
                    system("cls");
                    i++;
    }

        fordelay(10000000000);
        printf("Its time for RESULT");
        fordelay(100000000000);
        winner();
        fordelay(10000000);
again:
        printf("\n\nPress 1 for EXIT");
        printf("\nPress 2 to see which party has got how much VOTE");
        printf("\nPress 3 to see the list of VOTERS.");
        printf("\n\nGIVE YOUR CHOICE:");
        scanf("%d",&ex);
        if(ex==1)
        {
            exit(0);
        }
        else if(ex==2)
        {
            result();
            goto again;
        }
        else if(ex==3)
        {
            viewlist();
        }
        else
        {
            printf("\n\nI guess you have not read statement clearly");
            goto again;
        }
}

void votedcheck(int id)
{
    FILE *ap;

    ap=fopen("Voted.txt","r");
        while(fscanf(ap,"%d",&check.id)!=EOF)
        {
            if(id==check.id)
                {
                    printf("\n\nYou have already VOTED.");
                    exit(0);
                    fclose(ap);
                }
        }

}

void searchid(int id)
{
    FILE *yp;
    int n;
    yp=fopen("Registered.txt","r");
    while(fscanf(yp,"%d",&check.id)!=EOF)
        {
            if(id==check.id)
                {
                    vote();
                    fclose(yp);
                }
        }
}

void elsesearch(int id)
{
        fordelay(1000000000);
        printf("\n\nYour Id is not Registered.");
        fordelay(1000000000);
        printf("\n\nYou cannot VOTE.");
        fordelay(1000000000);
        printf("\n\nNext Person Please.");
        fordelay(1000000000);
        system("cls");
        main();
}

void vote()
{
        int choice;
            fordelay(1000000000000);
            printf("\n\nNow you are eligible to give VOTE.");
            fordelay(1000000000);
            printf("\n\nParties who are standing for election:");
            fordelay(10000000);
            printf("\n\n**********************************************************************\n");
            printf("*\t\t\t\t\t\t\t\t     *\n*  BJP\t\tCONGRESS\t\tAAP\t\tNOTA\t     *\n");
            fordelay(100000);
            printf("*\t\t\t\t\t\t\t\t     *\n**********************************************************************");
            printf("\n*\t\t\t\t\t\t\t\t     *\n*\t  Press 1 to give vote to BJP\t\t\t\t     *");
            fordelay(100000);
            printf("\n*\t\t\t\t\t\t\t\t     *\n*\t  Press 2 to give vote to CONGRESS\t\t\t     *");
            fordelay(100000);
            printf("\n*\t\t\t\t\t\t\t\t     *\n*\t  Press 3 to give vote to AAP\t\t\t\t     *");
            fordelay(100000);
            printf("\n*\t\t\t\t\t\t\t\t     *\n*\t  Press 4 for NOTA\t\t\t\t\t     *\n");
            printf("*\t\t\t\t\t\t\t\t     *\n**********************************************************************");
            fordelay(1000000000);
            printf("\n\nGive your choice  ->");


                    switch(getch()-48)
                {
                    case 1:
                        {
                            bjp();
                            break;
                        }
                    case 2:
                        {
                            cong();
                            break;
                        }
                    case 3:
                        {
                            aap();
                            break;
                        }
                    case 4:
                        {
                            nota();
                            break;
                        }
                }

}

void bjp()
{
    fordelay(100000000);
    MessageBeep(MB_ICONINFORMATION);
    printf("\nYour vote has been registered to BJP.");
    fordelay(10000000000);
    count1++;
}


void cong()
{
    fordelay(100000000);
    MessageBeep(MB_ICONINFORMATION);
    printf("\nYour vote has been registered to CONGRESS.");
    fordelay(10000000000);
    count2++;
}

void aap()
{
    fordelay(100000000);
    MessageBeep(MB_ICONINFORMATION);
    printf("\nYour vote has been registered to AAP.");
    fordelay(10000000000);
    count3++;
}

void nota()
{
    fordelay(100000000);
    MessageBeep(MB_ICONINFORMATION);
    printf("\nYou have given registered to NOTA.");
    fordelay(10000000000);
    count4++;
}

void result()
{
    printf("\n\n\tPARTY\t VOTES");
    printf("\n\tBJP  \t %d",count1);
    printf("\n\tCON  \t %d",count2);
    printf("\n\tAAP  \t %d",count3);
    printf("\n\tNOTA \t %d",count4);
}

void winnerbjp()
{
    fordelay(100000000000);
    system("COLOR 9");
    printf("\n\n\t*****\t  **********\t*****\t\n\t*    *\t      *\t\t*    *\t\n\t*     *\t      *\t\t*     *\t\n\t*    *\t      *\t\t*    *\t\n\t* * *\t      *\t\t* * *\n\t*    *    *   *\t\t*\n\t*     *   *   *\t\t*\n\t*    *     *  *\t\t*\n\t* * *\t     **\t\t*");
    fordelay(100000000000);
}

void winnercon()
{
    fordelay(100000000000);
    system("COLOR 9");
    printf("\n\n\t  ***\t  ***\t  *      *\n\t *\t *   *\t  **     *\n\t*\t*     *\t  * *    *\n       *       *       *  *  *   *\n       *       *       *  *   *  *\n\t*\t*     *\t  *    * *\n\t *\t *   *\t  *     **\n\t  ***\t  ***\t  *      *\n");
    fordelay(100000000000);
}

void winneraap()
{
    fordelay(100000000000);
    system("COLOR 9");
    printf("\n\n\t\t*\t\t*\t *****\t\n\t       * *\t       * *\t *    *\t\n\t      *   *\t      *   *\t *     *\t\n\t     *     *\t     *     *\t *    *\t\n\t    * * * * *\t    * * * * *\t * * *\n\t   *\t     *\t   *\t     *\t *\n\t  *\t      *\t  *\t      *\t *\n\t *\t       * *\t       * *");
    fordelay(100000000000);
}

void winnernota()
{
    fordelay(10000000000);
    system("COLOR 9");
    printf("\n\n\t*      *      ***    ***********       *\n\t**     *     *   *\t  *\t      * *\n\t* *    *    *     *\t  *\t     *   *\n\t*  *   *   *       *\t  *\t    *     *\n\t*   *  *   *       *\t  *\t   * * * * *\n\t*    * *    *     *\t  *\t  *\t    *\n\t*     **     *   *\t  *\t *\t     *\n\t*      *      ***\t  *\t*\t      *");
    fordelay(10000000000);
}


void winner()
{
    if(count1>count2)
        {
            if(count1>count3)
                {
                    if(count1>count4)
                        {
                            printf("\n\nWinner has %d VOTES",count1);
                            fordelay(1000000000);
                            system("cls");
                            winnerbjp();
                            system("cls");
                            system("COLOR 8");
                        }
                    else
                        {
                            printf("\n\nWinner has %d VOTES",count4);
                            fordelay(1000000000);
                            system("cls");
                            winnernota();
                            system("cls");
                            system("COLOR 8");
                        }
                }
            else
                {
                    if(count3>count4)
                        {
                            printf("\n\nWinner has %d VOTES",count3);
                            fordelay(1000000000);
                            system("cls");
                            winneraap();
                            system("cls");
                            system("COLOR 8");
                        }
                    else
                        {
                            printf("\n\nWinner has %d VOTES",count4);
                            fordelay(1000000000);
                            system("cls");
                            winnernota();
                            system("cls");
                            system("COLOR 8");
                        }
                }
        }
    else
        {
            if(count2>count3)
                {
                    if(count2>count4)
                        {
                            printf("\n\nWinner has %d VOTES",count2);
                            fordelay(1000000000);
                            system("cls");
                            winnercon();
                            system("cls");
                            system("COLOR 8");
                        }
                    else
                        {
                            printf("\n\nWinner has %d VOTES",count4);
                            fordelay(1000000000);
                            system("cls");
                            winnernota();
                            system("cls");
                            system("COLOR 8");
                        }

                }
            else
                {
                    if(count3>count4)
                        {
                            printf("\n\nWinner has %d VOTES",count3);
                            fordelay(1000000000);
                            system("cls");
                            winneraap();
                            system("cls");
                            system("COLOR 8");
                        }
                    else
                        {
                            printf("\n\nWinner has %d VOTES",count4);
                            fordelay(1000000000);
                            system("cls");
                            winnernota();
                            system("cls");
                            system("COLOR 8");
                        }
                }
        }

}


void viewlist(void)
{
    FILE *view;
    char address[30],first[10],last[10];
    int applyage=0,voter=0,day,month,year;

    view=fopen("Voterid.txt","r");
    system("cls");
    printf("Voter ID\tFirst Name\tLast Name\tAge\tDOB");
    while(fscanf(view,"%d   %s       %s       %d  %d\\%d\\%d\n",&voter,first,last,&applyage,&day,&month,&year,address)!=EOF)
    {
        printf("\n\n%d\t%s\t\t%s\t\t%d\t%d\\%d\\%d\n",voter,first,last,applyage,day,month,year,address);
        return 0;
    }
    fclose(view);
}


void main()
{
    int num=0;
again:
    printf("\n1.Press 1 for REGISTRATION.");
    printf("\n\n2.Press 2 to VOTE.(IF ALREADY REGISTERED)");
    printf("\n\n\nGIVE YOUR CHOICE:");
    scanf("%d",&num);
    system("cls");
    if(num==1)
    {
        apply();
    }
    else if(num==2)
    {
        voting();
    }
    else
    {
        printf("\nThere is no %d for option",num);
    }
    fordelay(600000000);
    system("cls");
    goto again;
getch();
}
