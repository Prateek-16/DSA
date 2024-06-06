//https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1


//array subset of another array


/*
Simple Question hai - A1 ko freq map mai daldo (freq uslye beacuse duplicates hai toh frequecy bhi consider karni padhegi)
A2 ko check karo then map mai hai toh freq to kaam karo agar freq greater than 0 ho toh
otherwise return false kardo (when a2 ka element map mai na mile ya fir Freq 0 ho gyi ho)
*/
string isSubset(int a1[], int a2[], int n, int m) {
    string ans = "Yes";
    unordered_map<int,int>mp;
    for (int i = 0 ; i < n ; i++){
        int ele = a1[i];
        mp[ele]++;
    }
    for (int i = 0 ; i < m ; i++){
        int ele = a2[i];
        if(mp.find(ele) != mp.end()){
            if(mp[ele]>0){
                mp[ele]--;
            }
            else{
                ans = "No";
                break;
            }
        }
        else{
            ans = "No";
            break;
        }
    }
    return ans;
}