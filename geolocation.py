"""
get geolocation
"""
try:
    # For Python 3.0 and later
    from urllib.request import urlopen
except ImportError:
    # Fall back to Python 2's urllib2
    from urllib2 import urlopen

def getGeolocation():
  # Automatically geolocate the connecting IP
  f = urlopen('http://freegeoip.net/json/')
  json_string = f.read().decode('utf-8')
  json_string = json_string[2:-2]
  f.close()

  # get rid of " and '
  json_string = ''.join(c for c in json_string if c not in '"')

  data = json_string.split(',')
  result= dict()

  for x in data:
    key_value = x.split(':')
    result[key_value[0]] = key_value[1]

  return result

if __name__ == '__main__':
  x = getGeolocation()
