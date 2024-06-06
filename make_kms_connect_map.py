import os
import requests
import folium
from folium.plugins import MarkerCluster

ip_list = []

log_output = os.popen('docker logs myvlmcsd | grep "IPv4 connection accepted"').read()
for i in log_output.split('\n')[:-1]:
    ip_item = i.split()[5].split(':')[0]
    if ip_item not in ip_list:
        ip_list.append(ip_item)

query_result = []

for i in range(0, len(ip_list), 100):
    batch = ip_list[i:i+100]
    r = requests.post("http://ip-api.com/batch?fields=status,lat,lon,query", json=batch)
    query_result += r.json()
    if int(r.headers['X-Rl']) == 0:
        import time
        time.sleep(int(r.headers['X-Ttl'])+1)

m = folium.Map(location=[0, 0], zoom_start=2)
marker_cluster = MarkerCluster().add_to(m)
for i in query_result:
    if i["status"] == "success":
        folium.Marker(location=[i["lat"], i["lon"]], popup=i["query"]).add_to(marker_cluster)
m.save('make_kms_connect_map.html')
