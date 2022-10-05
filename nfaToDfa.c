#include<stdio.h>
#include<stdlib.h>
struct node{
 int st;
 struct node *link;
};
struct node1{
 int nst[20];
};

void insert(int ,char, int,FILE *);
void resetValues();
int findalpha(char);
void findfinalstate(FILE *);
void printDeadState(struct node1 state,FILE *);
int insertdfastate(struct node1);
int compare(struct node1,struct node1);
void printnewstate(struct node1,FILE *);
static int set[20],nostate,noalpha,s,notransition,nofinal,start,finalstate[20],c,r,buffer[20];
static struct node1 deadState;
int complete=-1;
char alphabet[20];
static int eclosure[20][20]={0};
struct node1 hash[20],hash1[20];
struct node * transition[20][20]={NULL};
int main(){

  int i,j,m,l;//,k,t,n
//  struct node *temp;
//  struct node1 newstate={0},tmpstate={0};
  FILE *fp= fopen("input2.txt","r"),*ofp;
  ofp = fopen("output.txt","w");
    int test=0,t1=0;
    char line[100];
    if(fp == NULL){
        printf("\nfile cannot be opened :(... EXITING\n");
        return -1;
    }
    fgets(line,10,fp);
    printf("\n test= %d\n",(test=line[0]-48) );
    while (++t1<=test){
        // int i,j,k,m,t,n,l;
        struct node *temp;
        struct node1 newstate={0},tmpstate={0};
        // ofp = fopen("output.txt","a");
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
      noalpha = alplha[0] -48;
//  printf("\nEnter No of alphabets and alphabets? = %d \n",noalpha );
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
          insert(r,c,s,ofp);
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
        // fprintf(ofp,"Trnsitions of DFA with %d states",nostate+1);
        newstate.nst[start]=start;
        insertdfastate(newstate);
        int deadFlag=0;
        while(i!=complete){
          i++;
          newstate=hash[i];
          for(k=0;k<noalpha;k++){
            c=0;
            for(j=1;j<=nostate;j++)
              set[j]=0;
            for(j=1;j<=nostate;j++){
              l=newstate.nst[j];
              if(l!=0){
                temp=transition[l][k];
                while(temp!=NULL){
                  if(set[temp->st]==0){
                    c++;
                    set[temp->st]=temp->st;
                  }
                  temp=temp->link;
                }
              }
            }
            printf("\n");
            if(c!=0){
              for(m=1;m<=nostate;m++)
              tmpstate.nst[m]=set[m];
              insertdfastate(tmpstate);
              printnewstate(newstate,ofp);
              fprintf(ofp,"%c\t",alphabet[k]);
              printf("%c\t",alphabet[k]);
              printnewstate(tmpstate,ofp);
              fprintf(ofp,"\n");
              printf("\n");
            }else{
              // insertdfastate(deadState); // edited to handle dead state
              printnewstate(newstate,ofp);
              fprintf(ofp,"%c\t", alphabet[k]);
              printf("%c\t", alphabet[k]);
              // printnewstate(newstate);
              fprintf(ofp,"DEAD\n");
              printf("DEAD\n");
              deadFlag =1;
            }
          }
        }
        if(deadFlag){
          for(int k = 0 ; k<noalpha;k++){
            fprintf(ofp,"\n");
            printf("\n");
            deadState.nst[0]='$';
            printDeadState(deadState,ofp);
            insertdfastate(deadState);
            fprintf(ofp,"%c\t", alphabet[k]);
            printf("%c\t", alphabet[k]);
            printDeadState(deadState,ofp);
          }
        }
        fprintf(ofp,"\nStates of DFA:\n");
        printf("\nStates of DFA:\n");
        for(i=0;i<=complete;i++){
          if(hash[i].nst[0]=='$'){
            fprintf(ofp,"\t{DEAD}");
            printf("\t{DEAD}");
          }else{
            printnewstate(hash[i],ofp); 
          }
        }
        fprintf(ofp,"\n Alphabets:\n");   
        printf("\n Alphabets:\n");
        for(i=0;i<noalpha;i++){
          fprintf(ofp,"%c\t",alphabet[i]);
          printf("%c\t",alphabet[i]);
        }
        fprintf(ofp,"\n Start State: \n q%d",start);
        printf("\n Start State:\n");
        printf("q%d",start);
        fprintf(ofp,"\nFinal states:\n");
        printf("\nFinal states:\n");
        findfinalstate(ofp);
        printf("\n");
        fprintf(ofp,"\n------Test %d completed-----\n\n",t1);
        printf("\n------Test %d completed-----\n",t1);
        resetValues();
        i=0,j=0,k=0,m=0,l=0; // t=0,n=0,
        // temp = NULL;
        // struct node1 reset;
        // newstate=reset,tmpstate=reset;
    }
    fclose(fp);
    fclose(ofp);
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

void insert(int r,char c,int s,FILE *fp){
  int j;
  struct node *temp;
  j=findalpha(c);
  if(j==999){
    fprintf(fp,"ERROR\n");
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


void findfinalstate(FILE *fp){
 int i,j,k,t;
  for(i=0;i<=complete;i++){
      for(j=1;j<=nostate;j++){
        for(k=0;k<nofinal;k++){
          if(hash[i].nst[j]==finalstate[k]){
            printnewstate(hash[i],fp);
            fprintf(fp,"\t");
            printf("\t");
            j=nostate;
            break;
        }
      }
    }
  }
}


void printnewstate(struct node1 state,FILE *fp){
  int j;
  fprintf(fp,"{");
  printf("{");
  for(j=1;j<=nostate;j++){
    if(state.nst[j]!=0){
      fprintf(fp,"q%d,",state.nst[j]);
      printf("q%d,",state.nst[j]);
    }
  }
  fprintf(fp,"}\t");
  printf("}\t");
}

void printDeadState(struct node1 state,FILE *fp){
  fprintf(fp,"DEAD\t");
  printf("DEAD\t");
}
void resetValues(){
  struct node1 temp1;//=(struct node1) NULL;
  set[20],nostate=0,noalpha=0,s=0,notransition=0,nofinal=0,start=0;
  finalstate[20],c=0,r=0,buffer[20];
  complete =-1;
  deadState = temp1;
  // *hash = hash1;
  eclosure[20][20]=0;
  // transition[20][20] = (struct node*) 0;//{NULL};
  for(int i=0;i<20;i++)
    for(int j = 0;j<20;j++){
      transition[i][j]=NULL;
      // hash[i].nst[j] = 0;
    } 

  for (int i; i<20;i++){
    set[i] = finalstate[i]=buffer[i] =0;
    // hash[i] =0;
    hash[i] = hash1[i];
  }
}