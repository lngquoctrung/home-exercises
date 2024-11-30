window.onload = () => {
    const imageList = document.getElementById("imageList");
    const prevBtn = document.getElementById("back");
    const startBtn = document.getElementById("start");
    const nextBtn = document.getElementById("next");
    const slide = document.getElementById("slide");
    const describe = document.getElementById("describe");
    let i = 0;
    const length = imageList.children.length;
    const path = "./assets/images/"
    describe.innerHTML = `${imageList[i].value} (${i+1}/${length})`;

    function display(i){
        slide.src = path + imageList.children[i].value;
        describe.innerHTML = `${imageList.children[i].value} (${i+1}/${length})`;
    }

    nextBtn.addEventListener("click", () => {
        i++;
        if(i >= 10){
            i = 0;
        }
        display(i);
    });

    prevBtn.addEventListener("click", () => {
        i--;
        if(i < 0){
            i = length - 1;
        }
        display(i);
    });

    let startSlideshow = null;
    startBtn.addEventListener("click", () => {
        if(startBtn.innerHTML === "Start slideshow"){
            startBtn.innerHTML = "Stop slideshow";
            startSlideshow = setInterval(() => {
                i++;
                if(i >= 10){
                    i = 0;
                }
                display(i);
            }, 1000);
        }
        else if(startBtn.innerHTML === "Stop slideshow"){
            startBtn.innerHTML = "Start slideshow";
            clearInterval(startSlideshow);
        }
    });

    imageList.addEventListener("change", () => {
        i = imageList.selectedIndex;
        display(i);
    });
}