# Grocery Tracker

## Overview

The Grocery Tracker is a C++ console application that reads grocery item names from a text file, counts how many times each item appears, and stores the results using an STL map. The application provides an easy way to search for item frequencies, display all grocery items with their purchase counts, and create a backup data file for future use.



## Features

- Reads grocery items from an input text file
- Counts the frequency of each grocery item
- Converts item names to lowercase for consistent counting
- Stores frequency data using `std::map`
- Searches for the frequency of a specific item
- Displays all grocery items and their frequencies
- Creates a backup frequency file (`frequency.dat`)
- Uses object-oriented programming principles



## Technologies Used

- C++
- Standard Template Library (STL)
- `std::map`
- `fstream`
- `string`
- Object-Oriented Programming (OOP)



## How It Works

1. Opens the grocery input file.
2. Reads each grocery item line by line.
3. Converts each item to lowercase.
4. Stores and updates item frequencies using an STL map.
5. Allows users to:
- Search for an item's frequency
- Display all item frequencies
- Generate a backup frequency file



## Example Input


Spinach
Radishes
Broccoli
Peas
Cranberries
Broccoli
Potatoes




## Example Output


broccoli 2
cranberries 1
peas 1
potatoes 1
radishes 1
spinach 1




## Concepts Demonstrated

- Object-Oriented Programming
- Classes and Encapsulation
- File Input and Output
- STL Maps
- String Manipulation
- Data Processing
- Error Handling



## Future Improvements

- Display results sorted by frequency
- Add graphical histogram output
- Allow users to add or remove grocery items
- Support multiple grocery lists
- Improve input validation
- Add automated testing



## Author

**Nigar Babayeva**

Developed as a C++ project demonstrating file processing, STL containers, and object-oriented programming techniques.

