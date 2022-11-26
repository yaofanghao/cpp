// 2022.11.26 demo
// 实现对单个数据输入，利用训练好的模型得到输出结果

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
int class_num = 85;  // class nums of input

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

void writeValue(vector<int> &v,string filePath)
{
   	FILE *pfile=fopen("filePath","wb");

	vector<int>::iterator iter=v.begin();
	char *c=new char[2];
	for(;iter!=v.end();++iter)
	{		
	    c[1]='\n';
		
		if(*iter==0)
		   c[0]='0';
		else
			c[0]='1';
       fwrite(c,1,2,pfile);
	}
	fclose(pfile);
    delete c;
}

bool getRealValue()
{
    FILE *fp;
	int temp;

	if((fp=fopen("real_value.txt","rt"))==NULL)
		return false;
	while(1)
	{
		
		fscanf(fp,"%d",&temp);
		realvalue.push_back(temp);  
		if(feof(fp)) 
			break; 
	}
	return true;
}

double getAccuracy()
{
    if(!getRealValue())
		return 0.0;
	int counter=0;
	int counter1=0;
	for(int i=0;i<realvalue.size();i++)
	{
		if(realvalue.at(i)==predictvalue.at(i))
		{
			counter++;       //测试正确的个数
	    	if(realvalue.at(i)==1)
			  counter1++;
		}
	}
    //cout<<realvalue.size()<<endl;  //目标值为1的记录测试真确的个数
	return counter*1.0/realvalue.size();
}

int main()
{
    cout << "this is predict demo" << endl;

    svm_model *svmModel = svm_load_model("model.txt");
   	// FILE *fp;
	int line=0;
	int temp;
	
	while(1)
	{
		svm_node* input = new svm_node[class_num+1];
		for(int k=0;k<class_num;k++)
		{ 
		 	fscanf(fp,"%d",&temp);  // 这里的fp是预测的txt，对于单个数据需要修改
			input[k].index = k + 1;
			input[k].value = temp/(MAX*1.0);
		}
		input[class_num].index = -1;
		
    	int predictValue=svm_predict(svmModel, input);
		predictvalue.push_back(predictValue);

		cout<<predictValue<<endl;
		if(feof(fp)) 
			break; 
	}



    // predict((char*)"eval.txt");        // predict
	// writeValue(predictvalue,"result.txt");  // write predict value to result.txt
	// double accuracy=getAccuracy();          // get accuracy of predict

	return 0;
}