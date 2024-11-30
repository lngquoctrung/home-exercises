window.onload = () => {
    // Get two buttons by ID
    const fetch_api_btn = document.getElementById("fetch_api_btn");
    const ajax_btn = document.getElementById("ajax_btn");

    // Add event listener for two buttons
    fetch_api_btn.addEventListener("click", load_data_by_fetch_api);
    ajax_btn.addEventListener("click", load_data_by_ajax);

    // The Fetch API callback function is called when loading by Fetch API
    function load_data_by_fetch_api(){
        /*
            (1): Send a "GET" request by Fetch API to get JSON data.
            (2): - The `response` variable is a Response object returned by Fetch API,
                    it doesn't contain the JSON data, so calling `.json()` gets another
                    promise for the body of the http response that is yet to be loaded.
                 - The callback function in the first `then` function (2) will return
                    a Promise containing JSON data.
            (3): The `response` is a JSON data from the front callback.
        */
        fetch("./data/students.json", {method: "GET"})  // (1)
            .then(response => response.json())              // (2)
            .then(response => {                             // (3)
                const json_data = response["data"];

                // If table doesn't exist then adding a new table
                if(document.getElementById("table") === null){
                    load_table_data(json_data);
                    console.log("Data is loaded by Fetch API");
                }
                else{
                    reload_table_data(json_data); // Reload data
                    console.log("Data is reloaded by Fetch API");
                }
            })
            .catch(error => {throw(error);});
    }

    // The AJAX callback function is called when loading by AJAX
    function load_data_by_ajax(){
        // Initialize XMLHttpRequest object to send request
        const xhttp = new XMLHttpRequest();
        // Change the reponse type
        xhttp.responseType = "json";
        // Specify the type of request
        xhttp.open("GET", "./data/students.json", true);
        // Define a loading data function to be called when the above request is received
        xhttp.onload = function(){
            if(this.status === 200 || this.readyState === 4){
                const json_data = this.response["data"];
                // If table doesn't exist then adding a new table
                if(document.getElementById("table") === null){
                    load_table_data(json_data);
                    console.log("Data is loaded by AJAX");
                }
                else{
                    reload_table_data(json_data); // Reload data
                    console.log("Data is reloaded by AJAX");
                }
            }
            else throw "404";
        };
        // Send the request to the server
        xhttp.send();
    }

    // Load data
    function load_table_data(json_data){
        const headers = Object.keys(json_data[0]);
        let table = document.createElement("table");
        table.setAttribute("id", "table"); // Use to check the table whether is existed or not.
        table.setAttribute("class", "table table-striped mt-2"); // Use Bootstrap
        // Add headers for the table
        let thead = document.createElement("thead");
        let thead_row = document.createElement("tr");
        thead.appendChild(thead_row);
        table.appendChild(thead);
        for(let header of headers){
            let theader = document.createElement("th");
            // Uppercase the letters
            theader.innerHTML = header==="id" ?
                header.toUpperCase() :
                header.charAt(0).toUpperCase() + header.slice(1);
            thead_row.appendChild(theader);
        }

        // Add data
        let tbody = document.createElement("tbody");
        for(let i = 0; i < json_data.length; i++){
            let trow = document.createElement("tr");
            for(let header of headers){
                let tdata = document.createElement("td");
                tdata.innerHTML = json_data[i][header];
                trow.appendChild(tdata);
            }
            tbody.appendChild(trow);
        }
        table.appendChild(tbody);
        // Add the table element
        document.getElementById("main").appendChild(table);
    }

    // Reload data
    function reload_table_data(json_data){
        const headers = Object.keys(json_data[0]);
        let table = document.getElementById("table");
        // Update headers for the table
        let thead = table.firstElementChild;  // thead
        let thead_row = thead.firstElementChild;  // tr
        for(let i = 0; i < thead_row.childNodes.length; i++){
            let theader = thead_row.childNodes[i];
            // Uppercase the letters
            theader.innerHTML = headers[i]==="id" ?
                headers[i].toUpperCase() :
                headers[i].charAt(0).toUpperCase() + headers[i].slice(1);
        }

        // Update data
        let tbody = table.lastElementChild;  // tbody
        let trows = tbody.childNodes; // tr
        for(let i = 0; i < trows.length; i++){
            let trow = trows[i]; // i-th tr
            let tdatas = trow.childNodes; // j-th td
            for(let j = 0; j < tdatas.length; j++){
                tdatas[j].innerHTML = json_data[i][headers[j]];
            }
        }
    }
}