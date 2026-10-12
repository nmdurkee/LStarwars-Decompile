/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cd920; label: FUN_004cd920
 */

undefined4 FUN_004cd920(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x6c) == 0) {
      FUN_004ccad0(param_1);
    }
    cVar1 = *(char *)(param_1 + 0x37);
    if (cVar1 == '\x01') {
      if (((*(int *)(param_1 + 0x6c) != 0) &&
          (uVar2 = *(uint *)(*(int *)(param_1 + 0x6c) + 0x1fc), (uVar2 & 1) != 0)) &&
         ((uVar2 & 0x1000) != 0)) {
        return 1;
      }
    }
    else if (cVar1 == '\x02') {
      iVar3 = FUN_005cfd60(*(undefined4 *)(param_1 + 0x6c));
      if (iVar3 != 0) {
        return 1;
      }
    }
    else if ((cVar1 == '\x03') && (*(int *)(param_1 + 0x6c) != 0)) {
      return 1;
    }
  }
  return 0;
}

