/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x6977b0; label: FUN_006977b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006977b0(void)

{
  undefined4 uVar1;
  float10 fVar2;
  
  if (DAT_02972c38 == (undefined4 *)0x0) {
    DAT_02972c38 = &DAT_009736e8;
  }
  if (_DAT_00810d98 <= _DAT_00810d9c) {
    _DAT_00810d98 = _DAT_00810d9c;
  }
  FUN_005b33c0();
  fVar2 = (float10)FUN_005b3b00();
  if ((float)fVar2 <= _DAT_00810d98 * _DAT_00810d98) {
    fVar2 = (float10)FUN_005c0240((float)fVar2);
    if ((float)fVar2 <= _DAT_00810d9c) {
      uVar1 = FUN_006e6b90();
      return uVar1;
    }
    uVar1 = FUN_006e6b90();
    return uVar1;
  }
  return 0;
}

