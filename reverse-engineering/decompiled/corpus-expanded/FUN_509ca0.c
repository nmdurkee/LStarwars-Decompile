/* Ghidra pseudocode, not original source.
 * ev_6614b6c0ec400e98b17ca3318749993ac398f4a5e7c651bffc9aeb30b42772d2
 * Entry: 0x509ca0; label: FUN_00509ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00509ca0(int *param_1,undefined4 *param_2,float *param_3,char *param_4,float param_5,
                 float param_6)

{
  if (*param_1 == 0) {
    *param_3 = 0.5;
    *param_4 = '\0';
    return;
  }
  if (0.0 < *param_3) {
    param_6 = *param_3 - param_6;
    *param_3 = param_6;
    if (param_6 < 0.0 != (param_6 == 0.0)) {
      *param_2 = 1;
      *param_3 = param_5;
      *param_4 = *param_4 + '\x01';
      return;
    }
  }
  return;
}

