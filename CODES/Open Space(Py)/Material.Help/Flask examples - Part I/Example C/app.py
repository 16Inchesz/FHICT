
from flask import Flask
from flask import render_template

from datetime import datetime


def current_time():
    rightNow = datetime.now()
    time = rightNow.strftime("%I:%M%p")
    time = time.lstrip('0')
    time = time.lower()
    day = rightNow.strftime("%A")

    return "It is " + time + " on " + day + "."


app = Flask(__name__)


@app.route('/')
def hello_world():
    return render_template('general.html',
                            people_names = [],
                            time = current_time())

@app.route('/mary+')
def hello_mary_and_friends():
    return render_template('general.html',
                            people_names = [ "Mary", "Peter", "Jessica" ],
                            time = current_time())

@app.route('/john+')
def hello_john_and_friends():
    return render_template('general.html',
                            people_names = [ "John", "Sandra", "Amy" ],
                            time = current_time())

@app.route('/anyone/')
@app.route('/anyone/<name_from_url>')
def hello_person(name_from_url = None):
    if name_from_url == None:
        return render_template('general.html',
                                people_names = [],
                                time = current_time())
    else:
        return render_template('general.html',
                                people_names = [ name_from_url ],
                                time = current_time())
