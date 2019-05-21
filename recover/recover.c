// Implements a program called recover that recovers JPEGs from a forensic image

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    // accept one command-line argument (forensic image name)
    if (argc != 2)
    {
        fprintf(stderr, "Wrong number of command-line arguments input. Please input 1 command-line argument.");
        return 1;
    }

    //open memory card file
    FILE *raw_file = fopen("card.raw", "r");

    // if image cannot be opened for reading, return 2
    if (raw_file == NULL)
    {
        fprintf(stderr, "Error opening file");
        return 2;
    }

    // create buffer
    unsigned char buffer[BUFFER_SIZE];

    // create JPEG filename array
    char filename[8];

    // create output file
    FILE *new_image_file = NULL;

    // set JPEG counter to 0
    int JPEG_counter = 0;

    // set EOF boolean
    bool eof = false;

    // read in 512 bytes at a time
    while (fread(buffer, BUFFER_SIZE, 1, raw_file) == 1)
    {
        // find beginning of JPEG using distinct header
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (eof == true)
            {
                fclose(new_image_file);
            }
            else
            {
                eof = true;
            }

            // open a new JPEG and write filenames: ###.jpg in order found, starting at 000
            sprintf(filename, "%03i.jpg", JPEG_counter);

            new_image_file = fopen(filename, "w");

            // update counter
            JPEG_counter++;
        }

        // write 512 bytes until we reach the end of that JPEG and the beginning of a new JPEG is found
        if (eof == 1)
        {
            fwrite(&buffer, BUFFER_SIZE, 1, new_image_file);
        }
    }

    // detect end of memory card file and close files
    fclose(raw_file);
    fclose(new_image_file);
    return 0;
}