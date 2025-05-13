#include <stdio.h>
#include <stdlib.h>

int abs(int x) {
    if(x < 0){
        return -x;
    }
    else{
        return x;
    }
}

int main() {
    int n, head, seek_time = 0;
    
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    
    int requests[n];
    
    printf("Enter the requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    printf("Sequence of movement:\n");
    printf("%d -> ", head);
    
    for (int i = 0; i < n; i++) {
        seek_time += abs(head - requests[i]);
        head = requests[i];
        if(i != n-1)
            printf("%d -> ", head);
        else
            printf("%d\n", head);
    }
    
    printf("\nTotal seek time: %d\n", seek_time);
    
    return 0;
}