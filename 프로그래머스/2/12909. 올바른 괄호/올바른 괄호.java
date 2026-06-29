import java.util.*;

class Solution {
    boolean solution(String s) {
        Stack<Character> result = new Stack<>();
        
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(result.empty()){
                result.push(c);
            }else{
                if(result.peek() == '(' && c == ')'){
                    result.pop();
                }else{
                    result.push(c);
                }
            }
        }

        if(result.empty()) return true;
        else return false;
    }
}