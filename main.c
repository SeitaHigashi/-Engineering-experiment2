#include <stdio.h>

typedef struct queue_struct{
    int* data;
    struct queue_struct *next;
} Queue;

void init_queue(Queue* head){
    Queue *ptr,*tmp;
    while(head->next!=NULL){
        tmp=head->next;
        ptr=tmp->next;
        free(tmp);
    }
    head->next=NULL;
    head->data=NULL;
}

void enqueue(Queue *head,Queue *p){
    Queue *ptr;
    ptr=(Queue*)(head->data);
    ptr->next=p;
    p->next=NULL;
    head->data=(int*)p;
}

Queue *make_node(int data)
{
	Queue *p;
    int *i;

	p=(Queue*)calloc(1,sizeof(Queue));
	if(p==NULL){
		fprintf(stderr,"memory alloc error!\n");
		exit(1);
	}
    i=(int*)calloc(1,sizeof(int));
    *i=data;
	p->data=i;	
	p->next=NULL;

	return p;
}

Queue *dequeue(Queue* head){
    Queue *ptr;
    ptr=head->next;
    if(ptr==NULL) return ptr;
    head->next=ptr->next;
    if(head->next==NULL)head->data=(int*)head;
    return ptr;
}

Queue show_head(const Queue *head){
    return *(head->next);
}

int length_queue(const Queue *head){
    Queue *ptr;
    int cnt=0;
    ptr=head->next;
    while(ptr!=NULL){
        cnt++;
        ptr=ptr->next;
    }
    return cnt;
}

void print_queue(Queue *head)
{
    Queue *ptr;

    ptr=head->next;
    printf("Queue: ");
    while(ptr!=NULL){
        printf("[%d]",*(ptr->data));
        ptr=ptr->next;
    }
    printf("\n");
}

int command(void){
    int i=4;
    do{
        printf("1:enqueue 2:dequeue 3:show    4:init    5:length  0:end\n");
       scanf("%d",&i);
    }while(i<0 || 5<i);
return i;
}

void main(void)
{
    Queue head={NULL,NULL},*tmp;
    int com,data;

    init_queue(&head);

    while(com=command()){
        switch(com){
            case 1:
                printf("New Data:");
                scanf("%d",&data);
                tmp=make_node(data);
                enqueue(&head,tmp);
                break;
            case 2:
				tmp=dequeue(&head);
				if(tmp==NULL){
					printf("Queue is empty\n");
				}else{
					printf("Dequeued data is %d\n",tmp->data);
					free(tmp);
				}
				break;
			case 3:
				print_queue(&head);
				break;
			case 4:
				init_queue(&head);
				break;
			case 5:
				printf("Queue lenght is %d\n",length_queue(&head));
				break;
			default:
				break;
		}
	}
}
