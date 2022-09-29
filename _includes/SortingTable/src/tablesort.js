let sortDirection = false;
let tableData = [
    { Week: '0', name: 'Tool Setup Sprint and Pair Programming'},
    { Week: '1', name: 'Introduction to Python'},
    { Week: '2', name: 'Data Abstraction in Python'},
    { Week: '3', name: 'Creative Development Sprint'},
    { Week: '4', name: 'Python Web Server Project'},
    { Week: '5', name: 'UI Starters'},
    { Week: '6', name: 'Deployment'}

];

window.onload = () => {

loadTableData(tableData);

};

function loadTableData(tableData){
    const tableBody = document.getElementById('tableData');
    let dataHtml = '';

    for(let data of tableData) {
        dataHtml += `<tr><td>${week.number}</td><td>${blog.name}</td></tr>`;
    }
    console.log(dataHtml)

    tableBody.innerHtml = datahtml;
}
