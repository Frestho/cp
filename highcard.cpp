#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int N;
    cin >> N;

    //so that we can easily find bessie's cards in O(1)
    vector<int> els;
    unordered_set<int> bes;
    for(int i = 1; i <= 2*N; i++)
        bes.insert(i);
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        els.push_back(temp);
        bes.erase(temp);
    }
    // b for bessie lol
    vector<int> b(bes.begin(), bes.end());
	// O(nlogn)
	sort(b.begin(), b.end());
	sort(els.begin(), els.end());
	int j = 0;
	int wins = 0;
	for(int i = 0; i < els.size(); i++) {
		while(b[j] < els[i]) {
			j++;
			if(j >= b.size()) {break;}
		}
		if(j >= b.size()) {break;}
		wins++;
		j++;
	}
	cout << wins << endl;
/*
    // Array that takes O(n) to make where each element stores the least card bessie has greater than the array index
    int smallestGreater[100000];
    for(int i = 0; i < b.size(); i++) {
        if(i == 0)
            for(int j = 0; j < b[i]; j++)
                smallestGreater[j] = b[i];
        else
        	for(int j = b[i-1]; j < b[i]; j++)
            	smallestGreater[j] = b[i];
    }
    // go through elsie's deck and keep a set of bessie's cards that beat them. note how the set automatically throws out duplicates, so we can just check its length at the end
    unordered_set<int> bessiesWinningCards;
    for(auto i : els) {
		if (smallestGreater[i] > 0) {
			bessiesWinningCards.insert(smallestGreater[i]);
			for(int j = )
		}
	}
    cout << bessiesWinningCards.size() << endl;*/
}

/*
Lol I'm editing from the github website rn

I first tried this problem in January. Completely failed it as my code was too complicated and weird
and I didn't even have an algorithm in mind. I think what I tried to do was go through Bessie's cards
and designate some of them "winning cards" where she will play it and get a point. Really dumb though,
as the order of the cards doesn't even matter so idk what I was thinking.

My old way of randomly doing whatever first came to mind resulted in tons of frustrations, leading me
to quit USACO. Reassessment of my learning and coding style several months later led me to make more
reasonable habits. usaco.guide helped a ton.
*/
