/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4a9f60; label: FUN_004a9f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a9f60(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  if (((((*(char *)(param_1 + 0x28b) == '\0') && (*(char *)(param_1 + 0x7b5) == '\0')) &&
       (*(char *)(param_1 + 0x288) != '\0')) && (*(char *)(param_1 + 0x28c) != '\0')) &&
     ((*(char *)(param_1 + 0xe32) != '\x03' ||
      ((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_00802278) != 0)))) {
    if (*(char *)(param_1 + 0xe32) == '\x03') {
      uVar1 = 0x3e800000;
    }
    else {
      uVar1 = 0x3f800000;
    }
    iVar3 = FUN_0062c300(uVar1,_DAT_00925018);
    if (0 < iVar3) {
      cVar2 = (*(short *)(param_1 + 0x1064) == DAT_007f1a18) + '\v';
      if (*(int *)(*(int *)(param_1 + 0x50) + 0x1c) != 0) {
        FUN_0062c680(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),cVar2,param_1 + 0x8b4,iVar3,0x71c7,
                     *(undefined2 *)(param_1 + 0x58));
      }
      if (*(int *)(*(int *)(param_1 + 0x50) + 0x20) != 0) {
        FUN_0062c680(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),cVar2,param_1 + 0x8f4,iVar3,0x8e38,
                     *(undefined2 *)(param_1 + 0x58));
      }
    }
    if (*(char *)(param_1 + 0xe32) == '\x03') {
      uVar1 = 0x3f000000;
    }
    else {
      uVar1 = 0x3f800000;
    }
    FUN_00651470("R2Thrust",param_1 + 0x80,uVar1);
  }
  else if ((*(char *)(param_1 + 0x7b5) == -1) &&
          (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28))) {
    if (*(float *)(param_1 + 0xd38) <= 0.0) {
      if (*(char *)(param_1 + 0x281) != '\0') {
        FUN_00681f40("R2Move",param_1 + 0x80);
      }
    }
    else {
      FUN_00681f40("drd_r2_mvt_water_lp",param_1 + 400);
    }
  }
  if (((0.0 < *(float *)(param_1 + 0xd38)) && (*(float *)(param_1 + 0xd38) < 1.0)) &&
     ((iVar3 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) +
                       ((uint)(*(short *)(param_1 + 0x1064) != DAT_007f1a18) * 2 + 1) * 0x14),
      iVar3 != -1 &&
      ((iVar4 = FUN_0062c350(0x42c80000,_DAT_00925018), 0 < iVar4 &&
       (iVar5 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x110), iVar5 != -1))))))
  {
    iVar5 = iVar5 * 0x40;
    local_c = *(undefined4 *)(iVar5 + 0x834 + param_1);
    iVar5 = iVar5 + 0x834 + param_1;
    local_8 = *(float *)(iVar5 + 4);
    local_4 = *(undefined4 *)(iVar5 + 8);
    if ((*(char *)(param_1 + 0x283) == '\t') && (local_8 < *(float *)(param_1 + 0x220))) {
      local_8 = *(float *)(param_1 + 0x220);
    }
    FUN_00684c90(iVar3,&local_c,iVar4,0,0);
  }
  return;
}

