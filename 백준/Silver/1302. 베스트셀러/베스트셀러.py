n = int(input())
word_dict = {}

for _ in range(n):
    word = input()
    if word in word_dict:
        word_dict[word] += 1
    else:
        word_dict[word] = 1

max_freq = 0
most_common_word = ''

for word, count in word_dict.items():
    if max_freq < count:
        max_freq = count
        most_common_word = word
    elif max_freq == count and word < most_common_word:
    	most_common_word = word

print(most_common_word)