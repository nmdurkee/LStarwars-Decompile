/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x610ae0; label: FUN_00610ae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00610ae0(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  uVar4 = 0;
  if (*(char *)(in_ECX + 0x10) == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00610bde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (**(code **)(*DAT_028572e0 + 0x5c))();
    return uVar4;
  }
  if (*(int *)(in_ECX + 0x17b4) <= *(int *)(in_ECX + 0x17b0)) {
    uVar4 = (**(code **)(*DAT_028572e0 + 0x5c))(in_ECX + 0x40,3000,param_3);
    if (0 < (int)uVar4) {
      *(int *)(in_ECX + 0x19f8) = *(int *)(in_ECX + 0x19f8) + uVar4;
      *(int *)(in_ECX + 0x1a00) = *(int *)(in_ECX + 0x1a00) + 1;
      *(undefined4 *)(in_ECX + 0x17b0) = 0;
      *(uint *)(in_ECX + 0x17b8) = uVar4;
      iVar1 = FUN_006179c0();
      uVar2 = FUN_00617a60(in_ECX + 0x40,in_ECX + 0xbf8);
      *(undefined4 *)(in_ECX + 0x17b4) = uVar2;
      iVar3 = FUN_006179c0();
      *(int *)(in_ECX + 0x17d8) = *(int *)(in_ECX + 0x17d8) + *(int *)(in_ECX + 0x17b4);
      *(int *)(in_ECX + 0x1c10) = *(int *)(in_ECX + 0x1c10) + (iVar3 - iVar1);
      *(int *)(in_ECX + 0x17e0) = *(int *)(in_ECX + 0x17e0) + 1;
    }
  }
  iVar1 = *(int *)(in_ECX + 0x17b0);
  if ((iVar1 < *(int *)(in_ECX + 0x17b4)) && (-1 < (int)uVar4)) {
    uVar4 = (uint)CONCAT11(*(undefined1 *)(iVar1 + 0xbf9 + in_ECX),
                           *(undefined1 *)(iVar1 + 0xbf8 + in_ECX));
    if ((int)uVar4 < (int)param_2) {
      param_2 = uVar4;
    }
    FUN_004ef660(param_1,iVar1 + 0xbfa + in_ECX,param_2);
    *(int *)(in_ECX + 0x17b0) = *(int *)(in_ECX + 0x17b0) + uVar4 + 2;
    return param_2;
  }
  return uVar4;
}

