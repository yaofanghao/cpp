import numpy as np
import pandas as pd
from sklearn.model_selection import StratifiedShuffleSplit
from sklearn.model_selection import cross_val_score
from sklearn.tree import DecisionTreeRegressor
import time

all = pd.read_csv('all.csv')

split = StratifiedShuffleSplit(n_splits = 1, test_size = 0.2, random_state = 42)
for train_index, test_index in split.split(all, all['output']):
    strat_train_set = all.loc[train_index]
    strat_test_set = all.loc[test_index]

train_data = strat_train_set.drop('output', axis = 1)
train_label = strat_train_set['output']

def  display_scores(scores):
    print('Scores: ', scores)
    print('Mean: ', scores.mean())
    print('Standard deviation: ', scores.std())


from sklearn.svm import SVC
from sklearn.model_selection import cross_val_score

# svm_clf = SVC(C=10, decision_function_shape='ovr', kernel='rbf')
svm_clf = SVC()
svm_clf.fit(train_data, train_label)
scores = cross_val_score(svm_clf, train_data, train_label,cv=10)
display_scores(scores)

precision = cross_val_score(svm_clf,train_data, train_label,scoring='precision_weighted',cv=10)
print("Precision = ",round(100*precision.mean(),5),'%')

recall = cross_val_score(svm_clf,train_data, train_label,scoring='recall_weighted',cv=10)
print("Recall = ",round(100*recall.mean(),5),'%')

F1 = cross_val_score(svm_clf,train_data, train_label,scoring='f1_weighted',cv=10)
print("F1 = ",round(100*F1.mean(),5),'%')

start = time.time()

test_data=np.array([[1000,0,1,2,0.2,0.3,4]])
predict_result=svm_clf.predict(test_data)
print(predict_result)
# print("{}".format(all['output'][predict_result]))

end = time.time()

print("预测时间:%.8f秒"%(end-start))