$(function(){
        // Collect elements by jquery
        const emailField = $("#email");
        const passField = $("#pwd");
        const errorMessage = $(".errorMessage");
        const button = $("button");

        function displayErrorMessage(message){
            errorMessage.text(message);
            errorMessage.removeClass("d-none")
            errorMessage.addClass("d-block");
        }

        function hideErrorMessage(){
            errorMessage.removeClass("d-block")
            errorMessage.addClass("d-none");
        }

        // Hide the error message
        errorMessage.addClass("d-none");

        emailField.on("keydown", () => {
            hideErrorMessage();
        });
        passField.on("keydown", () => {
            hideErrorMessage();
        });

        function isValidForm(email, pass){
            if(email === ""){
                displayErrorMessage("Please enter your email address.")
                return false;
            }else if(!email.match(/^(\w+)@(\w+).(\w+)$/)){
                displayErrorMessage("Your email is not correct.")
                return false;
            }
            else if(pass === ""){
                displayErrorMessage("Please enter password.")
                return false;
            }
            else if(pass.length < 6){
                displayErrorMessage("Your password must contain at least 6 characters.")
                return false;
            }
            return true;
        }
        
        // Check the form whether is valid or not before submitting
        button.on("click", (event) => {
            const email = emailField.val();
            const pass = passField.val();
            console.log(email)
            if(!isValidForm(email, pass)){
                event.preventDefault();
                return false;
            }
            return true;
        });
    }
);