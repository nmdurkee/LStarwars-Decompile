/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58e040; label: FUN_0058e040
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

