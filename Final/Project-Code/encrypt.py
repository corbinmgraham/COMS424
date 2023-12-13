import skimage

def xor_bytes(a, b):
    return bytes(x ^ y for x, y in zip(a, b))

def encrypt_ctr(plaintext, key):
    block_size = 16  # AES block size
    nonce = b'\x00' * (block_size // 2)  # 8-byte nonce

    ciphertext = b""
    counter = 0

    while plaintext:
        counter_block = nonce + counter.to_bytes(block_size // 2, byteorder='big')
        keystream = xor_bytes(counter_block, key)

        block = plaintext[:block_size]
        padded_block = block.ljust(block_size, b'\x00')  # Pad the block if necessary

        encrypted_block = xor_bytes(padded_block, keystream)
        ciphertext += encrypted_block

        plaintext = plaintext[block_size:]
        counter += 1

    return ciphertext

def decrypt_ctr(ciphertext, key):
    return encrypt_ctr(ciphertext, key)  # Decryption and encryption are the same in CTR mode

def based_encrypt():
    # Example usage
    key = b"abcdefghijklmnop"
    plaintext = b"Hello, CTR encryption!"

    print(bin(100))

    # Encrypt the plaintext
    encrypted_text = encrypt_ctr(plaintext, key)
    print("Encrypted:", encrypted_text)

    # Decrypt the ciphertext
    decrypted_text = decrypt_ctr(encrypted_text, key)
    print("Decrypted:", decrypted_text.decode('utf-8'))


def qe(data):
    # Create a key
    key = 12345
    # Use this key in an evolving equation
    # The equation stops evolving when measured
    return key

def qd(key):
    return key

if __name__ == "__main__":
    temp_data = "abc"
    print(qd(qe(temp_data)))
    based_encrypt()