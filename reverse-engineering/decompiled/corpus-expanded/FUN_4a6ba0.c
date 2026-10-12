/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a6ba0; label: FUN_004a6ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a6ba0(int param_1,float *param_2)

{
  *param_2 = *(float *)(param_1 + 0x80);
  param_2[1] = *(float *)(param_1 + 0x84);
  param_2[2] = *(float *)(param_1 + 0x88);
  if (*(short *)(param_1 + 0x1064) == DAT_007f1914) {
    *param_2 = *param_2 +
               (float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x27a) >> 1] *
               *(float *)(param_1 + 0x1dc) * 1.5;
    param_2[2] = (float)(&DAT_029899a0)[(int)(*(ushort *)(param_1 + 0x27a) + 0x4000) >> 1 & 0x7fff]
                 * *(float *)(param_1 + 0x1dc) * 1.5 + param_2[2];
  }
  return;
}

