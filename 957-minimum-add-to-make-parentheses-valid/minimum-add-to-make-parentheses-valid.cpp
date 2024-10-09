class Solution {
public:
    int minAddToMakeValid(string s) {
        // stack always helps in parenthesis problems
        // put opening bracket in stack and now check if there's any opening for closed one which is outside the stack
        // now we need to balance the string 
        // we can make a count for the brackets that are open 
        // it can also be done without stack just by taking a variable for size of stack
        // first size = 0, then if we found an open bracket then increase the size of stack by 1


       int size = 0;
       int open = 0;

       for(char &ch : s){
        if(ch == '(') {
            size++;
        } else if(
            size > 0)
        {
            size--;
        } else{
            open++;
        }
       }


         return open + size;
    }
};