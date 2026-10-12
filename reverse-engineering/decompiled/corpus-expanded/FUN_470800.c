/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x470800; label: FUN_00470800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00470800(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x210);
  param_1 = param_1 + 0x30;
  FUN_00681f40("Explode2",param_1);
  FUN_00549de0(PTR_DAT_008021b4,0x3f000000,0,param_1);
  iVar3 = 0xa8;
  do {
    sVar1 = *(short *)(iVar3 + *(int *)(iVar2 + 0xa4));
    if (sVar1 != -1) {
      FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),(int)sVar1,param_1);
    }
    iVar3 = iVar3 + 2;
  } while (iVar3 < 0xae);
  iVar3 = 0xa0;
  do {
    sVar1 = *(short *)(iVar3 + *(int *)(iVar2 + 0xa4));
    if (sVar1 != -1) {
      FUN_0064b370((int)sVar1,param_1,1);
    }
    iVar3 = iVar3 + 2;
  } while (iVar3 < 0xa4);
  FUN_0056e5f0(param_1,0x3f19999a,0x3e99999a,0,0xffffffff,0x27);
  FUN_00549bb0(PTR_DAT_008021b4,0x3f000000,0x3f000000,0x3f800000);
  FUN_0054a910(0x3f333333,0,0,0);
  return;
}

