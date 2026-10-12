/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4ab8a0; label: FUN_004ab8a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

