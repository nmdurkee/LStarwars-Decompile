/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x656080; label: FUN_00656080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00656080(float *param_1,float param_2,int param_3,int param_4,int param_5)

{
  float *pfVar1;
  
  if (*(float *)(param_4 + 0x2cc) < param_2 != (*(float *)(param_4 + 0x2cc) == param_2)) {
    if (*(short *)(param_4 + 0x2ca) < 1) {
      *(float *)(param_4 + 0x200 + *(short *)(param_4 + 0x2c8) * 0x1c) = param_2;
      *(float *)(param_4 + 0x1e8 + *(short *)(param_4 + 0x2c8) * 0x1c) =
           *(float *)(param_4 + 400) + *param_1;
      *(float *)(param_4 + 0x1ec + *(short *)(param_4 + 0x2c8) * 0x1c) =
           *(float *)(param_4 + 0x194) + param_1[1];
      *(float *)(param_4 + 0x1f0 + *(short *)(param_4 + 0x2c8) * 0x1c) =
           *(float *)(param_4 + 0x198) + param_1[2];
      pfVar1 = (float *)(param_4 + 500 + *(short *)(param_4 + 0x2c8) * 0x1c);
      *pfVar1 = param_1[4];
      pfVar1[1] = param_1[5];
      pfVar1[2] = param_1[6];
      *(short *)(param_4 + 0x2c8) = *(short *)(param_4 + 0x2c8) + 1;
      if ((short)*(char *)(param_3 + 0x2f0) <= *(short *)(param_4 + 0x2c8)) {
        *(undefined2 *)(param_4 + 0x2c8) = 0;
      }
      if (param_5 != 0) {
        *(undefined2 *)(param_4 + 0x2ca) = *(undefined2 *)(param_4 + 0x2c8);
      }
      *(float *)(param_4 + 0x2cc) =
           *(float *)(param_3 + 0xa4) / (float)(int)*(char *)(param_3 + 0x2f0) + param_2;
      return;
    }
    *(short *)(param_4 + 0x2ca) = *(short *)(param_4 + 0x2ca) + -1;
  }
  return;
}

