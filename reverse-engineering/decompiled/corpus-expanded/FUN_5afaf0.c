/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5afaf0; label: FUN_005afaf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005afaf0(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  int local_4;
  
  if ((((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x516c), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (local_4 = 0, 0 < piVar1[1])) {
    pbVar5 = (byte *)(*piVar1 + 0x23);
    do {
      bVar3 = *pbVar5 & 0xfb | 3;
      *pbVar5 = bVar3;
      if ((param_3 != 0) && (local_4 < 0x20)) {
        iVar2 = (int)(local_4 + (local_4 >> 0x1f & 0x1fU)) >> 5;
        uVar4 = 1 << ((byte)local_4 & 0x1f);
        bVar3 = (((*(uint *)(param_3 + iVar2 * 4) & uVar4) != 0) * '\x02' ^ bVar3) & 2 ^ bVar3;
        *pbVar5 = bVar3;
        bVar3 = ((*(uint *)(param_3 + 4 + iVar2 * 4) & uVar4) != 0 ^ bVar3) & 1 ^ bVar3;
        *pbVar5 = bVar3;
        *pbVar5 = ((*(uint *)(param_3 + 8 + iVar2 * 4) & uVar4) != 0) * '\x04' ^ bVar3;
      }
      local_4 = local_4 + 1;
      pbVar5 = pbVar5 + 0x34;
    } while (local_4 < *(int *)(*(int *)(param_1 + 0x516c) + 4));
  }
  return;
}

