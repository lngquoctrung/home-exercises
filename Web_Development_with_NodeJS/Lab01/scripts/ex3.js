window.onload = () => {
    // Get elements by ID
    const input_field = document.getElementById("url_input");
    const display_btn = document.getElementById("display_btn");

    // Create and append <a> and <img> elements to website
    let a = document.createElement("a");
    let img = document.createElement("img");
    a.appendChild(img);
    document.getElementById("main").appendChild(a);

    // Event listener
    display_btn.addEventListener("click", async () =>{
        const text = input_field.value;
        // Clear input field
        input_field.value = "";
        /*
        Without try - cacth
        load_image(text)
        .then(response => {
            let url = URL.createObjectURL(response);
            // Set url to "src" attribute of <image> and <a> tags
            a.setAttribute("href", url);
            a.setAttribute("download", "myimage.jpg"); // Unable download function for image
            img.setAttribute("src", url);
            img.style.cssText = "width: 60%; margin-top: 10px";
        })
        */

        try{
            let response = await load_image(text);
            let url = URL.createObjectURL(response);
            // Set url to "src" attribute of <image> and <a> tags
            a.setAttribute("href", url);
            a.setAttribute("download", "myimage.jpg"); // Unable download function for image
            img.setAttribute("src", url);
            img.style.cssText = "width: 60%; margin-top: 10px";
        }
        catch (error){
            alert(error);
        }

    });

    function load_image(url){
        return new Promise((resolve, reject) => {
            // Initialize XMLHttpRequest object to send request
            const xhttp = new XMLHttpRequest();
            // Change the reponse type - "blob" is a Blob object contaning the binary data
            // "blob" type often uses for image, video, file, ...
            xhttp.responseType = "blob";

            // Check the input field whether is empty or not
            if(url !== ""){
                // Specify the type of request
                xhttp.open("GET", url, true);
                // Define a loading image function to be called when the above request is received
                xhttp.onload = function(){
                    if(xhttp.status === 200 )
                        if(xhttp.readyState === 4)
                            resolve(this.response);
                        else  reject("404");
                    else reject("404");
                };
                // Send the request to the server
                xhttp.send();
            }
            else reject("The input text is empty");
        });
    }
}