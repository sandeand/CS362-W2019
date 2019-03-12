

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTesthttp()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("http://www.google.com"));
      assertFalse(valid.isValid("htttp://www.google.com"));
   }

   public void testManualTestwww()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("http://www.google.com"));
      assertFalse(valid.isValid("http://ww.google.com"));
   }
   
   public void testManualTestcom()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("http://www.google.com"));
      assertFalse(valid.isValid("http://www.google.comm"));
   }
   
   public void testManualTestdot()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("http://www.google.com"));
      assertFalse(valid.isValid("http://www.google..com"));
   }
   
   public void testManualTestpup()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("https://www.google.com/search?q=greyhound+puppies&tbm=isch"));
   }
   
   public void testManualTestgov()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator();	   
      assertTrue(valid.isValid("https://www.epa.gov/"));
   }
   
   public void testManualTestfile()
   {
      //You can use this function to implement your manual testing	   
      UrlValidator valid = new UrlValidator(new String[] {"http","file"}, UrlValidator.ALLOW_LOCAL_URLS);
      assertTrue(valid.isValid("file:///C:/user/andrew/eclipse/"));
   }
   
    // Test first partition - scheme partition
   public void testSchemePartition() {	   
	// Store test schemes 
       String[] test_schemes = {"https://", "http://", "htp://", "://", ":/", "' '", "http", "https", "ftp"};
       UrlValidator scheme = new UrlValidator(test_schemes, 0);  
       int i;
	   
       // Display title and table headers
       System.out.println("\n\n      Testing Schemes");
       System.out.println("----------------------------");
       System.out.format("%s %10s %15s", "n", "Scheme", "Test Result");
       System.out.println();
       System.out.println("----------------------------");
       
       // Iterate over each of the schemes and test if valid
       for(i=0; i < test_schemes.length; i++) {
    	   String current_scheme = test_schemes[i];
    	   boolean is_valid_scheme = scheme.isValidScheme(current_scheme);

    	   // Test for each of the expected conditions
    	   if(
    			   i == 0 && is_valid_scheme == false || 
    			   i == 1 && is_valid_scheme == false || 
    			   i == 2 && is_valid_scheme == false || 
    			   i == 3 && is_valid_scheme == true  || 
    			   i == 4 && is_valid_scheme == true  || 
    			   i == 5 && is_valid_scheme == false || 
    			   i == 6 && is_valid_scheme == false ||
    			   i == 7 && is_valid_scheme == false ||
    			   i == 8 && is_valid_scheme == false
    	   )
    	   // Test failed
    	   {
    		   System.out.format("%d %12s %6s", i, current_scheme, "FAIL"); 
    		   System.out.println();
    	   }
    	   // Test passed
    	   else {
    		   System.out.format("%d %12s %6s", i, current_scheme, "PASS"); 
    		   System.out.println();
    	   }
       }    		
    }   
	
	

   // Test second partition - authority partition
   public void testAuthorityPartition() {
	   
       // Store testable authority examples
       String[] test_authority = {"' '", "www.google.com", "www.google~.com", "www.google", "invalid.hostname.com"};
       UrlValidator authority = new UrlValidator(test_authority, 0);
       
       // Display title and table headers
       System.out.println("\t  Testing Authority");
       System.out.println("--------------------------------------");
       System.out.format("%s %20s %15s", "n", "Authority", "Test Result");
       System.out.println();
       System.out.println("--------------------------------------");
       
       // Iterate over each of the authority examples 
       for(int i=0; i < test_authority.length; i++) {
    	   String current_authority = test_authority[i];
    	   boolean is_valid_authority = authority.isValidAuthority(current_authority);
    	   
    	   // Test for each of the expected conditions
    	   if(
    			   i == 0 && is_valid_authority == true  ||
    			   i == 1 && is_valid_authority == false || 
    			   i == 2 && is_valid_authority == true  || 
    			   i == 3 && is_valid_authority == true  ||  
    			   i == 4 && is_valid_authority == true
    	   )
    	   {
    	   // Test failed
    		   System.out.format("%d %20s %8s", i, current_authority, "FAIL"); 
    		   System.out.println();
    	   }
    	   // Test passed
    	   else {
    		   System.out.format("%d %20s %8s", i, current_authority, "PASS"); 
    		   System.out.println();
    	   }
       }	
    }
	
   // Test third parition - path partition
   public void testPathPartition() {	          
       // Store test paths 
       String[] test_paths = {"..", "/", "//", "test", "/test", "//test", "/../", "/.."};
       UrlValidator path = new UrlValidator(test_paths, 0);
       
       // Display title and table headers
       System.out.println("\n\n        Testing Path");
       System.out.println("----------------------------");
       System.out.format("%s %10s %15s", "n", "Path", "Test Result");
       System.out.println();
       System.out.println("----------------------------");
       
       // Iterate over each of the paths and test if valid
       for(int i=0; i < test_paths.length; i++) {
    	   String current_path = test_paths[i];
    	   boolean is_valid_path = path.isValidPath(current_path);
    	   if(!is_valid_path){
    		   System.out.println(i + "\t" + test_paths[i] + "\t" + " FAIL");
    	   }
    	   else {
    		   System.out.println(i + "\t" + test_paths[i] + "\t" + " PASS");
    	   }
       }
    }   

   // Test fourth partition - query partition
   public void testQueryPartition(){
       
       UrlValidator query = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       String testQueryPath = "http://www.google.com/path?";
       boolean is_valid_query = false;
       int i;
       int j;
	   
       // Display title and table headers
       System.out.println("\n\n               Testing Query");
       System.out.println("----------------------------------------------------------------------------------");
       System.out.format("%s %10s %60s", "n", "Query", "Test Result");
       System.out.println();
       System.out.println("----------------------------------------------------------------------------------");
       
       // Initialize list of expected invalid query
       ResultPair[] invalidQueries = {
           new ResultPair("badURLsM8 ", false),
           new ResultPair("*(&^#@(#%@$!;'", false),
           new ResultPair("[{}]", false),
           new ResultPair("google.com?", false),
       };
       
       // Initialize list of expected valid query
       ResultPair[] validQueries = {
           new ResultPair("action=view", true),
           new ResultPair("action=edit&mode=up", true),
           new ResultPair(" ", true)
       };

       // Iterate over list of all invalid queries 
       for (i = 0; i < invalidQueries.length; i++) {
           ResultPair invalidPair = invalidQueries[i];
           if(query.isValid(testQueryPath)) {
        	   System.out.format("%d      %s    %20s", i, testQueryPath + invalidPair.item, "FAIL");
        	   System.out.println();
        	 //System.out.println();
               assertEquals("http://www.google.com/path?" + invalidPair.item, invalidPair.valid, is_valid_query);
           }           
           else {
        	   System.out.format("%d %50s %s", i, testQueryPath + invalidPair.item, "ERROR");
        	   System.out.println();
           }          
       }
       
       // Iterate over list of all valid queries 
       for(j=0; j < validQueries.length; j++) {
    	   ResultPair validPair = validQueries[j];
	   // DEBUG: System.out.println("Number of valid queries items " + validQueries.length);
	   // DEBUG: System.out.println("Query item " + j + ": " + validPair.item + validPair.valid);
    	   if(query.isValid(testQueryPath)) {
        	   System.out.format("%d      %s    %23s", j+i, testQueryPath + validPair.item, "PASS");
        	   System.out.println();
           }           
           else {
        	   System.out.format("%d %50s %s", j, testQueryPath + validPair.item, "ERROR");
        	   System.out.println();
           }     	   
       }
       // Assert valid query 
       //assertEquals("http://www.google.com/path?" + validPair.item, validPair.valid, is_valid_query);
}

   
   //public void testYourFirstPartition()
   //{
	 //You can use this function to implement your First Partition testing	   

   //}
   
   //public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   //}
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
