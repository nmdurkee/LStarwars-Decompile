/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53dc80; label: FUN_0053dc80
 */

float10 FUN_0053dc80(short *param_1,int param_2)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  undefined1 local_c [12];
  
  psVar1 = param_1;
  if ((param_1 != (short *)0x0) && (1 < *param_1)) {
    iVar4 = (int)*param_1;
    if (param_2 == 0) {
      iVar4 = iVar4 + -1;
    }
    iVar3 = *(int *)(param_1 + 4);
    iVar5 = 0;
    param_1 = (short *)0x0;
    if (0 < iVar4) {
      do {
        if (iVar5 == *psVar1 + -1) {
          iVar2 = 0;
        }
        else {
          iVar2 = iVar5 + 1;
        }
        iVar2 = *(int *)(psVar1 + 4) + iVar2 * 0xc;
        FUN_005b3800(local_c,iVar2,iVar3);
        fVar6 = (float10)FUN_005bec80(local_c);
        iVar5 = iVar5 + 1;
        param_1 = (short *)(float)(fVar6 + (float10)(float)param_1);
        iVar3 = iVar2;
      } while (iVar5 < iVar4);
    }
    return (float10)(float)param_1;
  }
  return (float10)0;
}

