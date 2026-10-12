/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58b180; label: FUN_0058b180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058b180(int param_1)

{
  int iVar1;
  
  if ((((DAT_008028a0 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_008028a0)) &&
      (*(char *)(param_1 + 0x7b7) != -1)) ||
     ((DAT_008028a4 != -1 && (*(char *)(param_1 + 0x7b5) == DAT_008028a4)))) {
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    iVar1 = *(int *)(param_1 + 0x790);
    if ((iVar1 != 0) &&
       ((((DAT_008028a0 != -1 && (*(char *)(iVar1 + 0x7b5) == DAT_008028a0)) &&
         (*(char *)(iVar1 + 0x7b7) != -1)) ||
        ((DAT_008028a4 != -1 && (*(char *)(iVar1 + 0x7b5) == DAT_008028a4)))))) {
      *(undefined1 *)(iVar1 + 0x7b5) = 0xff;
    }
  }
  return;
}

