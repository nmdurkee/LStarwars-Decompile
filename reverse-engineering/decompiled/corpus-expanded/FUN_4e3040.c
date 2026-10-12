/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e3040; label: FUN_004e3040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e3040(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  DAT_0088958c = FUN_005aac00(DAT_0095df4c,"LiftChase",0);
  _DAT_0087a830 = 0;
  iVar3 = FUN_005cfac0(&DAT_008895b0);
  iVar2 = DAT_00889584;
  uVar1 = _DAT_00800098;
  if ((iVar3 != 0) && (DAT_00889584 != 0)) {
    if ((*(byte *)(DAT_008895a4 * 0x2e28 + 0x2800 + DAT_0087b2cc) & 1) == 0) {
      *(uint *)(DAT_00889584 + 0x50) = *(uint *)(DAT_00889584 + 0x50) | 1;
      *(undefined4 *)(iVar2 + 0x4c) = 0x3f800000;
      DAT_0080009c = 1;
      _DAT_00800098 = 0x3f800000;
      *(float *)(iVar2 + 0x40) = _DAT_00800094;
      DAT_008895f8 = 0;
      return;
    }
    if (-1 < DAT_0080009c) {
      uVar1 = **(undefined4 **)
                (*(int *)(DAT_008895b0 + 0x54) + (uint)*(ushort *)(DAT_00889584 + 0x5c) * 4);
      *(uint *)(DAT_00889584 + 0x50) = *(uint *)(DAT_00889584 + 0x50) & 0xfffffffe;
      *(undefined4 *)(iVar2 + 0x4c) = uVar1;
      *(float *)(iVar2 + 0x40) = _DAT_00800094;
      DAT_008895f8 = 0;
      return;
    }
    *(uint *)(DAT_00889584 + 0x50) = *(uint *)(DAT_00889584 + 0x50) | 1;
    *(undefined4 *)(iVar2 + 0x4c) = uVar1;
    *(float *)(iVar2 + 0x40) = -_DAT_00800094;
  }
  DAT_008895f8 = 0;
  return;
}

