/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x521c20; label: FUN_00521c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00521c20(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int unaff_ESI;
  
  if ((in_ECX != 0) && (unaff_ESI != 0)) {
    iVar1 = 0;
    piVar2 = (int *)(in_ECX + 0x18);
    do {
      if (*piVar2 == unaff_ESI) {
        return 1;
      }
      if (*piVar2 == 0) {
        return 0;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < 0x40);
  }
  return 0;
}

