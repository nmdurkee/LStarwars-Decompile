/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b3000; label: FUN_004b3000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004b3000(int param_1)

{
  undefined4 uVar1;
  
  FUN_00427b40(param_1);
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    FUN_004abac0(param_1,0,0,0x41000000,0);
    FUN_0058d8b0(param_1);
    FUN_0049c080(param_1);
    FUN_004a7880(param_1);
    FUN_004a7610(param_1);
    FUN_0049be00(param_1);
    FUN_004a3be0();
    FUN_004a4a20(param_1);
    FUN_005a03d0(param_1,0);
    FUN_004b0c80();
    FUN_004a7d00();
    FUN_0049c940();
    FUN_0049c610();
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) {
      uVar1 = 0x40000000;
    }
    else {
      uVar1 = 0x3f800000;
    }
    FUN_0049ea70(param_1,*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_0080227c,0,0,1,uVar1);
    FUN_004a7da0(param_1);
    FUN_004a82a0(param_1,0);
    FUN_0056a5b0(PTR_DAT_00802c54,param_1);
  }
  return;
}

