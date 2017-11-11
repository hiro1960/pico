picojsonを試したサンプルです。
実行すると以下の様な結果がでます。

---- dump input ----
{"follow":[{"age":38,"name":"hoge"},{"age":42,"name":"huga"}],"message":"success","nu\
mber":[1,2],"person":{"age":38,"name":"hoge"},"returnCode":0}
---- analyzing input ----
input is an object
follow  [{"age":38,"name":"hoge"},{"age":42,"name":"huga"}]
message  "success"
number  [1,2]
person  {"age":38,"name":"hoge"}
returnCode  0

success

follow  [{"age":38,"name":"hoge"},{"age":42,"name":"huga"}]
message  "fail"
number  [1,2]
person  {"age":38,"name":"hoge"}
piyopiyo  10
returnCode  0

hoge 38

huga 42

{"follow":[{"age":38,"name":"hoge"},{"age":42,"name":"huga"}],"message":"fail","numbe\
r":[1,2],"person":{"age":42,"name":"huga"},"piyopiyo":10,"returnCode":0}

ついでにcurlを使って、couchDBにアクセスしたサンプルものせました。