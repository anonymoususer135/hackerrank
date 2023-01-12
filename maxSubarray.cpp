vector<int> maxSubarray(vector<int> arr) {

    vector <vector <int>> subSequenceList;
    vector <int> subSequence;
    vector <vector <int>> permutationList;
    vector <vector <int>> subArrayList;
    vector <int> subArray;
    vector <int> eachSum;
    vector<int>allSums;
    int sum=0;
    for (int i=0; i< arr.size();i++)
        {
            subArray.push_back(arr[i]);
            subArrayList.push_back(subArray);
            subArray.clear();
            subArray.shrink_to_fit();
            subSequence.push_back(arr[i]);
            subSequenceList.push_back(subSequence);
            subSequence.clear();
            subSequence.shrink_to_fit();          
        }
    for (int i = 0; i < arr.size(); i++) {
        subArray.push_back(arr[i]);
        for (int j = i+1; j < arr.size(); j++) {
            subArray.push_back(arr[j]);
            subArrayList.push_back(subArray);
        }
        subArray.clear();
        subArray.shrink_to_fit();
    }
    cout << "--------------------------"<<endl;
    for (vector<int> i: subArrayList)
    {
        
        sum=std::accumulate(i.begin(), i.end(),decltype(i)::value_type(0));
        allSums.push_back(sum);
    }
    int maxSubArraySum = *max_element(allSums.begin(), allSums.end());
    std::cout<<maxSubArraySum<<std::endl;
    
    int n=1;
    vector <int> working;
    while (n<=arr.size()) {
    for (int i=0;i<n;i++) {
        working.push_back(arr[i]);
    } //Now working has a sub vector of arr up to n
    while (std::next_permutation(working.begin(), working.end())) {
        //each iteration, it will get a permutation store in working
        //save that permutation, which is a subsequence
        subSequenceList.push_back(working);
    }
    working.clear();
    working.shrink_to_fit();
    n++;
    }
    //here, subSequenceList has all permutation
    for (vector<int> i: subSequenceList) {
        //std:: cout << "[ ";
        for (int x: i) {
            eachSum.push_back(x);
            allSums.push_back(accumulate(eachSum.begin(), eachSum.end(), 0));
            eachSum.clear();
            //sum += x;
            //allSums.push_back(sum);
            //sum = 0;
            //std::cout << x << " ";
        }
        //std::cout << " ]" << std:: endl;
        
    }
    
    return subSequence;
}