/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5eb090; label: FUN_005eb090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005eb090(int param_1,int param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
                 int *param_6)

{
  uint *puVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_40c;
  int local_408;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_40c;
  local_408 = param_2;
  iVar4 = FUN_005ea9d0(param_1,param_5,*param_6);
  if (iVar4 == 0) {
    local_40c = *param_5;
    *param_5 = local_40c + 0xf & 0xfffffff0;
    _sprintf(local_404,"%s.qfn",param_1);
    iVar4 = FUN_004fd5d0(local_404,*param_5,*param_6 - *param_5);
    if (iVar4 != 0) {
      uVar3 = *param_5;
      *(int *)(uVar3 + 0x34) = *(int *)(uVar3 + 0x34) + uVar3;
      *(int *)(uVar3 + 0x38) = *(int *)(uVar3 + 0x38) + uVar3;
      uVar5 = iVar4 + 0xf + *param_5 & 0xfffffff0;
      *param_5 = uVar5;
      *(uint *)(uVar3 + 0x48) = uVar5;
      *param_5 = *param_5 + 0x58;
      iVar4 = *(int *)(uVar3 + 0x48);
      *(int *)(uVar3 + 0x44) = iVar4;
      *(int *)(uVar3 + 0x2c) = iVar4 + 0x50;
      *(int *)(uVar3 + 0x30) = iVar4 + 0x54;
      iVar4 = local_408;
      if (local_408 == 0) {
        iVar4 = param_1;
      }
      _sprintf(local_404,"%s",iVar4);
      iVar4 = FUN_005f8d60(local_404,param_5,*param_6);
      if (iVar4 != 0) {
        iVar6 = FUN_005e4b20(0);
        *(int *)(uVar3 + 0x40) = iVar6;
        if (iVar6 != 0) {
          *(undefined4 *)(iVar6 + 0x54) = 0x3f800000;
          *(undefined4 *)(*(int *)(uVar3 + 0x40) + 0x58) = 0x3f800000;
          *(undefined4 *)(*(int *)(uVar3 + 0x40) + 0x5c) = 0x3f800000;
          *(uint *)(*(int *)(uVar3 + 0x40) + 0x40) =
               *(uint *)(*(int *)(uVar3 + 0x40) + 0x40) & 0xffffefff | 0x2000;
          puVar1 = (uint *)(*(int *)(uVar3 + 0x40) + 0x40);
          *puVar1 = *puVar1 | 0xc000;
          *(undefined4 *)(*(int *)(uVar3 + 0x40) + 0x70) = 0x3f800000;
          *(uint *)(*(int *)(uVar3 + 0x40) + 0x40) =
               *(uint *)(*(int *)(uVar3 + 0x40) + 0x40) & 0xfffffff1 | 1;
          puVar1 = (uint *)(*(int *)(uVar3 + 0x40) + 0x40);
          *puVar1 = *puVar1 | 0x40000;
          *(short *)(*(int *)(uVar3 + 0x40) + 0x74) = (short)iVar4;
          iVar4 = *(int *)(uVar3 + 0x40);
          FUN_00601030(iVar4);
          psVar2 = (short *)(iVar4 + 0x2c0);
          *psVar2 = *psVar2 + 1;
          goto LAB_005eb22a;
        }
        FUN_005e5630(iVar4);
      }
    }
    FUN_005c1300(param_1);
    *param_5 = local_40c;
  }
LAB_005eb22a:
  __security_check_cookie(local_4 ^ (uint)&local_40c);
  return;
}

