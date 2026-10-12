/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b39f0; label: FUN_004b39f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b39f0(int param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    if (*(char *)(param_1 + 0x7b5) == '\x17') {
      uVar1 = 0;
    }
    else if ((*(short *)(param_1 + 0x1064) == DAT_007f18bc) && (*(char *)(param_1 + 0x283) == '\t'))
    {
      _DAT_0087b8dc = _DAT_007fc170;
      uVar1 = 0x3c23d70a;
    }
    else if ((*(short *)(param_1 + 0x1064) == DAT_007f18c0) &&
            (*(char *)(param_1 + 0x283) == '\x03')) {
      _DAT_0087b8dc = _DAT_007fc174;
      uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28);
    }
    else {
      uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28);
    }
    FUN_004abac0(param_1,0,uVar1,0x41000000,0);
    FUN_0049be00(param_1);
    if (*(short *)(param_1 + 0x1064) != DAT_007f18c0) {
      FUN_004a7610(param_1);
    }
    FUN_004a3be0();
    FUN_004a4a20(param_1);
    FUN_0056d8c0(param_1,PTR_DAT_00802c54);
    FUN_004b0c80();
    FUN_004a7d00();
    if ((*(short *)(param_1 + 0x1064) == DAT_007f18bc) &&
       ((*(int *)(param_1 + 0x10ac) != 0 ||
        (FUN_005972c0(param_1,0xb), *(int *)(param_1 + 0x10ac) != 0)))) {
      FUN_00597380(param_1);
    }
    FUN_0056a5b0(PTR_DAT_00802c54,param_1);
    return;
  }
  return;
}

