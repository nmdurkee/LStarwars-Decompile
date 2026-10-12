/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64b1c0; label: FUN_0064b1c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0064b1c0(int param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (DAT_02920a98 == 0x28) {
    return -1;
  }
  if ((&DAT_02913ae8)[param_1 * 0xbc] == -1) {
    return -1;
  }
  iVar5 = 0;
  piVar3 = &DAT_0291f7b4;
  do {
    if (*piVar3 == -1) {
      iVar4 = iVar5 * 0x6c;
      (&DAT_0291f7a8)[iVar5 * 0x1b] = *param_2;
      (&DAT_0291f7ac)[iVar5 * 0x1b] = param_2[1];
      uVar2 = param_2[2];
      (&DAT_0291f7b4)[iVar5 * 0x1b] = param_1;
      (&DAT_0291f7b0)[iVar5 * 0x1b] = uVar2;
      FUN_004f1f40(&DAT_0291f7b8 + iVar4,&DAT_02913a58 + param_1 * 0x178,0x10);
      FUN_0064ae50(iVar5,0);
      uVar1 = (&DAT_02913b0a)[param_1 * 0x178];
      (&DAT_0291f7e8)[iVar5 * 0x1b] = 0x461c3f9a;
      DAT_02920a98 = DAT_02920a98 + 1;
      (&DAT_0291f7d8)[iVar5 * 0x36] = 0;
      (&DAT_0291f7d6)[iVar5 * 0x36] = 0;
      (&DAT_0291f7d4)[iVar5 * 0x36] = 0;
      (&DAT_0291f7da)[iVar4] = uVar1;
      (&DAT_0291f7dc)[iVar5 * 0x1b] = 0;
      (&DAT_0291f7db)[iVar4] = 0;
      (&DAT_0291f7ec)[iVar5 * 0x36] = 0;
      (&DAT_0291f7ee)[iVar5 * 0x36] = 0;
      (&DAT_0291f7e5)[iVar4] = 1;
      return iVar5;
    }
    piVar3 = piVar3 + 0x1b;
    iVar5 = iVar5 + 1;
  } while ((int)piVar3 < 0x2920894);
  return -1;
}

