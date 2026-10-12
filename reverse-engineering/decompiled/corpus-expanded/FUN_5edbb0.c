/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5edbb0; label: FUN_005edbb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005edbb0(float *param_1,float *param_2)

{
  *param_1 = -DAT_0080b708;
  param_1[4] = DAT_0080b70c;
  param_1[8] = -_DAT_0080b710;
  param_1[1] = -_DAT_0080b718;
  param_1[5] = _DAT_0080b71c;
  param_1[9] = -_DAT_0080b720;
  param_1[2] = -_DAT_0080b728;
  param_1[6] = _DAT_0080b72c;
  param_1[10] = -_DAT_0080b730;
  param_1[0xb] = 0.0;
  param_1[7] = 0.0;
  param_1[3] = 0.0;
  param_1[0xf] = 1.0;
  param_1[0xc] = *param_2;
  param_1[0xd] = param_2[1];
  param_1[0xe] = param_2[2];
  return;
}

