from flask import Flask, render_template, request, redirect, url_for
import csv, random, os, time
from flask_sqlalchemy import SQLAlchemy
from sqlalchemy.sql import func

basedir = os.path.abspath(os.path.dirname(__file__))

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] =\
        'sqlite:///' + os.path.join(basedir, 'database.db')
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)

class Pizza(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    pizzaname = db.Column(db.String(100), nullable=False)
    status = db.Column(db.String(100), nullable=False)
    created_at = db.Column(db.DateTime(timezone=True),
                           server_default=func.now())
    bio = db.Column(db.Text)

    def __repr__(self):
        return f'<Pizza {self.pizzaname}>'

pizzas = [['Margharita', 'Tomato sauce, Mozzarella, Seasoning', '../static/img/1.png'], 
          ['Pepperoni', 'Tomato sauce, Mozzarella, Pepperoni', '../static/img/2.jpg'], 
          ['Hawaii', 'Tomato sauce, Ham, Pineaple, Mozarella', '../static/img/4.jpg'], 
          ['Cheese', 'Tomato sauce, Mozzarella, Cheddar, Gouda, Ricotta',  '../static/img/3.jpg']]

@app.route('/')
def main():  
    with open('./data/reviews.csv', 'r') as f:
        reviews = list(csv.reader(f))
    return render_template("index.html", userList = [reviews[-1], reviews[-2], reviews[-3]])

@app.route('/order')
def order():
    return render_template("orderPage.html", pizzas = pizzas)

@app.route('/redirect', methods = ['POST'])
def redirected():
    return redirect(url_for('order'))

@app.route('/review', methods = ['POST'])
def review():
    name = request.form['name']
    rev = request.form['message']
    with open('./data/reviews.csv', 'a', newline='') as f:
        writer = csv.writer(f, delimiter=",")
        writer.writerow([name, rev])
    return redirect(url_for('main'))

@app.route('/overview')
def index():
    pizza = Pizza.query.filter(Pizza.status != 'Delivered')
    return render_template('index1.html', pizza=pizza)

@app.post('/status')
def status():
    data = request.get_json()
    pizid = data['pizza_id']
    pizza = Pizza.query.get_or_404(pizid)
    pizza.status = 'Ready'
     
    db.session.commit()
    return redirect(url_for('index'))

@app.post('/deliver')
def deliver():
    pizza = Pizza.query.first()
    pizza.status = 'Delivered'
    
    pizzalist = [pizza.id, pizza.pizzaname, pizza.status, pizza.created_at, pizza.bio]
    print(pizzalist)
    
    with open('./data/test.csv', 'a', newline='') as filevar:
            writer = csv.writer(filevar)
            writer.writerow(pizzalist)
            time.sleep(0.1)
    db.session.delete(pizza)
    db.session.commit()
    return redirect(url_for('index'))

@app.route('/oven', methods = ['POST'])
def oven():
    data2 = request.get_json()
    pizid2 = data2['pizza_id']
    pizza2 = Pizza.query.get_or_404(pizid2)
    pizza2.status = 'In Oven'
    db.session.commit()
    return redirect(url_for('index'))

@app.route('/add', methods = ['POST'])
def add():
    if "Pepperoni" in request.form:
       database('Pepperoni')
    elif "Margharita" in request.form:
        database('Margharita')
    elif "Hawaii" in request.form:
        database('Hawaii')
    elif "Cheese" in request.form:
        database('Cheese')
    return redirect(url_for('index'))

def database(pizzaname):
    order = Pizza(pizzaname=pizzaname,status='Not Ready',bio=random.randint(1000,9999))
    db.session.add(order)
    db.session.commit()