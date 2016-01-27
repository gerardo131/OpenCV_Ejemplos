#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void matching_diferencias(Mat & imagen, Mat & template)
{
  int imagen_nCol=imagen.cols;
  int imagen_nFil=imagen.rows;
  int template_nCol= template.cols;
  int template_nFil= template.rows;

  if(imagen.isContinuous()) {imagen_nCol *= imagen_nFil; imagen_nFil=1; }
  if (template.isContinuous()) { template_nCol *=imagen_nFil; template_nFil=1; }

  uchar *p= imagen.data;
  for(int i =0;i<imagen_nFil*imagen_nCol;i++)
  {
      float TM=0;
      for(j=0 ;j< template_nFil+template_nCol;i++)
      {

      }
  }

}

int main(int argc, char* Argv[])
{
  Mat imagen = imread(Argv[1],0);
  Mat template = imread(Argv[2],0);
  namedWindow("muestra");
  imshow("muestra",imagen);
  while( !(waitKey(50) >= 0) );
  return 0;
}
