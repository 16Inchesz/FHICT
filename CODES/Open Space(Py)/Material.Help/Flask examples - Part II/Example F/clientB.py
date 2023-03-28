
import requests


# Main program:

print("\n\n*** Client B ***\n")

while True:
    name = input("Name of the volunter to register? ('Enter' to quit) ")

    if name == "":
        break

    age = int(input("Age of the volunteer? "))

    data = { 'sent_name': name, 'sent_age': age }
    response = requests.post('http://localhost:5000/remote_register', json = data)
