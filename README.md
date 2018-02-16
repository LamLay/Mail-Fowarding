# CPTR 142: Project #2
## Problem Overview
Most of us have lived in more than one home in our lives; it's common for people to move from time to time. Moving poses a number of logistical challenges, not the least of which is getting all of your belongings to your new home. But even discounting the complexity of the physical move, there are other issues to be dealt with. One of them is making sure that people and companies that you correspond with - friends, employers, banks, utility companies, and so on - have your new address, so your correspondence can continue even after your move.

Try as we might to give everyone our new address when we move, though, there's always someone we forget - some friend we haven't heard from in years, some company that we do business with only rarely - or someone who doesn't make the appropriate change in their records. Fortunately, the U.S. Postal Service provides a service called mail forwarding. Any mail addressed to you at your old address will automatically be sent to your new address instead. They even put a yellow sticker on the envelope to remind you that you should notify the sender of your new address. Very handy!

In this project, we'll explore the technological side of mail forwarding a little bit, by writing a program that determines whether individual pieces of mail should be forwarded and, if so, the address to which they should be forwarded. 

## The Program
Your program will maintain a list of forwarding entries, each consisting of a name, an old address, and a new address. The program consists of commands that allow the user to add a new forwarding entry, remove an existing forwarding entry, or report on the correct address to which a piece of mail should be sent, based on the address on the envelope.

The program should support commands similar to the following:

Command | Format | Description | Output
--------|--------|-------------|-------
ADD | ADD <br> _name_ <br> _oldAddress_ <br> _newAddress_ | Adds a new forwarding entry to the forwarding list, given the name, old address, and new address. Subsequent mailings to the named person at the old address will be forwarded to the new address. If an entry with the same name and old address exists already, adding should fail with an error message. | If a forwarding entry is added, the output should consist of the word **Added** on a line by itself. If not (because an entry for the same name and original address exists), the output should consist of the phrase **Entry already exists** on a line by itself.
REMOVE | REMOVE <br> _name_ <br> _oldAddress_ <br> _newAddress_ | Removes the forwarding entry from the forwarding list with the given name, old address, and new address, if there is one. Subsequent mailings to the named person at the old address will not be forwarded. | If a forwarding entry is removed, the output should consist of the word **Removed** on a line by itself. If not, the output should consist of the phrase **No such entry** on a line by itself.
MAIL | MAIL <br> _name_ <br> _address_ | A piece of mail is ready to be sent; it is addressed to the given name at the given address. This command checks to see if the mail should be forwarded to a different address. | This command should output the phrase **Send to**, followed by the address that this piece of mail should be sent to, on a line by itself. (If the mail is to be forwarded, its forwarding address should be printed; if not, its original address should be printed.)
QUIT | QUIT | Quits the program. | The output shoud consist of the word **Goodbye** on a line by itself.

Your program should read a sequence of commands from the console and write its output to the console. 

### A few minor, but important, notes
When you first start your program up, the list of forwarding entries should be empty.

The mail forwarding supported by your program should be recursive. (Note that you do not have to write your code recursively; you can use a loop to solve this problem instead.) For example, suppose that the following two forwarding entries are in the program's forwarding list:

*	name: Alex Thornton<br>
	old address: 123 Main St., Irvine, CA 92697<br>
	new address: 234 Main St., Irvine, CA 92697
*	name: Alex Thornton<br>
	old address: 234 Main St., Irvine, CA 92697<br>
	new address: 111 Beach Dr., Kihei, HI 96753

If a piece of mail is sent to Alex Thornton at 123 Main St., Irvine, CA 92697, the program should determine that it should be forwarded not to 234 Main St., Irvine, CA 92697, but to 111 Beach Dr., Kihei, HI 96753.

Your program is not required to parse or understand names or addresses; it's fine if they're stored as strings, and it's also fine if your program only considers a piece of mail to match a forwarding entry if the name and old address match exactly.

### An example of the program's execution

The following is an example of the program's execution, as it should be. Boldfaced, italicized text indicates input, while normal text indicates output.

> ***ADD***<br>
> ***Alex Thornton***<br>
> ***123 Main St., Irvine, CA 92697***<br>
> ***234 Main St., Irvine, CA 92697***<br>
> Added<br>
> ***MAIL***<br>
> ***Alex Thornton***<br>
> ***123 Main St., Irvine, CA 92697***<br>
> Send to 234 Main St., Irvine, CA 92697<br>
> ***MAIL***<br>
> ***Jane Doe***<br>
> ***123 Main St., Irvine, CA 92697***<br>
> Send to 123 Main St., Irvine, CA 92697<br>
> ***ADD***<br>
> ***Alex Thornton***<br>
> ***234 Main St., Irvine, CA 92697***<br>
> ***111 Beach Dr., Kihei, HI 96753***<br>
> Added<br>
> ***MAIL***<br>
> ***Alex Thornton***<br>
> ***123 Main St., Irvine, CA 92697***<br>
> Send to 111 Beach Dr., Kihei, HI 96753<br>
> ***QUIT***<br>
> Goodbye

Notice, again, that there are no prompts or other output, other than the output that is required as a response to each command. This may seem strange, but a simple, well-defined interface with no frills would be easier for another system to drive remotely. Not every program needs to have a fancy user-interface!

### Fair assumptions

It's fair to assume that your program will only receive valid input. We will not test your program with non-existent commands, nor with existing commands in the wrong format. This is not to say, of course, that error handling is unimportant in real programs, but it adds a level of complexity to this program that's more than I'd like you to be faced with. (You're free to implement error checking if you'd like, but it's not something that extra credit will be offered for.) In the event that your program receives input that doesn't follow the specifications above, it's fine for your program to ignore it, print an error message, or even crash; we won't be testing your program in these circumstances.

It's also fair to assume that there will be no "cycles" among the forwarding entries. In other words, you can assume that it will never be the case that two or more forwarding entries will exist like these, where mail is forwarded back to an address it originally came from:

* Alex - 123 Main St., Irvine, CA 92697 → 234 Main St., Irvine, CA 92697
* Alex - 234 Main St., Irvine, CA 92697 → 123 Main St., Irvine, CA 92697

Consider what would happen if we allowed entries like these to exist simultaneously. If someone sends mail to Alex at 123 Main St., Irvine, CA 92697, where should it be forwarded? To 234 Main St.? Back to 123 Main St. again? Then on to 234 Main St. again? Your program need not check for this case. You can simply assume that this case will never come up, and we won't test your program in this case. It's fine for your program runs infinitely or even crashes in this case. 

## Storing your forwarding list
One of the central tasks that this program will perform is to store and access a list of forwarding entries. For this purpose, you should use one of the techniques introduced in chapter 10 of the text (pointers and/or dynamic arrays), and not a vector.

## Code Review

You should have a code review by your professor or TA before turning in the assignment. See the Code Review Rubric document for expectations.

## Credits

This project is based on the one described by [Alex Thornton](https://www.engage-csedu.org/find-resources/you-wont-find-me-there).