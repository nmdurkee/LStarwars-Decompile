/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x530530; label: FUN_00530530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00530530(undefined4 param_1,float param_2,float param_3,uint param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  float10 fVar8;
  float local_24;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  iVar4 = (int)param_2;
  *(undefined4 *)(DAT_009238e4 + 0xc3938) = *(undefined4 *)((int)param_2 + 0x70);
  *(undefined4 *)(DAT_009238e4 + 0xc393c) = *(undefined4 *)((int)param_2 + 0x78);
  if (*(int *)(DAT_009238e4 + 4) == 0) {
    iVar5 = FUN_004f1ff0(DAT_009238e4 + 0xc3838);
    if (iVar5 != 0) {
      uVar6 = FUN_00527460("Warning",DAT_009238e4 + 0xc3838);
      *(undefined4 *)(DAT_009238e4 + 4) = uVar6;
      FUN_004f1f10(DAT_009238e4 + 0xc3838,&DAT_007516c0);
      if (*(int *)(DAT_009238e4 + 4) != 0) {
        return false;
      }
    }
    fVar8 = (float10)FUN_005b7d30(_DAT_00921f54 + param_3,0x3f800000);
    _DAT_00921f54 = (float)fVar8;
    if (((*(uint *)((int)param_2 + 0x70) & 0x100) == 0) &&
       ((*(byte *)(DAT_009238e4 + 0x43828) & 4) == 0)) {
      FUN_00620e70(param_2,param_3);
    }
    local_18 = *(undefined4 *)(DAT_009238e4 + 0x10);
    local_14 = *(undefined4 *)(DAT_009238e4 + 0x14);
    local_10 = *(undefined4 *)(DAT_009238e4 + 0x18);
    FUN_00620fa0(DAT_009238e4 + 0x10,DAT_009238e4 + 0x34,DAT_009238e4 + 0x38);
    FUN_005b3800(DAT_009238e4 + 0x1c,DAT_009238e4 + 0x10,&local_18);
    *(uint *)(DAT_009238e4 + 0x43828) = *(uint *)(DAT_009238e4 + 0x43828) & 0xfffffffb;
    iVar5 = DAT_009238e4;
    *(undefined4 *)(DAT_009238e4 + 0x3c) = 0;
    *(undefined4 *)(iVar5 + 0x40) = 0;
    *(undefined4 *)(iVar5 + 0x44) = 0;
    iVar5 = DAT_009238e4;
    *(undefined4 *)(DAT_009238e4 + 0x28) = *(undefined4 *)(DAT_009238e4 + 0x10);
    *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(iVar5 + 0x14);
    *(undefined4 *)(iVar5 + 0x30) = *(undefined4 *)(iVar5 + 0x18);
    if (DAT_009242bc == 0) {
      fVar8 = (float10)FUN_00673820(DAT_009238e4 + 0x10,0,0x40a00000,0xffffffff);
      local_24 = (float)fVar8;
    }
    uVar6 = 0xffffffff;
    if (DAT_009242bc == 0) {
      uVar6 = FUN_0067a6e0();
    }
    FUN_00520600(*(undefined4 *)(DAT_009238e4 + 8),DAT_009238e4 + 0x3c,uVar6);
    fVar3 = _DAT_02921864;
    fVar2 = _DAT_02920d84;
    if (((byte)DAT_00921f50 & 0x10) != 0) {
      param_2 = 2e+06;
      if (local_24 != 2e+06) {
        param_2 = ABS(*(float *)(DAT_009238e4 + 0x14) - local_24);
        *(float *)(DAT_009238e4 + 0x2c) = local_24;
      }
      if ((fVar2 != 2e+06) &&
         (fVar1 = *(float *)(DAT_009238e4 + 0x14) - fVar2, ABS(fVar1) < param_2)) {
        param_2 = ABS(fVar1);
        *(float *)(DAT_009238e4 + 0x2c) = fVar2;
      }
      if ((fVar3 != 2e+06) && (ABS(*(float *)(DAT_009238e4 + 0x14) - fVar3) < param_2)) {
        *(float *)(DAT_009238e4 + 0x2c) = fVar3;
      }
      if (((((DAT_0092390c == 0) && (*(int *)(DAT_009238e4 + 0x4868) != 0)) &&
           (iVar5 = *(int *)(DAT_009238e4 + 0x4868), *(int *)(iVar5 + 0x20) != 0)) &&
          ((*(int *)(iVar5 + 0x20) == *(int *)(iVar5 + 0x24) &&
           (*(float *)(DAT_009238e4 + 0x2c) < *(float *)(DAT_009238e4 + 0x14))))) &&
         (*(float *)(DAT_009238e4 + 0x2c) == local_24)) {
        FUN_005b3800(local_c,DAT_009238e4 + 0x28,DAT_009238e4 + 0x10);
        uVar7 = FUN_00690150(DAT_009238e4 + 0x10,local_c,
                             *(undefined4 *)
                              (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x24),
                             _DAT_00801cb0,0);
        if ((uVar7 != 0) && ((uVar7 & 0x10) == 0)) {
          FUN_005b37d0(DAT_009238e4 + 0x28,DAT_009238e4 + 0x10,local_c);
        }
      }
      *(float *)(DAT_009238e4 + 0x2c) = *(float *)(DAT_009238e4 + 0x2c) + _DAT_00921f38;
      iVar5 = DAT_009238e4;
      if (((byte)DAT_00921f50 & 0x20) != 0) {
        *(undefined4 *)(DAT_009238e4 + 0x10) = *(undefined4 *)(DAT_009238e4 + 0x28);
        *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar5 + 0x2c);
        *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(iVar5 + 0x30);
      }
    }
    if ((code *)(&DAT_00921f90)[DAT_009220ee * 0xc] != (code *)0x0) {
      uVar6 = (*(code *)(&DAT_00921f90)[DAT_009220ee * 0xc])(iVar4);
      *(undefined4 *)(DAT_009238e4 + 4) = uVar6;
    }
    if (*(int *)(DAT_009238e4 + 4) == 0) {
      return (*(uint *)(iVar4 + 0x78) & param_4) != 0;
    }
  }
  else {
    FUN_0062a400(*(undefined4 *)(DAT_009238e4 + 4),param_1,param_2);
  }
  return false;
}

