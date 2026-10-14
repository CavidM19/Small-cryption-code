#include <bits/stdc++.h>
#include <string>
using namespace std;

string chars="abcdefghijklmnopqrstuvwxyz .?";
int seperator(long long s){
	long long ss=pow(s,5)-s*s+pow(19,5);
	if(ss%chars.length()<=9){
		return 0;
	}else if(ss%chars.length()>=19){
		return 1;
	}else return 2;
}

int length(long long c){
	int a=0;
	while(c!=0){
		c/=10;
		a+=1;
	}
	return a;
}
string change_key(string key,string text){
	long long a=(text).length()%(key).length();
	long long b=(text).length()/(key).length();
	long long ab=a*b;
	int l=length(ab);
	while (l<(key).length()){
		ab=ab*ab-a*b*(a+b)+a+b+19;
		l=length(ab);
		
	}
	for (int i =0;i<(key).length();i++){
		key[i]=chars[(chars.find(key[i])+ab%10+i)%chars.length()];
	}
	return key;
}
string code_text(string key,string text){
	key = change_key(key,text);
	string long_key=key;
	while (text.length()>long_key.length()){
		long_key+=key;
	}
	
	for (long long i=0;i<text.length();i++){
		if(seperator(chars.find(long_key[i]))==0){
			text[i]=chars[(chars.find(text[i])+chars.find(long_key[i]))%chars.length()];
		}
		else if(seperator(chars.find(long_key[i]))==2){
			text[i]=chars[((chars.find(text[i])+chars.length())-chars.find(long_key[i]))%chars.length()];
	    }else{
	    	text[i]=chars[(chars.find(text[i])+2*chars.find(long_key[i])+19)%chars.length()];
		}
    }
    return text;
}

string decode_text(string key,string text){
	key = change_key(key,text);
	string long_key=key;
	while (text.length()>long_key.length()){
		long_key+=key;
	}
	
	for (long long i=0;i<text.length();i++){
		if(seperator(chars.find(long_key[i]))==0){
			text[i]=chars[((chars.find(text[i])+chars.length())-chars.find(long_key[i]))%chars.length()];
		}
		else if(seperator(chars.find(long_key[i]))==2){
			text[i]=chars[(chars.find(text[i])+chars.find(long_key[i]))%chars.length()];
	    }else{
	    	text[i]=chars[(chars.find(text[i])-2*chars.find(long_key[i])-19+3*chars.length())%chars.length()];
		}
    }
    return text;
}

int main(){
	
	string key,text,step;
	
	cout<<"Enter C for code , D for decode; ";
	
	cin>>step;
	cout<<"\n"<<"Enter key; ";
	cin.ignore();
	getline(cin,key);
	cout<<"\n"<<"Enter text; ";
	getline(cin,text);
	if (step=="C" || step=="c"){
		cout<<"Coded text; "<<code_text(key,text);
	}else if(step=="D" || step=="d"){
		cout<<"Decoded text; "<<"\n"<<decode_text(key,text);
	}else cout<<"Wrong operation!!!";
}
