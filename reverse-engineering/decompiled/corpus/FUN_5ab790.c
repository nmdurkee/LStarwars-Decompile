/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5ab790; label: FUN_005ab790
 */

void FUN_005ab790(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  short *psVar1;
  int local_4;
  
  if (param_2 != (int *)0x0) {
    local_4 = 0;
    if ((short)param_2[2] != 0) {
      psVar1 = (short *)(*param_2 + 0x126);
      do {
        if (psVar1[2] != -1) {
          FUN_00548640((int)psVar1[2],param_3,param_4,param_5);
        }
        if (*psVar1 != -1) {
          FUN_00548640((int)*psVar1,param_3,param_4,param_5);
        }
        if (psVar1[9] != -1) {
          FUN_00548640((int)psVar1[9],param_3,param_4,param_5);
        }
        local_4 = local_4 + 1;
        psVar1 = psVar1 + 0x9e;
      } while (local_4 < (int)(uint)*(ushort *)(param_2 + 2));
    }
  }
  return;
}

