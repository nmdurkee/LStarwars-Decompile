/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x668a30; label: FUN_00668a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00668a30(int param_1)

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
  DAT_0292fe14 = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,FUN_00668a10,"Super Scale");
  if (DAT_0292fe14 != 0) {
    uVar1 = FUN_00625240(0,&local_10,0,FUN_006689f0,1,99,DAT_00810ae8,"Super Scale");
    FUN_00618e10(DAT_0292fe14,uVar1);
    FUN_006279b0(param_1,DAT_0292fe14);
    *(int *)(DAT_0292fe14 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_0292fe14 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

