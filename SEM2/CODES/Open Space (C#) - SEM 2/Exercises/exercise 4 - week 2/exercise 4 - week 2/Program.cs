// See https://aka.ms/new-console-template for more information


Console.WriteLine("Please input string");
string word = Console.ReadLine();
string result = string.Empty;

for (int i = word.Length - 1; i >= 0; i--)
{
    result += word[i];
}

Console.WriteLine("you entered: " + word);
Console.WriteLine("the result is: "+ result);

if (result == word)
{
    Console.WriteLine("this word is also a palindrome");
}

