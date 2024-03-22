import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

inFilename = './data/yes24_crawlingData.xlsx'
outFilename = './data/yes24_dataframe.xlsx'

df_overTwentyThousand = pd.read_excel(inFilename, 'IT 서적 순위',index_col=None)

#df_overTwentyThousand = df_overTwentyThousand[df_overTwentyThousand['가격']>= 20000]

df_overTwentyThousand = df_overTwentyThousand.loc[:,['책이름','출판사','출판일','가격']]

x_data = df_overTwentyThousand['출판일']
y_data = df_overTwentyThousand['가격']
colorAry = [np.random.choice(['red','green','blue','gold']) for _ in range(len(x_data))]

plt.bar(x_data,y_data,color=colorAry)
plt.show()

writer = pd.ExcelWriter(outFilename)
df_overTwentyThousand.to_excel(writer,sheet_name='books',index=False)
writer.close()
print("save. ok")
