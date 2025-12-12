<img align="center" src="https://spotty-grenadilla-d26.notion.site/image/attachment%3Aace81f1b-3b20-4536-887e-7f2fbfe47737%3ALinkedIn_cover_-_10.png?table=block&id=2ab113de-b78e-80b0-8f75-f08f875b1c08&spaceId=d1b02b65-6f05-41fb-9868-69f5ce300038&width=1360&userId=&cache=v2">

<img align="right" src="https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExazN1eDNwanptZ2ExZHRod3RtOXY2dmNxYWhhYnptbnNqa2txdWFxMSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/l0ErBz1hFbqcOhYJi/giphy.gif" width="500" style="margin-left: 500px; margin-bottom: 10px;">

<div style="max-width: 30%;">

get_next_line is a 42 School project to read one line at a time from a file descriptor, practicing buffers, memory management, and static variables.
This project helped me strengthen my knowledge in:

* File handling with *file descriptors*
* Buffer and string manipulation
* Memory allocation using `malloc` and proper freeing
* Managing persistent state with static variables
* Edge-case handling (EOF, giant lines, multiple FDs, etc.)

</div>
<br>

---

✅ Project completed 125% successfully as part of my 42 journey.<br>
💻 **Language:** C
<br><br>
<img src="https://github.com/danielleseragioli/42_duck_badges/blob/main/badges/gnl_pin_bonus.png">
<br>

---

# Project Overview

The project is divided into two parts: **mandatory** and **bonus**.

---
## 📚 Mandatory Part

The main function to implement is:

```c
char *get_next_line(int fd);
```

 *🎯 Goal*

Create a function that **returns one line per call**, reading from a file descriptor until no data remains.
The function must:

* Read files of any size
* Work with any `BUFFER_SIZE` value
* Maintain leftover data between calls
* Correctly return `NULL` at EOF
* Handle partial reads, fragmented lines, and dynamic memory

### ⚙️ Function Logic Overview

| Category            | Description                                                            | Internal Logic / Examples                              | Allowed Functions        |
| ------------------- | ---------------------------------------------------------------------- | ------------------------------------------------------ | ------------------------ |
| Incremental reading | Read in small chunks of size `BUFFER_SIZE` until a full line is found. | `read()` + custom join/split logic                     | `read`, `malloc`, `free` |
| String processing   | Join buffers, search for `\n`, extract substrings.                     | custom helpers: `ft_strjoin`, `ft_strchr`, `ft_substr` | Only your own functions  |
| Persistent state    | Store leftover data for the next function call.                        | `static char *stash`                                   | -                        |

---

## ⭐ Bonus Part

The bonus extends the function to support **multiple file descriptors simultaneously**, without cross-interference.

### 🎯 Bonus Objectives

* Maintain a separate stash for each file descriptor
* Handle alternating reads between different FDs
* Ensure memory integrity and efficiency

| Category            | Description                                        | Requirements                      | Allowed                  |
| ------------------- | -------------------------------------------------- | --------------------------------- | ------------------------ |
| Multiple FD support | Each FD must preserve its own leftover data        | Separate `stash[fd]` or structure | `read`, `malloc`, `free` |
| Extra robustness    | Stable behavior with mixed or alternating FD reads | Avoid memory leaks and corruption | -                        |


---

# 🧩 Concepts Reinforced

* Dynamic memory management
* Buffer handling and incremental reads
* Static variables for persistent state
* Clean separation between utility functions
* Fragmented read handling
* Defensive programming and edge-case management

---
