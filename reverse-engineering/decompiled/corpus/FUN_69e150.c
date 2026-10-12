/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69e150; label: FUN_0069e150
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0069e150(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int aiStack_54 [6];
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  undefined4 *local_1c;
  undefined1 *local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  if (param_1 != param_2) {
    if ((*(int *)(param_1 + 0x58) < 2) || (*(int *)(param_2 + 0x58) < 2)) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    iStack_34 = 0x69e1a0;
    iVar5 = FUN_0069df70();
    if (iVar5 == 0) {
      iStack_34 = 0x69e1af;
      iVar5 = FUN_0069dfa0();
      if (iVar5 == 0) {
        if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 0x58) < 3)) {
          iVar5 = *(int *)(param_1 + 0x48);
        }
        else {
          iVar5 = *(int *)(param_1 + 0x60) * 0x20 + *(int *)(param_1 + 0x48);
        }
        if (*(int *)(param_2 + 4) == 0) {
          local_c = *(int *)(param_2 + 0x48);
        }
        else if (*(int *)(param_2 + 0x58) < 3) {
          local_c = *(int *)(param_2 + 0x48);
        }
        else {
          local_c = *(int *)(param_2 + 0x60) * 0x20 + *(int *)(param_2 + 0x48);
        }
        iStack_34 = param_1;
        iStack_38 = 0x69e202;
        local_10 = FUN_0069c560();
        iStack_38 = param_2;
        uStack_3c = 0x69e20b;
        local_14 = FUN_0069c560();
        iVar8 = *(int *)(iVar5 + 4);
        iStack_34 = 0x69e21d;
        iVar2 = iVar8 * -4;
        local_18 = &stack0xffffffd0 + iVar2;
        aiStack_54[8 - iVar8] = 0;
        aiStack_54[7 - iVar8] = iVar5;
        aiStack_54[6 - iVar8] = 0x69e228;
        iVar6 = FUN_006a0120();
        iVar4 = local_c;
        cVar3 = (char)local_10;
        aiStack_54[6 - iVar8] = 0;
        aiStack_54[5 - iVar8] = iVar4;
        iVar6 = iVar6 >> (cVar3 + 1U & 0x1f);
        aiStack_54[4 - iVar8] = 0x69e23d;
        FUN_006a0120();
        aiStack_54[4 - iVar8] = 0;
        aiStack_54[3 - iVar8] = param_1 + 0x1e0;
        aiStack_54[2 - iVar8] = 0x69e258;
        uVar7 = FUN_006a3190();
        aiStack_54[2 - iVar8] = 0;
        aiStack_54[1 - iVar8] = param_2 + 0x1e0;
        local_14 = param_2 + 0x1e0;
        aiStack_54[-iVar8] = 0x69e26c;
        local_10 = FUN_006a3190();
        iVar8 = 0;
        puVar10 = &stack0xffffffd0 + iVar2;
        puVar9 = &stack0xffffffd0 + iVar2;
        if (0 < *(int *)(iVar5 + 4)) {
          do {
            *(undefined4 *)(puVar9 + -4) = 0x69e28c;
            iVar2 = iVar6 * -4;
            puVar10 = puVar9 + iVar2;
            *(undefined1 **)(local_18 + iVar8 * 4) = puVar9 + iVar2;
            iVar8 = iVar8 + 1;
            puVar9 = puVar9 + iVar2;
          } while (iVar8 < *(int *)(iVar5 + 4));
        }
        puVar9 = local_18;
        *(int *)(puVar10 + -4) = iVar6;
        *(undefined1 **)(puVar10 + -8) = puVar9;
        *(int *)(puVar10 + -0xc) = param_1 + 0x1e0;
        *(int *)(puVar10 + -0x10) = iVar5;
        *(int *)(puVar10 + -0x14) = param_1;
        *(undefined4 *)(puVar10 + -0x18) = 0x69e2b4;
        FUN_0069dfe0();
        iVar8 = local_14;
        *(undefined4 ***)(puVar10 + -0x18) = &local_1c;
        *(int *)(puVar10 + -0x1c) = iVar8;
        *(undefined4 *)(puVar10 + -0x20) = 0x69e2c1;
        FUN_006a2e40();
        uVar1 = *local_1c;
        *(undefined4 *)(puVar10 + -0x20) = 0;
        *(undefined4 *)(puVar10 + -0x24) = 0;
        *(undefined4 *)(puVar10 + -0x28) = 0;
        *(undefined4 *)(puVar10 + -0x2c) = 0;
        *(int *)(puVar10 + -0x30) = iVar6 * 2;
        *(undefined4 *)(puVar10 + -0x34) = uVar1;
        *(undefined4 *)(puVar10 + -0x38) = 0;
        *(undefined **)(puVar10 + -0x3c) = &DAT_0076f030;
        *(undefined4 *)(puVar10 + -0x40) = 0x69e2df;
        FUN_006a32c0();
        uVar1 = local_1c[1];
        *(undefined4 *)(puVar10 + -0x40) = 0;
        *(undefined4 *)(puVar10 + -0x44) = 0;
        *(undefined4 *)(puVar10 + -0x48) = 0;
        *(undefined4 *)(puVar10 + -0x4c) = 0;
        *(int *)(puVar10 + -0x50) = iVar6 * 2;
        *(undefined4 *)(puVar10 + -0x54) = uVar1;
        *(undefined4 *)(puVar10 + -0x58) = 0;
        *(undefined **)(puVar10 + -0x5c) = &DAT_0076f028;
        *(undefined4 *)(puVar10 + -0x60) = 0x69e2fb;
        FUN_006a32c0();
        iVar8 = local_c;
        *(undefined4 *)(puVar10 + -4) = local_10;
        uVar1 = *(undefined4 *)(iVar8 + 4);
        *(undefined4 *)(puVar10 + -8) = uVar7;
        uVar7 = *(undefined4 *)(iVar5 + 4);
        *(undefined4 *)(puVar10 + -0xc) = uVar1;
        *(undefined4 *)(puVar10 + -0x10) = uVar7;
        *(undefined4 **)(puVar10 + -0x14) = local_1c;
        *(undefined4 *)(puVar10 + -0x18) = 0x69e322;
        FUN_0069dcd0();
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

