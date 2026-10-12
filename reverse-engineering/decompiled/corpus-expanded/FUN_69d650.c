/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69d650; label: FUN_0069d650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069d650(int param_1,double param_2)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  float10 fVar4;
  undefined8 uVar5;
  double local_10;
  
  local_10 = 0.0;
  iVar2 = 0;
  if (*(int *)(param_1 + 0x58) < 2) {
    return 0xffffff7d;
  }
  if (*(int *)(param_1 + 4) == 0) {
    return 0xffffff76;
  }
  if (0.0 <= param_2) {
    bVar3 = *(int *)(param_1 + 0x34) == 0;
    if (0 < *(int *)(param_1 + 0x34)) {
      do {
        fVar4 = (float10)FUN_0069c720(param_1,iVar2);
        if ((float10)param_2 < fVar4 + (float10)local_10) break;
        local_10 = (double)(fVar4 + (float10)local_10);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 0x34));
      bVar3 = iVar2 == *(int *)(param_1 + 0x34);
    }
    if (!bVar3) {
      uVar5 = FUN_006e6bc6();
      uVar1 = FUN_0069cb10(param_1,uVar5);
      return uVar1;
    }
  }
  return 0xffffff7d;
}

