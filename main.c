#include "pgmimages.h"

void processPGMFormattedImage( PGMFormattedImage* pgmFormattedImagePointer );
float FilterArray[3][3]={{1,0,-1},
						 {2,0,-2},
						 {1,0,-1}
						}
int main( void ){
 PGMFormattedImage* newPGMFormattedImage = ( PGMFormattedImage* )malloc( sizeof( PGMFormattedImage ) );
 readPGMFormattedImage( newPGMFormattedImage );
 writePGMFormattedImage( newPGMFormattedImage );
 processPGMFormattedImgae( newPGMFormattedImage );
 free( newPGMFormattedImage );
 return 0;
}

void processPGMFormattedImage( PGMFormattedImage* pgmFormattedImagePointer ){
 float* pixelValues = ( pgmFormattedImagePointer->pixelValues );
 for( int rowIndex = 0; rowIndex < *( pgmFormattedImagePointer->heightOfImage ); rowIndex ++ ){
  float* rowOfPixelValues = ( float* )( ( char* )pixelValues + rowIndex * *( pgmFormattedImagePointer->widthOfImage ) * sizeof( float ) );
  for( int columnIndex = 0; columnIndex < *( pgmFormattedImagePointer->widthOfImage ); columnIndex ++ ){
   *( rowOfPixelValues + columnIndex ) = 255 - ( int )*( rowOfPixelValues + columnIndex );
  	// NOT DRY FIX ME 
  	int filteri= -1 , filterj= -1;
  	int ivalue=rowIndex + 3,jvalue=columnIndex + 3 ;
  	float counter = 0;
  	int i = rowIndex , j = columnIndex , jfirst = columnIndex;
  		for(i;ivalue;i++){
  			filteri++;
  			for(j;j<jvalue;j++){
  				filterj++;
  				counter +=pixelsArray[i][j]*filterArray[filteri][filterj]; // DON'T DRY
			  	// pixelsArray  ound in pgmimages.h file
			  }
			  filterj=-1;
			  j=jfirst;
		  }
		  *(rowOfPixelValues + columnIndex) =  counter ;
  }  
 }
}

