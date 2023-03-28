
from flask import Flask
from flask import render_template

app = Flask(__name__)


@app.route('/')
def hello_world():
    return render_template('world.html')

@app.route('/mary')
def hello_mary():
    return render_template('person.html', person_name = "Mary")

@app.route('/john')
def hello_john():
    return render_template('person.html', person_name = "John")

@app.route('/anyone/')
@app.route('/anyone/<name_from_url>')
def hello_person(name_from_url = None):
    if name_from_url == None:
        return render_template('world.html')
    else:
        return render_template('person.html', person_name = name_from_url)
