//заголовочный файл программы обработки видео
#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

// namespaces объявления
using namespace cv;
using namespace std;

Mat Image;
Mat gray;

void help()
{
	printf("Тест захвата видеоустройства:\n");
	printf("Нажать q: выход из программы\n");
}

int main( int argc, char** argv )
{
	char key = 0;
    // check for failure
	VideoCapture capture(0);
	if (!capture.isOpened()) {
		printf("Не могу открыть устройство или видеофайл!\n");
		return 1;
	}

    // установить свойства для устройства видеозахвата
	capture.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

	namedWindow("Camera Video", CV_WINDOW_AUTOSIZE);
	namedWindow("Processed Video", CV_WINDOW_AUTOSIZE);

	while( key != 'q')
	{
		capture >> Image;
		cvtColor(Image, gray, CV_BGR2GRAY);
		imshow("Camera Video",Image);
		imshow("Processed Video", gray);
		key = waitKey(25);
	}
	return 0;
}
