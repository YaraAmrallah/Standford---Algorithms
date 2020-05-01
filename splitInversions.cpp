/*
 * splitInversions.cpp
 *
 *  Created on: May 1, 2020
 *      Author: yaraa
 */

long long unsigned int sortAndCountSplitInversions (int arr[], long long unsigned int starts, long long unsigned int ends)
{
	long long unsigned int inversionsCounter = 0;
	if(ends > starts)
	{
		// Find the middle of the array
		// 0 + 5-0/2 = 2
		// 0 + 6-0/2 = 3
		long long unsigned int mid = starts + (ends - starts)/2;

		// Pass both halves to be sorted recursively
		inversionsCounter += sortAndCountSplitInversions(arr, starts, mid);
		inversionsCounter += sortAndCountSplitInversions(arr, (mid + 1), ends);

		// Merging Steps
		// 1 - Construct two arrays
		int length1 = mid - starts + 1;
		int length2 = ends - mid;
		int leftArray[length1];
		int rightArray[length2];

		// 2 - Fill each array with the elements
		for(int i = 0; i < length1; i++)
		{
			leftArray[i] = arr[starts + i];
		}

		for(int j = 0; j < length2; j++)
		{
			rightArray[j] = arr[mid + 1 + j];
		}

		// Merge both arrays in order
		int i = 0;
		int j = 0;
		int k = starts;

		while(i < length1 && j < length2)
		{
			if(leftArray[i] < rightArray[j])
			{
				arr[k] = leftArray[i];
				i++;
			}
			else
			{
				arr[k] = rightArray[j];
				j++;

				inversionsCounter += length1 - i;
			}

			k++;
		}

		// add the rest of the elements

		while(i < length1)
		{
			arr[k] = leftArray[i];
			i++;
			k++;
		}

		while(j < length2)
		{
			arr[k] = rightArray[j];
			j++;
			k++;
		}
	}

	return inversionsCounter;
}


