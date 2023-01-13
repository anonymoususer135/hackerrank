void makeCombiUtil(vector<int> v, vector<vector<int> >& ans,
    vector<int>& tmp, int n, int left, int k)
{
    // Pushing this vector to a vector of vector
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }

    // i iterates from left to n. First time
    // left will be 1
    for (int i = left; i <= n; ++i)
    {
 //       tmp.push_back(v[i-1]);
        tmp.push_back(i-1); //index not value
        makeCombiUtil(v, ans, tmp, n, i + 1, k - 1);

        // Popping out last inserted element
        // from the vector
        tmp.pop_back();
    }
}

// Prints all combinations of size k of numbers
// from 1 to n.
vector<vector<int> > makeCombi(vector<int> v, int n, int k)
{
    vector<vector<int> > ans;
    vector<int> tmp;
    makeCombiUtil(v, ans, tmp, n, 1, k);
    return ans;
    vector <int> comb;
    vector <vector<int>> combs;
}

int sum_positive(int first, int second) {
    return first + (second > 0 ? second : 0);
}

std::vector<int> slice(std::vector<int> &v, int m, int n)
{
    std::vector<int> vec(n - m + 1);
    std::copy(v.begin() + m, v.begin() + n + 1, vec.begin());
    return vec;
}

vector<int> maxSubarray(vector<int> arr) {

    vector <vector <int>> subSequenceList;
    vector <int> subSequence;
    vector <vector <int>> permutationList;
    vector <vector <int>> subArrayList;
    vector<vector<int>> ans;
    vector <vector<int>>ansBackup;
    vector <int> subArray;
    vector <int> eachSum;
    vector<int>allSums;
    vector <int> finalSums;
    vector <int> working;
    int maxSubArraySum;
    int sum=0;
    
    working=arr;
    size_t previousIndex=0;
  //  std::cout<<"Hello world" << std::endl;
    for (size_t i=0; i<working.size(); i++) {
        if (i==0 && working[i]<0)
            {
            subArray.push_back(working[i]);
            continue;
            }
        if (working[i] >= 0)
          {
              sum+=working[i];
              subArray.push_back(sum);
 //             previousIndex=i;
              continue;
          }
          else {
              if (sum+working[i] >= 0) {
                  sum+=working[i];
                  subArray.push_back(sum);
   //               std::cout<<"hello world1"<<std::endl;
              }
              else {
                  sum=0;
   //               std::cout<<"hello world2"<<std::endl;
              }
          }
    }
    
    maxSubArraySum = *max_element(subArray.begin(), subArray.end());
 //   std::cout<<"hello world3 "<< subArray.size() <<  std::endl;
/*  
    for (int i: subArray) {
       std::cout << i << " ";
    }
    std::cout<<std::endl;
 */   
    /*
    for (int i=0; i< arr.size();i++)
        {
            subArray.push_back(arr[i]);
            subArrayList.push_back(subArray);
            subArray.clear();
            subArray.shrink_to_fit();        
        }
        */
    subArray.clear();
    subArray.shrink_to_fit();    
    int n=0;
    int accBegin=0;
    int accEnd=0;
    int countSubArray=1;
    int sizeSubArray=1;
  
    
     
    
    /*
    while (n<arr.size()) {
    */
        /*
        accEnd=n;
        accBegin=0;
        while (accEnd<=n) {
        sum=std::accumulate(arr.begin()+accBegin, arr.begin()+accEnd,decltype(arr)::value_type(0));
        eachSum.push_back(sum);
        accBegin++;
        accEnd++;
        }
        */
    /*
    for (int i = 0; i < arr.size(); i++) {
        subArray.push_back(arr[i]);
        sizeSubArray++;
        for (int j = i+1; j < arr.size(); j++) {
            if (sizeSubArray<=countSubArray) {
                subArray.push_back(arr[j]);
                sizeSubArray++;
            }
            else {
                break;
            }
        }
        sizeSubArray=1;
        if (subArray.size()==countSubArray)
            subArrayList.push_back(subArray);
        subArray.clear();
        subArray.shrink_to_fit();
    }
    
     countSubArray++;
     
     n++;
    }
    
    */
 //   std::cout<<eachSum.size()<<endl;
//   maxSubArraySum = *max_element(eachSum.begin(), eachSum.end());
    
    
    /*
    cout << "--------------------------"<<endl;
    for (int i=0;i<subArrayList.size();i++) {
        for (int x: subArrayList[i]) {
            
        std::cout<<x<<" ";
        }
        std:: cout << std:: endl;
        
    }
    */
    /*
    for (vector<int> i: subArrayList)
    {
        
        sum=std::accumulate(i.begin(), i.end(),decltype(i)::value_type(0));
        allSums.push_back(sum);
    }
    maxSubArraySum = *max_element(allSums.begin(), allSums.end());
    */
 //   int maxSubArraySum;
    int maxSubSequenceSum;
    
    //To get the max subsequence sum, all is needed to
    //add all those elements from arr that are > 0
    
    //if every element is < 0, then the max negative is largest
    //if every element is <=0, then max is 0
    //if there is at least one > 0, then throw away all <0, sum the positive
    
    bool allNegative=false;
    bool atLeastOnePostive=false;
    //all above are mutually exclusive, only one can be true;
    //scan arr
    
    for (int i: arr) {
        if (i<0)
            continue;
        atLeastOnePostive=true;
        break;
    }
    allNegative=true;
       
    maxSubSequenceSum=0;
    if (atLeastOnePostive)
         maxSubSequenceSum=accumulate(arr.begin(), arr.end(), 0, sum_positive);
         
         
    /*
        for (int i: arr) {
           if (i>0) 
               maxSubSequenceSum+=i;
        }
    */
    else 
     { 
       maxSubSequenceSum = *max_element(arr.begin(), arr.end());
       maxSubArraySum=maxSubSequenceSum;
     }
 //   std::cout<<maxSubArraySum<<std::endl;
    
    //Now we will do subsequence
    
    /*
    vector <int> v;
    vector <int> total;
    v=arr;
    n=v.size(); 
    for (size_t k = 1; k < v.size()+1; k++) {
    ans = makeCombi(v, n, k);
    ansBackup.insert(ansBackup.end(),ans.begin(),ans.end());
    }


    subSequence.clear();
    subSequence.shrink_to_fit();
    
    */
    
    /*
    for (vector <int> i:ansBackup) {
        for (int x: i) {
            subSequence.push_back(arr[x]);
        }
        subSequenceList.push_back(subSequence);
        subSequence.clear();
        subSequence.shrink_to_fit();
    }
    */
 
  
    
   /*
    for (vector<int> i:  subSequenceList) {
       sum=std::accumulate(i.begin(), i.end(),decltype(i)::value_type(0));
       total.push_back(sum);
}
        
    
 
    
    int maxSubSequenceSum = *max_element(total.begin(), total.end());
 //   std::cout<<maxSubSequenceSum<<std::endl;
 */
    //We need to extract sub array from sub sequence. 
    //SubArray index needs to be continuous
   // int maxSubArraySum;
   /*  
    bool throwAway=false; 
   
    for (vector <int> i:ansBackup) {
        for (int j=0;j<i.size();j++) {
            if (j==0)
              subArray.push_back(arr[i[j]]);
            else {
                if (i[j]!=i[j-1]+1) //if index is not continuous, throw away
                   {
                       subArray.clear();
                       subArray.shrink_to_fit();
                       throwAway=true;
                       break;
                   }
                else {
                    subArray.push_back(arr[i[j]]);
                }
            }   
        }
        if (throwAway) {
            throwAway=false;
            continue;
        }
        else {
            subArrayList.push_back(subArray);
            subArray.clear();
            subArray.shrink_to_fit();
        }
        
    }
    */
    /*
     for (vector <int> i:ansBackup) {
        for (int x: i) {
            std::cout << x << " ";
        }
        std::cout << std:: endl;
    }
    
    std:: cout << "Now subarray" << std:: endl;
    
    for (vector <int> i:subArrayList) {
        for (int x: i) {
            std::cout << x << " ";
        }
        std::cout << std:: endl;
    }
    */
    /*
    total.clear();
    total.shrink_to_fit();
    for (vector<int> i:  subArrayList) {
       sum=std::accumulate(i.begin(), i.end(),decltype(i)::value_type(0));
       total.push_back(sum);
}
    
    maxSubArraySum = *max_element(total.begin(), total.end());
    */
    
    vector <int> result;
    result.push_back(maxSubArraySum);
    result.push_back(maxSubSequenceSum);
    
    
    
    return result;
}
