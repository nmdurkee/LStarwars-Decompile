/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aa800; label: FUN_004aa800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004aa800(uint param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  float10 fVar6;
  undefined4 local_8;
  
  iVar3 = param_1;
  if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x40) == 0) {
    return;
  }
  fVar1 = *(float *)(param_1 + 0xd38);
  local_8 = 0;
  if (((((*(char *)(param_1 + 0x283) == '\t') && (*(char *)(param_1 + 0x28b) == '\0')) &&
       (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x19e) != '\0')) &&
      ((iVar4 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x110), iVar4 != -1 &&
       (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar4 * 4) != 0)))) &&
     ((*(float *)(iVar4 * 0x40 + 0x838 + param_1) < *(float *)(param_1 + 0x220) &&
      (((*(float *)(param_1 + 0x224) == 2e+06 ||
        (fVar2 = *(float *)(param_1 + 0x224) - *(float *)(param_1 + 0x220), fVar2 <= 0.0)) ||
       (0.26 <= fVar2)))))) {
    if (*(float *)(param_1 + 0x21c) != 2e+06) {
      param_1 = (uint)(*(float *)(param_1 + 0x220) < *(float *)(param_1 + 0x21c));
      if (0.0 < (float)param_1) {
        if (0.26 <= (float)param_1) {
          local_8 = 0x3f800000;
        }
        goto LAB_004aa8df;
      }
    }
    local_8 = 0x3f800000;
  }
LAB_004aa8df:
  fVar6 = (float10)FUN_0054fad0(*(undefined4 *)(iVar3 + 0xd38),local_8,_DAT_00925018 * 5.0);
  fVar2 = (float)fVar6;
  *(float *)(iVar3 + 0xd38) = fVar2;
  if ((fVar1 != 0.0) || (fVar2 <= 0.0)) {
    if ((fVar1 == 1.0) && (fVar2 < 1.0)) {
      FUN_00681f40("drd_r2_scope_down",iVar3 + 400);
    }
  }
  else {
    FUN_00681f40("drd_r2_scope_up",iVar3 + 400);
  }
  if (*(float *)(iVar3 + 0xdb0) <= 0.0) {
    iVar4 = FUN_0054fa60();
  }
  else {
    fVar1 = *(float *)(iVar3 + 0xdb0) - _DAT_00925018;
    *(float *)(iVar3 + 0xdb0) = fVar1;
    if (fVar1 < 0.0 == (fVar1 == 0.0)) {
      return;
    }
    if (*(char *)(iVar3 + 0x28b) == '\0') {
      pcVar5 = "R2Q501";
      if (*(short *)(iVar3 + 0x1064) != DAT_007f1a18) {
        pcVar5 = "R2D201";
      }
      FUN_00681f40(pcVar5,iVar3 + 0x80);
    }
    iVar4 = FUN_0054fa60();
  }
  *(float *)(iVar3 + 0xdb0) = (float)iVar4 * 1.5259022e-05 * 10.0 + 20.0;
  return;
}

