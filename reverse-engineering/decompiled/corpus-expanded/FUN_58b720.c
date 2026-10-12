/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58b720; label: FUN_0058b720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0058b720(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0x1fc) >> 7 & 1) == 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 0x804;
    }
    if ((*(uint *)(param_1 + 0x1f8) & 0x10001) != 0) {
      return uVar1 | 0x10;
    }
    if ((*(uint *)(param_1 + 0x1f8) & 4) != 0) {
      return uVar1 | 0x20;
    }
    uVar1 = uVar1 | 8;
  }
  return uVar1;
}

