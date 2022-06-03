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

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
