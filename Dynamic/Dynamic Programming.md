# Dynamic Programming

## 0-1 Knapsack Problem
Reference: [0/1 Knapsack Problem](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)

Given a set of $n$ items numbered from $1$ up to $n$, each with a weight $w_i$ and a value $v_i$, along with a maximum weight capacity $Capacity$, maximize the sum of the values of the items in the knapsack so that the sum of the weights is less than or equal to the knapsack's capacity.

> ### Example<br>
> INPUT:<br> 
> $Capacity = 13, n = 5, V = [24,2,9,10,9], W = [10,3,4,5,4]$

If we solve this problem by greedy algorithm, we need to calculate the value per weight first: $vw = v_i / w_i$

Then we got $v_w = [2.4,0.667,2.25,2,2.25]$.
In this way, the priority for picking up items is: 0->2->4->3->1. Under the limit of the upper capacity limit of 13, we will pick up item 0 and 1, and get the total value of the items to be 26.

But has the greedy algorithm obtained the optimal solution? It can be observed that if we select items 2, 3 and 4, we will get a backpack with a total value of 28.

1. Brute Force Enumeration
List all the products one by one, then remove the combinations that do not meet the capacity limit, and find the maximum value among the remaining ones, which is the optimal solution.

    > Pseudocode:<br>
    $KnapsackSR(h,i,c)$: Select the optimal solution when the capacity is c among the $h$ to $i$ commodities.<br> <br>
    Input: Item set $[{h, ..., i}]$<br>
    Output: The maximum value $P$<br><br>
    if $c < 0$ then<br>
    &emsp;return $-\infty$<br>
    endif<br>
    if $i \le h - 1$ then<br>
    &emsp;return 0<br>
    endif<br>
    $P_1 \gets Knapsack(h, i-1, c-v_i)$<br>
    $P_2 \gets Knapsack(h, i-1, c)$<br>
    $P \gets max\{P_1 + p_i, P_2\}$<br>
    return $P$
