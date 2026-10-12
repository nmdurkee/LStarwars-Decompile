/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x694930; label: FUN_00694930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00694930(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint *in_ECX;
  uint uVar5;
  int iVar6;
  
  uVar5 = *param_2;
  in_ECX[0x4b] = uVar5;
  in_ECX[0x4a] = uVar5;
  *param_2 = *param_2 + 0x10000;
  *in_ECX = *param_2 + 3 & 0xfffffffc;
  uVar3 = *param_2 + 3 & 0xfffffffc;
  *param_2 = uVar3 + 0x4800;
  in_ECX[2] = uVar3 + 0x4800;
  uVar3 = *param_2 + 3 & 0xfffffffc;
  *param_2 = uVar3 + 0x1e000;
  in_ECX[4] = uVar3 + 0x1e000;
  *param_2 = (*param_2 + 3 & 0xfffffffc) + 0x2000;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[5] = 0;
  FUN_004f1200(0);
  iVar4 = FUN_004fc860(param_1);
  if (iVar4 != 0) {
    FUN_004f1120(iVar4,&PTR_s_ALBUM_00810c90);
    FUN_004fc5b0(iVar4);
    cVar2 = **(char **)(iVar4 + 0x50c);
    while (cVar2 != '\0') {
      FUN_004f7fb0(iVar4);
      FUN_004fa180(iVar4);
      FUN_004fc5b0(iVar4);
      cVar2 = **(char **)(iVar4 + 0x50c);
    }
    FUN_004fa300(iVar4);
  }
  FUN_004f1200(0);
  if ((in_ECX[1] != 0) && (in_ECX[3] != 0)) {
    uVar5 = in_ECX[0x4b] + 3 & 0xfffffffc;
    if (uVar5 != *in_ECX) {
      FUN_004ef660(uVar5,*in_ECX,in_ECX[1] * 0x24);
      *in_ECX = uVar5;
    }
    uVar5 = in_ECX[2];
    uVar3 = *in_ECX + 3 + in_ECX[1] * 0x24 & 0xfffffffc;
    if (uVar3 != uVar5) {
      if (in_ECX[3] != 0) {
        FUN_004ef660(uVar3,uVar5,in_ECX[3] * 0x3c);
      }
      iVar4 = 0;
      in_ECX[2] = uVar3;
      if (0 < (int)in_ECX[1]) {
        iVar6 = 0;
        do {
          piVar1 = (int *)(iVar6 + 4 + *in_ECX);
          if (*(int *)(iVar6 + 4 + *in_ECX) != 0) {
            *piVar1 = *piVar1 + (uVar3 - uVar5);
          }
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 0x24;
        } while (iVar4 < (int)in_ECX[1]);
      }
    }
    uVar5 = in_ECX[4];
    uVar3 = in_ECX[2] + 3 + in_ECX[3] * 0x3c & 0xfffffffc;
    if (uVar3 != uVar5) {
      if (in_ECX[5] != 0) {
        FUN_004ef660(uVar3,uVar5,in_ECX[5] * 4);
      }
      iVar4 = 0;
      in_ECX[4] = uVar3;
      if (0 < (int)in_ECX[3]) {
        iVar6 = 0;
        do {
          piVar1 = (int *)(iVar6 + 0x18 + in_ECX[2]);
          if (*(int *)(iVar6 + 0x18 + in_ECX[2]) != 0) {
            *piVar1 = *piVar1 + (uVar3 - uVar5);
          }
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 0x3c;
        } while (iVar4 < (int)in_ECX[3]);
      }
    }
    iVar4 = 0;
    *param_2 = in_ECX[4] + in_ECX[5] * 4;
    if (0 < (int)in_ECX[1]) {
      do {
        FUN_00693f50();
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)in_ECX[1]);
    }
    FUN_00694840(param_2,param_3);
    return;
  }
  *param_2 = uVar5;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}

