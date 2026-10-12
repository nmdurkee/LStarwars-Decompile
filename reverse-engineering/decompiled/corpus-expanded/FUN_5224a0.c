/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x5224a0; label: FUN_005224a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005224a0(void)

{
  int iVar1;
  int *piVar2;
  int in_EDX;
  int unaff_ESI;
  
  if (unaff_ESI == 0) {
    return 0;
  }
  if (in_EDX != 0) {
    iVar1 = 0;
    piVar2 = (int *)(unaff_ESI + 0x18);
    do {
      if (*piVar2 == in_EDX) {
        if (iVar1 != 0) {
          return *(undefined4 *)(unaff_ESI + 0x14 + iVar1 * 4);
        }
        break;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < 0x40);
    iVar1 = 0x3f;
    piVar2 = (int *)(unaff_ESI + 0x114);
    do {
      if (*piVar2 != 0) {
        return *(undefined4 *)(unaff_ESI + 0x18 + iVar1 * 4);
      }
      iVar1 = iVar1 + -1;
      piVar2 = piVar2 + -1;
    } while (-1 < iVar1);
  }
  return *(undefined4 *)(unaff_ESI + 0x18);
}

