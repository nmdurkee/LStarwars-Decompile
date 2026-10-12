/* Ghidra pseudocode, not original source.
 * ev_8263a5d3e8c49c8909e3cfceaf1282da1bb42b3174c131367c36677ef6ae0531
 * Entry: 0x63ad30; label: FUN_0063ad30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063ad30(void)

{
  float fVar1;
  int iVar2;
  
  _DAT_029139d0 = 1;
  DAT_029139b4 = 1;
  FUN_00617e30(DAT_029139ac);
  DAT_0291389c = FUN_005958a0();
  *(undefined4 *)(DAT_0291389c + 0x4f84) = 0;
  iVar2 = DAT_0291399c;
  fVar1 = DAT_00973734;
  _DAT_029134c8 = DAT_00973730;
  _DAT_029134c4 = DAT_00973734;
  DAT_029139bc = 0;
  DAT_029139a0 = 0;
  DAT_029139a4 = 0;
  DAT_02913814 = 0;
  DAT_02913824 = 0;
  DAT_02913818 = 0;
  if (DAT_0291399c != 0) {
    *(float *)(DAT_0291399c + 0x5c) = DAT_00973734 + DAT_00973734;
    *(undefined4 *)(iVar2 + 0x58) = _DAT_029134c8;
    FUN_0061d810(iVar2,fVar1,0,0);
  }
  iVar2 = DAT_02913998;
  if (DAT_02913998 != 0) {
    *(float *)(DAT_02913998 + 0x5c) = _DAT_029134c4 - *(float *)(DAT_02913998 + 0x58);
    FUN_0061d810(iVar2,_DAT_029134c8,0,0);
  }
  *(byte *)(DAT_029137c4 + 0x11) = *(byte *)(DAT_029137c4 + 0x11) | 2;
  *(byte *)(DAT_02913508 + 0x11) = *(byte *)(DAT_02913508 + 0x11) | 2;
  DAT_029139c4 = 0;
  DAT_029139c8 = 0;
  DAT_029139cc = 0;
  return;
}

