# Image Filtering and Convolution Process


[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)]()

✨Simple image processing ✨
## Project Achievements

- Simple to intermediate pointer use
- Write a module that holds methods together
- Getting information about the PGM file content
- Basic image processing
- Learning gray-level tones

![My Image](/Example_Image/readmeImg/example_filter_images.PNG)

> As seen in the picture above, a different type of filtering is applied according to the values ​​of each kernal matrix to filter the picture with a kernel filter matrix.

In this project, the picture with batman and joker was chosen as the [picture](/Example_Image/readmeImg/Batman_Image.jpg) to be filtered.
But when using this image in the project, we need to use it in [pgm format](/Example_Image/Batman_2048.pgm).
## Tech

- C programing Language

You can access my project about creating visual images with Julia set [here](https://github.com/suleymanayaz/Julia-Cluster).


## Installation

This requires [TDM-GCC 4.9.2](https://sourceforge.net/projects/tdm-gcc/files/TDM-GCC%204.9%20series/4.9.2-tdm-1%20DW2/) 4.9.2 to run.

If you want to filter the image you want, in the [pgmimage.h](/src/pgmimages.h) file:

```sh
 void readPGMFormattedImage(PGMFormattedImage *pgmFormattedImagePointer ){
  ...
  if( ( pgmFILE = fopen( "./Batman_2048.pgm", "r" ) ) != NULL ) // pgm file path
  ...
  
 void writePGMFormattedImage( PGMFormattedImage* pgmFormattedImagePointer ){
 ...
 if( ( pgmFILE = fopen( "./Processed_Batman_2046.pgm", "w" ) ) != NULL ) // pgm file path
 ...

}
} 
```
You should change the file path in the line.



## License

MIT

**Free Software, Hell Yeah!**
