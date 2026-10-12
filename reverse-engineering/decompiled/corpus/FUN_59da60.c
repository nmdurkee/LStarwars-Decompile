/* Ghidra analysis pseudocode, not original source.
 * ev_0d1e553906e4ac29f0c898728bb3c9cf38177ab98ca2cbcdea8e6b852723dd83
 * Entry: 0x59da60; label: FUN_0059da60
 */

void FUN_0059da60(undefined4 *param_1,int param_2,int param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  
  if ((param_3 != param_2) && (*(byte *)(param_3 + 9) != param_4)) {
    *(char *)(param_3 + 9) = (char)param_4;
    if ((*(char *)(param_3 + 3) == '\0') &&
       ((((*(ushort *)(param_3 + 10) & 0x1000) == 0 &&
         (piVar1 = *(int **)(param_3 + 0xc), piVar1 != (int *)0x0)) && (iVar2 = 0, 0 < *piVar1)))) {
      do {
        FUN_0055a250(*param_1,**(undefined4 **)(piVar1[2] + iVar2 * 4),0,1);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *piVar1);
    }
    iVar2 = 0;
    if (*(char *)(param_3 + 2) != '\0') {
      do {
        FUN_0059da60(param_1,param_2,*(undefined4 *)(*(int *)(param_3 + 0x14) + iVar2 * 4),param_4);
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)*(byte *)(param_3 + 2));
    }
  }
  return;
}

