// 2022.11.28-11.29 demo
// 实现对输入一组数据，利用训练好的SVM模型得到输出结果（0/1）

#include "svm.h"
#include "svm.cpp"
#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif

svm_parameter param;
svm_model *svmModel;

// -------模型参数设置----------
// 输入数据集的类别个数 class_num
// 此处为3，表示图像的圆形度、偏心率、熵值
const int class_num = 3;  
void setParam()
{
    param.svm_type = C_SVC;  // type of RBF
	param.kernel_type = RBF;  // RBF kernal function exp(-γ×|u-v|^2)
	param.degree = 3;  // params of kernal function
	param.gamma = 0.5;  
	param.coef0 = 0;
	param.nu = 0.5;  
	param.cache_size = 40;  // cache size of program (MB)
	param.C = 500;
	param.eps = 1e-3;
	param.p = 0.1;
	param.shrinking = 1;
	// param.probability = 0;
	param.nr_weight = 0;
	param.weight = NULL;
    param.weight_label =NULL;
}

int main()
{
    std::cout << "this is a predict demo" << std::endl;
	std::cout << "num 0-roundIndex; " <<
		"num 1-eccIndex; " <<
		"num 2-entropy " << std::endl;
	std::cout << "----------" << std::endl;

    svm_model *svmModel = svm_load_model("model.txt");
	int line=0;
	float temp;

	svm_node* input = new svm_node[class_num+1];	
	for(int k=0;k<class_num;k++){
		input[k].index = k + 1;
		std::cout << "enter num " << k << ": ";
		std::cin >> temp;
		input[k].value = temp;
	}
	input[class_num].index = -1;

	std::cout << "input is: ";
	for(int k=0;k<class_num;k++){
		std::cout << input[k].value << " ";
	}

	// 得到预测值 0/1
	std::cout << std::endl;
	std::cout << "start predict......" << std::endl;
	std::cout << "----------" << std::endl;
	int predictValue=svm_predict(svmModel, input);
	std::cout << "predict result: " << predictValue << std::endl;
	if (predictValue){	
		std::cout << "Find fire!" << std::endl;
	}
	else{
		std::cout << "No fire!" << std::endl;
	}
	std::cout << "----------" << std::endl;

	return 0;
}