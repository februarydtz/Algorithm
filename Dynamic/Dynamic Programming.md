# Dynamic Programming
Dynamic programming refers to simplifying a complicated problem by breaking it down into simpler sub-problems in a recursive manner. In computer science, if a problem can be solved optimally by breaking it into sub-problems and then recursively finding the optimal solutions to the sub-problems, then it is said to have optimal substructure.

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

1. #### Brute Force Enumeration
List all the products one by one, then remove the combinations that do not meet the capacity limit, and find the maximum value among the remaining ones, which is the optimal solution.

> **Pseudocode:**<br>
> $KnapsackSR(h,i,c)$: Select the optimal solution when the capacity is c among the $h$ to $i$ items.<br> <br>
> Input: Item set $[{h, ..., i}]$<br>
> Output: The maximum value $P$<br><br>
> if $c < 0$ then<br>
> &emsp;return $-\infty$<br>
> endif<br>
> if $i \le h - 1$ then<br>
> &emsp;return 0<br>
> endif<br>
> $P_1 \gets Knapsack(h, i-1, c-v_i)$<br>
> $P_2 \gets Knapsack(h, i-1, c)$<br>
> $P \gets max\{P_1 + p_i, P_2\}$<br>
> return $P$

**Time Complexity of brute force enumeration: $O(2^n)$**

2. #### Dynamic Programming
Using dynamic programming ideas, we need to first find the optimal substructure of the 0-1 knapsack problem.<br>
For each item, we only have two choices, pick or not pick. If we delete one item from a optimal solution, then we delete the weight from the total weights, it's should also be a optimal solution.<br>
That is, if we have max capacity 13, and 5 items. The optimal substructure could be the solution of capacity 12 with 5 items, or capacity 13 with 4 items, or less.
So we can build a two-dimensional array to solve this problem.

| i \ j | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 |
|:-----:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0     | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0  | 0  | 0  | 0  |
| 1     | 0 |   |   |   |   |   |   |   |   |   |    |    |    |    |
| 2     | 0 |   |   |   |   |   |   |   |   |   |    |    |    |    |
| 3     | 0 |   |   |   |   |   |   |   |   |   |    |    |    |    |
| 4     | 0 |   |   |   |   |   |   |   |   |   |    |    |    |    |
| 5     | 0 |   |   |   |   |   |   |   |   |   |    |    |    |    |



If we can only choose item 1:
<table>
    <thead>
        <tr>
            <th>i \ j</th>
            <th>0</th>
            <th>1</th>
            <th>2</th>
            <th>3</th>
            <th>4</th>
            <th>5</th>
            <th>6</th>
            <th>7</th>
            <th>8</th>
            <th>9</th>
            <th>10</th>
            <th>11</th>
            <th>12</th>
            <th>13</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
        </tr>
        <tr>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>24</td>
            <td>24</td>
            <td>24</td>
            <td>24</td>
        </tr>
        <tr>
            <td>2</td>
            <td>0</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td>3</td>
            <td>0</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td>4</td>
            <td>0</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td>5</td>
            <td>0</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
    </tbody>
</table><br>

If we can choose item 1 and 2, $arr[2][13] = max(arr[1][13], arr[1][13-3]+2)$

<table>
    <thead>
        <tr>
            <th>i \ j</th>
            <th>0</th>
            <th>1</th>
            <th>2</th>
            <th>3</th>
            <th>4</th>
            <th>5</th>
            <th>6</th>
            <th>7</th>
            <th>8</th>
            <th>9</th>
            <th>10</th>
            <th>11</th>
            <th>12</th>
            <th>13</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
        </tr>
        <tr>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>24</td>
            <td>24</td>
            <td>24</td>
            <td>24</td>
        </tr>
        <tr>
            <td>2</td>
            <td>0</td>
            <td>0</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>24</td>
            <td>24</td>
            <td>24</td>
            <td>26</td>
        </tr>
        <tr>
            <td>3</td>
            <td>0</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td>4</td>
            <td>0</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
        <tr>
            <td>5</td>
            <td>0</td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
        </tr>
    </tbody>
</table><br>

So we can get the following formula:<br>
<center><img src="https://github.com/februarydtz/Algorithm/blob/C%2B%2B/Dynamic/img/CodeCogsEqn.gif" alt="Formula" style="align: center"></center>


Then the table will be:
<table>
    <thead>
        <tr>
            <th>i \ j</th>
            <th>0</th>
            <th>1</th>
            <th>2</th>
            <th>3</th>
            <th>4</th>
            <th>5</th>
            <th>6</th>
            <th>7</th>
            <th>8</th>
            <th>9</th>
            <th>10</th>
            <th>11</th>
            <th>12</th>
            <th>13</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
        </tr>
        <tr>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>0</td>
            <td>24</td>
            <td>24</td>
            <td>24</td>
            <td>24</td>
        </tr>
        <tr>
            <td>2</td>
            <td>0</td>
            <td>0</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>2</td>
            <td>24</td>
            <td>24</td>
            <td>24</td>
            <td>26</td>
        </tr>
        <tr>
            <td>3</td>
            <td>0</td>
            <td>0</td>
            <td>2</td>
            <td>2</td>
            <td>9</td>
            <td>9</td>
            <td>9</td>
            <td>9</td>
            <td>9</td>
            <td>9</td>
            <td>24</td>
            <td>24</td>
            <td>24</td>
            <td>26</td>
        </tr>
        <tr>
            <td>4</td>
            <td>0</td>
            <td>0</td>
            <td>2</td>
            <td>2</td>
            <td>9</td>
            <td>10</td>
            <td>10</td>
            <td>10</td>
            <td>10</td>
            <td>19</td>
            <td>24</td>
            <td>24</td>
            <td>24</td>
            <td>26</td>
        </tr>
        <tr>
            <td>5</td>
            <td>0</td>
            <td>0</td>
            <td>2</td>
            <td>2</td>
            <td>9</td>
            <td>10</td>
            <td>11</td>
            <td>11</td>
            <td>18</td>
            <td>19</td>
            <td>24</td>
            <td>24</td>
            <td>24</td>
            <td>28</td>
        </tr>    
    </tbody>
</table><br>

From this we get the optimal solution: if the number of items is 5 and the total capacity is 13, the maximum backpack value is 28