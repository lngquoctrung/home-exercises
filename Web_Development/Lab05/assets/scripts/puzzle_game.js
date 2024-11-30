$(function(){
    // === Declare Components ===
    $("body").append($("<div>").addClass("main"));
    const main = $(".main");
    main.append($("<table>").addClass("puzzle-area"));
    main.append($("<table>").addClass("photo-area"));
    const puzzleArea = $(".puzzle-area");

    // === Declare Values ===
    const imgIndexs = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const angles = [0, 90, 180, 270];
    // Shuffle array when reload page
    const shuffleImgIndexs = imgIndexs.sort(() => 0.5 -  Math.random());
    // Create array of image file paths based on shuffle array
    const imgFilePaths = [];
    for(let index of shuffleImgIndexs){
        const filePath = index < 10 ? `cntt_0${index}.gif` : `cntt_${index}.gif`
        imgFilePaths.push(filePath);
    }

    // === Initialize Components ===
    // Drag and Drop event
    function allowDrop(event){
        event.preventDefault();
    }
    function drop(event){
        event.preventDefault();
        let id = event.originalEvent.dataTransfer.getData("text");
        let draggedElement = document.getElementById(id);
        if(event.target.tagName.toLowerCase() === "td" && !event.target.hasChildNodes()){
            event.target.appendChild(draggedElement);
        }
        else if(event.target.tagName.toLowerCase() === "img"){
        }

    }
    function drag(event){
        event.originalEvent.dataTransfer.setData("text", event.target.id);
    }
    // Check the game whether is completed or not.
    function checkPuzzleCompletion(){
        let resultTableCells = puzzleArea.find($("td"));
        // Check all puzzle cells whether is filled or not
        let isFullFill = true;
        resultTableCells.each(function() {
            if ($(this).children().length === 0) {
                isFullFill = false;
                return false;
            }
        });
        // If all images are fully filled then check ordered and rotation
        if(isFullFill){
            function isCorrect(arr){
                const sortArr = [...arr].sort((a, b) => a - b);
                return JSON.stringify(arr) === JSON.stringify(sortArr);
            }
            let results = [];
            for(let resultImg of resultTableCells.find("img")){
                if(resultImg.style.rotate === "0deg")
                    results.push(parseInt(resultImg.id, 10));
            }
            if(!results.includes(10) && results.length === 9 && isCorrect(results)){
                congraMessage.fadeIn(1000);
                congraMessage.fadeOut(3000);
            }
        }
    }

    function changeRotationAngle(event){
        let currentAngle = event.target.style.rotate;
        let newAngle = parseInt(currentAngle, 10) + 90;
        // If the rotation angle of image is  360 degrees, it means that the rotation angle of image has returned to 0 degrees
        newAngle = newAngle === 360 ? 0 : newAngle;
        event.target.style.rotate = `${newAngle}deg`;
    }

    // Create an area to solve the puzzle
    for(let i = 0; i < 3; i++){
        const pzAreaTableRow = $("<tr>");
        for(let j = 0; j < 3; j++){
            const pzAreaTableCell = $("<td>");
            pzAreaTableCell.on("dragover", allowDrop);
            pzAreaTableCell.on("drop", drop);
            pzAreaTableRow.append(pzAreaTableCell);
        }
        puzzleArea.append(pzAreaTableRow);
    }

    // Create a photo area
    let imgFilePathIndex = 0;
    for(let i = 0; i < 2; i++){
        const ptAreaTableRow = $("<tr>");
        for(let j = 0; j < 5; j++){
            // Show image inside photo area
            const ptAreaTableImg = $(`<img id="image${shuffleImgIndexs[imgFilePathIndex]}" alt="" src="${"./assets/images/" + imgFilePaths[imgFilePathIndex]}">`);
            // Random angle of images when reload page
            const randomDegree = angles[Math.floor(Math.random() * angles.length)];
            ptAreaTableImg.css("rotate", `${randomDegree}deg`);
            // Add "click" event to change the rotation angle of images
            ptAreaTableImg.on("click", changeRotationAngle);
            // Allow image to drag
            ptAreaTableImg.attr({
                draggable: true,
            });
            ptAreaTableImg.on("dragstart", drag);
            // Add image inside <td> tag
            const ptAreaTableCell = $("<td>");
            ptAreaTableCell.on("dragover", allowDrop);
            ptAreaTableCell.on("drop", drop);
            ptAreaTableRow.append(ptAreaTableCell.append(ptAreaTableImg));
            imgFilePathIndex++;
        }
        $(".photo-area").append(ptAreaTableRow);
    }

    // Show congratulation message when completing the puzzle game
    const congraMessage = $("<div>");
    congraMessage.text("Congratulation!! You won the game");
    congraMessage.addClass("congratulation");
    main.append(congraMessage);

    // Catch drop event images to check the puzzle game whether completed or not.
    puzzleArea.on("drop", checkPuzzleCompletion);

    // Catch angle rotation of image inside puzzle area to check the puzzle game whether completed or not.
    puzzleArea.on("click", "img", checkPuzzleCompletion);
});