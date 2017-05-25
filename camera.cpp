#include<stdio.h>
#include<time.h>
#include<iostream>
#include"E101.h"

using namespace std;

int horizontalSample() {
    // returns an int in the range -120 to 120
    int pixels[32];
    double sum = 0;

    take_picture();

    for (int i = 1; i < 32; i++) {
        int w = get_pixel(120,i*10,3);

        // Filters noise by simplifying pixels as either black or white, depending on th white value of the pixel
        if (w > 127) {
            pixels[i-1] = 255;
        } else {
            pixels[i-1] = 0;
        }
    }

    // using odd amount so scaling factor is even. Dropped pixel is on the very right and not very useful
    for (int i = 0; i < 31; i++) {
        double s = i - 15;

        if(pixels[i] == 255) {
            sum += s;
        }

    }

    return (int) sum;
}

int whiteness() {
	int whiteness = 0;
	for (int i = 1; i < 32; i++) {
		int w = get_pixel(120,i*10,3);
		whiteness += w;
	}
	
	cout << "White" << whiteness << endl;

	return whiteness;
}

string identifyPaths() {
    /* When called identifies if there are paths to the north, east and west.
     * returns a string containing "NEW" if junction has all paths, "E" if only eastern path etc.
     * if a empty string is returned, then this method shouldn't have been called in the first place eg. in curves quad2
     */
    double accuracy = 0.95; // min. percent of pixels that should be white to be fairly confident of a path.
    string paths = "";
    double northPixels;
    double eastPixels;
    double westPixels;
    int sampleInterval = 2; // samples every nth pixel

    take_picture();

    //North
    for (int i = 1; i < 120/sampleInterval; i++) {
        int w = get_pixel(i*sampleInterval,160,3);

        // Filters noise by simplifying pixels as either black or white, depending on th white value of the pixel
        if (w > 127) {
            northPixels += 1;
        }
    }
    //East
    for (int i = 160; i < 320/sampleInterval; i++) {
        int w = get_pixel(120,i*sampleInterval,3);

        // Filters noise by simplifying pixels as either black or white, depending on th white value of the pixel
        if (w > 127) {
            eastPixels += 1;
        }
    }

    //West
    for (int i = 1; i < 160/sampleInterval; i++) {
        int w = get_pixel(120,i*sampleInterval,3);

        // Filters noise by simplifying pixels as either black or white, depending on th white value of the pixel
        if (w > 127) {
            westPixels += 1;
        }
    }

    if (northPixels >= 120/sampleInterval * accuracy) {
        paths += "N";
    }

    if (eastPixels >= 160/sampleInterval * accuracy) {
        paths += "E";
    }

    if (westPixels >= 160/sampleInterval * accuracy) {
        paths += "W";
    }

    return paths;
}
