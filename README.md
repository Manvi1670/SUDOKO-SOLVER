# 🏦 Cash Flow Minimizer System

A C++ console application that minimizes the total cash flow among multiple banks using a graph-based greedy algorithm, enhanced with payment-mode constraints (set intersection) and optimized with priority queues for scalability.

---

---

## 📘 Description

This project demonstrates a DSA implementation:
- Identifies **net balances** of banks via a directed graph of transactions.
- Applies a **greedy settlement algorithm**, pairing highest debtor & highest creditor.
- Enforces **payment-mode compatibility** using `set_intersection` on sorted sets.
- Leverages **priority queues** for O(n² log n)-time efficiency.

---

## 🧠 Features & Highlights

- ✅ **Net balance computation** for each bank (inflow-outflow).
- ✅ **Greedy settlement**: matches minimum debtor to maximum creditor until all balances settle.
- ✅ **Payment-type constraint**: transacts only if a common payment mode exists.
- ✅ **Priority queue optimization**: improves performance over linear scans.
- ✅ **Clean output**: removes redundant mutual transactions for clarity.

---

## ⚙️ Prerequisites

- C++ compiler (GCC, Clang) with C++11 support or higher.


---


## 💻 Installation & Building

```bash
# Clone the repository
git clone https://github.com/yourusername/cash-flow-minimizer.git
cd cash-flow-minimizer

# Build using g++
g++ -std=c++11 main.cpp -o cashflow

# Or using CMake
mkdir build && cd build
cmake ..
make
````

---

## 🚀 Usage

```bash
# Run the application:
./cashflow

# Example input:
3
WorldBank 2 GooglePay Paytm
BankA 1 GooglePay
BankB 1 Paytm
2
BankA BankB 100
BankB BankA 50
```

---

## 📈 Example

**Input (banks + transactions):**

```
WorldBank GooglePay Paytm
BankA GooglePay
BankB Paytm

Transactions:
BankA → BankB : Rs 100
BankB → BankA : Rs 50
```

**Output:**

```
BankA pays Rs 50 to BankB via GooglePay
```

This resolves the net balances in one optimized transaction.

---




## 👤 Author

Manvitha Bheemvarapu

* GitHub: [Profile](https://github.com/Manvi1670)

