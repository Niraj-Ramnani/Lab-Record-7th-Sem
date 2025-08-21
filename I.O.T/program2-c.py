# c) Word and character count of a given string. 
text = input("Enter a string: ")
character_count = len(text.replace(" ", ""))
word_count = len(text.split())
print("Total characters(excluding space):", character_count)
print("Total words:", word_count)
