/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x746bb0; label: FUN_00746bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00746bb0(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int in_ECX;
  byte *pbVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = 0;
  if (0 < *(int *)(in_ECX + 0x4b0)) {
    do {
      pbVar2 = (byte *)**(undefined4 **)(in_ECX + iVar5 * 4);
      pbVar4 = param_1;
      do {
        bVar1 = *pbVar2;
        bVar6 = bVar1 < *pbVar4;
        if (bVar1 != *pbVar4) {
LAB_00746bf0:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_00746bf5;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar6 = bVar1 < pbVar4[1];
        if (bVar1 != pbVar4[1]) goto LAB_00746bf0;
        pbVar2 = pbVar2 + 2;
        pbVar4 = pbVar4 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_00746bf5:
      if (iVar3 == 0) {
        return *(undefined4 *)(in_ECX + iVar5 * 4);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(in_ECX + 0x4b0));
  }
  return 0;
}

