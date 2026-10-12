/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b3b80; label: FUN_004b3b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004b3b80(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = *(uint *)(*(int *)(param_1 + 0xca4) + 8);
  uVar3 = *(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_00802278;
  uVar4 = uVar6 & DAT_0080227c;
  uVar5 = uVar6 & DAT_00802284;
  uVar1 = uVar6 & DAT_00802280;
  uVar6 = uVar6 & DAT_00802278;
  FUN_00427b40(param_1);
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    FUN_004abac0(param_1,0,0,0x41000000,0);
    FUN_0049c080(param_1);
    FUN_0049be00(param_1);
    FUN_004a7610(param_1);
    FUN_004a3be0();
    FUN_004a4a20(param_1);
    FUN_0056d8c0(param_1,PTR_DAT_00802c54);
    FUN_004b0c80();
    if ((DAT_007f39e4 == 0) || (DAT_00876580 != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    FUN_0059bd40(param_1,uVar2);
    FUN_00488770(param_1,uVar5);
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
      FUN_004a2070(0);
    }
    FUN_00562570(param_1,uVar6,uVar3,0,0,0,0xffffffff);
    FUN_00592280(param_1);
    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x40000) != 0) {
      FUN_004ce830(param_1,uVar1);
    }
    FUN_004d6060(param_1,uVar1);
    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x100000) != 0) {
      FUN_0054ea40(param_1);
    }
    FUN_00490d10(PTR_DAT_00802c54,param_1);
    FUN_004d0290(param_1);
    FUN_00474070(PTR_DAT_00802c54,param_1,uVar1);
    FUN_0046eda0(PTR_DAT_00802c54,param_1,uVar1);
    FUN_0058d6a0(param_1);
    FUN_0058db50(param_1);
    FUN_0058dec0(param_1);
    FUN_004a6160(uVar4,uVar1);
    FUN_004a7d00();
    FUN_0058cef0(param_1);
    FUN_0058cf50(param_1);
    FUN_00547cb0(param_1,0,0);
  }
  return;
}

