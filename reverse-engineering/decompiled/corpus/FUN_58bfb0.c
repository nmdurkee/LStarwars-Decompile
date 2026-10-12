/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58bfb0; label: FUN_0058bfb0
 */

void FUN_0058bfb0(int param_1,int param_2)

{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != 0)) && (*(int *)(param_2 + 0x54) != 0)) {
    iVar1 = (int)*(char *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0x10e);
    if (iVar1 != -1) {
      FUN_0058bee0(param_1,iVar1 * 0x40 + 0x834 + param_2,2,0x3f800000,0,0);
      return;
    }
    FUN_0058bee0(param_1,param_2 + 0x80,2,0x3f800000,0,0);
  }
  return;
}

