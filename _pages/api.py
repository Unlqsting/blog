import requests

url = "https://weatherbit-v1-mashape.p.rapidapi.com/forecast/3hourly"

querystring = {"lat":"33.0144484","lon":"-117.1214139","units":"imperial"}

headers = {
	"X-RapidAPI-Key": "e955c5ce4emsh9bea3b91975a2e4p12a645jsnb1be2d19fa12",
	"X-RapidAPI-Host": "weatherbit-v1-mashape.p.rapidapi.com"
}

response = requests.request("GET", url, headers=headers, params=querystring).json()

