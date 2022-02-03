# %% [code] {"jupyter":{"outputs_hidden":false},"execution":{"iopub.status.busy":"2022-02-03T02:20:39.083049Z","iopub.execute_input":"2022-02-03T02:20:39.083413Z","iopub.status.idle":"2022-02-03T02:20:40.467315Z","shell.execute_reply.started":"2022-02-03T02:20:39.083377Z","shell.execute_reply":"2022-02-03T02:20:40.466147Z"}}
# This Python 3 environment comes with many helpful analytics libraries installed
# It is defined by the kaggle/python Docker image: https://github.com/kaggle/docker-python
# For example, here's several helpful packages to load

# Kaggle Page: https://www.kaggle.com/mohamudharoon/

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
from sklearn.tree import DecisionTreeRegressor

# Input data files are available in the read-only "../input/" directory
# For example, running this (by clicking run or pressing Shift+Enter) will list all files under the input directory

import os
# for dirname, _, filenames in os.walk('/kaggle/input'):
#     for filename in filenames:
#         print(os.path.join(dirname, filename))
London_Housing_file_data = "/kaggle/input/housing-prices-in-london/London.csv"
house_data = pd.read_csv(London_Housing_file_data)

#From data columns, store the input columns into a list
feature_inputs = ["Area in sq ft", "No. of Bedrooms", "No. of Bathrooms"] 

X = house_data[feature_inputs]  # use the input list as our inputs
y = house_data.Price # store the expected value (Price) into a new variable (y)

#create a model and assign a random number to ensure same result on every run
London_model = DecisionTreeRegressor(random_state = 7)
#Fit data into model
London_model.fit(X, y) #where X is our input and y is our desired output

print("Predicted Price :" , end=" ")
# Print the top 5 result of the predicted price column
print(London_model.predict(X.head()))
# Print the top 5 result of the original price column
print(house_data.Price.head())

# %% [code] {"jupyter":{"outputs_hidden":false}}
