#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void parseChromatic(Mat & I)
{
    CV_Assert(I.depth()== CV_8U);
    int nchan = I.channels();
    int nfil = I.rows;
    int ncol = I.cols * nchan;
    if(I.isContinuous())
    {
      ncol *= nfil;
      nfil = 1;
    }
    uchar *p =I.data;
    float suma=0;
    for(int i =0;i< ncol*nfil/3;i++)
    {
      suma =0.0;
      for(int j =0; j<3;j++)
      {
        suma += (float)*(p++);
      }
      p-=3;
      for(int j =0; j<3;j++)
      {
        *p++ =(uchar) (255*((float)*p)/ suma );
      }
    }
}

int camara()
{
  VideoCapture cap(0);
  if(!cap.isOpened())
    return -1;
  namedWindow("webcamModificacion");
  namedWindow("webcamOrigina");
  for(;;)
  {
    Mat frame;
    cap >> frame;
    imshow("webcamOrigina",frame);
    parseChromatic(frame);
    imshow("webcamModificacion", frame);

    if(waitKey(50) >= 0) break;
  }
  return 0;
}

void foto(char arg[])
{
  Mat imagen;
  imagen = imread(arg,1);
  namedWindow("webcamModificacion");
  namedWindow("webcamOrigina");
  imshow("webcamOrigina",imagen);
  parseChromatic(imagen);
  imshow("webcamModificacion", imagen);
  while(!(waitKey(50) >= 0) ){}
}

int main(int argc,char* Argv[])
{
  foto(Argv[1]);
  camara();
  return 0;
}
