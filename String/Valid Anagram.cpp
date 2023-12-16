class Solution {
private:
    //convert into upper case and check
int handle(char a, char b){
	a = (a>='a'&&a<='z')? a-'a'+'A':a;
	b = (b>='a'&&b<='z')? b-'a'+'A':b;
	if(a<b)	return -1;
	if(a>b)	return 1;
	return 0;
}
int partation(string &str,int start,int end){
	char pivot = str[end];
	int i = start-1;
	for(int j = start; j < end; j++){
		if(handle(str[j],pivot)<0){
			i++;
			swap(str[i],str[j]);
		}
	}
	swap(str[i+1],str[end]);
	return i+1;
}
void quickSort(string& str,int start,int end){
	//base case
	if(start>=end){
		return ;
	}
	int part = partation(str,start,end);
	quickSort(str,start,part-1);
	quickSort(str,part+1,end);
}
public:
    bool isAnagram(string s, string t) {
        int l1 = s.size()-1;
        int l2 = t.size()-1;
        //Sort both String Using Quick Sort
        quickSort( s, 0, l1);
        quickSort( t, 0, l2);
        return s==t;
    }
};
