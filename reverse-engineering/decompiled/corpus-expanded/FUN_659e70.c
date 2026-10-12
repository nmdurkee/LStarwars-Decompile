/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x659e70; label: FUN_00659e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00659e70(int param_1)

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
  DAT_029620ec = FUN_00619250(0x46,0x46,0xfa,200,DAT_02912e80,FUN_00659e50,"Switch Type");
  if (DAT_029620ec != 0) {
    uVar1 = FUN_00627b80(0,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 0,1,FUN_00659d80,
                         &DAT_00763b90);
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(1,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 1,1,FUN_00659d80,
                         "Switch");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(2,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 2,1,FUN_00659d80,
                         "Switch One Cycle");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(3,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 3,1,FUN_00659d80,
                         "Switch Continuous");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(4,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 4,1,FUN_00659d80,
                         "Proximity");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(5,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 5,1,FUN_00659d80,
                         "Proximity One Cycle");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(6,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 6,1,FUN_00659d80,
                         "Proximity Continuous");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(7,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 7,1,FUN_00659d80,
                         "Terrain");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(8,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 8,1,FUN_00659d80,
                         "Terrain One Cycle");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(9,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 9,1,FUN_00659d80,
                         "Terrain Continuous");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(10,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 10,1,FUN_00659d80,
                         "Override NoAnim");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(0xb,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 0xb,1,FUN_00659d80,
                         "Override Play");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    uVar1 = FUN_00627b80(0xc,&local_10,(&DAT_0292fe24)[DAT_02962010 * 0xb5] == 0xc,1,FUN_00659d80,
                         "Override PlayCont");
    FUN_00618e10(DAT_029620ec,uVar1);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_029620ec + 8) = DAT_02900c84;
    }
    FUN_006279b0(param_1,DAT_029620ec);
    *(int *)(DAT_029620ec + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029620ec + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

