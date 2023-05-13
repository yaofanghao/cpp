#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <zbar.h>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace cv;
using namespace zbar;

extern void barcode_identify(ImageScanner, Mat);