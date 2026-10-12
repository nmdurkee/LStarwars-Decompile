/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x522460; label: FUN_00522460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00522460(void)

{
  int iVar1;
  int *piVar2;
  int in_EDX;
  int unaff_ESI;
  
  if (in_EDX == 0) {
    return 0;
  }
  if (unaff_ESI != 0) {
    iVar1 = 0;
    piVar2 = (int *)(in_EDX + 0x1c);
    do {
      if (((piVar2[-1] == unaff_ESI) && (iVar1 + 1 < 0x40)) && (*piVar2 != 0)) {
        return *(undefined4 *)(in_EDX + 0x1c + iVar1 * 4);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < 0x40);
  }
  return *(undefined4 *)(in_EDX + 0x18);
}

