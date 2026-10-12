/* Ghidra pseudocode, not original source.
 * ev_de7bd3aa239ec0c059aa1bbec058a25d35da9446e5dffd1cda86600a1f15d21b
 * Entry: 0x6586b0; label: FUN_006586b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006586b0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = param_1 * 0x330 + DAT_029620a4;
  iVar2 = *(int *)(DAT_0296209c + *(short *)(param_1 * 0x330 + 0x182 + DAT_029620a4) * 4);
  if (iVar2 != 0) {
    *param_2 = *(undefined4 *)(iVar3 + 400);
    param_2[1] = *(undefined4 *)(iVar3 + 0x194);
    param_2[2] = *(undefined4 *)(iVar3 + 0x198);
    local_4 = 0;
    local_c = 0;
    if (*(char *)(iVar2 + 0x2c) == '\v') {
      local_8 = 0x3f800000;
    }
    else {
      local_8 = 0;
      local_4 = 0x3f800000;
    }
    FUN_005b30a0(&local_c,&local_c,iVar3 + 0x80);
    *param_3 = local_c;
    param_3[1] = local_8;
    param_3[2] = local_4;
    cVar1 = *(char *)(iVar2 + 0x2c);
    if (((cVar1 == '\x06') || (cVar1 == '\a')) || (cVar1 == '\v')) {
      *param_4 = *(undefined4 *)(iVar2 + 0x58);
      return 1;
    }
    *param_4 = 0;
  }
  return 0;
}

