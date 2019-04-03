#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#define int int64_t

unordered_map<int,string> mp;

string ranstr(int len){
	string s = "";
	for(int i=1;i<=len;i++) s+=(char)('a'+rand()%26);
	return s;
}

uint64_t hhashtable[31];

uint64_t hhash(const std::string &s, uint64_t mod) {
	uint64_t val = 0,idx = s.size()-1;
	for (char c : s) val = (val + hhashtable[idx--] * c) % mod;
	return val;
}

vector <string> v1000000007 = {"aaaaaaaaaa","aaabuwihdn","aaaditnccp","aaahxlsbag","aaaiyxgxrr","aaakmulsqt","aaamarqnpv","aaaqpjvmnm","aabayfboev","aabcmcgjdx","aabcqlunnb","aabdqzeffy","aabeeizimd","aabqhqcepj","aabqxpmpqv","aabslmrkpx","aabuwihdna","aabzsyzaor","aaccyrlqqk","aacemoqlpm","aacgalvgoo","aacwsldbpl","aacywhshpz","aadeuuhosv","aadgirmjrx","aaditnccpa","aadkxjripo","aadmlgwdoq","aadvuzjxgg","aadxiwosfi","aaemtmngrz","aaeswbxaos","aaewmfhzgq","aaeyacmufs","aaezezkqht","aafailrcqq","aafexdwboh","aafkbelvfh","aafnjxyxhw","aafriqtleb","aagaqriftz","aagkjkcyiq","aagoychxgh","aagrqwkohk","aagtetpjgm","aagtuszuhy","aagxabaxsb","aagxtluied","aagzhizddf","aahffvokgb","aahfvuyvhn","aahqufdvis","aahsiciqhu","aahtmzgmjv","aahvawlhix","aahxlsbaga","aahzpoqggo","aaicvhcwih","aaiejehrhj","aaignawxhx","aaihbykiim","aaihrxutjy","aailqqphgd","aainenucff","aaiofziywq","aaisurnxuh","aaiuiosstj","aaiyxgxrra","aaizxuhjjx","aajgfhdpju","aajlywgkjm","aajnmtlfio","aajpaqqahq","aajuqujvws","aajweroqvu","aakbbspbhf","aakbrrzmir","aakgrwiwwh","aakiftnrvj","aakmqcemjw","aakmulsqta","aaknuzcilx","aakoiixlsc","aakpiwhdkz","aaktxomciq","aalafbiiin","aalavastjz","aalbjygeko","aalfyqldif","aalhjcgywr","aalinzeuys","aalkbwjpxu","aaloqooovl","aalqeltjun","aalutdyise","aamarqnpva","aamcbeegky","aamcfnskuc","aamhuthbkq","aamoyufryu","aamqmrkmxw"};

int32_t main()
{
	srand(time(NULL));
	//IOS;
	int n,mod;
	cin >> mod >> n;
	if(mod == 1000000007LL){
		for(int i=0;i<v1000000007.size();i++) for(int j=0;j<v1000000007.size();j++) if(i||j){
			cout << v1000000007[0] + v1000000007[0] << ' ' << v1000000007[i] + v1000000007[j] << '\n';
			n--;
			if(!n) return 0;
		}
	}
	else if(mod == 3213213213213213LL){
		
	}
	else if(mod == 9007199254740992LL){
		
	}
	else if(mod == 1000000000100011LL){
		
	}
	else{
		hhashtable[0] = 1;
		for(int i=1;i<=30;i++) hhashtable[i] = hhashtable[i-1]*131 % mod;
		for(int i=1;i<=n;i++){
			while(true){
				string s = ranstr(10);
				//if(mp.size()%10000==0)cout << mp.size() << '\n';
				int hh = hhash(s,mod);
				if(mp.find(hh) != mp.end()) {
					if(s == mp[hh]) continue;
					cout << s << ' ' << mp[hh] << '\n';
					break;
				}
				else mp[hh] = s;
			}
		}
	}
   return 0;
}


