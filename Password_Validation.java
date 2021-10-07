/*A password is considered valid if all the following constraints are satisfied:
1. It contains at least 8 characters and at most 20 characters.
2. It contains at least one digit.
3. It contains at least one upper case alphabet.
4. It contains at least one lower case alphabet.
5. It contains at least one special character which includes !@#$%&*()-+=^.
6. It doesn’t contain any white space.*/
  
import java.util.regex.*;
import java.util.Scanner;
class PasswordValidation {
  
    // Function to validate the password.
    public static boolean isPasswordValid(String password)
    {
        if (password == null) {
            return false;
        }
       
        String regex = "^(?=.*[0-9])"
                       + "(?=.*[a-z])(?=.*[A-Z])"
                       + "(?=.*[@#$%^&+=])"
                       + "(?=\\S+$).{8,20}$";
  
       
        Pattern p = Pattern.compile(regex);
  
     
        Matcher m = p.matcher(password);
        return m.matches();
    }
  
    // Driver Code.
    
}
