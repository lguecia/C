// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    if (fraction[0] == '1')
    {
        if (fraction[2] == '8')
        {
            return 1;
        }
        else if (fraction[2] == '4')
        {
            return 2;
        }
        else if (fraction[2] == '2')
        {
            return 4;
        }
        else if (fraction[2] == '1')
        {
            return 8;
        }
    }
    else if (fraction[0] == '3' && fraction[2] == '8')
    {
        return 3;
    }
    else
    {
        return 0;
    }
    return 0;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    // Parse string into note and octave
    int octave = note[strlen(note) - 1]  - '0';

    // A4 frequency
    double freq = 440.0;

    // Adjust frequency for each note
    switch (note[0])
    {
        case 'C' :
            freq /= pow(2.0, (9.0 / 12.0));
            break;
        case 'D' :
            freq /= pow(2.0, (7.0 / 12.0));
            break;
        case 'E' :
            freq /= pow(2.0, (5.0  / 12.0));
            break;
        case 'F' :
            freq /= pow(2.0, (4.0 / 12.0));
            break;
        case 'G' :
            freq /= pow(2.0, (2.0 / 12.0));
            break;
        case 'A' :
            break;
        case 'B' :
            freq *= pow(2.0, (2.0 / 12.0));
            break;
        default :
            return 0;
    }

    // Shift octave
    if (octave > 4)
    {
        freq *= pow(2.0, octave - 4);
    }
    else if (octave < 4)
    {
        freq  /= pow(2.0, 4 - octave);
    }

    // Adjust for flats and sharps
    if (note[1] == 'b')
    {
        freq /= (pow(2.0, (1.0 / 12.0)));
    }
    else if (note[1] == '#')
    {
        freq *= (pow(2.0, (1.0 / 12.0)));
    }

    // Return note value as int
    int ret = round(freq);
    return ret;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    // If s is rest, return true; Otherwise, return false
    if (strncmp(s, "", 1))
    {
        return false;
    }
    else
    {
        return true;
    }
}
