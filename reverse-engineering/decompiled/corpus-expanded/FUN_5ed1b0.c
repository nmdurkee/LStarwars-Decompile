/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5ed1b0; label: FUN_005ed1b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ed1b0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_404 [4];
  int local_400 [256];
  
  if ((param_2 != 0) && (param_3 != 0)) {
    iVar4 = 0;
    local_400[0] = param_2;
    local_400[1] = 0;
    do {
      iVar2 = local_400[iVar4 * 2];
      iVar1 = iVar2 + 0x10;
      iVar3 = FUN_005d59b0(iVar2,iVar1,&DAT_00806680,*(undefined4 *)(iVar2 + 0x58),1,local_404);
      if (iVar3 == 0) {
LAB_005ed243:
        iVar4 = iVar4 + -1;
      }
      else {
        if (iVar3 == 1) {
          if (DAT_0080b6f0 != 0) {
            FUN_005dc9f0(iVar2,iVar1,&DAT_00806680,0xff0000ff);
          }
          FUN_005d52f0(param_1,*(undefined4 *)(iVar2 + 0x48),1);
          goto LAB_005ed243;
        }
        FUN_005d52f0(param_1,*(undefined4 *)(iVar2 + 0x50),2);
        if ((*(int *)(iVar2 + 0x40) == 0) && (DAT_0080b6f0 != 0)) {
          FUN_005dc9f0(iVar2,iVar1,&DAT_00806680,0xff00ff00);
        }
        iVar3 = local_400[iVar4 * 2 + 1];
        iVar1 = *(int *)(iVar2 + 0x40);
        local_400[iVar4 * 2 + 1] = iVar3 + 1;
        if (iVar3 == iVar1) goto LAB_005ed243;
        iVar1 = *(int *)(iVar2 + 0x20 + iVar3 * 4);
        iVar4 = iVar4 + 1;
        local_400[iVar4 * 2 + 1] = 0;
        local_400[iVar4 * 2] = iVar1;
      }
    } while (-1 < iVar4);
  }
  return;
}

