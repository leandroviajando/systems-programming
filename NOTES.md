# Computer Science

## [Theory of Computation](https://www.educative.io/courses/theory-of-computation)

A **computation** is the execution of a self-contained procedure that processes input, unaided by outside intervention once it starts, and, if all goes well, eventually halts, yielding output that corresponds to the input given. For example, running a compiler on source code as input and receiving an executable file as output is a computation. A computation that always halts is called an **algorithm**.

### Formal Languages

A **formal language** is a set of strings formed with symbols from some finite alphabet. When studying formal languages, we are interested in the many ways symbols can be validly combined to form valid strings for a given context. We talk about **tokens** (or words), **sentences** (or phrases), which are sequences of tokens, and **language structure**, which defines how strings may be properly classified.

Operations in formal languages include:

- Length $|x|$, e.g. $|abc| = 3$
- Concatenation $xy$, e.g. $abc \cdot def = abcdef$
- Repetition $x^n$, e.g. $abc^3 = abcabcabc$
- Kleene star $x^*$, e.g. $abc^* = \{\lambda, abc, abcabc, \ldots\}$ where $\lambda$ is the empty string
- Reversal $x^R$, e.g. $(abc)^R = cba$

### Finite State Machines / Finite Automata

A **deterministic finite automaton (DFA)** is a finite state machine consisting of the following:

- A set of **states** $Q$, one of which is the initial (or start) state, and a subset of which are final (or accepting) states.
- An **alphabet** $\Sigma$ of valid input symbols.
- A **transition function** $\delta: Q \times \Sigma \to Q$ which, given a state and input symbol, determines the next state of the machine.

A **nondeterministic finite automaton (NFA)** is a finite state machine consisting of the following:

- A set of **states** $Q$, one of which is the initial (or start) state, and a subset of which are final (or accepting) states.
- An **alphabet** $\Sigma$ of valid input symbols.
- A **transition function** $\delta: Q \times (\Sigma \cup \lambda) \to 2^Q$ which, given a state and input symbol (which could be $\lambda$), determines the set of possible next states of the machine (i.e., a choice of states).

The difference lies in the definition of the transition function, namely:

- A $\lambda$ is a valid input (i.e., we can move without consuming any input).
- More than one state may be reached by the same input symbol.
- It is possible that no transitions exist at all for a particular input (an implicit jail).

The notation $2^Q$, sometimes written $P(Q)$, denotes the power set of states $Q$, i.e., the set of all possible subsets of $Q$. For example, $Q = \{q_0, q_q\} \implies 2^Q \ \{ \phi, \{q_0\}, \{q_1\}, \{q_0, q_1\} \}$ and $|2^Q| = 2^{|Q|} = 2^2 = 4$.

NFAs have one more interesting feature: they can move from one state to another “on a whim”—in other words, without consuming any input at all. We indicate this with a **lambda transition**.

**Equivalence**: Every NFA has an equivalent DFA, and every DFA has an equivalent NFA. This means that for every NFA, there exists a DFA that accepts the same language, and vice versa.

### Regular Expressions

Regular expressions include:

- The empty language / set $\emptyset$
- The one-string language / set $\{\lambda\}$
- For each parameter $a \in \Sigma$, the one-string language / set $\{a\}$
- The union of two languages / sets $L_1 \cup L_2$
- The concatenation of two languages / sets $L_1 \cdot L_2$
- The Kleene star of a language / set $L^*$
- The complement of a language / set $L^c$
- The intersection of two languages / sets $L_1 \cap L_2$
- The difference of two languages / sets $L_1 - L_2$
- A grouping of symbols $(L)$

Equivalence: Every regular expression has an equivalent regular language.

### Regular Languages

A **regular language** is a formal language for which there exists a deterministic finite automaton that accepts all and only those strings in the language. Regular languages are closed under the following operations:

- Union
- Concatenation
- Kleene star

### Turing Machines

A standard Turing machine is a deterministic automaton with a two-way infinite tape, along with the following:

- A set of states $Q$, one of which is the initial (or start) state, and a nonempty subset of which, say $H$, contains **halt states**.
- An input alphabet $\Sigma$.
- A tape alphabet $\Gamma$ that includes $\Sigma$, a special **blank symbol** $\sqcup$, and other arbitrary symbols as needed.
- A tranition function $\delta: Q \times \Gamma \to Q \times \Gamma \times \{L, R\}$ that, given a state and tape symbol, determines the next state, tape symbol, and direction of movement.

## [Introduction to Logic: Basics of Mathematical Reasoning](https://www.educative.io/courses/introduction-to-logic-basics-of-mathematical-reasoning)

TODO

### Propositional Logic

### First-Order Logic

## [Number Systems for Computer Scientists](https://www.educative.io/courses/number-systems-for-computer-scientists)

The decimal system leverages the fact that humans have ten fingers to count with. The binary system does something similar in the case of computers.

An essential component of computers is the transistor, which has two states, on and off. These are sometimes also referred to as high and low states, and correspond to the presence or absence of voltage.

Because 2 is a small base, it takes a large number of digits to represent a value, and the problem here is that it is hard for humans to accurately read and write a number in binary.

So we need a method better than a string of 1’s and 0’s to represent binary numbers. Four binary bits can represent the numbers from 0000 to 1111, or 0−15. This is a total of 16 numbers, so we would need our system to have 16 base symbols. Thus our system will be base-16, i.e. hexadecimal.

For example, in this case, we can remember the number by keeping track of `3 8 4` (the corresponding decimal values of the three groups of binary digits) and then expanding out the full binary form: `0011 1000 0100`.

$16^n = 2^{4n}$

The hexadecimal system’s main power lies in the compactness and ease of representation it brings to the binary system!

In general, for an `n`-base number system, we would need `n` base symbols. And the range that can be represented by `k` digits of an `n`-base number system is `0` to `n^k - 1`.

### Binary Operations

- **Addition**: `0 + 0 = 0`, `0 + 1 = 1`, `1 + 0 = 1`, `1 + 1 = 10`
- **Subtraction**: `0 - 0 = 0`, `0 - 1 = 1`, `1 - 0 = 1`, `1 - 1 = 0`
- **Multiplication**: `0 * 0 = 0`, `0 * 1 = 0`, `1 * 0 = 0`, `1 * 1 = 1`
- **Division**: `0 / 0 = 0`, `0 / 1 = 0`, `1 / 0 = 0`, `1 / 1 = 1`
- **Modulus**: `0 % 0 = 0`, `0 % 1 = 0`, `1 % 0 = 0`, `1 % 1 = 0`
- **Left Shift** multiplies a binary number by 2: `0 << 0 = 0`, `0 << 1 = 0`, `1 << 0 = 1`, `1 << 1 = 10`, `1 << 2 = 100`
- **Right Shift** divides a binary number by 2 and discards the remainder: `0 >> 0 = 0`, `0 >> 1 = 0`, `1 >> 0 = 1`, `1 >> 1 = 0`, `10 >> 1 = 1`, `100 >> 2 = 1`

It seems like a neat trick to be able to have a special operator to multiply or divide a number by powers of 22, but what is the use of shift operators beyond that?

One aspect is speed; using shift operators is usually much faster on the computer than carrying out the multiplication or division.

Another scenario is when working with bit sequences. Sometimes programmers will have to work with strings of bits instead of the decimal integer values they represent. In this case, shift operations come in handy.

### Signed Binary Numbers

A number’s representation in **sign magnitude** has the same number of bits as the original number, plus a bit called the sign bit on the extreme left (the MSB). The sign bit denotes that the number is negative if it is set to 1 and positive if it is set to 0.

The sign-magnitude representation has limitations, such as the duplication of zero representations and increased complexity in comparison operations.

**One’s complement** representation is another way of representing signed numbers. A number’s representation in one’s complement has the same number of bits as the original number, plus a bit called the sign bit on the extreme left (the MSB). The sign bit denotes that the number is negative if it is set to 1, and positive if it is set to 0. To represent a negative number, the other bits hold the complement of the original number in binary. To represent a positive number, the bits hold the number as it is in binary.

One of the major drawbacks of one’s complement is that it has two representations for 0, a negative 00 and a positive 0. For an 8-bit representation, these are 00000000 and 11111111. This is wasteful, because we lose out on one representation of one number.

**Two’s complement** is the most widely used representation of signed numbers. It provides ease of representation and computation. Unlike one’s complement, two’s complement has a unique representation for 0. Two’s complement representation also has a sign bit on the extreme left. Because there’s a unique representation of 0, the range of two’s complement is larger than one’s complement.

To represent a number in two’s complement, we follow the steps below:

1. Write the number in binary.
2. Take the complement of the number.
3. Add 1 to the number.

### Representing Numbers with Fractional Parts

**Fixed point notation** reserves a given number of trailing bits for the fractional part of a number. The number of bits reserved for the fractional part is called the fixed point. For example, `10110010` with four bits reserved for the fractional part would represent the number `11.125`.

To represent a decimal number in scientific notation, we set the decimal point to the right of the first non-zero digit in the number and set the power of 10 accordingly. Scientific notation makes the computation incredibly easy, and also provides a way to represent large numbers using fewer digits and less space, because we only need to store the exponent and the number before the multiplication sign (called the mantissa).

TODO: continue here <https://www.educative.io/courses/number-systems-for-computer-scientists/floating-point-representation>

### Representation in a Computer

A **byte** is a group of eight bits. A byte encompasses $2^8$ different combinations. It can represent the decimal numbers from 0 to 255, numbers in two's complement from -128 to 127, and a single character using ASCII.

Groups of different numbers of bytes then go on to represent larger numbers. For example, 4 bytes are used to store single precision floating points, and 8 bytes are used for double precision floating points.

## [Information Representation](https://www.educative.io/courses/information-representation-computer-systems)

### What is a Computer?

Any computer system can be built with only four basic functionalities:

- Input, e.g. a mouse, microphone, etc.
- Storage, e.g. hard drive, RAM, etc.
- Processor: an electronic circuit that can process the information, e.g. CPU, GPU, etc.
- Output, e.g. a monitor, printer, etc.

### Binary Digits and Bytes

One bit can store one of the two values, 0 or 1, on or off. A byte is a group of 8 bits.

A byte has 256 different configurations which means that a byte can store 256 different numbers. The maximum value that one byte can store is 255, whereas the minimum value that it can store is 0. Two bytes can store 65536 different configurations, ranging from to 65535.

### Number and Letter Representation

There are two Unicode Transformation Formats (UTFs) that can encode Unicode code points into bits:

- UTF-8 uses 1 to 4 units of 8 bits
- UTF-16 uses 1 or 2 units of 16 bits.

If the code point of a character is only 8 bits long, UTF-8 encodes it with a single byte as shown in Table 3. Note that UTF-16 and UTF-32 encode the characters with two bytes and four bytes, respectively. However, there is no difference in the code points or the hex values. A 16-bit value corresponding to an 8-bit value will just have 8 leading zeros. Therefore, encoding such characters with UTF-16 or UTF-32 leads to a wastage of memory in this case.

### Digital Logic Gates

A logic gate is a physical electronic device with either one or two bit inputs and only one-bit output.

- **AND Gate**: The output is 1 if and only if both inputs are 1.
- **OR Gate**: The output is 1 if at least one of the inputs is 1.
- **NOT Gate**: The output is the opposite of the input.
- **XOR Gate**: The output is 1 if and only if one of the inputs is 1.
- **NOR Gate**: The output is 1 if both inputs are 0.
- **NAND Gate**: The output is 0 if and only if both inputs are 1.
- **XNOR Gate**: The output is 1 if and only if both inputs are the same.

### Hardware Components of a Computer

Von Neumann architecture:

- Input unit
- Output unit
- Storage unit
- Central Processing Unit (CPU)

To store one bit of data in memory, we use a circuit, called a latch, that remembers or stores the previous input unless it is reset.

Random Access Memory (RAM) is a type of volatile memory that stores data temporarily. It is volatile because it loses its data when the power is turned off.

Secondary memory (e.g. hard disks, etc.) are forms of non-volatile memory that stores data permanently.

The central processing unit (CPU) takes data from the main memory, processes it, and returns the modified data into the main memory. It comprises two subunits called the control unit (CU) and the arithmetic logic unit (ALU). As the name suggests, the arithmetic logic unit processes the data, whereas the control unit controls data flow to and from the main memory.

Assembly language is referred to as a low-level language since it’s very similar to machine language. It is a human-readable version of machine language that uses mnemonics to represent machine instructions. One instruction in assembly language corresponds to one machine instruction.

### Data Representation in Python

```python
import numpy as np

#creating an uninitialised array
arr = np.empty((2), dtype = int)
print("Empty array:", arr)

#creating an array of zeros
arr1 = np.zeros((3), dtype = int)
print("Array of zeros:", arr1)

#creating an array of ones
arr2 = np.ones((7), dtype = int)
print("Array of ones:", arr2)
```

An English letter can easily be represented using 1 byte. In the code snippet below, we are finding the length of a UTF-8 encoded character that has the value A. Run to verify that it is indeed 1 byte.

```python
char = "A"

print("My character:" + char)
length = len(char.encode('utf-8'))

print("The length of a character in bytes:", length)
```

```python
char = "A"

print("My character:" + char)
length = len(char.encode('utf-16'))
print("My character in hex:", bytes(char, "UTF-16"))

print("The length of a character in bytes:", length)
```

In Python, a string is a UTF-8 encoded character sequence, used to store text or perform operations on it.

A file is a collection of related information that is recorded on secondary storage devices like magnetic disks, hard disks, and tapes. It acts as a medium for giving input and receiving output from a program.

In secondary storage, files are stored as streams of zeros and ones. We use ASCII and Unicode to convert binary data to human-readable format to process textual information from a file.

A few bytes in every file represents the format information and is called the metadata or the data about data. The metadata gives some description of features or characteristics of a particular data item to be able to process it correctly.

A file system is necessary to organize the files in memory so that the computer can differentiate between the files and easily access them.

### Image, Audio and Video Representation in Python

Each pixel on a classic computer screen (at the hardware implementation level) consists of three dots of colored phosphor: red, green, and blue. Mixing the red, green, and blue channels in varying proportions or intensities can result in many different colors.

Colored pixels can also be black or white in an image. The pixel appears black when the intensities of the three channels are set to 0, 0, 0, whereas it appears white when the intensities of the three channels are set to 255, 255, 255.

Observe that 4 bits correspond to 1 hexadecimal number. The color black is represented by the hex code 000000, whereas the color white is represented by the hex code FFFFFF. Similarly, all possible color combinations can be represented in hex codes.

```python
import numpy as np
import matplotlib.pyplot as plt

def create_image(size):
    """Create a simple black and white image"""
    img = np.zeros((size, size), dtype=bool)
    img[size//4:size*3//4, size//4:size*3//4] = True
    img[size//3:size*2//3, size//3:size*2//3] = False
    img[size//2, size//2] = False
    return img

def show_image(img):
    plt.imshow(img, cmap='gray')
    plt.show()

size = 100
img = create_image(size)

show_image(img)

not_image = np.logical_not(img)
and_image = np.logical_and(img, img)
xor_image = np.logical_xor(img, img)

show_image(not_image)
show_image(and_image)
show_image(xor_image)
```

### Data Compression

Lossy compressions allow a reduction in the size of a file by removing unnecessary or less important data. However, removing data can distort the original file and, therefore, lossy compressions are only used where a slight distortion to a file is tolerable because sometimes the loss in detail is barely noticeable by humans. The amount of data reduction possible using lossy compression is much higher than through lossless techniques.

## [Bit Manipulation](https://www.educative.io/courses/bit-manipulation)

Bit manipulation is the act of algorithmically manipulating bits or other pieces of data shorter than a word. Bitwise operations are incredibly simple and faster than arithmetic operations.

1. **Bitwise Conjunction (`&`) - AND Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100
       int b = 25;     // Binary: 11001

       int result = a & b;   // 1100 & 11001 = 1000 (8 in decimal)

       printf("Result of bitwise AND: %d\n", result); // Output: 8

       return 0;
   }

   ```

   ```python
   def is_even(n: int) -> Literal["even", "odd"]:
       return "even" if (n & 1)==0 else "odd"

   ```

2. **Bitwise Disjunction (`|`) - OR Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100
       int b = 25;     // Binary: 11001

       int result = a | b;   // 1100 | 11001 = 11101 (29 in decimal)

       printf("Result of bitwise OR: %d\n", result); // Output: 29

       return 0;
   }

   ```

3. **Bitwise Exclusive OR (`^`) - XOR Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100
       int b = 25;     // Binary: 11001

       int result = a ^ b;   // 1100 ^ 11001 = 10101 (21 in decimal)

       printf("Result of bitwise XOR: %d\n", result); // Output: 21

       return 0;
   }

   ```

   ```python
   def swap(a: int, b: int) -> Tuple[int, int]:
       a ^= b
       b ^= a
       a ^= b
       return a, b

   a, b = 10, 121
   a, b = swap(a, b)
   print(a, b)  // Output: 121 10

   ```

   ```c++
   #include <iostream>
   #include <string>

   string oppositeSign(int x, int y) {
       return (x ^ y) < 0 ? "Signs are opposite" : "Signs are not opposite";
   }

   int main() {
       int x = 100, y = -1;
       std::cout << "For inputs " << x << " , " << y << " : " << oppositeSign(x, y) << std::endl;
       int z = 100, p = 501;
       std::cout << "For inputs " << z << " , " << p << " : " << oppositeSign(z, p) << std::endl;
       return 0;
   }

   ```

4. **Bitwise Negation (`~`) - NOT Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100

       int result = ~a;   // ~1100 = 0011 (-13 in decimal)

       printf("Result of bitwise NOT: %d\n", result); // Output: -13

       return 0;
   }

   ```

5. **XOR Logic Gate inverts the AND Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100
       int b = 25;     // Binary: 11001

       int result_and = a & b;   // 1100 & 11001 = 1000 (8 in decimal)
       int result_xor = ~result_and; // Inverting the AND result

       printf("Result of inverted AND (XOR): %d\n", result_xor); // Output: -9

       return 0;
   }

   ```

6. **NOR Logic Gate inverts the OR Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100
       int b = 25;     // Binary: 11001

       int result_or = a | b;   // 1100 | 11001 = 11101 (29 in decimal)
       int result_nor = ~result_or; // Inverting the OR result

       printf("Result of inverted OR (NOR): %d\n", result_nor); // Output: -30

       return 0;
   }

   ```

7. **Bitwise Left-Shift (`<<`) - Doubling Signed Integers**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100

       a <<= 1;   // Left shift a by 1 bit: 11000 (24 in decimal)

       printf("Result of left shift: %d\n", a); // Output: 24

       return 0;
   }

   ```

8. **Bitwise Right-Shift (`>>`) - Halving Signed Integers**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100

       a >>= 1;   // Right shift a by 1 bit: 110 (6 in decimal)

       printf("Result of right shift: %d\n", a); // Output: 6

       return 0;
   }

   ```

   ```c++
   #include <iostream>

   int bitsLength(int n){
       int bitsCounter = 0;

       while((1 << bitsCounter) <= n){
           bitsCounter += 1;
       }

       return bitsCounter;
   }

   int main() {
       std::cout << bitsLength(8) << std::endl;  // Output: 4
       std::cout << bitsLength(2) << std::endl;  // Output: 2
       std::cout << bitsLength(7);
       return 0;  // Output: 3
   }

   ```

9. **Bitwise Assignment Operators (`&=`, `|=`, `^=`, `<<=`, `>>=`)**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100

       a <<= 2;   // Left shift a by 2 bits: 110000 (48 in decimal)

       printf("Result of left shift: %d\n", a); // Output: 48

       return 0;
   }

   ```

## [Operating Systems (40h)](https://www.educative.io/courses/operating-systems-virtualization-concurrency-persistence)

Writing to a file: `>` (overwrite) or `>>` (append)

Redirect standard error `2>` to a file:

```bash
command 2> error.txt
```

Redirect standard output `>` and standard error `2>` to a file:

```bash
command > output.txt 2> error.txt
```

Redirect standard error to standard output:

```bash
command 2>&1
```

[Writing an OS in Rust](https://os.phil-opp.com/)

### The OS Kernel

### Process Management: Processes, Threads, and Inter-Process Communication

### Time Management: CPU Scheduling Algorithms

### Resource Management

#### Synchronisation

#### Mutual Exclusion

#### Semaphores

#### Deadlock Prevention

#### Deadlock Avoidance and Detection

### Memory Management

#### Allocation, Protection, and Sharing of Memory

#### Physical and Virtual Memory

#### Paged Virtual Memory

### Storage Management

#### Storage Technologies

#### File Systems

### Virtualisation

#### Virtual Machines

#### Containers

## [Computer Security](https://www.educative.io/courses/practical-security-defending-your-systems)

### Patching

Even if all the code that you write is perfect, you’re still at risk. You’re dependent on lots of software written by third parties.

Once a vulnerability is made public, security researchers and criminals alike start writing tools to scan for vulnerable computers.

**Patching** is the time-critical process of updating third-party libraries or software to fix vulnerabilities.

Good patching practices:

- Knowing what software you have in place.
- Researching what vulnerabilities have been discovered in that software.
- Upgrading the vulnerable software to secure versions.
- Testing to make sure that the new versions work and don't break anything.

In order to be ready to upgrade, we need to be relatively current with our dependencies. We can’t remain on old, unsupported versions of software, even if the old versions are functionally sufficient. There could be **breaking changes** between our old, vulnerable version of that library and the current version.

**CVE** stands for common vulnerabilities and exposures. It is the closest thing the field has to a centralized repository of vulnerabilities. Many operating system vendors and large software vendors track their own security vulnerabilities in the public CVE list.

OWASP has a free, open-source tool called **Dependency-Check** that can help automate the detection of vulnerable third-party libraries. An alternative is **Dependabot**, for example.

The **principle of least privilege** mandates that a process should have the lowest level of privilege needed to accomplish its task. This never includes running as root (UNIX/Linux) or administrator (Windows). Anything application services need to do, they should do as nonadministrative users.

**Nmap** is a versatile open-source network-scanning tool.

- What machines are on our network
- What ports are open on those machines
- What operating systems are running on those machines

Nmap scans can be used to identify anomalies in the traffic that could potentially help uncover malware. For example, a HTTP server that is running on a machine that should not be running a HTTP server.

Why patch frequently?

Martin Fowler has written about the saying, “If it hurts, do it more often” as it pertains to activities like deployments and integration. This idea fits wonderfully into a discussion on patching. Fowler gives three main reasons why doing painful things more often makes them less painful over time:

- It breaks work into small, manageable pieces.
- It adds opportunities for feedback.
- It provides practice and the potential for automation.

### Vulnerabilities

#### SQL Injection

If you find yourself in a situation where you can’t protect yourself with prepared statements and concatenation is the only way to build the query you want, you’ll need to check that the data you’re concatenating is safe. One way to achieve this is to introduce a **level of indirection** so that the attacker picks an ID that corresponds to one option in a list of options but the attacker doesn’t get to provide the table name itself.

While it isn’t worthwhile to introduce a **dedicated database account** for every table, it can be worthwhile to introduce them for particularly sensitive tables, such as audit tables or tables that contain passwords. It would be unfortunate if SQL injection in some random part of your application allowed an attacker to change admin passwords or cover their tracks by deleting audit records.

#### Cross-Site Scripting (XSS)

We call this attack cross-site scripting (or XSS for short) if the attack injects JavaScript. We call it DOM injection if it injects regular HTML.

Recall that JavaScript has the full ability to interact with all browser UI widgets such as buttons, links, text boxes, and radio buttons.

Batching a few of these interactions together means that JavaScript can be written to do anything that the logged-in user can do. This includes things like authoring new blog posts, changing the password of the logged-in user, deleting posts, adding comments to other posts—anything that a logged-in user can do.

**HTML encoding** can help us defend against XSS attacks. Whenever we’re building up HTML as part of our response to a web browser, if we ever concatenate in user-controlled data, we need to HTML-encode it first. That way, even if an attacker tries to sneak JavaScript into one of our responses, we’ll encode it first and the browser will just display JavaScript source code to the user instead of executing attacker-controlled JavaScript.

#### Cross-Site Request Forgery (XSRF)

If XSS is a case of a browser trusting JavaScript from the server too much, XSRF is a case of a server trusting a browser too much.

The defense against this is the XSRF hidden form input. When a user logs into the blog site, the blog site should set a large (say 128 bits, base64–encoded) cookie valid only for the duration of the session. Every page that contains a form that will POST back to the blog server needs to put that same value into a hidden form input. Only the blog site and the browser have this value.

There’s an important caveat to XSRF defense. If the page is vulnerable to cross-site scripting (XSS), then the XSRF defenses will be bypassable. So it’s important to make sure that our web applications are not vulnerable to XSS. To see why XSS can bypass XSRF defenses, let’s think back to how XSRF defenses work. They add a little bit of secret information that wouldn’t be exposed or sendable from other websites. Typically, this is done with a hidden form input. If there’s XSS on a page with a hidden form input, malicious JavaScript can be injected into the page to send a request with the XSRF defense value.

It would be nice if we could layer on a one-time effort to help lessen the impact if we ever forget to be diligent in the future. That is the idea behind **SameSite cookies**.

#### Misconfigurations

One tool that can help with finding misconfigurations like this is Scout2. **Scout2** is an open-source tool designed to look for a wide range of AWS misconfigurations, not just overly permissive S3 buckets.

**Jenkins** has a common misconfiguration that merits special mention. Jenkins instances are often started with insecure settings that allow for unauthenticated execution of commands in a scripting language called Groovy. Groovy scripts can execute arbitrary shell commands. So a common attack is to scan the network for misconfigured Jenkins servers, use the Groovy Scripting Console to dump passwords from the Jenkins server, then use those passwords to compromise other servers on the network.

So make sure to lock down Jenkins so that it requires a login before allowing any of its functionality, especially the Groovy Scripting Console.

### Cryptography

Don't write your own cryptographic algorithms. Bugs can have a huge impact. Use well-known, well-tested libraries.

Don't use low-level crypto libraries. They are easy to misconfigure. Use high-level libraries that have been designed to be hard to misuse.

Use NaCl, libsodium, or Tink for encryption at rest. Use TLS 1.3 (or TLS 1.2 if you have legacy constraints) in a configuration that gets an A from SSL Labs for data in transit. Use scrypt, bcrypt, PBKDF2, or Argon2 for password hashing.

Minimising the cost of credential loss:

- Limit the time a credential is valid
- Limit the power of a credential with 2FA
- Limit the scope of a credential

### Phishing

In a phishing attack, the attacker sends an email to the victim and tricks the victim into doing something the attacker wants them to do-generally, reveal their login credentials. No need for an attacker to look for unpatched servers, weak cryptography, or SQL injection if they can just log in and use the system as a legitimate user.

**XSRF**: If you’re logged in to your bank’s website and the bank’s website doesn’t defend against XSRF, and then you click on a link in a phishing email, the phisher can take over your browser to interact with the bank’s website. The bank’s website will think it’s you, and the phisher can transfer money out of your account.

**Social engineering** is a less technical type of attack. In this kind of attack, a phisher would pretend to be someone they’re not and ask for things they shouldn’t have—HR records, banking information, passwords, and so on. This kind of attack is different because it probably won’t contain a link to a malicious or XSRF-vulnerable website. It probably just comes out and asks the intended victim to do something on behalf of the phisher.

**Malware-based phishing** emails are the least likely attack. It’s comparatively hard to write custom malware to attack phishing victims. Most of the time phishers are just after credentials anyway. And the odds of stealing credentials are so high that it’s generally not worth the effort to try to develop custom malware.

#### DNS-Based Defence

SMTP lets anyone send email from any address. That’s problematic, and it’s part of why there’s so much spam. Anyone can connect to bob.com’s SMTP server and claim to be sending legitimate email from alice.com.

**Sender Policy Framework (SPF)** is a technology that enables the administrators of a domain to specify which computers are authorized to send an email on behalf of that domain. SPF leverages the Domain Name System (DNS) to distribute this information. This lets a mail server determine whether incoming email is legitimate.

**Domain Keys Identified Mail (DKIM)** lets us lock down who can send an email for our domain via cryptography. It can be used in addition to SPF. When we set up a domain to use DKIM, we add a public key to the DNS records for our domain, and then our mail server uses the corresponding private key to sign our outgoing emails. That way, when the mail server at another domain receives an email claiming to be from our domain, that mail server can look up our public key in DNS and verify that the signature on the email is legitimate.

**DMARC, or Domain-Based Message Authentication, Reporting, and Conformance** is another DNS-based email tool. It’s built on top of SPF and DKIM and has two main uses. First, it can be used to help troubleshoot complex SPF and/or DKIM rules. Second, it can be used to collect forged emails for later analysis.

#### Authentication-Based Defence

There are a variety of 2FA options. Apps that run on your smartphone seem to be the most popular. Some of the smartphone-based 2FA apps communicate over SMS, which isn’t ideal. Phone companies can be social-engineered into making account changes. And attacks on the cell phone network itself are possible.

You’re still much better off with SMS-based 2FA than with no second factor. But if you have the choice, **prefer non-SMS-based 2FA**. Requiring 2FA for logins helps decrease the value of stolen credentials. It also helps in the face of credential-stuffing attacks.

Credential stuffing is an attack that targets password reuse. After a breach that results in a large number of leaked usernames and passwords, attackers can try those username/password combinations against other online services.

**U2F** is a more advanced form of 2FA. It is an open standard designed to [address a couple of the shortcomings of typical 2FA](https://fidoalliance.org/). If you have the option, choose U2F.

## [Computer Networking](https://www.educative.io/courses/grokking-computer-networking)

A network is officially defined as a group or system of interconnected people or items.

So, by this definition, train stations connected to each other with rail tracks make up a railway network. People who follow each other on Twitter make up an online social network.

Similarly, computers connected to each other with cable or wireless radio make up a computer network.

Two main purposes:

- Communication
- Sharing of resources

### The Internet

The **internet** is a network of subnetworks that consist of computers that are connected to each other.

The Internet is a network of networks of comupters whereas as the world wide web is information that can be accessed via the Internet.

A **protocol** is a set of rules that computers use to communicate with each other.

- **The Transmission Control Protocol (TCP)** is one such protocol. It was created to allow end systems to communicate effectively. The distinguishing feature of TCP is that it ensures that data reaches the intended destination and is not corrupted along the way.
- **The User Datagram Protocol (UDP)** is also one such key protocol. However, it does not ensure that data reaches the destination and that it remains incorrupt.
- **HyperText Transfer Protocol (HTTP)** is a web protocol that defines the format of messages to be exchanged between web clients, e.g., web browsers and web servers and what action is to be taken in response to the message. The World Wide Web uses this as its underlying protocol.

Computers send messages to each other that are made up of ones and zeros (bits).

However, instead of sending messages of possibly trillions of bits all in one go, they’re broken down into smaller units called **packets** to make transmission more manageable. These smaller sizes make transmission more manageable because most links are shared by a few end-systems. Sending smaller units in succession instead of one big file all in one go makes usage of the network fairer amongst end-systems.

Every device that is connected to the Internet has an address called an **IP Address** which is much like a mailing address.

- IP addresses are 32 bit numbers (in IP version 4).
- The human readable way for looking at these numbers is the dotted decimal notation, whereby the number is considered one octet of bits (8 bits) at a time. Those octets are read out in decimals, then separated by dots.
  - Hence, each number can be from 00 to 255255. For example, 1.2.3.4.
- Some IP addresses are reserved for specific functions. We’ll discuss them in more depth in later lessons.

```bash
curl ifconfig.me -s
```

Any host connected to the Internet could be running many network applications. In order to distinguish these applications, all bound to the same IP address, from one another, another form of addressing, known as **port numbers**, is used. Each endpoint in a communication session is identified with a unique IP address and port combination. This combination is also known as a **socket**. So in essence, ports help to address the packet to specific applications on hosts.

- IP addresses identify end systems but ports identify an application on the end system.
- Every application has a 16-bit port number. So the port number could range from 0 to $2^{16}=65535$.
- The ports 0−1023 are reserved for specific applications and are called well-known ports.
  - For instance, port 80 is reserved for HTTP traffic.
- The ports 1024−49152 are known as registered ports and they are used by specific, potentially proprietary, applications that are known but not system defined.
  - SQL server for example, uses port 1433
  - It is generally considered best practice not to use these ports for any user defined applications although there is no technical restriction on using them.
- The ports 49152–65535 can be used by user applications or for other purposes (dynamic port allocation for instance, but more on that later).

### Access Networks

Access networks, also known as the last mile, consist of the media through which end systems connect to the Internet. In other words, access networks are networks that physically connect end systems to the first router (also known as the “edge router”) on a path which connects them to some other end systems.

Routers and physical media such as wires that connect two end systems are part of an access network.

Some networks have varying upload and download transmission rates, called asymmetric transmission rates. This is useful because traffic going out from end hosts generally consists of small requests which solicit comparatively much larger responses.

Types of Access Networks:

- A **Digital Subscriber Line or DSL** uses the existing groundwork of telephone lines for an Internet connection. DSL connections are generally provided by the same company that provides local wired phone access. The telephone wire’s frequency spectrum is divided into 3 parts:
  - A downstream channel (which is used to receive data), in the 50 kHz to 1 MHz frequency range or ‘band’
  - An upstream channel (used to send data) which takes up the 4 kHz to 50 kHz band
  - A regular channel used for telephone conversations taking up the 0 to 4kHz range
- In the case of **cable** Internet, the TV cable company is the ISP and it relies on the preexisting infrastructure of cable TV to grant Internet access. It's very siimlar to DSL but slower during peak hours.
- Although DSL and cable Internet are incredibly popular, **Fiber To The Home or FTTH** is another access method. Optic fiber cables are claimed to be the cleanest method to transmit data.
- **Dial-Up** uses a modem over the telephone line, but does not fully utilize the spectrum of the transmission medium. It only uses the traditional voice channel frequencies. Hence, it is slower than DSL.
- The Internet can also be accessed via **satellites**. The transmission is slow but this option can be beneficial in remote areas where other physical access networks are not available.

### Types of Computer Networks

A medium in which the signal is transported on a confined pathway is called **guided**.

- Twisted pair copper wire
- Coaxial cable
- Fibre optic cable

Means of transmission that are not bound by a confined pathway are called **unguided media**, such as radio waves.

- Bluetooth
- Wi-Fi
- Cellular networks (3G, 4G, 5G)

By geographical distance, networks can be classified as:

- **Local Area Networks (LANs)**: These are networks that are confined to a small geographical area, such as a single building or a campus, e.g. ethernet or Wi-Fi.
- **Metropolitan Area Networks (MANs)**: These are networks that cover a larger geographical area, such as a city.
- **Wide Area Networks (WANs)**: These are networks that cover a large geographical area, such as a country or the world.

By topology, networks can be classified as:

- **Bus Topology**: All devices are connected to a single cable.
  - A break in the cable will disrupt the entire network.
  - Only one system can transmit at a time.
- **Ring Topology**: Devices are connected in a circular fashion.
  - A break in the cable will disrupt the entire network.
  - The system is uni-directional.
- **Star Topology**: All devices are connected to a central hub.
  - Hosts can all be transmitting at the same time. However, if the central device fails, the network is completely down.
- **Tree Topology**: A combination of bus and star topologies.
- **Mesh Topology**: Every device is connected to every other device.
  - Expensive.
  - Hard to scale.
  - Used in specialised applications only.

### Network Infrastructure: The OSI Model

When building a large complex system, it helps to approach the problem at gradually increasing levels of abstraction. Layered architectures give us modularity by allowing us to discuss specific, well-defined parts of larger systems. This makes changing implementation-level details and identifying bugs easier.

Each layer provides some services to the layer above it. Furthermore, the layer above is not concerned with the details of how the layer below performs its services. This is called **abstraction**.

Each layer at the sending end has a parallel in the receiving end. The application layer on one end system has a parallel on another end system, i.e., a chat app on one end system could be communicating with a chat app on another. These applications in the application layer are seemingly **communicating** with each other directly or **horizontally**. They are not aware of the layer below.

Each layer adds its own header to the message coming from above and the receiving entity on the other end removes it. The information in each header is useful for transmitting the message to the layer above. Adding the header is called encapsulation and removing it is called decapsulation.

The two most common ones are the **Open Systems Interconnection (OSI)** model and the **Transmission Control Protocol/Internet Protocol (TCP/IP)** model.

The OSI model stack:

- Application: end-user interaction
- Presentation: encoding and encryption
- Session: managing user sessions
- Transport: end-to-end communication
- Network: transportation of packets and load balancing
- Data Link: flow control, error detection and correction, encapsulating packets for transmission across a single link
- Physical: hardware transmitting bits

The OSI model is a theoretical model that is not used in practice. The TCP/IP model is the one that is used in practice. The Application, Presentation and Session layers of the OSI model are combined into the Application layer in the TCP/IP model:

- Application
- Transport
- Network
- Data Link
- Physical

Implementing intelligence in the core was too expensive, therefore, intelligence was implemented at edge devices. So, the Internet’s design was of intelligent end devices and a dumb and fast core network.

### The Application Layer

Processes on different machines send messages to each other through the computer network. The interface between a process and the computer network is called a socket - a combination of the IP address and a port number. Note that sockets do not have anything to do with hardware – they are software interfaces.

#### Hypertext Transfer Protocol (HTTP)

TODO: continue here

#### Cookies

#### Email: SMTP, POP, IMAP

#### Domain Name System (DNS)

### The Transport Layer

### The Network Layer

### The Data Link Layer

## [Databases (19h)](https://www.educative.io/courses/deep-dive-into-the-internals-of-the-database)
