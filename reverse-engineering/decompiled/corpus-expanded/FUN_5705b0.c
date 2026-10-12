/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x5705b0; label: FUN_005705b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005705b0(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  if ((param_1 == 0) || ((*(uint *)(param_2 + 0x1f8) & 0x40000) != 0)) {
    return 0;
  }
  iVar4 = FUN_00570280(0x40);
  bVar6 = iVar4 == 0;
  if (bVar6) {
    iVar4 = FUN_00570280(*(undefined4 *)(*(int *)(param_1 + 0x50b8) + 8));
  }
  if (iVar4 == 0) {
    return 0;
  }
  *(byte *)(iVar4 + 0x17) = *(byte *)(iVar4 + 0x17) | 8;
  if (!bVar6) {
    *(byte *)(iVar4 + 0x17) = *(byte *)(iVar4 + 0x17) & 0xfe;
  }
  if (((*(byte *)(iVar4 + 0x17) & 0x40) == 0) ||
     (uVar5 = (uint)(char)PTR_PTR_008033b0[0xc], PTR_PTR_008033b0[0xc] == -1)) {
    uVar5 = (uint)*(byte *)(iVar4 + 0x25);
  }
  iVar3 = uVar5 * 0x38;
  iVar1 = *(int *)(*(int *)PTR_PTR_008033b0 + 8 + iVar3);
  if (iVar1 != 0) {
    FUN_00681f40(iVar1,iVar4 + 8);
  }
  pcVar2 = *(code **)(*(int *)PTR_PTR_008033b0 + 0x28 + iVar3);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(param_1,iVar4,uVar5,param_2,0);
  }
  if ((*(byte *)(*(int *)PTR_PTR_008033b0 + 0xe + iVar3) & 0x40) != 0) {
    DAT_0095123c = DAT_0095123c + 1;
  }
  return iVar4;
}

