Stack s(5); // Initialize stack with max size of 5

s.push(10);
s.push(20);
s.push(30);
cout << s.peek() << endl;  // Output: 30
s.pop();
cout << s.peek() << endl;  // Output: 20
cout << (s.isEmpty() ? "Empty" : "Not Empty") << endl;  // Output: Not Empty