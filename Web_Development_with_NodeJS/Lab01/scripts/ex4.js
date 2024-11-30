$('document').ready(() => {
    // Load immediately data when load page
    let session_students = JSON.parse(window.sessionStorage.getItem("students"));
    // Initialize session array data if data doesn't exist
    if(!session_students) {
        session_students = [];
    }
    // Load data
    session_students.forEach((element) => display_student(element, "session_storage_table"));

    let local_students = JSON.parse(window.localStorage.getItem("students"));
    if(!local_students){
        local_students = [];
    }
    // Load data
    local_students.forEach((element) => display_student(element, "local_storage_table"));

    // Add event listener
    // Local storage
    $("#local_storage_btn").on("click", () => {
        let input_name_field = $("#name");
        let input_age_field = $("#age");
        // Assume that the lenght of local storage is ID
        let id = local_students.length + 1;
        // Get `name` and `age` from input field
        let name = input_name_field.val();
        let age = input_age_field.val();
        let student = {"id": id, "name": name, "age": age};

        // Display student to local storage table
        display_student(student, "local_storage_table");

        // Save data into local storage
        local_students.push(student);
        window.localStorage.setItem("students", JSON.stringify(local_students));

        // Clear input field
        input_name_field.val("");
        input_age_field.val("");
    });

    // Session storage
    $("#session_storage_btn").on("click", () => {
        let input_name_field = $("#name");
        let input_age_field = $("#age");
        // Assume that the lenght of session storage is ID
        let id = session_students.length + 1;
        // Get `name` and `age` from input field
        let name = input_name_field.val();
        let age = input_age_field.val();
        let student = {"id": id, "name": name, "age": age};

        // Display student to session storage table
        display_student(student, "session_storage_table");

        // Save data into local storage
        session_students.push(student);
        window.sessionStorage.setItem("students", JSON.stringify(session_students));
        // Clear input field
        input_name_field.val("");
        input_age_field.val("");
    });
});

function display_student(student, table_id) {
    let tbody = $(`#${table_id}`).children("tbody");
    tbody.append(`
        <tr>
            <td>${student.id}</td>
            <td>${student.name}</td>
            <td>${student.age}</td>
        </tr>
    `);
}