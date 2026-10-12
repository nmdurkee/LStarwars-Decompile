/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x505820; label: FUN_00505820
 */

void FUN_00505820(char *param_1,uint *param_2,uint *param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *local_408;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_408;
  uVar9 = *param_3;
  uVar2 = *param_2;
  local_408 = param_3;
  pcVar6 = param_1;
  do {
    cVar1 = *pcVar6;
    pcVar6[(int)(local_404 + -(int)param_1)] = cVar1;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar7 = uVar2 + 0xf & 0xfffffff0;
  *param_2 = uVar7;
  iVar8 = FUN_004fd5d0(local_404,uVar7,uVar9 - uVar2);
  if (iVar8 == 0) goto LAB_005059a2;
  piVar3 = (int *)*param_2;
  iVar4 = *piVar3;
  if (iVar4 < 10) {
    if (2 < iVar4) {
      FUN_004fff00(param_1,iVar4);
    }
    piVar3[1] = (int)piVar3 - piVar3[1];
    if (((*piVar3 < 2) || (piVar3[10] = (int)piVar3 - piVar3[10], *piVar3 < 2)) ||
       ((*(byte *)(piVar3 + 0xe) & 8) == 0)) {
      FUN_00505780(0);
      if (((1 < *piVar3) && ((*(byte *)(piVar3 + 0xe) & 1) != 0)) && (param_4 == 0)) {
        iVar8 = 0;
        if (((piVar3[4] != 0) && (iVar4 = *(int *)(piVar3[4] + 8), iVar4 != 0)) ||
           ((((int *)piVar3[5] != (int *)0x0 &&
             (iVar4 = *(int *)(*(int *)piVar3[5] + 0x4c), iVar4 != 0)) ||
            ((((piVar5 = (int *)piVar3[6], iVar10 = iVar8, piVar5 != (int *)0x0 &&
               (iVar10 = *(int *)(*piVar5 + 0x44), iVar10 == 0)) &&
              (iVar10 = iVar8, piVar5 != (int *)0x0)) &&
             (iVar4 = *(int *)(*piVar5 + 0x48), *(int *)(*piVar5 + 0x48) != 0)))))) {
          iVar10 = iVar4;
        }
        if (piVar3[0x13] != 0) {
          iVar10 = *param_2 + piVar3[0x13];
        }
        piVar3[0xc] = iVar10 + 0xfU & 0xfffffff0;
        uVar9 = (iVar10 + 0xfU & 0xfffffff0) + 0x400 + piVar3[0xf];
        if (DAT_00800890 == 0) {
          piVar3[0xd] = uVar9 + 0xf & 0xfffffff0;
          uVar9 = (uVar9 + 0xf & 0xfffffff0) + 0x400 + piVar3[0xf];
        }
        *param_2 = uVar9;
        iVar8 = FUN_004f1ff0(param_1);
        uVar9 = *param_2;
        *param_2 = uVar9 + 4 + iVar8;
        FUN_004f1f10(uVar9,param_1);
        piVar3[0xb] = uVar9;
        goto LAB_00505988;
      }
    }
    else {
      FUN_00505780(0);
    }
    *param_2 = *param_2 + iVar8;
  }
  else {
    piVar3[0x16] = iVar8;
    piVar3[1] = (int)piVar3 - piVar3[1];
    piVar3[10] = (int)piVar3 - piVar3[10];
    if ((*(byte *)(piVar3 + 0xe) & 8) == 0) {
      FUN_00505780(0);
      if (((*(byte *)(piVar3 + 0xe) & 1) != 0) && (param_4 == 0)) {
        uVar9 = piVar3[0x13] + *param_2 + 0xf;
        piVar3[0xc] = uVar9 & 0xfffffff0;
        uVar9 = (uVar9 & 0xfffffff0) + 0x400 + piVar3[0xf];
        if (DAT_00800890 == 0) {
          piVar3[0xd] = uVar9 + 0xf & 0xfffffff0;
          uVar9 = (uVar9 + 0xf & 0xfffffff0) + 0x400 + piVar3[0xf];
        }
        *param_2 = uVar9;
        iVar8 = FUN_004f1ff0(param_1);
        uVar9 = *param_2;
        *param_2 = uVar9 + 4 + iVar8;
        FUN_004f1f10(uVar9,param_1);
        piVar3[0xb] = uVar9;
        FUN_00500140(piVar3,param_2);
        goto LAB_00505988;
      }
    }
    else {
      FUN_00505780(0);
    }
    *param_2 = *param_2 + iVar8;
    FUN_00500140(piVar3,param_2);
  }
LAB_00505988:
  if (*local_408 < *param_2) {
    FUN_004fff00(param_1,*param_2 - *local_408);
  }
LAB_005059a2:
  __security_check_cookie(local_4 ^ (uint)&local_408);
  return;
}

