/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x509ca0; label: FUN_00509ca0
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

