/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x426de0; label: FUN_00426de0
 */

void FUN_00426de0(undefined4 param_1,ushort param_2)

{
  float fVar1;
  int iVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x49,param_1);
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x4a,param_1);
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x4b,param_1);
  FUN_00571b60(*(undefined4 *)(PTR_DAT_00802c54 + 0x138),2,param_1);
  FUN_0054a910(0x3f800000,0x3dcccccd,0,0);
  FUN_00681f40("exp_thermalDet",param_1);
  local_4 = 0x3f400000;
  local_8 = 0x3f000000;
  if ((param_2 & 0x1000) == 0) {
    FUN_00549bb0(PTR_DAT_008021b4,0x3f800000,0x3f800000,0x3f800000);
  }
  else {
    local_4 = 0x3fa80000;
    local_8 = 0x3f600000;
    iVar2 = FUN_0054fa60();
    if (iVar2 < 0x8000) {
      fVar1 = -1.0;
    }
    else {
      fVar1 = 1.0;
    }
    FUN_00549de0(PTR_DAT_008021b4,fVar1 + fVar1,2,param_1);
    FUN_00549bb0(PTR_DAT_008021b4,0x40000000,0x3f800000,0x3f800000);
    FUN_00681f40("exp_thermalDet",param_1);
  }
  FUN_0056e5f0(param_1,local_4,local_8,0,0xffffffff,param_2 | 0x67);
  return;
}

