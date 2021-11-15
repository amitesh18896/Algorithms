import java.util.*; 
  
class AddnOfLI{ 
      
  
static String sum(String s1, String s2)  
{  
    String s = "";  				
   
    int n1 = s1.length(), n2 = s2.length();  
    int diff = n2 - n1;  

    int carry = 0; 

    if (s1.length() > s2.length()){ 
        String t = s1; 
        s1 = s2; 
        s2 = t; 
    } 
      
  
    for (int i = n1 - 1; i>=0; i--)  
    {  
        int sum = ((int)(s1.charAt(i)-'0') +  
            (int)(s2.charAt(i+diff)-'0') + carry);  
        s += (char)(sum % 10 + '0');  
        carry = sum / 10;  
    }  
  
    
    for (int i = n2 - n1 - 1; i >= 0; i--)  
    {  
        int sum = ((int)(s2.charAt(i) - '0') + carry);  
        s += (char)(sum % 10 + '0');  
        carry = sum / 10;  
    }  
  
    
    if (carry > 0)  
        s += (char)(carry + '0');  
  
    
    return new StringBuilder(s).reverse().toString(); 
}  
  

public static void main(String[] args)  
{  
    Scanner input = new Scanner(System.in);

    System.out.println("Enter the first integer: ");
    String s1 = input.nextLine();  
    System.out.println("Enter the second integer: ");
    String s2 = input.nextLine();  
    System.out.println("The sum is " + sum(s1, s2));  
}  
} 
  