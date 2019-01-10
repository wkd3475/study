import urllib, urllib2

url = "https://pay.toss.im/api/v1/payments"
params = {
    "orderNo": "2019-01-10-2015410048",
    "amount": 500,
    "amountTaxFree": 0,
    "productDesc":"테스트 결제",
    "apiKey": "sk_test_apikey1234567890",
    "expiredTime":"2015-07-20 16:21:00",
    "resultCallback": "https://myshop.com/toss/result.php",
    "retUrl": "https://naver.com",
    "cashRecipt": 
}

response = urllib.urlopen(url, urllib.urlencode(params))
print(response.read())