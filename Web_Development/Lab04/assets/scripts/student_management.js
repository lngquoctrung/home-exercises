window.onload = () => {
    const firstNameInputField = document.getElementById("firstname");
    const lastNameInputField = document.getElementById("lastname");
    const emailInputField = document.getElementById("email");
    const addButton = document.getElementById("add-btn");
    const resetButton = document.getElementById("reset-btn");

    // Add event listener for exist rows
    const tbodyTag = document.getElementsByTagName("tbody")[0];
    let trows = tbodyTag.getElementsByTagName("tr");
    if(trows){
        for(let trow of trows){
            let deleteButton = trow.getElementsByTagName("button")[0];
            deleteButton.addEventListener("click", () => {
                trow.remove();
            });
        }
    }

    // Check the input whether is valid or not
    function isValid(firstName, lastName, email){
        if(firstName === ""){
            alert("Please enter first name");
            return false;
        }
        else if(lastName === ""){
            alert("Please enter last name");
            return false;
        }
        else if(email === ""){
            alert("Please enter email");
            return false;
        }
        else if(!email.match(/(\w+)@(\w+)\.(\w+)/)){
            alert("Email is invalid");
            return false;
        }
        return true;
    }

    // Reset input field
    resetButton.addEventListener("click", () => {
        firstNameInputField.value = "";
        lastNameInputField.value = "";
        emailInputField.value = "";
    });

    // Add data
    addButton.addEventListener("click", (event) => {
        let firstName = firstNameInputField.value;
        let lastName = lastNameInputField.value;
        let email = emailInputField.value;

        if(!isValid(firstName, lastName, email)){
            event.preventDefault();
            return false;
        }

        const trow = document.createElement("tr");

        const td1 = document.createElement("td");
        td1.innerHTML = firstName;

        const td2 = document.createElement("td");
        td2.innerHTML = lastName;

        const td3 = document.createElement("td");
        td3.innerHTML = email;

        const td4 = document.createElement("td");
        const deleteButton = document.createElement("button");
        deleteButton.innerHTML = "Delete";
        deleteButton.classList.add("btn");
        deleteButton.classList.add("btn-danger");
        deleteButton.classList.add("btn-sm");
        deleteButton.addEventListener("click", () => {
            trow.remove();
        });
        td4.appendChild(deleteButton);

        trow.appendChild(td1);
        trow.appendChild(td2);
        trow.appendChild(td3);
        trow.appendChild(td4);
        tbodyTag.appendChild(trow);

        firstNameInputField.value = "";
        lastNameInputField.value = "";
        emailInputField.value = "";

        return true;
    });

}