/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x420d30; label: FUN_00420d30
 */

void FUN_00420d30(float param_1,float param_2,undefined4 param_3,float param_4,float param_5,
                 float param_6,float param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int in_ECX;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_28;
  
  local_38 = param_5 * 0.5;
  FUN_004208a0(*(float *)(in_ECX + 0xc) * param_6,0x40c88080);
  fVar1 = -param_2 - 0.06;
  FUN_00607d70(0xd,5,*(undefined4 *)(in_ECX + 0xebc));
  FUN_004200c0();
  local_34 = param_1 - param_4;
  FUN_006009e0(local_34,fVar1 - local_38,param_3);
  FUN_004200c0();
  FUN_006009e0(local_34,local_38 + fVar1,param_3);
  FUN_004200c0();
  FUN_006009e0(param_1 + param_4,fVar1 - param_5,param_3);
  FUN_004200c0();
  FUN_006009e0(param_1 + param_4,fVar1 + param_5,param_3);
  FUN_006009a0();
  local_28 = 0;
  fVar2 = (param_4 + param_4) / param_7;
  fVar3 = (param_5 - local_38) / param_7;
  fVar2 = fVar2 + (fVar2 * 0.2) / param_7;
  iVar6 = FUN_006e6b90();
  if (0 < iVar6) {
    do {
      FUN_00420780((float)local_28 * 0.05 + param_6,*(undefined4 *)(in_ECX + 0xc),0x804040c8);
      FUN_00607d70(0xd,5,*(undefined4 *)(in_ECX + 0xebc));
      FUN_004200c0();
      FUN_006009e0(local_34,fVar1 - local_38,param_3);
      FUN_004200c0();
      FUN_006009e0(local_34,local_38 + fVar1,param_3);
      FUN_004200c0();
      fVar4 = local_34 + fVar2 * 0.8;
      fVar5 = local_38 + fVar3 * 0.8;
      FUN_006009e0(fVar4,fVar1 - fVar5,param_3);
      FUN_004200c0();
      FUN_006009e0(fVar4,fVar5 + fVar1,param_3);
      FUN_006009a0();
      local_38 = fVar3 + local_38;
      local_28 = local_28 + 1;
      local_34 = local_34 + fVar2;
    } while (local_28 < iVar6);
  }
  return;
}

