class Solution {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder("");
        
        // 앞에서부터 비교해 지워가는 방식
        for(char num : number.toCharArray()){
            while(k > 0 && sb.length() > 0 && sb.charAt(sb.length() - 1) < num){
                k--;
                sb.deleteCharAt(sb.length() - 1);
            }
            sb.append(num);
        }
        // 더 지울 수 있는 경우
        // 뒷 자리부터 지운다
        if(k>0) return sb.substring(0, sb.length() - k);
        else return sb.toString();
    }
}