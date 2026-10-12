/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4ab8a0; label: FUN_004ab8a0
 */

void FUN_004ab8a0(int param_1,int param_2)

{
  float fVar1;
  
  fVar1 = (float)(&DAT_0087b8ec)[param_2];
  *(undefined2 *)(param_1 + 0x3a) = 1;
  if (0.0 <= fVar1) {
    *(undefined2 *)(param_1 + 0x42) = 0x4f;
  }
  else {
    *(undefined2 *)(param_1 + 0x42) = 0x26;
  }
  *(undefined4 *)(param_1 + 0x10) = (&DAT_007fc198)[param_2];
  *(undefined4 *)(param_1 + 0x14) = (&DAT_007fc198)[param_2];
  *(float *)(param_1 + 0x44) = ABS(fVar1);
  return;
}

