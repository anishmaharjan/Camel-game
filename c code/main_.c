// Euphoria To C version 2.5
#include <time.h>
#include "C:\EUPHORIA\include\euphoria.h"
#include <float.h>
#include "main_.h"

int Argc;
char **Argv;
unsigned default_heap;
__declspec(dllimport) unsigned __stdcall GetProcessHeap(void);
unsigned long *peek4_addr;
unsigned char *poke_addr;
unsigned long *poke4_addr;
struct d temp_d;
double temp_dbl;

void main(int argc, char *argv[])
{
    int _11 = 0;
    int _349 = 0;
    int _0, _1, _2;
    
    void *hInstance;
    
    hInstance = 0;
    _control87(MCW_EM,MCW_EM);
    default_heap = GetProcessHeap();
    Argc = argc;
    Argv = argv;
    winInstance = hInstance;
    eu_startup(_00, _01, 1, (int)CLOCKS_PER_SEC, (int)CLOCKS_PER_SEC);
    init_literal();
    shift_args(argc, argv);
    RefDS(_9);
    _2DIGITS = _9;
    Concat((object_ptr)&_2HEX_DIGITS, _2DIGITS, (s1_ptr)_10);
    Concat((object_ptr)&_2START_NUMERIC, _2DIGITS, (s1_ptr)_12);
    RefDS(_28);
    _2ESCAPE_CHARS = _28;
    RefDS(_29);
    _2ESCAPED_CHARS = _29;
    RefDS(_313);
    _3PI = _313;
    _3PI_HALF = NewDouble(DBL_PTR(_3PI)->dbl / DBL_PTR(_314)->dbl);

    // clear_screen() --Erase text from the screen. 
    ClearScreen();

    // line = 1 
    _1line = 1;

    // while 1 do --The game's loop. 
L1:

    // puts(1, "\n Welcome to The Game Of Camel. ") 
    EPuts(1, _341);

    // while line = 1 do 
L2:
    if (_1line != 1)
        goto L3;

    // puts(1, "Would you like instructions? Type Y for ") 
    EPuts(1, _343);

    // puts(1, "yes or N for no. ") 
    EPuts(1, _344);

    // key = wait_key() --Wait for the user to enter something 
    _0 = _2wait_key();
    _1key = _0;

    // puts(1, '\n') 
    EPuts(1, 10);

    // if key = 'n' or key = 'N' then 
    DeRef(_11);
    _11 = (_1key == 110);
    if (_11 != 0) {
        goto L4;
    }
    DeRef(_349);
    _349 = (_1key == 78);
L5:
    if (_349 == 0)
        goto L6;
L4:

    // line = 2 --Jump to the next while-loop. 
    _1line = 2;

    // exit --Continue on... 
    goto L3;
    goto L2;
L6:

    // elsif key = 'y' or key = 'Y' then--Give the instructions now. 
    DeRef(_349);
    _349 = (_1key == 121);
    if (_349 != 0) {
        goto L7;
    }
    DeRef(_11);
    _11 = (_1key == 89);
L8:
    if (_11 == 0)
        goto L2;
L7:

    // puts(1, "Welcome to the game of Camel. ") 
    EPuts(1, _355);

    // puts(1, "The object of the game is to travel 200 ") 
    EPuts(1, _356);

    // puts(1, "miles across the Great Gobi Desert. ") 
    EPuts(1, _357);

    // puts(1, "A tribe of knocked kneed Pigmies will be ") 
    EPuts(1, _358);

    // puts(1, "chasing you. ") 
    EPuts(1, _359);

    // puts(1, "You will be asked for commands every so ") 
    EPuts(1, _360);

    // puts(1, "often. ") 
    EPuts(1, _361);

    // puts(1, "C O M M A N D S: ") 
    EPuts(1, _362);

    // puts(1, "1 drink from your canteen, ") 
    EPuts(1, _363);

    // puts(1, "2 move ahead moderate speed, ") 
    EPuts(1, _364);

    // puts(1, "3 move ahead fast speed, ") 
    EPuts(1, _365);

    // puts(1, "4 stop for a rest, ") 
    EPuts(1, _366);

    // puts(1, "5 status check, ") 
    EPuts(1, _367);

    // puts(1, "and 6 hope for help. ") 
    EPuts(1, _368);

    // puts(1, "You will get a quart of water which will last") 
    EPuts(1, _369);

    // puts(1, "you six drinks. ") 
    EPuts(1, _370);

    // puts(1, "You must renew your water supply at an ") 
    EPuts(1, _371);

    // puts(1, "Oases completely. ") 
    EPuts(1, _372);

    // puts(1, "You get a half quart if found by help. ") 
    EPuts(1, _373);

    // puts(1, "If help does not find you after command ") 
    EPuts(1, _374);

    // puts(1, "'6', you lose. ") 
    EPuts(1, _375);

    // line = 2 
    _1line = 2;

    // exit --Jump to the next while-loop. 
    goto L3;
L9:
LA:

    // end while 
    goto L2;
L3:

    // init() --Call the subroutine to initialize the 
    _1init();

    // puts(1, "Good luck and good cameling. ") 
    EPuts(1, _376);

    // while line = 2 do--Check where you are before letting you proceed. 
LB:
    if (_1line != 2)
        goto LC;

    // if you >199 then --You made it! 
    if (_1you <= 199)
        goto LD;

    // puts(1, "YOU WIN! A party is given in your honor! ") 
    EPuts(1, _380);

    // puts(1, "The Pigmies are planning to attend. ") 
    EPuts(1, _381);

    // line = 4 --Jump to the last while-loop. 
    _1line = 4;

    // exit --Go ahead, JUMP! 
    goto LC;
LD:

    // if pigmies >you then 
    if (_1pigmies <= _1you)
        goto LE;

    // pigmies -= 1 --Let the Pigmies move back some to make it easier to catch you. 
    _1pigmies = _1pigmies - 1;

    // printf(1, "The Pigmies are %d miles ahead of you.", {pigmies-you}) 
    DeRef(_11);
    _11 = _1pigmies - _1you;
    if (_11 + HIGH_BITS >= 0)
        _11 = NewDouble((double)_11);
    _0 = _11;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_11);
    *((int *)(_2+4)) = _11;
    _11 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(1, _384, _11);
LE:

    // if rand(2) = 1 and pigmies <you then --The Pigmies can cheat! 
    DeRef(_11);
    _11 = good_rand() % ((unsigned)2) + 1;
    _11 = (_11 == 1);
    if (_11 == 0) {
        goto LF;
    }
    DeRef(_349);
    _349 = (_1pigmies < _1you);
L10:
    if (_349 == 0)
        goto LF;

    // if you-pigmies <5 then --They are less than five miles behind you. 
    DeRef(_349);
    _349 = _1you - _1pigmies;
    if (_349 + HIGH_BITS >= 0)
        _349 = NewDouble((double)_349);
    if (binary_op_a(GREATEREQ, _349, 5))
        goto L11;

    // pigmies = you --Let them catch up to you. 
    _1pigmies = _1you;
L11:
LF:

    // if you >pigmies then --You are ahead of the pigmies. 
    if (_1you <= _1pigmies)
        goto L12;

    // if rand(2) = 2 then --Trap the pigmies for a bit. 
    DeRef(_349);
    _349 = good_rand() % ((unsigned)2) + 1;
    if (_349 != 2)
        goto L13;

    // pigmies = rand(you) --Move at a random speed. 
    _1pigmies = good_rand() % ((unsigned)_1you) + 1;
    goto L14;
L13:

    // pigmies += rand(20) 
    DeRef(_349);
    _349 = good_rand() % ((unsigned)20) + 1;
    _1pigmies = _1pigmies + _349;
L14:
L12:

    // if pigmies = you then 
    if (_1pigmies != _1you)
        goto L15;

    // puts(1, "THE PIGMIES HAVE CAPTURED YOU! CAMEL AND ") 
    EPuts(1, _401);

    // puts(1, "PEOPLE SOUP IS THEIR FAVORITE DISH. ") 
    EPuts(1, _402);

    // line = 4 --Jump to the last while-loop. 
    _1line = 4;

    // exit --GO AHEAD, JUMP! 
    goto LC;
L15:

    // if gocommands <3 then --You had better get a drink. 
    if (_1gocommands >= 3)
        goto L16;

    // puts(1, "W A R N I N G -- GET A DRINK ") 
    EPuts(1, _404);
L16:

    // if gocommands = 0 then --Too many commands without 
    if (_1gocommands != 0)
        goto L17;

    // puts(1, "YOU RAN OUT OF WATER... SORRY CHUM!!!!!! ") 
    EPuts(1, _406);

    // line = 3 --Jump to the next while-loop. 
    _1line = 3;

    // exit --GO AHEAD, JUMP! 
    goto LC;
L17:

    // if days < 1 then --You ran your camel to death! 
    if (_1days >= 1)
        goto L18;

    // puts(1, "\n YOU DIRTY LOUSY RAP SCALLION!!! ") 
    EPuts(1, _408);

    // puts(1, "YOU RAN YOUR INNOCENT CAMEL TO DEATH! ") 
    EPuts(1, _409);

    // line = 3 --Jump to the next while-loop. 
    _1line = 3;

    // exit --GO AHEAD, JUMP! 
    goto LC;
L18:

    // if you = 0 then --You are just starting. 
    if (_1you != 0)
        goto L19;

    // puts(1, "You are in the middle of the desert at an ") 
    EPuts(1, _411);

    // puts(1, "Oases. ") 
    EPuts(1, _412);
L19:

    // if pigmies and you >pigmies then 
    if (_1pigmies == 0) {
        goto L1A;
    }
    DeRef(_11);
    _11 = (_1you > _1pigmies);
L1B:
    if (_11 == 0)
        goto L1A;

    // printf(1, "The Pigmies are %d miles behind you. ",{you-pigmies}) 
    DeRef(_11);
    _11 = _1you - _1pigmies;
    if (_11 + HIGH_BITS >= 0)
        _11 = NewDouble((double)_11);
    _0 = _11;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_11);
    *((int *)(_2+4)) = _11;
    _11 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(1, _415, _11);
L1A:

    // printf(1, "You have travelled %d miles altogether, " & 
    Concat((object_ptr)&_11, _418, (s1_ptr)_419);
    DeRef(_349);
    _349 = 200 - _1you;
    if (_349 + HIGH_BITS >= 0)
        _349 = NewDouble((double)_349);
    _0 = _349;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _1you;
    ((int *)_2)[2] = _349;
    Ref(_349);
    _349 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(1, _11, _349);

    // while 3 do 
L1C:

    // puts(1, "Your command? ") 
    EPuts(1, _424);

    // key = wait_key() --Wait for the user to enter something 
    _0 = _2wait_key();
    _1key = _0;

    // puts(1, '\n') 
    EPuts(1, 10);

    // if key = '1' then --The number one was pressed. 
    if (_1key != 49)
        goto L1D;

    // if drinks = 0 then 
    if (_1drinks != 0)
        goto L1E;

    // puts(1, "YOU RAN OUT OF WATER. SORRY CHUM!!!!!! ") 
    EPuts(1, _429);

    // line = 3 --Jump to the next while-loop. 
    _1line = 3;
    goto L1C;
L1E:

    // drinks -= 1 
    _1drinks = _1drinks - 1;

    // puts(1, "BETTER WATCH FOR A OASIS. ") 
    EPuts(1, _431);

    // gocommands = 4 --Reset how many commands you can go 
    _1gocommands = 4;

    // exit --Repeat all over again starting from the 
    goto LB;
L1F:
    goto L1C;
L1D:

    // elsif key = '2' then --The number two was pressed. 
    if (_1key != 50)
        goto L20;

    // you += rand(5) --Move randomly from 1 to 5 miles. 
    DeRef(_349);
    _349 = good_rand() % ((unsigned)5) + 1;
    _1you = _1you + _349;

    // days -= 1 --Subtract one day from the camel. 
    _1days = _1days - 1;

    // puts(1, "Your camel likes this paste! ") 
    EPuts(1, _437);

    // gocommands -= 1 --Subtract commands you have before drinking. 
    _1gocommands = _1gocommands - 1;

    // exit --Tell where you are. 
    goto LB;
    goto L1C;
L20:

    // elsif key = '3' then --The number three was pressed. 
    if (_1key != 51)
        goto L21;

    // gocommands -= 1 --You wasted one more command. 
    _1gocommands = _1gocommands - 1;

    // n = rand(4) --What happens here? 
    _1n = good_rand() % ((unsigned)4) + 1;

    // if n = 1 then --The Note-taker chose the first action. 
    if (_1n != 1)
        goto L22;

    // puts(1, "YOU HAVE BEEN CAUGHT IN A SAND-STORM... ") 
    EPuts(1, _444);

    // puts(1, "GOOD LUCK! ") 
    EPuts(1, _445);

    // you += rand(5) --Slow down. 
    DeRef(_349);
    _349 = good_rand() % ((unsigned)5) + 1;
    _1you = _1you + _349;

    // exit --Return to the previous while-loop and see 
    goto LB;
    goto L23;
L22:

    // elsif n = 2 then --The Note-taker chose to perform 
    if (_1n != 2)
        goto L24;

    // puts(1, "You have stopped at an Oases. Your camel is ") 
    EPuts(1, _449);

    // puts(1, "filling your canteen and eating figs. ") 
    EPuts(1, _450);

    // drinks = 6 --Put six more drinks in the canteen. 
    _1drinks = 6;

    // gocommands = 4 --Reset the commands. 
    _1gocommands = 4;

    // n = 4 --Force the Note-taker to do the last action. 
    _1n = 4;
    goto L23;
L24:

    // elsif n = 3 then --Oops! The Note-taker chose the 
    if (_1n != 3)
        goto L25;

    // puts(1, "YOU HAVE BEEN CAPTURED BY A HIDDENSAND-BERBER. ") 
    EPuts(1, _452);

    // puts(1, "Luckily the local sheik has agreed to their ") 
    EPuts(1, _453);

    // puts(1, "ransom-demands... But... watch for thePigmies. ") 
    EPuts(1, _454);

    // puts(1, "You have a new set of commands. ") 
    EPuts(1, _455);

    // puts(1, "#7 attempt an escape, or #8 wait for payment.") 
    EPuts(1, _456);

    // while 2 do --This while-loop lets the user type in 
L26:

    // puts(1, "Your sub-command? ") 
    EPuts(1, _457);

    // key = wait_key() --Wait for the user to enter something 
    _0 = _2wait_key();
    _1key = _0;

    // puts(1, '\n') 
    EPuts(1, 10);

    // if key = '7' then --The number seven was pressed. 
    if (_1key != 55)
        goto L27;

    // n = rand(2) --One of two things can happen. 
    _1n = good_rand() % ((unsigned)2) + 1;

    // if n = 1 then --You made it. 
    if (_1n != 1)
        goto L28;

    // puts(1, "CONGRATULATIONS! YOU SUCCESSFULLY ESCAPED! ") 
    EPuts(1, _462);

    // exit --Get out of this while-loop. 
    goto L29;
    goto L26;
L28:

    // puts(1, "You were mortally wounded by a pig stabber ") 
    EPuts(1, _463);

    // puts(1, "while trying to escape. ") 
    EPuts(1, _464);

    // line = 3 --Jump to the next while-loop. 
    _1line = 3;

    // exit --Go ahead, jump! 
    goto L29;
L2A:
    goto L26;
L27:

    // elsif key = '8' then --The number eight was pressed. 
    if (_1key != 56)
        goto L26;

    // puts(1, "Your ransom has been payed and you are ") 
    EPuts(1, _467);

    // puts(1, "free to go. The local sultin is collecting. ") 
    EPuts(1, _468);

    // puts(1, "Just Wait ") 
    EPuts(1, _469);

    // sleep(10) --Stop for ten seconds. 
    _3sleep(10);

    // you += rand(3) --Move from one to three miles. 
    DeRef(_349);
    _349 = good_rand() % ((unsigned)3) + 1;
    _1you = _1you + _349;

    // exit --Get out of this loop and continue. 
    goto L29;
L2B:
L2C:

    // end while 
    goto L26;
L29:
L25:
L23:

    // if n = 4 then --Your camel is burning across 
    if (_1n != 4)
        goto LB;

    // you += rand(20) --Randomly move from one to 
    DeRef(_349);
    _349 = good_rand() % ((unsigned)20) + 1;
    _1you = _1you + _349;

    // puts(1, "Your camel is burning across the desert ") 
    EPuts(1, _475);

    // puts(1, "sands. ") 
    EPuts(1, _476);

    // days -= 3 --Subtract three days from your camel. 
    _1days = _1days - 3;

    // exit --Get out of this loop, and find where we are. 
    goto LB;
L2D:

    // exit --Restart over again. 
    goto LB;
    goto L1C;
L21:

    // elsif key = '4' then --The number four was pressed. 
    if (_1key != 52)
        goto L2E;

    // puts(1, "Your camel thanks you. ") 
    EPuts(1, _480);

    // days = 7 --You now have seven good days left. 
    _1days = 7;

    // gocommands -= 1 --Lose one more command. 
    _1gocommands = _1gocommands - 1;

    // exit --Continue on with the application. 
    goto LB;
    goto L1C;
L2E:

    // elsif key = '5' then --Status Check Please? 
    if (_1key != 53)
        goto L2F;

    // printf(1, "Your camel has %d good days left. " & 
    {
        int concat_list[4];

        concat_list[0] = _487;
        concat_list[1] = _486;
        concat_list[2] = _485;
        concat_list[3] = _484;
        Concat_N((object_ptr)&_349, concat_list, 4);
    }
    _0 = _11;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _1days;
    *((int *)(_2+8)) = _1drinks;
    *((int *)(_2+12)) = _1gocommands;
    _11 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(1, _349, _11);
    goto L1C;
L2F:

    // elsif key = '6' then --HELP! SIX WAS PRESSED. 
    if (_1key != 54)
        goto L30;

    // n = rand(2) --Chose whether to give out help or not. 
    _1n = good_rand() % ((unsigned)2) + 1;

    // if n = 1 then --Give Help. 
    if (_1n != 1)
        goto L31;

    // puts(1, "Help has found you in a state of ") 
    EPuts(1, _494);

    // puts(1, "unconsciousness. ")--Let the camel rest for a while. 
    EPuts(1, _495);

    // days = 7 --Your camel is rejubinated. 
    _1days = 7;

    // drinks = 3 --You get the half-quart of water. 
    _1drinks = 3;

    // gocommands = 8 --You now have eight commands without 
    _1gocommands = 8;
    goto L1C;
L31:

    // line = 3 --Jump to the next while-loop. 
    _1line = 3;

    // exit --Go ahead! JUMP! 
    goto LB;
L32:
    goto L1C;
L30:

    // puts(1, "Invalid Option. ") 
    EPuts(1, _496);

    // puts(1, "The commands you can choose from are: ") 
    EPuts(1, _497);

    // puts(1, "1 drink from your canteen ") 
    EPuts(1, _498);

    // puts(1, "2 move ahead moderate speed ") 
    EPuts(1, _499);

    // puts(1, "3 move ahead fast speed ") 
    EPuts(1, _500);

    // puts(1, "4 stop for a rest ") 
    EPuts(1, _501);

    // puts(1, "5 status check ") 
    EPuts(1, _502);

    // puts(1, "6 hope for help ") 
    EPuts(1, _503);

    // puts(1, "Simply type the command in by number using ") 
    EPuts(1, _504);

    // puts(1, "Computer Braille and don't press ENTER. ") 
    EPuts(1, _505);
L33:

    // end while --End of while-loop two. 
    goto L1C;
L34:

    // end while --Done checking position. 
    goto LB;
LC:

    // if line = 3 then --This isn't a loop. It generates 
    if (_1line != 3)
        goto L35;

    // n = rand(5) --We have five loser statements. 
    _1n = good_rand() % ((unsigned)5) + 1;

    // puts(1, "Your body and soul lay a rest in the sand. ") 
    EPuts(1, _508);

    // if n = 1 then --This is the first loser statement. 
    if (_1n != 1)
        goto L36;

    // puts(1, "The National's Camel Union is not attending ") 
    EPuts(1, _510);

    // puts(1, "your funeral!!!!!! ") 
    EPuts(1, _511);
    goto L37;
L36:

    // elsif n = 2 then --This is the second loser statement. 
    if (_1n != 2)
        goto L38;

    // puts(1, "Your body was eaten by voltures and ") 
    EPuts(1, _513);

    // puts(1, "imported cannon balls!!!!!! ") 
    EPuts(1, _514);
    goto L37;
L38:

    // elsif n = 3 then --This is the third loser statement. 
    if (_1n != 3)
        goto L39;

    // puts(1, "The local shiek now uses your skull for a ") 
    EPuts(1, _516);

    // puts(1, "chain purse!!!!!! ") 
    EPuts(1, _517);
    goto L37;
L39:

    // elsif n = 4 then --This is the fourth loser statement. 
    if (_1n != 4)
        goto L3A;

    // puts(1, "People with little inteligence should ") 
    EPuts(1, _519);

    // puts(1, "stay out of the desert. ") 
    EPuts(1, _520);
    goto L37;
L3A:

    // elsif n = 5 then --This is the last loser statement. 
    if (_1n != 5)
        goto L3B;

    // puts(1, "Turkeys should fly, not ride camels. ") 
    EPuts(1, _522);
L3B:
L37:
L35:

    // line = 4 --Jump to the last while-loop. 
    _1line = 4;

    // while line = 4 do --The Last while-loop. 
L3C:
    if (_1line != 4)
        goto L1;

    // puts(1, "Want another camel and a new game? ") 
    EPuts(1, _524);

    // key = wait_key() --Wait for the user to enter something 
    _0 = _2wait_key();
    _1key = _0;

    // puts(1, '\n') 
    EPuts(1, 10);

    // if key = 'y' or key = 'Y' then --Yes was entered. 
    DeRef(_11);
    _11 = (_1key == 121);
    if (_11 != 0) {
        goto L3D;
    }
    DeRef(_349);
    _349 = (_1key == 89);
L3E:
    if (_349 == 0)
        goto L3F;
L3D:

    // line = 1 --Jump to the first while-loop. 
    _1line = 1;

    // exit --Start all over. 
    goto L1;
    goto L3C;
L3F:

    // elsif key = 'n' or key = 'N' then --No was entered. 
    DeRef(_349);
    _349 = (_1key == 110);
    if (_349 != 0) {
        goto L40;
    }
    DeRef(_11);
    _11 = (_1key == 78);
L41:
    if (_11 == 0)
        goto L3C;
L40:

    // puts(1, "CHICKEN! ") 
    EPuts(1, _532);

    // sleep(5) --Suspend execution for five seconds. 
    _3sleep(5);

    // abort(0) --Shutdown the program. 
    UserCleanup(0);
L42:
L43:

    // end while 
    goto L3C;
L44:

    // end while 
    goto L1;
L45:
    Cleanup(0);
}
