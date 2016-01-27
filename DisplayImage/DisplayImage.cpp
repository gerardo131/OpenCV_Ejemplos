#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

uchar table[256];
void createTable(int partes )
{
  for(int i=0;i<256;i++)
  {
    table[i]= partes*(i/partes);
  }
}

void ScanImageAndReduse(Mat & I)
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
    for(int i =0;i< ncol*nfil;i++)
      *p++ = table[*p];
}

int main()
{

  VideoCapture cap(0);

  if(!cap.isOpened())
    return -1;

  namedWindow("webcamModificacion");
  namedWindow("webcamOrigina");
  createTable( 10 );
  for(;;)
  {
    Mat frame;
    cap >> frame;
    imshow("webcamOrigina",frame);
    ScanImageAndReduse(frame);
    imshow("webcamModificacion", frame);

    if(waitKey(50) >= 0) break;
  }
  return 0;
}
