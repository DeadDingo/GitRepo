//
//  pgmUtility.h
//  cscd240pgm
//
//  Created by Tony Tian on 11/2/13.
//  Copyright (c) 2013 Tony Tian. All rights reserved.
//

#ifndef cscd240pgm_pgmUtility_h
#define cscd240pgm_pgmUtility_h

#include <math.h>

#define rowsInHeader 4      // number of rows in image header
#define maxSizeHeadRow 200  // maximal number characters in one row in the header

#endif

/**
 *  Function Name: 
 *      pgmRead()
 *      pgmRead() reads in a pgm image using I/O direction by following its format strctly.
 *      
 *  @param[in,out]  header  holds the header of the pgm file in a 2D character array
 *                          After we process the pixels in the input image, we write the origianl 
 *                          header (or modified) back to a new image file.
 *  @param[in,out]  numRows describes how many rows of pixels in the image.
 *  @param[in,out]  numCols describe how many pixels in one row in the image.
 *  @return         If successful, return all pixels in the pgm image, which an int *, equicalent to 
 *                  a 2D array. Otherwise null.
 *
 */
int ** pgmRead( char **header, int *numRows, int *numCols );


/**
 *  Function Name:
 *      pgmDrawCircle()
 *      pgmDrawCircle() draw a circle on the image by setting relavant pixels to Zero.
 *
 *  @param[in,out]  pixels  holds all pixels in the pgm image, which a 2D integer array. The array
 *                          are modified after the drawing.
 *  @param[in]      numRows describes how many rows of pixels in the image.
 *  @param[in]      numCols describes how many pixels in one row in the image.
 *  @param[in]      centerCol specifies at which column you like to center your circle.
 *  @param[in]      centerRow specifies at which row you like to center your circle.
 *                        centerCol and centerRow defines the center of the circle.
 *  @param[in]      radius    specifies the radius of the circle would be in number of pixels.
 *  @param[in,out]  header returns the new header after draw. 
 *                  the circle draw might change the maximal intensity value in the image, so we
 *                  have to change maximum intensity value in the header accordingly.
 *  @return         return 1 if max intensity is changed, otherwise return 0;
 */
int pgmDrawCircle( int **pixels, int numRows, int numCols, int centerRow,
                  int centerCol, int radius, char **header );


/**
 *  Function Name:
 *      pgmDrawEdge()
 *      pgmDrawEdge() draw a black edge around the image by setting relavant pixels to Zero.
 *
 *  @param[in,out]  pixels  holds all pixels in the pgm image, which a 2D integer array. The array
 *                          are modified after the drawing.
 *  @param[in]      numRows describes how many rows of pixels in the image.
 *  @param[in]      numCols describes how many pixels in one row in the image.
 *  @param[in]      edgeWidth specifies how wide the edge frame would be in number of pixels.
 *  @param[in,out]  header returns the new header after draw.
 *                  the circle draw might change the maximal intensity value in the image, so we
 *                  have to change maximum intensity value in the header accordingly.
 *
 *  @return         return 1 if max intensity is changed by the drawing, otherwise return 0;
 */
int pgmDrawEdge( int **pixels, int numRows, int numCols, int edgeWidth, char **header );



/**
 *  Function Name:
 *      pgmWrite()
 *      pgmWrite() write headers and pixels into a pgm image using I/O direction.
 *
 *  @param[in]  header  holds the header of the pgm file in a 2D character array
 *                          we write the same header back to a new image file.
 *  @param[in]  pixels  holds all pixels in the pgm image, which a 2D integer array.
 *  @param[in]  numRows describes how many rows of pixels in the image.
 *  @param[in]  numCols describe how many pixels in one row in the image.
 *  @return         return 0 if the function successfully read the header and pixels.
 *                          else return -1;
 */
int pgmWrite( const char **header, const int **pixels, int numRows, int numCols );


/**
 *  Function Name:
 *      distance()
 *      distance() returns the Euclidean distance between two coordinates.
 *
 *  @param[in]  p1  point one, p1[0] is for row number, p1[1] is for column number
 *  @param[in]  p2  point one, p2[0] is for row number, p2[1] is for column number
 *  @return         return distance between p1 and p2
 */
double distance( int p1[], int p2[] );


