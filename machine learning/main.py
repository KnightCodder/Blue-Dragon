import joblib
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

data = pd.read_csv('data/trainingData.csv', header=None)

X = data.drop(columns=9, axis=1)
Y = data[9]

# print(X.head())
# print(Y.head())

X_train, X_test, Y_train, Y_test = train_test_split( X, Y, test_size = 0.1, stratify = None, random_state = 1)

model = LinearRegression()

model.fit(X_train, Y_train)

Y_pred = model.predict(X_test)

print("coeffiecients: ", model.coef_)
print("Intercept: ", model.intercept_)

mse = mean_squared_error(Y_test, Y_pred)
r2 = r2_score(Y_test, Y_pred)
print("Mean Squared Error: ", mse)
print("R^2 Score: ", r2)


# Assuming 'model' is your trained Linear Regression model

# Define the file path where you want to save the model
file_path = 'models/linear_regression_model.pkl'

# Save the model to the file
joblib.dump(model, file_path)

# Optionally, you can also save the model coefficients and intercept separately
coefficients_path = 'models/linear_regression_coefficients.npy'
intercept_path = 'models/linear_regression_intercept.npy'

np.save(coefficients_path, model.coef_)
np.save(intercept_path, model.intercept_)

