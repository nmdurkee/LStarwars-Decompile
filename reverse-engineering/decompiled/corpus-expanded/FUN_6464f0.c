/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x6464f0; label: FUN_006464f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006464f0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined1 *puVar6;
  int iVar7;
  
  DAT_02920a18 = 0;
  uVar4 = *(uint *)(param_2 + 0xc) >> 0x10;
  iVar2 = *(uint *)(param_2 + 0xc) + uVar4 * -0x10000;
  if (iVar2 == 9999) {
    iVar2 = -1;
  }
  if (DAT_02920970 != 0) {
    *(int *)(DAT_02920970 + 0x148 + uVar4 * 4) = iVar2;
  }
  iVar2 = DAT_0292096c;
  iVar7 = 0;
  puVar6 = &DAT_0291f7e4;
  do {
    iVar1 = *(int *)(puVar6 + -0x30);
    if (iVar1 == *(int *)(iVar2 + 0xc)) {
      iVar3 = 0;
      *puVar6 = 0;
      if (iVar7 < 4) {
        piVar5 = &DAT_02913ba0 + iVar1 * 0x5e;
        for (; (*piVar5 == -1 || ((&DAT_02913bb0)[iVar3 + iVar1 * 0x178] == '\0'));
            iVar3 = iVar3 + 1) {
          piVar5 = piVar5 + 1;
        }
        *puVar6 = 1;
      }
    }
    puVar6 = puVar6 + 0x6c;
    iVar7 = iVar7 + 1;
  } while ((int)puVar6 < 0x29208c4);
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}

