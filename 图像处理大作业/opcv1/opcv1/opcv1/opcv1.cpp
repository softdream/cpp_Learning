// opcv1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "cv.h"
#include <math.h>
using namespace std;
CvSeq* findSquares4( IplImage* img, CvMemStorage* storage ,int minarea, int maxarea, int minangle, int maxangle);
void drawSquares1( IplImage* img, CvSeq* squares ,const char* wndname);
void findCircle(IplImage* img,CvMemStorage* storage);
int thresh = 50;
IplImage* img = 0;
IplImage* img0 = 0;
CvMemStorage* storage = 0;
CvPoint pt[4];
const char* wndname = "Square Detection Demo";

double angle( CvPoint* pt1, CvPoint* pt2, CvPoint* pt0 )
{
    double dx1 = pt1->x - pt0->x;
    double dy1 = pt1->y - pt0->y;
    double dx2 = pt2->x - pt0->x;
    double dy2 = pt2->y - pt0->y;//
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
//    double angle_line = (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);//余弦值
//    return acos(angle_line)*180/3.141592653;
}

// returns sequence of squares detected on the image.
// the sequence is stored in the specified memory storage
CvSeq* findSquares3( IplImage* img, CvMemStorage* storage )
{
    CvSeq* contours;
    int i, c, l, N = 11;
    CvSize sz = cvSize( img->width & -2, img->height & -2 );
    IplImage* timg = cvCloneImage( img ); // make a copy of input image
    IplImage* gray = cvCreateImage( sz, 8, 1 );		//1/2
    IplImage* pyr = cvCreateImage( cvSize(sz.width/2, sz.height/2), 8, 3 );		//1/4
    IplImage* tgray;
    CvSeq* result;
    double s, t;
    // create empty sequence that will contain points -
    // 4 points per square (the square's vertices)
    CvSeq* squares = cvCreateSeq( 0, sizeof(CvSeq), sizeof(CvPoint), storage );
    
    // select the maximum ROI in the image
    // with the width and height divisible by 2
    cvSetImageROI( timg, cvRect( 0, 0, sz.width, sz.height ));	//去图像1/2大小的图片，即将图片分为四份，去左上角的部分    
    // down-scale and upscale the image to filter out the noise
    cvPyrDown( timg, pyr, 7 );
    cvPyrUp( pyr, timg, 7 );
    tgray = cvCreateImage( sz, 8, 1 );    
    // find squares in every color plane of the image
    for( c = 0; c < 3; c++ )//在三通道下
    {
        // extract the c-th color plane
        cvSetImageCOI( timg, c+1 );
        cvCopy( timg, tgray, 0 );        
        // try several threshold levels
        for( l = 0; l < N; l++ )
        {
            // hack: use Canny instead of zero threshold level.
            // Canny helps to catch squares with gradient shading   
            if( l == 0 )
            {
                // apply Canny. Take the upper threshold from slider
                // and set the lower to 0 (which forces edges merging) //thresh
                cvCanny( tgray, gray, 1000, 900, 5 );
//				 cvThreshold( tgray, gray, (l+1)*255/N, 255, CV_THRESH_BINARY );	//二值化
				cvShowImage( "canny", gray );
                // dilate canny output to remove potential
                // holes between edge segments 
//                cvDilate( gray, gray, 0, 1 );
//				cvShowImage( "膨胀", gray );
           }
           else
            {
                // apply threshold if l!=0:
                //     tgray(x,y) = gray(x,y) < (l+1)*255/N ? 255 : 0
                cvThreshold( tgray, gray, (l+1)*255/N, 255, CV_THRESH_BINARY );	//二值化
			//	cvShowImage( "canny", gray );
            }            
            // find contours and store them all as a list
            cvFindContours( gray, storage, &contours, sizeof(CvContour),
                CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0) );		//二值图像中寻找轮廓            
            // test each contour
            while( contours )//返回的轮廓在contours中
            {
                // approximate contour with accuracy proportional
                // to the contour perimeter
                result = cvApproxPoly( contours, sizeof(CvContour), storage,
                    CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0 );	//用指定精度逼近多边形曲线
                // square contours should have 4 vertices after approximation
                // relatively large area (to filter out noisy contours)
                // and be convex.
                // Note: absolute value of an area is used because
                // area may be positive or negative - in accordance with the
                // contour orientation
//				printf("area=%f\n",cvContourArea(result,CV_WHOLE_SEQ));
                if( result->total == 3 &&
                    fabs(cvContourArea(result,CV_WHOLE_SEQ)) > 200 &&//计算整个区域的面积
                    cvCheckContourConvexity(result) )//判断轮廓是否为凸
                {
                    s = 0;                    
                    for( i = 0; i < 5; i++ )
                    {
                        // find minimum angle between joint
                        // edges (maximum of cosine)
                        if( i >= 2 )
                        {
                            t = fabs(angle(
                            (CvPoint*)cvGetSeqElem( result, i ),
                            (CvPoint*)cvGetSeqElem( result, i-2 ),
                            (CvPoint*)cvGetSeqElem( result, i-1 )));
                            s = s > t ? s : t;
							//printf("%f",t);
                        }
                    }                    
                    // if cosines of all angles are small
                    // (all angles are ~90 degree) then write quandrange
                    // vertices to resultant sequence 
                    if( (s < 0.98)&&(s>-0.98) )
                        for( i = 0; i < 3; i++ )
                            cvSeqPush( squares,
                                (CvPoint*)cvGetSeqElem( result, i ));
                }                
                // take the next contour
                contours = contours->h_next;
            }
        }
    }
    
    // release all the temporary images
    cvReleaseImage( &gray );
    cvReleaseImage( &pyr );
    cvReleaseImage( &tgray );
    cvReleaseImage( &timg );
    
    return squares;
}


// the function draws all the squares in the image
void drawSquares( IplImage* img, CvSeq* squares )
{
    CvSeqReader reader;
    IplImage* cpy = cvCloneImage( img );
    int i;
//	int x3=0,y3=0,i3=0;
//	double r3;
    
    // initialize reader of the sequence
    cvStartReadSeq( squares, &reader, 0 );
    
    // read 4 sequence elements at a time (all vertices of a square)
    for( i = 0; i < squares->total; i += 4 )
    {
        CvPoint* rect = pt;
        int count = 3;
        
        // read 4 vertices
        memcpy( pt, reader.ptr, squares->elem_size );
        CV_NEXT_SEQ_ELEM( squares->elem_size, reader );
        memcpy( pt + 1, reader.ptr, squares->elem_size );
        CV_NEXT_SEQ_ELEM( squares->elem_size, reader );
        memcpy( pt + 2, reader.ptr, squares->elem_size );
        CV_NEXT_SEQ_ELEM( squares->elem_size, reader );
//        memcpy( pt + 3, reader.ptr, squares->elem_size );
//        CV_NEXT_SEQ_ELEM( squares->elem_size, reader );
		printf("%d-%d\n",rect->x,rect->y);
		printf("%d-%d\n",(rect+1)->x,(rect+1)->y);
		printf("%d-%d\n",(rect+2)->x,(rect+2)->y);
        // draw the square as a closed polyline 
//        cvPolyLine( cpy, &rect, &count, 1, 1, CV_RGB(255,255,0), 2, CV_AA, 0 );
		cvRectangle(cpy,cvPoint((rect+1)->x,rect->y),cvPoint((rect+2)->x,(rect+2)->y),cvScalar(0, 0, 255), 3, 4, 0 );
		//cvRectangle(cpy,cvPoint(20,20),cvPoint((rect+1)->x,(rect+1)->y),cvScalar(0, 0, 255), 3, 4, 0 );
		//cvRectangle(cpy,cvPoint(20,20),cvPoint((rect+2)->x,(rect+2)->y),cvScalar(0, 0, 255), 3, 4, 0 );
//		x3+=rect->x;
//		y3+=rect->y;
//		r3=sqrt((x3/i3-rect->x)*(x3/i3-rect->x)+(y3/i3-rect->y)*(y3/i3-rect->y));
//		i3++;
    }
//	cvCircle(cpy,cvPoint(int(x3/i3),int(y3/i3)),(int)r3,CV_RGB(255,0,0),2);
    
    // show the resultant image
    cvShowImage( wndname, cpy );
    cvReleaseImage( &cpy );
}


void on_trackbar( int a )
{
    if( img )
	{
        drawSquares( img, findSquares3( img, storage ) );
//		drawSquares1( img, findSquares4( img, storage,100,5000,85,100 ),"square");
//		findCircle(img,storage);
	}
}
void writeCSV()
{
	 std::ofstream oFile;
         
        //打开要输出的文件

    oFile.open("F:\\MYPROJECT\\vcProject\\00.csv", ios::out | ios::trunc);
	oFile << "id" << "," << "x1" << "," << "y1" << "," << "x2" <<","<<"y2"<<","<<"score"<< endl;
	 for(int i=0;i<=5999;i++)
	 {    
    oFile << i<< "," << "400" << "," << "600" << "," << "601" <<"," << "801" <<","<<"1"<< endl;
	printf("%d\n",i);
	 }
 
    oFile.close();
}
int _tmain(int argc, _TCHAR* argv[])
{
    int i, c;
    // create memory storage that will contain all the dynamic data
    storage = cvCreateMemStorage(0);
        img0 = cvLoadImage( "F:\\MYPROJECT\\vcProject\\003453.png", CV_LOAD_IMAGE_COLOR );
        if( !img0 )
        {
            printf("Couldn't load %s\n","F:\\MYPROJECT\\vcProject\\003453.jpg");
        }
        img = cvCloneImage( img0 );
//		printf("s%d,%d",img->width,img->height);
		img->height=img->height-100;
//	cv::Mat image= cv::imread("F:\\MYPROJECT\\vcProject\\DSCF3173.jpg");
  //      cvSmooth(img,img,CV_MEDIAN,3,3,0,0);
		//cvShowImage( "canny", img );
        // create window and a trackbar (slider) with parent "image" and set callback
        // (the slider regulates upper threshold, passed to Canny edge detector) 
       cvNamedWindow( wndname, 1 );
//	   writeCSV();
//	   findCircle(img,storage);
       cvCreateTrackbar( "canny thresh", wndname, &thresh, 1000, on_trackbar );
//	 drawSquares( img, findSquares3( img, storage ) );
//        drawSquares1( img0, findSquares4( img0, storage,10,2000,80,100 ),"square");
        // force the image processing
       on_trackbar(0);
        // wait for key.
        // Also the function cvWaitKey takes care of event processing
        c = cvWaitKey(0);
        // release both images
        cvReleaseImage( &img );
        cvReleaseImage( &img0 );
        // clear memory storage - reset free space position
        cvClearMemStorage( storage );

	return 0;
}
CvSeq* findSquares4( IplImage* img, CvMemStorage* storage ,int minarea, int maxarea, int minangle, int maxangle)
{  
    CvSeq* contours;//边缘
    int N = 6;  //阈值分级
    CvSize sz = cvSize( img->width & -2, img->height & -2 );
    IplImage* timg = cvCloneImage( img );//拷贝一次img
    IplImage* gray = cvCreateImage( sz, 8, 1 ); //img灰度图
    IplImage* pyr = cvCreateImage( cvSize(sz.width/2, sz.height/2), 8, 3 );  //金字塔滤波3通道图像中间变量
    IplImage* tgray = cvCreateImage( sz, 8, 1 ); ;   
    CvSeq* result;  
    double s, t;  
    CvSeq* squares = cvCreateSeq( 0, sizeof(CvSeq), sizeof(CvPoint), storage );   

    cvSetImageROI( timg, cvRect( 0, 0, sz.width, sz.height ));   
    //金字塔滤波 
    cvPyrDown( timg, pyr, 7 );  
    cvPyrUp( pyr, timg, 7 );   
    //在3个通道中寻找矩形 
    for( int c = 0; c < 3; c++ ) //对3个通道分别进行处理 
    {       
        cvSetImageCOI( timg, c+1 );     
        cvCopy( timg, tgray, 0 );  //依次将BGR通道送入tgray         
        for( int l = 0; l < N; l++ )     
        {         
            if( l == 0 )
            {
                // apply Canny. Take the upper threshold from slider
                // and set the lower to 0 (which forces edges merging) 		
                cvCanny( tgray, gray,900,1000, 5 );
                // dilate canny output to remove potential
                // holes between edge segments 
				//cvShowImage( "canny", gray );				
                cvDilate( gray, gray, 0, 1 );
				cvErode(gray, gray, 0, 1);
				cvShowImage( "fazhi", gray ); 
            }
            //不同阈值下二值化
			else
				cvThreshold( tgray, gray, (l+1)*255/N, 255, CV_THRESH_BINARY );
			printf("%d-%d\n",minarea,maxarea);
            cvFindContours( gray, storage, &contours, sizeof(CvContour),CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0) );          
            while( contours )    
            { //多边形逼近             
              result = cvApproxPoly( contours, sizeof(CvContour), storage,CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0 ); 
				 
                //如果是凸四边形并且面积在范围内
              if( result->total == 4 && fabs(cvContourArea(result,CV_WHOLE_SEQ)) > minarea  && fabs(cvContourArea(result,CV_WHOLE_SEQ)) < maxarea &&
				  cvCheckContourConvexity(result) )  
                {         
                    s = 0;      
                    //判断每一条边
                    for( int i = 0; i < 5; i++ )  
                    {                   
                        if( i >= 2 )           
                        {   //角度            
                            t = fabs(angle( (CvPoint*)cvGetSeqElem( result, i ),(CvPoint*)cvGetSeqElem( result, i-2 ),(CvPoint*)cvGetSeqElem( result, i-1 )));   
                            s = s > t ? s : t;     
							printf("%f",t);
                        }         
                    }   
                    //这里的S为直角判定条件 单位为角度
                    if( s > minangle && s < maxangle )                      
                        for( int i = 0; i < 4; i++ )              
                            cvSeqPush( squares,(CvPoint*)cvGetSeqElem( result, i ));     
                }                                      
                contours = contours->h_next;      
            }   
        } 
    }
    cvReleaseImage( &gray );   
    cvReleaseImage( &pyr );  
    cvReleaseImage( &tgray );  
    cvReleaseImage( &timg );   
    return squares;
}  

void drawSquares1( IplImage* img, CvSeq* squares ,const char* wndname)
{   
    CvSeqReader reader;   
    IplImage* cpy = cvCloneImage( img );   
    CvPoint pt[4];
    int i;       
    cvStartReadSeq( squares, &reader, 0 );     
    for( i = 0; i < squares->total; i += 4 )  
    {       
        CvPoint* rect = pt;    
        int count = 4;      
        memcpy( pt, reader.ptr, squares->elem_size ); 
        CV_NEXT_SEQ_ELEM( squares->elem_size, reader ); 
        memcpy( pt + 1, reader.ptr, squares->elem_size );     
        CV_NEXT_SEQ_ELEM( squares->elem_size, reader );   
        memcpy( pt + 2, reader.ptr, squares->elem_size );   
        CV_NEXT_SEQ_ELEM( squares->elem_size, reader );     
        memcpy( pt + 3, reader.ptr, squares->elem_size );  
        CV_NEXT_SEQ_ELEM( squares->elem_size, reader );         
        //cvPolyLine( cpy, &rect, &count, 1, 1, CV_RGB(0,255,0), 3, CV_AA, 0 );
        cvPolyLine( cpy, &rect, &count, 1, 1, CV_RGB(255,255,0), 1, CV_AA, 0 );//彩色绘制
    }        
    cvShowImage( wndname, cpy );  
    cvReleaseImage( &cpy );
}
void findCircle(IplImage* img,CvMemStorage* storage)
{
	 IplImage* color = NULL; 
	 IplImage* im = NULL; 
    cvNamedWindow ("circle", 1);
	 im=cvCreateImage (cvGetSize(img), IPL_DEPTH_8U, 1);
	 cvCvtColor (img, im, CV_BGR2GRAY);  
	cvSmooth (im, im, CV_GAUSSIAN, 5, 5); 
	 cvShowImage ("tt", im); 
	CvSeq* circles = cvHoughCircles (im, storage, CV_HOUGH_GRADIENT, 2, im->width/3, 300,118, 10, 500);  
	 //color = cvCreateImage (cvGetSize(img), IPL_DEPTH_8U, 3);
	 //cvCvtColor (img, color, CV_GRAY2RGB);  
	 printf("a");
    for (int i = 0; i < circles->total; i++)  
    {  
        float* p = (float*)cvGetSeqElem (circles, i);  
        CvPoint pt = cvPoint (cvRound(p[0]), cvRound(p[1]));  
        cvCircle (img0, pt, cvRound(p[2]), CV_RGB(255, 0, 0), 3, 8, 0);  
    }  
  
    cvShowImage ("circle", img0); 
}
