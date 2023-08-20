# CPP-Based-Compiler
-------C++ Based Compiler-------

This is a jff C++ Based Compiler (prototype stage 1). This compiler mechanism is based on simple Control Statements. if...else if...if is heavily used here. This is prototype is not in any way claims to be EFFICIENT. You can help me out by optimizing it.

In this First Prototype stage this compiler is able to declare AND initialize a variable. Can perform addition of more than 2 operands.


### Create a file named source.txt in the same folder where compiler.cpp is present and write the Prototype Code with shown below syntax, Then save the txt file and run the cpp file to get output.


---SYNTAX DOCUMENTATION---
1. * -> marks the beginning of each line.
2. ~ -> Comes immidiately after the * symbol and basically used before declaring variables;
3. Datatypes:
    #Currently only one datatype is made to work: The Integer
    a. i -> comes after ~. The name of the var is set by writing the datatype and the varname both seperated by the ~ symbol.
    e.g. :- *~i~<var_name>=10
        This assigns the int type var a value of 10;
4. /p -> Ender /p (one of the Enders) prints the given value of the variable in its LOC.        

HERE IS AN EXAMPLE CODE:

*~i~a=66
*~i~k=82
*~i~l=1
*/m~c=a+k+l~/p

this assigns values to variables a, k and l. Adds them and assigns the value to c and gives c (value) as the output. /p gives the output of c.



----------------------------THIS IS JUST A PROTOTYPE, TRY AND OPTIMISE IT. HELPS A LOT----------------------------
            --------------------------------------THANK YOU--------------------------------------
