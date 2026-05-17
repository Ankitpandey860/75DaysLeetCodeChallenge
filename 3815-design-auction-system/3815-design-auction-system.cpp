class AuctionSystem {
public:
    unordered_map<int, multiset<pair<int,int>>> bids; 
    unordered_map<int, unordered_map<int,int>> getBid; 
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        int lstbid=getBid[itemId][userId];
        getBid[itemId][userId]=bidAmount;
        if(lstbid!=0){
            bids[itemId].erase({lstbid,userId});
        }
        bids[itemId].insert({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId,itemId,newAmount);
    }
    
    void removeBid(int userId, int itemId) {
        int lstamount=getBid[itemId][userId];
        bids[itemId].erase({lstamount,userId});
        getBid[itemId][userId]=0;
    }
    
    int getHighestBidder(int itemId) {
        if(bids[itemId].size() != 0){
            auto res = *bids[itemId].rbegin();
            if(res.first == 0) return -1;
            return res.second;
        }
        return -1;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */