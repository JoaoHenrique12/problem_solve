import pandas as pd

"""
CONVERT CATEGORICAL VARIABLES INTO NUMBERS
    df = pd.get_dummies(df, columns=["Sex","Pclass","Embarked"])


FIND ALL NOT NUMERIC
    df.describe(include=[object])

SUM NA
    df.isna().sum()


Removing specific rows

for x in df.index:
  if df.loc[x, "Duration"] > 120:
    df.drop(x, inplace = True)


Removing duplicated rows
df.drop_duplicates(inplace = True)
df['Maxpulse'].drop_duplicates(inplace = True)

Find duplicateds
print(df.duplicated())
print(df['Poem'].duplicated())

"""


def locate_functions():
    df_train = pd.read_csv('train.csv')

    # Locate lines
    print("\n\nLOC\n")
    print(df_train.loc[0])

    print("\n\nLOC[0,2]\n")
    print(df_train.loc[[0, 2]])
    print("\n------------------------\n")

    print("\n\nLOC[3,'Poem']\n")
    print(df_train.loc[3, 'Poem'])

    print("\n\niloc[1:5,0:1] LINE, COLUMNS\n")
    print(df_train.iloc[1:5, 0:1])

    # print(df_train.iloc[[1,2,3],0:1])


def analyzing_data():
    df_train = pd.read_csv('train.csv')
    print(df_train.head(10))
    print("\n------------------------\n")
    print(df_train.tail())
    print("\n------------------------\n")
    print(df_train.info())


def create_data_frame_from_json():
    data = {
        "calories": [420, 380, 390],
        "duration": [50, 40, 45]
    }

    df = pd.DataFrame(data)

    print(df)


def index_to_name():
    data = {
        "calories": [420, 380, 390],
        "duration": [50, 40, 45]
    }

    df = pd.DataFrame(data, index=["day1", ] + ['GenericName'] * 2)

    print(df)

    print("\n------------------------\n")
    print(df.columns[0] + " " + df.columns[1])
    print(df.loc["day1"])


def options():
    pd.options.display.max_rows = 19
    pd.options.display.max_columns = 2
    df = pd.read_csv('train.csv')
    print(df)


def data_cleaning_part1():
    '''
    Bad data could be:
        Empty cells
        Data in wrong format
        Wrong data
        Duplicates

            -> DROP NA <-

            df[df['Poem'].isna()] # show where is NA
    '''

    df = pd.read_csv("train.csv")

    print("Original DataFrame:")
    print(df)

    df_middle = df.dropna()

    print("\nDataFrame after dropping rows with missing values:")
    print(df_middle)

    # df['Poem'].mean()
    # df['Poem'].median()
    # df['Poem'].mode()[0]

    print(df[df['Poem'].isna()])  # show where is NA
    df["Poem"].fillna("", inplace=True)


def load_json():
    data = {
        "Duration": {
            "0": 60,
            "1": 60,
            "2": 60,
            "3": 45,
            "4": 45,
            "5": 60
        },
        "Pulse": {
            "0": 110,
            "1": 117,
            "2": 103,
            "3": 109,
            "4": 117,
            "5": 102
        },
        "Maxpulse": {
            "0": 130,
            "1": 145,
            "2": 135,
            "3": 175,
            "4": 148,
            "5": 127
        },
        "Calories": {
            "0": 409,
            "1": 479,
            "2": 340,
            "3": 282,
            "4": 406,
        }
    }
    df = pd.DataFrame(data)

    print(df)
