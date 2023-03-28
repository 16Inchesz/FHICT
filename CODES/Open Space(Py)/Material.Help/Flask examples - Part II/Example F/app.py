
from flask import Flask
from flask import render_template
from flask import request, redirect

import random


app = Flask(__name__)
currentVolunteers = []


@app.route('/')
def show_and_register():
    return render_template('form.html',
                            volunteers = currentVolunteers)


@app.route('/register', methods = ['POST'])
def add_volunteer():
    name = request.form['newname']
    age = request.form['newage']

    newVolunteer = (name, age)
    currentVolunteers.append(newVolunteer)

    return redirect('/')


@app.route('/take', methods = ['GET'])
def send_away_volunteer():

    if len(currentVolunteers) == 0:
        return {}

    volunteer = random.choice(currentVolunteers)
    currentVolunteers.remove(volunteer)

    (name, age) = volunteer
    return { 'sent_name': name, 'sent_age': age }


@app.route('/remote_register', methods = ['POST'])
def also_add_volunteer():
    data = request.get_json()
    name = data['sent_name']
    age = data['sent_age']

    newVolunteer = (name, age)
    currentVolunteers.append(newVolunteer)

    return
