/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x595a90; label: FUN_00595a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00595a90(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_0093d500) {
    piVar1 = (int *)(DAT_0093d504 + 0xe04);
    do {
      if ((((piVar1[-0x302] & 1U) != 0) && ((piVar1[-0x302] & 0x1000U) != 0)) && (*piVar1 != -1)) {
        FUN_00635750(*piVar1);
        *piVar1 = -1;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x436;
    } while (iVar2 < DAT_0093d500);
  }
  return;
}

