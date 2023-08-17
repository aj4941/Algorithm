def filp_words(idx, word_list):
    word_list = word_list.split()
    word_list = word_list[::-1]
    answer = " ".join(word_list)
    return f"Case #{idx + 1}: {answer}"

if __name__ == "__main__":
    for i in range(int(input())):
        word_list = input()
        print(filp_words(i, word_list))