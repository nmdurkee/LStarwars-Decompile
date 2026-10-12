/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x527460; label: FUN_00527460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00527460(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,FUN_00527360,param_1);
  if ((iVar1 != 0) &&
     (iVar2 = FUN_00619250(0x78,0x5a,0x1b8,0xfa,DAT_02912e80,0,param_1), iVar2 != 0)) {
    uVar3 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00527390,param_2);
    FUN_00618e10(iVar2,uVar3);
    FUN_006279b0(iVar1,iVar2);
  }
  return iVar1;
}

