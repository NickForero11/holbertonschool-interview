# 0x06. Log Parsing

---

## Description

The objective of this project is create a script (`0-stats.py`) that reads stdin line by line and computes metrics:

* The data is produced by the script (`0-generator.py`).
* Input format: `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`
* After every 10 lines and/or a keyboard interruption (CTRL + C), print these statistics from the beginning:
  * Total file size: `File size: <total size>`
  * Where `<total size>` is the sum of all previous `<file size>` (see input format above)
  * Number of lines by status code:
    * Possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
    * If a status code doesn’t appear, don’t print anything for this status code
    * format: `<status code>: <number>`
    * Status codes should be printed in ascending order


---

## Author

* **Nicolas Forero Puello** - [NickForero11](https://github.com/NickForero11)
