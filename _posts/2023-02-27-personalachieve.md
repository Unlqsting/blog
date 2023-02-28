---
keywords: fastai
description: This blog contains the reflections, notes and code for the final project of the Tri2 CPT. 
title: Final Project Tri2
toc: true
badges: true 
comments: true 
categories: [CTP(tri2), week24, hacks(tri2)]
layout: markdown
---

# How to access my project (runtime Links)
- Frontend: https://unlqsting.github.io/tracker/forum
- Backend: https://lennsflask.duckdns.org/api/forum/

The first link leads you to the actual web app where you can access all of the features of my part of the group project. 

The second link leads you to the API endpoints of the project. I have linked my "read" endpoint above. The other endpoints for my part of the project are: /update, /delete, /create

# Technical Achievements:

Although most of my accomplishments are related to the frontend and creating a pleasant user experience, I still integrated features such as update and delete into the web app. I had been struggling with just getting the create and read feature to work, so I was very happy to get the other two features to work as well. Here is how I did it:

- **Update**: For this feature, getting the frontend to work was harder than the backend. The backend was much simpler. Once I had the frontend figured out where the user clicks on a post -> a modal pop-up -> user can now edit the post -> user clicks submit -> the post is updated in the database, I was able to implement the backend. The backend was just a simple PATCH request to the database. 

![image.png](attachment:image.png)

This PATCH request was sent to the /update endpoint containing the post id and the new post content. The backend then updates the post in the database after doing some validation checks (**garbage in, garbage out**). 

![image.png](attachment:image-2.png)

- **Delete**: This feature was very simple. There was no struggle for this. It was simply just obtaining the id of the clicked post and then sending a DELETE request to the /delete endpoint with the post id. 

![image.png](attachment:image-3.png)

The backend then searches through the database and looks for the specific id that was sent through the DELETE request. The backend then deletes the post from the database.

![image.png](attachment:image-4.png)

To control accidental deletes (**garbage in, garbage out**), I added a confirmation modal that pops up when the user clicks on the delete button. 


---------------------


# Personal achievements (bonus)

- I was able to get a modal to pop up when the user clicks on a post. This is done by adding an event listener to a specific html div. In the event listener, it listens for when the user clicks on a post and then it uses HTML String to create inputs with values being the post title and post body. This allows for the user to change their previous inputs of post title and post body. Clicking on the modal also allows the user to delete their blog post. 

![image.png](attachment:image-5.png) 

- talking about posts, a user can add a post the website is automatically reloaded to display the new post. This took hours for me to figure out and it was a lot of stack overflow. Here, I create a for loop that loops through a JSONified array and creates an interactable post object by using HTML String.

![image.png](attachment:image-6.png)

- Another personal achievement is not procrastinating. I was able to keep a schedule for when I would work on this project and I followed it. 

### Why are these personal achievements? 
I would consider these personal achievements because I was able to get my complicated ideas to turn into reality by just some hardwork. Usually, I would think about making this or doing that, but never really following through it. Especially the idea for the modal and displaying the posts was incredibly satisfying for me to complete. It just raised my self-esteem.

