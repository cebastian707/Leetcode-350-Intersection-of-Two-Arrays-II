/*By::Cebastian Santiago
* Leetcode 350
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>


void intersecthelper(int first, int second,std::map<int,int> num2,std::vector<int>&temp) {
	for (auto i : num2){
		if (i.first == first){
			int sec = std::min(i.second,second);

			while (sec > 0){
				temp.push_back(i.first);
				sec--;
			}

		}

	}
}


std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
	//sort the vectors 
	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());
	//create hashs
	std::map<int, int> Hash1;
	std::map<int, int> Hash2;
	std::vector<int> a;

	//insert nums1 into Hash1
	for (auto i : nums1){
		Hash1[i]++;
	}

	//insert nums2 into Hash2
	for (auto i : nums2){
		Hash2[i]++;
	}


	//main part of the program compare the elements with the helper function
	for (auto i : Hash1){
		 intersecthelper(i.first, i.second, Hash2,a);
	}

	return a;
}



int main(int argc, char* argv[]) {
	std::vector<int> num1 = {4,9,5};
	std::vector<int> num2 = {9,4,9,8,4};

	std::vector<int> a = intersect(num1, num2);

	for (auto i : a){
		std::cout << i << std::endl;
	}
	
	return 0;
}