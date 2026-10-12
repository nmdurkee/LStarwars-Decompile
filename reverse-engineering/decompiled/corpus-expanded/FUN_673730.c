/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x673730; label: FUN_00673730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00673730(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  float10 fVar1;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  fVar1 = (float10)2e+06;
  _DAT_02924b08 = (float)fVar1;
  _DAT_02920d84 = (float)fVar1;
  _DAT_02962004 = 0x3f800000;
  DAT_0292fdc8 = 0xffffffff;
  _DAT_02921864 = (float)fVar1;
  DAT_02961fdc = 0xffff;
  _DAT_0292fbf4 = 0xffff;
  DAT_0292fdbc = 0x3f800000;
  DAT_02920ab0 = 0;
  _DAT_0292fdcc = 0;
  DAT_0292fd44 = 0;
  DAT_0292182c = 0;
  _DAT_02947d90 = 0;
  DAT_0292fbf0 = 0;
  if (DAT_0292fc68 != 0) {
    DAT_0292186c = FUN_006de8d0(0x948);
    DAT_02924b34 = DAT_02962b30;
    local_c = *param_1;
    local_8 = (float)param_1[1];
    local_4 = param_1[2];
    FUN_00671750(&local_c,param_5);
    FUN_006729e0(&local_c,param_3,param_4);
    FUN_006de960();
    fVar1 = (float10)local_8;
    DAT_0292fb54 = 0;
  }
  return fVar1;
}

