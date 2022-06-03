#include "pgmimages.h"

void processPGMFormattedImage( PGMFormattedImage* pgmFormattedImagePointer );
float FilterArray[3][3]={{1,0,-1},  // FilterArray is matris. 
						 {2,0,-2},
						 {1,0,-1}
						};

int main( void ){
 PGMFormattedImage* newPGMFormattedImage = ( PGMFormattedImage* )malloc( sizeof( PGMFormattedImage ) );
 readPGMFormattedImage( newPGMFormattedImage ); // Read pgm file
 processPGMFormattedImage( newPGMFormattedImage );  // The picture is multiplied by a kernel matrix and a filtering operation is performed.
 writePGMFormattedImage( newPGMFormattedImage ); // Write pgm file (image)
 free( newPGMFormattedImage ); // free memory
 return 0;
}

void processPGMFormattedImage( PGMFormattedImage* pgmFormattedImagePointer ){
 float* pixelValues = ( pgmFormattedImagePointer->pixelValues );
 int rowIndex,columnIndex;
 for( rowIndex = 0; rowIndex < *( pgmFormattedImagePointer->heightOfImage ); rowIndex ++ ){
  float* rowOfPixelValues = ( float* )( ( char* )pixelValues + rowIndex * *( pgmFormattedImagePointer->widthOfImage ) * sizeof( float ) );
  for(columnIndex = 0; columnIndex < *( pgmFormattedImagePointer->widthOfImage ); columnIndex ++ ){
   *( rowOfPixelValues + columnIndex ) = 255 - ( int )*( rowOfPixelValues + columnIndex );
  	int filterRow= -1 , filterCol= -1;
  	int maxRow=rowIndex + 3,maxCol=columnIndex + 3 ;
  	float counter = 0;
  	int i = rowIndex , j = columnIndex , firstCol = columnIndex;
  		for(i;i<maxRow;i++){
  			filterRow++;
  			for(j;j<maxCol;j++){
  				filterCol++;
  				counter +=pixelsArray[i][j]*FilterArray[filterRow][filterCol]; 
				
			  }
			  filterCol= filterCol -1;
			  j=firstCol;
		  }
		  *(rowOfPixelValues + columnIndex) =  counter ;
  }  
 }
}



