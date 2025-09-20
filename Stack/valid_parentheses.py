def isValidParentheses(s):
    stack = []
    bracket_map = {')':'(','}':'{',']':'['}

    for char in s:
        if char in bracket_map.values():
            stack.append(char)
        elif char in bracket_map.keys():
            if not stack or stack[-1] != bracket_map[char]:
                return False
            stack.pop()
    return len(stack)==0

user_input = input("Enter a string containing brackets: ")
if isValidParentheses(user_input):
    print("The string is valid.")
else:
    print("The string is invalid.")