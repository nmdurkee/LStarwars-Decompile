/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x5245c0; label: FUN_005245c0
 */

void FUN_005245c0(int param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  undefined2 uVar1;
  int iVar2;
  int unaff_ESI;
  float10 fVar3;
  undefined1 local_1b4 [4];
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194 [2];
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  float local_16c;
  undefined4 local_168;
  undefined1 local_164 [4];
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  float local_154;
  float local_14c;
  float local_144;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  float local_f8;
  float local_f0;
  float local_e8;
  undefined1 local_ac [16];
  undefined1 local_9c;
  undefined2 local_9a;
  undefined1 *local_30;
  undefined4 *local_2c;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_1b4;
  local_1b0 = param_3;
  _memset(local_ac,0,0xa8);
  local_188 = 0;
  local_184 = 0;
  local_180 = 0;
  local_17c = 0;
  local_178 = 0;
  local_174 = 0;
  local_170 = 0;
  local_16c = 0.0;
  local_168 = 0;
  _memset(local_164,0,0xb8);
  local_160 = *(undefined4 *)(unaff_ESI + 0x18);
  local_15c = *(undefined4 *)(unaff_ESI + 0x1c);
  local_154 = param_4 + *(float *)(unaff_ESI + 0x24);
  local_1ac = 0;
  local_1a8 = 0;
  local_1a4 = 0;
  local_1a0 = 0;
  local_19c = 0;
  local_198 = 0;
  local_14c = (*(float *)(unaff_ESI + 0x28) + *(float *)(unaff_ESI + 0x1c)) - param_4;
  local_158 = *(undefined4 *)(unaff_ESI + 0x20);
  local_104 = *(undefined4 *)(param_1 + 0x18);
  local_100 = *(undefined4 *)(param_1 + 0x1c);
  local_144 = *(float *)(unaff_ESI + 0x2c) + *(float *)(unaff_ESI + 0x1c) + param_4;
  local_fc = *(undefined4 *)(param_1 + 0x20);
  local_30 = local_164;
  local_f8 = *(float *)(param_1 + 0x24) + param_4;
  local_2c = &local_188;
  local_9c = 2;
  local_9a = 1;
  local_f0 = (*(float *)(param_1 + 0x28) + *(float *)(param_1 + 0x1c)) - param_4;
  local_e8 = *(float *)(param_1 + 0x2c) + *(float *)(param_1 + 0x1c) + param_4;
  local_178 = CONCAT31(local_178._1_3_,1);
  fVar3 = (float10)FUN_005bed80(unaff_ESI + 0x18,param_1 + 0x18,local_194);
  local_16c = (float)fVar3;
  if (local_16c == 0.0) {
    local_16c = 0.0001;
  }
  FUN_005bfe00(local_194[0],local_18c);
  uVar1 = FUN_006e6b90();
  local_178 = CONCAT22(uVar1,(undefined2)local_178);
  iVar2 = FUN_0051b1f0(0);
  if (iVar2 != 0) {
    FUN_005243b0();
    __security_check_cookie(local_4 ^ (uint)local_1b4);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)local_1b4);
  return;
}

