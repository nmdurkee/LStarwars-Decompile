/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d1a70; label: FUN_005d1a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_005d1a70(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = FUN_004fa5f0(param_2,0);
  if (iVar1 == 0) {
    return (int *)0x0;
  }
  iVar2 = FUN_004f6b40(iVar1);
  if (param_1 == (int *)0x0) {
    piVar3 = (int *)FUN_004eef40(iVar2,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutexanm.c",
                                 0x1bc);
  }
  else {
    piVar3 = (int *)(*param_1 + 3U & 0xfffffffc);
    *param_1 = (int)piVar3 + iVar2;
  }
  FUN_004fb550(iVar1,piVar3,iVar2);
  FUN_004f99e0(iVar1);
  *piVar3 = (int)DAT_009738d4;
  if (DAT_009738d4 != (int *)0x0) {
    *(int **)((int)DAT_009738d4 + 4) = piVar3;
  }
  piVar3[1] = 0;
  DAT_009738d4 = piVar3;
  if (param_1 != (int *)0x0) {
    *(ushort *)((int)piVar3 + 0x1b6) = *(ushort *)((int)piVar3 + 0x1b6) & 0xfffe;
    return piVar3;
  }
  *(ushort *)((int)piVar3 + 0x1b6) = *(ushort *)((int)piVar3 + 0x1b6) | 1;
  return piVar3;
}

