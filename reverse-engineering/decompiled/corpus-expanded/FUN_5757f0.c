/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x5757f0; label: FUN_005757f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005757f0(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x120) != 0) {
    iVar1 = FUN_0057cdd0(*(int *)(unaff_ESI + 0x120));
    if (iVar1 == 0) {
      return *(undefined4 *)(unaff_ESI + 0x120);
    }
  }
  DAT_00951384 = 0;
  return 0;
}

