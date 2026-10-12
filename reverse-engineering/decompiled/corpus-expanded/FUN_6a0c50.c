/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a0c50; label: FUN_006a0c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a0c50(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 == 0) {
    return 0xffffff7f;
  }
  FUN_006a3570();
  iVar3 = 6;
  do {
    iVar3 = iVar3 + -1;
    FUN_006a3570();
  } while (iVar3 != 0);
  FUN_006a3570();
  if (0 < *(int *)(iVar1 + 0x18)) {
    puVar5 = (undefined4 *)(iVar1 + 0x720);
    iVar3 = 0;
    do {
      iVar2 = FUN_006a91f0(*puVar5);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar3 < *(int *)(iVar1 + 0x18));
  }
  FUN_006a3570();
  FUN_006a3570();
  FUN_006a3570();
  iVar3 = 0;
  if (0 < *(int *)(iVar1 + 0x10)) {
    piVar4 = (int *)(iVar1 + 800);
    do {
      FUN_006a3570();
      if (*(int *)(&PTR_DAT_00817010)[*piVar4] == 0) {
        return 0xffffffff;
      }
      (**(code **)(&PTR_DAT_00817010)[*piVar4])(piVar4[0x40]);
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < *(int *)(iVar1 + 0x10));
  }
  FUN_006a3570();
  iVar3 = 0;
  if (0 < *(int *)(iVar1 + 0x14)) {
    piVar4 = (int *)(iVar1 + 0x520);
    do {
      FUN_006a3570();
      (**(code **)(&PTR_DAT_00817018)[*piVar4])(piVar4[0x40]);
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < *(int *)(iVar1 + 0x14));
  }
  FUN_006a3570();
  iVar3 = 0;
  if (0 < *(int *)(iVar1 + 0xc)) {
    piVar4 = (int *)(iVar1 + 0x120);
    do {
      FUN_006a3570();
      (**(code **)(&PTR_PTR_00817024)[*piVar4])(param_1,piVar4[0x40]);
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < *(int *)(iVar1 + 0xc));
  }
  FUN_006a3570();
  iVar3 = 0;
  if (0 < *(int *)(iVar1 + 8)) {
    do {
      FUN_006a3570();
      FUN_006a3570();
      FUN_006a3570();
      FUN_006a3570();
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(iVar1 + 8));
  }
  FUN_006a3570();
  return 0;
}

