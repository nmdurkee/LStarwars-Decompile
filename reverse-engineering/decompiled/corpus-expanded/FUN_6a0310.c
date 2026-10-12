/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x6a0310; label: FUN_006a0310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a0310(void)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int *unaff_EDI;
  
  piVar1 = (int *)unaff_EDI[7];
  if (piVar1 == (int *)0x0) {
    return 0xffffff7f;
  }
  iVar3 = FUN_006a3bb0();
  *unaff_EDI = iVar3;
  if (iVar3 != 0) {
    return 0xffffff7a;
  }
  iVar3 = FUN_006a3bb0();
  unaff_EDI[1] = iVar3;
  iVar3 = FUN_006a3bb0();
  unaff_EDI[2] = iVar3;
  iVar3 = FUN_006a3bb0();
  unaff_EDI[3] = iVar3;
  iVar3 = FUN_006a3bb0();
  unaff_EDI[4] = iVar3;
  iVar3 = FUN_006a3bb0();
  unaff_EDI[5] = iVar3;
  bVar2 = FUN_006a3bb0();
  *piVar1 = 1 << (bVar2 & 0x1f);
  bVar2 = FUN_006a3bb0();
  iVar3 = 1 << (bVar2 & 0x1f);
  piVar1[1] = iVar3;
  if ((((0 < unaff_EDI[2]) && (0 < unaff_EDI[1])) && (0x3f < *piVar1)) &&
     ((*piVar1 <= iVar3 && (iVar3 < 0x2001)))) {
    iVar3 = FUN_006a3bb0();
    if (iVar3 == 1) {
      return 0;
    }
  }
  FUN_006a0180();
  return 0xffffff7b;
}

