/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43cca0; label: FUN_0043cca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0043cca0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7
                ,int param_8,undefined4 param_9)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  byte local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar9 = 0;
  iVar8 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (param_4 == 0) {
    return 0;
  }
  if (param_5 == 0) {
    return 0;
  }
  iVar3 = FUN_0051adf0(param_2,param_3,param_4,param_5,local_10);
  if (iVar3 == 0) goto switchD_0043cd0f_default;
  switch(param_6) {
  case 0:
    if (param_7 != 0) {
      FUN_005cf5b0(*(undefined4 *)(param_2 + 0x1394),&local_c,param_7,1);
    }
    break;
  case 1:
    iVar8 = FUN_0057c920(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),param_7);
    goto LAB_0043ce37;
  case 2:
    iVar8 = FUN_0058e980(PTR_DAT_00802c54,param_7);
    goto LAB_0043ce37;
  case 3:
    iVar8 = FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),0xffffffff,param_7);
    goto LAB_0043ce37;
  case 4:
    uVar4 = DAT_00802f54;
    goto LAB_0043ce16;
  case 5:
    if ((param_8 < 0) || (0 < param_8)) {
      return 0;
    }
    break;
  case 6:
    iVar8 = FUN_0059f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2acc),param_7);
LAB_0043ce37:
    if (iVar8 == 0) break;
    goto LAB_0043ce57;
  case 7:
    uVar10 = *(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8);
    uVar4 = DAT_007f8cc4;
    goto LAB_0043ce29;
  case 8:
    uVar10 = *(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8);
    uVar4 = DAT_00802644;
    goto LAB_0043ce29;
  case 9:
    uVar4 = DAT_007ffc20;
LAB_0043ce16:
    uVar10 = *(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8);
LAB_0043ce29:
    piVar5 = (int *)FUN_0055a020(uVar10,uVar4,param_7);
    if (piVar5 != (int *)0x0) {
      iVar8 = *piVar5;
      goto LAB_0043ce37;
    }
  }
switchD_0043cd0f_default:
  iVar6 = FUN_005cfac0(&local_c);
  if ((iVar6 != 0) || (param_6 == 5)) {
LAB_0043ce57:
    iVar9 = FUN_004f1440(param_1 + 8);
    if (iVar9 != 0) {
      FUN_004f1410(param_1 + 8,iVar9);
      FUN_004f1310(param_1 + 0x10,iVar9);
      bVar1 = **(byte **)(param_2 + 0x10);
      uVar7 = 0;
      if (bVar1 != 0) {
        do {
          if (*(int *)(*(int *)(*(byte **)(param_2 + 0x10) + 4) + uVar7 * 4) == param_3) {
            *(char *)(iVar9 + 0xa5) = (char)uVar7;
            break;
          }
          bVar2 = (char)uVar7 + 1;
          uVar7 = (uint)bVar2;
        } while (bVar2 < bVar1);
      }
      *(int *)(iVar9 + 8) = iVar3;
      *(undefined4 *)(iVar9 + 0x18) = param_9;
      *(ushort *)(iVar9 + 0xa6) =
           *(ushort *)(iVar9 + 0xa6) ^ (*(byte *)(iVar9 + 0xa6) ^ local_10[0]) & 1;
      if (iVar8 != 0) {
        *(int *)(iVar9 + 0xc) = iVar8;
        *(undefined1 *)(iVar9 + 0xa4) = (undefined1)param_6;
        return iVar9;
      }
      iVar8 = FUN_005cfac0(&local_c);
      if (iVar8 != 0) {
        *(undefined4 *)(iVar9 + 0xc) = local_c;
        *(undefined4 *)(iVar9 + 0x10) = local_8;
        *(undefined4 *)(iVar9 + 0x14) = local_4;
        *(undefined1 *)(iVar9 + 0xa4) = (undefined1)param_6;
        return iVar9;
      }
      *(int *)(iVar9 + 0xc) = param_8;
      *(undefined1 *)(iVar9 + 0xa4) = (undefined1)param_6;
    }
  }
  return iVar9;
}

