/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x428d70; label: FUN_00428d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00428d70(int param_1,int param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_00499920();
  _DAT_0087b8b8 = (float)fVar1;
  if (*(int *)(param_1 + 0x128) == DAT_0087b158) {
    FUN_004e4220(param_1,param_2);
  }
  if (DAT_0087b090 != 0) {
    if (*(short *)(param_2 + 0xf0) == *(short *)(DAT_0087b090 + 0x62)) {
      if ((*(int *)(param_1 + 0x128) == DAT_0087b08c) && (DAT_00882a70 == 3)) {
        if (DAT_0093b2a4 == 0) {
          DAT_00951b80 = DAT_0087b098;
          DAT_00950770 = 1;
          if (DAT_0093d84c != -1) {
            DAT_0093d850 = 1;
            return;
          }
        }
        else {
          FUN_0057a5b0(param_1);
        }
      }
      else if ((*(short *)(param_2 + 0xf0) == *(short *)(DAT_0087b090 + 0x62)) &&
              (*(int *)(param_1 + 0x128) == DAT_0087b08c)) {
        FUN_004d9f90();
        return;
      }
    }
  }
  return;
}

