import pandas

sr2 = pandas.Series([50,60,70,80],index=['다현','정연','쯔위','사나'])
sr3 = pandas.Series([11,22,33,44],index=['다현','사나','모모','재남'])
sr1 = pandas.Series([10,20,30,40],index=['다현','정연','쯔위','사나'])

sr12 = sr1 + sr2
print(sr12, '\n')

sr13 = sr1 + sr3
print(sr13)