/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x462fa0; label: FUN_00462fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00462fa0(int param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float10 extraout_ST0;
  float local_20c;
  float local_208;
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_20c;
  if ((param_3 == 0) || (*(int *)(param_1 + 0x14) < 1)) goto LAB_0046329d;
  if (0.5 <= *(float *)(param_1 + 0x18)) {
    local_208 = 1.0;
    if (4.5 <= *(float *)(param_1 + 0x18)) {
      fVar1 = *(float *)(param_1 + 0x18) - 4.5;
      local_20c = 1.0 - (fVar1 + fVar1);
    }
    else {
      local_20c = 1.0;
    }
  }
  else {
    local_20c = *(float *)(param_1 + 0x18) + *(float *)(param_1 + 0x18);
    local_208 = local_20c;
  }
  iVar2 = FUN_006e6b90();
  iVar3 = FUN_006e6b90(_DAT_0087b93c,1,(float)extraout_ST0,0xff,0xbf,0);
  local_208 = (_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] +
              _DAT_007fc314;
  FUN_004b80e0(**(undefined4 **)(param_2 + 0x1c),local_208);
  if (*(float *)(param_2 + 0x60) == 0.0) {
    uVar4 = *(undefined4 *)(DAT_00926c20 + DAT_00880714 * 4);
    uVar5 = 0xff;
    uVar6 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(DAT_00926c20 + DAT_008806fc * 4);
    uVar5 = 0;
    uVar6 = 0xff;
  }
  FUN_0050d910(uVar4,0,0x3e4ccccd,0x3f800000,0x3f333333,0x3f333333,0x3f333333,0,uVar5,uVar6,0,
               0x3fd9999a,1,0,0,iVar2);
  fVar1 = 0.0;
  if (*(float *)(param_2 + 0x60) == 0.0) {
    local_208 = *(float *)(param_2 + 0xa8);
  }
  else {
    if (0.5 <= *(float *)(param_1 + 0x18)) {
      if (*(float *)(param_1 + 0x18) < 4.0) {
        local_20c = (*(float *)(param_1 + 0x18) - 0.5) / 3.5;
        local_208 = (*(float *)(param_2 + 0x60) - *(float *)(param_2 + 0x5c)) * local_20c +
                    *(float *)(param_2 + 0x5c);
        goto LAB_00463197;
      }
      fVar1 = 1.0;
    }
    local_208 = (*(float *)(param_2 + 0x60) - *(float *)(param_2 + 0x5c)) * fVar1 +
                *(float *)(param_2 + 0x5c);
    local_20c = fVar1;
  }
LAB_00463197:
  FUN_0054bbc0(local_208,1,1,1,local_204);
  FUN_0050c780(local_204,0,0,0x3f800000,0x3f333333,0x3f333333,0x3f333333,0,0xff,0xff,0xff,iVar2);
  FUN_0054bbc0(*(undefined4 *)(param_2 + 0x5c),1,1,1,local_204);
  FUN_004f1f10(local_104,&DAT_00755d74);
  FUN_004f1e80(local_104,local_204);
  FUN_004f1e80(local_104,&DAT_00755d70);
  FUN_0050c780(local_104,0,0xbe4ccccd,0x3f800000,0x3f333333,0x3f333333,0x3f333333,0,0xff,0xff,0xff,
               iVar2 / 2);
LAB_0046329d:
  __security_check_cookie(local_4 ^ (uint)&local_20c);
  return;
}

