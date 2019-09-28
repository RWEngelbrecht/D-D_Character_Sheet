#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <string.h>


typedef struct R_char
{
    //Basic Info
    char *name;
    char *class;
    unsigned int level;
    char background[50];
    char allignment[10];
    unsigned int exp;
    
    //Stats
    int ac;
    int hp;
    int initiative;
    int speed;
    int tempHp;
    char *hitDice;
    
    //Skills
    int strength;
    int strMod;
    int dexterity;
    int dexMod;
    int constitution;
    int cntMod;
    int intelligence;
    int intMod;
    int wisdom;
    int wisMod;
    int charisma;
    int chrMod;
    int passivePerception;
    
    //Equipment
    char mainWeapon[20];
    char scndWeapon[];
    
    
}   RigardtChar;

int main()
{
    double expEarned;
//    int profBonus = 2;
    char action;
    int dieNum = 0;
    char menuAct;
    int healthDiff;
    
    RigardtChar basicInfo;
    
    strcpy(basicInfo.name, "Ront the Ravenous");
    strcpy(basicInfo.class, "Barbarian");
    strcpy(basicInfo.background, "Outlander");
    strcpy(basicInfo.allignment, "CN");
    basicInfo.level = 2;
    basicInfo.exp = 0;
    
    RigardtChar skills;
    skills.strength = 20;
    skills.strMod = 4;
    skills.dexterity = 14;
    skills.dexMod = 2;
    skills.constitution = 19;
    skills.cntMod = 3;
    skills.intelligence = 7;
    skills.intMod = 0;
    skills.wisdom = 11;
    skills.wisMod = 0;
    skills.charisma = 11;
    skills.chrMod = 1;
    skills.passivePerception = 10;
    
    RigardtChar stats;
    stats.ac = 16;
    stats.hp = 30;
    stats.initiative = dieNum + skills.dexMod;
    stats.speed = 30;
    stats.tempHp = stats.hp;
    strcpy(stats.hitDice, "1d6");
    
    
START:  printf("What do you want to do?\nEXP(x)\nSkills(s)\nStats/Play(p)\nSkill check(c)\n");
        scanf(" %c", &action);
    
    if(action == 'X' || action =='x')
    {
        
        while(basicInfo.level < 100)
        {
            printf("%s's current Level is %d and has %f XP.\n", basicInfo.name, basicInfo.level, basicInfo.exp);
            printf("Please enter XP earned: \n");
            
            scanf("%lf", &expEarned);
            basicInfo.exp = expEarned + basicInfo.exp;
            
            int levelGain = expEarned/100;
            int expCarry = levelGain*100;
            
            if(basicInfo.exp >= 100)
            {
                
                basicInfo.level = basicInfo.level + levelGain;
                printf("Level Up!\n");
                basicInfo.exp = basicInfo.exp - expCarry;
                printf("%s's current Level is %d and has %f XP.\n", basicInfo.name, basicInfo.level, basicInfo.exp);
                
                goto START;
            }
            else{
                goto START;
            }
        }
    }
    else if(action == 'S' || action =='s'){
        printf("Your skills:\nStrength: %d\nDexterity: %d\nConstitution: %d\nIntelligence: %d\nWisdom: %d\nCharisma: %d\nPassive Perception: %d\n", skills.strength, skills.dexterity, skills.constitution, skills.intelligence, skills.wisdom, skills.charisma,skills.passivePerception);
        goto START;
    }
    else if(action == 'P' || action == 'p'){
    MENU:   printf("See stats(s)\nRoll initiative(i)\nChange HP(h)\nGo back(e)\nMain menu(q)\n");
        scanf(" %c", &menuAct);
        
        if(menuAct == 'S' || menuAct == 's'){
            printf("Level: %d\nCurrent EXP: %f\nAC: %d\nMax HP: %d\nSpeed: %d\nCurrent HP: %d\n", basicInfo.level, basicInfo.exp, stats.ac, stats.hp, stats.speed, stats.tempHp);
            goto MENU;
            }
        else if(menuAct == 'i' || menuAct == 'I'){
            printf("Roll for initiative.\nEnter result of die throw: ");
            scanf("%d", &dieNum);
            
            stats.initiative = dieNum + skills.dexMod;
            
            printf("Your initiative is %d.\n", stats.initiative);
            goto MENU;
        }
        else if(menuAct == 'h' || menuAct == 'H'){
            printf("Your current health is %d.\nHealth up(u) or Health down(d)?\n", stats.tempHp);
            scanf(" %c", &menuAct);
            if(menuAct == 'u' || menuAct == 'U'){
               
                printf("Add how much health?\n");
                scanf("%d", &healthDiff);
                if(stats.tempHp + healthDiff < stats.hp){
                    stats.tempHp = stats.tempHp + healthDiff;
                    printf("Your current hp is %d.\n", stats.tempHp);
                    goto MENU;
                }else if(stats.tempHp + healthDiff > stats.hp){
                    printf("Exceeds max HP!\n");
                    stats.tempHp = (stats.tempHp + healthDiff) - (stats.tempHp + healthDiff - stats.hp);
                    printf("Your Current HP is %d.\n", stats.tempHp);
                    goto MENU;
                }
                
            }else if(menuAct == 'd' || menuAct == 'D'){
                printf("Your current HP is %d.\nHow many HPs were lost?\n", stats.tempHp);
                scanf("%d", &healthDiff);
                if((stats.tempHp - healthDiff) > 0){
                    
                    stats.tempHp = stats.tempHp - healthDiff;
                    printf("Your current HP is %d.\n", stats.tempHp);
                    goto MENU;
                }else{
                    printf("YOU DIED.\n");
                    goto START;
                }
            }
        }
        else if(menuAct == 'e' || menuAct == 'E'){
            goto MENU;
        }
        else if(menuAct == 'q' || menuAct == 'Q'){
            goto START;
        }
    }
    else if(action == 'c' || action == 'C'){
CMENU:  printf("Which skill do you need to check?\nStrength(s)\nDexterity(d)\nConstitution(n)\nIntelligence(d)\nWisdom(w)\nCharisma(c)\n");
        scanf(" %c", &menuAct);
        if(menuAct == 'Q' || menuAct == 'q'){
            goto START;
        }
        printf("Enter your die roll.\n");
        scanf("%d", &dieNum);
        
        if(menuAct == 's' || menuAct == 'S'){
            printf("Your Strength check is %d.\n", dieNum + skills.strMod);
            goto CMENU;
        }else if(menuAct == 'd' || menuAct == 'D'){
            printf("Your Dexterity check is %d.\n", dieNum + skills.dexMod);
            goto CMENU;
        }else if(menuAct == 'n' || menuAct == 'N'){
            printf("Your Constitution check is %d.\n", dieNum + skills.cntMod);
            goto CMENU;
        }else if(menuAct == 'i' || menuAct == 'I'){
            printf("Your Intelligence check is %d.\n", dieNum + skills.intMod);
            goto CMENU;
        }else if(menuAct == 'w' || menuAct == 'W'){
            printf("Your Wisdom check is %d.\n", dieNum + skills.wisMod);
            goto CMENU;
        }else if(menuAct == 'c' || menuAct == 'C'){
            printf("Your Charisma check is %d.\n", dieNum + skills.chrMod);
            goto CMENU;
        }else if(menuAct == 'e' || menuAct == 'E'){
            goto CMENU;
        }else if(menuAct == 'Q' || menuAct == 'q'){
            goto START;
        }
    }
    
    return 0;
}

