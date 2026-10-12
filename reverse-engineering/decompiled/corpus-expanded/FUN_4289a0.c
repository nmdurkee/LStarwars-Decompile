/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x4289a0; label: FUN_004289a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004289a0(int *param_1,float param_2)

{
  int iVar1;
  
  if ((((param_1 != (int *)0x0) && (iVar1 = FUN_0056e160(0x2c), iVar1 != 0)) && (DAT_00951154 == 0))
     && (DAT_0093b338 == 0)) {
    param_2 = param_2 + (float)param_1[1];
    param_1[1] = (int)param_2;
    if (NAN(param_2) || 1.0 < param_2 == (param_2 == 1.0)) {
      if ((param_2 <= 0.0) && (-4 < *param_1)) {
        param_1[1] = 0x3f000000;
        *param_1 = *param_1 + -1;
        param_1[2] = 0;
        return (float10)(float)param_1[1];
      }
    }
    else if (*param_1 < 4) {
      param_1[1] = 0x3f000000;
      *param_1 = *param_1 + 1;
      param_1[2] = 0;
      return (float10)(float)param_1[1];
    }
  }
  return (float10)(float)param_1[1];
}

