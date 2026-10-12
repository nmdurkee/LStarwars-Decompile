/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x605800; label: FUN_00605800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00605800(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  uVar1 = FUN_005f79e0();
  uVar2 = DAT_02976704 / param_1;
  param_1 = DAT_02976700 / param_1;
  iVar3 = 0;
  do {
    if ((&DAT_0280d7e0)[iVar3] == '\0') {
      (&DAT_0280d7e0)[iVar3] = 1;
      puVar4 = &DAT_00986f00 + iVar3 * 0xc;
      goto LAB_00605848;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x20);
  param_1 = FUN_005f7490();
  puVar4 = (undefined4 *)0x0;
LAB_00605848:
  FUN_005f81f0(puVar4,param_1,uVar2,param_2,1,0,uVar1);
  puVar4[8] = puVar4[8] & 0xffffdbff | 0x1b00;
  return puVar4;
}

