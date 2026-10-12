/* Ghidra analysis pseudocode, not original source.
 * ev_0d1e553906e4ac29f0c898728bb3c9cf38177ab98ca2cbcdea8e6b852723dd83
 * Entry: 0x59df70; label: FUN_0059df70
 */

void FUN_0059df70(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  byte *unaff_ESI;
  int iVar3;
  
  if ((*unaff_ESI != 0) && (iVar3 = 0, *unaff_ESI != 0)) {
    do {
      iVar2 = *(int *)(*(int *)(unaff_ESI + 0x10) + iVar3 * 4);
      iVar2 = (*(code *)(&PTR_LAB_0080551c)[(uint)*(byte *)(iVar2 + 3) * 3])
                        (param_1,iVar2,**(undefined1 **)(unaff_ESI + 0x18));
      if (iVar2 == 0) {
        piVar1 = *(int **)(unaff_ESI + 0xc);
        iVar3 = 0;
        if (*piVar1 < 1) {
          return;
        }
        do {
          FUN_0055b0e0(*param_1,**(undefined4 **)(piVar1[2] + iVar3 * 4),1,unaff_ESI[10] >> 7,1);
          iVar3 = iVar3 + 1;
        } while (iVar3 < *piVar1);
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(uint)*unaff_ESI);
  }
  piVar1 = *(int **)(unaff_ESI + 0xc);
  iVar3 = 0;
  if (0 < *piVar1) {
    do {
      FUN_0055b0e0(*param_1,**(undefined4 **)(piVar1[2] + iVar3 * 4),0,unaff_ESI[10] >> 7,1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *piVar1);
  }
  return;
}

