$(() => {
    let color_value = 255;
    const body = $("body");
    const main = $("<div>");
    const displayColorValue = $("<div>Hover a cell</div>");
    const colorTable = $("<table>");
    const messageBox = $("<div>Background color has been changed</div>");

    // Main section
    main.addClass("main");

    // Display color value of cell
    displayColorValue.addClass("color-display");
    // Copy color value to the clipboard
    displayColorValue.on("click", () => {
        navigator.clipboard.writeText(displayColorValue.text())
            .then(() => {displayMessage("Color has been copied to the clipboard")});
    });
    main.append(displayColorValue);

    // Color table
    let colorValue = "Hover a cell";
    let backgroundColor = "RGB(255, 255, 255)";
    colorTable.addClass("color-picker-table");
    for(let i = 0; i < 10; i++){
        const row = $("<tr></tr>");
        for(let j = 0; j < 10; j++){
            const cell = $("<td></td>");
            cell.addClass("cell");
            let red = Math.round(Math.random() * color_value);
            let green = Math.round(Math.random() * color_value);
            let blue = Math.round(Math.random() * color_value);
            cell.css("background-color", `RGB(${red}, ${green}, ${blue})`);
            cell.on("mouseover", () => {
                displayColorValue.text(`rgb(${red}, ${green}, ${blue})`);
                body.css("background-color", `RGB(${red}, ${green}, ${blue})`);
            });
            cell.on("click", () => {
                colorValue = `rgb(${red}, ${green}, ${blue})`;
                backgroundColor = `RGB(${red}, ${green}, ${blue})`;
                displayMessage("Background color has been changed");
            });
            row.append(cell);
        }
        colorTable.append(row);
        colorTable.on("mouseleave", () => {
            displayColorValue.text(colorValue);
            body.css("background-color", backgroundColor);
        })
    }
    main.append(colorTable);

    messageBox.addClass("message");
    main.append(messageBox);
    body.append(main);

    function displayMessage(message){
        messageBox.text(message);
        messageBox.fadeIn(1000);
        messageBox.fadeOut(1000);
    }
});