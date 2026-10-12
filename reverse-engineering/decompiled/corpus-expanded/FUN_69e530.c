/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69e530; label: FUN_0069e530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0069e530(undefined8 param_1,code *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  if (1 < *(int *)(in_ECX + 0x58)) {
    iVar4 = FUN_0069df70();
    if (iVar4 == 0) {
      iVar4 = *(int *)(in_ECX + 0x48);
      iVar5 = iVar4;
      if ((*(int *)(in_ECX + 4) != 0) && (2 < *(int *)(in_ECX + 0x58))) {
        iVar5 = *(int *)(in_ECX + 0x60) * 0x20 + iVar4;
      }
      local_c = iVar5;
      if (iVar4 == 0) {
        local_10 = -0x83;
      }
      else {
        local_10 = FUN_006a14a0(iVar4);
      }
      iVar4 = *(int *)(iVar5 + 4);
      local_10 = local_10 + 1;
      local_18 = FUN_006a0120(iVar5,0);
      local_18 = local_18 >> ((byte)local_10 & 0x1f);
      local_20 = FUN_006a3190(in_ECX + 0x1e0,0);
      iVar5 = iVar4 * -4;
      puVar7 = &stack0xffffffd0 + iVar5;
      local_14 = &stack0xffffffd0 + iVar5;
      iVar9 = 0;
      puVar6 = &stack0xffffffd0 + iVar5;
      puVar3 = &stack0xffffffd0 + iVar5;
      if (0 < iVar4) {
        do {
          iVar5 = local_18;
          *(undefined4 *)(puVar6 + -4) = 0x69e5f4;
          iVar5 = iVar5 * -4;
          puVar7 = puVar6 + iVar5;
          *(undefined1 **)(local_14 + iVar9 * 4) = puVar6 + iVar5;
          iVar9 = iVar9 + 1;
          puVar6 = puVar6 + iVar5;
          puVar3 = local_14;
        } while (iVar9 < iVar4);
      }
      local_14 = puVar3;
      iVar5 = local_c;
      puVar6 = local_14;
      *(int *)(puVar7 + -4) = local_18;
      *(undefined1 **)(puVar7 + -8) = puVar6;
      *(int *)(puVar7 + -0xc) = in_ECX + 0x1e0;
      *(int *)(puVar7 + -0x10) = iVar5;
      *(int *)(puVar7 + -0x14) = in_ECX;
      local_1c = in_ECX + 0x1e0;
      *(undefined4 *)(puVar7 + -0x18) = 0x69e61f;
      FUN_0069dfe0();
      *(undefined8 *)(puVar7 + -8) = param_1;
      *(int *)(puVar7 + -0xc) = in_ECX;
      puVar8 = (undefined4 *)(puVar7 + -0x10);
      *(undefined4 *)(puVar7 + -0x10) = 0x69e62c;
      iVar5 = (*param_2)();
      if (iVar5 == 0) {
        puVar8[2] = 0x69e638;
        iVar5 = FUN_0069dfa0();
        if (iVar5 == 0) {
          if ((*(int *)(in_ECX + 4) == 0) || (*(int *)(in_ECX + 0x58) < 3)) {
            iVar5 = *(int *)(in_ECX + 0x48);
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x60) * 0x20 + *(int *)(in_ECX + 0x48);
          }
          uVar1 = *(undefined4 *)(iVar5 + 4);
          puVar8[2] = 0;
          puVar8[1] = iVar5;
          *puVar8 = 0x69e660;
          FUN_006a0120();
          iVar5 = local_1c;
          *puVar8 = 0;
          puVar8[-1] = iVar5;
          puVar8[-2] = 0x69e672;
          local_10 = FUN_006a3190();
          iVar5 = local_1c;
          puVar8[-2] = &local_24;
          puVar8[-3] = iVar5;
          puVar8[-4] = 0x69e682;
          FUN_006a2e40();
          uVar2 = local_20;
          puVar8[-4] = local_10;
          puVar8[-5] = uVar2;
          puVar8[-6] = uVar1;
          puVar8[-7] = iVar4;
          puVar8[-8] = local_24;
          puVar8[-9] = 0x69e69d;
          FUN_0069dcd0();
        }
      }
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

