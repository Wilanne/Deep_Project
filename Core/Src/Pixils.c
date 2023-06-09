/*
 * Pixils.c
 *
 *  Created on: 11 mai 2023
 *      Author: leoau
 */

#include "Pixils.h"

characterPixels8_8 Wizard[4] = {
    {
        .pixels = {
            { W, W, PU, PU, PU, PU, PU, W },
            { W, PU, PU, PU, BL, BL, BL, PU },
            { PU, PU, PU, BL, W, BL, W, W },
            { PU, W, PU, BL, BL, BL, BL, W },
            { W, W, W, PU, BL, BL, PU, W },
            { W, PU, W, PU, PU, PU, W, W },
            { W, W, PU, PU, PU, PU, PU, W },
            { W, W, W, W, W, W, W, W },
        }
    },
    {
        .pixels = {
            { W, W, PU, PU, PU, PU, W, W },
            { W, PU, PU, BL, BL, BL, PU, W },
            { PU, PU, BL, W, BL, W, BL, PU },
            { PU, PU, BL, BL, BL, BL, BL, PU },
            { W, PU, PU, BL, BL, BL, PU, W },
            { W, W, W, PU, PU, PU, W, W },
            { W, W, PU, PU, PU, PU, PU, W },
            { W, PU, PU, PU, PU, PU, PU, W },
        }
    },
    {
        .pixels = {
            { W, W, PU, PU, PU, PU, W, W },
            { W, PU, BL, BL, BL, PU, PU, W },
            { PU, BL, W, BL, W, BL, PU, PU },
            { PU, BL, BL, BL, BL, BL, PU, PU },
            { W, PU, BL, BL, BL, PU, PU, W },
            { W, W, PU, PU, PU, W, W, W },
            { W, PU, PU, PU, PU, PU, W, W },
            { W, PU, PU, PU, PU, PU, PU, W },
        }
    },
    {
        .pixels = {
            { W, PU, PU, PU, PU, PU, W, W },
            { PU, BL, BL, BL, PU, PU, PU, W },
            { W, W, BL, W, BL, PU, PU, PU },
            { W, BL, BL, BL, BL, PU, W, PU },
            { W, PU, BL, BL, PU, W, W, W },
            { W, W, PU, PU, PU, W, PU, W },
            { W, PU, PU, PU, PU, PU, W, W },
            { W, W, W, W, W, W, W, W },
        }
    }
};


