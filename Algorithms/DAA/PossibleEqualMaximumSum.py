def findCommonMaxSum(stack1, stack2, stack3):
    sum1 = sum(stack1)
    sum2 = sum(stack2)
    sum3 = sum(stack3)

    if (sum1 == sum2 == sum3) or (len(stack1) == 0 and len(stack2) == 0 and len(stack3) == 0):
        return sum1

    if sum1 > sum2 and sum1 > sum3:
        if len(stack1) > 0:
            sum1 -= stack1.pop()
    elif sum2 > sum1 and sum2 > sum3:
        if len(stack2) > 0:
            sum2 -= stack2.pop()
    else:
        if len(stack3) > 0:
            sum3 -= stack3.pop()

    return findCommonMaxSum(stack1, stack2, stack3)

stack1 = [1, 2, 1, 4]
stack2 = [1, 2, 3]
stack3 = [1, 2]

common = findCommonMaxSum(stack1, stack2, stack3)
print("Common maximum sum:", common)
