/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x45a8f0; label: FUN_0045a8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045a8f0(int param_1,undefined4 param_2,float param_3)

{
  short local_4;
  
  if (-1 < *(int *)(param_1 + 0x14)) {
    *(float *)(param_1 + 0x18) = param_3 + *(float *)(param_1 + 0x18);
  }
  switch(*(int *)(param_1 + 0x14)) {
  case 0:
    DAT_00876db4._0_2_ = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8220;
    return;
  case 1:
    DAT_00876db4._0_2_ = 0;
    if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) !=
        (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18))) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 2;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8220;
      return;
    }
    break;
  case 2:
    local_4 = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_4;
    if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) !=
        (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18))) {
      FUN_00681f40("TrueJedi_100pc",0);
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8224;
      *(undefined4 *)(param_1 + 0x14) = 3;
      return;
    }
    break;
  case 3:
    DAT_00876db4._0_2_ = 0;
    if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) !=
        (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18))) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 4;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8220;
      return;
    }
    break;
  case 4:
    local_4 = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_4;
    if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) !=
        (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18))) {
      FUN_00681f40("TrueJedi_100pc",0);
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8224;
      *(undefined4 *)(param_1 + 0x14) = 5;
      return;
    }
    break;
  case 5:
    DAT_00876db4._0_2_ = 0;
    if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) !=
        (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18))) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 6;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8224;
      return;
    }
    break;
  case 6:
    DAT_00876db4._0_2_ = 0;
    if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) !=
        (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18))) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 7;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8220;
      return;
    }
    break;
  case 7:
    local_4 = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_4;
    if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) !=
        (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18))) {
      FUN_004838f0(param_2);
      return;
    }
  }
  return;
}

