/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69b5e0; label: FUN_0069b5e0
 */

undefined4 FUN_0069b5e0(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *piVar5;
  int *unaff_EDI;
  longlong lVar6;
  undefined1 local_10 [16];
  
  *param_2 = 0;
  *unaff_EDI = 0;
  lVar6 = FUN_0069b340(local_10,0x10000,0);
  while( true ) {
    if (lVar6 == -2) {
      return 0;
    }
    if (lVar6 < 0) break;
    iVar1 = FUN_0069ecc0(local_10);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = *unaff_EDI;
    piVar5 = (int *)*param_2;
    iVar2 = FUN_0069ed70(local_10);
    if (piVar5 != (int *)0x0) {
      while (iVar1 != 0) {
        iVar1 = iVar1 + -1;
        if (*piVar5 == iVar2) {
          if ((void *)*param_2 != (void *)0x0) {
            _free((void *)*param_2);
          }
          *param_2 = 0;
          *unaff_EDI = 0;
          return 0xffffff7b;
        }
        piVar5 = piVar5 + 1;
      }
    }
    uVar3 = FUN_0069ed70(local_10);
    *unaff_EDI = *unaff_EDI + 1;
    pvVar4 = _realloc((void *)*param_2,*unaff_EDI * 4);
    *param_2 = (int)pvVar4;
    *(undefined4 *)((int)pvVar4 + *unaff_EDI * 4 + -4) = uVar3;
    lVar6 = FUN_0069b340(local_10,0x10000,0);
  }
  return (int)lVar6;
}

