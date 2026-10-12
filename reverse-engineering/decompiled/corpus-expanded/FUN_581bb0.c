/* Ghidra pseudocode, not original source.
 * ev_f9aef5a40e02ce8ca7a9836408264f920f991102075b72e653cbe4eaab14c8b7
 * Entry: 0x581bb0; label: FUN_00581bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00581bb0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float10 fVar9;
  float local_98;
  float local_94;
  float local_90;
  int iStack_8c;
  int iStack_88;
  int local_84;
  float afStack_80 [12];
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  undefined1 auStack_40 [64];
  
  local_98 = 0.0;
  local_94 = 0.0;
  local_90 = 0.0;
  pfVar6 = (float *)&DAT_00951db0;
  local_84 = 0x20;
  do {
    if (*(char *)(pfVar6 + 0xe) != '\0') {
      fVar3 = pfVar6[-0x32];
      if (*(code **)((int)fVar3 + 0x54) == (code *)0x0) {
        fVar9 = (float10)pfVar6[-1];
      }
      else {
        fVar9 = (float10)(**(code **)((int)fVar3 + 0x54))(pfVar6 + -0x32);
      }
      fVar1 = (float)fVar9;
      fVar2 = *pfVar6;
      pfVar7 = pfVar6 + -0x20;
      pfVar8 = afStack_80;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *pfVar8 = *pfVar7;
        pfVar7 = pfVar7 + 1;
        pfVar8 = pfVar8 + 1;
      }
      if (*(float *)((int)fVar3 + 0x24) <= fVar2) {
        fVar2 = fVar1;
        if (pfVar6[-1] != 1.0) goto LAB_00581c8c;
      }
      else {
        local_94 = fVar1;
        if ((*(uint *)((int)fVar3 + 0x60) & 0x2000000) == 0) {
          local_94 = fVar1 * (*pfVar6 / *(float *)((int)fVar3 + 0x24));
        }
        fVar2 = local_94;
        if (((uint)pfVar6[10] & 0x200) != 0) {
          fVar1 = local_94;
        }
LAB_00581c8c:
        local_94 = fVar2;
        local_98 = fVar1;
        local_90 = fVar1;
        FUN_005b4c30(afStack_80,&local_98);
      }
      FUN_005b4900(afStack_80,pfVar6 + -0x10);
      iVar5 = FUN_005cfac0((int)fVar3 + 0x68);
      if (iVar5 == 0) {
        iStack_8c = 0;
      }
      else {
        iStack_8c = FUN_005f33b0((int)fVar3 + 0x68,afStack_80);
      }
      iVar5 = FUN_005cfac0((int)fVar3 + 0x74);
      if (iVar5 == 0) {
        iStack_88 = 0;
      }
      else {
        iStack_88 = FUN_005f33b0((int)fVar3 + 0x74,afStack_80);
      }
      if ((pfVar6[8] != 2e+06) &&
         (iVar5 = FUN_005505a0(afStack_80,pfVar6[8],
                               *(undefined4 *)(*(int *)(param_1 + 0x128) + 0xc0),auStack_40),
         iVar5 != 0)) {
        iVar5 = FUN_005cfac0((int)fVar3 + 0x80);
        if (iVar5 != 0) {
          FUN_005f33b0((int)fVar3 + 0x80,auStack_40);
        }
        iVar5 = FUN_005cfac0((int)fVar3 + 0x8c);
        if (iVar5 != 0) {
          FUN_005f33b0((int)fVar3 + 0x8c,auStack_40);
        }
      }
      if (pfVar6[7] != 2e+06) {
        local_90 = local_94;
        local_98 = local_94;
        FUN_005b45a0(afStack_80,&local_98);
        FUN_0057f890();
        uVar4 = FUN_0057f7b0();
        fStack_50 = pfVar6[-0x10];
        fStack_4c = pfVar6[7] + 0.005;
        fStack_48 = pfVar6[-0xe];
        FUN_005f33b0((int)fVar3 + 0x98,uVar4);
      }
      if ((iStack_8c == 0) && (iStack_88 == 0)) {
        if (((DAT_0093b328 == 0) && (*(char *)((int)pfVar6 + 0x3a) != '\0')) &&
           (((uint)pfVar6[10] & 0x20) == 0)) {
          *(undefined1 *)(pfVar6 + 0xe) = 0;
        }
      }
      else {
        *(undefined1 *)((int)pfVar6 + 0x3a) = 1;
      }
    }
    pfVar6 = pfVar6 + 0x4e;
    local_84 = local_84 + -1;
    if (local_84 == 0) {
      return;
    }
  } while( true );
}

