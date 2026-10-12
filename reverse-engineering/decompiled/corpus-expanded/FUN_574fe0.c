/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x574fe0; label: FUN_00574fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00574fe0(int param_1)

{
  int iVar1;
  int local_4;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    FUN_00578da0(*(undefined4 *)(param_1 + 0x510),&local_4);
    if ((local_4 != -1) && ((*(byte *)(local_4 * 0x130 + 100 + DAT_00951b78) & 0xe0) == 0)) {
      *(short *)(DAT_00951398 + 0xf2) = (short)local_4;
    }
  }
  return;
}

