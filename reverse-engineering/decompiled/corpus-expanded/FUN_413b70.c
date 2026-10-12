/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x413b70; label: FUN_00413b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00413b70(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"stormtrooper");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 1;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00751e7c);
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 2;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"macewindu");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 3;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"battledroid");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 4;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"hoverdroid");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0x11;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"walker2legs");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0xf;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"walker4legs");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0x10;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"wookiee");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 5;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"obiwankenobi");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 6;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00751e20);
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 7;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"clone");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 8;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"rebel");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 9;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00751e0c);
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 10;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"lando");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0xb;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"weirdo");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00751df4);
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0xc;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"hansolo");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0xd;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"padme");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0xe;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"critter");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0x12;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"naboostarfighter");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0x13;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&PTR_FUN_00751dc4);
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0x14;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"republicgunship");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0x15;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"henchman");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x116) = 0x16;
    }
  }
  return;
}

