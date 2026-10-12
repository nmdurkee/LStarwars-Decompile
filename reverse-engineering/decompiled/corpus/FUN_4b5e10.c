/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b5e10; label: FUN_004b5e10
 */

void FUN_004b5e10(int param_1)

{
  uint uVar1;
  
  FUN_00427b40(param_1);
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    FUN_004abac0(param_1,0,0,0x41000000,0);
    FUN_0049c080(param_1);
    FUN_0049be00(param_1);
    FUN_004a7610(param_1);
    FUN_004a3be0();
    FUN_004a4a20(param_1);
    FUN_0056d8c0(param_1,PTR_DAT_00802c54);
    FUN_004b0c80();
    FUN_0058d6a0(param_1);
    FUN_0058db50(param_1);
    FUN_0058dec0(param_1);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xca4) + 8);
    FUN_004b3d40(param_1,uVar1 & DAT_0080227c,uVar1 & DAT_00802280,1,0,0);
    FUN_004a7d00();
    FUN_004a8640(*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802280);
    FUN_0056a5b0(PTR_DAT_00802c54,param_1);
  }
  return;
}

