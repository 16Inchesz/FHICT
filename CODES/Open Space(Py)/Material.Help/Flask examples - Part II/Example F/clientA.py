
import requests 


def what_to_do():
    action = input("Do you need a volunteer? (Y/N) ")

    if action in "Yy":
        return "y"
    elif action in "Nn":
        return "n"
    else:
        print("Invalid option (only Y/N).")
        return ""


def get_volunteer():

    response = requests.get('http://localhost:5000/take')
    data = response.json()

    if data == {}:
        print("No volunteers at the server.")
        return

    name = data['sent_name']
    age = data['sent_age']

    print("Volunteer received from server:", name, "(aged " + str(age) + ").")


# Main program:
print("\n\n*** Client A ***\n")

while True:
    action = what_to_do()

    if action == "y":
        get_volunteer()
    elif action == "n":
        break
