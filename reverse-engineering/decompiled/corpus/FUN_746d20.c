/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x746d20; label: FUN_00746d20
 */

uint * FUN_00746d20(byte *param_1)

{
  byte bVar1;
  uint *puVar2;
  int in_ECX;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  
  iVar6 = 0;
  if (0 < *(int *)(in_ECX + 0x89c)) {
    piVar7 = (int *)(in_ECX + 0x4b4);
    do {
      puVar2 = (uint *)*piVar7;
      if ((*puVar2 & 0x4020) == 0x4020) {
        pbVar3 = (byte *)puVar2[3];
        pbVar5 = param_1;
        do {
          bVar1 = *pbVar3;
          bVar8 = bVar1 < *pbVar5;
          if (bVar1 != *pbVar5) {
LAB_00746d70:
            iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_00746d75;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar8 = bVar1 < pbVar5[1];
          if (bVar1 != pbVar5[1]) goto LAB_00746d70;
          pbVar3 = pbVar3 + 2;
          pbVar5 = pbVar5 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_00746d75:
        if (iVar4 == 0) {
          return puVar2;
        }
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar6 < *(int *)(in_ECX + 0x89c));
  }
  return (uint *)0x0;
}

