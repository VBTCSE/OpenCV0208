// OpenCV0208

// The purpose of this program is to display a live stream from a camera.
// The color video from the camera is first converted to a monochromatic video.
// Then, the monochromatic video is run through the Canny edge detector to create an edge detection video.


// Correct usage: OpenCV0208.exe rawvideo_image_filename monovideo_image_filename edgedetection_image_filename
// The filenames are for three output files:
// image frame from the raw video
// image frame from the monochromatic video
// image frame from the edge detection video



// Refer to http://docs.opencv.org/master for relevant documentation.


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	//-------------------------------------------------------------------------
	// Test whether the number of arguments (argc) is not equal to 4.
	// If it is not equal to 4, output a message showing what the correct
	// usage of this program is, then pause for the user response and return -1.
	//-------------------------------------------------------------------------

	if (argc != 4)
	{
		cout << " Usage: " << argv[0] << "rawvideo_image_filename monovideo_image_filename edgedetection_image_filename" << endl;
		system("pause");
		return -1;
	}







	//-------------------------------------------------------------------------
	// Declare char* (c-strings) to hold the three image filenames.
	//-------------------------------------------------------------------------

	char* filenameRawVideo = argv[1];		// output file name for raw video frame
	char* filenameMonochromatic = argv[2];	// output file name for monochromatic video frame
	char* filenameEdgeDetect = argv[3];		// output file name for edge detection video frame







	//-------------------------------------------------------------------------
	// Declare a VideoCapture object to provide the video input stream.
	//-------------------------------------------------------------------------

	VideoCapture cap;







	//-------------------------------------------------------------------------
	// Use the open function of the VideoCapture class to open the video
	// from a camera whose index is 0
	//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
	cap.open(0);







	//-------------------------------------------------------------------------
	// Check whether the video capture device was opened.
	// Use the isOpened function of the VideoCapture class.
	//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
	if (!cap.isOpened())
	{
		cerr << "Could not open capture device." << endl;
		system("pause");
		return -1;
	}







	//-------------------------------------------------------------------------
	// Declare three Mat objects to contain:
	// 1. the image of each frame from the video input stream,
	// 2. the image of each frame from the monochromatic video,
	// 3. the image of each frame from the edge detection video.
	//-------------------------------------------------------------------------

	Mat frame;
	Mat imageGray;
	Mat imageEdgeDetect;







	//-------------------------------------------------------------------------
	// Use the namedWindow function three times to create three windows for 
	// displaying each of the three videos.
	//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
	namedWindow("Raw Video", WINDOW_AUTOSIZE);
	namedWindow("Monochromatic Image", WINDOW_AUTOSIZE);
	namedWindow("Edge Detection Image", WINDOW_AUTOSIZE);







	//-------------------------------------------------------------------------
	// Use a "forever" loop to step through each frame of the video file.
	//-------------------------------------------------------------------------

	for (;;)
	{

		//-------------------------------------------------------------------------
		// Use the extraction operator (>>) to input one frame from the video stream
		// (the VideoCapture object allocated above), into the image (the Mat object
		// allocated above).
		//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
		cap >> frame;







		//-------------------------------------------------------------------------
		// Perform the edge detection.
		//
		// First, use the cvtColor function to convert the input frame into
		// a monchromatic image (color to gray-scale conversion).
		//
		// Second, use the Canny function to perform edge detection on the gray-scale
		// image.  The gray-scale image is the input, the edge-detect image is the output.
		//
		// Experiment with values of the first and second threshold (see the documentation).
		// The first threshold should be smaller than the second threshold.  Typical values 
		// could be 10 and 100 or 20 and 70.  Try different values to find a set that gives
		// a clear meaningful edge-detection image.
		//
		// Finally, try a suggested aperture size of 3 for the Sobel operator and a flag of true
		// for the L2gradient.  You can try other values, to see what the effect is.
		//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
		cvtColor(frame, imageGray, COLOR_BGR2GRAY);
		Canny(imageGray, imageEdgeDetect, 20, 70, 3, true);







		//-------------------------------------------------------------------------
		// Use the imshow function three times to display the three video images
		// in each of the three windows created above.
		//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
		imshow("Raw Video", frame);
		imshow("Monochromatic Image", imageGray);
		imshow("Edge Detection Image", imageEdgeDetect);







		//-------------------------------------------------------------------------
		// Use the waitKey function to wait 33 milliseconds, or until the user 
		// presses a key, in the video window.  Use the return value of waitKey
		// to determine whether a key was pressed by the user.  If a key was pressed,
		// break out of the "forever" loop, ending the program.
		//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
		int n = waitKey(33);

		if (n < 255)
		{
			break;
		}


	}







	//-------------------------------------------------------------------------
	// Use the imwrite function three times to write the three images from
	// each of the three videos.
	//-------------------------------------------------------------------------
#pragma message ("*** add code ***")	// TODO: add your code here.  Replace this line with your code
	imwrite(filenameRawVideo, frame);
	imwrite(filenameMonochromatic, imageGray);
	imwrite(filenameEdgeDetect, imageEdgeDetect);





	return 0;
}