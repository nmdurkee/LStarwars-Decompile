/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49b9d0; label: FUN_0049b9d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049b9d0(void)

{
  float fVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int unaff_ESI;
  float10 extraout_ST0;
  float10 fVar5;
  float10 extraout_ST1;
  float local_8;
  
  if (*(char *)(unaff_ESI + 0x7b5) != ',') {
    return;
  }
  if ((DAT_0087afb0 == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087afb0)) {
    if ((DAT_0087b018 == 0) ||
       ((*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b018 || (*(int *)(unaff_ESI + 0x36c) == 0)))) {
      fVar5 = (float10)FUN_00498480();
      local_8 = (float)fVar5;
      if (local_8 == 2e+06) {
        local_8 = 0.0;
      }
    }
    else {
      local_8 = *(float *)(*(int *)(unaff_ESI + 0x36c) + 0x14) + _DAT_0087b8fc;
    }
  }
  else {
    local_8 = -1.5;
  }
  cVar2 = *(char *)(unaff_ESI + 0x7b3);
  *(undefined1 *)(unaff_ESI + 0x107a) = 0;
  if (cVar2 == '\0') {
    if (local_8 < *(float *)(unaff_ESI + 0x60) == (local_8 == *(float *)(unaff_ESI + 0x60))) {
      *(undefined4 *)(unaff_ESI + 0x6c) = 0;
      *(undefined4 *)(unaff_ESI + 0x68) = 0;
      *(undefined2 *)(unaff_ESI + 0x278) = 0xc000;
      *(undefined2 *)(unaff_ESI + 0x27c) = 0;
      *(float *)(unaff_ESI + 0x70) =
           *(float *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x1c) * 0.5;
      goto LAB_0049ba85;
    }
    *(undefined1 *)(unaff_ESI + 0x7b3) = 1;
  }
  else if (cVar2 != '\x01') {
    if (cVar2 == '\x02') {
      fVar1 = *(float *)(unaff_ESI + 0x77c) + _DAT_00925018;
      *(float *)(unaff_ESI + 0x77c) = fVar1;
      if (1.0 <= fVar1) {
        *(undefined1 *)(unaff_ESI + 0x7b5) = 0xff;
        fVar1 = 1.0;
      }
      *(undefined4 *)(unaff_ESI + 0x68) = 0;
      *(undefined2 *)(unaff_ESI + 0x278) = 0;
      *(undefined4 *)(unaff_ESI + 0x6c) = 0;
      *(undefined2 *)(unaff_ESI + 0x27c) = 0;
      iVar4 = *(int *)(*(int *)(unaff_ESI + 0x54) + 0x24);
      *(float *)(unaff_ESI + 0x70) =
           fVar1 * *(float *)(iVar4 + 0x1c) + *(float *)(iVar4 + 0x1c) * 0.5 * (1.0 - fVar1);
      iVar4 = FUN_006e6b90();
      fVar5 = (float10)(float)(extraout_ST0 -
                              ((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + extraout_ST0)
                              * extraout_ST1);
      *(float *)(unaff_ESI + 0x60) =
           (float)(fVar5 * (float10)local_8 +
                  (float10)*(float *)(unaff_ESI + 0x758) * (extraout_ST0 - fVar5));
    }
    else {
      *(undefined1 *)(unaff_ESI + 0x7b5) = 0xff;
    }
    goto LAB_0049ba85;
  }
  sVar3 = FUN_00550100(*(undefined2 *)(unaff_ESI + 0x278),0,0x10000,0);
  *(short *)(unaff_ESI + 0x278) = sVar3;
  *(undefined4 *)(unaff_ESI + 0x6c) = 0;
  *(undefined2 *)(unaff_ESI + 0x27c) = 0;
  *(undefined4 *)(unaff_ESI + 0x68) = 0;
  *(float *)(unaff_ESI + 0x70) =
       *(float *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x1c) * 0.5;
  if (sVar3 == 0) {
    *(undefined1 *)(unaff_ESI + 0x7b3) = 2;
    *(undefined4 *)(unaff_ESI + 0x758) = *(undefined4 *)(unaff_ESI + 0x60);
    *(undefined4 *)(unaff_ESI + 0x77c) = 0;
  }
LAB_0049ba85:
  iVar4 = unaff_ESI + 0x68;
  FUN_005b35a0(iVar4,iVar4,*(undefined2 *)(unaff_ESI + 0x278));
  FUN_005b3620(iVar4,iVar4,*(undefined2 *)(unaff_ESI + 0x27a));
  return;
}

