/* Ghidra pseudocode, not original source.
 * ev_63eb9bd68174043ae1497f20c7ab174ab5c86e6d078dec24e1a9d3709ec9fcaa
 * Entry: 0x5fa720; label: FUN_005fa720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005fa720(int *param_1,int *param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  int in_EDX;
  int unaff_EDI;
  
  do {
    do {
      pbVar1 = (byte *)(*param_2 * *(int *)(unaff_EDI + 4) + *(int *)(unaff_EDI + 0x10) + *param_1);
      iVar2 = 0;
      if (0 < in_EDX) {
        do {
          if (*pbVar1 != param_3) {
            return 1;
          }
          iVar2 = iVar2 + 1;
          pbVar1 = pbVar1 + *(int *)(unaff_EDI + 4);
        } while (iVar2 < in_EDX);
      }
      iVar2 = *param_1;
      *param_1 = iVar2 + 1;
    } while (iVar2 + 1 < *(int *)(unaff_EDI + 4));
    *param_1 = 0;
    *param_2 = *param_2 + in_EDX;
  } while (*param_2 + in_EDX < *(int *)(unaff_EDI + 8));
  return 0;
}

