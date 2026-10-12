/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x408370; label: FUN_00408370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00408370(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int local_4;
  
  iVar2 = FUN_0055f450();
  if (*(int *)(iVar2 + 0x128) == DAT_0087b0f8) {
    local_4 = 0x2e;
    if (*(char *)(param_1 + 0x104) != -1) {
      param_2 = param_1 + 300;
    }
  }
  else {
    local_4 = (int)*(short *)(param_1 + 0xfc);
  }
  iVar4 = 0;
  do {
    if ((*(uint *)(param_1 + 0xf0) & 0x40000200) == 0) {
      if (param_3 != -1) goto LAB_004083df;
LAB_004083e5:
      iVar1 = param_2 + iVar4 * 0xc;
      FUN_0062c560(*(undefined4 *)(iVar2 + 0x134),local_4,iVar1);
      if ((*(uint *)(param_1 + 0xf0) & 0x10000000) == 0) {
        iVar3 = FUN_0055f2c0(param_1);
        if (iVar3 != 0) {
          FUN_0062c560(*(undefined4 *)(iVar2 + 0x134),local_4,iVar1);
        }
      }
    }
    else {
      if (param_3 == -1) {
        bVar5 = iVar4 == 1;
      }
      else {
LAB_004083df:
        bVar5 = param_3 == iVar4;
      }
      if (bVar5) goto LAB_004083e5;
    }
    iVar4 = iVar4 + 1;
    if (2 < iVar4) {
      if (*(short *)(param_1 + 0xfe) != -1) {
        FUN_00571b60(*(undefined4 *)(iVar2 + 0x138),(int)*(short *)(param_1 + 0xfe),param_1 + 0x88);
      }
      if (*(char *)(param_1 + 0x101) == '\x1d') {
        FUN_0062c560(*(undefined4 *)(iVar2 + 0x134),0x7f,param_1 + 0x88);
        FUN_00571b60(*(undefined4 *)(iVar2 + 0x138),6,param_1 + 0x88);
        FUN_00549bb0(PTR_DAT_008021b4,0x3f400000,0x3f400000,0x3f800000);
        FUN_0054a910(0x3f000000,0,0,0);
      }
      if (((param_5 == 0) && (*(int *)(param_1 + 4) != 0)) &&
         ((*(byte *)(*(int *)(param_1 + 4) + 0x1fc) & 0x80) != 0)) {
        iVar4 = FUN_0056e160(0x12);
        if ((iVar4 != 0) &&
           ((*(int *)(iVar2 + 300) == 0 || ((*(byte *)(*(int *)(iVar2 + 300) + 0x7a) & 1) == 0)))) {
          FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x49,param_1 + 0x88);
          FUN_0054a850(**(undefined4 **)(*(int *)(param_1 + 4) + 0xca4),0x3e99999a,0);
          FUN_00681f40("exp_thermalDet",param_2);
          FUN_00549f10();
          iVar2 = FUN_0056e5f0(param_1 + 0x88,DAT_00950f60 * 0.5,0x3e800000,0,0xffffffff,0xa067);
          if (((iVar2 != 0) &&
              ((((DAT_0093b324 != 0 && (iVar4 = *(int *)(param_1 + 4), iVar4 != 0)) &&
                ((iVar4 == DAT_0093d7f0 || (iVar4 == DAT_0093d7f4)))) &&
               (((*(uint *)(iVar4 + 0x1fc) & 1) != 0 && ((*(uint *)(iVar4 + 0x1fc) & 0x1000) != 0)))
               ))) && ((*(char *)(iVar4 + 0x280) == '\0' || (*(char *)(iVar4 + 0x280) == '\x01'))))
          {
            *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) | 0x10000;
            *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_1 + 4);
          }
        }
      }
      return;
    }
  } while( true );
}

