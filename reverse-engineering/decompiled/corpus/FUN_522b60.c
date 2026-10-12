/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x522b60; label: FUN_00522b60
 */

int FUN_00522b60(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_14;
  undefined1 local_c [12];
  
  local_14 = 3.4028235e+38;
  iVar3 = 0;
  iVar4 = 0;
  iVar1 = FUN_004f1440(DAT_009238e4 + 0x4874);
  if (iVar1 != 0) {
    do {
      if ((iVar1 != param_3) && (iVar2 = FUN_00522a00(param_2), iVar2 != 0)) {
        fVar5 = (float10)FUN_005b3cf0(DAT_009238e4 + 0x10,iVar2 + 0x18,local_c);
        if ((float)fVar5 < local_14) {
          iVar3 = iVar1;
          iVar4 = iVar2;
          local_14 = (float)fVar5;
        }
      }
      iVar1 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar1);
    } while (iVar1 != 0);
    if ((iVar4 != 0) && (iVar3 != 0)) {
      if (param_1 != (int *)0x0) {
        *param_1 = iVar3;
      }
      return iVar4;
    }
  }
  return 0;
}

