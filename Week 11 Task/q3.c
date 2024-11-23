#include <stdio.h>
#include <ctype.h>

void copy_and_convert(const char *input_file, const char *output_file) {
    FILE *infile, *outfile;
    char ch;

    infile = fopen(input_file, "r");
    if (infile == NULL) {
        printf("Error: Could not open input file %s\n", input_file);
        return;
    }

    outfile = fopen(output_file, "w");
    if (outfile == NULL) {
        printf("Error: Could not open output file %s\n", output_file);
        fclose(infile); 
        return;
    }

    while ((ch = fgetc(infile)) != EOF) {
        ch = toupper(ch);
        fputc(ch, outfile);
    }

    fclose(infile);
    fclose(outfile);

    printf("File copied and converted successfully. Output saved to %s\n", output_file);
}

int main() {
    const char *input_file = "input.txt";  
    const char *output_file = "output.txt"; 

    copy_and_convert(input_file, output_file);

    return 0;
}
