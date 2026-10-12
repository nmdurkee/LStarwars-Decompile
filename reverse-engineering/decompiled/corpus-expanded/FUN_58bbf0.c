/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58bbf0; label: FUN_0058bbf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0058bbf0(int param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if ((param_1 != 0) && (0 < *(int *)(param_1 + 4))) {
    psVar2 = (short *)(param_1 + 0x16);
    do {
      if ((*(int *)(psVar2 + 1) != 0) && (*psVar2 == param_2)) {
        return *(undefined4 *)(param_1 + 0x18 + iVar1 * 0x14);
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 10;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return 0;
}

