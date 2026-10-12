/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54ba80; label: FUN_0054ba80
 */

void FUN_0054ba80(int param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_1;
  
  local_1 = 0x2c;
  if (DAT_0080235c == 2) {
    local_1 = 0x20;
  }
  else if (((DAT_0080235c != 1) && (DAT_0080235c != 0x12)) && (DAT_0080235c != 0)) {
    local_1 = 0x2e;
  }
  if (param_3 < 0) {
    param_3 = FUN_004f1ff0(param_1);
  }
  iVar1 = 0;
  iVar4 = 0;
  iVar3 = param_3;
  if (param_3 < 1) {
    *param_2 = 0;
    return;
  }
  do {
    iVar3 = iVar3 + -1;
    param_2[iVar1] = *(undefined1 *)(iVar4 + param_1);
    iVar2 = iVar1 + 1;
    if ((iVar3 != 0) && (iVar3 == (iVar3 / 3) * 3)) {
      param_2[iVar2] = local_1;
      iVar2 = iVar1 + 2;
    }
    iVar4 = iVar4 + 1;
    iVar1 = iVar2;
  } while (iVar4 < param_3);
  param_2[iVar2] = 0;
  return;
}

