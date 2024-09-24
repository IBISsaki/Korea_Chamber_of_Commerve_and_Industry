import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression


def main():
    df_1 = pd.read_csv("/home/test/Desktop/AIOT_2024_ROBOT/artificial_intelligence/data/housing.tap", delimiter = "\t")
    print(df_1.head())      # 위쪽 5개의 데이터
    print(df_1.info())
    model = LinearRegression()
    target = 'MEDV'
    feature = ['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT']
    model.fit(df_1[feature], df_1[target])
    
    # 결과 출력
    print(model.intercept_)
    print()
    print(model.coef_)

    df_2 = pd.read_csv("/home/test/Desktop/AIOT_2024_ROBOT/artificial_intelligence/data/housing_predict.tap", delimiter = "\t")
    fitted = model.predict(df_2[feature])
    print(fitted)
    

if __name__ == "__main__":

    main()
