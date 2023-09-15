#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mx 50
#define inf 2147483647

struct process {
    char Name[mx];
    int at;
    int bt;
    int wt;
    int tt;
    int ft;
};

struct process* new_process(char* Name, int at, int bt, int wt, int ft, int tt) {
    struct process* pr = (struct process*)malloc(sizeof(struct process));
    strcpy(pr->Name, Name); // Copy the name into the allocated memory
    pr->at = at;
    pr->bt = bt;
    pr->ft = ft;
    pr->tt = tt;
    pr->wt = wt;
    return pr;
}

void print_process(int n, struct process* ar[]) {
    float awt = 0;
    float aft = 0;
    printf("----------------------------------------\n");
    printf("| process | at | bt | wt |  ft  |  tt  |\n");
    for (int i = 0; i < n; i++) {
        printf("----------------------------------------\n");
        printf("| %s | %d | %d | %d |  %d  |  %d  |\n",
               ar[i]->Name, ar[i]->at, ar[i]->bt, ar[i]->wt, ar[i]->ft, ar[i]->tt);
        printf("----------------------------------------\n");
        awt += ar[i]->wt;
        aft += ar[i]->ft;
    }
    printf("avg wt : %f\n", awt);
    printf("avg wt : %f\n", aft);
    return;
}

int main() {
    int n, arr, bst, cur = 0;
    int min_, temp_int;
    char Pname[mx];

    printf("number of process :");
    scanf("%d", &n);

    struct process* pr[n];
    struct process* done_pr[n];
// TAKING INPUT
    for (int i = 0; i < n; i++) {
        printf("%d process:\n", i + 1);
        printf("process name: ");
        scanf("%s", Pname);
        printf("process arrival time: ");
        scanf("%d", &arr);
        printf("process burst time: ");
        scanf("%d", &bst);
//                           Name,  at, bt,  wt,ft,tt
        pr[i] = new_process(Pname, arr, bst, 0, 0 , 0);
    }
    // sjf
    for(int a =0;a<n;a++){
        min_ = inf;
        for(int i = 0;i<n;i++){
            if(pr[i] != NULL && pr[i]->at <= cur && pr[i]->bt < min_ ){
                    temp_int = i;
                    min_ = pr[i]->bt;
            }
        }
        done_pr[a] = pr[temp_int];
        if(a == 0){
            done_pr[0]->wt = 0; 
        }else{
            done_pr[a]->wt = done_pr[a-1]->ft - done_pr[a]->at;
        }
        done_pr[a]->ft = cur + done_pr[a]->bt;
        done_pr[a]->tt = done_pr[a]->ft - done_pr[a]->at;  
        cur += done_pr[a]->bt;
        pr[temp_int] = NULL;
    } 
    
    print_process(n, done_pr);
  return 0;
}