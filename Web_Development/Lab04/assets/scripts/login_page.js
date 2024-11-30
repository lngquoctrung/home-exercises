window.onload = () => {
    const emailInputField = document.getElementById("email");
    const pwdInputField = document.getElementById("pwd");
    const errorMessage = document.getElementsByClassName("errorMessage");
    const btnSubmit = document.getElementsByClassName("btn");

    // Display error function
    function displayErrorMessage(error){
        errorMessage[0].innerHTML = error;
        errorMessage[0].classList.add("d-block");
    }

    // Hide error function
    function hideErrorMessage(){
        errorMessage[0].classList.remove("d-block");
        errorMessage[0].classList.add("d-none");
    }

    // Hide error
    hideErrorMessage();

    // Hide error message when users'r typing
    emailInputField.addEventListener("keydown", () => {
        console.log("1");
        hideErrorMessage();
    });

    // Check form whether is valid or not
    function isValid(email, pass){
        if(email === ""){
            displayErrorMessage("Please enter your email");
            return false;
        }
        // Use regular expression to check format email
        /*
            (\w+)@(\w+)\.(\w+):
            - (\w+)@: contains at least one word be @ symbol. -> Name
            - (\w+)\.(\w+): contains at least one word front and back of . symbol -> Domain
            For example: aaa@bbb.ccc
        */
        else if(!email.match(/(\w+)@(\w+)\.(\w+)/)){
            displayErrorMessage("Your email is not correct");
            return false;
        }
        else if(pass === ""){
            displayErrorMessage("Please enter your password");
            return false;
        }
        else if(pass.length < 6){
            displayErrorMessage("Your password must contain at least 6 characters");
            return false;
        }
        return true;
    }

    emailInputField.addEventListener("change", () => {

    })

    btnSubmit[0].addEventListener("click", (event) => {
        let email = emailInputField.value;
        let pass = pwdInputField.value;
        if(!isValid(email, pass)){
            event.preventDefault();
            return false;
        }
        return true;
    });
}