class Solution {
public:
    unordered_map<string,string> m;
    int x=1;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s="tinyurl.com/"+to_string(x);
        m.insert({s,longUrl}),x++;
        return(s);
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return(m[shortUrl]);
    }
};
