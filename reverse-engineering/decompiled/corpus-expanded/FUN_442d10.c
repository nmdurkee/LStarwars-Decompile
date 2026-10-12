/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x442d10; label: FUN_00442d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

