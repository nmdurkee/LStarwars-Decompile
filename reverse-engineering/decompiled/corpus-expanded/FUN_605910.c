/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x605910; label: FUN_00605910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00605910(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = FUN_005f79e0();
  iVar2 = 0;
  do {
    if ((&DAT_0280d7e0)[iVar2] == '\0') {
      (&DAT_0280d7e0)[iVar2] = 1;
      puVar3 = &DAT_00986f00 + iVar2 * 0xc;
      goto LAB_00605938;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x20);
  uVar1 = FUN_005f7490();
  puVar3 = (undefined4 *)0x0;
LAB_00605938:
  FUN_005f81f0(puVar3,param_1,param_2,param_3,1,0,uVar1);
  puVar3[8] = puVar3[8] & 0xffffdbff | 0x1b00;
  return puVar3;
}

