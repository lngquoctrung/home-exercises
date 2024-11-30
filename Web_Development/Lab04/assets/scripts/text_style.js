window.onload = () => {
    const inputField = document.getElementById("message");
    const resultDisplay = document.getElementById("result");
    const colorOption = document.getElementById("color");
    const switchBold = document.getElementById("bold");
    const switchItalic = document.getElementById("italic");
    const switchUnderline = document.getElementById("underline");
    const resetButton = document.getElementById("reset-btn");

    const defaultResult = resultDisplay.innerHTML;

    function displayResult(message, color, isBold, isItalic, isUnderline){
        resultDisplay.style.color = color;
        if(isBold) resultDisplay.style.fontWeight = "bold";
        else resultDisplay.style.fontWeight = "normal";
        if(isItalic) resultDisplay.style.fontStyle = "italic";
        else resultDisplay.style.fontStyle = "normal";
        if(isUnderline) resultDisplay.style.textDecoration = "underline";
        else resultDisplay.style.textDecoration = "none";
        resultDisplay.innerHTML = message !== "" ? message : defaultResult;
    }

    colorOption.addEventListener("change", () => {
        displayResult(inputField.value, colorOption.value, switchBold.checked, switchItalic.checked, switchUnderline.checked);
    });

    switchBold.addEventListener("change", () => {
        displayResult(inputField.value, colorOption.value, switchBold.checked, switchItalic.checked, switchUnderline.checked);
    });

    switchItalic.addEventListener("change", () => {
        displayResult(inputField.value, colorOption.value, switchBold.checked, switchItalic.checked, switchUnderline.checked);
    });

    switchUnderline.addEventListener("change", () => {
        displayResult(inputField.value, colorOption.value, switchBold.checked, switchItalic.checked, switchUnderline.checked);
    });

    inputField.addEventListener("keydown", () => {
        displayResult(inputField.value, colorOption.value, switchBold.checked, switchItalic.checked, switchUnderline.checked);
    });

    resetButton.addEventListener("click", () => {
        resultDisplay.style.removeProperty("color");
        resultDisplay.style.removeProperty("font-weight");
        resultDisplay.style.removeProperty("font-style");
        resultDisplay.style.removeProperty("text-decoration");
        resultDisplay.innerHTML = defaultResult;

        inputField.value = "";
        switchBold.checked = false;
        switchItalic.checked = false;
        switchUnderline.checked = false;
        colorOption.value = "black";
    });
}