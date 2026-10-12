/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58b210; label: FUN_0058b210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058b210(int param_1)

{
  float fVar1;
  
  if ((DAT_008028a4 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_008028a4)) {
    if (*(int *)(param_1 + 0x790) == 0) {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      return;
    }
    fVar1 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar1;
    if (fVar1 <= 0.0) {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      if ((*(char *)(param_1 + 0x7b7) != -1) &&
         ((*(byte *)(*(char *)(param_1 + 0x7b7) * 0x10 + 10 + DAT_009553dc) & 2) != 0)) {
        FUN_0058b080();
      }
    }
  }
  return;
}

