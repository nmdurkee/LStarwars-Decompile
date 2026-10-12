/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51fef0; label: FUN_0051fef0
 */

void FUN_0051fef0(int param_1,int param_2,int param_3,float param_4,int param_5,int param_6,
                 float param_7,int param_8)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_10;
  undefined1 local_c [12];
  
  local_10 = 3.4028235e+38;
  iVar3 = -1;
  if ((((param_2 != 0) && (param_3 != 0)) && (*(int *)(param_3 + 4) != 0)) && (param_5 != 0)) {
    if (0.0 < param_4) {
      local_10 = param_4 * param_4;
    }
    if (param_8 != 0) {
      FUN_0051fe60(param_1,param_2);
    }
    iVar5 = 0;
    if ('\0' < *(char *)(param_2 + 0x10)) {
      do {
        if ((param_8 == 0) || (*(char *)(iVar5 + *(int *)(param_2 + 0x18)) == -1)) {
          iVar6 = *(int *)(param_1 + 0x28) +
                  (uint)*(byte *)(*(int *)(param_2 + 0x14) + iVar5) * 0x3c;
          if ((param_7 == 0.0) ||
             (iVar2 = FUN_005d6620(iVar6 + 0x10,param_7,&DAT_00806680), iVar4 = iVar3,
             fVar1 = local_10, iVar2 != 0)) {
            iVar6 = iVar6 + 0x10;
            fVar7 = (float10)FUN_005b3c50(param_5,iVar6,local_c);
            if ((float)fVar7 < local_10) {
              iVar3 = iVar5;
              local_10 = (float)fVar7;
            }
            iVar4 = iVar3;
            fVar1 = local_10;
            if (param_6 != 0) {
              fVar7 = (float10)FUN_005b3c50(param_6,iVar6,local_c);
              iVar4 = iVar5;
              fVar1 = (float)fVar7;
              if (local_10 <= (float)fVar7) goto LAB_00520031;
            }
          }
        }
        else {
LAB_00520031:
          iVar4 = iVar3;
          fVar1 = local_10;
        }
        local_10 = fVar1;
        iVar5 = iVar5 + 1;
        iVar3 = iVar4;
      } while (iVar5 < *(char *)(param_2 + 0x10));
      if (iVar4 != -1) {
        *(uint *)(*(int *)(param_3 + 4) + 0xa4) =
             *(int *)(param_1 + 0x28) + (uint)*(byte *)(*(int *)(param_2 + 0x14) + iVar4) * 0x3c;
        *(undefined1 *)(*(int *)(param_2 + 0x18) + iVar4) = *(undefined1 *)(param_3 + 0x28d);
      }
    }
  }
  return;
}

