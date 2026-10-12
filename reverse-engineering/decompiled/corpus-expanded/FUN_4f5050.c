/* Ghidra pseudocode, not original source.
 * ev_df79f36d452c441765aee3b48fdf5c85f40e43d18ea34c7e23c83a31d911b650
 * Entry: 0x4f5050; label: FUN_004f5050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004f5050(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0297dbcc;
  DAT_0297dbcc = param_1;
  switch(param_1) {
  case 1:
  case 2:
  case 5:
    break;
  case 3:
  case 4:
  case 6:
    if (DAT_0297dbdc != 0) {
      _DAT_0297dbe0 = 0x41c80000;
      FUN_004feb70(param_1);
      return uVar1;
    }
    _DAT_0297dbe0 = 0x41f00000;
  default:
    FUN_004feb70(param_1);
    return uVar1;
  }
  if (DAT_0297dbdc == 0) {
    _DAT_0297dbe0 = 0x42700000;
    FUN_004feb70(param_1);
    return uVar1;
  }
  _DAT_0297dbe0 = 0x42480000;
  FUN_004feb70(param_1);
  return uVar1;
}

