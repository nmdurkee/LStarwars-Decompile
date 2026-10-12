/* Ghidra pseudocode, not original source.
 * ev_6614b6c0ec400e98b17ca3318749993ac398f4a5e7c651bffc9aeb30b42772d2
 * Entry: 0x5097d0; label: FUN_005097d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005097d0(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 0x14);
  if (sVar1 != -1) {
    if (*(short *)(&DAT_00800abc + sVar1 * 0x1c) != -1) {
      *(undefined2 *)(&DAT_00800abc + sVar1 * 0x1c) = *(undefined2 *)(param_1 + 8);
    }
    if (*(short *)(&DAT_00800abe + *(short *)(param_1 + 0x14) * 0x1c) != -1) {
      *(undefined2 *)(&DAT_00800abe + *(short *)(param_1 + 0x14) * 0x1c) =
           *(undefined2 *)(param_1 + 10);
    }
  }
  return;
}

