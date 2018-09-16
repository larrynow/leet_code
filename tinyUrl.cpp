class Solution {
public:

    map<string,string> urlMap;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        srand((unsigned)time(NULL));
        string tinyUrl = to_string(rand());
        tinyUrl = "http://tinyurl.com/"+tinyUrl;
        urlMap.insert(pair<string, string>(tinyUrl,longUrl));

        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string longUrl = urlMap[shortUrl];
        return longUrl;
    }
};
