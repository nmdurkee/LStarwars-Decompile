/* Ghidra pseudocode, not original source.
 * ev_d6810b63b1adbb1cff68d70c4de6dcedf5c7ec9f8161f7a4b49c43fe0c68c9ee
 * Entry: 0x7415c0; label: FUN_007415c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007415c0(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(DAT_0297cc6c + 4);
  iVar2 = 400;
  do {
    if (-1 < *piVar1) {
      FUN_00744010(piVar1);
    }
    piVar1 = piVar1 + 0x136;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

