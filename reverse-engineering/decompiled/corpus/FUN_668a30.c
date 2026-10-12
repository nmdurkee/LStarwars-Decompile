/* Ghidra analysis pseudocode, not original source.
 * ev_b1d683d72d7bcdb306124a83b006db4b41bf581671bc5ef620d768a8a4b84d3d
 * Entry: 0x668a30; label: FUN_00668a30
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
  DAT_0292fe14 = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,&LAB_00668a10,"Super Scale");
  if (DAT_0292fe14 != 0) {
    uVar1 = FUN_00625240(0,&local_10,0,&LAB_006689f0,1,99,DAT_00810ae8,"Super Scale");
    FUN_00618e10(DAT_0292fe14,uVar1);
    FUN_006279b0(param_1,DAT_0292fe14);
    *(int *)(DAT_0292fe14 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_0292fe14 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

