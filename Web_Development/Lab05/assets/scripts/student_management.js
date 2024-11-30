$(() => {
    const nameField = $("#name");
    const emailField = $("#email");
    const phoneField = $("#phone");
    const tBody = $("tbody");
    const addBtn = $("#add-button");
    const updateBtn = $("#update-button");
    const alertSection = $(".alert-section");
    const modalBox = $(".modal");

    const getStdUrl = "http://localhost:8080/get-students.php";
    const deleteStdUrl = "http://localhost:8080/delete-student.php";
    const updateStdUrl = "http://localhost:8080/update-student.php";
    let editStdID;

    updateBtn.prop("disabled", true);

    // ============ ALERT MESSAGE ============
    // Alear message function
    function renderMessage(msg, isSuccess = true){
        // status check the alert to be success or failed
        let type = isSuccess ? "success" : "danger";
        let state = type === "success" ? 'Success!' : 'Fail!'
        let alertMessage = $(`
            <div class="alert alert-${type} alert-dismissible w-50 mb-2 m-auto" role="alert">
                <div><span class="fw-bold">${state}</span> ${msg}</div>
                <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
            </div>    
        `);
        alertSection.append(alertMessage);
        alertMessage.fadeIn(3000);
        alertMessage.fadeOut(3000);
    }


    // ============ DISPLAY DATA ============
    // Handle delete event
    function handleRemoveStudent(deleteRow){
        return function (){
            let stdID = deleteRow.childNodes[0].innerHTML;
            $.ajax({
                url: deleteStdUrl,
                type: "POST",
                data: {id: stdID},
                success: function (data){
                    if(data["status"]){
                        deleteRow.remove();
                        renderMessage(data["data"]);
                        // Render table again
                        $.get({
                            url: getStdUrl,
                            method: "GET",
                            success: data => renderTable(data["data"]),
                        });
                    }
                    else renderMessage(data["data"], false);
                },
            });
            modalBox.modal("hide");
        }
    }
    // Delete student
    function deleteStudent(){
        let deleteRow = this.closest("tr");
        // let stdID = deleteRow.childNodes[0].innerHTML;
        let stdName = deleteRow.childNodes[1].innerHTML;
        let modalFooter = $(".modal-footer");
        let confirmDeleteBtn = modalFooter.children(".btn-danger");
        $(".modal-body").find("strong").text(stdName);

        // Display modal box to confirm
        modalBox.modal("show");
        // Remove click event of confirm button of deleted element
        confirmDeleteBtn.off("click");
        // Add again new click event for other elements
        confirmDeleteBtn.on("click", handleRemoveStudent(deleteRow));
    }

    // Update student
    function updateStudent(updateRow){
        let stdID = updateRow.find("td:eq(0)").text();
        let stdName = updateRow.find("td:eq(1)").text();
        let stdEmail = updateRow.find("td:eq(2)").text();
        let stdPhone = updateRow.find("td:eq(3)").text();

        // Disable add button
        addBtn.prop("disabled", true);
        updateBtn.prop("disabled", false);

        // Fill student information inside form
        editStdID = stdID;
        nameField.val(stdName);
        emailField.val(stdEmail);
        phoneField.val(stdPhone);
    }

    // Function display the data to be responded by server
    function renderTable(data){
        // Clear all children elements before display
        tBody.empty();
        // Display data
        data.forEach(row => {
            let tRow = $(`<tr>`);
            for(let key in row) tRow.append($(`<td>${row[key]}</td>`));
            let editBtn = $("<button>").addClass("btn btn-primary mx-2").text("Edit");
            let deleteBtn = $("<button>").addClass("btn btn-danger").text("Delete");
            // Catch delete student event
            deleteBtn.on("click", deleteStudent);
            // Catch edit student event
            editBtn.on("click", function(){
                updateStudent($(this).closest("tr"));
            });
            tRow.append($("<td>").append(editBtn).append(deleteBtn));
            tBody.append(tRow);
        });
    }

    // Get data when load page
    $.ajax({
        url: getStdUrl,
        type: "GET", 
        success: function(data){
            let resStatus = data["status"];
            let resData = data["data"];
            if(resStatus) renderTable(resData);
            else renderMessage(resData, false);
        }, 
        error: () => renderMessage("An unknown error occured. Please try again later.", false)
    });


    // ============ ADD STUDENT ============
    function isValidForm(name, email, phone){
        if(name === "" || email === "" || phone === ""){
            let emptyVar;
            if(name === "") emptyVar = Object.keys({name})[0];
            else if(email === "") emptyVar = Object.keys({email})[0];
            else emptyVar = Object.keys({phone})[0] + " number";
            renderMessage(`Please enter the ${emptyVar} of student`, false);
            return false;
        }
        else if(!email.match(/^(\w+)@(\w+)\.(\w+)$/)){
            renderMessage(`Email of student is invalid`, false);
            return false;
        }
        else if(!phone.match(/^[0-9]+$/)){
            renderMessage(`Phone number of student is invalid`, false);
            return false;
        }
        return true;
    }

    // Catch event add student
    addBtn.on("click", function(event){
        let name = nameField.val();
        let email = emailField.val();
        let phone = phoneField.val();
        // Check input is valid or not
        if(isValidForm(name, email, phone)){
            event.preventDefault();
            let url = $(this).closest("form").attr("action");
            let queryString = $(this).closest("form").serialize();
            $.ajax({
                url: url,
                type: "POST",
                data: queryString,
                success: (data) => {
                    if(data["status"]){
                        renderMessage(data["data"]);
                        // Render table again
                        $.get({
                            url: getStdUrl,
                            method: "GET",
                            success: data => renderTable(data["data"]),
                        });
                    }
                    else renderMessage(data["data"], false);
                },
                error: () => renderMessage("An unknown error occured. Please try again later.", false)
            })
        }
        else{
            event.preventDefault();
            return false;
        }
    });


    // ============ UPDATE STUDENT ============
    updateBtn.on("click", function(event){
        let name = nameField.val();
        let email = emailField.val();
        let phone = phoneField.val();

        // Check input is valid or not
        if(isValidForm(name, email, phone)){
            event.preventDefault();
            let queryString = $(this).closest("form").serialize();
            $.ajax({
                url: updateStdUrl,
                type: "POST",
                data: `id=${editStdID}&` + queryString,
                success: (data) => {
                    renderMessage(data["data"]);
                    // Render table again
                    $.get({
                        url: getStdUrl,
                        method: "GET",
                        success: data => {
                            renderTable(data["data"]);
                            nameField.val("");
                            emailField.val("");
                            phoneField.val("");
                            // Enable add button
                            addBtn.prop("disabled", false);
                            updateBtn.prop("disabled", true);
                        },
                    });
                },
                error: () => renderMessage("An unknown error occured. Please try again later.", false)
            })
        }
        else{
            event.preventDefault();
            return false;
        }
    });
});