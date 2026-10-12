/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x504b80; label: FUN_00504b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_00504b80(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar6 = (int *)0x0;
  iVar2 = FUN_004fc860(param_1);
  if (iVar2 != 0) {
    FUN_004f7fb0(iVar2);
    iVar3 = FUN_004fc5b0(iVar2);
    piVar1 = (int *)0x0;
    while (iVar3 != 0) {
      FUN_004f7fb0(iVar2);
      iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"SCRIPT");
      piVar5 = piVar1;
      piVar7 = piVar6;
      if (((iVar3 == 0) && (piVar4 = (int *)FUN_00504b10(iVar2,param_3), piVar4 != (int *)0x0)) &&
         (piVar5 = piVar4, piVar7 = piVar4, piVar1 != (int *)0x0)) {
        *piVar1 = (int)piVar4;
        piVar7 = piVar6;
      }
      iVar3 = FUN_004fc5b0(iVar2);
      piVar6 = piVar7;
      piVar1 = piVar5;
    }
    FUN_004fa300(iVar2);
    *param_2 = *param_2 + 0xf & 0xfffffff0;
  }
  return piVar6;
}

