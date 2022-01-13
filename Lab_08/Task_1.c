#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaring the complex_number struct
struct complex_number
{
    double Re;
    double Im;
    char Op;
};


//this function takes the user input as a string then formats it to a complex number  by saving
//the real part, imaginary part and operator to its corresponding variable in complex_number struct
struct complex_number convert_to_complex(char userInput[20]){
    struct complex_number operand;
	char delim[] = " ";
    // this split the user input into three, separating it by the space
	char *ptr = strtok(userInput, delim);

    int count = 1;
	while(ptr != NULL)
	{
        char imaginary_num[4];
        int i = 0;

		switch(count){
            case 1:
                //the word before the first space is the Real part, then it converts the string to a double
                sscanf(ptr, "%lf", &operand.Re);
            break;

            case 2:
                // the char after the first space is the operator
                operand.Op = ptr[0];
            break;

            case 3:

                //the word after the second space is the Imaginary part, then it converts the string to a double
                // it loop through it until it see the `i` character
                while(ptr[i] != 'i'){
                    imaginary_num[i] = ptr[i];
                    i++;
                }
                //this convert the array of char(string) stored in the imaginar_num to double
                sscanf(imaginary_num, "%lf", &operand.Im);
            break;
            default:

            break;

		}
		ptr = strtok(NULL, delim);
		count++;
	}
	if(operand.Op == '-'){
        operand.Im = operand.Im * -1;
	}
	return  operand;

}

//this function takes two complex number and add thm together by adding their imaginary part together,
//then add their real part together and return the value as a complex number
struct complex_number add(struct complex_number operand1, struct complex_number operand2) {
    struct complex_number temp;
    temp.Re = operand1.Re + operand2.Re;
    temp.Im = operand1.Im + operand2.Im;
    return (temp);
}


//this function takes two complex number and subtract the operand 2 from operand 1 by subtracting their imaginary part together,
//then subtract their real part and return the value as a complex number
struct complex_number subtract(struct complex_number operand1, struct complex_number operand2) {
    struct complex_number temp;
    temp.Re = operand1.Re - operand2.Re;
    temp.Im = operand1.Im - operand2.Im;
    return (temp);
}

//this function takes two complex number and multiply them together
struct complex_number multiply(struct complex_number operand1, struct complex_number operand2) {
    struct complex_number temp;
    temp.Re = operand1.Re*operand2.Re - operand1.Im*operand2.Im;
    temp.Im = operand1.Im*operand2.Re + operand1.Re*operand2.Im;
    return (temp);
}


//this function takes two complex number and divide them
struct complex_number divide(struct complex_number operand1, struct complex_number operand2) {
    struct complex_number temp;
    if(operand2.Re == 0 && operand2.Im == 0){
        printf("You cannot divide by 0 + 0i \n");
    }
    else{
        double x = operand1.Re*operand2.Re + operand1.Im*operand2.Im;
        double y = operand1.Im*operand2.Re - operand1.Re*operand2.Im;
        double z = operand2.Re*operand2.Re + operand2.Im*operand2.Im;
        //applying formular (x - yi)/z
        temp.Re = x/z;
        temp.Im = y/z;
    }
    return (temp);

}


//this function helps to format the result to a good printable form
struct complex_number formatAnswer(struct complex_number result) {
    //if the imaginary part is a negative number multiply it by -1 to get a positive number
    //then save the negative operator in the operator variable
    if(result.Im < 0){
        result.Op = '-';
        result.Im = result.Im * -1;
	}
	else{
        result.Op = '+';
	}
    return (result);
}


int main()
{

    //declaring variables
    struct complex_number operand1;
    struct complex_number operand2;
    struct complex_number result;

    char userInput1[20], userInput2[20], inputOperator, operationText[50];


//    char userInput1[] = "8.34 - 34.5i";
//    char userInput2[] = "-23.89 + 2.3i";

    printf("This program takes two complex number from  the user and apply the operation defined by the user\n\n");
    printf("NOTE: For the effective running of the program please do not put any space before or after entering the complex number. \n");
    printf("Only 2 spaces are required and it must be before and after the operator\n\n");


    printf("Please enter a complex number in format a + bi: ");
    scanf("%[^\n]%*c", userInput1);

    printf("Please enter an operator. Excepeted are (+,-,/,*): ");
    inputOperator = getchar();
    getchar();

    printf("Please enter a complex number in format c + di: ");
    scanf("%[^\n]%*c", userInput2);

    operand1 = convert_to_complex(userInput1);
    operand2 = convert_to_complex(userInput2);

    if(inputOperator == '+')
    {
        result = add(operand1, operand2);
        //format the result to a good printable form
        result = formatAnswer(result);
        strcpy(operationText, "The sum of the input(Addition):  ");
    }
    else if(inputOperator == '-'){
        result = subtract(operand1, operand2);
        //format the result to a good printable form
        result = formatAnswer(result);
        strcpy(operationText, "The reduction of the input(Subtraction):  ");
    }
    else if(inputOperator == '*'){
        result = multiply(operand1, operand2);
        //format the result to a good printable form
        result = formatAnswer(result);
        strcpy(operationText, "The product of the input(Multiplication): ");
    }
    else if(inputOperator == '/'){
        result = divide(operand1, operand2);
        //format the result to a good printable form
        result = formatAnswer(result);
        strcpy(operationText, "The quotient of the user input(Division): ");
    }
    else{
        printf("The operator is not supported \n\n");
        return 0;
    }
    printf("\n %s %.3f %c %.3fi \n\n",operationText, result.Re, result.Op, result.Im);

    return 0;
}
