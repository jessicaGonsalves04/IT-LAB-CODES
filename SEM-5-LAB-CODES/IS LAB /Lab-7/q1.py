# Implement the Paillier encryption scheme in Python. Encrypt two integers (e.g., 15 and 25)
# using your implementation of the Paillier encryption scheme. Print the ciphertexts. Perform
# an addition operation on the encrypted integers without decrypting them. Print the result of
# the addition in encrypted form. Decrypt the result of the addition and verify that it matches
# the sum of the original integers.


from Crypto.Util import number
import random

def generate_keypair(bits=512):
    """Generates a public/private key pair for Paillier encryption"""
    p = number.getPrime(bits)
    q = number.getPrime(bits)
    n = p * q
    g = n + 1  # g = n + 1 is often used in practical implementations
    lambda_n = (p - 1) * (q - 1)  # λ(n) = (p - 1)(q - 1)
    mu = number.inverse(lambda_n, n)  # Modular inverse of λ(n) modulo n
    return (n, g), (lambda_n, mu)

def encrypt(public_key, message):
    """Encrypts a message using the Paillier encryption scheme"""
    n, g = public_key
    r = random.randint(1, n - 1)  # Random value for encryption
    ciphertext = (pow(g, message, n * n) * pow(r, n, n * n)) % (n * n)
    return ciphertext

def decrypt(private_key, public_key, ciphertext):
    """Decrypts a ciphertext using the Paillier encryption scheme"""
    n, _ = public_key
    lambda_n, mu = private_key
    u = pow(ciphertext, lambda_n, n * n)
    l = (u - 1) // n
    message = (l * mu) % n
    return message

def main():
    # Generate key pair
    public_key, private_key = generate_keypair(bits=512)

    # Encrypt integers
    a = 15
    b = 25
    ciphertext_a = encrypt(public_key, a)
    ciphertext_b = encrypt(public_key, b)

    # Perform additive homomorphic operation (add ciphertexts)
    ciphertext_sum = (ciphertext_a * ciphertext_b) % (public_key[0] * public_key[0])

    # Decrypt the result
    decrypted_sum = decrypt(private_key, public_key, ciphertext_sum)

    # Print results
    print(f"Ciphertext of a: {ciphertext_a}")
    print(f"Ciphertext of b: {ciphertext_b}")
    print(f"Ciphertext of a + b: {ciphertext_sum}")
    print(f"Decrypted sum: {decrypted_sum}")
    print(f"Expected sum: {a + b}")

if __name__ == "__main__":
    main()

"""
Output:
Ciphertext of a: 6537959441495741266482661937520248824810149853621041447570815979745345616620096180745260816828927289591233952597570582824755320124601904880332196773711727817250003141058857603094843911914104849249283198632121760675737771984198863986582253555799313834132014090878303587105137531425218385589995388429281615604862789329038266060170760381317108013567528822362881477832931399452959485436508026184056065950026237498777542868900125107440263366181800815197222515959607390095579485291273760738371089390688400602480049449464040449973013653199205442048099332505090704566965249504775847001742007999778295684369947675719051918573
Ciphertext of b: 4619495029792625370548443266937361769024603598556173277837228939984181705657626359593246306057404103647683110898973041671988761868732569408325473877243831564366544534890695406931048322823536898503109887837421659041710175104440155803210157938109379947660688616193105569019298021422939163172021982124419488592068823200321781744092749542134323571140167009883285446979254525027200091899323742227247686173667713275929840651492453623506514658289683333164918318584274458486321668129903920657532155825995750517914050741138474361476168607523673353155703311373935910541786017628814328669851195140299002765327635091482876927585
Ciphertext of a + b: 5441632483514900858691488001264536821816039449757926222711030200851353820970382481473112703910255679897875010665045841191527592683925973306397817962236025838572139698618623103685482638997855159365043388468877292972076934743008688013751842522899761695812043789314046537972073757337121113430753088987367637304611947412168271544167359511732805337072066718695317945938231443501554512267204827607266528741339623003520960589047282301283482090502257976338353994403757682454596064716491613568005560841140486952963515696792103770397221638946811171820753244060269558066870760039673736152334975696082783841797169273832905074100
Decrypted sum: 40
Expected sum: 40
"""