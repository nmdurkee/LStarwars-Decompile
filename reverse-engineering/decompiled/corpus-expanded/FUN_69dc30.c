/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69dc30; label: FUN_0069dc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0069dc30(int param_1,int *param_2,uint param_3,undefined4 *param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = param_1;
  if (*(int *)(param_1 + 0x58) < 2) {
    return 0xffffff7d;
  }
  do {
    if ((*(int *)(iVar3 + 0x58) == 4) && (uVar4 = FUN_006a2db0(iVar3 + 0x1e0,&param_1), uVar4 != 0))
    {
      if (param_2 != (int *)0x0) {
        *param_2 = param_1;
      }
      if ((int)param_3 < (int)uVar4) {
        uVar4 = param_3;
      }
      FUN_006a2e10(iVar3 + 0x1e0,uVar4);
      puVar1 = (uint *)(iVar3 + 0x50);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + uVar4;
      *(int *)(iVar3 + 0x54) =
           *(int *)(iVar3 + 0x54) + ((int)uVar4 >> 0x1f) + (uint)CARRY4(uVar2,uVar4);
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(iVar3 + 0x60);
      }
      return uVar4;
    }
    uVar4 = FUN_0069c090(0,1,1);
    if (uVar4 == 0xfffffffe) {
      return 0;
    }
  } while (0 < (int)uVar4);
  return uVar4;
}

