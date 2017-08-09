

#include "ocropus/ocr-noisefilter.h"
#include "ocropus/ocr-pageframe-rast.h"
#include "folder.h"

using namespace ocropus;
using namespace colib;
using namespace iulib;


int main(int argc, char*argv[])
{
  bytearray a,out;
  bytearray pfout,pfin;
  char *name;
  
  
  char *input_image_name;
  input_image_name = (char *)malloc(2001*sizeof(char));
  strcpy(input_image_name,argv[1]);
	
  char *dirname;
  dirname = (char *)malloc(2001*sizeof(char));
  dirname = IITkgp_functions::input_image_name_cut(input_image_name);
  
  name = (char *)malloc(2001*sizeof(char));
	
  name = IITkgp_functions::CreateNameIntoFolder(dirname,"LabelAllInOne.png");
  
  read_image_binary(a,name);
  
  NoiseFilter NF;
  
  
  
  //out.copy<unsigned char>(a);
  
  NF.blackFilter(out,a);
  
  intarray labels;
  copy(labels,out);
  for(int i=0;i<labels.length();i++)
    labels[i] = !labels[i];
  //labels.copy<unsigned char>(out);
  
  label_components(labels);
  narray<rectangle> boxes;
  bounding_boxes(boxes,labels);
  
  
  NF.ccanalysis(out,out,boxes);
  
  NF.whiteFilter(out,out);
  
  
  IITkgp_functions::makedir("NoiseFilter");
   name=(char *)malloc(2001*sizeof(char));
   name = IITkgp_functions::CreateNameIntoFolder("NoiseFilter",argv[1]);
   write_image_binary(name,out);
   out.clear();
   
  
  
  //int image_width  = a.dim(0);
  //int image_height = a.dim(1);
  pfin.copy<unsigned char>(a);
  
  
  
   IITkgp_functions::makedir("PageFrame");
   name=(char *)malloc(2001*sizeof(char));
   name = IITkgp_functions::CreateNameIntoFolder("PageFrame",argv[1]);
   //read_image_binary(pfin,argv[1]);
   PageFrameRAST PF;
   PF.cleanup(pfout,pfin);
   write_image_binary(name,pfout);
   pfout.clear();
   
   
   
  
  
}