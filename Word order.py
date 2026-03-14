
n = int(input().strip())

word_count = {}
word_order = []

for _ in range(n):
    word = input().strip()  # Read each word
    
    if word not in word_count:
        word_order.append(word)
        word_count[word] = 0
    

    word_count[word] += 1


print(len(word_order))

occurrences = [word_count[word] for word in word_order]
print(' '.join(map(str, occurrences)))
