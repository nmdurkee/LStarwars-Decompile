/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69b550; label: FUN_0069b550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0069b550(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int *unaff_ESI;
  int *unaff_EDI;
  
  uVar1 = FUN_0069ed70();
  *unaff_ESI = *unaff_ESI + 1;
  if (unaff_EDI != (int *)0x0) {
    pvVar2 = _realloc((void *)*unaff_EDI,*unaff_ESI * 4);
    *unaff_EDI = (int)pvVar2;
    *(undefined4 *)(*unaff_EDI + -4 + *unaff_ESI * 4) = uVar1;
    return;
  }
  pvRam00000000 = _malloc(4);
  *(undefined4 *)((int)pvRam00000000 + *unaff_ESI * 4 + -4) = uVar1;
  return;
}

