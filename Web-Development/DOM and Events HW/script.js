//Create new elements for table and buttons
var newTable = document.createElement("table");

var upBtn = document.createElement("button");
upBtn.textContent = "UP";

var downBtn = document.createElement("button")
downBtn.textContent = "DOWN";

var leftBtn = document.createElement("button");
leftBtn.textContent = "LEFT";

var rightBtn = document.createElement("button")
rightBtn.textContent = "RIGHT";

var mark = document.createElement("button");
mark.textContent = "Mark Cell";

//Create the table
function createTable(newTable){

    //Create the header row 
  var hdrRow = document.createElement("tr");
  
  //create header cells and add the text for them. appendCild to hdrRow
  for (var i = 0; i < 4; i++){
    var hdrCell = document.createElement("th");
    hdrCell.textContent = "Header " + (i+1);
    hdrCell.style.border = "2px solid black";
    hdrRow.appendChild(hdrCell);
  }
  
  //appendChild the header row to the table
  newTable.appendChild(hdrRow);
    
  //create the rest of the table rows and insert their text.
  for (var i = 1; i < 4; i++){
    var row = document.createElement("tr")
    for (var j = 1; j < 5; j++){
      var cell = document.createElement("td")
      cell.textContent = (i) + ", " + (j);
      cell.style.border = "1px solid black";
      
      //apend the cell to the table body row
      row.appendChild(cell);
    }
    
    //append the row to the table
    newTable.appendChild(row);
  }
  
  //return the table
  return newTable;
}

/* Down button functionality. If the selection will not go off of the table, increase
 * the cell row by 1 and select it.
 */
function moveDown(table,cell){
  if (cell.row < 3 && cell.row > 0){
    table.children[cell.row].children[cell.col].style.border = "1px solid black";
    cell.row += 1;
    table.children[cell.row].children[cell.col].style.border = "4px solid black";
  }
}

//Event listener for down button
downBtn.addEventListener("click", function(){
  moveDown(table,currentCell);
})


/* Up button functionality. If the selection will not go off of the table, decrease
 * the cell row by 1 and select it.
 */
function moveUp(table, cell){
  if (cell.row > 1){
    table.children[cell.row].children[cell.col].style.border = "1px solid black";
    cell.row -= 1;
    table.children[cell.row].children[cell.col].style.border = "4px solid black";
  }
}

//Event listener for up button
upBtn.addEventListener("click", function(){
  moveUp(table,currentCell);
})

/* Left button functionality. If the selection will not go off of the table, decrease
 * the cell column by 1 and select it.
 */
function moveLeft(table, cell){
  if (cell.col > 0){
    table.children[cell.row].children[cell.col].style.border = "1px solid black";
    cell.col -= 1;
    table.children[cell.row].children[cell.col].style.border = "4px solid black";
  }
}

//Event listener for left button
leftBtn.addEventListener("click", function(){
  moveLeft(table,currentCell);
})

/* Right button functionality. If the selection will not go off of the table, increase
 * the cell column by 1 and select it.
 */
function moveRight(table, cell){
  if (cell.col < table.rows[cell.row].cells.length-1){
    table.children[cell.row].children[cell.col].style.border = "1px solid black";
    cell.col += 1;
    table.children[cell.row].children[cell.col].style.border = "4px solid black";
  }
}

//Event listener for right button
rightBtn.addEventListener("click", function(){
  moveRight(table,currentCell);
})

//If the cell is yellow already, change color to white to toggle the mark
//Otherwise, change the color to yellow 
function markCell(table, cell){
    if(table.children[cell.row].children[cell.col].style.backgroundColor == "yellow"){
  table.children[cell.row].children[cell.col].style.backgroundColor = "white";
  }else
  table.children[cell.row].children[cell.col].style.backgroundColor = "yellow";
}

//add event listener for the markCell function
mark.addEventListener("click", function(){
  markCell(table,currentCell);
})

//function to create table
var table  = createTable(newTable);

//Start with the cell in the upper left corner selected
var currentCell = {col:0, row:1};
table.children[1].children[0].style.border = "4px solid black";

//Appen the table and buttons to the body of the document
document.body.appendChild(table);
document.body.appendChild(upBtn);
document.body.appendChild(downBtn);
document.body.appendChild(leftBtn);
document.body.appendChild(rightBtn);
document.body.appendChild(mark);
