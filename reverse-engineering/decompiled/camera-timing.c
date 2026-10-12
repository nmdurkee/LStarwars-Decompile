/* Ghidra pseudocode; not original source. ev_b93162f417ce769d18c418ca0f4e32c22833544a379c82d303174eb029042845 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00577790(int param_1,float param_2,undefined4 param_3,float param_4,undefined4 param_5,
                 int param_6,uint param_7)

{
  if (param_1 != 0) {
    _DAT_00951914 = param_2;
    _DAT_009514e8 = param_3;
    DAT_00951918 = ~-(uint)(DAT_00951288 != 0) & param_7;
    _DAT_0095191c = 0;
    DAT_009514e4 = param_1;
    _DAT_009514d8 = param_4;
    DAT_009514dc = 0;
    _DAT_009514ec = param_5;
    DAT_00951920 = 0;
    DAT_00951924 = 0;
    DAT_009514e0 = param_6;
    if (((param_6 != 0) && (param_2 == 0.0)) && (param_4 < 0.0 != (param_4 == 0.0))) {
      _DAT_00950760 = 0x3f800000;
    }
    if ((param_2 < 0.0 != (param_2 == 0.0)) && (param_4 <= 0.0)) {
      PTR_DAT_008021b4[0x22c] = 0xff;
      *(undefined4 *)(PTR_DAT_008021b4 + 0x1bc) = *(undefined4 *)(PTR_DAT_008021b4 + 0x1c0);
      FUN_005765b0();
      DAT_009514de = 0;
      return;
    }
    FUN_005765b0();
    DAT_009514de = 0;
  }
  return;
}

