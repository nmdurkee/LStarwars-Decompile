/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69bff0; label: FUN_0069bff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069bff0(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (3 < *(int *)(unaff_ESI + 0x58)) {
    return 0;
  }
  if (*(int *)(unaff_ESI + 0x58) < 3) {
    return 0xffffff7f;
  }
  if (*(int *)(unaff_ESI + 4) == 0) {
    iVar1 = *(int *)(unaff_ESI + 0x48);
  }
  else {
    iVar1 = *(int *)(unaff_ESI + 0x60) * 0x20 + *(int *)(unaff_ESI + 0x48);
  }
  iVar1 = FUN_006a2380(unaff_ESI + 0x1e0,iVar1);
  if (iVar1 != 0) {
    return 0xffffff77;
  }
  FUN_006a14d0(unaff_ESI + 0x1e0,unaff_ESI + 0x250);
  *(undefined8 *)(unaff_ESI + 0x68) = 0;
  *(undefined8 *)(unaff_ESI + 0x70) = 0;
  *(undefined4 *)(unaff_ESI + 0x58) = 4;
  return 0;
}

