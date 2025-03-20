#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Twitter {
private:
    int timestamp;  // Global timestamp to order tweets
    unordered_map<int, vector<pair<int, int>>> tweets;  // {userId -> {timestamp, tweetId}}
    unordered_map<int, unordered_set<int>> followers;   // {userId -> set of users they follow}

public:
    Twitter() {
        timestamp = 0;
    }

    // User posts a new tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    // Retrieve the 10 most recent tweet IDs in the user's news feed
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        
        // Add the user's own tweets
        for (const auto& tweet : tweets[userId]) {
            maxHeap.push(tweet);
        }

        // Add the tweets of users that the user follows
        for (int followeeId : followers[userId]) {
            for (const auto& tweet : tweets[followeeId]) {
                maxHeap.push(tweet);
            }
        }

        // Get the 10 most recent tweets
        vector<int> result;
        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }

        return result;
    }

    // User follows another user
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    // User unfollows another user
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */