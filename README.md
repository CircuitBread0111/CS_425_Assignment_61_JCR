# 🧵 `pth_hello.c` – Multithreaded "Hello World" in C with Pthreads

A simple C program demonstrating the use of **POSIX threads (pthreads)** to create multiple threads that each print a message. Each thread identifies itself by printing its unique thread ID and the total number of threads created.

---

## 📄 File Information

- **File Name:** `pth_hello.c`  
- **Language:** C  
- **Author:** Jerrin C. Redmon  
- **Version:** 1.0.0  
- **Date:** April 14, 2025  

---

## 🧠 Description

This program showcases basic multithreading in C using `pthread.h`. When executed, it:

- Accepts a command-line argument specifying the number of threads.
- Creates that many threads using `pthread_create`.
- Each thread prints a message containing:
  - Its thread ID (starting from 0)
  - The total number of threads
- Waits for all threads to finish using `pthread_join`.

---

## 🚀 How to Compile and Run

### 🔧 Compile

```bash
gcc -o pth_hello pth_hello.c -lpthread
```

### ▶️ Run

```bash
./pth_hello <num_threads>
```

Example:

```bash
./pth_hello 8
```

---

## 🧹 Example Output

```
Hello from thread 0 of 8 on host
Hello from thread 1 of 8 on host
Hello from thread 2 of 8 on host
Hello from thread 3 of 8 on host
Hello from thread 4 of 8 on host
Hello from thread 5 of 8 on host
Hello from thread 6 of 8 on host
Hello from thread 7 of 8 on host
```

(Note: Output order may vary due to thread scheduling.)

---

## 🧱 Code Structure

- `main`:
  - Parses command-line argument for thread count.
  - Allocates memory for thread handles.
  - Launches threads with their IDs and total count.
  - Waits for all threads to finish.
- `say_hello`:
  - Receives a pointer to a 2-element array:
    - `args[0]` = thread ID
    - `args[1]` = total threads
  - Prints the thread’s message.
  - Frees memory after use.

---

## 📦 Dependencies

- `pthread.h` — POSIX thread library  
- `stdlib.h`, `stdio.h`, `unistd.h` — Standard C headers  

Link the pthread library with `-lpthread`.

---

## 🪪 License

This project is released under the MIT License.  
Feel free to modify and use it for learning, teaching, or integration into larger projects.

---

## 👨‍💻 Author

**Jerrin C. Redmon**  
Feel free to reach out for questions or collaboration ideas!

