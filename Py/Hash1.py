import hashlib

def read_dictionary(file_path):
    with open(file_path,'r') as file:
        return [line.strip() for line in file]
    
def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

def crack_password(target_hash, dictionary):
    for word in dictionary:
        hashed_word = hash_password(word)
        if hashed_word == target_hash:
            return word
    return None

if __name__ == "__main__":
    target_hash = "066955bb1fc466f82c039d6d99a8948adfe82f56b77604e0dfeda2b76439c9a9"
    dictionary_file = "dictionary.txt"

    dictionary = read_dictionary(dictionary_file)

    cracked_password = crack_password(target_hash, dictionary)

    if cracked_password:
        print(f"Password cracked! The password is : {cracked_password}")
    else:
        print("Password not found in the dictionary")