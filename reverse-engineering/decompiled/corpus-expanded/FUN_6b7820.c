/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b7820; label: FUN_006b7820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_006b7820(int param_1,int param_2,int param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  float *pfVar12;
  float10 fVar13;
  uint auStack_64 [3];
  size_t asStack_58 [2];
  uint auStack_50 [2];
  size_t asStack_48 [2];
  undefined1 auStack_40 [4];
  float afStack_3c [2];
  undefined4 uStack_34;
  float *local_1c;
  float *local_18;
  int local_8;
  
  uVar9 = param_3 + 1 >> 1;
  iVar1 = uVar9 * 4 + 4;
  uStack_34 = 0x6b7842;
  iVar11 = -iVar1;
  *(undefined4 *)((int)&uStack_34 + iVar11) = 0x6b784c;
  *(undefined4 *)((int)&uStack_34 + iVar1 * -2) = 0x6b7856;
  *(undefined4 *)((int)&uStack_34 + iVar1 * -3) = 0x6b7860;
  *(undefined4 *)(&stack0xffffffd0 + uVar9 * 4 + iVar11) = 0x3f800000;
  uVar8 = param_3 >> 1;
  local_8 = 1;
  if (3 < (int)uVar9) {
    uVar10 = uVar9 >> 2;
    local_8 = uVar10 * 4 + 1;
    pfVar12 = (float *)(param_1 + 8);
    pfVar5 = (float *)(param_1 + -0xc + param_3 * 4);
    pfVar7 = (float *)((int)afStack_3c + uVar9 * 4 + iVar11);
    do {
      uVar10 = uVar10 - 1;
      pfVar7[2] = pfVar5[2] + pfVar12[-2];
      pfVar7[1] = pfVar5[1] + pfVar12[-1];
      *pfVar7 = *pfVar5 + *pfVar12;
      pfVar7[-1] = pfVar5[-1] + pfVar12[1];
      pfVar12 = pfVar12 + 4;
      pfVar5 = pfVar5 + -4;
      pfVar7 = pfVar7 + -4;
    } while (uVar10 != 0);
  }
  if (local_8 <= (int)uVar9) {
    local_18 = (float *)(param_1 + -4 + local_8 * 4);
    iVar6 = uVar9 - local_8;
    iVar4 = param_3 - local_8;
    local_8 = iVar6 + 1;
    pfVar12 = (float *)(param_1 + iVar4 * 4);
    local_1c = (float *)(&stack0xffffffd0 + iVar6 * 4 + iVar11);
    do {
      fVar2 = *pfVar12;
      fVar3 = *local_18;
      local_18 = local_18 + 1;
      pfVar12 = pfVar12 + -1;
      *local_1c = fVar2 + fVar3;
      local_8 = local_8 + -1;
      local_1c = local_1c + -1;
    } while (local_8 != 0);
  }
  *(undefined4 *)(&stack0xffffffd0 + uVar8 * 4 + iVar1 * -2) = 0x3f800000;
  local_8 = 1;
  if (3 < (int)uVar8) {
    uVar10 = uVar8 >> 2;
    local_8 = uVar10 * 4 + 1;
    pfVar12 = (float *)(param_1 + 8);
    pfVar5 = (float *)(param_1 + -0xc + param_3 * 4);
    pfVar7 = (float *)((int)afStack_3c + uVar8 * 4 + iVar1 * -2);
    do {
      uVar10 = uVar10 - 1;
      pfVar7[2] = pfVar12[-2] - pfVar5[2];
      pfVar7[1] = pfVar12[-1] - pfVar5[1];
      *pfVar7 = *pfVar12 - *pfVar5;
      pfVar7[-1] = pfVar12[1] - pfVar5[-1];
      pfVar12 = pfVar12 + 4;
      pfVar5 = pfVar5 + -4;
      pfVar7 = pfVar7 + -4;
    } while (uVar10 != 0);
  }
  if (local_8 <= (int)uVar8) {
    pfVar5 = (float *)(param_1 + -4 + local_8 * 4);
    pfVar12 = (float *)(param_1 + (param_3 - local_8) * 4);
    iVar4 = (uVar8 - local_8) + 1;
    pfVar7 = (float *)(&stack0xffffffd0 + (uVar8 - local_8) * 4 + iVar1 * -2);
    do {
      fVar2 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      fVar3 = *pfVar12;
      pfVar12 = pfVar12 + -1;
      iVar4 = iVar4 + -1;
      *pfVar7 = fVar2 - fVar3;
      pfVar7 = pfVar7 + -1;
    } while (iVar4 != 0);
  }
  if ((int)uVar8 < (int)uVar9) {
    iVar4 = 2;
    if (3 < (int)(uVar8 - 1)) {
      uVar10 = uVar8 - 1 >> 2;
      iVar4 = uVar10 * 4 + 2;
      pfVar12 = (float *)((int)afStack_3c + uVar8 * 4 + iVar1 * -2);
      do {
        uVar10 = uVar10 - 1;
        fVar2 = pfVar12[1];
        pfVar12[1] = pfVar12[3] + fVar2;
        fVar3 = *pfVar12;
        *pfVar12 = fVar3 + pfVar12[2];
        pfVar12[-1] = pfVar12[-1] + pfVar12[3] + fVar2;
        pfVar12[-2] = fVar3 + pfVar12[2] + pfVar12[-2];
        pfVar12 = pfVar12 + -4;
      } while (uVar10 != 0);
    }
    if (iVar4 <= (int)uVar8) {
      iVar6 = (uVar8 - iVar4) + 1;
      pfVar12 = (float *)(&stack0xffffffd0 + (uVar8 - iVar4) * 4 + iVar1 * -2);
      do {
        iVar6 = iVar6 + -1;
        *pfVar12 = pfVar12[2] + *pfVar12;
        pfVar12 = pfVar12 + -1;
      } while (iVar6 != 0);
    }
  }
  else {
    iVar4 = 1;
    if (3 < (int)uVar9) {
      uVar10 = uVar9 >> 2;
      iVar4 = uVar10 * 4 + 1;
      pfVar12 = (float *)((int)afStack_3c + uVar9 * 4 + iVar11 + 4);
      do {
        fVar2 = pfVar12[1];
        uVar10 = uVar10 - 1;
        pfVar12[1] = fVar2 - pfVar12[2];
        fVar2 = *pfVar12 - (fVar2 - pfVar12[2]);
        *pfVar12 = fVar2;
        fVar2 = pfVar12[-1] - fVar2;
        pfVar12[-1] = fVar2;
        pfVar12[-2] = pfVar12[-2] - fVar2;
        pfVar12 = pfVar12 + -4;
      } while (uVar10 != 0);
    }
    if (iVar4 <= (int)uVar9) {
      iVar6 = (uVar9 - iVar4) + 1;
      pfVar12 = (float *)(&stack0xffffffd0 + (uVar9 - iVar4) * 4 + iVar11);
      do {
        iVar6 = iVar6 + -1;
        *pfVar12 = *pfVar12 - pfVar12[1];
        pfVar12 = pfVar12 + -1;
      } while (iVar6 != 0);
    }
    iVar4 = 1;
    if (3 < (int)uVar8) {
      uVar10 = uVar8 >> 2;
      iVar4 = uVar10 * 4 + 1;
      pfVar12 = (float *)((int)afStack_3c + uVar8 * 4 + iVar1 * -2 + 4);
      do {
        uVar10 = uVar10 - 1;
        fVar2 = pfVar12[1];
        pfVar12[1] = pfVar12[2] + fVar2;
        fVar2 = pfVar12[2] + fVar2 + *pfVar12;
        *pfVar12 = fVar2;
        fVar2 = fVar2 + pfVar12[-1];
        pfVar12[-1] = fVar2;
        pfVar12[-2] = fVar2 + pfVar12[-2];
        pfVar12 = pfVar12 + -4;
      } while (uVar10 != 0);
    }
    if (iVar4 <= (int)uVar8) {
      iVar6 = (uVar8 - iVar4) + 1;
      pfVar12 = (float *)(&stack0xffffffd0 + (uVar8 - iVar4) * 4 + iVar1 * -2);
      do {
        iVar6 = iVar6 + -1;
        *pfVar12 = pfVar12[1] + *pfVar12;
        pfVar12 = pfVar12 + -1;
      } while (iVar6 != 0);
    }
  }
  *(undefined4 *)((int)&uStack_34 + iVar1 * -4) = 0x6b7b51;
  FUN_006b7260();
  *(undefined4 *)((int)&uStack_34 + iVar1 * -4) = 0x6b7b5b;
  FUN_006b7260();
  *(undefined1 **)((int)&uStack_34 + iVar1 * -4) = &stack0xffffffd0 + iVar1 * -3;
  afStack_3c[1 - iVar1] = (float)(&stack0xffffffd0 + iVar11);
  afStack_3c[-iVar1] = 9.870675e-39;
  iVar4 = FUN_006b7370();
  if (iVar4 == 0) {
    *(undefined1 **)((int)&uStack_34 + iVar1 * -4) = &stack0xffffffd0 + iVar1 * -4;
    afStack_3c[1 - iVar1] = (float)(&stack0xffffffd0 + iVar1 * -2);
    afStack_3c[-iVar1] = 9.870711e-39;
    iVar4 = FUN_006b7370();
    if (iVar4 == 0) {
      *(undefined1 **)((int)&uStack_34 + iVar1 * -4) = &stack0xffffffd0 + iVar1 * -3;
      afStack_3c[1 - iVar1] = (float)(&stack0xffffffd0 + iVar11);
      afStack_3c[-iVar1] = 9.870744e-39;
      FUN_006b7650();
      afStack_3c[-iVar1] = (float)(&stack0xffffffd0 + iVar1 * -4);
      *(undefined1 **)(auStack_40 + iVar1 * -4) = &stack0xffffffd0 + iVar1 * -2;
      asStack_48[1 - iVar1] = 0x6b7bad;
      FUN_006b7650();
      asStack_48[1 - iVar1] = (size_t)FUN_006b7330;
      asStack_48[-iVar1] = 4;
      auStack_50[1 - iVar1] = uVar9;
      auStack_50[-iVar1] = (uint)(&stack0xffffffd0 + iVar1 * -3);
      asStack_58[1 - iVar1] = 0x6b7bbe;
      _qsort((void *)auStack_50[-iVar1],auStack_50[1 - iVar1],asStack_48[-iVar1],
             (_PtFuncCompare *)asStack_48[1 - iVar1]);
      asStack_58[1 - iVar1] = (size_t)FUN_006b7330;
      asStack_58[-iVar1] = 4;
      auStack_64[2 - iVar1] = uVar8;
      auStack_64[1 - iVar1] = (uint)(&stack0xffffffd0 + iVar1 * -4);
      auStack_64[-iVar1] = 0x6b7bcf;
      _qsort((void *)auStack_64[1 - iVar1],auStack_64[2 - iVar1],asStack_58[-iVar1],
             (_PtFuncCompare *)asStack_58[1 - iVar1]);
      iVar11 = 0;
      if (0 < (int)uVar9) {
        do {
          *(undefined4 *)((int)&uStack_34 + iVar1 * -4) = 0x6b7beb;
          fVar13 = (float10)FUN_006ec300();
          *(float *)(param_2 + iVar11 * 8) = (float)fVar13;
          iVar11 = iVar11 + 1;
        } while (iVar11 < (int)uVar9);
      }
      iVar11 = 0;
      if (0 < (int)uVar8) {
        pfVar12 = (float *)(param_2 + 4);
        do {
          *(undefined4 *)((int)&uStack_34 + iVar1 * -4) = 0x6b7c0f;
          fVar13 = (float10)FUN_006ec300();
          *pfVar12 = (float)fVar13;
          iVar11 = iVar11 + 1;
          pfVar12 = pfVar12 + 2;
        } while (iVar11 < (int)uVar8);
      }
      return 0;
    }
  }
  return 0xffffffff;
}

