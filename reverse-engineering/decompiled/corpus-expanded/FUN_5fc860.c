/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fc860; label: FUN_005fc860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

