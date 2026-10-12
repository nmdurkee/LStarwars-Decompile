/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x5097d0; label: FUN_005097d0
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

