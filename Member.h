#pragma once
#include <string>
#include <vector>
class Member {
	
private:
	int following;
	int idMember;
	static int counter;
	std::vector<Member*> myMemberFollow;
	std::vector<Member*> myMemberFollower;
public:
	Member();
	int followers;
	int findIndex(vector<Member*>, Member&);
	static int count();
	void follow(Member&);
	void unfollow(Member&);
	int numFollowers();
	int numFollowing();
	void setFollowers(Member&, int);
	~Member();
	
};

