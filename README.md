Credit Management System

Description
• As this is a credit management system, we have functions to add details of a new customer in a
structure. The details are written in the form of a structure in an external text file.
• The details include: Name, age, annual income, employment status, residential status, major
loan, loan amount, mortgage amount, car loan EMI, collateral and no late payments.
• We have eligibility criteria to see if the customer can get a loan or not- done through an
algorithm and also based on employment and collateral status.
• For the old customers, we can see their details stored in a structure in another file based on:
• Customer name
• Date of transaction
• All transactions of a customer for a particular cause- for ex, all the instances where a customer has paid a mortgage bill.
• We can add multiple transactions for various customers.
• We have a function that gives you all the details of a transaction that is due. It’s basically a
reminder to make the transaction.
• The last function is to generate a monthly report for the customers. This gives you the total
they’ve spent in a particular month.


C-concepts used
• We’ve used an array of structures to add the details of old customers
• Created a structure for storing new customer details
• Used the file operations fopen and fclose and written data (structures) to another external file
using file pointers.
• Read information from the text file- “f.txt”
• Used a switch case for choosing what action you want to perform.
• Used break statements in switch cases.
• Used printf statements to format the front page.
• Created a function for determining if a customer is eligible for a loan based on an algorithm
• Created functions for various search options- for searching by name, date and cause. Passing
search information taken from the user as parameters to the function.
• To compare the strings, we use the function strcmp() from the header file <string.h>
• To add a transaction, we use the file pointer to open the file “f.txt” write a structure
containing new transaction details and close the file using fclose(). We use the append mode(a+)
for the fopen function.
• Created a function for giving you a reminder which uses the standard function strcmp() to check
if paidyet=“no”.
• Created a function to calculate the monthly total of a customer, using for loops, strcmp(),
reading information from structures and adding the sum of amounts if the month matches the
desired month.
• Used a while loop to ensure that all menu options are available and the program only exits when
a certain option (7) is pressed.


![Screenshot 2023-08-04 at 2 47 14 PM](https://github.com/shreyas463/CreditSysProject/assets/76155738/918331ff-e1f6-4060-a178-c78d9261769b)







