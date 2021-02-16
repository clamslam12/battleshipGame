///Name: Minh Durbin
///Student ID: 101820610
///Object Oriented Programming: Final Project Battleship


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
const int row = 10, col = 10;

class person
{
protected:
    int num_of_ships = 5;
public:
    int placement_grid[row][col] = {{0,0,0,0,0,0,0,0,0,0}, // placement grid for player and computer
                                    {0,0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0,0,0}};

    int shot_grid[row][col] = {{0,0,0,0,0,0,0,0,0,0}, //grid for choosing/shooting opponents ship(for player and computer)
                               {0,0,0,0,0,0,0,0,0,0},
                               {0,0,0,0,0,0,0,0,0,0},
                               {0,0,0,0,0,0,0,0,0,0},
                               {0,0,0,0,0,0,0,0,0,0},
                               {0,0,0,0,0,0,0,0,0,0},
                               {0,0,0,0,0,0,0,0,0,0},
                               {0,0,0,0,0,0,0,0,0,0},
                               {0,0,0,0,0,0,0,0,0,0},
                               {0,0,0,0,0,0,0,0,0,0}};
    char check_grid[row][col] = {{'.','.','.','.','.','.','.','.','.','.'}, //grid to display x and o for misses/hits
                                 {'.','.','.','.','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.','.','.'},
                                 {'.','.','.','.','.','.','.','.','.','.'}};

};

class computer : public person
{
public:

};

void print_array(int the_array[][col], int row_size)
{
    for(int i = 0; i < row_size; i++){
        for(int j = 0; j < col; j++)
        {
            cout << the_array[i][j] << " ";

        }
        cout << endl;
}}
void print_char_array(char the_array[][col], int row_size)
{
    for(int i = 0; i < row_size; i++){
        for(int j = 0; j < col; j++)
        {
            cout << the_array[i][j] << " ";

        }
        cout << endl;
    }
}

void carrier_placement(char the_input, char the_x, int the_y, person& the_obj)
{
    int convert = static_cast<int>(the_x) - 96; ///convert = the_x
    if(the_input == 'h' && convert >= 7) ///horizontal placement of carrier if x >= 7
    {
        int new_row = --the_y, new_col = convert;

        for(int i = 0; i < 5; i++) {

            the_obj.placement_grid[new_row][--new_col] = 1;

        }

    }else if( the_input == 'h' && convert < 7) ///horizontal placement of carrier if x < 7
    {

        int new_row = --the_y, new_col = --convert;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 4; i++) {

            the_obj.placement_grid[new_row][++new_col] = 1;

        }
    }else if(the_input == 'v' && the_y < 7) ///vertical placement of carrier if y < 7
    {
        int new_row = --the_y, new_col = --convert;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 4; i++) {

            the_obj.placement_grid[++new_row][new_col] = 1;
        }
    }else if(the_input == 'v' && the_y >= 7) ///vertical placement of carrier if y >= 7
    {
        int new_row = the_y, new_col = --convert;

        for(int i = 0; i < 5; i++) {

            the_obj.placement_grid[--new_row][new_col] = 1;

        }

    }
}
void comp_carrier_placement(char the_input, int the_x, int the_y, person& the_obj)
{

    if(the_input == 'h' && the_x >= 7) ///horizontal placement of carrier if x >= 7
    {
        int new_row = --the_y, new_col = the_x;

        for(int i = 0; i < 5; i++) {

            the_obj.placement_grid[new_row][--new_col] = 1;

        }

    }else if( the_input == 'h' && the_x < 7) ///horizontal placement of carrier if x < 7
    {

        int new_row = --the_y, new_col = --the_x;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 4; i++) {

            the_obj.placement_grid[new_row][++new_col] = 1;

        }
    }else if(the_input == 'v' && the_y < 7) ///vertical placement of carrier if y < 7
    {
        int new_row = --the_y, new_col = --the_x;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 4; i++) {

            the_obj.placement_grid[++new_row][new_col] = 1;
        }
    }else if(the_input == 'v' && the_y >= 7) ///vertical placement of carrier if y >= 7
    {
        int new_row = the_y, new_col = --the_x;

        for(int i = 0; i < 5; i++) {

            the_obj.placement_grid[--new_row][new_col] = 1;

        }

    }
}
void battleship_placement(char the_input, char the_x, int the_y, person& the_obj)
{
    int convert = static_cast<int>(the_x) - 96; ///convert = the_x
    if(the_input == 'h' && convert >= 8) ///horizontal placement of battleship if x >= 8
    {
        int new_row = --the_y, new_col = convert;

        for(int i = 0; i < 4; i++) {

            the_obj.placement_grid[new_row][--new_col] = 1;

        }

    }else if( the_input == 'h' && convert < 8) ///horizontal placement of battleship if x < 8
    {
        int new_row = --the_y, new_col = --convert;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[new_row][++new_col] = 1;

        }
    }else if(the_input == 'v' && the_y < 8) ///vertical placement of battleship if y < 8
    {
        int new_row = --the_y, new_col = --convert;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[++new_row][new_col] = 1;
        }
    }else if(the_input == 'v' && the_y >= 8) ///vertical placement of battleship if y >= 8
    {
        int new_row = the_y, new_col = --convert;

        for(int i = 0; i < 4; i++) {

            the_obj.placement_grid[--new_row][new_col] = 1;

        }

    }
}
void comp_battleship_placement(char the_input, int the_x, int the_y, person& the_obj)
{

    if(the_input == 'h' && the_x >= 8) ///horizontal placement of battleship if x >= 8
    {
        int new_row = --the_y, new_col = the_x;

        for(int i = 0; i < 4; i++) {

            the_obj.placement_grid[new_row][--new_col] = 1;

        }

    }else if( the_input == 'h' && the_x < 8) ///horizontal placement of battleship if x < 8
    {
        int new_row = --the_y, new_col = --the_x;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[new_row][++new_col] = 1;

        }
    }else if(the_input == 'v' && the_y < 8) ///vertical placement of battleship if y < 8
    {
        int new_row = --the_y, new_col = --the_x;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[++new_row][new_col] = 1;
        }
    }else if(the_input == 'v' && the_y >= 8) ///vertical placement of battleship if y >= 8
    {
        int new_row = the_y, new_col = --the_x;

        for(int i = 0; i < 4; i++) {

            the_obj.placement_grid[--new_row][new_col] = 1;

        }

    }
}
void cruiser_placement(char the_input, char the_x, int the_y, person& the_obj)
{
    int convert = static_cast<int>(the_x) - 96; ///convert = the_x
    if(the_input == 'h' && convert >= 9) ///horizontal placement of cruiser if x >= 9
    {
        int new_row = --the_y, new_col = convert;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[new_row][--new_col] = 1;

        }

    }else if( the_input == 'h' && convert < 9) ///horizontal placement of cruiser if x < 9
    {
        int new_row = --the_y, new_col = --convert;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[new_row][++new_col] = 1;

        }
    }else if(the_input == 'v' && the_y < 9) ///vertical placement of cruiser if y < 9
    {
        int new_row = --the_y, new_col = --convert;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[++new_row][new_col] = 1;
        }
    }else if(the_input == 'v' && the_y >= 9) ///vertical placement of cruiser if y >= 9
    {
        int new_row = the_y, new_col = --convert;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[--new_row][new_col] = 1;

        }

    }
}
void comp_cruiser_placement(char the_input, int the_x, int the_y, person& the_obj)
{

    if(the_input == 'h' && the_x >= 9) ///horizontal placement of cruiser if x >= 9
    {
        int new_row = --the_y, new_col = the_x;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[new_row][--new_col] = 1;

        }

    }else if( the_input == 'h' && the_x < 9) ///horizontal placement of cruiser if x < 9
    {
        int new_row = --the_y, new_col = --the_x;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[new_row][++new_col] = 1;

        }
    }else if(the_input == 'v' && the_y < 9) ///vertical placement of cruiser if y < 9
    {
        int new_row = --the_y, new_col = --the_x;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[++new_row][new_col] = 1;
        }
    }else if(the_input == 'v' && the_y >= 9) ///vertical placement of cruiser if y >= 9
    {
        int new_row = the_y, new_col = --the_x;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[--new_row][new_col] = 1;

        }

    }
}
void sub_placement(char the_input, char the_x, int the_y, person& the_obj)
{
    int convert = static_cast<int>(the_x) - 96; ///convert = the_x
    if(the_input == 'h' && convert >= 9) ///horizontal placement of submarine if x >= 9
    {
        int new_row = --the_y, new_col = convert;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[new_row][--new_col] = 1;

        }

    }else if( the_input == 'h' && convert < 9) ///horizontal placement of submarine if x < 9
    {
        int new_row = --the_y, new_col = --convert;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[new_row][++new_col] = 1;

        }
    }else if(the_input == 'v' && the_y < 9) ///vertical placement of submarine if y < 9
    {
        int new_row = --the_y, new_col = --convert;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[++new_row][new_col] = 1;
        }
    }else if(the_input == 'v' && the_y >= 9) ///vertical placement of submarine if y >= 9
    {
        int new_row = the_y, new_col = --convert;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[--new_row][new_col] = 1;

        }

    }
}
void comp_sub_placement(char the_input, int the_x, int the_y, person& the_obj)
{

    if(the_input == 'h' && the_x >= 9) ///horizontal placement of submarine if x >= 9
    {
        int new_row = --the_y, new_col = the_x;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[new_row][--new_col] = 1;

        }

    }else if( the_input == 'h' && the_x < 9) ///horizontal placement of submarine if x < 9
    {
        int new_row = --the_y, new_col = --the_x;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[new_row][++new_col] = 1;

        }
    }else if(the_input == 'v' && the_y < 9) ///vertical placement of submarine if y < 9
    {
        int new_row = --the_y, new_col = --the_x;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[++new_row][new_col] = 1;
        }
    }else if(the_input == 'v' && the_y >= 9) ///vertical placement of submarine if y >= 9
    {
        int new_row = the_y, new_col = --the_x;

        for(int i = 0; i < 3; i++) {

            the_obj.placement_grid[--new_row][new_col] = 1;

        }

    }
}
void destroyer_placement(char the_input, char the_x, int the_y, person& the_obj)
{
    int convert = static_cast<int>(the_x) - 96; ///convert = the_x
    if(the_input == 'h' && convert >= 10) ///horizontal placement of destroyer if x >= 10
    {
        int new_row = --the_y, new_col = convert;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[new_row][--new_col] = 1;

        }

    }else if( the_input == 'h' && convert < 10) ///horizontal placement of destroyer if x < 10
    {
        int new_row = --the_y, new_col = --convert;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 1; i++) {

            the_obj.placement_grid[new_row][++new_col] = 1;

        }
    }else if(the_input == 'v' && the_y < 10) ///vertical placement of destroyer if y < 10
    {
        int new_row = --the_y, new_col = --convert;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 1; i++) {

            the_obj.placement_grid[++new_row][new_col] = 1;
        }
    }else if(the_input == 'v' && the_y >= 10) ///vertical placement of destroyer if y >= 10
    {
        int new_row = the_y, new_col = --convert;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[--new_row][new_col] = 1;

        }

    }
}
void comp_destroyer_placement(char the_input, int the_x, int the_y, person& the_obj)
{

    if(the_input == 'h' && the_x >= 10) ///horizontal placement of destroyer if x >= 10
    {
        int new_row = --the_y, new_col = the_x;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[new_row][--new_col] = 1;

        }

    }else if( the_input == 'h' && the_x < 10) ///horizontal placement of destroyer if x < 10
    {
        int new_row = --the_y, new_col = --the_x;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 1; i++) {

            the_obj.placement_grid[new_row][++new_col] = 1;

        }
    }else if(the_input == 'v' && the_y < 10) ///vertical placement of destroyer if y < 10
    {
        int new_row = --the_y, new_col = --the_x;
        the_obj.placement_grid[new_row][new_col] = 1;

        for(int i = 0; i < 1; i++) {

            the_obj.placement_grid[++new_row][new_col] = 1;
        }
    }else if(the_input == 'v' && the_y >= 10) ///vertical placement of destroyer if y >= 10
    {
        int new_row = the_y, new_col = --the_x;

        for(int i = 0; i < 2; i++) {

            the_obj.placement_grid[--new_row][new_col] = 1;

        }

    }
}
int sum_of_array(int the_array[][col], int row_size)
{
    int sum = 0;
    for(int i = 0; i < row_size; i++)
    {
        for(int j = 0; j < col; j++)
        {
            sum += the_array[i][j];

        }
    }
    return sum;
}
int main()
{
    srand(10);

    person me;
    computer it;

    cout << "\n\n************WELCOME TO BATTLESHIP**************\n\n";
    cout << "your placement grid\n"; ///printing player placement grid
    print_array(me.placement_grid,row);

    ///player placement

    char orientation_input, x_coord;
    int  y_coord;

    cout << "carrier ship(5 spaces): press h for horizontal or v for vertical\n";
    cin >> orientation_input;
    cout << "carrier ship(5 spaces): enter x-coordinate position (a-j)\n";
    cin >> x_coord;
    cout << "carrier ship(5 spaces): enter y-coordinate position (1-10)\n";
    cin >> y_coord;
    carrier_placement(orientation_input,x_coord,y_coord,me);

    cout << "your placement grid\n";
    print_array(me.placement_grid,row);

    char ori_battleship, battleship_x;
    int battleship_y;
    cout << "battleship ship(4 spaces): press h for horizontal or v for vertical\n";
    cin >> ori_battleship;
    cout << "battleship ship(4 spaces): enter x-coordinate position (a-j)\n";
    cin >> battleship_x;
    cout << "battleship ship(4 spaces): enter y-coordinate position (1-10)\n";
    cin >> battleship_y;
    battleship_placement(ori_battleship,battleship_x,battleship_y,me);

    cout << "your placement grid\n";
    print_array(me.placement_grid,row);

    char ori_cruiser, cruiser_x;
    int cruiser_y;
    cout << "cruiser ship(3 spaces): press h for horizontal or v for vertical\n";
    cin >> ori_cruiser;
    cout << "cruiser ship(3 spaces): enter x-coordinate position (a-j)\n";
    cin >> cruiser_x;
    cout << "cruiser ship(3 spaces): enter y-coordinate position (1-10)\n";
    cin >> cruiser_y;
    cruiser_placement(ori_cruiser,cruiser_x,cruiser_y,me);

    cout << "your placement grid\n";
    print_array(me.placement_grid, row);

    char ori_sub, sub_x;
    int sub_y;
    cout << "submarine ship(3 spaces): press h for horizontal or v for vertical\n";
    cin >> ori_sub;
    cout << "submarine ship(3 spaces): enter x-coordinate position (a-j)\n";
    cin >> sub_x;
    cout << "submarine ship(3 spaces): enter y-coordinate position (1-10)\n";
    cin >> sub_y;
    sub_placement(ori_sub,sub_x,sub_y,me);

    cout << "your placement grid\n";
    print_array(me.placement_grid, row);

    char ori_destroyer, destroyer_x;
    int destroyer_y;
    cout << "destroyer ship(2 spaces): press h for horizontal or v for vertical\n";
    cin >> ori_destroyer;
    cout << "destroyer ship(2 spaces): enter x-coordinate position (a-j)\n";
    cin >> destroyer_x;
    cout << "destroyer ship(2 spaces): enter y-coordinate position (1-10)\n";
    cin >> destroyer_y;
    destroyer_placement(ori_destroyer,destroyer_x,destroyer_y,me);

    cout << "your placement grid\n";
    print_array(me.placement_grid, row); ///printing player placement grid

  ///computer placement

  ///computer carrier placement
    cout << endl;
    char comp_carrier_ori = 'h';
    int comp_carrier_x = rand() % 10 + 1, comp_carrier_y = rand() % 10 + 1;
    comp_carrier_placement(comp_carrier_ori,comp_carrier_x,comp_carrier_y,it);


    ///computer battleship placement
    char comp_battleship_ori = 'v';
    int comp_battleship_x = rand() % 10 + 1, comp_battleship_y = rand() % 10 + 1;
    comp_battleship_placement(comp_battleship_ori,comp_battleship_x,comp_battleship_y,it);


    ///computer cruiser placement
    char comp_cruiser_ori = 'h';
    int comp_cruiser_x = rand() % 10 + 1, comp_cruiser_y = rand() % 10 + 1;
    comp_cruiser_placement(comp_cruiser_ori,comp_cruiser_x,comp_cruiser_y,it);

    
    ///computer submarine placement
    char comp_sub_ori = 'v';
    int comp_sub_x = rand() % 10 + 1, comp_sub_y = rand() % 10 + 1;
    comp_sub_placement(comp_sub_ori,comp_sub_x,comp_sub_y,it);

    cout << endl;
    ///computer destroyer placement
    char comp_destroyer_ori = 'h';
    int comp_destroyer_x = rand() % 10 + 1, comp_destroyer_y = rand() % 10 + 1;
    comp_destroyer_placement(comp_destroyer_ori,comp_destroyer_x,comp_destroyer_y,it);

   //  ///printing computer placement grid optional

    cout << endl;

    ///menu
    srand(time(NULL));
    bool menu = true;
    while(menu)
    {
        ///check sum of player and computer array

        if(sum_of_array(it.placement_grid,row) == 0)
        {
            cout << "you win!" << endl;
            break;
        }else if(sum_of_array(me.placement_grid, row) == 0)
        {
            cout << "you lose!" << endl;
            break;
        }

        ///computer guess

        int comp_shot_x = (rand() % 10) + 1, comp_shot_y = (rand() % 10) + 1;
        int comp_row_index = --comp_shot_y, comp_col_index = --comp_shot_x;

        it.shot_grid[comp_row_index][comp_col_index] = 1;

        ///compares computer shot grid to player placement grid

        if (it.shot_grid[comp_row_index][comp_col_index] == me.placement_grid[comp_row_index][comp_col_index])
        {
            me.placement_grid[comp_row_index][comp_col_index] = 0;///set player placement grid to 0 hit/check array sum
            cout << "computer has hit column " << ++comp_shot_x << " and row " << ++comp_shot_y << endl;
            cout << "computer check grid\n";
            it.check_grid[comp_row_index][comp_col_index] = 'O'; ///places O in computer check grid
            print_char_array(it.check_grid, row);

        } else {
            cout << "computer has missed column " << ++comp_shot_x << " and row " << ++comp_shot_y << endl;
            cout << "computer check grid\n";
            it.check_grid[comp_row_index][comp_col_index] = 'X'; ///places X in computer check grid
            print_char_array(it.check_grid, row);
        }



        ///player guess

        cout << "do you want to continue? y or n\n";
        char answer;
        cin >> answer;
        if (answer == 'y') {
            int shot_y;
            char shot_x, orig_shot_x;
            cout << "guess the x-coordinate (a-j)\n";
            cin >> shot_x;
            orig_shot_x = shot_x; ///save the original char column
            cout << "guess the y-coordinate (1-10)\n";
            cin >> shot_y;

            int convert = static_cast<int>(shot_x) - 96; ///convert = shot_x
            int row_index = --shot_y, col_index = --convert;
            me.shot_grid[row_index][col_index] = 1;

            ///compares player shot grid to computer placement grid

            if (me.shot_grid[row_index][col_index] == it.placement_grid[row_index][col_index])
            {
                it.placement_grid[row_index][col_index] = 0; ///set computer placement grid to 0/check array sum
                cout << "you hit column " << orig_shot_x << " and row " << ++shot_y << endl;
                cout << "your check grid\n";
                me.check_grid[row_index][col_index] = 'O'; /// places O in player check grid
                print_char_array(me.check_grid, row);

            } else {
                cout << "you missed column " << orig_shot_x << " and row " << ++shot_y << endl;
                cout << "your check grid\n";
                me.check_grid[row_index][col_index] = 'X'; ///places X in player check grid
                print_char_array(me.check_grid, row);
            }


        } else
            break;


    }
    cout << "your guess grid\n";
    print_char_array(me.check_grid, row);
    cout << endl << "computer's placement ships\n";
    print_array(it.placement_grid,row);

    cout << "goodbye" << endl;

    return 0;
}