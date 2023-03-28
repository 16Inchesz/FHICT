
from flask import Flask
from flask import render_template


volunteeringTestData = \
    [
        ("Mary", 23),
        ("John", 21),
        ("Sandra", 31),
        ("Barbara", 19),
        ("Peter", 25),
        ("Olivia", 21),
        ("Albert", 19)
    ]


app = Flask(__name__)


@app.route('/')
def volunteer_page():
    return render_template('index.html',
                            volunteers = volunteeringTestData)
