/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fc860; label: FUN_005fc860
 */

int FUN_005fc860(int param_1,undefined4 *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar2 = 1;
  if ((DAT_00806b94 == 1) && (0 < param_3)) {
    iVar4 = 0;
    do {
      iVar2 = param_3;
      piVar1 = (int *)(iVar4 + *(int *)(param_1 + 0xc));
      iVar4 = iVar4 + 0xc;
      puVar5 = (undefined4 *)(*piVar1 * 0x50 + DAT_00973860);
      puVar6 = param_2;
      for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      param_2 = param_2 + 0x14;
      param_3 = iVar2 + -1;
    } while (iVar2 + -1 != 0);
  }
  return iVar2;
}

