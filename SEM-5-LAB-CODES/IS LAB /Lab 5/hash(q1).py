def custom_hash(input_string):
    hash_value=5381
    for i in input_string:
        hash_value=(hash_value*33)&0xFFFFFFFF
        hash_value+=ord(i)
        hash_value^=(hash_value>>5)
        hash_value=(hash_value) & 0xFFFFFFFF
    return hash_value
input_str="jessica"
result=custom_hash(input_str)
print(f"Hash Value for '{input_str}' is: {result}")