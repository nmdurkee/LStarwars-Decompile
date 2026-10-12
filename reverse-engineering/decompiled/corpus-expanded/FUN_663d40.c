/* Ghidra pseudocode, not original source.
 * ev_277e9292cb53e7665c3bde753cc9c2d26e6793a349ba78c22fc7a8e115ea3a32
 * Entry: 0x663d40; label: FUN_00663d40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00663d40(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_029231a8;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    (&DAT_02924b84)[DAT_029231a8 * 0x16] = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)((&DAT_02924b60)[iVar1 * 0x16] * 0x330 + 0x2d0 + DAT_029620a4) =
         *(undefined4 *)(param_2 + 0xc);
  }
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  DAT_02962a50 = 0;
  return;
}

