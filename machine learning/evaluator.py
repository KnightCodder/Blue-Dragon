import joblib
import pandas as pd

model = joblib.load('models/linear_regression_model.pkl')

data = pd.read_csv('data/temp.csv', header=None)

X = data.drop(columns=9, axis=1)
Y = data[9]

prediction = model.predict(X)

print("evaluation : " , prediction)
