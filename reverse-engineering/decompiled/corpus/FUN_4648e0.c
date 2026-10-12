/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x4648e0; label: FUN_004648e0
 */

void FUN_004648e0(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int local_8;
  
  iVar7 = 0;
  local_8 = 0;
  bVar1 = true;
  iVar6 = 0;
  iVar2 = FUN_0055f450();
  if (0 < param_4) {
    do {
      iVar3 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar7 * 4),"name=");
      if (iVar3 == 0) {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar7 * 4),&DAT_00757ebc);
        if (iVar3 == 0) {
          bVar1 = true;
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar7 * 4),"FALSE");
          if (iVar3 == 0) {
            bVar1 = false;
          }
          else {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar7 * 4),"buildit=");
            if (((iVar3 != 0) &&
                (piVar4 = (int *)FUN_0055a020(*param_1,DAT_00804e44,iVar3 + 8), piVar4 != (int *)0x0
                )) && (*piVar4 != 0)) {
              iVar6 = *piVar4;
            }
          }
        }
      }
      else {
        local_8 = iVar3 + 5;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_4);
    if (bVar1) {
      if (local_8 != 0) {
        iVar2 = 0;
        uVar5 = 0;
        if (iVar6 != 0) {
          uVar5 = *(undefined2 *)(iVar6 + 0x74);
          iVar2 = iVar6 + 0x34;
        }
        iVar2 = FUN_0041f6d0(local_8,iVar2,uVar5);
        if ((iVar2 == 0) && (iVar6 != 0)) {
          FUN_00590690(iVar6);
          return;
        }
      }
    }
    else if (local_8 != 0) {
      if ((((DAT_0093d7f0 != 0) && ((*(uint *)(DAT_0093d7f0 + 0x1fc) & 0x1000) != 0)) &&
          ((*(char *)(DAT_0093d7f0 + 0x28b) == '\0' &&
           ((*(byte *)(DAT_0093d7f0 + 0x400) != 0xff &&
            (iVar6 = (uint)*(byte *)(DAT_0093d7f0 + 0x400) * 0xa4 +
                     *(int *)(*(int *)(iVar2 + 0x2ae8) + 0x18), iVar6 != 0)))))) &&
         (iVar6 = FUN_004f8b10(iVar6,local_8), iVar6 == 0)) {
        FUN_004882d0(DAT_0093d7f0,0);
      }
      if (((((DAT_0093d7f4 != 0) && ((*(uint *)(DAT_0093d7f4 + 0x1fc) & 0x1000) != 0)) &&
           (*(char *)(DAT_0093d7f4 + 0x28b) == '\0')) &&
          ((*(char *)(DAT_0093d7f4 + 0x400) != -1 &&
           (iVar6 = (uint)*(byte *)(DAT_0093d7f0 + 0x400) * 0xa4 +
                    *(int *)(*(int *)(iVar2 + 0x2ae8) + 0x18), iVar6 != 0)))) &&
         (iVar6 = FUN_004f8b10(iVar6,local_8), iVar6 == 0)) {
        FUN_004882d0(DAT_0093d7f4,0);
      }
      FUN_00414c50(local_8);
    }
  }
  return;
}

