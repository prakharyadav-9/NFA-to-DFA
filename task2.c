#include<stdio.h>
#include<stdlib.h>
struct node{
 int st;
 struct node *link;
};
struct node1{
 int nst[20];
};

void insert(int ,char, int);
int findalpha(char);
void findfinalstate(void);
int insertdfastate(struct node1);
int compare(struct node1,struct node1);
void printnewstate(struct node1);
static int set[20],nostate,noalpha,s,notransition,nofinal,start,finalstate[20],c,r,buffer[20];
int complete=-1;
char alphabet[20];
static int eclosure[20][20]={0};
struct node1 hash[20];
struct node * transition[20][20]={NULL};
int main(){
 int i,j,k,m,t,n,l;
 struct node *temp;
 struct node1 newstate={0},tmpstate={0};
 FILE *fp= fopen("input2.txt","r");
    int test=0;
    char line[100];
    if(fp == NULL){
        printf("\nfile cannot be opened :(... EXITING\n");
        return -1;
    }
    fgets(line,10,fp);
    // while ((ch =fgetc(fp))!='\n'){
    //     if(ch > 48)
    //         printf("\n test = %d",test =ch-48);
    // }
    printf("\n test= %d\n",(test=line[0]-48) );
    while (test--){
        fgets(line,10,fp);
        int alplha[28],sNo=0,startState=0,fNo=0,finalStates[20],tran,transitions[400];
        char ch;
        // printf("\ninput alphabets:: for test =%d",test);
        fgets(line,10,fp);
        // printf("Number of alphabets and alplabets = ");
        for(int i=0,j=0;line[i];i=i+2){
            alplha[j++] = line[i];
            // printf("%c",alplha[j-1]);
        }
        fgets(line,10,fp);
        (sNo = line[0] - 48);
        // printf("\n totalStateNumber:: %d",sNo);
        startState =1;
        fgets(line,10,fp);
        (fNo = line[0]-48);
        // printf("\n enter Number of final state:: %d",fNo);
        // printf("\n final states::\t");
        fgets(line,10,fp);
        for(int i=0,j=0;line[i];i=i+2){
            finalStates[j++] = line[i] - 48;
        }
        // for(int i=0,j=0;(ch = fgetc(fp)) != '\n';i=i+1){
        //     // ch = fgetc(fp);
        //     if(ch != ' '){
        //         finalStates[j++] = ch - 48;
        //     }
        // }
        // for(int i=0;i<fNo;i++){
        //     printf("%d ,",finalStates[i]);
        // }
        (tran = (fgetc(fp)-48));
        // printf("\n Transitions:: %d",tran);
        fgets(line,10,fp);
        int k=0;
        for(int i=0;i<tran ; i++){
            fgets(line,10,fp);
            // printf("\nline from file:: %s\n",line);
            for(int j=0;line[j];j=j+2){
                transitions[k++]= j[line];
                // printf("%c ",j[line]);
            }
        }
        // printf("\n---> transitions\t");
        // for(int i=0;i<k;i++){
        //     if((i)%3==0) printf("\n");
        //     printf("%c ",transitions[i]);
        // }
        


//  printf("Enter the number of alphabets?\n");
//  printf("NOTE:- [ use letter e as epsilon]\n");
//  printf("NOTE:- [e must be last character ,if it is present]\n");
//  printf("\nEnter No of alphabets and alphabets? = %d \n",noalpha = alplha[0] -48);
//  scanf("%d",&noalpha);
// printf("No of");
//  getchar();
      for(i=1;i<=noalpha;i++){
          alphabet[i-1]=alplha[i];//getchar();
          // printf("%c .",alphabet[i]);
          // getchar();
      }
//  printf("Enter the number of states?\n");
      nostate = sNo; //  scanf("%d",&nostate);
//  printf("Enter the start state?\n");
      start = startState;//  scanf("%d",&start);
//  printf("Enter the number of final states?\n");
      nofinal = fNo;//scanf("%d",&nofinal);
//  printf("Enter the final states?\n");
      for(i=0;i<nofinal;i++){
        finalstate[i] = finalStates[i];
          // scanf("%d",&finalstate[i]);
      }
//  printf("Enter no of transition?\n");

      notransition = tran;//  scanf("%d",&notransition);
//  printf("NOTE:- [%d Transition is in the form–> qno alphabet qno]\n",notransition);
//  printf("NOTE:- [States number must be greater than zero]\n");
//  printf("\nEnter transition?\n");


      for(i=0;i<notransition;i++){
        // for(int j=i*3;j<i+3;j+=3){
          printf("\n r = %d",r=transitions[i*3] - 48);//transitions[j];
          printf(" c=%c",c = transitions[i*3 + 1]);//transitions[j+1];
          printf(" s= %d \n",s = transitions[i*3 +2] -48);//transitions[j+2];
          insert(r,c,s);
        // }
        // scanf("%d %c%d",&r,&c,&s);
        // insert(r,c,s);
      }
        for(i=0;i<20;i++){
          for(j=0;j<20;j++)
            hash[i].nst[j]=0;
        }
        complete=-1;
        i=-1;
        printf("\nEquivalent DFA.....\n");
        printf(".......................\n");
        
        printf("Trnsitions of DFA\n");

        newstate.nst[start]=start;
        insertdfastate(newstate);
        while(i!=complete)
        {
          i++;
          newstate=hash[i];
          for(k=0;k<noalpha;k++)
          {
          c=0;
          for(j=1;j<=nostate;j++)
          set[j]=0;
          for(j=1;j<=nostate;j++)
          {
            l=newstate.nst[j];
            if(l!=0)
            {
            temp=transition[l][k];
            while(temp!=NULL)
            {
              if(set[temp->st]==0)
              {
              c++;
              set[temp->st]=temp->st;
              }
              temp=temp->link;
            }
            }
          }
          printf("\n");
          if(c!=0)
          {
            for(m=1;m<=nostate;m++)
            tmpstate.nst[m]=set[m];

            insertdfastate(tmpstate);

            printnewstate(newstate);
            printf("%c\t",alphabet[k]);
            printnewstate(tmpstate);
            printf("\n");
            }
            else
            {
            printnewstate(newstate);
            printf("%c\t", alphabet[k]);
            printf("NULL\n");
            }

          }
          }
        printf("\nStates of DFA:\n");
        for(i=0;i<=complete;i++)
        printnewstate(hash[i]);  
        printf("\n Alphabets:\n");
        for(i=0;i<noalpha;i++)
        printf("%c\t",alphabet[i]);
        printf("\n Start State:\n");
          printf("q%d",start);
        printf("\nFinal states:\n");
        findfinalstate();
        printf("\n");
        printf("\n------Test %d completed-----\n",test+1);
    }
}

int insertdfastate(struct node1 newstate){
 int i;
 for(i=0;i<=complete;i++){
  if(compare(hash[i],newstate))
   return 0;
 }
 complete++;
 hash[complete]=newstate;
 return 1;
}
int compare(struct node1 a,struct node1 b){
 int i;
  for(i=1;i<=nostate;i++){
   if(a.nst[i]!=b.nst[i])
    return 0;
  }
  return 1;
}

void insert(int r,char c,int s){
       int j;
       struct node *temp;
       j=findalpha(c);
       if(j==999)
       {
         printf("error\n");
        exit(0);
       }
       temp=(struct node *) malloc(sizeof(struct node));
       temp->st=s;
       temp->link=transition[r][j];
       transition[r][j]=temp;
}

int findalpha(char c){
 int i;
 for(i=0;i<noalpha;i++)
 if(alphabet[i]==c)
  return i;

  return(999);
}


void findfinalstate(){
 int i,j,k,t;
  for(i=0;i<=complete;i++)
  {
  for(j=1;j<=nostate;j++)
  {
   for(k=0;k<nofinal;k++)
   {
    if(hash[i].nst[j]==finalstate[k])
    {
     printnewstate(hash[i]);
     printf("\t");
     j=nostate;
     break;
    }
   }
  }
  }
}


void printnewstate(struct node1 state)
{
 int j;
 printf("{");
  for(j=1;j<=nostate;j++)
  {
   if(state.nst[j]!=0)
    printf("q%d,",state.nst[j]);
  }
  printf("}\t");

}
