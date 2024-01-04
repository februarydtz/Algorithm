# Algorithm Analysis
**Reference:** [Discrete Mathematics and Its Applications, 7E, Kenneth H. Rosen](https://www.amazon.com/Discrete-Mathematics-Its-Applications-Seventh/dp/0073383090)

## Definition of Algorithm
> In mathematics and computer science, an algorithm is a finite sequence of rigorous instructons, typically used to solve a class of specific problems or to perform a computation. 

**Example 1:** Describe an algorithm for finding the maximum value in a finite sequence of integers.

**Solution:** 

    (1) Let the temporary maximum value be equal to the first integer in the sequence. 
    (At each stage of the entire process, the temporary maximum value is equal to the largest integer that has been checked)

    (2) Compare the next integer in the sequence with the temporary maximum value.  
    If this number is greater than the temporary maximum value, set the temporary maximum value to this integer.

    (3) If there are other integers in the sequence, repeat the previous step.

    (4) Stop when there are no other integers in the sequence.  
    The temporary maximum value at this time is the largest integer in the sequence.

