/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43b410; label: FUN_0043b410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0043b410(void)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  int unaff_ESI;
  float10 fVar6;
  float10 fVar7;
  float local_3c;
  undefined4 local_38;
  float local_34;
  float local_30 [4];
  undefined4 local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  *(uint *)(unaff_ESI + 0xef4) = *(uint *)(unaff_ESI + 0xef4) | 0x10000;
  iVar5 = *(int *)(*(int *)(unaff_ESI + 0x420) + 0x7c);
  if (*(char *)(unaff_ESI + 0x7b5) == 'E') {
    uVar4 = *(ushort *)(unaff_ESI + 0x7a6);
    local_3c = 0.0;
    local_38 = 0;
    local_34 = 1.0;
    FUN_005b3620(&local_3c,&local_3c,uVar4);
  }
  else {
    iVar1 = (uint)*(byte *)(*(byte *)(unaff_ESI + 0x428) + 0x10 + *(int *)(unaff_ESI + 0x424)) *
            0x5c + iVar5 + 4;
    FUN_005b3800(local_30 + 3,
                 (uint)*(byte *)((*(byte *)(unaff_ESI + 0x428) == 0) + 0x10 +
                                *(int *)(unaff_ESI + 0x424)) * 0x5c + iVar5 + 4,iVar1);
    local_20 = 0;
    FUN_005b3b30(local_30 + 3,local_30 + 3);
    FUN_005b3620(local_30 + 3,local_30 + 3,0x4000);
    local_c = -local_30[3];
    local_18 = local_30[3];
    local_8 = 0;
    local_4 = -local_1c;
    local_14 = local_20;
    local_10 = local_1c;
    iVar5 = FUN_0067b430(iVar1,&local_18,0,0x3f800000,0,DAT_0095100c | DAT_008034c4 | 0x5f);
    if (iVar5 == 0) {
      fVar7 = (float10)(float)0x4e6e6b28;
    }
    else {
      fVar7 = (float10)FUN_005bec80(&local_18);
    }
    uVar3 = local_8;
    fVar2 = local_c;
    local_18 = local_c;
    local_14 = local_8;
    local_10 = local_4;
    iVar5 = FUN_0067b430(iVar1,&local_18,0,0x3f800000,0,DAT_0095100c | DAT_008034c4 | 0x5f);
    if (iVar5 == 0) {
      fVar6 = (float10)(float)0x4e6e6b28;
    }
    else {
      fVar6 = (float10)FUN_005bec80(&local_18);
    }
    if (((float)fVar7 < 1e+09) || ((float)fVar6 < 1e+09)) {
      if ((float)fVar6 <= (float)fVar7) {
        local_3c = fVar2;
        local_38 = uVar3;
        local_34 = local_4;
      }
      else {
        local_3c = local_30[3];
        local_38 = local_20;
        local_34 = local_1c;
      }
    }
    uVar4 = FUN_005be2d0(local_3c,local_34);
  }
  local_30[0] = *(float *)(unaff_ESI + 0x3dc) - *(float *)(unaff_ESI + 0x5c);
  local_30[1] = 0.0;
  local_30[2] = *(float *)(unaff_ESI + 0x3e4) - *(float *)(unaff_ESI + 100);
  fVar7 = (float10)FUN_005bec80(local_30);
  if (_DAT_00801c6c < (float)fVar7) {
    fVar2 = _DAT_00801c6c / (float)fVar7;
    FUN_005b3830(local_30,local_30,fVar2 + fVar2);
  }
  FUN_005b3620(local_30,local_30,-(uint)uVar4);
  local_30[2] = 0.0;
  FUN_005b3620(local_30,local_30,(uint)uVar4);
  FUN_005b3830(&local_3c,&local_3c,_DAT_00801c6c);
  FUN_005b37d0(local_30,local_30,&local_3c);
  *(float *)(unaff_ESI + 0x3dc) = *(float *)(unaff_ESI + 0x5c) + local_30[0];
  *(undefined4 *)(unaff_ESI + 0x3e0) = *(undefined4 *)(unaff_ESI + 0x60);
  *(float *)(unaff_ESI + 0x3e4) = *(float *)(unaff_ESI + 100) + local_30[2];
  return 1;
}

