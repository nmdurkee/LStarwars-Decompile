/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x746b40; label: FUN_00746b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00746b40(byte *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int in_ECX;
  byte *pbVar5;
  int iVar6;
  bool bVar7;
  
  iVar2 = *(int *)(in_ECX + 0x4b0);
  iVar6 = 0;
  if (0 < iVar2) {
    do {
      pbVar3 = (byte *)**(undefined4 **)(in_ECX + iVar6 * 4);
      pbVar5 = param_1;
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_00746b80:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_00746b85;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_00746b80;
        pbVar3 = pbVar3 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_00746b85:
    } while ((iVar4 != 0) && (iVar6 = iVar6 + 1, iVar6 < iVar2));
  }
  if (iVar6 < iVar2 + -1) {
    *(undefined4 *)(in_ECX + iVar6 * 4) = *(undefined4 *)(in_ECX + -4 + iVar2 * 4);
  }
  *(int *)(in_ECX + 0x4b0) = *(int *)(in_ECX + 0x4b0) + -1;
  return;
}

