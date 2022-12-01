// 2022.11.26-11.29 demo
// 实现制作txt数据集和SVM模型的训练

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
svm_problem prob;
svm_model *svmModel;
list<svm_node*> xList;
list<double>  yList;
const int nTstTimes=10;
int trainNum=0;

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
    clock_t t1,t2;
	FILE *fp;
	int k;
	int line=0;
	float temp;	

	// 开始训练SVM模型
	cout<<"strat training..."<<endl;
	t1=clock(); 
	if((fp=fopen((char*) "train.txt","rt"))==NULL)
		return -1;
	while(1){
		svm_node* features = new svm_node[class_num+1];		 
		for(k=0;k<class_num;k++){
		 	fscanf(fp,"%f",&temp); 	   
			std::cout << "line: " << line; 
			std::cout << " temp:" << temp << std::endl;
			features[k].index = k + 1;
			features[k].value = temp;
		}			
		features[class_num].index = -1;

		fscanf(fp,"%f",&temp);
		xList.push_back(features);
		yList.push_back(temp);    
		line++;
		trainNum=line;
		if(feof(fp)) 
			break; 
	}
   
    setParam();
	prob.l=line;
	prob.x=new svm_node *[prob.l];  // 对应的特征向量
	prob.y = new double[prob.l];    // 放的是值
	int index=0;	
	while(!xList.empty()){
		prob.x[index]=xList.front();
		prob.y[index]=yList.front();
		xList.pop_front();
		yList.pop_front();
		index++;
	}
	// std::cout<<prob.l<<"list end"<<std::endl;
	std::cout << "----------" << std::endl;
	svmModel=svm_train(&prob, &param);

	// 保存模型
	svm_save_model("model.txt",svmModel);
	std::cout << "----------" << std::endl;
	std::cout<<"success save SVM-model to model.txt"<<std::endl;

	//释放空间
	delete  prob.y;
	delete [] prob.x;
	svm_free_and_destroy_model(&svmModel);

    t2=clock();	
	std::cout << "----------" << std::endl;
 	std::cout << "training data number: " << trainNum<<std::endl;
	std::cout << "training time: " << 1.0*(t2-t1)/nTstTimes << "ms" << std::endl; 
	std::cout << "traning done!" << std::endl;
	std::cout << "----------" << std::endl;

	system("pause");
	return 0;
}