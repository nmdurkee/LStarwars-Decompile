/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x6393b0; label: FUN_006393b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006393b0(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  bVar6 = true;
  if ((DAT_02913824 != (undefined4 *)0x0) && (*(char *)(DAT_02913824 + 0x1e) != '\0')) {
    iVar9 = 0;
    iVar7 = DAT_0291389c;
    puVar10 = DAT_02913824;
    do {
      if ((((undefined4 *)(iVar9 + 4 + iVar7) != puVar10) &&
          (*(char *)(iVar9 + 0x5c + iVar7) != '\0')) &&
         (*(char *)(iVar9 + 0x7c + iVar7) == *(char *)(puVar10 + 0x1e))) {
        if (bVar6) {
          FUN_006378f0();
          bVar6 = false;
          iVar7 = DAT_0291389c;
          puVar10 = DAT_02913824;
        }
        uVar3 = *(undefined4 *)(iVar9 + 0xc + iVar7);
        uVar4 = *(undefined4 *)(iVar9 + 4 + iVar7);
        uVar5 = *(undefined4 *)(iVar9 + 8 + iVar7);
        uVar1 = *(undefined2 *)(iVar9 + 0x6e + iVar7);
        uVar2 = *(undefined2 *)(iVar9 + 0x6c + iVar7);
        puVar11 = (undefined4 *)(iVar9 + 4 + iVar7);
        for (iVar8 = 0x23; iVar7 = DAT_0291389c, iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar11 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar11 = puVar11 + 1;
        }
        *(undefined4 *)(iVar9 + 4 + DAT_0291389c) = uVar4;
        iVar7 = iVar9 + 4 + iVar7;
        *(undefined4 *)(iVar7 + 4) = uVar5;
        *(undefined4 *)(iVar7 + 8) = uVar3;
        *(undefined2 *)(iVar9 + 0x6e + DAT_0291389c) = uVar1;
        *(undefined2 *)(iVar9 + 0x6c + DAT_0291389c) = uVar2;
        iVar7 = DAT_0291389c;
        puVar10 = DAT_02913824;
      }
      iVar9 = iVar9 + 0x8c;
    } while (iVar9 < 0x4600);
  }
  return;
}

