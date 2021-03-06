#pragma once

/* --------------------------------------------------------------------------------------------------------------------------------------------
    The code written in Bitmap.c and Bitmap.h was not written by our group but instead was written by Henrique Ferrolho and shared by himself at
    http://difusal.blogspot.pt/2014/09/minixtutorial-8-loading-bmp-images.html.
 --------------------------------------------------------------------------------------------------------------------------------------------*/

/** @defgroup Bitmap Bitmap
 * @{
 * Functions for manipulating bitmaps
 */

#include "enum.h"

typedef struct {
    unsigned short type; // specifies the file type
    unsigned int size; // specifies the size in bytes of the bitmap file
    unsigned int reserved; // reserved; must be 0
    unsigned int offset; // specifies the offset in bytes from the bitmapfileheader to the bitmap bits
} BitmapFileHeader;

typedef struct {
    unsigned int size; // specifies the number of bytes required by the struct
    int width; // specifies width in pixels
    int height; // specifies height in pixels
    unsigned short planes; // specifies the number of color planes, must be 1
    unsigned short bits; // specifies the number of bit per pixel
    unsigned int compression; // specifies the type of compression
    unsigned int imageSize; // size of image in bytes
    int xResolution; // number of pixels per meter in x axis
    int yResolution; // number of pixels per meter in y axis
    unsigned int nColors; // number of colors used by the bitmap
    unsigned int importantColors; // number of colors that are important
} BitmapInfoHeader;

/// Represents a Bitmap
typedef struct {
    BitmapInfoHeader bitmapInfoHeader;
    unsigned char* bitmapData;
} Bitmap;

/**
 * @brief Loads a bmp image
 *
 * @param filename Path of the image to load
 * @return Non NULL pointer to the image buffer
 */
Bitmap* loadBitmap(const char* filename);

/**
 * @brief Draws an unscaled, unrotated bitmap at the given position
 *
 * @param bitmap bitmap to be drawn
 * @param x destiny x coord
 * @param y destiny y coord
 */
void drawBitmap(Bitmap* bitmap, int x, int y);

/**
 * @brief Draws an unscaled, unrotated bitmap at the given position with red filter, only red color
 *
 * @param bitmap bitmap to be drawn
 * @param x destiny x coord
 * @param y destiny y coord
 * @param applyFilter flag to indicate if filter is to be applied
 */
void drawBitmapWithRedFilter(Bitmap* bmp, int x, int y, bool applyFilter);

/**
 * @brief Destroys the given bitmap, freeing all resources used by it.
 *
 * @param bitmap bitmap to be destroyed
 */
void deleteBitmap(Bitmap* bmp);

/**@}*/
