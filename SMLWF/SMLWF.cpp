#define NOMINMAX
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <format>
#include <windows.h>
#include "Utilities.h"
#include "Functions.h"
#include "Battlefield.h"
#include "Weapon.h"
#include "Gun.h"
#include "Pistol.h"
#include "Shotgun.h"
#include "SMG.h"
#include "AR.h"
#include "Sniper.h"
#include "MG.h"
#include "Explosive.h"
#include "Melee.h"
using namespace std;

int main()
{
    // Classes
    Utilities utility;
    Functions functions;
    Battlefield battlefield;

    Pistol pistolTemp;
    Shotgun shotgunTemp;
    SMG smgTemp;
    AR arTemp;
    Sniper sniperTemp;
    MG mgTemp;
    Explosive explosiveTemp;
    Melee meleeTemp;

    vector<Pistol> pistol;
    vector<Shotgun> shotgun;
    vector<SMG> smg;
    vector<AR> ar;
    vector<Sniper> sniper;
    vector<MG> mg;
    vector<Explosive> explosive;
    vector<Melee> melee;

    // Files
    fstream fptr;

    // Utility Variables
    int index;

    string fileName;

    // Temporary Variables
    string tempString;
    int tempInt;
    float tempFloat;

    // Input Variables
    string nameInput;
    float damageInput;
    float accuracyInput;
    float crInput;
    float cdInput;

    int magSizeInput;
    float reloadSpeedInput;
    int bulletSpeedInput;
    int fireRateInput;

    string weaponInventoryInput;

    // Validation Variables
    bool isNameTaken;

    // Warp Variables
    int yesnoWarp;
    int mainWarp;
    int creatorWarp;
    int inventoryWarp;
    int settingsWarp;
    int detailWarp;
    int arenaWarp;

    // Size variables
    int pistols = 0;
    int shotguns = 0;
    int smgs = 0;
    int ars = 0;
    int snipers = 0;
    int mgs = 0;
    int explosives = 0;
    int melees = 0;
    int totalWeapons;

    // "Destroy" Variables
    string destroyWeaponInput;
    string destroyCategory;

    // Settings Variables
    int displayType = 1; // 1 = mixed int and float ; 2 = int only
    int sortMode = 1; // 1 = Creation ; 2 = Ascending ; 3 = Descending

    // Randomizer Seed
    srand(time(NULL));

    // Color Variable
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);

    /*
    do
    {
        do
        {
            system("cls");

            cin >> tempString;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (battlefield.putObject(tempString, 0));
    }
    while (true);
    */

    /*
     File Code
     */
    functions.fileRead(pistol, shotgun, smg, ar, sniper, mg, explosive, melee, pistols, shotguns, smgs, ars, snipers, mgs, explosives, melees, totalWeapons);

    // Main Code
    do
    {
        do
        {
            utility.logo();
            
            cout << "Where do you want to go?\n";
            cout << "1. Inventory\n";
            cout << "2. Create Weapon\n";
            cout << "3. Test Weapon\n";
            cout << "4. Destroy Weapon\n";
            cout << "5. Settings\n";
            cout << "6. Exit\n\n";

            cout << "Your Choice: ";
            cin >> mainWarp;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        while (mainWarp < 1 || mainWarp > 6);

        // Inventory
        if (mainWarp == 1) {
            do
            {
                do
                {
                    utility.logo();
                    utility.subtitile("Inventory");

                    cout << "Which storage you wanna go?\n";
                    cout << "1. Pistol\n";
                    cout << "2. Shotgun\n";
                    cout << "3. SMG\n";
                    cout << "4. Assault Rifle\n";
                    cout << "5. Sniper\n";
                    cout << "6. Machine Gun\n";
                    cout << "7. Explosive\n";
                    cout << "8. Melee\n";
                    cout << "9. Main Menu\n\n";

                    cout << "Your choice: ";
                    cin >> inventoryWarp;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                while (inventoryWarp < 1 || inventoryWarp > 9);

                if (inventoryWarp != 9) {
                    do
                    {
                        do
                        {
                            utility.logo();

                            // Pistol
                            if (inventoryWarp == 1) {
                                utility.subtitile("Pistol");
                                utility.tableHeaderDisplay();

                                if (pistols == 0) {
                                    cout << "NO DATA!\n";
                                }
                                else {
                                    for (int i = 0; i < pistols; i++) {
                                        if (displayType == 1) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6.2f}% | {4:>8.2f}% | {5:>8.2f}% \n", i + 1, pistol[i].getName(), (int)pistol[i].getDamage(), pistol[i].getAccuracy(), pistol[i].getCR(), pistol[i].getCD());
                                        }
                                        else if (displayType == 2) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6}% | {4:>8}% | {5:>8}% \n", i + 1, pistol[i].getName(), (int)pistol[i].getDamage(), (int)pistol[i].getAccuracy(), (int)pistol[i].getCR(), (int)pistol[i].getCD());
                                        }
                                    }
                                }

                                cout << endl;
                            }

                            // Shotgun
                            else if (inventoryWarp == 2) {
                                utility.subtitile("Shotgun");
                                utility.tableHeaderDisplay();

                                if (shotguns == 0) {
                                    cout << "NO DATA!\n";
                                }
                                else {
                                    for (int i = 0; i < shotguns; i++) {
                                        if (displayType == 1) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6.2f}% | {4:>8.2f}% | {5:>8.2f}% \n", i + 1, shotgun[i].getName(), (int)shotgun[i].getDamage(), shotgun[i].getAccuracy(), shotgun[i].getCR(), shotgun[i].getCD());
                                        }
                                        else if (displayType == 2) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6}% | {4:>8}% | {5:>8}% \n", i + 1, shotgun[i].getName(), (int)shotgun[i].getDamage(), (int)shotgun[i].getAccuracy(), (int)shotgun[i].getCR(), (int)shotgun[i].getCD());
                                        }
                                    }
                                }

                                cout << endl;
                            }

                            // SMG
                            else if (inventoryWarp == 3) {
                                utility.subtitile("SMG");
                                utility.tableHeaderDisplay();

                                if (smgs == 0) {
                                    cout << "NO DATA!\n";
                                }
                                else {
                                    for (int i = 0; i < smgs; i++) {
                                        if (displayType == 1) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6.2f}% | {4:>8.2f}% | {5:>8.2f}% \n", i + 1, smg[i].getName(), (int)smg[i].getDamage(), smg[i].getAccuracy(), smg[i].getCR(), smg[i].getCD());
                                        }
                                        else if (displayType == 2) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6}% | {4:>8}% | {5:>8}% \n", i + 1, smg[i].getName(), (int)smg[i].getDamage(), (int)smg[i].getAccuracy(), (int)smg[i].getCR(), (int)smg[i].getCD());
                                        }
                                    }
                                }

                                cout << endl;
                            }

                            // AR
                            else if (inventoryWarp == 4) {
                                utility.subtitile("Assault Rifle");
                                utility.tableHeaderDisplay();

                                if (ars == 0) {
                                    cout << "NO DATA!\n";
                                }
                                else {
                                    for (int i = 0; i < ars; i++) {
                                        if (displayType == 1) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6.2f}% | {4:>8.2f}% | {5:>8.2f}% \n", i + 1, ar[i].getName(), (int)ar[i].getDamage(), ar[i].getAccuracy(), ar[i].getCR(), ar[i].getCD());
                                        }
                                        else if (displayType == 2) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6}% | {4:>8}% | {5:>8}% \n", i + 1, ar[i].getName(), (int)ar[i].getDamage(), (int)ar[i].getAccuracy(), (int)ar[i].getCR(), (int)ar[i].getCD());
                                        }
                                    }
                                }

                                cout << endl;
                            }

                            // Sniper
                            else if (inventoryWarp == 5) {
                                utility.subtitile("Sniper");
                                utility.tableHeaderDisplay();

                                if (snipers == 0) {
                                    cout << "NO DATA!\n";
                                }
                                else {
                                    for (int i = 0; i < snipers; i++) {
                                        if (displayType == 1) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6.2f}% | {4:>8.2f}% | {5:>8.2f}% \n", i + 1, sniper[i].getName(), (int)sniper[i].getDamage(), sniper[i].getAccuracy(), sniper[i].getCR(), sniper[i].getCD());
                                        }
                                        else if (displayType == 2) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6}% | {4:>8}% | {5:>8}% \n", i + 1, sniper[i].getName(), (int)sniper[i].getDamage(), (int)sniper[i].getAccuracy(), (int)sniper[i].getCR(), (int)sniper[i].getCD());
                                        }
                                    }
                                }

                                cout << endl;
                            }

                            // MG
                            else if (inventoryWarp == 6) {
                                utility.subtitile("Machine Gun");
                                utility.tableHeaderDisplay();

                                if (mgs == 0) {
                                    cout << "NO DATA!\n";
                                }
                                else {
                                    for (int i = 0; i < mgs; i++) {
                                        if (displayType == 1) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6.2f}% | {4:>8.2f}% | {5:>8.2f}% \n", i + 1, mg[i].getName(), (int)mg[i].getDamage(), mg[i].getAccuracy(), mg[i].getCR(), mg[i].getCD());
                                        }
                                        else if (displayType == 2) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6}% | {4:>8}% | {5:>8}% \n", i + 1, mg[i].getName(), (int)mg[i].getDamage(), (int)mg[i].getAccuracy(), (int)mg[i].getCR(), (int)mg[i].getCD());
                                        }
                                    }
                                }

                                cout << endl;
                            }

                            // Explosive
                            else if (inventoryWarp == 7) {
                                utility.subtitile("Explosive");
                                utility.tableHeaderDisplay();

                                if (explosives == 0) {
                                    cout << "NO DATA!\n";
                                }
                                else {
                                    for (int i = 0; i < explosives; i++) {
                                        if (displayType == 1) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6.2f}% | {4:>8.2f}% | {5:>8.2f}% \n", i + 1, explosive[i].getName(), (int)explosive[i].getDamage(), explosive[i].getAccuracy(), explosive[i].getCR(), explosive[i].getCD());
                                        }
                                        else if (displayType == 2) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6}% | {4:>8}% | {5:>8}% \n", i + 1, explosive[i].getName(), (int)explosive[i].getDamage(), (int)explosive[i].getAccuracy(), (int)explosive[i].getCR(), (int)explosive[i].getCD());
                                        }
                                    }
                                }

                                cout << endl;
                            }

                            // Melee
                            else if (inventoryWarp == 8) {
                                utility.subtitile("Melee");
                                utility.tableHeaderDisplay();

                                if (melees == 0) {
                                    cout << "NO DATA!\n";
                                }
                                else {
                                    for (int i = 0; i < melees; i++) {
                                        if (displayType == 1) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6.2f}% | {4:>8.2f}% | {5:>8.2f}% \n", i + 1, melee[i].getName(), (int)melee[i].getDamage(), melee[i].getAccuracy(), melee[i].getCR(), melee[i].getCD());
                                        }
                                        else if (displayType == 2) {
                                            cout << format("{0:<3} | {1:<20} | {2:>6} | {3:>6}% | {4:>8}% | {5:>8}% \n", i + 1, melee[i].getName(), (int)melee[i].getDamage(), (int)melee[i].getAccuracy(), (int)melee[i].getCR(), (int)melee[i].getCD());
                                        }
                                    }
                                }

                                cout << endl;
                            }

                            cout << "1. View Weapon Detail\n";
                            cout << "2. Back to Inventory Menu\n";

                            cout << "Your choice: ";
                            cin >> detailWarp;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        while (detailWarp != 1 && detailWarp != 2);

                        // View Weapon Detail
                        if (detailWarp == 1) {
                            cout << "Select Weapon: ";
                            cin >> weaponInventoryInput;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            functions.detailsDisplay(weaponInventoryInput, inventoryWarp, displayType, pistol, shotgun, smg, ar, sniper, mg, explosive, melee);
                        }

                        // Back
                        else if (detailWarp == 2) {
                            break;
                        }
                    }
                    while (true);
                }
            }
            while (inventoryWarp != 9);
        }

        // Create Weapon
        else if (mainWarp == 2) {
            do
            {
                do
                {
                    utility.logo();
                    utility.subtitile("Weapon Creator");

                    cout << "Choose a weapon type!\n";
                    cout << "1. Pistol\n";
                    cout << "2. Shotgun\n";
                    cout << "3. SMG\n";
                    cout << "4. Assault Rifle\n";
                    cout << "5. Sniper\n";
                    cout << "6. Machine Gun\n";
                    cout << "7. Explosive\n";
                    cout << "8. Melee\n";
                    cout << "9. Main Menu\n\n";

                    cout << "Your choice: ";
                    cin >> creatorWarp;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                while (creatorWarp < 1 || creatorWarp > 9);

                if (creatorWarp != 9) {
                    do
                    {
                        utility.logo();
                        utility.subtitile("Weapon Creator");

                        cout << "Input name (max = 20 character): ";
                        cin >> nameInput;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (nameInput.length() > 20) {
                            cout << "Name too long!";
                            cin.get();

                            continue;
                        }
                        if (!functions.checkValidName(nameInput, pistol, shotgun, smg, ar, sniper, mg, explosive, melee)) {
                            cout << "Name already taken!";
                            cin.get();

                            continue;
                        }

                        break;
                    }
                    while (true);

                    cout << "Set amount of damage: ";
                    cin >> damageInput;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Set weapon accuracy: ";
                    cin >> accuracyInput;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Input Critical Rate: ";
                    cin >> crInput;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Input Critical Damage: ";
                    cin >> cdInput;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    // Melee Input
                    if (creatorWarp == 8) {
                        utility.logo();
                        utility.subtitile("Weapon Creator");

                        cout << "Input Attack Speed: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        meleeTemp.setAtkSpeed(tempInt);


                        cout << "Input Max Range: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        meleeTemp.setMaxRange(tempInt);

                        cout << "\nInput Category: \n";
                        cout << "1. Sword\n";
                        cout << "2. Hammer\n";
                        cout << "3. Glove\n";
                        cout << "4. Spear\n\n";

                        do
                        {
                            cout << "Your choice: ";
                            cin >> tempInt;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        while (tempInt < 1 || tempInt > 4);

                        meleeTemp.setCategory(tempInt);
                    }

                    // Gun Input
                    else {
                        utility.logo();
                        utility.subtitile("Weapon Creator");

                        cout << "Set Magazine Size: ";
                        cin >> magSizeInput;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Input Reload Speed: ";
                        cin >> reloadSpeedInput;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Input Bullet Speed: ";
                        cin >> bulletSpeedInput;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Input Fire Rate: ";
                        cin >> fireRateInput;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    /*
                     Put the data to all classes
                     */

                    // Pistol
                    if (creatorWarp == 1) {
                        cout << "Input Effective Range: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        pistolTemp.setEffectiveRange(tempInt);

                        pistolTemp.setName(nameInput);
                        pistolTemp.setDamage(damageInput);
                        pistolTemp.setAccuracy(accuracyInput);
                        pistolTemp.setCR(crInput);
                        pistolTemp.setCD(cdInput);

                        pistolTemp.setMagSize(magSizeInput);
                        pistolTemp.setReloadSpeed(reloadSpeedInput);
                        pistolTemp.setBulletSpeed(bulletSpeedInput);
                        pistolTemp.setFireRate(fireRateInput);

                        pistolTemp.setIndex(++pistols);
                        //pistol.push_back(pistolTemp);
                        pistol.insert(pistol.begin(), 1, pistolTemp);
                    }

                    // Shotgun
                    else if (creatorWarp == 2) {
                        cout << "Set Pellet Count: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        shotgunTemp.setPelletCount(tempInt);

                        cout << "Input Effective Range: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        shotgunTemp.setEffectiveRange(tempInt);

                        shotgunTemp.setName(nameInput);
                        shotgunTemp.setDamage(damageInput);
                        shotgunTemp.setAccuracy(accuracyInput);
                        shotgunTemp.setCR(crInput);
                        shotgunTemp.setCD(cdInput);

                        shotgunTemp.setMagSize(magSizeInput);
                        shotgunTemp.setReloadSpeed(reloadSpeedInput);
                        shotgunTemp.setBulletSpeed(bulletSpeedInput);
                        shotgunTemp.setFireRate(fireRateInput);

                        shotgunTemp.setIndex(++shotguns);
                        //shotgun.push_back(shotgunTemp);
                        shotgun.insert(shotgun.begin(), 1, shotgunTemp);
                    }

                    // SMG
                    else if (creatorWarp == 3) {
                        cout << "Input Effective Range: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        smgTemp.setEffectiveRange(tempInt);

                        smgTemp.setName(nameInput);
                        smgTemp.setDamage(damageInput);
                        smgTemp.setAccuracy(accuracyInput);
                        smgTemp.setCR(crInput);
                        smgTemp.setCD(cdInput);

                        smgTemp.setMagSize(magSizeInput);
                        smgTemp.setReloadSpeed(reloadSpeedInput);
                        smgTemp.setBulletSpeed(bulletSpeedInput);
                        smgTemp.setFireRate(fireRateInput);

                        smgTemp.setIndex(++smgs);
                        //smg.push_back(smgTemp);
                        smg.insert(smg.begin(), 1, smgTemp);
                    }

                    // AR
                    else if (creatorWarp == 4) {
                        cout << "Input Effective Range: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        arTemp.setEffectiveRange(tempInt);

                        arTemp.setName(nameInput);
                        arTemp.setDamage(damageInput);
                        arTemp.setAccuracy(accuracyInput);
                        arTemp.setCR(crInput);
                        arTemp.setCD(cdInput);

                        arTemp.setMagSize(magSizeInput);
                        arTemp.setReloadSpeed(reloadSpeedInput);
                        arTemp.setBulletSpeed(bulletSpeedInput);
                        arTemp.setFireRate(fireRateInput);

                        arTemp.setIndex(++ars);
                        //ar.push_back(arTemp);
                        ar.insert(ar.begin(), 1, arTemp);
                    }

                    // Sniper
                    else if (creatorWarp == 5) {
                        cout << "Input Scope Size: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        sniperTemp.setScopeSize(tempInt);

                        sniperTemp.setName(nameInput);
                        sniperTemp.setDamage(damageInput);
                        sniperTemp.setAccuracy(accuracyInput);
                        sniperTemp.setCR(crInput);
                        sniperTemp.setCD(cdInput);

                        sniperTemp.setMagSize(magSizeInput);
                        sniperTemp.setReloadSpeed(reloadSpeedInput);
                        sniperTemp.setBulletSpeed(bulletSpeedInput);
                        sniperTemp.setFireRate(fireRateInput);

                        sniperTemp.setIndex(++snipers);
                        //sniper.push_back(sniperTemp);
                        sniper.insert(sniper.begin(), 1, sniperTemp);
                    }

                    // MG
                    else if (creatorWarp == 6) {
                        cout << "Input Max Recoil: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        mgTemp.setMaxRecoil(tempInt);

                        cout << "Input Recoil Gain / Round: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        mgTemp.setRecoilGain(tempInt);

                        cout << "Input Effective Range: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        mgTemp.setEffectiveRange(tempInt);

                        mgTemp.setName(nameInput);
                        mgTemp.setDamage(damageInput);
                        mgTemp.setAccuracy(accuracyInput);
                        mgTemp.setCR(crInput);
                        mgTemp.setCD(cdInput);

                        mgTemp.setMagSize(magSizeInput);
                        mgTemp.setReloadSpeed(reloadSpeedInput);
                        mgTemp.setBulletSpeed(bulletSpeedInput);
                        mgTemp.setFireRate(fireRateInput);

                        mgTemp.setIndex(++mgs);
                        //mg.push_back(mgTemp);
                        mg.insert(mg.begin(), 1, mgTemp);
                    }

                    // Explosive
                    else if (creatorWarp == 7) {
                        cout << "Input Explosive Radius: ";
                        cin >> tempInt;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        explosiveTemp.setExplosiveRadius(tempInt);

                        explosiveTemp.setName(nameInput);
                        explosiveTemp.setDamage(damageInput);
                        explosiveTemp.setAccuracy(accuracyInput);
                        explosiveTemp.setCR(crInput);
                        explosiveTemp.setCD(cdInput);

                        explosiveTemp.setMagSize(magSizeInput);
                        explosiveTemp.setReloadSpeed(reloadSpeedInput);
                        explosiveTemp.setBulletSpeed(bulletSpeedInput);
                        explosiveTemp.setFireRate(fireRateInput);

                        explosiveTemp.setIndex(++explosives);
                        //explosive.push_back(explosiveTemp);
                        explosive.insert(explosive.begin(), 1, explosiveTemp);
                    }

                    // Melee
                    else if (creatorWarp == 8) {
                        meleeTemp.setName(nameInput);
                        meleeTemp.setDamage(damageInput);
                        meleeTemp.setAccuracy(accuracyInput);
                        meleeTemp.setCR(crInput);
                        meleeTemp.setCD(cdInput);

                        meleeTemp.setIndex(++melees);
                        //melee.push_back(meleeTemp);
                        melee.insert(melee.begin(), 1, meleeTemp);
                    }

                    // After creating a weapon
                    functions.bubbleSort(4, pistol, shotgun, smg, ar, sniper, mg, explosive, melee);
                    functions.fileUpdate(pistol, shotgun, smg, ar, sniper, mg, explosive, melee);
                    functions.bubbleSort((sortMode + 2) % 4 + 1, pistol, shotgun, smg, ar, sniper, mg, explosive, melee);
                    totalWeapons++;

                    utility.logo();

                    cout << "Weapon successfully created, do you want to create another one?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n\n";

                    do
                    {
                        cout << "Your choice: ";
                        cin >> yesnoWarp;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    while (yesnoWarp != 1 && yesnoWarp != 2);

                    if (yesnoWarp == 2)
                        creatorWarp = 9;
                }
            }
            while (creatorWarp != 9);
        }

        // Test Weapon
        else if (mainWarp == 3) {
            if (totalWeapons == 0) {
                cout << "You don't have a weapon yet!";
                cin.get();

                continue;
            }

            battlefield.updateWeaponData();
            battlefield.initializeArena();
            battlefield.pickWeapon(totalWeapons);
            battlefield.reset();

            do
            {
                do
                {
                    system("cls");
                    battlefield.battleUI();

                    cout << "1. Attack\n";
                    cout << "2. Move\n";
                    cout << "3. Reload\n";
                    cout << "4. Change Weapon\n";
                    cout << "5. View Weapon Detail\n";
                    cout << "6. Exit\n";

                    cout << "Your choice: ";
                    cin >> arenaWarp;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                while (arenaWarp < 1 || arenaWarp > 6);

                if (arenaWarp == 1)
                    battlefield.attack();
                else if (arenaWarp == 2)
                    battlefield.move();
                else if (arenaWarp == 3)
                    battlefield.reload();
                else if (arenaWarp == 4)
                    battlefield.changeWeapon();
                else if (arenaWarp == 5)
                    battlefield.statsDisplayOnBattlefield(displayType);

                // Checks when all the bot already dead
                if (battlefield.checkAllDeath()) {
                    battlefield.statsDisplay();

                    break;
                }
            }
            while (arenaWarp != 6);
        }

        // Destroy Weapon
        else if (mainWarp == 4) {
            utility.logo();
            utility.subtitile("Destroy Weapon");

            cout << "Input weapon name: ";
            cin >> destroyWeaponInput;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            index = -1;

            // Pistol
            for (int i = 0; i < pistols; i++) {
                if (destroyWeaponInput == pistol[i].getName()) {
                    index = i;
                    destroyCategory = "pistol";

                    break;
                }
            }

            // Shotgun
            for (int i = 0; i < shotguns; i++) {
                if (destroyWeaponInput == shotgun[i].getName()) {
                    index = i;
                    destroyCategory = "shotgun";

                    break;
                }
            }

            // SMG
            for (int i = 0; i < smgs; i++) {
                if (destroyWeaponInput == smg[i].getName()) {
                    index = i;
                    destroyCategory = "smg";

                    break;
                }
            }

            // AR
            for (int i = 0; i < ars; i++) {
                if (destroyWeaponInput == ar[i].getName()) {
                    index = i;
                    destroyCategory = "ar";

                    break;
                }
            }

            // Sniper
            for (int i = 0; i < snipers; i++) {
                if (destroyWeaponInput == sniper[i].getName()) {
                    index = i;
                    destroyCategory = "sniper";

                    break;
                }
            }

            // MG
            for (int i = 0; i < mgs; i++) {
                if (destroyWeaponInput == mg[i].getName()) {
                    index = i;
                    destroyCategory = "mg";

                    break;
                }
            }

            // Explosive
            for (int i = 0; i < explosives; i++) {
                if (destroyWeaponInput == explosive[i].getName()) {
                    index = i;
                    destroyCategory = "explosive";

                    break;
                }
            }
            // Melee
            for (int i = 0; i < melees; i++) {
                if (destroyWeaponInput == melee[i].getName()) {
                    index = i;
                    destroyCategory = "melee";

                    break;
                }
            }


            if (index == -1) {
                cout << "Weapon not found, press 'Enter' to continue!";
                cin.get();
            }
            else {
                if (destroyCategory == "pistol") {
                    pistol.erase(pistol.begin() + index);
                    pistols--;
                }
                else if (destroyCategory == "shotgun") {
                    shotgun.erase(shotgun.begin() + index);
                    shotguns--;
                }
                else if (destroyCategory == "smg") {
                    smg.erase(smg.begin() + index);
                    smgs--;
                }
                else if (destroyCategory == "ar") {
                    ar.erase(ar.begin() + index);
                    ars--;
                }
                else if (destroyCategory == "sniper") {
                    sniper.erase(sniper.begin() + index);
                    snipers--;
                }
                else if (destroyCategory == "mg") {
                    mg.erase(mg.begin() + index);
                    mgs--;
                }
                else if (destroyCategory == "explosive") {
                    explosive.erase(explosive.begin() + index);
                    explosives--;
                }
                else if (destroyCategory == "melee") {
                    melee.erase(melee.begin() + index);
                    melees--;
                }

                totalWeapons--;

                functions.bubbleSort(4, pistol, shotgun, smg, ar, sniper, mg, explosive, melee);
                functions.fileUpdate(pistol, shotgun, smg, ar, sniper, mg, explosive, melee);
                functions.bubbleSort((sortMode + 2) % 4 + 1, pistol, shotgun, smg, ar, sniper, mg, explosive, melee);

                cout << destroyWeaponInput << " destroyed, press 'Enter' to continue!";
                cin.get();
            }
        }

        // Settings
        else if (mainWarp == 5) {
            do
            {
                do
                {
                    utility.logo();
                    utility.subtitile("Settings");

                    if (displayType == 1)
                        cout << "Current Display: Float and Integer\n";
                    else
                        cout << "Current Display: Integer only\n";

                    if (sortMode == 1)
                        cout << "Sort: Latest to Oldest\n\n";
                    else if (sortMode == 2)
                        cout << "Sort: Alphabetical Ascending Order\n\n";
                    else if (sortMode == 3)
                        cout << "Sort: Alphabetical Descending Order\n\n";
                    else if (sortMode == 4)
                        cout << "Sort: Oldest to Latest\n\n";

                    if (displayType == 1)
                        cout << "1. Display only integers\n";
                    else
                        cout << "1. Allow float display\n";

                    if (sortMode == 1)
                        cout << "2. Sort Alphabetical Ascending Order\n";
                    else if (sortMode == 2)
                        cout << "2. Sort Alphabetical Descending Order\n";
                    else if (sortMode == 3)
                        cout << "2. Sort Based on Oldest Time Created\n";
                    else if (sortMode == 4)
                        cout << "2. Sort Based on Newest Time Created\n";

                    cout << "3. Main Menu\n\n";

                    cout << "Your choice: ";
                    cin >> settingsWarp;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                while (settingsWarp < 1 || settingsWarp > 3);

                // Display Type
                if (settingsWarp == 1) {
                    displayType %= 2;
                    displayType++;
                }

                // Sort
                else if (settingsWarp == 2) {
                    functions.bubbleSort(sortMode, pistol, shotgun, smg, ar, sniper, mg, explosive, melee);

                    sortMode %= 4;
                    sortMode++;
                }
            }
            while (settingsWarp != 3);
        }
    }
    while (mainWarp != 6);

    return 0;
}
