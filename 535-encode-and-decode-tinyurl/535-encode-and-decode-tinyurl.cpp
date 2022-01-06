class Solution {
public:

    // Encodes a URL to a shortened URL.
    int id=10001;
    unordered_map<string,string> mp;
    string encode(string longUrl) {
        string t=to_string(id);
        mp[t]=longUrl;
        id++;
        return t;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));