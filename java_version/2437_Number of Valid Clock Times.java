class Solution {
    public int countTime(String time) {
        int countHour = 0;
        int countMinute = 0;
        for (int i = 0; i < 24; i++) {
            int hiHour = i / 10;
            int loHour = i % 10;
            if ((time.charAt(0) == '?' || time.charAt(0) == hiHour + '0') && 
                (time.charAt(1) == '?' || time.charAt(1) == loHour + '0')) {
                countHour++;
            }
        } 
        for (int i = 0; i < 60; i++) {
            int hiMinute = i / 10;
            int loMinute = i % 10;
            if ((time.charAt(3) == '?' || time.charAt(3) == hiMinute + '0') && 
                (time.charAt(4) == '?' || time.charAt(4) == loMinute + '0')) {
                countMinute++;
            }
        }
        return countHour * countMinute;
    }
}