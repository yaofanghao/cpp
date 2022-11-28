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
list<double>  yList ;
const int MAX=10;
const int nTstTimes=10;
vector<int> predictvalue;
vector<int> realvalue;
int trainNum=0;

// -------setting----------
// int class_num = 3;  // class nums of input

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
    clock_t t1,t2,t3;
	
	cout<<"请稍等待..."<<endl;
	t1=clock();
	// train((char*)"train.txt");   // train

	FILE *fp;
	int k;
	int line=0;
	float temp;
 
	if((fp=fopen("train.txt","rt"))==NULL)
		return -1;
	while(1)
	{
		svm_node* features = new svm_node[3+1];
		 
		for(k=0;k<3;k++)
		{
		 	fscanf(fp,"%f",&temp); 	         
			features[k].index = k + 1;
			features[k].value = temp;
			cout << "line: " << line; 
			cout << " temp:" << temp << endl;	
		}			
		features[3].index = -1;

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
	while(!xList.empty())
	{
		prob.x[index]=xList.front();
		prob.y[index]=yList.front();
		xList.pop_front();
		yList.pop_front();
		index++;
	}
	//std::cout<<prob.l<<"list end\n";
	svmModel=svm_train(&prob, &param);

	//std::cout<<"\n"<<"over\n";
	//保存model
	svm_save_model("model.txt",svmModel);

	//释放空间
	delete  prob.y;
	delete [] prob.x;
	svm_free_and_destroy_model(&svmModel);




    t2=clock();
	
 	cout<<"训练数据共:"<<trainNum<<"条记录"<<endl;
	cout<<"训练的时间:"<<1.0*(t2-t1)/nTstTimes<<"ms"<<endl; 

	return 0;
}