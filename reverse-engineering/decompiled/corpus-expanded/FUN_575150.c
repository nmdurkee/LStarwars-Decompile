/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x575150; label: FUN_00575150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00575150(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = FUN_004f9e70(param_1);
  if (uVar1 < 0x40) {
    *(char *)(DAT_00951398 + 0xf4) = (char)uVar1;
  }
  return;
}

