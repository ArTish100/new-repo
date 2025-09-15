import re
from bs4 import BeautifulSoup

def getpayload(message):
    if message.is_multipart():
        parts = []
        for part in message.walk():
            try:
                content = part.get_payload(decode=True)
                if content:
                    parts.append(content.decode('utf-8', errors='ignore'))
            except:
                continue
        return ''.join(parts)
    else:
        try:
            return message.get_payload(decode=True).decode('utf-8', errors='ignore')
        except:
            return str(message.get_payload())

def getpayload_dict(message):
    result = []
    if message.is_multipart():
        for part in message.walk():
            try:
                payload = part.get_payload(decode=True)
                if payload:
                    result.append({"payload": payload.decode('utf-8', errors='ignore')})
            except:
                continue
    else:
        try:
            result.append({"payload": message.get_payload(decode=True).decode('utf-8', errors='ignore')})
        except:
            result.append({"payload": str(message.get_payload())})
    return result

def ishtml(message):
    content_type = message.get_content_type()
    return 'html' in content_type.lower()

def getAttachmentCount(message):
    count = 0
    for part in message.walk():
        if part.get_content_disposition() == 'attachment':
            count += 1
    return count

def geturls_payload(message):
    payload = getpayload(message)
    return re.findall(r'https?://[^\s\'">]+', payload)

def getexternalresources(message):
    payload = getpayload(message)
    return re.findall(r'src=["\'](http[s]?://.*?\.(css|js))["\']', payload)

def getjavascriptusage(message):
    payload = getpayload(message)
    return re.findall(r'<script.*?>.*?</script>', payload, flags=re.DOTALL | re.IGNORECASE)

def getcssusage(message):
    payload = getpayload(message)
    return re.findall(r'<style.*?>.*?</style>', payload, flags=re.DOTALL | re.IGNORECASE)

def getIPHrefs(message):
    payload = getpayload(message)
    return re.findall(r'href=["\']http://\d{1,3}(\.\d{1,3}){3}.*?["\']', payload)
