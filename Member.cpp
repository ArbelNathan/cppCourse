#include "Member.h"
#include <vector>
#include <iostream>
using namespace std;
//init static members
int Member::counter = 0;
static int id = 0;

//constructor
Member::Member(): followers(0), following(0)
{
	this->counter++;
	vector<Member*> myMemberFollow;
	vector<Member*> myMemberFollower;
	id++;
	this->idMember = id;
}

void Member::follow(Member& member)
{
	if(!this->myMemberFollow.empty()){
		int i =findIndex(myMemberFollow,member);
		if(i ==-1){
			this->following++;
			member.followers++;
			this->myMemberFollow.push_back(&member);
			member.myMemberFollower.push_back(this);
		}
	}
	else{
		this->following++;
		member.followers++;
		this->myMemberFollow.push_back(&member);
		member.myMemberFollower.push_back(this);
	}
}

void Member::unfollow(Member& member)
{
	if(!this->myMemberFollow.empty()){
		int i =findIndex(myMemberFollow,member);
		if(i !=-1){
			this->following--;
			member.followers--;
			this->myMemberFollow.erase(myMemberFollow.begin() + i);
			int j = findIndex(member.myMemberFollower, *this);
			member.myMemberFollower.erase(member.myMemberFollower.begin() + j);
		}
	}

}

int Member::findIndex(vector<Member*> vec, Member& member){
	int i = 0;
	while(i < vec.size() && vec[i]->idMember != member.idMember){
		i++;
	}
	if(i != vec.size()){
		return i;
	}

	else{
 		return -1;
	}

}

void Member::setFollowers(Member& member, int num){
	member.followers = num;
}

int Member::numFollowers()
{
	return this->myMemberFollower.size();
}

int Member::numFollowing()
{
	return this->myMemberFollow.size();
}

int Member::count()
{
	return counter;
}

Member::~Member()
{
	
	while(!myMemberFollow.empty()){
		unfollow(*myMemberFollow[0]);
	}
	while(!myMemberFollower.empty()){
		myMemberFollower[0]->unfollow(*this);
	}
	counter--;	
	
}





