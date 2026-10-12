/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x664100; label: FUN_00664100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00664100(void)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = DAT_029231a8;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    uVar2 = FUN_006e6b90();
    (&DAT_02924b9c)[iVar1 * 0x2c] = uVar2;
    uVar2 = FUN_006e6b90();
    *(undefined2 *)((&DAT_02924b60)[iVar1 * 0x16] * 0x330 + 0x2f0 + DAT_029620a4) = uVar2;
  }
  return;
}

