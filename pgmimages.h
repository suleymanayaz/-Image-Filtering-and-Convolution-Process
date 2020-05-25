#include <stdio.h>
#include <stdlib.h>

struct pgmFormattedImage{
 char *magicNumber;
 float *pixelValues;
 int *widthOfImage;
 int *heightOfImage;
 int *maximumGrayLevel;
};
typedef struct pgmFormattedImage PGMFormattedImage;

void readPGMFormattedImage( PGMFormattedImage *pgmFormattedImagePointer );
void writePGMFormattedImage( PGMFormattedImage *pgmFormattedImagePointer );
float pixelsArray[2048][2048];

void readPGMFormattedImage( PGMFormattedImage *pgmFormattedImagePointer ){
 FILE *pgmFILE = NULL;
 if( ( pgmFILE = fopen( "./Batman_2048.pgm", "r" ) ) != NULL ){
  int* widthOfImage = ( int* )malloc( sizeof( int ) );
  int* heightOfImage = ( int* )malloc( sizeof( int ) );
  int* maximumGrayLevel = ( int* )malloc( sizeof( int ) );
  char *magicNumber = ( char* )malloc( 2 * sizeof( char ) );
  
  //reading magic number from pgm formatted file
  fscanf( pgmFILE, "%s", magicNumber );
  ( pgmFormattedImagePointer )->magicNumber = magicNumber;
  //reading magic number from pgm formatted file

  //reading width and height of pgm formatted file
  fscanf( pgmFILE, "%d%d", widthOfImage, heightOfImage );
  ( pgmFormattedImagePointer )->widthOfImage = widthOfImage;
  ( pgmFormattedImagePointer )->heightOfImage = heightOfImage;
  //reading width and height of pgm formatted file

  //reading maximum gray level of image
  fscanf( pgmFILE, "%d", maximumGrayLevel );
  ( ( pgmFormattedImagePointer )->maximumGrayLevel ) = maximumGrayLevel;
  //reading maximum gray level of image
 
  //reading pixel values of images
  float *pixelValues = ( float* )malloc( *( pgmFormattedImagePointer->widthOfImage ) * *( pgmFormattedImagePointer->heightOfImage ) * sizeof( float ) );
  for( int rowIndex = 0; rowIndex < *( pgmFormattedImagePointer->heightOfImage ); rowIndex++ ){
   float *rowOfPixelValues = ( float* )( ( char* )pixelValues + rowIndex * *( pgmFormattedImagePointer->widthOfImage ) * sizeof( float ) );
   for( int columnIndex = 0; columnIndex < *( ( pgmFormattedImagePointer )->widthOfImage ); columnIndex ++ ){
    fscanf( pgmFILE, "%f", ( rowOfPixelValues + columnIndex ) );
    pixelsArray[rowIndex][columnIndex]=(*rowOfPixelValues + columnIndex);
	//printf( "%.1f\t", *( rowOfPixelValues + columnIndex ) );
   }
   //printf( "\n" );
  }
  ( pgmFormattedImagePointer )->pixelValues = pixelValues;
  //reading pixel values of images
  fclose( pgmFILE );
 }
 else{
  printf( "The pgm formatted image file cannot be read.\n" );
  exit( EXIT_FAILURE );
 } 
}
void writePGMFormattedImage( PGMFormattedImage* pgmFormattedImagePointer ){
 FILE *pgmFILE = NULL;
 if( ( pgmFILE = fopen( "./Processed_Batman_2046.pgm", "w" ) ) != NULL ){
  //writing magic number to pgm formatted file
  fprintf( pgmFILE, "%s\n", ( pgmFormattedImagePointer->magicNumber ) );
  //writing magic number to pgm formatted file
 
  //writing width and height of pgm formatted file
  fprintf( pgmFILE, "%d %d\n", *( pgmFormattedImagePointer->widthOfImage ) -2, *( pgmFormattedImagePointer->heightOfImage ) -2);
  //writing width and height of pgm formatted file
  
  //writing maximum gray level of image
  fprintf( pgmFILE, "%d\n", 255 );
  //writing maximum gray level of image

  //writing pixel values of image
  float* pixelValues = ( pgmFormattedImagePointer->pixelValues );
  for( int rowIndex = 0; rowIndex < *( pgmFormattedImagePointer->heightOfImage ) -2; rowIndex ++ ){
   float* rowOfPixelValues = ( float* )( ( char* )pixelValues + rowIndex * *( pgmFormattedImagePointer->widthOfImage ) * sizeof( float ) );
   for( int columnIndex = 0; columnIndex < *( pgmFormattedImagePointer->widthOfImage ) -2 ; columnIndex ++ ){
    //fprintf( pgmFILE, "%d\t", ( ( int )*( rowOfPixelValues + columnIndex ) ) <= 150 ? 0 : ( int )*( rowOfPixelValues + columnIndex ) );
    if((int)*(rowOfPixelValues + columnIndex) < 0 ){
    	fprintf(pgmFILE, "%d\t",0);
	}
	 if((int)*(rowOfPixelValues + columnIndex) > 255 ){
    	fprintf(pgmFILE, "%d\t",255);
	}
	 if((int)*(rowOfPixelValues + columnIndex) <=0 && (int)*(rowOfPixelValues + columnIndex) <= 255 ){
    	fprintf(pgmFILE, "%d\t",(int)*(rowOfPixelValues + columnIndex ));
	}
   }  
   if( rowIndex != *( pgmFormattedImagePointer->heightOfImage ) - 3 ){
    fprintf( pgmFILE, "\n" );
   }
  }
  //writing pixel value of image
  fclose( pgmFILE );
 }
 else{
  printf( "The pgm formatted file cannot be writen.\n" );
  exit( EXIT_FAILURE );
 }
}
