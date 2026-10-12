/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42cf40; label: FUN_0042cf40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042cf40(int param_1,int param_2)

{
  if ((param_2 == 1) && (*(byte *)(param_1 + 0x206) != 0xff)) {
    if (((*(byte *)(param_1 + 0x206) & 1) != 0) && (DAT_0093d7f0 != 0)) {
      FUN_0054a8a0(**(undefined4 **)(DAT_0093d7f0 + 0xca4),0x3e4ccccd,0);
      FUN_0054a850(**(undefined4 **)(DAT_0093d7f0 + 0xca4),0x3f4ccccd,0);
    }
    if (((*(byte *)(param_1 + 0x206) & 2) != 0) && (DAT_0093d7f4 != 0)) {
      FUN_0054a8a0(**(undefined4 **)(DAT_0093d7f4 + 0xca4),0x3e4ccccd,0);
      FUN_0054a850(**(undefined4 **)(DAT_0093d7f4 + 0xca4),0x3f4ccccd,0);
    }
  }
  return;
}

