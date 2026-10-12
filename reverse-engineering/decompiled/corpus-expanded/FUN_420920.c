/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x420920; label: FUN_00420920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00420920(float param_1,float param_2,undefined4 param_3,float param_4,float param_5,
                 undefined4 param_6,float param_7,float param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 local_18;
  undefined4 local_10;
  
  FUN_004208a0(param_7 * *(float *)(in_ECX + 0xc),0x40c88080);
  fVar1 = -param_2 - 0.06;
  FUN_00607d70(0xd,5,*(undefined4 *)(in_ECX + 0xebc));
  FUN_004200c0();
  fVar2 = param_1 - param_4;
  FUN_006009e0(fVar2,fVar1 - param_5,param_3);
  FUN_004200c0();
  FUN_006009e0(fVar2,fVar1 + param_5,param_3);
  FUN_004200c0();
  fVar3 = param_1 + param_4;
  FUN_006009e0(fVar3,fVar1 - param_5,param_3);
  FUN_004200c0();
  FUN_006009e0(fVar3,fVar1 + param_5,param_3);
  FUN_006009a0();
  fVar4 = param_5 * 0.5;
  local_18 = 0.0;
  iVar5 = FUN_006e6b90();
  FUN_00607d70(0xe,5,*(undefined4 *)(in_ECX + 0xebc));
  uVar6 = iVar5 << 0x18;
  FUN_004208a0(*(undefined4 *)(in_ECX + 0xc),uVar6 | 0xc8c8c8);
  FUN_004200c0();
  FUN_006009e0(fVar2,fVar1,param_3);
  FUN_004200c0();
  FUN_006009e0(fVar3,fVar1,param_3);
  FUN_004208a0(*(undefined4 *)(in_ECX + 0xc),uVar6 | 0xffc864);
  FUN_004208a0(*(undefined4 *)(in_ECX + 0xc),uVar6 | 0xff9678);
  uVar6 = 0;
  do {
    local_10 = param_5 * 0.8;
    if ((uVar6 & 3) != 0) {
      local_10 = fVar4;
    }
    FUN_004200c0();
    FUN_006009e0(local_18 + param_1,local_10 + fVar1,param_3);
    FUN_004200c0();
    FUN_006009e0(local_18 + param_1,fVar1 - local_10,param_3);
    FUN_004200c0();
    FUN_006009e0(param_1 - local_18,local_10 + fVar1,param_3);
    FUN_004200c0();
    FUN_006009e0(param_1 - local_18,fVar1 - local_10,param_3);
    uVar6 = uVar6 + 1;
    local_18 = local_18 + param_4 / 20.0;
  } while ((int)uVar6 < 0x14);
  FUN_006009a0();
  fVar2 = (param_4 * param_8) / 100.0;
  FUN_00420780(param_6,*(undefined4 *)(in_ECX + 0xc),0x400000c8);
  FUN_00607d70(0xd,5,*(undefined4 *)(in_ECX + 0xebc));
  FUN_004200c0();
  fVar3 = param_1 - fVar2;
  FUN_006009e0(fVar3,fVar1 - fVar4,param_3);
  FUN_004200c0();
  FUN_006009e0(fVar3,fVar4 + fVar1,param_3);
  FUN_004200c0();
  fVar2 = fVar2 + param_1;
  FUN_006009e0(fVar2,fVar1 - fVar4,param_3);
  FUN_004200c0();
  FUN_006009e0(fVar2,fVar4 + fVar1,param_3);
  FUN_006009a0();
  return;
}

