/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x45e140; label: FUN_0045e140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0045e140(int param_1,int param_2,float param_3)

{
  if (-1 < *(int *)(param_1 + 0x14)) {
    *(float *)(param_1 + 0x18) = param_3 + *(float *)(param_1 + 0x18);
  }
  if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) !=
      (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18))) {
    FUN_004838f0(param_2);
    if ((int)*(char *)(param_2 + 0xb8) < (int)(*(byte *)(param_2 + 0xb7) - 1)) {
      *(undefined4 *)(param_1 + 0x1c) = 0x3dcccccd;
      return;
    }
    FUN_00486940(*(undefined1 *)(param_2 + 0xba));
  }
  return;
}

