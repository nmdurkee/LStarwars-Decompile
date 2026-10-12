/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4c02d0; label: FUN_004c02d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c02d0(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  int local_8;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x5090) != 0)) &&
     (local_8 = 0, 0 < *(int *)(param_1 + 0x5094))) {
    pbVar2 = (byte *)(*(int *)(param_1 + 0x5090) + 0x3c);
    do {
      FUN_004c0230();
      if ((param_3 != 0) && (local_8 < 0x80)) {
        uVar4 = 1 << ((byte)local_8 & 0x1f);
        iVar3 = (int)(local_8 + (local_8 >> 0x1f & 0x1fU)) >> 5;
        *pbVar2 = *pbVar2 ^ (((*(uint *)(param_3 + iVar3 * 4) & uVar4) != 0) * '\b' ^ *pbVar2) & 8;
        bVar1 = (((*(uint *)(param_3 + 0x20 + iVar3 * 4) & uVar4) != 0) * '\x02' ^ *pbVar2) & 2 ^
                *pbVar2;
        *pbVar2 = bVar1;
        *pbVar2 = ((*(uint *)(param_3 + 0x10 + iVar3 * 4) & uVar4) != 0 ^ bVar1) & 1 ^ bVar1;
      }
      local_8 = local_8 + 1;
      pbVar2 = pbVar2 + 0x54;
    } while (local_8 < *(int *)(param_1 + 0x5094));
  }
  return;
}

