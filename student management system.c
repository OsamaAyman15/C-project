#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
	int id;
	char name[50];
	int age;
	float gpa;
};
struct node{
	struct student data;
	struct node *next;
};
 struct node *head=NULL;
 /*************** Functions Prototypes ***************/
 void addStudent(const struct student *const ptr);
 void displayStudents(void);
 void searchStudentByID(int id);
 void updateStudent(int id);
 float calculateAverageGPA(void);
 void searchHighestGPA(void);
 void deleteStudent(int id);
 /*************** Main Programs ***************/
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct student d;
	float ave;
	int operation,id;
	for(;;){                                /*infinite loop*/
		printf("1. Add Student\n");
		printf("2. Display Students\n");
		printf("3. Search Student by ID\n");
		printf("4. Update Student Information\n");
		printf("5. Delete Student\n");
		printf("6. Calculate Average GPA\n");
		printf("7. Search for Student With Highest GPA\n");
		printf("8. Exit\n");
		printf("enter choice: \n");
		scanf("%d",&operation);
		switch(operation){
		case 1:
			printf("Enter Name:\n");
			getchar();
			gets(d.name);
			printf("Enter Student ID:\n");
			scanf("%d",&d.id);
			printf("Enter Age:\n");
			scanf("%d",&d.age);
			printf("Enter GPA:\n");
			scanf("%f",&d.gpa);
			addStudent(&d);
			break;
		case 2:
			displayStudents();
			break;
		case 3:
			printf("Enter Student ID to search:\n");
			scanf("%d",&id);
			searchStudentByID(id);
			break;
		case 4:
			printf("Enter Student ID to Update it’s Information:\n");
			scanf("%d",&id);
			updateStudent(id);
			break;
		case 5:
			printf("Enter Student ID to Delete it’s Data:\n");
			scanf("%d",&id);
			deleteStudent(id);
			break;
		case 6:
			 ave=calculateAverageGPA();
			 printf("Average GPA = %.2f\n",ave);
			break;
		case 7:
			searchHighestGPA();
			break;
		case 8:
			printf("Exiting....\n");
			return 0;
		default:
			printf("You Did Not Choose Any Operations\n");
		}
	}
	return 0;
}
/*************** Functions Definitions ***************/
void addStudent(const struct student *const ptr){
	struct node *current=head;
	struct node *link=NULL;
	while(current!=NULL){
		if(current->data.id==ptr->id){
		printf("this ID is Already Reserved\n");
		return;
		}
		current=current->next;
	}
	link=(struct node*)malloc(sizeof(struct node));
	if(link==NULL){
		printf("Not Available Memory\n");
		return;
	}
	if(head==NULL){
		link->data=*ptr;
		link->next=NULL;
		head=link;
		printf("The Student Added Successfully\n");
		return;
	}
	current=head;
	while(current->next!=NULL){
		current=current->next;
	}
	link->data=*ptr;
	link->next=NULL;
	current->next=link;
	printf("The Student Added Successfully\n");
}
void displayStudents(void){
	struct node *current=head;
	if(current==NULL){
		printf("No Students are present\n");
		return;
	}
	while(current!=NULL){
		printf("Student Data:\n [ID:%d\t Name:%s\t Age:%d\t GPA:%.2f]\n",current->data.id,current->data.name,current->data.age,current->data.gpa);
		current=current->next;
	}
}
void searchStudentByID(int id){
	struct node *current=head;
		if(head==NULL){
		printf("No Students are present\n");
		return;
	}
	while(current!=NULL){
		if(current->data.id==id){
        printf("Student Found:\n [ID:%d\t Name:%s\t Age:%d\t GPA:%.2f]\n",current->data.id,current->data.name,current->data.age,current->data.gpa);
		return;
		}
		current=current->next;
	}
		printf("Student with ID %d Not Found\n",id);
}
void updateStudent(int id){
	struct node *current=head;
		if(head==NULL){
		printf("No Students are present\n");
		return;
	}
		while(current!=NULL){
			if(current->data.id==id){
			printf("Enter New Details for the student with ID %d\n",id);
			printf("Enter New Name:\n");
			getchar();
			gets(current->data.name);
			printf("Enter New Age:\n");
			scanf("%d",&current->data.age);
			printf("Enter New GPA:\n");
			scanf("%f",&current->data.gpa);
			return;
			}
			current=current->next;
		}
		printf("Student with ID %d Not Found\n",id);
}
float calculateAverageGPA(void){
	float sum=0;
	int count=0;
	struct node *current=head;
		if(head==NULL){
		printf("No Students are present\n");
		return 0.0;
	}
		while(current!=NULL){
			count++;
			sum+=current->data.gpa;
			current=current->next;
		}
    	return sum/count;
}
void searchHighestGPA(void){
	struct node *current=head;
	struct student store;
	store.gpa=0;
			if(head==NULL){
			printf("No Students are present\n");
			return;
		}
			while(current!=NULL){
				if(store.gpa<=current->data.gpa){
					store.gpa=current->data.gpa;
					store.id=current->data.id;
					store.age=current->data.age;
					strcpy(store.name,current->data.name);
			}
				current=current->next;
		}
	printf("Student With The Highest GPA:\n [ID:%d\t Name:%s\t Age:%d\t GPA:%.2f]\n",store.id,store.name,store.age,store.gpa);
}
void deleteStudent(int id){
	struct node *current=NULL;
	struct node *prev=NULL;
	if(head==NULL){
			printf("No Students are present\n");
			return;
		}
	        if(head->data.id==id){
	        	current=head;
	        	head=head->next;
	        	free(current);
	        	return;
	        }
	        current=head->next;
	        prev=head;
	        while(current!=NULL){
	        	if(current->data.id==id){
	        		prev->next=current->next;
	        	   	free(current);
	        	   	printf("Student with ID %d deleted successfully\n",id);
	        	   	return;
	        	}
	        	current=current->next;
	        	prev=prev->next;
	        }
	        printf("student with ID %d not found\n",id);
}
