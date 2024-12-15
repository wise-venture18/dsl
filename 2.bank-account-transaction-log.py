"""Write a Python program that computes the net amount of a bank account 
based a transaction log from console input. The transaction log format is 
shown as following: D 100 W 200 (Withdrawal is not allowed if balance is 
going negative. Write functions for withdraw and deposit) D means deposit 
while W means withdrawal. 
Suppose the following input is supplied to the program: 
D 300, D 300 , W 200, D 100 Then, the output should be: 500"""

#CODE:-

# Functions to handle deposit and withdrawal
def deposit(balance, amount):
    return balance + amount

def withdraw(balance, amount):
    if balance >= amount:
        return balance - amount
    else:
        print(f"Insufficient funds for withdrawal of {amount}.")
        return balance

# Main code to process the transaction log
def main():
    balance = 0
    transactions = input("Enter transactions (e.g., D 300, W 200): ").split(',')
    
    for transaction in transactions:
        transaction = transaction.strip()  # Remove any extra spaces
        if transaction:
            action, amount = transaction.split()
            amount = int(amount)
            
            if action == 'D':
                balance = deposit(balance, amount)
            elif action == 'W':
                balance = withdraw(balance, amount)
            else:
                print(f"Invalid transaction type: {action}")

    print(f"Net balance: {balance}")

# Run the main function
main()
