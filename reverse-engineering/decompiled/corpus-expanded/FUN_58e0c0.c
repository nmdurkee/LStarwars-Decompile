/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58e0c0; label: FUN_0058e0c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0058e0c0(int param_1)

{
  int iVar1;
  
  iVar1 = (int)*(char *)(param_1 + 0x7b5);
  if ((((*(uint *)(PTR_PTR_007fb0e4 + iVar1 * 0x10 + 8) & 0x10000) == 0) &&
      (((DAT_00802838 == -1 || (iVar1 != DAT_00802838)) || (*(char *)(param_1 + 0x7b8) != '\x03'))))
     && ((((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x8000) == 0 ||
          (DAT_00802844 == 0)) || (iVar1 != DAT_00802844)))) {
    return 0;
  }
  return 1;
}

