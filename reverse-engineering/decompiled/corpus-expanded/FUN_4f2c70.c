/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2c70; label: FUN_004f2c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f2c70(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  
  uVar1 = *param_1;
  iVar4 = 0;
  iVar2 = 0;
  puVar3 = param_1 + 1;
  if (uVar1 == 0x2d) {
    uVar1 = *puVar3;
    iVar2 = -1;
    puVar3 = param_1 + 2;
  }
  while ((0x2f < uVar1 && (uVar1 < 0x3a))) {
    iVar4 = (uVar1 - 0x30) + iVar4 * 10;
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
  }
  if (iVar2 != 0) {
    return iVar2 * iVar4;
  }
  return iVar4;
}

