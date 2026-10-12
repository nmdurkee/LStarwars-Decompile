/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x6056b0; label: FUN_006056b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006056b0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = &DAT_00986f00;
  do {
    (&DAT_0280d7e0)[iVar2] = 0;
    FUN_005f7b40(puVar1);
    puVar1 = puVar1 + 0xc;
    iVar2 = iVar2 + 1;
  } while (puVar1 != (undefined4 *)&DAT_00987500);
  return;
}

