const strtBtn = document.getElementById("start-btn");
const nxtBtn = document.getElementById("next-btn");
const qConElem = document.getElementById("question-container");
const ansBtns = document.getElementById("answer-buttons");
const qElem = document.getElementById("question");

let quizScore = 0;
let shuflQues, currQIndex;

strtBtn.addEventListener('click',startGame);

nxtBtn.addEventListener('click',()=>{
    currQIndex++;
    setnextQuestion();
})

function startGame(){
    strtBtn.classList.add('hide');
    shuflQues=questions.sort(()=>Math.random() -0.5);
    currQIndex=0;
    qConElem.classList.remove('hide');
    setnextQuestion();
    quizScore=0;
}

function setnextQuestion(){
    resetState();
    showQuestion(shuflQues[currQIndex]);
}

function showQuestion(question){
    qElem.innerText = question.question;
    question.answers.forEach((answer) => {
        const button = document.createElement('button');
        button.innerText=answer.text;
        button.classList.add('btn')
        if(answer.correct){
            button.dataset.correct = answer.correct;
        }
        button.addEventListener('click',selectAnswer);
        ansBtns.appendChild(button);
    })
}

function resetState(){
    clearStatusClass(document.body);
    nxtBtn.classList.add('hide');
    while(ansBtns.firstChild){
        ansBtns.removeChild(ansBtns.firstChild);
    }
}

function selectAnswer(e){
    const selectedButton = e.target;
    const correct = selectedButton.dataset.correct;
    setStatusClass(document.body,correct);
    Array.from(ansBtns.children).forEach((button) => {
        setStatusClass(button,button.dataset.correct);
    })
    if(shuflQues.length > currQIndex + 1){
        nxtBtn.classList.remove("hide");
    }else{
        strtBtn.innerText = 'Restart';
        strtBtn.classList.remove("hide");
    }
    if(selectedButton.dataset = correct){
        quizScore++;
    }
    document.getElementById('right-answers').innerText=quizScore;
}

function setStatusClass(element, correct){
    clearStatusClass(element);
    if(correct){
        element.classList.add('correct');    
    }else{
        element.classList.add('wrong');
    }
}

function clearStatusClass(element){
    element.classList.remove('correct');
    element.classList.remove('wrong');
}

let questions = [
    {
        question: 'Which one of these is a Javascript framework ?',
        answers:[
            {text: 'Python', correct:false},
            {text: 'Django', correct:false},
            {text: 'React', correct:true},
            {text: 'SQL', correct:false},
        ]
    },
    {
        question: 'Who is the Prime Mininster of India ?',
        answers:[
            {text: 'Narendra Modi', correct:true},
            {text: 'Rahul Gandhi', correct:false},
        ]
    },
    {
        question: 'What is 5 multiplied by 4 ?',
        answers:[
            {text: '200', correct:false},
            {text: '13', correct:false},
            {text: '20', correct:true},
            {text: '2', correct:false},
        ]
    }
]