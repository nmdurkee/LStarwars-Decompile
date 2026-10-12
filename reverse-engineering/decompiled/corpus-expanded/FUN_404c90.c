/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x404c90; label: FUN_00404c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00404c90(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0xaf) & 1) != 0)) {
    if (*(float *)(param_1 + 0xb0) < 0.2) {
      *(float *)(param_1 + 0xb0) = *(float *)(param_1 + 0xb0) + _DAT_00925018;
      return;
    }
    *(byte *)(param_1 + 0xaf) = *(byte *)(param_1 + 0xaf) & 0xfe;
    *(undefined4 *)(param_1 + 0xa0) = DAT_0093b0cc;
    *(undefined4 *)(param_1 + 0xa4) = DAT_0093b0d0;
    uVar1 = DAT_0093b0d4;
    *(undefined4 *)(param_1 + 0xb0) = 0;
    *(undefined4 *)(param_1 + 0xa8) = uVar1;
  }
  return;
}

