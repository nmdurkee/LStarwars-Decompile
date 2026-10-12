/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x6056f0; label: FUN_006056f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 *
FUN_006056f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  do {
    if ((&DAT_0280d7e0)[iVar1] == '\0') {
      (&DAT_0280d7e0)[iVar1] = 1;
      puVar2 = &DAT_00986f00 + iVar1 * 0xc;
      goto LAB_0060570b;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x20);
  FUN_005f7490();
  puVar2 = (undefined4 *)0x0;
LAB_0060570b:
  param_4 = param_4 & 0xffffffef;
  if ((param_4 != 0) && (param_4 != 1)) {
    FUN_005f7490();
    return (undefined4 *)0x0;
  }
  FUN_005f81f0(puVar2,param_1,param_2,param_3,param_4,0,param_5);
  return puVar2;
}

