Goal is the same as last year (and always): do as many puzzles as you can!

# Day 1
When I remembered Advent of Code, I was comfortably on my way to bed. That being said, the itch called me to get back on my laptop and to continue to ignore my homework.

## Part 1
Day 1 is a simple problem that breaks down into two main parts for me: parsing in the input and following proper rotation logic. Counterintuitively, I'm going to start with the second thing I mentioned. 

Since I'm going for solutions, not good solutions, my logic was a simple, "if the end of the line is reached, manually wrap around". A cooler option could be some sort of linked list that manually knows how to traverse itself or, if I worked in Python, a baseline array could work with minor finagling. 

Parsing the input it what got me initially sweating and it always has me sweating. This time, it caused my decision to work in C++ because from my limited experience, its the most consistent when it comes to reading in inputs [as it I know how to work with it and I understand where the errors come from]. I did the bare minimum to break my input into cars and rotation amount (thank you C++ for being strict with your typing) and for breaking out of the loop, I *admittedly* did a cheeky piece of code. Instead of looking for the end of the file [because I forgot how to and couldn't refresh my memory with a few Google searches] I abused the fact that I only looked for the left-right directions and any input that wasn't a char would break out of the loop. In this case, I typed random letters to end my loop. 

It's not the most elegant [solution](src/AoC_D1B.cpp), but it works!

## Part 2
Luckily for me, my code was *just* robust enough it could be easily edited to account for part two [side note: sorry if this isn't making sense without the questions as context; I'd rather not share them for the integrity of the challenge but I encourage you to try them on your own!]. 

My main hurdles came from not programming in C++ in a minute. Though I immediately was able to make the change to add the password to my function and make it a value by reference, I for some reason also tried to return it as a second output leading to a odd under-counting problem that took far too long to catch.

```cpp
    // Original (wrong) function
    int rotate(int start, char dir, int rotate_amount, int& password)
    {
        int num = start;
        for(int i = rotate_amount; i > 0; i--)
        {
            if(num == 0) password += 1;
            if(dir == 'L')
            {
                if(num == 0)
                {
                    num = 99;
                } else {
                    num -= 1;
                }
            } else if(dir == 'R')
            {
                if(num == 99)
                {
                    num = 0;
                } else {
                    num += 1;
                }
            }
        }
        return num, password;
    }

    // Accessed
    current, password = rotate(current, direction, amount, password);
```

Again, the [code](src/AoC_D1B.cpp) won't win any award for code golfing, but it works!

## Thoughts
Day 1 was fun! Also, [if this writing is anything to show] I shouldn't be trying to work while tired =_=. Many searches could've been avoided if advent released at 8:00 AM instead of 11:00 PM. 

Looking forward to a lot of fun challenges this year [and for the shorter year in general]!