/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x575200; label: FUN_00575200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00575200(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_0055f460(*(undefined4 *)(param_1 + 0x510));
    uVar2 = FUN_0057c970(*(undefined4 *)(iVar1 + 0x2ab0));
    *(undefined4 *)(DAT_00951398 + 0x120) = uVar2;
  }
  return;
}

