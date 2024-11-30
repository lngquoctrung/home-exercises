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
    display_btn.addEventListener("click", () =>{
        const text = input_field.value;
        // Clear input field
        input_field.value = "";
        // Initialize XMLHttpRequest object to send request
        const xhttp = new XMLHttpRequest();

        // Change the response type - "blob" is a Blob object containing the binary data
        // "blob" type often uses for image, video, file, ...
        xhttp.responseType = "blob";

        // Check the input field whether is empty or not
        if(text !== ""){
            // Specify the type of request
            xhttp.open("GET", text, true);

            // Define a loading image function to be called when the above request is received
            xhttp.onload = function(){
                if(xhttp.status === 200 || xhttp.readyState === 4){
                    // `this.response` will return a Blob object
                    // Create Object URL from the Blob object
                    const url = URL.createObjectURL(this.response);

                    // Set url to "src" attribute of <image> and <a> tags
                    a.setAttribute("href", url);
                    a.setAttribute("download", "myimage.jpg"); // Unable download function for image
                    img.setAttribute("src", url);
                    img.style.cssText = "width: 60%; margin-top: 10px";
                }
                else throw "404";
            };

            // Send the request to the server
            xhttp.send();
        }
        else{
            alert("Input is empty");
        }
    });
}