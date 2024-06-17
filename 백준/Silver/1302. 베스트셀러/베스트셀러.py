n = int(input())
word_dict = {}

for _ in range(n):
    word = input()
    if word in word_dict:
        word_dict[word] += 1
    else:
        word_dict[word] = 1

sorted_word_dict = dict(sorted(word_dict.items()))

max_freq = 0
most_common_word = ''

for word, count in sorted_word_dict.items():
    if count > max_freq:
        max_freq = count
        most_common_word = word

print(most_common_word)