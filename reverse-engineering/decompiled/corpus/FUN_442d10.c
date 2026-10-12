/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x442d10; label: FUN_00442d10
 */

float10 FUN_00442d10(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (((*(int *)(PTR_DAT_00802c54 + 0x4678) != 0) && (param_3 != 0)) &&
     (*(int *)(param_3 + 0xd0) != 0)) {
    uVar2 = (uint)*(byte *)(*(int *)(param_3 + 0xd0) + 0x28d);
    iVar1 = *(int *)(PTR_DAT_00802c54 + 0x4678);
    if ((*(char *)(uVar2 + 0x42c0 + iVar1) != -1) &&
       (*(short *)(*(char *)(iVar1 + 0x4280 + uVar2) * 0x214 + 0x20e + iVar1) != 0)) {
      return (float10)1;
    }
  }
  return (float10)0;
}

