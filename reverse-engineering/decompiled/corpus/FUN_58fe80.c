/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x58fe80; label: FUN_0058fe80
 */

float10 FUN_0058fe80(uint param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
    iVar2 = FUN_0055f210(param_1);
    if (iVar2 != 0) {
      return (float10)3.0;
    }
  }
  piVar1 = (int *)(param_1 + 0x798);
  param_1 = (uint)*(byte *)(param_1 + 0x7b4);
  uVar3 = (uint)*(byte *)(*piVar1 + 0x6c);
  iVar2 = *(byte *)(*piVar1 + 0x6f) - param_1;
  if ((int)(uVar3 + iVar2) / 2 <= (int)(iVar2 + param_1)) {
    param_1 = (uVar3 - iVar2) - param_1;
  }
  if ((int)param_1 < 0xb) {
    if ((int)param_1 < 0) {
      param_1 = 0;
    }
  }
  else {
    param_1 = 10;
  }
  return (float10)((float)(int)param_1 / 10.0 + 1.0);
}

