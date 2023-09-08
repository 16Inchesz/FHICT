import random

def chances(attempts):
  attempts = attempts + 1
  return attempts

#words and random generator
options = ['bottle', 'bread', 'plant', 'candle',
         'book', 'soup', 'tennis', 'playing']

word = random.choice(options)

#empty list for user later
used = []

#variables 
display = word
attempts = 0                                                        #initially at 0, but first letter didn't count as attempt 
attempts = int(attempts)                                            #needs to be an inteffer type if i want to compare it to max_attempts(also an integer variable)
max_attempts = int(input("Please input max amount of attempts(minimum 10):"))

#longest word is 7 character long so recommended input is 10, if user inputs lower then 10, ask again.
while max_attempts < 10:
  max_attempts = int(input("Please input a minimum of 10:"))

#Turn random word to lines.
for x in range(len(display)):
  #replace each letter with a '_' using slicing.
  display = display[0:x] + "_" + display[x+1:]

#run as long total attempts is smaller than user inputted attempts
while attempts <= max_attempts:
#loop for program
  if display != word:
    guess = input("Please enter a letter: ")
    guess = guess.lower()

    #add guesses to used and display
    used.extend(guess)
    print ("Attempts: ")
    print (attempts)
    
    #if guess is correct, replaces correct guess using slicing. 
    for x in range(len(word)):
      if word[x] == guess:
        display = display[0:x] + guess + display[x+1:]

    print("Used letters:")
    print(used)
        
    #lines of gussed and unguessed letters
    print(display)
    attempts = chances(attempts)
  else:
    print("Congratulations, YOU WON!!")
    break
  
print("Play again?")