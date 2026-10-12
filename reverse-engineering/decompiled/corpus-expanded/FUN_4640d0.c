/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x4640d0; label: FUN_004640d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004640d0(int param_1,int param_2,float param_3)

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

