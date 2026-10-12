/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4fa3f0; label: FUN_004fa3f0
 */

void FUN_004fa3f0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int extraout_EDX;
  int iVar7;
  longlong lVar8;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  piVar2 = (int *)FUN_004f98c0(param_1);
  if ((((piVar2 != (int *)0x0) || (piVar2 = (int *)PTR_DAT_00800478, param_3 == 0)) ||
      (param_2 == 1)) ||
     ((param_2 == 2 ||
      (iVar3 = FUN_004f9bd0(param_3,param_1,param_2), piVar2 = (int *)PTR_DAT_00800478, iVar3 == 0))
     )) {
    (*(code *)piVar2[0x8b])(piVar2,local_104,param_1,0x100);
    if (*piVar2 == 2) {
      pcVar6 = ";1";
      pcVar4 = local_104;
      while (local_104[0] != '\0') {
        pcVar4 = pcVar4 + 1;
        local_104[0] = *pcVar4;
      }
      do {
        cVar1 = *pcVar6;
        *pcVar4 = cVar1;
        pcVar4 = pcVar4 + 1;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
    }
    if (*piVar2 == 1) {
      FUN_006dee30(local_104[2] + -0x30,local_104[3] + -0x30,local_104 + piVar2[0x12],param_2,0);
    }
    else {
      iVar3 = FUN_004ff2f0(local_104,param_2);
      if (-1 < iVar3) {
        iVar7 = iVar3 * 0x40;
        _memset(&DAT_008ceb50 + iVar7,0,0x40);
        *(int *)(&DAT_008ceb50 + iVar7) = iVar3;
        *(int *)(&DAT_008ceb84 + iVar7) = param_2;
        if (param_2 == 1) {
          *(undefined4 *)(&DAT_008ceb68 + iVar7) = 0;
          *(undefined4 *)(&DAT_008ceb6c + iVar7) = 0;
        }
        else {
          if (iVar3 < 0x11) {
            iVar3 = iVar3 + 1;
            while( true ) {
              lVar8 = FUN_004f6de0(iVar3,0,0,2);
              if ((0 < (int)((ulonglong)lVar8 >> 0x20)) || (-1 < lVar8)) break;
              if (param_4 == 0) {
                FUN_004ef7b0();
              }
            }
            *(longlong *)(&DAT_008ceb68 + iVar7) = lVar8;
            if (param_2 == 3) {
              do {
                iVar5 = FUN_004f01f0(iVar3);
              } while (iVar5 != 0);
            }
            while( true ) {
              FUN_004f6de0(iVar3,0,0,0);
              if ((0 < extraout_EDX) || (-1 < extraout_EDX)) break;
              if (param_4 == 0) {
                FUN_004ef7b0();
              }
            }
            if (param_2 == 3) {
              do {
                iVar7 = FUN_004f01f0(iVar3);
              } while (iVar7 != 0);
              goto LAB_004fa5d2;
            }
          }
          if (param_2 == 0) {
            *(undefined4 *)(&DAT_008ceb7c + iVar7) = DAT_0091ee90;
          }
        }
      }
    }
  }
LAB_004fa5d2:
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

