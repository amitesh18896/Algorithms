# include <stdio.h>
# include <stdlib.h>
typedef struct adjnode{
    int value;
    struct adjnode *next;
}adjnode;
typedef struct adjarray{
    struct adjnode *head;
}adjarray;
typedef struct graph{
    int v;
    adjarray *array; 
}graph;
typedef struct queue_node{
    int data;
    struct queue_node *next;
}queue_node;
graph *creategraph(int V){
    graph * G;
    G = (graph *) calloc(1,sizeof(graph));
    G->v = V;
    G->array = (adjarray *) calloc(V,sizeof(adjarray));
    for (int i = 0; i < G->v;++i){
        G->array[i].head = (adjnode *)calloc(1,sizeof(adjnode));
    }
    return G;
}
int in_dex (graph *G,int data){
    for (int  i = 0; i < G->v ; ++i){
        if (G->array[i].head->value ==  data)
            return i;
    }
    return G->v;
}
void addnode(graph *G, int src,int dest){
    int x = in_dex(G,src);
    int y = in_dex(G,dest);
    adjnode * crawl = G->array[x].head;
    while(crawl->next){
        crawl = crawl->next;
    }
    crawl->next = (adjnode *) calloc(1,sizeof(adjnode)); 
    crawl->next->value = dest;    
}
void print(graph *G){
    for (int i = 0; i < G->v ;++i){
        adjnode *crawl = G->array[i].head;
        printf("%d--->",crawl->value);
        while(crawl->next){
            printf("%d --->",crawl->next->value);
            crawl = crawl->next;
        }
        printf("\n");
    }
}
void createheadnodes(graph *G,int arr[10]){
    for (int i = 0 ;i < G->v;++i){
        G->array[i].head->value = arr[i];
    }
}
queue_node * enqueue(queue_node * front,int n){
    queue_node * temp = (queue_node *)malloc(sizeof(queue_node));
    temp->data = n;
    temp->next = NULL;
    if (front  == NULL){
        front = temp;
        return front;
    }
    queue_node* p = front;
    while(p->next){
        p = p->next;
    }
    p->next = temp;
    return front;
}
queue_node * dequeue (queue_node *front){
    queue_node * p = front;
    if (front == NULL)
        return front;
    queue_node * temp = front;
    front = front->next;
    free(temp);
    return front;
} 
void dfsgraph(graph * G,int visited_array[][2],int V,int i){
    int index = in_dex(G,i);
    int in; // for reference inside the visited_array
    for (int j = 0; j < V;++j){
        if (visited_array[j][0] == i){
            in = j;
            if (visited_array[j][1] == 1){
                return;
            }
        }
    }
    printf("%d ",i);
    visited_array[in][1] = 1;
    adjnode * temp = G->array[index].head->next;
    while (temp){
        dfsgraph(G,visited_array,V,temp->value);
        temp = temp->next;
    }
}
void bfsgraph (graph *G,int visited_array[][2],int V,queue_node *front){
    //printf("error");
    int i = G->array[0].head->value;
    front = enqueue(front,i);
    //printf("error");
    for (int j = 0 ;j < V; ++j){
        if (visited_array[j][0] == i){
            visited_array[j][1] = 1;
        }
    }
    while (front != NULL){
        int index = in_dex(G,front->data);
        adjnode * p = G->array[index].head->next;
        while (p){
            int visited = p->value;
            for (int k = 0; k < V; ++k){
                if (visited == visited_array[k][0] && visited_array[k][1] == 0)
                {    
                    visited_array[k][1] = 1;
                    front = enqueue(front,visited);
                    break;
                }
            }
            p = p->next;           
        }
        printf("%d ",front->data);
        front = dequeue(front);
    }
}
int main(){
    int V = 6;
    graph * G = creategraph(V); // No of vertices
    int arr[6] = {10,9,6,5,8,1};
    createheadnodes(G,arr);
    addnode(G,10,9);
    addnode(G,10,6);
    addnode(G,9,5);
    addnode(G,9,8);
    addnode(G,6,8);
    addnode(G,5,8);
    addnode(G,8,6);
    addnode(G,6,10);
    addnode(G,5,1);
    addnode(G,1,8);
    //print(G);
    int visited_array[V][2] ;
    for (int i = 0 ; i < V; ++i){
        visited_array[i][0] = arr[i];
        visited_array[i][1] = 0;
    }
    //dfsgraph(G,visited_array,V,10);
    queue_node * front = NULL;
    //front = enqueue(front,10);
    //printf("%d ",front->data);
    //front = dequeue(front);

    bfsgraph(G,visited_array,V,front); 
}