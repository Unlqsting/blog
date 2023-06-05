---
keywords: fastai
description: This blog contains the reflections, notes and code for the final project of the Tri2 CPT. 
title: Final Project Tri2
toc: false
badges: true
categories: [CTP(tri2), week24, hacks(tri2)]
hide: false
nb_path: _notebooks/2023-02-26-finalproject.ipynb
layout: notebook
---

<!--
#################################################
### THIS FILE WAS AUTOGENERATED! DO NOT EDIT! ###
#################################################
# file to edit: _notebooks/2023-02-26-finalproject.ipynb
-->

<div class="container" id="notebook-container">
        
<div class="cell border-box-sizing text_cell rendered"><div class="inner_cell">
<div class="text_cell_render border-box-sizing rendered_html">
<h1 id="How-to-access-my-project-(runtime-Links)">How to access my project (runtime Links)<a class="anchor-link" href="#How-to-access-my-project-(runtime-Links)"> </a></h1><ul>
<li>Frontend: <a href="https://unlqsting.github.io/tracker/forum">https://unlqsting.github.io/tracker/forum</a></li>
<li>Backend: <a href="https://lennsflask.duckdns.org/api/forum/">https://lennsflask.duckdns.org/api/forum/</a></li>
</ul>
<p>The first link leads you to the actual web app where you can access all of the features of my part of the group project.</p>
<p>The second link leads you to the API endpoints of the project. I have linked my "read" endpoint above. The other endpoints for my part of the project are: /update, /delete, /create</p>

</div>
</div>
</div>
<div class="cell border-box-sizing text_cell rendered"><div class="inner_cell">
<div class="text_cell_render border-box-sizing rendered_html">
<h1 id="Technical-Achievements:">Technical Achievements:<a class="anchor-link" href="#Technical-Achievements:"> </a></h1><p>Although most of my accomplishments are related to the frontend and creating a pleasant user experience, I still integrated features such as update and delete into the web app. I had been struggling with just getting the create and read feature to work, so I was very happy to get the other two features to work as well. Here is how I did it:</p>
<ul>
<li><strong>Update</strong>: For this feature, getting the frontend to work was harder than the backend. The backend was much simpler. Once I had the frontend figured out where the user clicks on a post -&gt; a modal pop-up -&gt; user can now edit the post -&gt; user clicks submit -&gt; the post is updated in the database, I was able to implement the backend. The backend was just a simple PATCH request to the database. </li>
</ul>
<p><img src="/blog/images/copied_from_nb/images/update.png" alt="image.png"></p>
<p>This PATCH request was sent to the /update endpoint containing the post id and the new post content. The backend then updates the post in the database after doing some validation checks (<strong>garbage in, garbage out</strong>).</p>
<p><img src="/blog/images/copied_from_nb/images/patch.png" alt="image.png"></p>
<ul>
<li><strong>Delete</strong>: This feature was very simple. There was no struggle for this. It was simply just obtaining the id of the clicked post and then sending a DELETE request to the /delete endpoint with the post id. </li>
</ul>
<p><img src="/blog/images/copied_from_nb/images/fetch.png" alt="image.png"></p>
<p>The backend then searches through the database and looks for the specific id that was sent through the DELETE request. The backend then deletes the post from the database.</p>
<p><img src="/blog/images/copied_from_nb/images/delete.png" alt="image.png"></p>
<p>To control accidental deletes (<strong>garbage in, garbage out</strong>), I added a confirmation modal that pops up when the user clicks on the delete button.</p>
<hr>
<h1 id="Personal-achievements-(bonus)">Personal achievements (bonus)<a class="anchor-link" href="#Personal-achievements-(bonus)"> </a></h1><ul>
<li>I was able to get a modal to pop up when the user clicks on a post. This is done by adding an event listener to a specific html div. In the event listener, it listens for when the user clicks on a post and then it uses HTML String to create inputs with values being the post title and post body. This allows for the user to change their previous inputs of post title and post body. Clicking on the modal also allows the user to delete their blog post. </li>
</ul>
<p><img src="/blog/images/copied_from_nb/images/achieve1.png" alt="image.png"></p>
<ul>
<li>talking about posts, a user can add a post the website is automatically reloaded to display the new post. This took hours for me to figure out and it was a lot of stack overflow. Here, I create a for loop that loops through a JSONified array and creates an interactable post object by using HTML String.</li>
</ul>
<p><img src="/blog/images/copied_from_nb/images/achieve2.png" alt="image.png"></p>
<ul>
<li>Another personal achievement is not procrastinating. I was able to keep a schedule for when I would work on this project and I followed it. </li>
</ul>
<h3 id="Why-are-these-personal-achievements?">Why are these personal achievements?<a class="anchor-link" href="#Why-are-these-personal-achievements?"> </a></h3><p>I would consider these personal achievements because I was able to get my complicated ideas to turn into reality by just some hardwork. Usually, I would think about making this or doing that, but never really following through it. Especially the idea for the modal and displaying the posts was incredibly satisfying for me to complete and compared to other frontend web devekopment projects I have seen, my project seems like it is more of a complete frontend. It takes into consideration the user experience and it is very easy to use.</p>

</div>
</div>
</div>
</div>
 
