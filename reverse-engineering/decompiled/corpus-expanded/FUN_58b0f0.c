/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58b0f0; label: FUN_0058b0f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0058b0f0(int param_1)

{
  char cVar1;
  
  if (((((DAT_008028a0 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_008028a0)) &&
       (cVar1 = *(char *)(param_1 + 0x7b7), cVar1 != -1)) &&
      ((*(int *)(param_1 + 0x790) != 0 && (DAT_008028a4 != -1)))) &&
     (*(char *)(*(int *)(param_1 + 0x790) + 0x7b5) == DAT_008028a4)) {
    if ((cVar1 != -1) && ((*(byte *)(cVar1 * 0x10 + 10 + DAT_009553dc) & 4) != 0)) {
      FUN_0058b080();
    }
    if (*(int *)(param_1 + 0x790) != 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x790) + 0x7b5) = 0xff;
    }
    return 1;
  }
  return 0;
}

