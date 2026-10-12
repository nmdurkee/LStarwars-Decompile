/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x7467a0; label: FUN_007467a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_007467a0(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int in_ECX;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  pbVar5 = (byte *)(in_ECX + 0x8a0);
  do {
    pbVar2 = param_1;
    pbVar4 = pbVar5;
    if ((byte *)(in_ECX + 0x8a0 + *(int *)(in_ECX + 0x940) * 0x14) <= pbVar5) {
      return 0;
    }
    do {
      bVar1 = *pbVar2;
      bVar6 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_007467e5:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_007467ea;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar6 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_007467e5;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_007467ea:
    if (iVar3 == 0) {
      return *(undefined4 *)(pbVar5 + 0x10);
    }
    pbVar5 = pbVar5 + 0x14;
  } while( true );
}

