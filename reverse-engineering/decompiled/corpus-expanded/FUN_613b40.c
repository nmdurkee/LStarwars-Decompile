/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x613b40; label: FUN_00613b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00613b40(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int *in_ECX;
  int iVar7;
  undefined4 unaff_EBX;
  int *piVar8;
  undefined1 *unaff_EDI;
  int iVar9;
  undefined1 *puVar10;
  int iStack_48;
  undefined4 uStack_44;
  uint local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34 [4];
  undefined1 auStack_24 [16];
  int aiStack_14 [4];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&iStack_48;
  piVar8 = *(int **)(param_1 + 8);
  local_38 = param_3;
  local_3c = param_1;
  local_34[0] = param_4;
  local_40 = 0;
  if (piVar8 == (int *)0x0) {
    __security_check_cookie(local_4 ^ (uint)&iStack_48);
    return;
  }
  do {
    if ((piVar8[7] & 0x80000000U) == 0) {
      if (piVar8[9] == (uint)*(ushort *)(in_ECX + 3)) {
        iVar3 = piVar8[3];
        (**(code **)(*piVar8 + 4))(param_2,iVar3,aiStack_14,0x100);
        iVar7 = piVar8[3];
        iVar9 = 1;
        if (iVar7 == DAT_02973ab4) {
LAB_00613c79:
          unaff_EDI = auStack_24;
        }
        else {
          if ((iVar7 == DAT_02973ab8) || (iVar7 == DAT_02973ad0)) {
            iVar9 = 3;
            goto LAB_00613c79;
          }
          if (iVar7 == DAT_02973aa8) {
            unaff_EDI = &stack0xffffffac;
          }
          else if (iVar7 == DAT_02973aac) {
            unaff_EDI = &stack0xffffffac;
          }
          else if (iVar7 == DAT_02973ab0) {
            unaff_EDI = &stack0xffffffac;
          }
          else {
            FUN_00611890();
          }
        }
        FUN_004ef660(local_34,unaff_EDI,iVar9 * 4);
        iVar7 = 0;
        if (iVar9 != 0) {
          iVar6 = *(int *)(iStack_48 + 8);
          do {
            uVar5 = iVar6 + 3U & 0xfffffffc;
            (&local_40)[iVar7] = uVar5;
            iVar7 = iVar7 + 1;
            iVar6 = uVar5 + 0xc;
          } while (iVar7 < iVar9);
          *(int *)(iStack_48 + 8) = iVar6;
        }
        puVar10 = unaff_EDI;
        (**(code **)(*in_ECX + 0x14))(unaff_EBX,param_2,uStack_44,&local_40,unaff_EDI,iVar9);
        if (aiStack_14[0] == 0) {
          iVar3 = piVar8[3];
          if (iVar3 == DAT_02973aa8) {
            uVar1 = FUN_006e6b90();
            local_3c = CONCAT31(local_3c._1_3_,uVar1);
          }
          else if (iVar3 == DAT_02973aac) {
            uVar2 = FUN_006e6b90();
            local_3c = CONCAT22(local_3c._2_2_,uVar2);
          }
          else if (iVar3 == DAT_02973ab0) {
            local_3c = FUN_006e6b90();
          }
          (**(code **)(*piVar8 + 8))(param_2,piVar8[3],&local_3c,0x100,0);
        }
        else {
          uVar5 = (**(code **)(*in_ECX + 0x10))(iVar3,param_2,&stack0xffffffb4,puVar10,iVar9);
          local_40 = local_40 | uVar5;
        }
      }
    }
    else {
      iVar3 = FUN_006be7f0(piVar8[3]);
      local_3c = iVar3;
      uVar4 = (**(code **)*piVar8)(param_2);
      uVar5 = FUN_00613b40(iVar3,uVar4,local_38,local_34[0],param_5);
      local_40 = local_40 | uVar5;
    }
    piVar8 = (int *)piVar8[1];
    if (piVar8 == (int *)0x0) {
      __security_check_cookie(local_4 ^ (uint)&iStack_48);
      return;
    }
  } while( true );
}

