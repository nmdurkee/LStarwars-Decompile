/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b6520; label: FUN_004b6520
 */

void FUN_004b6520(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(param_1 + 0xca4) + 8);
  uVar1 = uVar2 & DAT_00802280;
  uVar2 = uVar2 & DAT_0080227c;
  FUN_0058d8b0(param_1);
  FUN_00427b40(param_1);
  if (*(undefined1 **)(param_1 + 0xcc4) != (undefined1 *)0x0) {
    **(undefined1 **)(param_1 + 0xcc4) = 0;
  }
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    FUN_004abac0(param_1,0,0,0,0);
    FUN_0049c080(param_1);
    FUN_0049be00(param_1);
    FUN_004a7610(param_1);
    FUN_004a3be0();
    FUN_004a4a20(param_1);
    FUN_0056d8c0(param_1,PTR_DAT_00802c54);
    FUN_004b0c80();
    FUN_004b3d40(param_1,uVar2,uVar1,0,0,0);
    FUN_004aad70();
    FUN_004aaec0();
    FUN_004a7d00();
    FUN_004a8640(uVar1);
    FUN_0056a5b0(PTR_DAT_00802c54,param_1);
  }
  return;
}

