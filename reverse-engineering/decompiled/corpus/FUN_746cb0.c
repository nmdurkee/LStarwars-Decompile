/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x746cb0; label: FUN_00746cb0
 */

int * FUN_00746cb0(byte *param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
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
      piVar2 = (int *)*piVar7;
      if (*piVar2 == param_2) {
        pbVar3 = (byte *)piVar2[3];
        pbVar5 = param_1;
        do {
          bVar1 = *pbVar3;
          bVar8 = bVar1 < *pbVar5;
          if (bVar1 != *pbVar5) {
LAB_00746cf7:
            iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_00746cfc;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar8 = bVar1 < pbVar5[1];
          if (bVar1 != pbVar5[1]) goto LAB_00746cf7;
          pbVar3 = pbVar3 + 2;
          pbVar5 = pbVar5 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_00746cfc:
        if (iVar4 == 0) {
          return piVar2;
        }
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar6 < *(int *)(in_ECX + 0x89c));
  }
  return (int *)0x0;
}

