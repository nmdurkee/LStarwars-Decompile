/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58e040; label: FUN_0058e040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058e040(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x790);
  if (iVar1 != 0) {
    if (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar1 + 0x7b5) * 0x10 + 8) & 0x4000000) != 0) ||
       (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar1 + 0x7b5) * 0x10 + 8) & 0x8000000) != 0 &&
        ((*(uint *)(iVar1 + 0x7bc) & 0x20000) != 0)))) {
      uVar2 = FUN_00547820(iVar1,0);
      FUN_00547930(0x3f,param_1 + 0x80,uVar2);
    }
  }
  return;
}

