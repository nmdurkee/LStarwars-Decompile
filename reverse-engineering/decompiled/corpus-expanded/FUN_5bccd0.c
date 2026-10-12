/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bccd0; label: FUN_005bccd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bccd0(int param_1,float param_2,int param_3,int param_4,int param_5)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48 [72];
  
  iVar2 = (int)param_2;
  FUN_005bcc80(local_48,param_1,param_2);
  iVar3 = param_1 - (int)param_2;
  iVar4 = param_5 + -1;
  fVar1 = (float)iVar4;
  param_2 = 0.0;
  if (0 < iVar4) {
    puVar5 = (undefined4 *)(param_4 + 8);
    do {
      FUN_005bc760(local_48,param_1,iVar2,param_2,param_3,&local_54);
      puVar5[-2] = local_54;
      iVar4 = iVar4 + -1;
      puVar5[-1] = local_50;
      *puVar5 = local_4c;
      param_2 = param_2 + (float)(iVar3 + 2) / fVar1;
      puVar5 = puVar5 + 3;
    } while (iVar4 != 0);
  }
  iVar4 = param_3 + param_1 * 0xc;
  param_4 = param_4 + param_5 * 0xc;
  *(undefined4 *)(param_4 + -0xc) = *(undefined4 *)(param_3 + param_1 * 0xc);
  *(undefined4 *)(param_4 + -8) = *(undefined4 *)(iVar4 + 4);
  *(undefined4 *)(param_4 + -4) = *(undefined4 *)(iVar4 + 8);
  return;
}

