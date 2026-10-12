/* Ghidra pseudocode, not original source.
 * ev_36c567c8b03fa9be6305a90618e5976b2395159d59c428aaf9f1abc99d465ca0
 * Entry: 0x65b2f0; label: FUN_0065b2f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065b2f0(int param_1)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  DAT_02962104 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,&LAB_0065b2d0,"Memory Card Test Menu"
                             );
  if (DAT_02962104 != 0) {
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065af60,"Card Present Test");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065afa0,"Card Type Test");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065afe0,"Card Format Test");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065b020,"Card Free Space");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065b070,"Card Slots Used");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,0,FUN_0065b0c0,"Card Save Slot 0");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,0,FUN_0065b130,"Card Load Slot 0");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(0,&local_10,0,0,FUN_0065b190,"Card Delete Slot 0");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065b0c0,"Card Save Slot 1");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065b130,"Card Load Slot 1");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065b190,"Card Delete Slot 1");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065b210,"Format Card");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065b1d0,"Unformat Card");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0065b250,"Write KeyCard");
    FUN_00618e10(DAT_02962104,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,&LAB_0065b290,"Check KeyCard");
    FUN_00618e10(DAT_02962104,uVar1);
    FUN_006279b0(param_1,DAT_02962104);
    *(int *)(DAT_02962104 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02962104 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

