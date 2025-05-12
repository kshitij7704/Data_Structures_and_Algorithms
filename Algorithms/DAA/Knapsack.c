#include <stdio.h>

float knapsack(int capacity, int weights[], int profits[], int n){
    float ratios[n];
    for(int i=0;i<n;i++){
        ratios[i] = (float)profits[i] / weights[i];
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if (ratios[i] < ratios[j]){
                // Swap ratios
                float tempRatio = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = tempRatio;

                // Swap weights
                int tempWeight = weights[i];
                weights[i] = weights[j];
                weights[j] = tempWeight;

                // Swap profits
                int tempProfit = profits[i];
                profits[i] = profits[j];
                profits[j] = tempProfit;
            }
        }
    }

    int currentWeight = 0;
    float totalProfit = 0.0;

    for(int i=0;i<n;i++){
        if(currentWeight + weights[i] <= capacity){
            currentWeight += weights[i];
            totalProfit += profits[i];
        } 
        else{
            float remainingCapacity = capacity - currentWeight;
            totalProfit += (remainingCapacity / weights[i]) * profits[i];
            break;
        }
    }

    return totalProfit;
}

int main(){
    int n, capacity;

    printf("Enter the capacity of Knapsack: ");
    scanf("%d",&capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], profit[n]; 
    printf("Enter the weight and profit for each item:\n");
    for(int i=0;i<n;i++){
        printf("For item %d\n", i+1);
        printf("Weight: ");
        scanf("%d", &weights[i]);
        printf("Profit: ");
        scanf("%d", &profit[i]);
    }

    float maxProfit = knapsack(capacity, weights, profit, n);
    printf("Maximum profit: %.2f\n", maxProfit);

    return 0;
}