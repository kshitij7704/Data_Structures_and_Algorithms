// Demonstrate bankers deadlock detector algorithm
// find the number of process involved in dadlock if there is a deadlock? resolve the deadlock by selecting a victim process that has maximum no. of allocated resources
#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max_resources[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int processes, resources;

void calculateNeed(){
    for(int i=0;i<processes;i++){
        for(int j=0;j<resources;j++){
            need[i][j] = max_resources[i][j] - allocation[i][j];
        }
    }
}

int isSafeState(int work[]){
    int finish[MAX_PROCESSES] = {0};
    int work_copy[MAX_RESOURCES];
    for(int i=0;i<resources;i++){
        work_copy[i] = work[i];
    }

    int num_finished = 0;
    while(num_finished < processes){
        int found = 0;
        for(int i=0;i<processes;i++){
            if(!finish[i]){
                int j;
                for(j=0;j<resources;j++){
                    if(need[i][j] > work_copy[j]){
                        break;
                    }
                }
                if(j == resources){
                    for(int k=0;k<resources;k++){
                        work_copy[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    num_finished++;
                    found = 1;
                }
            }
        }
        if(!found){
            return 0;
        }
    }
    return 1;
}

void displaySafeSequence(int safe_seq[]){
    printf("Safe sequence of execution of processes: ");
    for(int i=0;i<processes;i++){
        printf("P%d ", safe_seq[i] + 1);
    }
    printf("\n");
}

int detectDeadlock(){
    calculateNeed();

    int work[MAX_RESOURCES];
    for(int i=0;i<resources;i++){
        work[i] = available[i];
    }

    if(isSafeState(work)){
        printf("No deadlock detected.\n");
        int safe_seq[MAX_PROCESSES];
        for(int i = 0; i < processes; i++){
            safe_seq[i] = i;
        }
        displaySafeSequence(safe_seq);
        return -1;
    } 
    else{
        printf("Deadlock detected. Resolving deadlock...\n");

        int max_allocated_process = -1;
        int max_allocated_resources = -1;
        for(int i=0;i<processes;i++){
            int allocated_resources = 0;
            for(int j=0;j<resources;j++){
                allocated_resources += allocation[i][j];
            }
            if(allocated_resources > max_allocated_resources){
                max_allocated_resources = allocated_resources;
                max_allocated_process = i;
            }
        }

        if(max_allocated_process != -1){
            printf("Victim process: %d\n", max_allocated_process + 1);
            for(int i=0;i<resources;i++){
                available[i] += allocation[max_allocated_process][i];
                allocation[max_allocated_process][i] = 0;
            }
            printf("Deadlock resolved.\n");
            return max_allocated_process;
        } 
        else{
            printf("Unable to resolve deadlock.\n");
            return -1;
        }
    }
}

int main(){
    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter number of resources: ");
    scanf("%d", &resources);

    printf("Enter allocation matrix:\n");
    for(int i=0;i<processes;i++){
        for(int j=0;j<resources;j++){
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter maximum resources matrix:\n");
    for(int i=0;i<processes;i++){
        for(int j=0;j<resources;j++){
            scanf("%d", &max_resources[i][j]);
        }
    }

    printf("Enter available resources: ");
    for (int i=0;i<resources;i++){
        scanf("%d", &available[i]);
    }

    detectDeadlock();
    return 0;
}