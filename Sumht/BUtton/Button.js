const btn = document.getElementById('btn-1');
btn.onclick = function(){
    const eNode=document.createElement('p');
    eNode.textContent='The content added';
    document.body.appendChild(eNode);
};


// const btn = document.querySelector('#btn-1');

// function addParagraph(){
    
// }

// btn.addEventListener('click',addParagraph);