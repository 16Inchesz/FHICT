import random
#words and random generator
options = ['bottle', 'bread', 'plant', 'candle',
         'book', 'soup', 'tennis', 'playing']
word = random.choice(options)
#empty list for user later
used = []
#variables 
display = word
attempts = 1                                                        #initially at 0, but first letter didn't count as attempt (idk why...)

for x in range (len(display)):
  #replace each letter with a '_'
  display = display[0:x] + "_" + display[x+1:]
#loop for program
while display != word:
  guess = input("Please enter a letter: ")
  guess = guess.lower()
  #add guesses to used and display
  used.extend(guess)
  print ("Attempts: ")
  print (attempts)
  
  #if guess is correct, see below.
  for x in range(len(word)):
    if word[x] == guess:
      display = display[0:x] + guess + display[x+1:]
  print("Used letters:",used)
      
  #lines of gussed and unguessed letters
  print(display)
  attempts = attempts + 1

print("congratulations!")