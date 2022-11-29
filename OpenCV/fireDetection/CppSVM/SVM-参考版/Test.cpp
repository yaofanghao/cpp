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

void setParam()
{
    param.svm_type = C_SVC;
	param.kernel_type = RBF;
	param.degree = 3;
	param.gamma = 0.5;
	param.coef0 = 0;
	param.nu = 0.5;
	param.cache_size = 40;
	param.C = 500;
	param.eps = 1e-3;
	param.p = 0.1;
	param.shrinking = 1;
	// param.probability = 0;
	param.nr_weight = 0;
	param.weight = NULL;
    param.weight_label =NULL;
}

void train(char *filePath)
{
	
	FILE *fp;
	int k;
	int line=0;
	int temp;
 
	if((fp=fopen(filePath,"rt"))==NULL)
		return ;
	while(1)
	{
		 svm_node* features = new svm_node[85+1];
		 
		 for(k=0;k<85;k++)
		 {
		 	fscanf(fp,"%d",&temp);
           
			cout << "training... line" << line; 
			cout << " temp:" << temp << endl;					
	         
			features[k].index = k + 1;
			features[k].value = temp/(MAX*1.0) ;
		}
			
		features[85].index = -1;


		fscanf(fp,"%d",&temp);
		xList.push_back(features);
		yList.push_back(temp);
    
		line++;
		trainNum=line;
		if(feof(fp)) 
			break; 
	}


   	
   
    setParam();
	prob.l=line;
	prob.x=new svm_node *[prob.l];  //对应的特征向量
	prob.y = new double[prob.l];    //放的是值
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
}

void predict(char *filePath)
{
   svm_model *svmModel = svm_load_model("model.txt");

   	FILE *fp;
	int line=0;
	int temp;

	if((fp=fopen(filePath,"rt"))==NULL)
		return ;
	

	while(1)
	{
		 svm_node* input = new svm_node[85+1];
		 for(int k=0;k<85;k++)
		 {
		 	fscanf(fp,"%d",&temp);
			input[k].index = k + 1;
			input[k].value = temp/(MAX*1.0);
		}
		input[85].index = -1;


		
    	int predictValue=svm_predict(svmModel, input);
		predictvalue.push_back(predictValue);

		cout<<predictValue<<endl;
		if(feof(fp)) 
			break; 
	}

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

	if((fp=fopen("tictgts2000.txt","rt"))==NULL)
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
    clock_t t1,t2,t3;
	
	cout<<"请稍等待..."<<endl;
	t1=clock();
	train("ticdata2000.txt");   //训练
    t2=clock();
	
    predict("ticeval2000.txt");        //预测
	t3=clock();
	writeValue(predictvalue,"result.txt");  //将预测值写入到文件
	double accuracy=getAccuracy();          //得到正确率
	cout<<"训练数据共:"<<trainNum<<"条记录"<<endl;
	cout<<"测试数据共:"<<realvalue.size()<<"条记录"<<endl;
	cout<<"训练的时间:"<<1.0*(t2-t1)/nTstTimes<<"ms"<<endl;
	cout<<"预测的时间:"<<1.0*(t3-t2)/nTstTimes<<"ms"<<endl;
    cout<<"测试正确率为:"<<accuracy*100<<"%"<<endl;
    
  

	return 0;
}