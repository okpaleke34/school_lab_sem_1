#include<stdio.h>
    //this function takes a file location and copy it to another file in the second location
    double copy(char *input, char *output) {
        FILE *f_in = fopen(input, "r");
        FILE *f_out = fopen(output, "a");
        if (!f_in || !f_out) {
            fclose(f_in);
            fclose(f_out);
            return -1;
        }
        int c;
        while ((c = fgetc(f_in)) != EOF)
            fputc(c, f_out);
        fclose(f_in);
        fseek(f_out, 0, SEEK_END);
        long size = ftell(f_out);
        fclose(f_out);
        return (double)(size); // Bytes
    }
    
    int main()
    {
        double output;
        if ((output = copy("/Users/Big Name/Documents/School_C_Lab/st.csv", "/Users/Big Name/Documents/School_C_Lab/st7.csv")) != -1)
        {
            printf("Size of file: %lf Bytes.\n", output);
        }
        else{
            printf("There was an error copying the file");
        }
        return 0;
    }
    
