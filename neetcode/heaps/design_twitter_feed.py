from collections import defaultdict
from typing import List
import heapq

class Twitter:

    def __init__(self):
        self.tweets = defaultdict(list)
        self.following = defaultdict(set)
        self.time = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        userTweets = self.tweets[userId]
        heapq.heappush(userTweets, (self.time, tweetId))
        self.time -= 1

    def getNewsFeed(self, userId: int) -> List[int]:
        self.following[userId].add(userId)
        feed = []
        for followee in self.following[userId]:
            iterable = heapq.merge(feed, self.tweets[followee])
            feed = heapq.nsmallest(10, iterable)
        return [x[1] for x in feed]

    def follow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].discard(followeeId)
