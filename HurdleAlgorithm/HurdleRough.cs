///<summary>
/// This is for collecting median values in the array
///</summary>
public int SortingAverageIndexs(int desiredCount, int[] original, ref Collection<int> output)
{
	int ret = 0;
	double walker = (double)(spliteLine.Length - 2.0) / (double)((desiredCount - 2.0) * 2.0);
	double step = walker * 2.0;
	int istep = (int)Math.Round(step);
	if(original.Length / desiredCount >= 2 || step - (int)step >= 0.5)
	{
		for(int i = 0; i < original.Length; i++)
		{
			if(output.Count == desiredCount) break;
			if(i == 0 || i == original.Length - 1)
			{
				output.Add(original[i]);
			}else if((int)walker == i)
			{
				output.Add(original[i]);
			}else if((int)walker + istep == i)
			{
				output.Add(original[i]);
				walker = (int)walker + istep;
			}
		}
	}else{
		int differenceBTWnumbers = original.Length - desiredCount;
		int skip = 0;
		int skipcheck = 0;
		for(int i = 0; i < original.Length; i++)
		{
			if(output.Count == desiredCount) break;
			if(i == 0 || i == original.Length - 1)
			{
				output.Add(original[i]);
			}else if((original.Length/(differenceBTWnumbers==0?1:differenceBTWnumbers * 2)) == skipcheck)
			{
				if(differenceBTWnumbers != 0 )
				{
					skipcheck = 0;
					walker = (int)walker + istep;
					if(skip == differenceBTWnumbers)
					{
						Log("Already Skipped All");
					}else{
						Log("Skip");
						skip++;
					}
				}
			}else if((int)walker == i)
			{

			}else if((int)walker + istep == i)
			{
				output.Add(original[i]);
				walker = (int)walker + istep;
				skipcheck++;
			}
		}
	}
	return ret;
}

