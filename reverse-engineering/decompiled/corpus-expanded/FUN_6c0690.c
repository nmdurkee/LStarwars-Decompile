/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c0690; label: FUN_006c0690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c0690(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c [3];
  
  local_c[0] = 0x80808080;
  local_c[1] = 0x80800000;
  local_c[2] = 0x80000080;
  FUN_006ba6a0(0);
  iVar1 = param_1 + 0x10;
  iVar2 = 0;
  iVar3 = iVar1;
  do {
    FUN_006baa80(iVar3,_DAT_0081f9b4 * _DAT_0081fa04,local_c[iVar2],8);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x10;
  } while (iVar2 < 3);
  FUN_006ba7d0(iVar1,param_1 + 0x20,0xffffffff);
  FUN_006ba7d0(iVar1,param_1 + 0x30,0xffffffff);
  if (DAT_02973a60 != 0) {
    if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
      FUN_006009c0();
    }
    DAT_02973a60 = 0;
  }
  return;
}

