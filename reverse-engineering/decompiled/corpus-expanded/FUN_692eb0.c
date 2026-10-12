/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x692eb0; label: FUN_00692eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00692eb0(int param_1)

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
  DAT_02921830 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,FUN_0066ac90,"Data Menu");
  if (DAT_02921830 == 0) {
    return;
  }
  uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0068cc30,"Type Name...");
  FUN_00618e10(DAT_02921830,uVar1);
  if (DAT_00810ad8 != -1) {
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0068cee0,"Delete Effect");
    FUN_00618e10(DAT_02921830,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,&LAB_006626e0,"Copy Effect");
    FUN_00618e10(DAT_02921830,uVar1);
  }
  if (DAT_0292118b == '\0') {
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_00669dd0,"Save General list");
  }
  else if (DAT_0292118b == '\x01') {
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_00669dd0,"Save Level list");
  }
  else {
    if (DAT_0292118b != '\x05') goto LAB_0069300e;
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_00669dd0,"Save Char list");
  }
  FUN_00618e10(DAT_02921830,uVar1);
LAB_0069300e:
  uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_00692ba0,"Load all from file");
  FUN_00618e10(DAT_02921830,uVar1);
  if (DAT_00810ad8 != -1) {
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0068eb60,"Clipboard...");
    FUN_00618e10(DAT_02921830,uVar1);
  }
  if (DAT_02962a3c != 0) {
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_00664850,"List Orphans...");
    FUN_00618e10(DAT_02921830,uVar1);
    uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0068cd30,"Delete Orphans");
    FUN_00618e10(DAT_02921830,uVar1);
  }
  uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0068d3d0,"Quick Delete Types...");
  FUN_00618e10(DAT_02921830,uVar1);
  uVar1 = FUN_00627a80(1,&local_10,0,0,FUN_0066ab80,"Info Box Style...");
  FUN_00618e10(DAT_02921830,uVar1);
  uVar1 = FUN_00627bc0(1,&local_10,DAT_02962a40,2,FUN_0066ac70,"Show All Placed");
  FUN_00618e10(DAT_02921830,uVar1);
  FUN_006279b0(param_1,DAT_02921830);
  *(int *)(DAT_02921830 + 0x14) = *(int *)(param_1 + 0x14) + 10;
  *(int *)(DAT_02921830 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  return;
}

