/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x466f90; label: FUN_00466f90
 */

void FUN_00466f90(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  short *psVar1;
  int local_4;
  
  if (param_2 != (int *)0x0) {
    local_4 = 0;
    if (*(short *)((int)param_2 + 0xe) != 0) {
      psVar1 = (short *)(*param_2 + 0x84);
      do {
        if (psVar1[-1] != -1) {
          FUN_00548640((int)psVar1[-1],param_3,param_4,param_5);
        }
        if (*psVar1 != -1) {
          FUN_00548640((int)*psVar1,param_3,param_4,param_5);
        }
        if (psVar1[1] != -1) {
          FUN_00548640((int)psVar1[1],param_3,param_4,param_5);
        }
        local_4 = local_4 + 1;
        psVar1 = psVar1 + 0x52;
      } while (local_4 < (int)(uint)*(ushort *)((int)param_2 + 0xe));
    }
  }
  return;
}

