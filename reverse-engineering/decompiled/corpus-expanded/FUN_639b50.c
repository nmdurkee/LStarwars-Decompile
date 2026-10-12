/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x639b50; label: FUN_00639b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00639b50(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  if ((DAT_0291396c != 0) && (*(int *)(DAT_0291396c + 0x550) < 0x20)) {
    piVar4 = (int *)(DAT_0291396c + 0xd0);
    iVar2 = *(int *)(DAT_0291396c + 0xd0);
    while (iVar2 != 0) {
      piVar4 = piVar4 + 9;
      iVar3 = iVar3 + 1;
      iVar2 = *piVar4;
    }
    iVar2 = iVar3 * 0x24;
    *(undefined4 *)(iVar2 + 0xd0 + DAT_0291396c) = 1;
    puVar1 = (undefined4 *)(iVar2 + 0xd4 + DAT_0291396c);
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
    puVar1[2] = param_1[2];
    *(undefined4 *)(iVar2 + 0xec + DAT_0291396c) = *(undefined4 *)(DAT_0291396c + 0x558);
    *(undefined4 *)(iVar2 + 0xf0 + DAT_0291396c) = *(undefined4 *)(DAT_0291396c + 0x55c);
    *(undefined4 *)(iVar2 + 0xe0 + DAT_0291396c) = *(undefined4 *)(DAT_0291396c + 0x24);
    *(undefined4 *)(iVar2 + 0xe4 + DAT_0291396c) = *(undefined4 *)(DAT_0291396c + 0x14);
    *(undefined4 *)(iVar2 + 0xe8 + DAT_0291396c) = *(undefined4 *)(DAT_0291396c + 0x1c);
    *(int *)(DAT_0291396c + 0x550) = *(int *)(DAT_0291396c + 0x550) + 1;
    return iVar3;
  }
  return -1;
}

