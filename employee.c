#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

#define MAX 100 

typedef struct Employee { 
  char fname[50];  
  char lname[50]; 
  int empID; 
  float salary; 
  int phoneno; 
  struct Employee *next;
}node; 

node *create(int n){     //creating a database
  int i; 
  node *head,*p; 
  head=NULL; 
  p=NULL; 
  head=(node*)malloc(sizeof(node));     //creating head node 
  printf("\nENTER THE FIRST NAME OF THE EMPLOYEE:\t"); 
  scanf("%s",head->fname); 
  printf("\nENTER THE LAST NAME OF THE EMPLOYEE:\t"); 
  scanf("%s",head->lname); 
  printf("\nENTER EMPLOYEE ID:\t"); 
  scanf("%d",&head->empID); 
  printf("\nENTER EMPLOYEE SALARY:\t"); 
  scanf("%f",&head->salary);  
  printf("\nENTER CONTACT NUMBER OF AN EMPLOYEE:\t"); 
  scanf("%d",&head->phoneno); 
  head->next=NULL; 
  p=head; 
  for(i=1;i<n;i++){ 
    p->next=(node*)malloc(sizeof(node));         //creating other nodes p=p->next; 
    p->next=NULL; 
    printf("\nENTER THE FIRST NAME OF THE EMPLOYEE:\t"); 
    scanf("%s",p->fname);
    printf("\nENTER THE LAST NAME OF THE EMPLOYEE:\t"); 
    scanf("%s",p->lname); 
    printf("\nENTER EMPLOYEE ID:\t"); 
    scanf("%d",&p->empID); 
    printf("\nENTER EMPLOYEE SALARY:\t"); 
    scanf("%f",&p->salary); 
    printf("\nENTER CONTACT NUMBER OF AN EMPLOYEE:\t"); 
    scanf("%d",&p->phoneno); 
    }
  return (head); 
  } 
  
void display(node *head){       //displaying list of records
  node *temp; 
  if(head==NULL) 
    printf("\nNO DATABASE IS PRESENT\n"); 
  else{ 
    temp=head; 
    printf("database contents:\n\n"); 
    while(temp!=NULL){ 
      printf("\n\n1.FIRST NAME: %s\n",temp->fname); 
      printf("2.LAST NAME: %s\n",temp->lname); 
      printf("3.EMPLOYEE ID: %d\n",temp->empID); 
      printf("4.EMPLOYEE SALARY: %f\n",temp->salary); 
      printf("5.CONTACT NO: %d\n",temp->phoneno); 
      temp=temp->next;
      } 
    } 
} 

int Insertafter(node *head){         //inserting new record
  int keyID; 
  int flag=0; 
  printf("ENTER THE ID YOU WANT TO INSERT AFTER THAT:\t"); 
  scanf("%d",&keyID); 
  node *temp,*p; 
  p=(node*)malloc(sizeof(node)); 
  printf("\nENTER THE FIRST NAME OF THE EMPLOYEE:\t"); 
  scanf("%s",p->fname); 
  printf("\nENTER THE LAST NAME OF THE EMPLOYEE:\t"); 
  scanf("%s",p->lname); 
  printf("\nENTER EMPLOYEE ID:\t"); 
  scanf("%d",&p->empID); 
  printf("\nENTER EMPLOYEE SALARY:\t"); 
  scanf("%f",&p->salary); 
  printf("\nENTER CONTACT NUMBER OF AN EMPLOYEE:\t"); 
  scanf("%d",&p->phoneno); 
  p->next=NULL;  
  if(head==NULL) 
    head=p; 
  else{ 
    temp=head; 
    while(temp!=NULL&&temp->empID!=keyID) 
    temp=temp->next; 
    if(temp->empID==keyID){ 
      p->next=temp->next; 
      temp->next=p; 
      flag=1;
    } 
  } 
  if(flag==0) 
    printf("empID NOT FOUND"); 
  return flag;
}

node * delete(node *head){             //deleting any record from the database
  node *temp,*ptr; 
  int keyID; 
  printf("ENTER THE EMPLOYEE ID YOU WANT TO DELETE:\t"); 
  scanf("%d",&keyID); 
  if(head!=NULL){ 
  if(head->next!=NULL){ 
    if(keyID==head->empID){             //if it is first node to be deleted  
      temp=head; 
      head=head->next; 
      free(temp); 
      printf("\nDATA IS SUCESSFULLY DELETED\n");
    } 
    else{                      //if it is any node other than the first node 
      ptr=head->next; 
      while(ptr!=NULL&&ptr->empID!=keyID){ 
        temp=ptr; ptr=ptr->next; 
      } 
      if(ptr->empID==keyID) { 
        temp->next=ptr->next; 
        free(ptr); 
        printf("\n\nDATA IS SUCESSFULLY DELETED\n"); 
      } 
    }
  } 
  else if(head==NULL) 
    printf("\nNO DATBASE IS PRESENT");
    else 
      printf("\n\nEMPLOYEE ID IS NOT FOUND");
  } 
  return (head);
}

void search(node*head ){           //searching any record from the database 
  node *temp; 
  temp=head; 
  int keyID; 
  printf("\nENTER THE EMPLOYEE ID YOU WANT TO SEARCH:\t"); 
  scanf("%d",&keyID); 
  while(temp!=NULL&&temp->empID!=keyID) 
    temp=temp->next; 
  if(temp->empID==keyID) { 
    printf("\n\nID IS FOUND IN THE LIST\n\nFIRST NAME OF EMPLOYEE:\t%s",temp->fname); 
    printf("\nLAST NAME :\t%s",temp->lname); 
    printf("\nEMPLOYEE ID:\t%d",temp->empID); 
    printf("\nSALARY:\t%f",temp->salary); 
    printf("\nCONTACT NO:\t%d",temp->phoneno); 
  } 
  else 
    printf("\n\nEMPLOYEE ID NOT FOUND"); 
}

int main() { 
  int n,choice,result; node *h; 
  h=NULL; 
  do {printf("\n-----------------------MENU-------------------------\n");          //displaying menu 
    printf("\tPRESS\n"); printf("\t1 * CREATING A DATABASE\n"); 
    printf("\t2 * DISPLAYING YOUR RECORD\n"); 
    printf("\t3 * INSERTING A RECORD AFTER AN ANOTHER RECORD\n"); 
    printf("\t4 * DELETING ANY RECORD FROM THE DATABASE\n"); 
    printf("\t5 * SEARCH ANY RECORD\n"); 
    printf("\t0 * exit\n"); 
    printf("\nENTER YOUR CHOICE\n");                     //taking users choice 
    scanf("%d",&choice); 
    switch(choice) { 
      case 1:printf("\nENTER THE MAXIMUM SIZE OF YOUR DATABASE\n"); 
            scanf("%d",&n); 
            h=create(n); 
            break; 
      case 2:display(h); 
            break; 
      case 3:result=Insertafter(h); 
             if (result==1) 
              printf("\n\nDATA SUCESSFULLY INSERTED"); 
             else 
              printf("\n\nDATA IS NOT INSERTED"); 
             break; 
      case 4:h=delete(h); 
             break; 
      case 5:search(h); 
             break; 
      case 0:exit(0); 
             break; 
      }
    } while(1);
  return 0; 
} 
