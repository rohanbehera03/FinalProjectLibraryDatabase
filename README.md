
# Library System 
  Authors: 
  [Andrew Tee](https://github.com/atee001) [Rohan Behera](https://github.com/rohanbehera03) [Cameron Tsai](https://github.com/CJT578078)
   
## Project Description
  * Why is it important or interesting to you?
    * The ability to catagorize thousands of books is interesting as we are able to track a huge amount of data. This is a real life application of how software can benefit someone's life. A typical library catalog allows users to search for books by title, author, publisher, etc. For our project we will be developing a simple library database where the user can checkout books, find new books based on recommendations, and manage their account balance. 
  
  * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
    * We plan to use C++, vim as a text editor, and Linux as the Operating System. The user will be able to interact with the program through a terminal window using a set of predefined commands.
    
  * What will be the input/output of your project?
    * Input: Search query for books, funds, inputing books. 
    * Output: Account information, displaying books, availibility of books.
  
  * What are the two design patterns you will be using? For each design pattern you must explain in 4-5 sentences:
    * We will use strategy and composite for the searchQuery. The composite pattern is the searchOR and searchAND which contains an aggregate of the interface SearchStrat. The strategy pattern is the searchByAuthor, searchByGenre, and searchByTitle. The SearchAND and SearchOR is considered a composite since the class is a composite of Search interface pointers. The leafs are the SearchByAuthor, SearchByGenre, and SearchByTitle. The strategy pattern is allowing the user to dynamically choose which searchStrategy they want. The factory pattern is used to display the search interface to the user and the conditions for an invalid search query.

## Class Diagram
[Final Project New (3).pdf](https://github.com/cs100/final-project-rbehe002_atee001_-ctsai081/files/6577845/Final.Project.New.3.pdf)
 
 ## Screenshots
 User Interface:
 ![Screen Shot 2021-06-01 at 10 04 09 AM](https://user-images.githubusercontent.com/65427904/120363277-cd5f0d00-c2c0-11eb-9e46-d43f0cd0cf04.png)
![Screen Shot 2021-06-01 at 10 06 08 AM](https://user-images.githubusercontent.com/65427904/120363453-05fee680-c2c1-11eb-92b6-5bbcf4dcc316.png)
![Screen Shot 2021-06-01 at 10 22 19 AM](https://user-images.githubusercontent.com/65427904/120365429-47909100-c2c3-11eb-8e82-2a2702cae7ce.png)
![Screen Shot 2021-06-01 at 10 25 16 AM](https://user-images.githubusercontent.com/65427904/120365739-ab1abe80-c2c3-11eb-9506-86190227bb67.png)
![Screen Shot 2021-06-01 at 10 29 03 AM](https://user-images.githubusercontent.com/65427904/120366168-31cf9b80-c2c4-11eb-9338-507954319a58.png)
Librarian Interface:
![Screenshot (391)](https://user-images.githubusercontent.com/80326381/120368679-347fc000-c2c7-11eb-92e9-8fd172c728d8.png)
SearchBox:
![Screenshot (394)](https://user-images.githubusercontent.com/80326381/120369369-02229280-c2c8-11eb-839a-c7329e156832.png)
Removing Book from Library:
![Screenshot (396)](https://user-images.githubusercontent.com/80326381/120371895-554a1480-c2cb-11eb-9a94-3bf8b7c3b3d2.png)
Displaying all Library Books:

![Screenshot (397)](https://user-images.githubusercontent.com/80326381/120372378-fa64ed00-c2cb-11eb-8a35-fd60ebbc6127.png)



  
 ## Installation/Usage
  Click master branch. Click code and then under clone and HTTPS copy the link. Open a terminal window on your computer and type the command git clone --recursive then a space and then paste the link. Type cd final-project-rbehe002_atee001_-ctsai081 to get into the directory. Type cmake3 . and then make to compile. Then type ./driver user.txt to run the program.

 ## Testing
  Our project was test/validated with the GoogleTest C++ framework.
 
