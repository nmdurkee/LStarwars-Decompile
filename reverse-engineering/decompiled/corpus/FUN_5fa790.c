/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5fa790; label: FUN_005fa790
 */

undefined4 FUN_005fa790(int *param_1,int *param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  int in_EDX;
  int unaff_EDI;
  
  do {
    do {
      pbVar1 = (byte *)(*param_2 * *(int *)(unaff_EDI + 4) + *(int *)(unaff_EDI + 0x10) + *param_1);
      iVar2 = 0;
      if (in_EDX < 1) {
        return 1;
      }
      while (*pbVar1 == param_3) {
        iVar2 = iVar2 + 1;
        pbVar1 = pbVar1 + *(int *)(unaff_EDI + 4);
        if (in_EDX <= iVar2) {
          return 1;
        }
      }
      iVar2 = *param_1;
      *param_1 = iVar2 + 1;
    } while (iVar2 + 1 < *(int *)(unaff_EDI + 4));
    *param_1 = 0;
    *param_2 = *param_2 + in_EDX;
  } while (*param_2 + in_EDX < *(int *)(unaff_EDI + 8));
  return 0;
}

