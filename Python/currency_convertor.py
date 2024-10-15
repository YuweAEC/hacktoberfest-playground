from PyQt5 import QtCore, QtGui, QtWidgets
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from datetime import datetime
import sys

now=str(datetime.now())
now=now[0:10]
## ************      Funtions       *********************
def curexnow(now=now): 
    try:
        df1=pd.read_csv("CurEx_"+now+".csv")
    except Exception as e: 
        print(e)
        ls=pd.read_html("https://www.x-rates.com/historical/?from=USD&amount=1&date="+now)
        # pd.read_html returns a list of all tables(dataframes) on a web page
        df1=ls[1]       # assigning the dataframe at '1' in ls to dtf
        df1.rename(columns={"US Dollar":"Currency","1.00 USD":"Value/USD","inv. 1.00 USD":"USD"},inplace=True)
        df1.drop("USD",axis=1,inplace=True)
        df1.loc[52,:]=["US Dollar",1.00000]
        df1.to_csv("CurEx_"+now+".csv",index=False)
    return df1

def convert():
    dtf=curexnow()
    from_cur=dd_from.currentText()
    to_cur=dd_to.currentText()
    from_amt=float(inp_from.text())
    from_cur=dtf.loc[dtf["Currency"]==from_cur,"Value/USD"]
    from_cur = float(from_cur)
    to_cur=float(dtf.loc[dtf["Currency"]==to_cur,"Value/USD"])
    to_amt=((from_amt*to_cur)/from_cur)

    out_to.setText(str(to_amt))

def plot(self):
    df=dtf.loc[0:22]
    df1=dtf.loc[22:55]
    plt.barh(df["Currency"],df["Value/USD"],color="blue")
    plt.grid(color="black",alpha=0.3,linestyle="--",linewidth=1)
    plt.title("Currency")


    plt.barh(df1["Currency"],df1["Value/USD"],color="red")
    plt.grid(color="black",alpha=0.3,linestyle="--",linewidth=1)
    plt.title("Currency")


    plt.show()

dtf=curexnow()
lst=dtf.loc[:,"Currency"].tolist()


app = QtWidgets.QApplication([])

MainWindow=QtWidgets.QMainWindow()
MainWindow.setObjectName("MainWindow")
MainWindow.resize(700, 463)
MainWindow.setWindowTitle("Converter")

centralwidget = QtWidgets.QWidget(MainWindow)

font = QtGui.QFont()
font.setPointSize(22)
heading = QtWidgets.QLabel(centralwidget)
heading.setGeometry(QtCore.QRect(230, 40, 261, 41))
heading.setFont(font)
heading.setText("Currency Converter")

font = QtGui.QFont()
font.setPointSize(18)
label_from = QtWidgets.QLabel(centralwidget)
label_from.setGeometry(QtCore.QRect(20, 150, 84, 31))
label_from.setFont(font)
label_from.setText("From :")

label_to = QtWidgets.QLabel(centralwidget)
label_to.setGeometry(QtCore.QRect(20, 220, 84, 31))
label_to.setFont(font)
label_to.setText("To :")

dd_from = QtWidgets.QComboBox(centralwidget)
dd_from.setGeometry(QtCore.QRect(110, 150, 250, 32))
dd_from.addItems(lst)
dd_from.setEditable(1)

dd_to = QtWidgets.QComboBox(centralwidget)
dd_to.setGeometry(QtCore.QRect(110, 220, 250, 32))
dd_to.addItems(lst)
dd_to.setEditable(1)

inp_from = QtWidgets.QLineEdit(centralwidget)
inp_from.setGeometry(QtCore.QRect(390, 150, 281, 32))

out_to = QtWidgets.QLineEdit(centralwidget)
out_to.setGeometry(QtCore.QRect(390, 220, 281, 32))

button_cnv = QtWidgets.QPushButton(centralwidget)
button_cnv.setGeometry(QtCore.QRect(440, 410, 131, 41))
button_cnv.setFont(font)
button_cnv.clicked.connect(lambda:convert())
button_cnv.setText("Convert")

button_veiw = QtWidgets.QPushButton(centralwidget)
button_veiw.setGeometry(QtCore.QRect(20, 410, 131, 41))
button_veiw.setFont(font)
button_veiw.clicked.connect(lambda:Database.show())
button_veiw.setText("View Data")

MainWindow.setCentralWidget(centralwidget)

Database=QtWidgets.QMainWindow()

Database.resize(500, 730)
Database.setWindowTitle("Today's Currency Exchange Rates")

tableView = QtWidgets.QTableWidget(Database)
tableView.setGeometry(QtCore.QRect(10, 10, 470, 641))
tableView.setRowCount(54)
tableView.setColumnCount(2)
tableView.setColumnWidth(0,250)
tableView.setColumnWidth(1,170)
tableView.setHorizontalHeaderLabels(["Currency","Value/USD"])

for x in range(0,52):
    for i in [0,1]:
        if i==0:
            item=QtWidgets.QTableWidgetItem(str(dtf.iloc[x,i]))
            tableView.setItem(x,i,item)
        else:
            item=QtWidgets.QTableWidgetItem(str("%.5f"%round(dtf.iloc[x,i],5)))
            item.setTextAlignment(QtCore.Qt.AlignHCenter)
            tableView.setItem(x,i,item)

font = QtGui.QFont()
font.setPointSize(18)

pushButton_2 = QtWidgets.QPushButton(Database)
pushButton_2.setGeometry(QtCore.QRect(330, 670, 140, 41))
pushButton_2.setFont(font)
pushButton_2.clicked.connect(lambda:plot(plot))
pushButton_2.setText("Show Graph")

MainWindow.show()

app.exec()
