

    
    public static boolean isAnagram(String a, String b) {
    
        a = a.toLowerCase();
        b = b.toLowerCase();
        
    
        if (a.length() != b.length()) {
            return false;
        }
        
    
        int[] charCount = new int[26]; 
        
        for (char c : a.toCharArray()) {
            charCount[c - 'a']++; 
        }
        
        
        for (char c : b.toCharArray()) {
            charCount[c - 'a']--; 
        }
        
    
        for (int count : charCount) {
            if (count != 0) {
                return false;
            }
        }
        
        return true; 
    }




