function display_maze(way) {
    for (let i = 0; way[i]; i++)
        console.log(way[i].join(""));
    console.log('\n');
}

function create_maze(width, height) {
    let way = new Array(height);

    for (let rows = 0; rows < height; rows++) {
        way[rows] = new Array(width);
        for (let columns = 0; columns < height; columns++)
            way[rows][columns] = "X";
        way[rows].join("");
    }
    return way
}

function snail(width, height) {
    let way = create_maze(width, height);
    let index = 1;
    let row = 0;
    let column = -1;

    display_maze(way);
    for (let loop = 0; loop < height; loop++) {
        for (let val = 0; val < (height - loop); val++) {
            column += index;
            way[row][column] = 'V';
            display_maze(way);
        }
        for (let val = 1; val < (height - loop); val++) {
            row += index;
            way[row][column] = 'V';
            display_maze(way);
        }
        index = -index;
    }
}

snail(process.argv[1], process.argv[2]);