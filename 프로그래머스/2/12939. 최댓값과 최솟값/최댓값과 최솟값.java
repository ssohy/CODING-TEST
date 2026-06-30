class Solution {
    public String solution(String s) {
        int min = (int)2e9;
        int max = (int)-2e9;
        String answer = "";
        for(int i = 0; i < s.length(); i++){
            String curNum = "";
            if(s.charAt(i) == ' ') continue;
            while(i < s.length() && s.charAt(i) != ' '){
                curNum += s.charAt(i);
                i++;
            }
            int num = Integer.parseInt(curNum);
            if(min > num) min = num;
            if(max < num) max = num;
        }
        answer = (min + " " + max);
        return answer;
    }
}