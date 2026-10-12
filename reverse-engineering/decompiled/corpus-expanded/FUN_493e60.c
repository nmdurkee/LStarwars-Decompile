/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x493e60; label: FUN_00493e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493e60(undefined4 param_1,float param_2,int param_3,int param_4)

{
  float fVar1;
  uint uVar2;
  float local_134;
  float local_130;
  float local_12c;
  int local_128;
  char local_124 [32];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_134;
  local_12c = _DAT_00800994 * 0.75;
  local_130 = _DAT_0080098c * 0.75;
  if (param_4 == -1) {
    FUN_004f1f10(local_104,*(undefined4 *)(DAT_00926c20 + DAT_008807fc * 4));
  }
  else {
    _sprintf(local_104,"%s %i",*(undefined4 *)(DAT_00926c20 + DAT_00880800 * 4),param_4 + 1);
  }
  if ((param_3 == 0) || (DAT_009213e4 == 0)) {
    local_134 = 3.57331e-43;
    local_128 = (uint)local_128._1_3_ << 8;
  }
  else {
    local_134 = 0.0;
    local_128 = CONCAT31(local_128._1_3_,0xff);
  }
  fVar1 = local_134;
  local_134 = param_2 - local_12c * 1.5;
  FUN_0050c780(local_104,param_1,local_134,0x3f800000,local_130,local_130,local_130,0,fVar1,
               local_128,0xff,_DAT_00921d60 & 0xff);
  if (param_4 == -1) {
    uVar2 = (uint)DAT_0086e4e0;
  }
  else {
    if ((&DAT_02989540)[param_4] == 0) {
      if (DAT_008015a4 <= DAT_0080200c) {
        local_134 = local_12c * 0.5 + param_2;
        FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_008809cc * 4),param_1,local_134,0x3f800000,
                     local_130,local_130,local_130,0,0,0xff,0,0x3ee66666,2,0,0,_DAT_00921d60);
        __security_check_cookie(local_4 ^ (uint)&local_134);
        return;
      }
      local_134 = local_12c * 0.5 + param_2;
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880aec * 4),param_1,local_134,0x3f800000,
                   local_130,local_130,local_130,0,0xff,0,0,0x3ee66666,2,0,0,_DAT_00921d60);
      __security_check_cookie(local_4 ^ (uint)&local_134);
      return;
    }
    uVar2 = (&DAT_02989320)[param_4];
  }
  local_134 = (float)(uVar2 * 100);
  _sprintf(local_124,"%.1f%%",(double)(int)local_134 / (double)DAT_0093b2b8);
  local_130 = local_130 * 1.5;
  local_134 = local_12c * 0.5 + param_2;
  FUN_0050c780(local_124,param_1,local_134,0x3f800000,local_130,local_130,local_130,0,0xff,0xbf,0,
               _DAT_00921d60 & 0xff);
  __security_check_cookie(local_4 ^ (uint)&local_134);
  return;
}

