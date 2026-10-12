/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x605890; label: FUN_00605890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00605890(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = DAT_02976704 / param_1;
  param_1 = DAT_02976700 / param_1;
  iVar2 = 0;
  do {
    if ((&DAT_0280d7e0)[iVar2] == '\0') {
      (&DAT_0280d7e0)[iVar2] = 1;
      puVar3 = &DAT_00986f00 + iVar2 * 0xc;
      goto LAB_006058c8;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x20);
  param_1 = FUN_005f7490();
  puVar3 = (undefined4 *)0x0;
LAB_006058c8:
  FUN_005f81f0(puVar3,param_1,uVar1,param_2,1,0,param_3);
  puVar3[8] = puVar3[8] & 0xffffdbff | 0x1b00;
  return puVar3;
}

